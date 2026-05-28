#ifndef VIEWLENSDIALOG_H
#define VIEWLENSDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTimer>
#include <QTime>
#include <QDebug>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QAbstractItemView>

namespace Ui {
class ViewLensDialog;
}

class ViewLensDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewLensDialog(QWidget *parent = nullptr);
    ~ViewLensDialog();

private slots:
    void updateTime();
    void on_btn_add_clicked();
    void on_btn_edit_clicked();
    void on_btn_delete_clicked();
    void on_btn_close_clicked();

private:
    Ui::ViewLensDialog *ui;
    QSqlDatabase db;
    QTimer *clockTimer;

    bool openDatabase();
    void loadLenses();
};

#endif // VIEWLENSDIALOG_H
