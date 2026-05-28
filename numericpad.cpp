#include "numericpad.h"
#include "ui_numericpad.h"

Numericpad::Numericpad(QLineEdit *targetInput, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Numericpad)
    , targetLineEdit(targetInput)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    connectAllNumbers();
}

Numericpad::~Numericpad()
{
    delete ui;
}

// ─── Connect all number buttons to one slot ────────────────────────────────────
void Numericpad::connectAllNumbers()
{
    QList<QPushButton*> numButtons = {
        ui->Button0, ui->Button1, ui->Button2, ui->Button3,
        ui->Button4, ui->Button5, ui->Button6, ui->Button7,
        ui->Button8, ui->Button9
    };

    for (QPushButton *btn : numButtons) {
        connect(btn, &QPushButton::clicked, this, &Numericpad::onNumberPressed);
    }
}

// ─── Number press ─────────────────────────────────────────────────────────────
void Numericpad::onNumberPressed()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (!btn || !targetLineEdit) return;
    targetLineEdit->insert(btn->text());
}

// ─── Dot ──────────────────────────────────────────────────────────────────────
void Numericpad::on_Buttondot_clicked()
{
    if (!targetLineEdit) return;
    // Allow only one decimal point
    if (!targetLineEdit->text().contains('.'))
        targetLineEdit->insert(".");
}

// ─── Backspace ────────────────────────────────────────────────────────────────
void Numericpad::on_Buttonbp_clicked()
{
    if (targetLineEdit) targetLineEdit->backspace();
}

// ─── Clear ────────────────────────────────────────────────────────────────────
void Numericpad::on_Buttonclr_clicked()
{
    if (targetLineEdit) targetLineEdit->clear();
}

// ─── Done ─────────────────────────────────────────────────────────────────────
void Numericpad::on_Buttondne_clicked()
{
    this->accept();
}
