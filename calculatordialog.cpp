#include "calculatordialog.h"
#include "ui_calculatordialog.h"
#include "printdialog.h"
#include "addpatientdialog.h"
#include "promptdialog.h"
#include "homescreendialog.h"

// ─────────────────────────────────────────────────────────────
//  Constructor / Destructor
// ─────────────────────────────────────────────────────────────
CalculatorDialog::CalculatorDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CalculatorDialog)
    , clockTimer(new QTimer(this))
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    if (!openDatabase()) {
        qDebug() << "CalculatorDialog: Failed to open database!";
    }

    // ── Clock ─────────────────────────────────────────────────
    connect(clockTimer, &QTimer::timeout, this, &CalculatorDialog::updateTime);
    clockTimer->start(1000);
    updateTime();

    // ── Default formula tab: SRK II ───────────────────────────
    // (the red tab in the screenshot)
}

CalculatorDialog::~CalculatorDialog()
{

    delete ui;
}

// ─────────────────────────────────────────────────────────────
//  Setters
// ─────────────────────────────────────────────────────────────
void CalculatorDialog::setPatientId(const QString &patientId)
{
    m_patientId = patientId;
}

void CalculatorDialog::setDoctorId(const QString &doctorId)
{
    m_doctorId = doctorId;
}

// ─────────────────────────────────────────────────────────────
//  Database
// ─────────────────────────────────────────────────────────────
bool CalculatorDialog::openDatabase()
{
    const QString connName = "calculator_conn";
    if (QSqlDatabase::contains(connName)) {
        db = QSqlDatabase::database(connName);
    } else {
       db = QSqlDatabase::database();
    }
    if (!db.open()) {
        qDebug() << "DB Error:" << db.lastError().text();
        return false;
    }
    return true;
}

// ─────────────────────────────────────────────────────────────
//  Clock
// ─────────────────────────────────────────────────────────────
void CalculatorDialog::updateTime()
{
    // lbl_time label exists per the Object Inspector
}

// ─────────────────────────────────────────────────────────────
//  Formula helpers
// ─────────────────────────────────────────────────────────────
void CalculatorDialog::updateFormula(const QString &formula)
{
    // TODO: recalculate IOL values based on chosen formula and
    //       populate the cdisp* QLineEdit fields.
    qDebug() << "Active formula:" << formula;
}

void CalculatorDialog::calculate()
{
    // TODO: read K1, K2, AL etc. from display fields,
    //       run the active formula, write results to cdisp* fields.
}

// ─────────────────────────────────────────────────────────────
//  Formula tab buttons
// ─────────────────────────────────────────────────────────────
void CalculatorDialog::on_btn_srkt_clicked()   { updateFormula("SRK T");    }
void CalculatorDialog::on_btn_srkii_clicked()  { updateFormula("SRK II");   }
void CalculatorDialog::on_btn_hofferq_clicked(){ updateFormula("Hoffer Q"); }
void CalculatorDialog::on_btn_holladay_clicked(){ updateFormula("Holladay");}
void CalculatorDialog::on_btn_haigis_clicked() { updateFormula("Haigis");   }

// ─────────────────────────────────────────────────────────────
//  Warning / info buttons
// ─────────────────────────────────────────────────────────────
void CalculatorDialog::on_btn_warning1_clicked()
{
    PromptDialog p("Info", "Lens 1 — no warning details yet.", this);
    p.exec();
}

void CalculatorDialog::on_btn_warning2_clicked()
{
    PromptDialog p("Info", "Lens 2 — no warning details yet.", this);
    p.exec();
}

void CalculatorDialog::on_btn_warning3_clicked()
{
    PromptDialog p("Info", "Lens 3 — no warning details yet.", this);
    p.exec();
}

// ─────────────────────────────────────────────────────────────
//  Navigation buttons
// ─────────────────────────────────────────────────────────────
void CalculatorDialog::on_btn_home_clicked()
{
    HomeScreenDialog homeScreen(m_patientId, m_doctorId, this);
    homeScreen.exec();
}

void CalculatorDialog::on_btn_measure_clicked()
{
    accept();
}

void CalculatorDialog::on_btn_newPatient_clicked()
{
    AddPatientDialog *dlg = new AddPatientDialog(this);
    dlg->exec();
    delete dlg;
}

void CalculatorDialog::on_btn_print_clicked()
{
    PrintDialog *dlg = new PrintDialog(this);
    dlg->setPatientId(m_patientId);
    dlg->setDoctorId(m_doctorId);
    dlg->exec();
    delete dlg;
}
