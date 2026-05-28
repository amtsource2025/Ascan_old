#ifndef CALCULATORDIALOG_H
#define CALCULATORDIALOG_H

#include <QDialog>
#include <QTimer>
#include <QTime>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class CalculatorDialog;
}

class CalculatorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CalculatorDialog(QWidget *parent = nullptr);
    ~CalculatorDialog();

    void setPatientId(const QString &patientId);
    void setDoctorId(const QString &doctorId);

private slots:
    void updateTime();

    void on_btn_home_clicked();
    void on_btn_measure_clicked();
    void on_btn_newPatient_clicked();
    void on_btn_print_clicked();

    void on_btn_srkt_clicked();
    void on_btn_srkii_clicked();
    void on_btn_hofferq_clicked();
    void on_btn_holladay_clicked();
    void on_btn_haigis_clicked();

    void on_btn_warning1_clicked();
    void on_btn_warning2_clicked();
    void on_btn_warning3_clicked();

private:
    Ui::CalculatorDialog *ui;
    QTimer *clockTimer;
    QSqlDatabase db;

    QString m_patientId;
    QString m_doctorId;

    bool openDatabase();
    void calculate();
    void updateFormula(const QString &formula);
};

#endif // CALCULATORDIALOG_H
