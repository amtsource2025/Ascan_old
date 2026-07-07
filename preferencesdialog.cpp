#include "preferencesdialog.h"
#include "ui_preferencesdialog.h"
#include "keypad.h"
#include "numericpad.h"

#include <QDialog>
#include <QEvent>
#include <QMouseEvent>
#include <QTimer>
#include <QTime>
#include <QDate>
#include <QDateTime>
#include <QProcess>
#include <QStorageInfo>
#include <QFile>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

// ─────────────────────────────────────────────────────────────
//  Constructor / Destructor
// ─────────────────────────────────────────────────────────────
PreferencesDialog::PreferencesDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PreferencesDialog)
    , clockTimer(new QTimer(this))
    , db(QSqlDatabase::database())       // reuse main.cpp's connection
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    // ── Clock ─────────────────────────────────────────────────
    connect(clockTimer, &QTimer::timeout, this, &PreferencesDialog::updateTime);
    clockTimer->start(1000);
    updateTime();

    // ── Snackbar: hide at startup ──────────────────────────────
    ui->snackbar->hide();

    // ── Serial Number and Software Version are read-only ───────
    ui->lineEdit_serialNumber->setReadOnly(true);
    ui->lineEdit_softwareVersion->setReadOnly(true);

    // ── PSK masked by default ──────────────────────────────────
    ui->lineEdit_psk->setEchoMode(QLineEdit::Password);

    // ── Install event filters for touch keypad ─────────────────
    // General page — text fields
    ui->lineEdit_hospitalName->installEventFilter(this);
    ui->lineEdit_hospitalAddress->installEventFilter(this);
    ui->lineEdit_currentDoctor->installEventFilter(this);

    // Network page — text fields
    ui->lineEdit_ssid->installEventFilter(this);
    ui->lineEdit_psk->installEventFilter(this);

    // Date & Time page — numeric fields
    ui->lineEdit_day->installEventFilter(this);
    ui->lineEdit_year->installEventFilter(this);
    ui->lineEdit_hour->installEventFilter(this);
    ui->lineEdit_minute->installEventFilter(this);

    // Measurement page — numeric fields
    ui->lineEdit_acVelocity->installEventFilter(this);
    ui->lineEdit_lVelocity->installEventFilter(this);
    ui->lineEdit_vitVelocity->installEventFilter(this);
    ui->lineEdit_avVelocity->installEventFilter(this);

    // ── Start on General page ─────────────────────────────────
    ui->stackedWidget->setCurrentIndex(0);
    loadGeneralSettings();
}

PreferencesDialog::~PreferencesDialog()
{
    // Do NOT close db — owned by main.cpp
    delete ui;
}

// ─────────────────────────────────────────────────────────────
//  Event filter — opens touch keypad on field tap
// ─────────────────────────────────────────────────────────────
bool PreferencesDialog::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {

        // ── Text fields → Keypad ──────────────────────────────
        if (obj == ui->lineEdit_hospitalName    ||
            obj == ui->lineEdit_hospitalAddress ||
            obj == ui->lineEdit_currentDoctor   ||
            obj == ui->lineEdit_ssid            ||
            obj == ui->lineEdit_psk)
        {
            QLineEdit *le = qobject_cast<QLineEdit*>(obj);
            Keypad *kp = new Keypad(le, this);
            kp->exec();
            delete kp;
            return true;
        }

        // ── Numeric fields → Numericpad ───────────────────────
        if (obj == ui->lineEdit_day         ||
            obj == ui->lineEdit_year        ||
            obj == ui->lineEdit_hour        ||
            obj == ui->lineEdit_minute      ||
            obj == ui->lineEdit_acVelocity  ||
            obj == ui->lineEdit_lVelocity   ||
            obj == ui->lineEdit_vitVelocity ||
            obj == ui->lineEdit_avVelocity)
        {
            QLineEdit *le = qobject_cast<QLineEdit*>(obj);
            Numericpad *np = new Numericpad(le, this);
            np->exec();
            delete np;
            return true;
        }
    }
    return QDialog::eventFilter(obj, event);
}

