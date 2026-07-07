#include "welcomedialog.h"
#include "ui_welcomedialog.h"
#include "addpatientdialog.h"
#include "adddoctordialog.h"
#include "measuredialog.h"
#include "promptdialog.h"
#include "homescreendialog.h"
#include <QApplication>
#include <QDebug>
#include "AppManager.h"

#include "viewdoctordialog.h"
#include "viewpatientdialog.h"
#include "viewlensdialog.h"
#include "preferencesdialog.h"
#include "calibrationdialog.h"
#include "printdialog.h"
#include "promptdialog.h"
#include "calculatordialog.h"


// ─────────────────────────────────────────────────────────────
//  Constructor / Destructor
// ─────────────────────────────────────────────────────────────
welcomeDialog::welcomeDialog(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WelcomeDialog)
    , m_lastPatientId("")
{
    ui->setupUi(this);

    m_lastPatientId.clear();

    this->setCursor(Qt::ArrowCursor);

    // ✅ reuse main.cpp's connection, never close it
    db = QSqlDatabase::database();
    if (!db.isOpen())
        qDebug() << "welcomedialog: DB not open!";

    ensureDefaultDoctor();
    loadPatients();

    // ── Clock ─────────────────────────────────────────────────
    clockTimer = new QTimer(this);
    connect(clockTimer, &QTimer::timeout, this, &welcomeDialog::updateTime);
    clockTimer->start(1000);
    updateTime();

    // ── ComboBox signal ───────────────────────────────────────
    connect(ui->comboBox_patientSelect,
            QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &welcomeDialog::onPatientSelectionChanged);
}

welcomeDialog::~welcomeDialog()
{
    delete ui;
}

// ─────────────────────────────────────────────────────────────
//  Refresh patient list every time this screen becomes visible
//  (needed because AppManager reuses this instance via hide()/show()
//  instead of constructing it fresh each time)
// ─────────────────────────────────────────────────────────────
void welcomeDialog::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);
    loadPatients();
}

// ─────────────────────────────────────────────────────────────
//  Database — kept for compatibility but simplified
// ─────────────────────────────────────────────────────────────
bool welcomeDialog::openDatabase()
{
    db = QSqlDatabase::database(); // ✅ reuse main.cpp connection
    if (!db.isOpen()) {
        qDebug() << "DB not open!";
        return false;
    }
    return true;
}

QString welcomeDialog::getLastPatientId()
{
    return m_lastPatientId;
}

// ─────────────────────────────────────────────────────────────
//  Ensure Default Doctor "Adithya"
// ─────────────────────────────────────────────────────────────
QString welcomeDialog::ensureDefaultDoctor()
{
    QSqlQuery query(db);
    query.prepare("SELECT doctorid FROM doctor WHERE LOWER(name) = 'adithya' LIMIT 1");
    if (query.exec() && query.next()) {
        m_defaultDoctorId = query.value(0).toString();
        return m_defaultDoctorId;
    }

    QString doctorID = "DOC-0001";
    query.prepare(
        "INSERT INTO doctor (doctorid, name, lenspresetone, lenspresettwo, "
        "lenspresetthree, formula) VALUES (:did, 'Adithya', '', '', '', 'SRKT')");
    query.bindValue(":did", doctorID);
    if (query.exec()) {
        m_defaultDoctorId = doctorID;
        qDebug() << "Default doctor 'Adithya' created with id:" << m_defaultDoctorId;
    } else {
        qDebug() << "Failed to create default doctor:" << query.lastError().text();
    }
    return m_defaultDoctorId;
}

void welcomeDialog::ensurePatientHasDoctor(const QString & /*patientId*/) {}

