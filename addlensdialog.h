#ifndef ADDLENSDIALOG_H
#define ADDLENSDIALOG_H

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
class AddLensDialog;
}

class AddLensDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddLensDialog(QWidget *parent = nullptr);
    ~AddLensDialog();

private slots:
    void on_btn_save_clicked();
    void on_btn_cancel_clicked();

private:
    Ui::AddLensDialog *ui;
    QSqlDatabase db;

    bool openDatabase();
    bool saveLens();
    void clearFields();
    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // ADDLENSDIALOG_H
