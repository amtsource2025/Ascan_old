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

class welcomedialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit welcomedialog(QWidget *parent = nullptr);
    ~welcomedialog();

private slots:
    void onPatientSelectionChanged(int index);
    void on_btn_enter_clicked();
    void on_btn_surgeon_clicked();
    void on_btn_newDoctor_2_clicked();
    void on_btn_ascan_clicked();
    void updateTime();

private:
    Ui::WelcomeDialog *ui;
    QSqlDatabase       db;
    QTimer            *clockTimer;

    QString m_defaultDoctorId;

    bool    openDatabase();
    QString ensureDefaultDoctor();
    void    ensurePatientHasDoctor(const QString &patientId);
    QString resolveDoctor(const QString &patientId);
    void    loadPatients();
    void    selectPatientById(const QString &patientId);
};

#endif // WELCOMEDIALOG_H
