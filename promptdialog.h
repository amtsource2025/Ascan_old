#ifndef PROMPTDIALOG_H
#define PROMPTDIALOG_H

#include <QDialog>

namespace Ui { class PromptDialog; }

class PromptDialog : public QDialog
{
    Q_OBJECT
public:
    explicit PromptDialog(const QString &title,
                          const QString &message,
                          QWidget *parent = nullptr);
    ~PromptDialog();

private slots:
    void on_btn_yes_clicked();
    void on_btn_no_clicked();

private:
    Ui::PromptDialog *ui;
};

#endif
