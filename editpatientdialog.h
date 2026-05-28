#ifndef EDITPATIENTDIALOG_H
#define EDITPATIENTDIALOG_H

#include <QDialog>
#include <QTimer>
#include <QSqlDatabase>

namespace Ui {
class EditPatientDialog;
}

class EditPatientDialog : public QDialog
{
    Q_OBJECT

public:
    // Pass the internal DB id (integer primary key)
    explicit EditPatientDialog(int patientDbId, QWidget *parent = nullptr);
    ~EditPatientDialog();


private slots:
    void on_btn_save_clicked();
    void on_btn_cancel_clicked();
    void updateTime();

private:
    Ui::EditPatientDialog *ui;
    QTimer                *clockTimer;
    QSqlDatabase           db;
    int                    m_dbId;   // internal integer id

    bool openDatabase();
    void loadPatient();
};

#endif // EDITPATIENTDIALOG_H
