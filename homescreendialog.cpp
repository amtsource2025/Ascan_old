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

// ─────────────────────────────────────────────────────────────────────────────
HomeScreenDialog::HomeScreenDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HomeScreenDialog)
    , clockTimer(new QTimer(this))
    , snackbarTimer(new QTimer(this))
    , m_sidebarAnimation(nullptr)
    , m_contentAnimation(nullptr)        // ── NEW
    , m_tracking(false)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    setupSidebar();
    setupSidebarAnimation();

    grabGesture(Qt::SwipeGesture);
    setAttribute(Qt::WA_AcceptTouchEvents);

    connect(clockTimer, &QTimer::timeout, this, &HomeScreenDialog::updateClock);
    clockTimer->start(1000);
    updateClock();



    // Paste this anywhere in your constructor temporarily
    for (auto *b : findChildren<QPushButton*>())
        qDebug() << b->objectName() << b->geometry();

    const QRect dlg = this->geometry();
    m_contentFullRect = QRect(150,
                              ui->stackedWidget->geometry().y(),
                              dlg.width(),
                              ui->stackedWidget->geometry().height());
    ui->stackedWidget->setGeometry(m_contentFullRect);

    showPage(PAGE_MAIN);
}

// ── NEW: pre-loaded patient/doctor constructor ────────────────────────────────
HomeScreenDialog::HomeScreenDialog(const QString &patientId,
                                   const QString &doctorId,
                                   QWidget *parent)
    : HomeScreenDialog(parent)
{
    m_currentPatientId = patientId;
    m_currentDoctorId  = doctorId;

    if (!patientId.isEmpty())
        ui->lbl_currentPatientName->setText(patientId);
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
    // Hide sidebar off-screen to the left on startup
    ui->frame_sidebar->move(-SIDEBAR_WIDTH, ui->frame_sidebar->y());
    ui->frame_sidebar->hide();

    // ── On startup: stackedWidget fills the FULL dialog width ────────────────
    // Store the full-width rect so we always know the "no sidebar" state.
    // This rect is: x=0, y=0, w=dialog width, h=dialog height
    // We read it from the current stackedWidget geometry set in Designer,
    // but override x and width to always fill full width when sidebar is gone.
    const QRect dlg = this->geometry();
    m_contentFullRect = QRect(0,
                              ui->stackedWidget->geometry().y(),
                              dlg.width(),
                              ui->stackedWidget->geometry().height());

    // The "sidebar visible" rect — stackedWidget shifts right by SIDEBAR_WIDTH
    m_contentSidebarRect = QRect(SIDEBAR_WIDTH,
                                 ui->stackedWidget->geometry().y(),
                                 dlg.width() - SIDEBAR_WIDTH,
                                 ui->stackedWidget->geometry().height());

    // Apply full-width immediately on startup so buttons are centered
    ui->stackedWidget->setGeometry(m_contentFullRect);
}

void HomeScreenDialog::setupSidebarAnimation()
{
    // ── Sidebar slide animation ───────────────────────────────────────────────
    m_sidebarAnimation = new QPropertyAnimation(ui->frame_sidebar, "pos", this);
    m_sidebarAnimation->setDuration(ANIM_DURATION);
    m_sidebarAnimation->setEasingCurve(QEasingCurve::OutCubic);

    // ── Content area resize animation ─────────────────────────────────────────
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

    // Slide sidebar in from left
    m_sidebarAnimation->stop();
    m_sidebarAnimation->setStartValue(ui->frame_sidebar->pos());
    m_sidebarAnimation->setEndValue(QPoint(0, ui->frame_sidebar->y()));
    m_sidebarAnimation->start();

    // Shrink+shift content area to the right to make room for sidebar
    m_contentAnimation->stop();
    m_contentAnimation->setStartValue(ui->stackedWidget->geometry());
    m_contentAnimation->setEndValue(m_contentSidebarRect);
    m_contentAnimation->start();
}

void HomeScreenDialog::hideSidebar()
{
    // Slide sidebar out to the left
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

    // Expand content area back to full width — buttons re-center
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
    CalculatorDialog dlg(this);
    dlg.exec();
}

void HomeScreenDialog::on_btn_lenses_clicked()
{
    ViewLensDialog dlg(this);
    dlg.exec();
}

