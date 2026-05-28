#pragma once
#include <QDialog>
#include <QSqlDatabase>
#include <QTimer>

namespace Ui { class PatientDetailDialog; }

class PatientDetailDialog : public QDialog
{
    Q_OBJECT
public:
    explicit PatientDetailDialog(int patientDbId, QWidget *parent = nullptr);
    ~PatientDetailDialog();

private slots:
    void updateTime();
    void on_btn_close_clicked();

private:
    void loadPatient();

    Ui::PatientDetailDialog *ui;
    QSqlDatabase             db;
    QTimer                  *clockTimer;
    int                      m_patientDbId;
};
