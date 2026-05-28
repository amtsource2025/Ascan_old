#ifndef HOMESCREENDIALOG_H
#define HOMESCREENDIALOG_H

#include <QDialog>
#include <QTimer>
#include <QTime>
#include <QMouseEvent>
#include <QGestureEvent>
#include <QSwipeGesture>
#include <QPropertyAnimation>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class HomeScreenDialog; }
QT_END_NAMESPACE

class HomeScreenDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HomeScreenDialog(QWidget *parent = nullptr);

    // ── NEW: open with a pre-selected patient & doctor ────────
    explicit HomeScreenDialog(const QString &patientId,
                              const QString &doctorId,
                              QWidget *parent = nullptr);

    ~HomeScreenDialog();

    // ── Setters (called externally to pre-load info) ──────────
    void setDoctorName(const QString &name);
    void setDoctorFormula(const QString &formula);
    void setPatientName(const QString &name);

private slots:
    void on_btn_doctors_clicked();
    void on_btn_patients_clicked();
    void on_btn_calculator_clicked();
    void on_btn_lenses_clicked();
    void on_btn_print_clicked();
    void on_btn_settings_clicked();
    void on_btn_measure_clicked();

    void on_btn_calibrate_clicked();
    void on_btn_back_clicked();

    void on_btn_currentDoctorChooser_clicked();
    void on_btn_currentDoctorLogo_clicked();
    void on_btn_currentDocAdd_clicked();
    void on_btn_currentDocEdit_clicked();
    void on_btn_currentDocView_clicked();
    void on_btn_currentDoctorLoad_clicked();
    void on_btn_currentDoctorChooserExit_clicked();

    void on_btn_currentPatientChooser_clicked();
    void on_btn_currentPatientLogo_clicked();
    void on_btn_currentPatientAdd_clicked();
    void on_btn_currentPatientEdit_clicked();
    void on_btn_currentPatientView_clicked();
    void on_btn_currentPatientLoad_clicked();
    void on_btn_currentPatientChooserExit_clicked();

    void updateClock();

private:
    Ui::HomeScreenDialog *ui;
    QTimer               *clockTimer;
    QTimer               *snackbarTimer;
    QPropertyAnimation   *m_sidebarAnimation;

    QPoint m_swipeStart;
    bool   m_tracking;

    QString m_currentPatientId;
    QString m_currentDoctorId;

    static constexpr int PAGE_MAIN     = 0;
    static constexpr int PAGE_PATIENTS = 1;
    static constexpr int PAGE_DOCTORS  = 2;
    static constexpr int PAGE_SETTINGS = 3;

    static constexpr int SIDEBAR_WIDTH   = 300;
    static constexpr int ANIM_DURATION   = 250;
    static constexpr int SWIPE_THRESHOLD = 60;

    void setupSidebar();
    void setupSidebarAnimation();
    bool isSidebarVisible() const;
    void showSidebar();
    void hideSidebar();
    void showPage(int index);
    void refreshPatientTable();

    bool event(QEvent *event) override;
    bool gestureEvent(QGestureEvent *event);
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    // ── Add these two members ─────────────────────────────────────
    QPropertyAnimation *m_contentAnimation;   // animates stackedWidget geometry
    QRect               m_contentFullRect;    // stackedWidget rect when sidebar hidden
    QRect               m_contentSidebarRect; // stackedWidget rect when sidebar shown|

    void centerMainButtons(int contentX, int contentWidth);
};

#endif // HOMESCREENDIALOG_H