void HomeScreenDialog::on_btn_print_clicked()
{
    PrintDialog dlg(this);
    dlg.exec();
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

    MeasureDialog *measure = new MeasureDialog(m_currentPatientId,
                                               m_currentDoctorId, this);
    measure->exec();
    delete measure;
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
    this->accept();
}

// ═════════════════════════════════════════════════════════════════════════════
//  DOCTOR SIDEBAR
// ═════════════════════════════════════════════════════════════════════════════

void HomeScreenDialog::on_btn_currentDoctorChooser_clicked()
{
    showPage(PAGE_DOCTORS);
}

void HomeScreenDialog::on_btn_currentDoctorLogo_clicked()
{
    showPage(PAGE_DOCTORS);
}

void HomeScreenDialog::on_btn_currentDocAdd_clicked()
{
    AddDoctorDialog *dlg = new AddDoctorDialog(this);
    if (dlg->exec() == QDialog::Accepted)
        // showSnackbar("Doctor added successfully.");
    delete dlg;
}

void HomeScreenDialog::on_btn_currentDocEdit_clicked()
{

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

    if (row < 0) {
        // showSnackbar("Please select a doctor first.");
        return;
    }

    m_currentDoctorId     = table->item(row, 0) ? table->item(row, 0)->text() : "";
    const QString name    = table->item(row, 1) ? table->item(row, 1)->text() : "";
    const QString formula = table->item(row, 5) ? table->item(row, 5)->text() : "";

    ui->lbl_currentDoctorName->setText("Name: " + name);
    ui->lbl_currentDoctorFormula->setText("Formula: " + formula);

    showPage(PAGE_MAIN);
    // showSnackbar("Doctor loaded: " + name);
}

void HomeScreenDialog::on_btn_currentDoctorChooserExit_clicked()
{
    showPage(PAGE_MAIN);
}

// ═════════════════════════════════════════════════════════════════════════════
//  PATIENT SIDEBAR
// ═════════════════════════════════════════════════════════════════════════════

void HomeScreenDialog::on_btn_currentPatientChooser_clicked()
{
    showPage(PAGE_PATIENTS);
}

void HomeScreenDialog::on_btn_currentPatientLogo_clicked()
{
    showPage(PAGE_PATIENTS);
}

void HomeScreenDialog::on_btn_currentPatientAdd_clicked()
{
    AddPatientDialog *dlg = new AddPatientDialog(this);
    if (dlg->exec() == QDialog::Accepted) {
        // showSnackbar("Patient added successfully.");
        refreshPatientTable();
    }
    delete dlg;
}

void HomeScreenDialog::on_btn_currentPatientEdit_clicked()
{
    // showSnackbar("Edit Patient — not yet implemented.");
}

void HomeScreenDialog::on_btn_currentPatientView_clicked()
{
    ViewPatientDialog dlg(this);
    dlg.exec();
}

void HomeScreenDialog::on_btn_currentPatientLoad_clicked()
{
    QTableWidget *table = ui->table_patients;
    const int row = table->currentRow();

    if (row < 0) {
        // showSnackbar("Please select a patient first.");
        return;
    }

    m_currentPatientId  = table->item(row, 0) ? table->item(row, 0)->text() : "";
    const QString name  = table->item(row, 2) ? table->item(row, 2)->text() : "";

    ui->lbl_currentPatientName->setText(m_currentPatientId + " - " + name);

    showPage(PAGE_MAIN);
    // showSnackbar("Patient loaded: " + name);
}

void HomeScreenDialog::on_btn_currentPatientChooserExit_clicked()
{
    showPage(PAGE_MAIN);
}

// ─────────────────────────────────────────────────────────────────────────────
void HomeScreenDialog::refreshPatientTable()
{
    QTableWidget *table = ui->table_patients;
    if (!table) return;

    QSqlDatabase db = QSqlDatabase::database(); // ✅ just this one line
    if (!db.isOpen()) {
        qDebug() << "refreshPatientTable: DB not open";
        return;
    }

    const QString connName = "homescreen_refresh_conn";
    if (QSqlDatabase::contains(connName)) {
        db = QSqlDatabase::database(connName);
    } else {
        db = QSqlDatabase::database();
    }

    if (!db.open()) {
        qDebug() << "HomeScreenDialog refreshPatientTable DB error:"
                 << db.lastError().text();
        return;
    }

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
            QString genderStr = (query.value(3).toInt() == 0) ? "M" : "F";
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
}
