#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QDialog>
#include <QTimer>
#include <QSqlDatabase>

namespace Ui {
class PreferencesDialog;
}

class PreferencesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PreferencesDialog(QWidget *parent = nullptr);
    ~PreferencesDialog();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    // ── Clock ──────────────────────────────────────────────────
    void updateTime();

    // ── Sidebar navigation ─────────────────────────────────────
    void on_btn_general_clicked();
    void on_btn_databases_clicked();
    void on_btn_printer_clicked();
    void on_btn_network_clicked();
    void on_btn_date_time_clicked();
    void on_btn_statistics_clicked();
    void on_btn_measurement_clicked();
    void on_btn_backup_clicked();

    // ── Buttons ────────────────────────────────────────────────
    void on_btn_save_clicked();
    void on_btn_back_clicked();

    // ── Databases page ─────────────────────────────────────────
    void on_btn_clearScans_clicked();

    // ── Printer page ───────────────────────────────────────────
    void on_btn_testPrint_clicked();
    void on_but_save_printer_clicked();

    // ── Network page ───────────────────────────────────────────
    void on_checkBox_pwdMask_toggled(bool checked);

    // ── Date & Time page ───────────────────────────────────────
    void on_but_save_date_clicked();

    // ── Backup & Restore page ──────────────────────────────────
    void on_btn_restoreAll_clicked();
    void on_btn_restoreSettings_clicked();

private:
    Ui::PreferencesDialog *ui;
    QTimer      *clockTimer;
    QSqlDatabase db;

    // ── Helpers ────────────────────────────────────────────────
    void showSnackbar(const QString &msg);

    // ── General ────────────────────────────────────────────────
    void loadGeneralSettings();
    void saveGeneralSettings();

    // ── Databases ──────────────────────────────────────────────
    void loadDatabaseStats();
    void loadDiskUsage();

    // ── Printer ────────────────────────────────────────────────
    void loadPrinterPorts();
    void savePrinterSettings();

    // ── Network ────────────────────────────────────────────────
    void loadNetworkSettings();
    void saveNetworkSettings();

    // ── Date & Time ────────────────────────────────────────────
    void loadCurrentDateTime();
    void saveDateTimeSettings();

    // ── Statistics ─────────────────────────────────────────────
    void loadStatistics();

    // ── Measurement ────────────────────────────────────────────
    void loadMeasurementSettings();
    void saveMeasurementSettings();
};

#endif // PREFERENCESDIALOG_H
