#ifndef VIEWPATIENTDIALOG_H
#define VIEWPATIENTDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTimer>
#include <QDebug>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QAbstractItemView>
#include <QTime>

namespace Ui {
class ViewPatientDialog;
}

class ViewPatientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewPatientDialog(QWidget *parent = nullptr);
    ~ViewPatientDialog();



private slots:
    void updateTime();
    void on_btn_add_clicked();
    void on_btn_edit_clicked();
    void on_btn_delete_clicked();
    void on_btn_view_clicked();
    void on_btn_close_clicked();

private:
    Ui::ViewPatientDialog *ui;
    QSqlDatabase db;
    QTimer *clockTimer;

    bool openDatabase();
    void loadPatients();
};

#endif // VIEWPATIENTDIALOG_H
