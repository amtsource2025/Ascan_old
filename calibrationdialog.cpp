#include "calibrationdialog.h"
#include "ui_calibrationdialog.h"

// ─────────────────────────────────────────────────────────────
//  Constructor / Destructor
// ─────────────────────────────────────────────────────────────
CalibrationDialog::CalibrationDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CalibrationDialog)
    , clockTimer(new QTimer(this))
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    // ── Clock ─────────────────────────────────────────────────
    connect(clockTimer, &QTimer::timeout, this, &CalibrationDialog::updateTime);
    clockTimer->start(1000);
    updateTime();

    // ── Initial state ─────────────────────────────────────────
    ui->lineEdit_avgAl->clear();
    if (ui->lbl_avgAl)
        ui->lbl_avgAl->clear();
}

CalibrationDialog::~CalibrationDialog()
{
    delete ui;
}

// ─────────────────────────────────────────────────────────────
//  Clock
// ─────────────────────────────────────────────────────────────
void CalibrationDialog::updateTime()
{
    // lbl_time may not be present in all UI versions — guard it
    if (ui->label)
        ui->label->setText(QTime::currentTime().toString("hh:mm"));
}

// ─────────────────────────────────────────────────────────────
//  Start calibration
// ─────────────────────────────────────────────────────────────
void CalibrationDialog::on_btn_start_clicked()
{
    // TODO: trigger hardware calibration sequence
    // The wm_plt QFrame hosts the waveform / A-scan plot widget.
    // Connect your hardware signal here and update lineEdit_avgAl
    // when an average AL value is computed.
    qDebug() << "Calibration started";
}

// ─────────────────────────────────────────────────────────────
//  Back → close dialog
// ─────────────────────────────────────────────────────────────
void CalibrationDialog::on_btn_back_clicked()
{
    reject();
}
