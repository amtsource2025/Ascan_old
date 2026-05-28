#ifndef PRINTDIALOG_H
#define PRINTDIALOG_H

#include <QDialog>
#include <QTimer>
#include <QTime>
#include <QDebug>

namespace Ui {
class PrintDialog;
}

class PrintDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PrintDialog(QWidget *parent = nullptr);
    ~PrintDialog();

    // Optional: pre-fill patient/scan context before opening
    void setPatientId(const QString &patientId);
    void setDoctorId(const QString &doctorId);

private slots:
    void updateTime();

    // Main menu buttons
    void on_btn_back_clicked();
    void on_btn_scan_clicked();
    void on_btn_calculations_clicked();
    void on_btn_both_clicked();
    void on_btn_newPatient_clicked();

    // Page-level print triggers
    void on_btn_both2_clicked();
    void on_btn_both3_clicked();
    void on_btn_calculations2_clicked();
    void on_btn_scan2_clicked();
    void on_btn_newPatient2_clicked();

private:
    Ui::PrintDialog *ui;
    QTimer *clockTimer;

    QString m_patientId;
    QString m_doctorId;

    // Page index constants (mirror the stackedWidget in the UI)
    static constexpr int PAGE_MENU  = 0;
    static constexpr int PAGE_SCAN  = 1;
    static constexpr int PAGE_CALC  = 2;
    static constexpr int PAGE_BOTH  = 3;

    void showPage(int index);
    void doPrint(const QString &content);
};

#endif // PRINTDIALOG_H
