#ifndef EDITDOCTORDIALOG_H
#define EDITDOCTORDIALOG_H

#include <QDialog>
#include <QTimer>
#include <QSqlDatabase>

namespace Ui {
class EditDoctorDialog;
}

class EditDoctorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDoctorDialog(const QString &doctorId, QWidget *parent = nullptr);
    ~EditDoctorDialog();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;


private slots:
    void on_btn_save_clicked();
    void on_btn_cancel_clicked();
    void updateTime();

private:
    Ui::EditDoctorDialog *ui;
    QTimer               *clockTimer;
    QSqlDatabase          db;
    QString               m_doctorId;

    bool openDatabase();
    void loadDoctor();
    void loadLensOptions();
};

#endif // EDITDOCTORDIALOG_H
