#include "preferencesdialog.h"
#include "ui_preferencesdialog.h"
#include <QDialog>
#include <QTimer>
#include <QTime>          // ✅ add this
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

PreferencesDialog::PreferencesDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PreferencesDialog)
    , clockTimer(new QTimer(this))
    , db(QSqlDatabase::database())       // ✅ reuse main.cpp's connection
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    // ── Clock ─────────────────────────────────────────────────
    connect(clockTimer, &QTimer::timeout, this, &PreferencesDialog::updateTime);
    clockTimer->start(1000);
    updateTime();

    // ── Start on General page (index 0) ───────────────────────
    ui->stackedWidget->setCurrentIndex(0);

    // ── Load data ─────────────────────────────────────────────
    loadGeneralSettings();
}

PreferencesDialog::~PreferencesDialog()
{
    // ✅ Do NOT close db — owned by main.cpp
    delete ui;
}

// ─────────────────────────────────────────────────────────────
//  Clock
// ─────────────────────────────────────────────────────────────
void PreferencesDialog::updateTime()
{
    ui->lbl_time->setText(QTime::currentTime().toString("hh:mm"));
}

// ─────────────────────────────────────────────────────────────
//  Sidebar Navigation
// ─────────────────────────────────────────────────────────────
void PreferencesDialog::on_btn_general_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    loadGeneralSettings();
}

void PreferencesDialog::on_btn_databases_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    loadDatabaseStats();
}

void PreferencesDialog::on_btn_printer_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void PreferencesDialog::on_btn_network_clicked()
{
    // page index — add more pages to UI as needed
    ui->stackedWidget->setCurrentIndex(3);
}

void PreferencesDialog::on_btn_date_time_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void PreferencesDialog::on_btn_statistics_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void PreferencesDialog::on_btn_measurement_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void PreferencesDialog::on_btn_backup_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

// ─────────────────────────────────────────────────────────────
//  General page — load/save settings
// ─────────────────────────────────────────────────────────────
void PreferencesDialog::loadGeneralSettings()
{
    if (!db.isOpen()) return;

    QSqlQuery q(db);
    // Assumes a settings table: CREATE TABLE settings(key TEXT PRIMARY KEY, value TEXT)
    auto getValue = [&](const QString &key) -> QString {
        q.prepare("SELECT value FROM settings WHERE key = :key");
        q.bindValue(":key", key);
        return (q.exec() && q.next()) ? q.value(0).toString() : "";
    };

    ui->lineEdit_hospitalName->setText(getValue("hospital_name"));
    ui->lineEdit_hospitalAddress->setText(getValue("hospital_address"));
    ui->lineEdit_currentDoctor->setText(getValue("current_doctor"));
    ui->lineEdit_serialNumber->setText(getValue("serial_number"));
    ui->lineEdit_softwareVersion->setText(getValue("software_version"));
}

void PreferencesDialog::saveGeneralSettings()
{
    if (!db.isOpen()) return;

    QSqlQuery q(db);
    auto setValue = [&](const QString &key, const QString &value) {
        q.prepare("INSERT OR REPLACE INTO settings(key, value) VALUES(:key, :value)");
        q.bindValue(":key",   key);
        q.bindValue(":value", value);
        q.exec();
    };

    setValue("hospital_name",    ui->lineEdit_hospitalName->text().trimmed());
    setValue("hospital_address", ui->lineEdit_hospitalAddress->text().trimmed());
    setValue("current_doctor",   ui->lineEdit_currentDoctor->text().trimmed());
    setValue("serial_number",    ui->lineEdit_serialNumber->text().trimmed());
    setValue("software_version", ui->lineEdit_softwareVersion->text().trimmed());
}

// ─────────────────────────────────────────────────────────────
//  Databases page — show row counts
// ─────────────────────────────────────────────────────────────
void PreferencesDialog::loadDatabaseStats()
{
    if (!db.isOpen()) return;

    QSqlQuery q(db);
    auto count = [&](const QString &table) -> int {
        q.exec("SELECT COUNT(*) FROM " + table);
        return (q.next()) ? q.value(0).toInt() : 0;
    };

    ui->lbl_patCount->setText("Patients: "  + QString::number(count("patient")));
    ui->lbl_doctorCount->setText("Doctors: " + QString::number(count("doctor")));
    ui->lbl_lensCount->setText("Lenses: "   + QString::number(count("lens")));
    ui->lbl_scansCount->setText("Scans: "   + QString::number(count("scans")));
}

// ─────────────────────────────────────────────────────────────
//  Buttons
// ─────────────────────────────────────────────────────────────
void PreferencesDialog::on_btn_save_clicked()
{
    saveGeneralSettings();

}

void PreferencesDialog::on_btn_back_clicked()
{
    reject();
}
