#include "homescreendialog.h"
#include "ui_homescreendialog.h"

#include "viewdoctordialog.h"
#include "viewpatientdialog.h"
#include "calibrationdialog.h"
#include "calculatordialog.h"
#include "viewlensdialog.h"
#include "printdialog.h"
#include "adddoctordialog.h"
#include "addpatientdialog.h"
#include "promptdialog.h"
#include "measuredialog.h"
#include "preferencesdialog.h"
#include "welcomedialog.h"
#include "AppManager.h"

// ─────────────────────────────────────────────────────────────────────────────
//  Constructor / Destructor
// ─────────────────────────────────────────────────────────────────────────────
HomeScreenDialog::HomeScreenDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HomeScreenDialog)
    , clockTimer(new QTimer(this))
    , snackbarTimer(new QTimer(this))
    , m_sidebarAnimation(nullptr)
    , m_contentAnimation(nullptr)
    , m_tracking(false)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    setupSidebar();
    setupSidebarAnimation();

    grabGesture(Qt::SwipeGesture);

    connect(clockTimer, &QTimer::timeout, this, &HomeScreenDialog::updateClock);
    clockTimer->start(1000);
    updateClock();

    const QRect dlg = this->geometry();
    m_contentFullRect = QRect(300,
                              ui->stackedWidget->geometry().y(),
                              dlg.width(),
                              ui->stackedWidget->geometry().height());
    ui->stackedWidget->setGeometry(m_contentFullRect);

    showPage(PAGE_MAIN);
}

// ── Pre-loaded patient/doctor constructor ─────────────────────────────────────
HomeScreenDialog::HomeScreenDialog(const QString &patientId,
                                   const QString &doctorId,
                                   QWidget *parent)
    : HomeScreenDialog(parent)
{
    m_currentPatientId = patientId;
    m_currentDoctorId  = doctorId;

    // Show something instantly so the dialog never appears to "hang" before
    // the SQL lookups below complete.
    if (!patientId.isEmpty())
        ui->lbl_currentPatientName->setText(patientId);

    // Defer both DB lookups until after this dialog has had its first
    // paint event. show()/exec() in the caller happens immediately; the
    // sidebar labels fill in a frame later instead of blocking display.
    QTimer::singleShot(0, this, [this, patientId, doctorId]() {
        if (!patientId.isEmpty()) {
            QSqlDatabase db = QSqlDatabase::database();
            QSqlQuery q(db);
            q.prepare("SELECT name FROM patient WHERE patientid = :pid LIMIT 1");
            q.bindValue(":pid", patientId);
            if (q.exec() && q.next())
                ui->lbl_currentPatientName->setText(patientId + " - " + q.value(0).toString());
            else
                ui->lbl_currentPatientName->setText(patientId);
        }

        refreshDoctorSidebar(doctorId);
    });
}

HomeScreenDialog::~HomeScreenDialog()
{
    delete ui;
}

// ═════════════════════════════════════════════════════════════════════════════
//  SIDEBAR SLIDE ANIMATION
// ═════════════════════════════════════════════════════════════════════════════
void HomeScreenDialog::setupSidebar()
{
    ui->frame_sidebar->move(-SIDEBAR_WIDTH, ui->frame_sidebar->y());
    ui->frame_sidebar->hide();

    const QRect dlg = this->geometry();

    // Normal position (no sidebar) — X = 300
    m_contentFullRect = QRect(300,
                              ui->stackedWidget->geometry().y(),
                              dlg.width(),
                              ui->stackedWidget->geometry().height());

    // Sidebar open position — X = 450
    m_contentSidebarRect = QRect(450,
                                 ui->stackedWidget->geometry().y(),
                                 dlg.width() - SIDEBAR_WIDTH,
                                 ui->stackedWidget->geometry().height());

    ui->stackedWidget->setGeometry(m_contentFullRect);
}

void HomeScreenDialog::setupSidebarAnimation()
{
    m_sidebarAnimation = new QPropertyAnimation(ui->frame_sidebar, "pos", this);
    m_sidebarAnimation->setDuration(ANIM_DURATION);
    m_sidebarAnimation->setEasingCurve(QEasingCurve::OutCubic);

    m_contentAnimation = new QPropertyAnimation(ui->stackedWidget, "geometry", this);
    m_contentAnimation->setDuration(ANIM_DURATION);
    m_contentAnimation->setEasingCurve(QEasingCurve::OutCubic);
}

