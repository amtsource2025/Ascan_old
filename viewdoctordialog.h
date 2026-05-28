#ifndef VIEWDOCTORDIALOG_H
#define VIEWDOCTORDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTimer>

namespace Ui { class ViewDoctorDialog; }

class ViewDoctorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewDoctorDialog(QWidget *parent = nullptr);
    explicit ViewDoctorDialog(QWidget *parent, const QString &patientId);
    ~ViewDoctorDialog();

    QString selectedDoctorId() const { return m_selectedDoctorId; }



private slots:
    void on_btn_add_clicked();
    void on_btn_edit_clicked();
    void on_btn_delete_clicked();
    void on_btn_view_clicked();
    void on_btn_close_clicked();
    void onDoctorRowClicked(int row, int column);
    void updateTime();

private:
    Ui::ViewDoctorDialog *ui;
    QSqlDatabase db;
    QTimer *clockTimer;

    bool    m_selectionMode = false;
    QString m_patientId;
    QString m_selectedDoctorId;

    bool openDatabase();
    void loadDoctors();
    void init();
};

#endif