QString welcomeDialog::resolveDoctor(const QString &patientId)
{
    QSqlQuery query(db);

    // Step 1: check reading history
    query.prepare(
        "SELECT doctorid FROM reading WHERE patientid = :pid "
        "ORDER BY rowid DESC LIMIT 1");
    query.bindValue(":pid", patientId);
    if (query.exec() && query.next()) {
        const QString did = query.value(0).toString();
        if (!did.isEmpty()) return did;
    }

    // Step 2: most recently added custom doctor
    query.prepare(
        "SELECT doctorid FROM doctor WHERE LOWER(name) != 'adithya' "
        "ORDER BY rowid DESC LIMIT 1");
    if (query.exec() && query.next()) {
        const QString customDid = query.value(0).toString();
        if (!customDid.isEmpty()) return customDid;
    }

    // Step 3: fallback to Adithya
    return ensureDefaultDoctor();
}

// ─────────────────────────────────────────────────────────────
//  Clock
// ─────────────────────────────────────────────────────────────
void welcomeDialog::updateTime()
{
    ui->lbl_time->setText(QTime::currentTime().toString("hh:mm:ss"));
}

// ─────────────────────────────────────────────────────────────
//  Load Patients into comboBox
// ─────────────────────────────────────────────────────────────
void welcomeDialog::loadPatients()
{
    const QSignalBlocker blocker(ui->comboBox_patientSelect);

    QString previousPatient = m_lastPatientId;
    bool previousStillExists = false;

    ui->comboBox_patientSelect->clear();
    ui->comboBox_patientSelect->addItem("-- Select Patient --", "");

    QSqlQuery query(db);
    query.prepare("SELECT patientid, name FROM patient ORDER BY name ASC");

    if (query.exec()) {
        while (query.next()) {
            const QString pid  = query.value(0).toString();
            const QString name = query.value(1).toString();

            ui->comboBox_patientSelect->addItem(pid + " - " + name, pid);

            if (!previousPatient.isEmpty() && pid == previousPatient)
                previousStillExists = true;
        }
    } else {
        qDebug() << "loadPatients error:" << query.lastError().text();
    }

    // ✅ Most recently added patient — works on ANY database file with the
    // same schema, since it relies only on rowid (SQLite's built-in
    // insertion-order column), not on any hardcoded id.
    QString lastInsertedPatientId;
    QSqlQuery lastQuery(db);
    lastQuery.prepare("SELECT patientid FROM patient ORDER BY rowid DESC LIMIT 1");
    if (lastQuery.exec() && lastQuery.next())
        lastInsertedPatientId = lastQuery.value(0).toString();

    QString targetPatientId;
    if (previousStillExists) {
        // Keep whatever was already selected (e.g. reopening this screen,
        // or a patient was just added through AddPatientDialog).
        targetPatientId = previousPatient;
    } else if (!lastInsertedPatientId.isEmpty()) {
        // Previous selection is gone (deleted, or this is first load) ->
        // fall back to whichever patient is now last in the database.
        targetPatientId = lastInsertedPatientId;
    }

    if (!targetPatientId.isEmpty()) {
        int idx = ui->comboBox_patientSelect->findData(targetPatientId);
        if (idx >= 0) {
            ui->comboBox_patientSelect->setCurrentIndex(idx);
            m_lastPatientId = targetPatientId;
        }
    } else {
        ui->comboBox_patientSelect->setCurrentIndex(0);
        m_lastPatientId.clear();
    }

    // setCurrentIndex above happens inside QSignalBlocker scope, so force
    // a repaint here to make sure the newly selected text is drawn.
    ui->comboBox_patientSelect->update();
}

// ─────────────────────────────────────────────────────────────
//  Select a patient by ID after add
// ─────────────────────────────────────────────────────────────
void welcomeDialog::selectPatientById(const QString &patientId)
{
    if (patientId.isEmpty())
        return;

    m_lastPatientId = patientId;

    int idx = ui->comboBox_patientSelect->findData(patientId);

    if (idx >= 0)
        ui->comboBox_patientSelect->setCurrentIndex(idx);
}

// ─────────────────────────────────────────────────────────────
//  Slot: selection changed — clear any error label
// ─────────────────────────────────────────────────────────────
void welcomeDialog::onPatientSelectionChanged(int)
{
    m_lastPatientId =
        ui->comboBox_patientSelect->currentData().toString();
}

