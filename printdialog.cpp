#include "printdialog.h"
#include "ui_printdialog.h"
#include "promptdialog.h"

// ─────────────────────────────────────────────────────────────
//  Constructor / Destructor
// ─────────────────────────────────────────────────────────────
PrintDialog::PrintDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PrintDialog)
    , clockTimer(new QTimer(this))
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    // ── Clock ─────────────────────────────────────────────────
    connect(clockTimer, &QTimer::timeout, this, &PrintDialog::updateTime);
    clockTimer->start(1000);
    updateTime();

    // ── Start on main menu page ───────────────────────────────
    showPage(PAGE_MENU);

    // ── Progress bars hidden until a print job starts ─────────
    ui->progressBar->setValue(0);
    ui->progressBar_2->setValue(0);

}

PrintDialog::~PrintDialog()
{
    delete ui;
}

// ─────────────────────────────────────────────────────────────
//  Setters
// ─────────────────────────────────────────────────────────────
void PrintDialog::setPatientId(const QString &patientId)
{
    m_patientId = patientId;
}

void PrintDialog::setDoctorId(const QString &doctorId)
{
    m_doctorId = doctorId;
}

// ─────────────────────────────────────────────────────────────
//  Clock
// ─────────────────────────────────────────────────────────────
void PrintDialog::updateTime()
{
    ui->lbl_time->setText(QTime::currentTime().toString("hh:mm"));
}

// ─────────────────────────────────────────────────────────────
//  Navigation helper
// ─────────────────────────────────────────────────────────────
void PrintDialog::showPage(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}

// ─────────────────────────────────────────────────────────────
//  Print helper — sends text to the selected printer type
// ─────────────────────────────────────────────────────────────
void PrintDialog::doPrint(const QString &content)
{
    // TODO: implement actual thermal / A4 printing via QPrinter
    // comboBox holds "Thermal" / "A4" etc.
    QString printerType = ui->comboBox->currentText();
    qDebug() << "Printing via" << printerType << ":\n" << content;
}

// ─────────────────────────────────────────────────────────────
//  Main-menu buttons
// ─────────────────────────────────────────────────────────────
void PrintDialog::on_btn_back_clicked()
{
    reject();
}

void PrintDialog::on_btn_scan_clicked()
{
    // Populate plainTextEdit_scan with scan data then show page
    ui->plainTextEdit_scan->setPlainText(
        "Patient ID : " + m_patientId + "\n"
                                        "Doctor  ID : " + m_doctorId  + "\n\n"
                       "[Scan data will appear here]");
    showPage(PAGE_SCAN);
}

void PrintDialog::on_btn_calculations_clicked()
{
    ui->plainTextEdit_calc->setPlainText(
        "Patient ID : " + m_patientId + "\n"
                                        "Doctor  ID : " + m_doctorId  + "\n\n"
                       "[Calculation results will appear here]");
    showPage(PAGE_CALC);
}

void PrintDialog::on_btn_both_clicked()
{
    ui->plainTextEdit_all->setPlainText(
        "Patient ID : " + m_patientId + "\n"
                                        "Doctor  ID : " + m_doctorId  + "\n\n"
                       "[Scan + Calculation data will appear here]");
    showPage(PAGE_BOTH);
}

void PrintDialog::on_btn_newPatient_clicked()
{
    // TODO: open AddPatientDialog from within PrintDialog
    PromptDialog p("New Patient",
                   "New Patient from Print — not yet implemented.", this);
    p.exec();
}

// ─────────────────────────────────────────────────────────────
//  Page-level print triggers
// ─────────────────────────────────────────────────────────────
void PrintDialog::on_btn_scan2_clicked()
{
    doPrint(ui->plainTextEdit_scan->toPlainText());
}

void PrintDialog::on_btn_calculations2_clicked()
{
    doPrint(ui->plainTextEdit_calc->toPlainText());
}

void PrintDialog::on_btn_both2_clicked()
{
    doPrint(ui->plainTextEdit_all->toPlainText());
}

void PrintDialog::on_btn_both3_clicked()
{
    // Secondary "both" trigger (same page, possibly different button position)
    doPrint(ui->plainTextEdit_all->toPlainText());
}

void PrintDialog::on_btn_newPatient2_clicked()
{
    PromptDialog p("New Patient",
                   "New Patient from Print — not yet implemented.", this);
    p.exec();
}
