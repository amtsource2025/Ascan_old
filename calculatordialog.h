#ifndef CALCULATORDIALOG_H
#define CALCULATORDIALOG_H

#include <QDialog>
#include <QTimer>
#include <QTime>
#include <QDebug>
#include <QEvent>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <cmath>

#include "keypad.h"
#include "numericpad.h"
#include "IOLCalculator.h"    // ← your lib header (capital IOL, matches filename)

namespace Ui { class CalculatorDialog; }

// ─── IOL Formula selection ────────────────────────────────────
enum class IolFormula { SRKII, SRKT, HofferQ, Holladay, Haigis };

// ─── Per-lens constants ───────────────────────────────────────
struct LensConstants {
    double aConst = 118.0;  // SRK II / SRK-T
    double sf     =   1.36; // Holladay 1
    double pAcd   =   4.97; // Hoffer Q
    // a0/a1/a2 removed — Haigis not used
};

// ─── Result for one lens panel ────────────────────────────────
struct IolResult {
    bool   valid       = false;
    double emmPower    = 0.0;
    double iolPower[5] = {};
    double predRx[5]   = {};
};

class CalculatorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CalculatorDialog(QWidget *parent = nullptr);
    ~CalculatorDialog();

    void setPatientId(const QString &patientId);
    void setDoctorId (const QString &doctorId);
    void setBiometerValues(double k1, double k2, double k, double al, double rx = 0.0);


protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void updateTime();

    void on_comboBox_lensOne_currentIndexChanged  (int index);
    void on_comboBox_lensTwo_currentIndexChanged  (int index);
    void on_comboBox_lensThree_currentIndexChanged(int index);

    void on_btn_home_clicked();
    void on_btn_measure_clicked();
    void on_btn_newPatient_clicked();
    void on_btn_print_clicked();

    void on_btn_srkt_clicked();
    void on_btn_srkii_clicked();
    void on_btn_hofferq_clicked();
    void on_btn_holladay_clicked();
    void on_btn_haigis_clicked();   // kept in slots — but does nothing

    void on_btn_warning1_clicked();
    void on_btn_warning2_clicked();
    void on_btn_warning3_clicked();

    void on_btn_eye_clicked();

private:
    Ui::CalculatorDialog *ui;
    QTimer               *clockTimer;
    QSqlDatabase          db;
    QString               m_patientId;

    QString               m_doctorId;
    IolFormula            m_formula { IolFormula::SRKII };

    // ── Setup ────────────────────────────────────────────────
    bool openDatabase();
    void populateAllCombos();
    void populateCombo(QComboBox *cb);
    void installEventFilters();

    // ── Lens selection ───────────────────────────────────────
    void loadLensIntoPanel(int panelNum, int comboIndex);
    void updateConstantVisibility();

    // ── Calculation ──────────────────────────────────────────
    void calculate();
    void updateFormula(IolFormula f);
    void runAndFillPanel(int panelNum, double k, double al, double rx);
    void fillPanel(int panelNum, const IolResult &r);
    LensConstants readLensConstants(int panelNum) const;

    // ── Formula engines removed — handled by IOLCalculator lib ──
    // calcSRKII / calcSRKT / calcHofferQ / calcHolladay /
    // calcHaigis / predictedRx  → all deleted

    void loadPatientHeader();
    void loadDoctorLensPresets();
    void selectLensInCombo(QComboBox *cb, const QString &preset);
    void loadBiometerForEye();
    void updateEyeButtonText();

    void updateFormulaButtonStyle(QPushButton *selectedButton);

    int m_eye = 0;   // 0 = OS, 1 = OD  (matches rleye convention)
};

#endif // CALCULATORDIALOG_H
