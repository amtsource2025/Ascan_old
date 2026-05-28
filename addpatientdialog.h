#ifndef ADDPATIENTDIALOG_H
#define ADDPATIENTDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QEvent>
#include <QLineEdit>
#include "keypad.h"
#include "numericpad.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AddPatientDialog; }
QT_END_NAMESPACE

class AddPatientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddPatientDialog(QWidget *parent = nullptr);
    ~AddPatientDialog();


    QString getNewPatientId() const { return m_newPatientId; }

private slots:
    void on_btn_save_clicked();
    void on_btn_cancel_clicked();

private:
    Ui::AddPatientDialog *ui;
    QSqlDatabase          db;

    QString m_newPatientId;

    bool    openDatabase();
    QString generatePatientID();
    bool    savePatient();
    void    clearFields();

    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // ADDPATIENTDIALOG_H
