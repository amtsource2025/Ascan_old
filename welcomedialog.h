#ifndef WELCOMEDIALOG_H
#define WELCOMEDIALOG_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "keypad.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WelcomeDialog; }
QT_END_NAMESPACE

class welcomeDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit welcomeDialog(QWidget *parent = nullptr);
    ~welcomeDialog();

    void    loadPatients();
    void    selectPatientById(const QString &patientId);
    QString getLastPatientId();
protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void onPatientSelectionChanged(int index);
    void on_btn_enter_clicked();
    void on_btn_surgeon_clicked();
    void on_btn_newDoctor_2_clicked();
    void on_btn_ascan_clicked();
    void updateTime();

    void on_btn_calculator_clicked();

    void on_btn_calibrate_clicked();

    void on_btn_doctors_clicked();

    void on_btn_patients_clicked();

    void on_btn_lenses_clicked();

    void on_btn_settings_clicked();

    void on_btn_print_clicked();

private:
    Ui::WelcomeDialog *ui;
    QSqlDatabase       db;
    QTimer            *clockTimer;

    QString m_defaultDoctorId;

    QString m_lastPatientId;

    bool    openDatabase();
    QString ensureDefaultDoctor();
    void    ensurePatientHasDoctor(const QString &patientId);
    QString resolveDoctor(const QString &patientId);

    QString m_currentPatientId;
    QString m_currentDoctorId;

};

#endif // WELCOMEDIALOG_H
