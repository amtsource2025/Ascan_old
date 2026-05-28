#include "welcomedialog.h"
#include "ui_welcomedialog.h"
#include "addpatientdialog.h"
#include "adddoctordialog.h"
#include "measuredialog.h"
#include "promptdialog.h"
#include "homescreendialog.h"

// ─────────────────────────────────────────────────────────────
//  Constructor / Destructor
// ─────────────────────────────────────────────────────────────
welcomedialog::welcomedialog(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WelcomeDialog)
{
    ui->setupUi(this);

    // ✅ Fix: just reuse main.cpp's connection, never close it
    db = QSqlDatabase::database();
    if (!db.isOpen())
        qDebug() << "welcomedialog: DB not open!";

    ensureDefaultDoctor();
    loadPatients();

    // ── Clock ─────────────────────────────────────────────────
    clockTimer = new QTimer(this);
    connect(clockTimer, &QTimer::timeout, this, &welcomedialog::updateTime);
    clockTimer->start(1000);
    updateTime();

    // ── ComboBox signal ───────────────────────────────────────
    connect(ui->comboBox_patientSelect,
            QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &welcomedialog::onPatientSelectionChanged);
}

welcomedialog::~welcomedialog()
{
    // ✅ Do NOT close db — owned by main.cpp
    delete ui;
}

// ─────────────────────────────────────────────────────────────
//  Database — kept for compatibility but simplified
// ─────────────────────────────────────────────────────────────
bool welcomedialog::openDatabase()
{
    db = QSqlDatabase::database(); // ✅ reuse main.cpp connection
    if (!db.isOpen()) {
        qDebug() << "DB not open!";
        return false;
    }
    return true;
}

// ─────────────────────────────────────────────────────────────
//  Ensure Default Doctor "Adithya"
// ─────────────────────────────────────────────────────────────
QString welcomedialog::ensureDefaultDoctor()
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

void welcomedialog::ensurePatientHasDoctor(const QString & /*patientId*/) {}

QString welcomedialog::resolveDoctor(const QString &patientId)
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
void welcomedialog::updateTime()
{
    ui->lbl_time->setText(QTime::currentTime().toString("hh:mm:ss"));
}

// ─────────────────────────────────────────────────────────────
//  Load Patients into comboBox
// ─────────────────────────────────────────────────────────────
void welcomedialog::loadPatients()
{
    const QSignalBlocker blocker(ui->comboBox_patientSelect);
    ui->comboBox_patientSelect->clear();
    ui->comboBox_patientSelect->addItem("-- Select Patient --", "");

    QSqlQuery query(db);
    query.prepare("SELECT patientid, name FROM patient ORDER BY name ASC");

    if (query.exec()) {
        while (query.next()) {
            const QString pid  = query.value(0).toString();
            const QString name = query.value(1).toString();
            ui->comboBox_patientSelect->addItem(pid + " - " + name, pid);
        }
    } else {
        qDebug() << "loadPatients error:" << query.lastError().text();
    }
}

// ─────────────────────────────────────────────────────────────
//  Select a patient by ID after add
// ─────────────────────────────────────────────────────────────
void welcomedialog::selectPatientById(const QString &patientId)
{
    if (patientId.isEmpty()) return;
    const int idx = ui->comboBox_patientSelect->findData(patientId);
    if (idx >= 0)
        ui->comboBox_patientSelect->setCurrentIndex(idx);
}

// ─────────────────────────────────────────────────────────────
//  Slot: selection changed — clear any error label
// ─────────────────────────────────────────────────────────────
void welcomedialog::onPatientSelectionChanged(int /*index*/)
{
    ui->label->clear();
}

// ─────────────────────────────────────────────────────────────
//  ENTER button
// ─────────────────────────────────────────────────────────────
void welcomedialog::on_btn_enter_clicked()
{
    if (ui->comboBox_patientSelect->currentIndex() <= 0) {
        PromptDialog dlg("Selection Required", "Please select a patient first!", this);
        dlg.exec();
        return;
    }

    const QString selectedPatientId =
        ui->comboBox_patientSelect->currentData().toString();
    const QString resolvedDoctorId = resolveDoctor(selectedPatientId);

    MeasureDialog *md = new MeasureDialog(selectedPatientId, resolvedDoctorId, this);
    md->exec();
    delete md;

    loadPatients();
}

// ─────────────────────────────────────────────────────────────
//  Surgeon button — add patient
// ─────────────────────────────────────────────────────────────
void welcomedialog::on_btn_surgeon_clicked()
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
void welcomedialog::on_btn_newDoctor_2_clicked()
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
}

// ─────────────────────────────────────────────────────────────
//  A-Scan button
// ─────────────────────────────────────────────────────────────
void welcomedialog::on_btn_ascan_clicked()
{
    HomeScreenDialog homeScreen(this);
    homeScreen.exec();
    loadPatients(); // refresh in case patients were added inside HomeScreen
}
