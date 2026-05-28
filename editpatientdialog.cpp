#include "editpatientdialog.h"
#include "ui_editpatientdialog.h"
#include "promptdialog.h"
#include <QTime>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

// ─────────────────────────────────────────────────────────────
//  Constructor / Destructor
// ─────────────────────────────────────────────────────────────
EditPatientDialog::EditPatientDialog(int patientDbId, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditPatientDialog)
    , clockTimer(new QTimer(this))
    , m_dbId(patientDbId)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    if (!openDatabase())
        qDebug() << "EditPatientDialog: Failed to open database!";

    // Clock
    connect(clockTimer, &QTimer::timeout, this, &EditPatientDialog::updateTime);
    clockTimer->start(1000);
    updateTime();

    // patID (auto-generated system ID) is read-only
    ui->lineEdit_patID->setReadOnly(true);

    loadPatient();
}

EditPatientDialog::~EditPatientDialog()
{
    if (db.isOpen())
        db.close();
    delete ui;
}

// ─────────────────────────────────────────────────────────────
//  Database
// ─────────────────────────────────────────────────────────────
bool EditPatientDialog::openDatabase()
{
    const QString connName = "editpatient_conn";
    if (QSqlDatabase::contains(connName)) {
        db = QSqlDatabase::database(connName);
    } else {
        db = QSqlDatabase::database();
    }
    if (!db.open()) {
        qDebug() << "DB Error:" << db.lastError().text();
        return false;
    }
    return true;
}

// ─────────────────────────────────────────────────────────────
//  Load existing patient data into fields
// ─────────────────────────────────────────────────────────────
void EditPatientDialog::loadPatient()
{
    QSqlQuery query(db);
    query.prepare("SELECT patientid, custPatientID, name, age, gender, phone, "
                  "rk1, rk2, rk, lk1, lk2, lk, "
                  "operatingmethod, operatingmode, operatingeye "
                  "FROM patient WHERE id = :id");
    query.bindValue(":id", m_dbId);

    if (!query.exec() || !query.next()) {
        qDebug() << "loadPatient error:" << query.lastError().text();
        return;
    }

    // ── Basic fields ──────────────────────────────────────────
    ui->lineEdit_patID->setText(query.value(0).toString());      // patientid (system)
    ui->lineEdit_CustPatID->setText(query.value(1).toString());  // custPatientID
    ui->lineEdit_patName->setText(query.value(2).toString());    // name
    ui->lineEdit_age->setText(query.value(3).toString());        // age
    ui->lineEdit_phone->setText(query.value(5).toString());      // phone

    // ── Gender (0 = Male, 1 = Female) ────────────────────────
    int gender = query.value(4).toInt();
    ui->checkBox_male->setChecked(gender == 0);
    ui->checkBox_female->setChecked(gender == 1);

    // ── Keratometer values ────────────────────────────────────
    ui->lineEdit_rk1->setText(query.value(6).toString());
    ui->lineEdit_rk2->setText(query.value(7).toString());
    ui->lineEdit_rk->setText(query.value(8).toString());
    ui->lineEdit_lk1->setText(query.value(9).toString());
    ui->lineEdit_lk2->setText(query.value(10).toString());
    ui->lineEdit_lk->setText(query.value(11).toString());

    // ── Operating Method (0=Aphakic, 1=Phakic, 2=Dense) ──────
    int method = query.value(12).toInt();
    ui->checkBox_aphakic->setChecked(method == 0);
    ui->checkBox_phakic->setChecked(method == 1);
    ui->checkBox_dense->setChecked(method == 2);

    // ── Operating Mode (0=Contact, 1=Immersion) ───────────────
    int mode = query.value(13).toInt();
    ui->checkBox_contact->setChecked(mode == 0);
    ui->checkBox_immersion->setChecked(mode == 1);

    // ── Operating Eye (0=Left, 1=Right) ───────────────────────
    int eye = query.value(14).toInt();
    ui->checkBox_left->setChecked(eye == 0);
    ui->checkBox_right->setChecked(eye == 1);
}

// ─────────────────────────────────────────────────────────────
//  Clock
// ─────────────────────────────────────────────────────────────
void EditPatientDialog::updateTime()
{
    ui->lbl_time->setText(QTime::currentTime().toString("hh:mm"));
}

// ─────────────────────────────────────────────────────────────
//  Save
// ─────────────────────────────────────────────────────────────
void EditPatientDialog::on_btn_save_clicked()
{
    QString custPatID = ui->lineEdit_CustPatID->text().trimmed();
    QString name      = ui->lineEdit_patName->text().trimmed();
    int     age       = ui->lineEdit_age->text().toInt();
    QString phone     = ui->lineEdit_phone->text().trimmed();

    if (name.isEmpty()) {
        PromptDialog p("Validation", "Patient Name cannot be empty.", this);
        p.exec();
        return;
    }

    // Gender
    int gender = ui->checkBox_female->isChecked() ? 1 : 0;

    // Keratometer
    double rk1 = ui->lineEdit_rk1->text().toDouble();
    double rk2 = ui->lineEdit_rk2->text().toDouble();
    double rk  = ui->lineEdit_rk->text().toDouble();
    double lk1 = ui->lineEdit_lk1->text().toDouble();
    double lk2 = ui->lineEdit_lk2->text().toDouble();
    double lk  = ui->lineEdit_lk->text().toDouble();

    // Operating method (0=Aphakic, 1=Phakic, 2=Dense)
    int method = 0;
    if (ui->checkBox_phakic->isChecked())  method = 1;
    if (ui->checkBox_dense->isChecked())   method = 2;

    // Operating mode (0=Contact, 1=Immersion)
    int mode = ui->checkBox_immersion->isChecked() ? 1 : 0;

    // Operating eye (0=Left, 1=Right)
    int eye = ui->checkBox_right->isChecked() ? 1 : 0;

    QSqlQuery query(db);
    query.prepare("UPDATE patient SET "
                  "custPatientID = :cid, name = :name, age = :age, "
                  "phone = :phone, gender = :gender, "
                  "rk1 = :rk1, rk2 = :rk2, rk = :rk, "
                  "lk1 = :lk1, lk2 = :lk2, lk = :lk, "
                  "operatingmethod = :method, operatingmode = :mode, "
                  "operatingeye = :eye "
                  "WHERE id = :id");

    query.bindValue(":cid",    custPatID);
    query.bindValue(":name",   name);
    query.bindValue(":age",    age);
    query.bindValue(":phone",  phone);
    query.bindValue(":gender", gender);
    query.bindValue(":rk1",    rk1);
    query.bindValue(":rk2",    rk2);
    query.bindValue(":rk",     rk);
    query.bindValue(":lk1",    lk1);
    query.bindValue(":lk2",    lk2);
    query.bindValue(":lk",     lk);
    query.bindValue(":method", method);
    query.bindValue(":mode",   mode);
    query.bindValue(":eye",    eye);
    query.bindValue(":id",     m_dbId);

    if (!query.exec()) {
        qDebug() << "Save patient error:" << query.lastError().text();
        PromptDialog err("Database Error",
                         "Failed to save:\n" + query.lastError().text(), this);
        err.exec();
        return;
    }

    QTimer::singleShot(800, this, [this]() { accept(); });
}

// ─────────────────────────────────────────────────────────────
//  Cancel
// ─────────────────────────────────────────────────────────────
void EditPatientDialog::on_btn_cancel_clicked()
{
    reject();
}