// ─────────────────────────────────────────────────────────────
//  ENTER button
// ─────────────────────────────────────────────────────────────
void welcomeDialog::on_btn_enter_clicked()
{
    const QString selectedPatientId =
        (ui->comboBox_patientSelect->currentIndex() > 0)
            ? ui->comboBox_patientSelect->currentData().toString()
            : QString();

    const QString resolvedDoctorId =
        selectedPatientId.isEmpty() ? QString() : resolveDoctor(selectedPatientId);

    AppManager::home->loadContext(selectedPatientId, resolvedDoctorId);

    this->hide();
    AppManager::home->show();
}

// ─────────────────────────────────────────────────────────────
//  Surgeon button — add patient
// ─────────────────────────────────────────────────────────────
void welcomeDialog::on_btn_surgeon_clicked()
{
    AddPatientDialog *apd = new AddPatientDialog(this);
    if (apd->exec() == QDialog::Accepted) {
        const QString newPatientId = apd->getNewPatientId();
        loadPatients();
        selectPatientById(newPatientId);
    }
    delete apd;
}

// ─────────────────────────────────────────────────────────────
//  NEW button — add patient or doctor
// ─────────────────────────────────────────────────────────────
void welcomeDialog::on_btn_newDoctor_2_clicked()
{
    PromptDialog askPatient("Add New", "Do you want to add a new Patient?", this);
    if (askPatient.exec() == QDialog::Accepted) {
        AddPatientDialog *apd = new AddPatientDialog(this);
        if (apd->exec() == QDialog::Accepted) {
            const QString newPatientId = apd->getNewPatientId();
            loadPatients();
            selectPatientById(newPatientId);
        }
        delete apd;
        return;
    }

    PromptDialog askDoctor("Add New", "Do you want to add a new Doctor?", this);
    if (askDoctor.exec() == QDialog::Accepted) {
        AddDoctorDialog *addDoc = new AddDoctorDialog(this);
        addDoc->exec();
        delete addDoc;
    }

    // this->close();
}

// ─────────────────────────────────────────────────────────────
//  A-Scan button
// ─────────────────────────────────────────────────────────────
void welcomeDialog::on_btn_ascan_clicked()
{
    if (ui->comboBox_patientSelect->currentIndex() <= 0) {
        PromptDialog dlg("Selection Required", "Please select a patient first!", this);
        dlg.exec();
        return;
    }

    const QString selectedPatientId = ui->comboBox_patientSelect->currentData().toString();
    const QString resolvedDoctorId  = resolveDoctor(selectedPatientId);

    AppManager::measure->loadContext(selectedPatientId, resolvedDoctorId);

    this->hide();
    AppManager::measure->show();
}


void welcomeDialog::on_btn_doctors_clicked()
{
    ViewDoctorDialog dlg(this);
    dlg.exec();
}

void welcomeDialog::on_btn_patients_clicked()
{
    ViewPatientDialog dlg(this);
    dlg.exec();
}

void welcomeDialog::on_btn_calculator_clicked()
{
    AppManager::calculator->setPatientId(m_currentPatientId);
    AppManager::calculator->setDoctorId(m_currentDoctorId);
    this->hide();
    AppManager::calculator->show();
}

void welcomeDialog::on_btn_lenses_clicked()
{
    ViewLensDialog dlg(this);
    dlg.exec();
}

void welcomeDialog::on_btn_print_clicked()
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


    if (!AppManager::print) {
        AppManager::print = new PrintDialog();
    }

    AppManager::print->setPatientId(m_currentPatientId);
    AppManager::print->setDoctorId(m_currentDoctorId);
    AppManager::print->setPreviousPage(PrintDialog::HomePage);

    AppManager::print->show();
    AppManager::print->raise();
    AppManager::print->activateWindow();

    this->hide();
}

void welcomeDialog::on_btn_settings_clicked()
{
    PreferencesDialog dlg(this);
    dlg.exec();
}

void welcomeDialog::on_btn_calibrate_clicked()
{
    CalibrationDialog dlg(this);
    dlg.exec();
}
