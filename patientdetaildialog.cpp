#include "patientdetaildialog.h"
#include "ui_patientdetaildialog.h"
#include <QTime>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

PatientDetailDialog::PatientDetailDialog(int patientDbId, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PatientDetailDialog)
    , db(QSqlDatabase::database())
    , clockTimer(new QTimer(this))
    , m_patientDbId(patientDbId)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    // Clock
    connect(clockTimer, &QTimer::timeout, this, &PatientDetailDialog::updateTime);
    clockTimer->start(1000);
    updateTime();

    // All inputs read-only / disabled
    const auto edits = findChildren<QLineEdit *>();
    for (auto *e : edits)
        e->setReadOnly(true);

    const auto boxes = findChildren<QCheckBox *>();
    for (auto *b : boxes)
        b->setEnabled(false);

    loadPatient();
}

PatientDetailDialog::~PatientDetailDialog()
{
    delete ui;
}

void PatientDetailDialog::updateTime()
{
    ui->lbl_time->setText(QTime::currentTime().toString("hh:mm"));
}

void PatientDetailDialog::loadPatient()
{
    QSqlQuery q(db);
    q.prepare(
        "SELECT custPatientID, name, age, gender, phone, "
        "operatingmethod, operatingmode, operatingeye, "
        "lk1, lk2, lk, rk1, rk2, rk "
        "FROM patient WHERE id = :id");
    q.bindValue(":id", m_patientDbId);

    if (!q.exec() || !q.next()) {
        qDebug() << "PatientDetailDialog loadPatient error:" << q.lastError().text();
        return;
    }

    ui->lineEdit_patID->setText(q.value(0).toString());
    ui->lineEdit_patName->setText(q.value(1).toString());
    ui->lineEdit_age->setText(q.value(2).toString());

    // Gender checkboxes
    int gender = q.value(3).toInt();   // 0 = Male, 1 = Female
    ui->checkBox_male->setChecked(gender == 0);
    ui->checkBox_female->setChecked(gender == 1);

    ui->lineEdit_phone->setText(q.value(4).toString());

    // Operating method  (0 = Aphakic, 1 = Phakic, 2 = Dense)
    int opMethod = q.value(5).toInt();
    ui->checkBox_aphakic->setChecked(opMethod == 0);
    ui->checkBox_phakic->setChecked(opMethod == 1);
    ui->checkBox_dense->setChecked(opMethod == 2);

    // Operating mode  (0 = Contact, 1 = Immersion)
    int opMode = q.value(6).toInt();
    ui->checkBox_contact->setChecked(opMode == 0);
    ui->checkBox_immersion->setChecked(opMode == 1);

    // Operating eye  (0 = Left, 1 = Right)
    int opEye = q.value(7).toInt();
    ui->checkBox_left->setChecked(opEye == 0);
    ui->checkBox_right->setChecked(opEye == 1);

    // Keratometry — Left eye
    ui->lineEdit_lk1->setText(q.value(8).toString());
    ui->lineEdit_lk2->setText(q.value(9).toString());
    ui->lineEdit_lk->setText(q.value(10).toString());

    // Keratometry — Right eye
    ui->lineEdit_rk1->setText(q.value(11).toString());
    ui->lineEdit_rk2->setText(q.value(12).toString());
    ui->lineEdit_rk->setText(q.value(13).toString());
}

void PatientDetailDialog::on_btn_close_clicked()
{
    reject();
}
