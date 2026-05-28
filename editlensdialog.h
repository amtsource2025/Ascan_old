#ifndef EDITLENSDIALOG_H
#define EDITLENSDIALOG_H

#include <QDialog>
#include <QTimer>
#include <QSqlDatabase>

namespace Ui {
class EditLensDialog;
}

class EditLensDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditLensDialog(const QString &iol, QWidget *parent = nullptr);
    ~EditLensDialog();

private slots:
    void on_btn_save_clicked();
    void on_btn_cancel_clicked();
    void updateTime();

private:
    Ui::EditLensDialog *ui;
    QTimer             *clockTimer;
    QSqlDatabase        db;
    QString             m_iol;      // original IOL key (read-only)

    bool openDatabase();
    void loadLens();
};

#endif // EDITLENSDIALOG_H
