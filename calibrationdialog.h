#ifndef CALIBRATIONDIALOG_H
#define CALIBRATIONDIALOG_H

#include <QDialog>
#include <QTimer>
#include <QTime>
#include <QDebug>

namespace Ui {
class CalibrationDialog;
}

class CalibrationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CalibrationDialog(QWidget *parent = nullptr);
    ~CalibrationDialog();

private slots:
    void updateTime();
    void on_btn_start_clicked();
    void on_btn_back_clicked();

private:
    Ui::CalibrationDialog *ui;
    QTimer *clockTimer;
};

#endif // CALIBRATIONDIALOG_H
