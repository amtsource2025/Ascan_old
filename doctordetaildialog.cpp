#include "doctordetaildialog.h"
#include "ui_doctordetaildialog.h"
#include <QTime>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>

DoctorDetailDialog::DoctorDetailDialog(const QString &doctorId, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DoctorDetailDialog)
    , db(QSqlDatabase::database())
    , clockTimer(new QTimer(this))
    , m_doctorId(doctorId)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    // Clock
    connect(clockTimer, &QTimer::timeout, this, &DoctorDetailDialog::updateTime);
    clockTimer->start(1000);
    updateTime();

    // All value fields read-only
    const auto edits = findChildren<QLineEdit *>();
    for (auto *e : edits)
        e->setReadOnly(true);

    loadDoctor();
    loadPatientCombo();

    connect(ui->comboBox_patient,
            QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &DoctorDetailDialog::onPatientSelected);
}

DoctorDetailDialog::~DoctorDetailDialog()
{
    delete ui;
}

// ── Clock ─────────────────────────────────────────────────────────────────
void DoctorDetailDialog::updateTime()
{
    ui->lbl_time->setText(QTime::currentTime().toString("hh:mm"));
}

// ── Load doctor header ─────────────────────────────────────────────────────
void DoctorDetailDialog::loadDoctor()
{
    QSqlQuery q(db);
    q.prepare("SELECT doctorid, name, formula, "
              "lenspresetone, lenspresettwo, lenspresetthree "
              "FROM doctor WHERE doctorid = :id");
    q.bindValue(":id", m_doctorId);
    if (!q.exec() || !q.next()) {
        qDebug() << "DoctorDetailDialog loadDoctor error:" << q.lastError().text();
        return;
    }

    ui->lineEdit_docID->setText(q.value(0).toString());
    ui->lineEdit_docName->setText(q.value(1).toString());
    ui->lineEdit_primaryFormula->setText(q.value(2).toString());

    // Lens presets stored as JSON strings: {"iol":"...","asrkt":"...","asrkii":"...","acd":"...","sf":"...","a0":"...","a1":"...","a2":"..."}
    loadLensPreset(q.value(3).toString(), 0);   // Lens1
    loadLensPreset(q.value(4).toString(), 1);   // Lens2
    loadLensPreset(q.value(5).toString(), 2);   // Lens3
}

void DoctorDetailDialog::loadLensPreset(const QString &presetJson, int tabIndex)
{
    // If your lens presets are plain strings (not JSON), skip JSON parsing
    // and fill them into the IOL label directly.
    QJsonDocument doc = QJsonDocument::fromJson(presetJson.toUtf8());
    QJsonObject   obj = doc.object();

    auto val = [&](const QString &key) { return obj.value(key).toString(); };

    populateLensTab(tabIndex,
                    val("iol"),
                    val("asrkt"), val("asrkii"),
                    val("acd"),   val("sf"),
                    val("a0"),    val("a1"), val("a2"));
}

void DoctorDetailDialog::populateLensTab(int tab,
                                         const QString &iol,
                                         const QString &asrkt, const QString &asrkii,
                                         const QString &acd,  const QString &sf,
                                         const QString &a0,   const QString &a1,
                                         const QString &a2)
{
    switch (tab) {
    case 0:  // Lens1
        ui->lbl_iolLensOne->setText("IOL: " + iol);
        ui->lbl_asrktLensOneValue->setText(asrkt);
        ui->lbl_asrkiiLensOneValue->setText(asrkii);
        ui->lbl_acdLensOneValue->setText(acd);
        ui->lbl_sfLensOneValue->setText(sf);
        ui->lbl_a0LensOneValue->setText(a0);
        ui->lbl_a1LensOneValue->setText(a1);
        ui->lbl_a2LensOneValue->setText(a2);
        break;
    case 1:  // Lens2
        ui->lbl_iolLensTwo->setText("IOL: " + iol);
        ui->lbl_asrktLensTwoValue->setText(asrkt);
        ui->lbl_asrkiiLensTwoValue->setText(asrkii);
        ui->lbl_acdLensTwoValue->setText(acd);
        ui->lbl_sfLensTwoValue->setText(sf);
        ui->lbl_a0LensTwoValue->setText(a0);
        ui->lbl_a1LensTwoValue->setText(a1);
        ui->lbl_a2LensTwoValue->setText(a2);
        break;
    case 2:  // Lens3
        ui->lbl_iolLensThree->setText("IOL: " + iol);
        ui->lbl_asrktLensThreeValue->setText(asrkt);
        ui->lbl_asrkiiLensThreeValue->setText(asrkii);
        ui->lbl_acdLensThreeValue->setText(acd);
        ui->lbl_sfLensThreeValue->setText(sf);
        ui->lbl_a0LensThreeValue->setText(a0);
        ui->lbl_a1LensThreeValue->setText(a1);
        ui->lbl_a2LensThreeValue->setText(a2);
        break;
    default: break;
    }
}