// ─────────────────────────────────────────────────────────────
//  Snackbar helper
// ─────────────────────────────────────────────────────────────
void PreferencesDialog::showSnackbar(const QString &msg)
{
    ui->snackbar->setText(msg);
    ui->snackbar->show();
    QTimer::singleShot(2500, this, [this]{ ui->snackbar->hide(); });
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
    loadDiskUsage();
}

void PreferencesDialog::on_btn_printer_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    loadPrinterPorts();
}

void PreferencesDialog::on_btn_network_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    loadNetworkSettings();
}

void PreferencesDialog::on_btn_backup_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void PreferencesDialog::on_btn_date_time_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    loadCurrentDateTime();
}

void PreferencesDialog::on_btn_statistics_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    loadStatistics();
}

void PreferencesDialog::on_btn_measurement_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    loadMeasurementSettings();
}

// ─────────────────────────────────────────────────────────────
//  Save button — routes to the active page's save function
// ─────────────────────────────────────────────────────────────
void PreferencesDialog::on_btn_save_clicked()
{
    switch (ui->stackedWidget->currentIndex()) {
    case 0: saveGeneralSettings();     break;
    case 7: saveMeasurementSettings(); break;
    default: break;   // other pages have their own save buttons
    }
}

void PreferencesDialog::on_btn_back_clicked()
{
    reject();
}

// ─────────────────────────────────────────────────────────────
//  PAGE 0 — General
// ─────────────────────────────────────────────────────────────
void PreferencesDialog::loadGeneralSettings()
{
    if (!db.isOpen()) return;

    QSqlQuery q(db);
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
        if (!q.exec())
            qWarning() << "saveGeneralSettings:" << q.lastError().text();
    };

    setValue("hospital_name",    ui->lineEdit_hospitalName->text().trimmed());
    setValue("hospital_address", ui->lineEdit_hospitalAddress->text().trimmed());
    setValue("current_doctor",   ui->lineEdit_currentDoctor->text().trimmed());
    // serial_number and software_version are read-only — not saved here

    showSnackbar("General settings saved.");
}

// ─────────────────────────────────────────────────────────────
//  PAGE 1 — Databases
// ─────────────────────────────────────────────────────────────
void PreferencesDialog::loadDatabaseStats()
{
    if (!db.isOpen()) return;

    QSqlQuery q(db);
    auto count = [&](const QString &table) -> int {
        q.exec("SELECT COUNT(*) FROM " + table);
        return q.next() ? q.value(0).toInt() : 0;
    };

    ui->lbl_patCount->setText("Patients: "  + QString::number(count("patient")));
    ui->lbl_doctorCount->setText("Doctors: " + QString::number(count("doctor")));
    ui->lbl_lensCount->setText("Lenses: "   + QString::number(count("lens")));
    ui->lbl_scansCount->setText("Scans: "   + QString::number(count("scans")));
}

void PreferencesDialog::loadDiskUsage()
{
    QStorageInfo storage = QStorageInfo::root();
    qint64 total     = storage.bytesTotal()     / (1024 * 1024);
    qint64 available = storage.bytesAvailable() / (1024 * 1024);
    qint64 used      = total - available;

    ui->lbl_totDiskSpace->setText(
        QString("Total Disk Space: %1 MB").arg(total));
    ui->lbl_availDiskSpace->setText(
        QString("Available: %1 MB").arg(available));

    int pct = (total > 0) ? static_cast<int>((used * 100) / total) : 0;
    ui->progressBar_diskSpace->setValue(pct);
    ui->progressBar_diskSpace->setFormat(QString("%1% used").arg(pct));
}

