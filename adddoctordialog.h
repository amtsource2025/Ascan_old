#ifndef ADDDOCTORDIALOG_H
#define ADDDOCTORDIALOG_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <QDebug>
#include "keypad.h"
#include "numericpad.h"
#include <QEvent>

namespace Ui {
class AddDoctorDialog;
}

class AddDoctorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDoctorDialog(QWidget *parent = nullptr);
    ~AddDoctorDialog();



private slots:
    void on_btn_save_clicked();
    void on_btn_cancel_clicked();

private:
    Ui::AddDoctorDialog *ui;
    QSqlDatabase db;

    bool openDatabase();
    bool saveDoctor();
    void clearFields();
    void loadLensPresets();
    QString generateDoctorID();
    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // ADDDOCTORDIALOG_H