bool HomeScreenDialog::isSidebarVisible() const
{
    return ui->frame_sidebar->isVisible() && ui->frame_sidebar->x() >= 0;
}

void HomeScreenDialog::showSidebar()
{
    ui->frame_sidebar->show();

    m_sidebarAnimation->stop();
    m_sidebarAnimation->setStartValue(ui->frame_sidebar->pos());
    m_sidebarAnimation->setEndValue(QPoint(0, ui->frame_sidebar->y()));
    m_sidebarAnimation->start();

    m_contentAnimation->stop();
    m_contentAnimation->setStartValue(ui->stackedWidget->geometry());
    m_contentAnimation->setEndValue(m_contentSidebarRect);
    m_contentAnimation->start();
}

void HomeScreenDialog::hideSidebar()
{
    m_sidebarAnimation->stop();
    m_sidebarAnimation->setStartValue(ui->frame_sidebar->pos());
    m_sidebarAnimation->setEndValue(QPoint(-SIDEBAR_WIDTH, ui->frame_sidebar->y()));

    disconnect(m_sidebarAnimation, &QPropertyAnimation::finished, nullptr, nullptr);
    connect(m_sidebarAnimation, &QPropertyAnimation::finished,
            this, [this]() {
                if (ui->frame_sidebar->x() < 0)
                    ui->frame_sidebar->hide();
            });

    m_sidebarAnimation->start();

    m_contentAnimation->stop();
    m_contentAnimation->setStartValue(ui->stackedWidget->geometry());
    m_contentAnimation->setEndValue(m_contentFullRect);
    m_contentAnimation->start();
}

// ─────────────────────────────────────────────────────────────────────────────
//  Touch / swipe gestures
// ─────────────────────────────────────────────────────────────────────────────
bool HomeScreenDialog::event(QEvent *event)
{
    if (event->type() == QEvent::Gesture)
        return gestureEvent(static_cast<QGestureEvent *>(event));
    return QDialog::event(event);
}

bool HomeScreenDialog::gestureEvent(QGestureEvent *event)
{
    if (QSwipeGesture *swipe = static_cast<QSwipeGesture *>(
            event->gesture(Qt::SwipeGesture))) {
        if (swipe->state() == Qt::GestureFinished) {
            const QSwipeGesture::SwipeDirection h = swipe->horizontalDirection();
            if (h == QSwipeGesture::Right && !isSidebarVisible())
                showSidebar();
            else if (h == QSwipeGesture::Left && isSidebarVisible())
                hideSidebar();
        }
    }
    return true;
}

void HomeScreenDialog::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_swipeStart = event->pos();
        m_tracking   = true;
    }
    QDialog::mousePressEvent(event);
}

void HomeScreenDialog::mouseReleaseEvent(QMouseEvent *event)
{
    if (m_tracking && event->button() == Qt::LeftButton) {
        const int deltaX = event->pos().x() - m_swipeStart.x();
        if (deltaX > SWIPE_THRESHOLD && !isSidebarVisible())
            showSidebar();
        else if (deltaX < -SWIPE_THRESHOLD && isSidebarVisible())
            hideSidebar();
        m_tracking = false;
    }
    QDialog::mouseReleaseEvent(event);
}

// ═════════════════════════════════════════════════════════════════════════════
//  PUBLIC SETTERS
// ═════════════════════════════════════════════════════════════════════════════
void HomeScreenDialog::setDoctorName(const QString &name)
{
    ui->lbl_currentDoctorName->setText("Name: " + name);
}

void HomeScreenDialog::setDoctorFormula(const QString &formula)
{
    ui->lbl_currentDoctorFormula->setText("Formula: " + formula);
}

void HomeScreenDialog::setPatientName(const QString &name)
{
    ui->lbl_currentPatientName->setText(name);
}

void HomeScreenDialog::showPage(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}

void HomeScreenDialog::updateClock()
{
    ui->lbl_time->setText(QTime::currentTime().toString("hh:mm"));
}

// ═════════════════════════════════════════════════════════════════════════════
//  SIDEBAR / TABLE REFRESH HELPERS
// ═════════════════════════════════════════════════════════════════════════════

