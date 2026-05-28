#ifndef NUMERICPAD_H
#define NUMERICPAD_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class Numericpad;
}

class Numericpad : public QDialog
{
    Q_OBJECT

public:
    explicit Numericpad(QLineEdit *targetInput, QWidget *parent = nullptr);
    ~Numericpad();

private slots:
    void onNumberPressed();
    void on_Buttondot_clicked();
    void on_Buttonbp_clicked();   // backspace
    void on_Buttonclr_clicked();  // clear
    void on_Buttondne_clicked();  // done

private:
    Ui::Numericpad *ui;
    QLineEdit      *targetLineEdit;

    void connectAllNumbers();
};

#endif // NUMERICPAD_H