void PreferencesDialog::on_btn_clearScans_clicked()
{
    if (!db.isOpen()) return;

    QMessageBox::StandardButton reply = QMessageBox::question(
        this,
        "Clear Scans",
        "Delete all scan records? This cannot be undone.",
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {
        QSqlQuery q(db);
        if (q.exec("DELETE FROM scans")) {
            showSnackbar("All scans cleared.");
            loadDatabaseStats();
        } else {
            showSnackbar("Error: " + q.lastError().text());
        }
    }
}

// ─────────────────────────────────────────────────────────────
//  PAGE 2 — Printer
//
//  Scans /dev for ttyUL*, ttyUSB*, ttyS* — covers both the
//  Zynq board (ttyUL1) and a development PC (ttyUSB0 / ttyS0).
//  Previously saved port is restored from the settings table.
// ─────────────────────────────────────────────────────────────
void PreferencesDialog::loadPrinterPorts()
{
    QComboBox *cb = ui->comboBox_printer;
    cb->blockSignals(true);
    cb->clear();

    // Hardcoded ports present on SOM144ASC-DEV board
    const QStringList ports = {
        "/dev/ttyUL1",
    };

    for (const QString &p : ports)
        cb->addItem(p);

    qDebug() << "loadPrinterPorts: comboBox has" << cb->count() << "items";
    for (int i = 0; i < cb->count(); ++i)
        qDebug() << "  " << i << ":" << cb->itemText(i);

    // Restore previously saved port from settings table
    if (db.isOpen()) {
        QSqlQuery q(db);
        q.prepare("SELECT value FROM settings WHERE key = 'printer_port'");
        if (q.exec() && q.next()) {
            const QString saved = q.value(0).toString().trimmed();
            qDebug() << "loadPrinterPorts: saved port =" << saved;
            int idx = cb->findText(saved);
            if (idx >= 0)
                cb->setCurrentIndex(idx);
        }
    }

    cb->blockSignals(false);
}

void PreferencesDialog::savePrinterSettings()
{
    if (!db.isOpen()) return;

    const QString port = ui->comboBox_printer->currentText().trimmed();

    QSqlQuery q(db);
    q.prepare("INSERT OR REPLACE INTO settings(key, value) "
              "VALUES('printer_port', :val)");
    q.bindValue(":val", port);
    q.exec();
    showSnackbar("Printer port saved: " + port);
}

void PreferencesDialog::on_btn_testPrint_clicked()
{
    const QString port = ui->comboBox_printer->currentText().trimmed();

    if (port.isEmpty()) {
        showSnackbar("No printer port selected.");
        return;
    }

    QFile f(port);
    if (!f.open(QIODevice::WriteOnly | QIODevice::Unbuffered)) {
        showSnackbar("Cannot open " + port + ".");
        return;
    }

    QByteArray data("*** ACUAXIS TEST PRINT ***\r\n\r\n\r\n\f");
    qint64 written = f.write(data);
    f.flush();
    f.close();

    if (written == data.size())
        showSnackbar("Test sent to " + port + ".");
    else
        showSnackbar("Partial write — check printer cable.");
}


// void PrintDialog::resetContext()
// {
//     m_hasScanCtx   = false;
//     m_hasCalcCtx   = false;
//     m_autoPageDone = false;   // ← this is the key one
//     m_scanContent.clear();
//     m_calcContent.clear();
// }

void PreferencesDialog::on_but_save_printer_clicked()
{
    savePrinterSettings();
}

// ─────────────────────────────────────────────────────────────
//  PAGE 3 — Network
// ─────────────────────────────────────────────────────────────
void PreferencesDialog::loadNetworkSettings()
{
    if (!db.isOpen()) return;

    QSqlQuery q(db);
    auto getValue = [&](const QString &key) -> QString {
        q.prepare("SELECT value FROM settings WHERE key = :key");
        q.bindValue(":key", key);
        return (q.exec() && q.next()) ? q.value(0).toString() : "";
    };

    ui->lineEdit_ssid->setText(getValue("wifi_ssid"));
    ui->lineEdit_psk->setText(getValue("wifi_psk"));
}

void PreferencesDialog::saveNetworkSettings()
{
    if (!db.isOpen()) return;

    QSqlQuery q(db);
    auto setValue = [&](const QString &key, const QString &value) {
        q.prepare("INSERT OR REPLACE INTO settings(key, value) VALUES(:key, :value)");
        q.bindValue(":key",   key);
        q.bindValue(":value", value);
        q.exec();
    };

    setValue("wifi_ssid", ui->lineEdit_ssid->text().trimmed());
    setValue("wifi_psk",  ui->lineEdit_psk->text());

    QString ssid = ui->lineEdit_ssid->text().trimmed();
    QString psk  = ui->lineEdit_psk->text();
    bool clearExisting = ui->checkBox_clearSSID->isChecked();

    QString confContent;
    if (clearExisting) {
        confContent = "ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev\n"
                      "update_config=1\n\n";
    } else {
        QFile f("/etc/wpa_supplicant/wpa_supplicant.conf");
        if (f.open(QIODevice::ReadOnly | QIODevice::Text)) {
            confContent = f.readAll();
            f.close();
        }
    }

    if (!ssid.isEmpty()) {
        confContent += QString(
                           "network={\n"
                           "    ssid=\"%1\"\n"
                           "    psk=\"%2\"\n"
                           "}\n"
                           ).arg(ssid, psk);
    }

    QFile confFile("/etc/wpa_supplicant/wpa_supplicant.conf");
    if (confFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&confFile);
        out << confContent;
        confFile.close();
        QProcess::startDetached("wpa_cli", QStringList() << "reconfigure");
        showSnackbar("Network settings saved. Reconnecting...");
    } else {
        showSnackbar("Error: Cannot write network config.");
    }
}