// Re-queries the doctor table for the given doctorId and updates the
// "Current Doctor" labels in the sidebar (name + formula).
void HomeScreenDialog::refreshDoctorSidebar(const QString &doctorId)
{
    if (doctorId.isEmpty())
        return;

    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery q(db);
    q.prepare("SELECT name, formula FROM doctor WHERE doctorid = :did LIMIT 1");
    q.bindValue(":did", doctorId);

    if (q.exec() && q.next()) {
        setDoctorName(q.value(0).toString());
        setDoctorFormula(q.value(1).toString());
    } else {
        qDebug() << "refreshDoctorSidebar: lookup failed for" << doctorId
                 << q.lastError().text();
    }
}

// Populates table_doctors (ID / Name / Lens1 / Lens2 / Lens3 / Formula).
void HomeScreenDialog::refreshDoctorTable()
{
    QTableWidget *table = ui->table_doctors;
    if (!table) return;

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "refreshDoctorTable: DB not open";
        return;
    }

    table->setUpdatesEnabled(false);
    table->setSortingEnabled(false);

    table->clearContents();
    table->setRowCount(0);
    table->setColumnCount(6);
    table->setHorizontalHeaderLabels(
        {"ID", "Name", "Lens1", "Lens2", "Lens3", "Formula"});

    QSqlQuery query(db);
    query.prepare(
        "SELECT doctorid, name, lenspresetone, lenspresettwo, lenspresetthree, formula "
        "FROM doctor ORDER BY name ASC"
        );

    if (query.exec()) {
        int row = 0;
        while (query.next()) {
            table->insertRow(row);
            for (int col = 0; col < 6; ++col)
                table->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
            ++row;
        }
    } else {
        qDebug() << "refreshDoctorTable query error:" << query.lastError().text();
    }

    table->setSortingEnabled(true);
    table->setUpdatesEnabled(true);
}

// ═════════════════════════════════════════════════════════════════════════════
//  MAIN PAGE BUTTONS
// ═════════════════════════════════════════════════════════════════════════════
void HomeScreenDialog::on_btn_doctors_clicked()
{
    ViewDoctorDialog dlg(this);
    dlg.exec();
}

void HomeScreenDialog::on_btn_patients_clicked()
{
    ViewPatientDialog dlg(this);
    dlg.exec();
}

void HomeScreenDialog::on_btn_calculator_clicked()
{
    AppManager::calculator->setPatientId(m_currentPatientId);
    AppManager::calculator->setDoctorId(m_currentDoctorId);
    this->hide();
    AppManager::calculator->show();
}

void HomeScreenDialog::on_btn_lenses_clicked()
{
    ViewLensDialog dlg(this);
    dlg.exec();
}

void HomeScreenDialog::on_btn_print_clicked()
{
    if (m_currentPatientId.isEmpty()) {
        PromptDialog dlg("No Patient Selected",
                         "Please load a patient before printing.",
                         this);
        dlg.exec();
        return;
    }

    if (m_currentDoctorId.isEmpty()) {
        PromptDialog dlg("No Doctor Selected",
                         "Please select a doctor before printing.",
                         this);
        dlg.exec();
        return;
    }

    // Lazy singleton may not have been constructed yet if preloading is
    // still staggered/in-flight — force it into existence before use.
    if (!AppManager::print) {
        AppManager::print = new PrintDialog();
    }

    AppManager::print->setPatientId(m_currentPatientId);
    AppManager::print->setDoctorId(m_currentDoctorId);
    AppManager::print->setPreviousPage(PrintDialog::HomePage);

    // Show the destination BEFORE hiding this one, so there's never a
    // moment with zero visible top-level windows (that gap is what was
    // triggering the auto-close on the board).
    AppManager::print->show();
    AppManager::print->raise();
    AppManager::print->activateWindow();

    this->hide();
}

void HomeScreenDialog::on_btn_settings_clicked()
{
    PreferencesDialog dlg(this);
    dlg.exec();
}

