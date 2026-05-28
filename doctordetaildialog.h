#pragma once
#include <QDialog>
#include <QSqlDatabase>
#include <QTimer>

namespace Ui { class DoctorDetailDialog; }

class DoctorDetailDialog : public QDialog
{
    Q_OBJECT
public:
    explicit DoctorDetailDialog(const QString &doctorId, QWidget *parent = nullptr);
    ~DoctorDetailDialog();

private slots:
    void updateTime();
    void onPatientSelected(int index);
    void on_btn_close_clicked();

private:
    void loadDoctor();
    void loadLensPreset(const QString &presetJson, int tabIndex);
    void loadPatientCombo();
    void loadPatientDetails(int patientDbId);
    void populateLensTab(int tab,
                         const QString &iol,
                         const QString &asrkt, const QString &asrkii,
                         const QString &acd,  const QString &sf,
                         const QString &a0,   const QString &a1, const QString &a2);

    Ui::DoctorDetailDialog *ui;
    QSqlDatabase            db;
    QTimer                 *clockTimer;
    QString                 m_doctorId;
};