void PreferencesDialog::on_checkBox_pwdMask_toggled(bool checked)
{
    ui->lineEdit_psk->setEchoMode(
        checked ? QLineEdit::Normal : QLineEdit::Password
        );
}

// ─────────────────────────────────────────────────────────────
//  PAGE 4 — Backup & Restore
// ─────────────────────────────────────────────────────────────
void PreferencesDialog::on_btn_restoreAll_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(
        this,
        "Restore All",
        "This will erase ALL data including scans and reset to factory defaults.\n"
        "This cannot be undone. Are you sure?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {
        if (!db.isOpen()) return;
        QSqlQuery q(db);
        q.exec("DELETE FROM scans");
        q.exec("DELETE FROM patient");
        q.exec("DELETE FROM doctor");
        q.exec("DELETE FROM lens");
        q.exec("DELETE FROM settings");
        showSnackbar("Factory restore complete. All data cleared.");
    }
}

void PreferencesDialog::on_btn_restoreSettings_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(
        this,
        "Restore Preferences",
        "This will reset all preferences to factory defaults.\n"
        "Scan records will NOT be affected. Continue?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {
        if (!db.isOpen()) return;
        QSqlQuery q(db);
        q.exec("DELETE FROM settings");
        showSnackbar("Preferences restored to defaults.");
        loadGeneralSettings();
    }
}

// ─────────────────────────────────────────────────────────────
//  PAGE 5 — Date & Time
// ─────────────────────────────────────────────────────────────
void PreferencesDialog::loadCurrentDateTime()
{
    QDateTime now = QDateTime::currentDateTime();
    QDate d = now.date();
    QTime t = now.time();

    ui->lineEdit_day->setText(QString::number(d.day()));
    ui->comboBox_month->setCurrentIndex(d.month() - 1);   // 0-indexed
    ui->lineEdit_year->setText(QString::number(d.year()));
    ui->lineEdit_hour->setText(QString("%1").arg(t.hour(),   2, 10, QChar('0')));
    ui->lineEdit_minute->setText(QString("%1").arg(t.minute(), 2, 10, QChar('0')));
}