void HomeScreenDialog::on_btn_measure_clicked()
{
    if (m_currentPatientId.isEmpty()) {
        PromptDialog dlg("No Patient Selected",
                         "Please load a patient from the patient chooser first.",
                         this);
        dlg.exec();
        return;
    }

    if (m_currentDoctorId.isEmpty()) {
        PromptDialog dlg("No Doctor Selected",
                         "Please load a doctor from the doctor chooser first.",
                         this);
        dlg.exec();
        return;
    }

    AppManager::measure->loadContext(m_currentPatientId, m_currentDoctorId);
    this->hide();
    AppManager::measure->show();
}

// ═════════════════════════════════════════════════════════════════════════════
//  SETTINGS PAGE
// ═════════════════════════════════════════════════════════════════════════════
void HomeScreenDialog::on_btn_calibrate_clicked()
{
    CalibrationDialog dlg(this);
    dlg.exec();
}

void HomeScreenDialog::on_btn_back_clicked()
{
    this->hide();
    AppManager::welcome->show();

    // welcome refresh pannanum ippo — since finished-signal path illa
    AppManager::welcome->loadPatients();
    const QString lastPatientId = AppManager::welcome->getLastPatientId();
    if (!lastPatientId.isEmpty())
        AppManager::welcome->selectPatientById(lastPatientId);
}

// ═════════════════════════════════════════════════════════════════════════════
//  DOCTOR SIDEBAR
// ═════════════════════════════════════════════════════════════════════════════
void HomeScreenDialog::on_btn_currentDoctorChooser_clicked()
{
    refreshDoctorTable();
    showPage(PAGE_DOCTORS);
}

void HomeScreenDialog::on_btn_currentDoctorLogo_clicked()
{
    refreshDoctorTable();
    showPage(PAGE_DOCTORS);
}

void HomeScreenDialog::on_btn_currentDocAdd_clicked()
{
    AddDoctorDialog *dlg = new AddDoctorDialog(this);
    if (dlg->exec() == QDialog::Accepted) {
        refreshDoctorTable();
    }
    delete dlg;
}

void HomeScreenDialog::on_btn_currentDocEdit_clicked()
{
    // TODO: open edit dialog for currently selected doctor
}

void HomeScreenDialog::on_btn_currentDocView_clicked()
{
    ViewDoctorDialog dlg(this);
    dlg.exec();
}

void HomeScreenDialog::on_btn_currentDoctorLoad_clicked()
{
    QTableWidget *table = ui->table_doctors;
    const int row = table->currentRow();

    if (row < 0)
        return;

    m_currentDoctorId     = table->item(row, 0) ? table->item(row, 0)->text() : "";
    const QString name    = table->item(row, 1) ? table->item(row, 1)->text() : "";
    const QString formula = table->item(row, 5) ? table->item(row, 5)->text() : "";

    ui->lbl_currentDoctorName->setText("Name: " + name);
    ui->lbl_currentDoctorFormula->setText("Formula: " + formula);

    showPage(PAGE_MAIN);
}

void HomeScreenDialog::on_btn_currentDoctorChooserExit_clicked()
{
    showPage(PAGE_MAIN);
}

void HomeScreenDialog::on_btn_currentDoctorMore_clicked()
{
    // TODO: popup menu with Add / Edit / View
}

// ═════════════════════════════════════════════════════════════════════════════
//  PATIENT SIDEBAR
// ═════════════════════════════════════════════════════════════════════════════
void HomeScreenDialog::on_btn_currentPatientChooser_clicked()
{
    refreshPatientTable();
    showPage(PAGE_PATIENTS);
}

void HomeScreenDialog::on_btn_currentPatientLogo_clicked()
{
    refreshPatientTable();
    showPage(PAGE_PATIENTS);
}

void HomeScreenDialog::on_btn_currentPatientAdd_clicked()
{
    AddPatientDialog *dlg = new AddPatientDialog(this);
    if (dlg->exec() == QDialog::Accepted) {
        refreshPatientTable();
    }
    delete dlg;
}

void HomeScreenDialog::on_btn_currentPatientEdit_clicked()
{
    // TODO: open edit dialog for currently selected patient
}

void HomeScreenDialog::on_btn_currentPatientView_clicked()
{
    ViewPatientDialog dlg(this);
    connect(&dlg, &ViewPatientDialog::patientSelected,
            this, &HomeScreenDialog::applyPatientSelection);
    dlg.exec();
}

