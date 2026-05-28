#include "promptdialog.h"
#include "ui_promptdialog.h"

PromptDialog::PromptDialog(const QString &title,
                           const QString &message,
                           QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PromptDialog)
{
    ui->setupUi(this);
    setWindowTitle(title);
    ui->label->setText(title);
    ui->label_2->setText(message);
}

PromptDialog::~PromptDialog()
{
    delete ui;
}

void PromptDialog::on_btn_yes_clicked() { accept(); }
void PromptDialog::on_btn_no_clicked()  { reject(); }