void PreferencesDialog::saveDateTimeSettings()
{
    int day    = ui->lineEdit_day->text().toInt();
    int month  = ui->comboBox_month->currentIndex() + 1;
    int year   = ui->lineEdit_year->text().toInt();
    int hour   = ui->lineEdit_hour->text().toInt();
    int minute = ui->lineEdit_minute->text().toInt();

    QDate newDate(year, month, day);
    QTime newTime(hour, minute, 0);

    if (!newDate.isValid() || !newTime.isValid()) {
        showSnackbar("Invalid date or time entered.");
        return;
    }

    QString dtStr = QString("%1-%2-%3 %4:%5:00")
                        .arg(year)
                        .arg(month,  2, 10, QChar('0'))
                        .arg(day,    2, 10, QChar('0'))
                        .arg(hour,   2, 10, QChar('0'))
                        .arg(minute, 2, 10, QChar('0'));

    QProcess proc;
    proc.start("date", QStringList() << "-s" << dtStr);
    proc.waitForFinished(3000);

    if (proc.exitCode() == 0) {
        QProcess::startDetached("hwclock", QStringList() << "--systohc");
        showSnackbar("Date & time updated.");
    } else {
        showSnackbar("Error setting date/time (need root).");
    }
}

void PreferencesDialog::on_but_save_date_clicked()
{
    saveDateTimeSettings();
}

// ─────────────────────────────────────────────────────────────
//  PAGE 6 — Statistics
// ─────────────────────────────────────────────────────────────
void PreferencesDialog::loadStatistics()
{
    if (!db.isOpen()) return;

    QSqlQuery q(db);
    auto countQuery = [&](const QString &sql) -> int {
        q.exec(sql);
        return q.next() ? q.value(0).toInt() : 0;
    };

    int total = countQuery("SELECT COUNT(*) FROM scans");
    int week  = countQuery(
        "SELECT COUNT(*) FROM scans "
        "WHERE date >= date('now', '-7 days')"
        );
    int month = countQuery(
        "SELECT COUNT(*) FROM scans "
        "WHERE date >= date('now', '-30 days')"
        );
    int today = countQuery(
        "SELECT COUNT(*) FROM scans "
        "WHERE date = date('now')"
        );

    ui->lbl_totalScans->setText(QString::number(total));
    ui->lbl_totalScans->setReadOnly(true);

    ui->lbl_scansPastWeek->setText(QString::number(week));
    ui->lbl_scansPastWeek->setReadOnly(true);

    ui->lbl_scansPastMonth->setText(QString::number(month));
    ui->lbl_scansPastMonth->setReadOnly(true);

    ui->lbl_scansToday->setText(QString::number(today));
    ui->lbl_scansToday->setReadOnly(true);
}

// ─────────────────────────────────────────────────────────────
//  PAGE 7 — Measurement (velocity settings)
// ─────────────────────────────────────────────────────────────
void PreferencesDialog::loadMeasurementSettings()
{
    if (!db.isOpen()) return;

    QSqlQuery q(db);
    auto getValue = [&](const QString &key, const QString &defaultVal) -> QString {
        q.prepare("SELECT value FROM settings WHERE key = :key");
        q.bindValue(":key", key);
        return (q.exec() && q.next()) ? q.value(0).toString() : defaultVal;
    };

    ui->lineEdit_acVelocity->setText(getValue("vel_anterior_chamber", "1532"));
    ui->lineEdit_lVelocity->setText(getValue("vel_lens",              "1641"));
    ui->lineEdit_vitVelocity->setText(getValue("vel_vitreous",        "1532"));
    ui->lineEdit_avVelocity->setText(getValue("vel_average",          "1550"));
}

void PreferencesDialog::saveMeasurementSettings()
{
    if (!db.isOpen()) return;

    QSqlQuery q(db);
    auto setValue = [&](const QString &key, const QString &value) {
        q.prepare("INSERT OR REPLACE INTO settings(key, value) VALUES(:key, :value)");
        q.bindValue(":key",   key);
        q.bindValue(":value", value);
        if (!q.exec())
            qWarning() << "saveMeasurementSettings:" << q.lastError().text();
    };

    setValue("vel_anterior_chamber", ui->lineEdit_acVelocity->text().trimmed());
    setValue("vel_lens",             ui->lineEdit_lVelocity->text().trimmed());
    setValue("vel_vitreous",         ui->lineEdit_vitVelocity->text().trimmed());
    setValue("vel_average",          ui->lineEdit_avVelocity->text().trimmed());

    showSnackbar("Measurement settings saved.");
}