void HomeScreenDialog::applyPatientSelection(const QString &patientId)
{
    if (patientId.isEmpty()) return;

    m_currentPatientId = patientId;

    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery q(db);
    q.prepare("SELECT name FROM patient WHERE patientid = :pid LIMIT 1");
    q.bindValue(":pid", patientId);
    QString name;
    if (q.exec() && q.next())
        name = q.value(0).toString();

    ui->lbl_currentPatientName->setText(m_currentPatientId + " - " + name);

    // Resolve the most-recently-used doctor for this patient
    QSqlQuery dq(db);
    dq.prepare("SELECT doctorid FROM reading WHERE patientid = :pid ORDER BY rowid DESC LIMIT 1");
    dq.bindValue(":pid", patientId);
    if (dq.exec() && dq.next()) {
        const QString did = dq.value(0).toString();
        if (!did.isEmpty()) {
            m_currentDoctorId = did;
            refreshDoctorSidebar(did);
        }
    }
}

void HomeScreenDialog::on_btn_currentPatientLoad_clicked()
{
    QTableWidget *table = ui->table_patients;
    const int row = table->currentRow();

    if (row < 0)
        return;

    m_currentPatientId  = table->item(row, 0) ? table->item(row, 0)->text() : "";
    const QString name  = table->item(row, 2) ? table->item(row, 2)->text() : "";

    ui->lbl_currentPatientName->setText(m_currentPatientId + " - " + name);

    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery dq(db);
    dq.prepare("SELECT doctorid FROM reading WHERE patientid = :pid ORDER BY rowid DESC LIMIT 1");
    dq.bindValue(":pid", m_currentPatientId);
    if (dq.exec() && dq.next()) {
        const QString did = dq.value(0).toString();
        if (!did.isEmpty()) {
            m_currentDoctorId = did;
            refreshDoctorSidebar(did);
        }
    }

    showPage(PAGE_MAIN);
}

void HomeScreenDialog::on_btn_currentPatientChooserExit_clicked()
{
    showPage(PAGE_MAIN);
}

void HomeScreenDialog::on_btn_currentPatientMore_clicked()
{
    // TODO: popup menu with Add / Edit / View
}

// ─────────────────────────────────────────────────────────────────────────────
void HomeScreenDialog::refreshPatientTable()
{
    QTableWidget *table = ui->table_patients;
    if (!table) return;

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "refreshPatientTable: DB not open";
        return;
    }

    table->setUpdatesEnabled(false);
    table->setSortingEnabled(false);

    table->clearContents();
    table->setRowCount(0);
    table->setColumnCount(6);
    table->setHorizontalHeaderLabels(
        {"ID", "pID", "Name", "Gender", "Age", "Contact"});

    QSqlQuery query(db);
    query.prepare(
        "SELECT patientid, custPatientID, name, gender, age, phone "
        "FROM patient ORDER BY name ASC"
        );

    if (query.exec()) {
        int row = 0;
        while (query.next()) {
            table->insertRow(row);
            const QString genderStr = (query.value(3).toInt() == 0) ? "M" : "F";
            table->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
            table->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
            table->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
            table->setItem(row, 3, new QTableWidgetItem(genderStr));
            table->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));
            table->setItem(row, 5, new QTableWidgetItem(query.value(5).toString()));
            ++row;
        }
    } else {
        qDebug() << "refreshPatientTable query error:" << query.lastError().text();
    }

    table->setSortingEnabled(true);
    table->setUpdatesEnabled(true);
}

void HomeScreenDialog::loadContext(const QString &patientId, const QString &doctorId)
{
    m_currentPatientId = patientId;
    m_currentDoctorId  = doctorId;

    if (!patientId.isEmpty())
        ui->lbl_currentPatientName->setText(patientId);

    QTimer::singleShot(0, this, [this, patientId, doctorId]() {
        if (!patientId.isEmpty()) {
            QSqlDatabase db = QSqlDatabase::database();
            QSqlQuery q(db);
            q.prepare("SELECT name FROM patient WHERE patientid = :pid LIMIT 1");
            q.bindValue(":pid", patientId);
            if (q.exec() && q.next())
                ui->lbl_currentPatientName->setText(patientId + " - " + q.value(0).toString());
            else
                ui->lbl_currentPatientName->setText(patientId);
        }
        refreshDoctorSidebar(doctorId);
    });
}