// ── Patient combo ─────────────────────────────────────────────────────────
void DoctorDetailDialog::loadPatientCombo()
{
    ui->comboBox_patient->clear();
    ui->comboBox_patient->addItem("-- Select patient --", QVariant(-1));

    QSqlQuery q(db);
    q.prepare("SELECT id, name FROM patient WHERE doctorid = :did ORDER BY name ASC");
    q.bindValue(":did", m_doctorId);
    if (!q.exec()) {
        qDebug() << "loadPatientCombo error:" << q.lastError().text();
        return;
    }
    while (q.next())
        ui->comboBox_patient->addItem(q.value(1).toString(), q.value(0).toInt());
}

void DoctorDetailDialog::onPatientSelected(int index)
{
    int dbId = ui->comboBox_patient->itemData(index).toInt();
    if (dbId < 0) {
        // Clear patient fields
        ui->lineEdit_patName->clear();
        ui->lineEdit_patientAge->clear();
        ui->lineEdit_patientGender->clear();
        ui->lineEdit_patientContact->clear();
        ui->lbl_currentPatientLK1Value->clear();
        ui->lbl_currentPatientLK2Value->clear();
        ui->lbl_currentPatientLKValue->clear();
        ui->lbl_currentPatientRK1Value->clear();
        ui->lbl_currentPatientRK2Value->clear();
        ui->lbl_currentPatientRKValue->clear();
        ui->lineEdit_patOpEye->setText("");
        ui->lineEdit_patOpMethod->setText("");
        ui->lineEdit_patOpMode->setText("");
        return;
    }
    loadPatientDetails(dbId);
}

void DoctorDetailDialog::loadPatientDetails(int patientDbId)
{
    QSqlQuery q(db);
    q.prepare("SELECT name, age, gender, phone, "
              "lk1, lk2, lk, rk1, rk2, rk, "
              "operatingeye, operatingmethod, operatingmode "
              "FROM patient WHERE id = :id");
    q.bindValue(":id", patientDbId);
    if (!q.exec() || !q.next()) {
        qDebug() << "loadPatientDetails error:" << q.lastError().text();
        return;
    }

    ui->lineEdit_patName->setText(q.value(0).toString());
    ui->lineEdit_patientAge->setText(q.value(1).toString());
    ui->lineEdit_patientGender->setText(q.value(2).toInt() == 0 ? "Male" : "Female");
    ui->lineEdit_patientContact->setText(q.value(3).toString());

    ui->lbl_currentPatientLK1Value->setText(q.value(4).toString());
    ui->lbl_currentPatientLK2Value->setText(q.value(5).toString());
    ui->lbl_currentPatientLKValue->setText(q.value(6).toString());
    ui->lbl_currentPatientRK1Value->setText(q.value(7).toString());
    ui->lbl_currentPatientRK2Value->setText(q.value(8).toString());
    ui->lbl_currentPatientRKValue->setText(q.value(9).toString());

    ui->lineEdit_patOpEye->setText(q.value(10).toString());
    ui->lineEdit_patOpMethod->setText(q.value(11).toString());
    ui->lineEdit_patOpMode->setText(q.value(12).toString());
}

// ── Close ─────────────────────────────────────────────────────────────────
void DoctorDetailDialog::on_btn_close_clicked()
{
    reject();
}
