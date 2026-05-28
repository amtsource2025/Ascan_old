#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QDialog>
#include <QTimer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

namespace Ui { class PreferencesDialog; }

class PreferencesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PreferencesDialog(QWidget *parent = nullptr);
    ~PreferencesDialog();

private slots:
    void updateTime();

    // Sidebar navigation
    void on_btn_general_clicked();
    void on_btn_databases_clicked();
    void on_btn_printer_clicked();
    void on_btn_network_clicked();
    void on_btn_backup_clicked();
    void on_btn_date_time_clicked();
    void on_btn_statistics_clicked();
    void on_btn_measurement_clicked();

    // Actions
    void on_btn_save_clicked();
    void on_btn_back_clicked();

private:
    Ui::PreferencesDialog *ui;
    QTimer      *clockTimer;
    QSqlDatabase db;

    void loadGeneralSettings();
    void saveGeneralSettings();
    void loadDatabaseStats();
};

#endif // PREFERENCESDIALOG_H
