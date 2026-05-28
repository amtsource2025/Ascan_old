#ifndef KEYPAD_H
#define KEYPAD_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class Keypad;
}

// ─── Keyboard display mode ────────────────────────────────────────────────────
enum class KeyMode {
    CAPS,       // Initial state  → Touch-Keyboard1.png  (uppercase)
    LOWER,      // After 1st char → Touch-Keyboard.png   (lowercase)
    NUMERIC     // ?123 pressed   → Touch-Keyboard2.png  (numbers/symbols)
};

class Keypad : public QDialog
{
    Q_OBJECT

public:
    explicit Keypad(QLineEdit *targetInput, QWidget *parent = nullptr);
    ~Keypad();

private slots:
    // ── Letter buttons (all routed through one slot) ──────────────────────────
    void onLetterPressed();

    // ── Special / control buttons ─────────────────────────────────────────────
    void on_spacebutton_clicked();
    void on_apostrophe_clicked();
    void on_comma_clicked();
    void on_question_clicked();
    void on_fstop_clicked();
    void on_bpbutton_clicked();

    // ↑ Caps-Lock toggle (left + right)
    void on_numbutton_clicked();    // ↑ left
    void on_numbutton_2_clicked();  // ↑ right

    // ?123 / ABC toggle (left + right)
    void on_numbutton_3_clicked();  // ?123 left  / ABC left
    void on_numbutton_4_clicked();  // ?123 right / ABC right

    // Enter / Close
    void on_donebutton_clicked();
    void on_donebutton_2_clicked();

private:
    Ui::Keypad   *ui;
    QLineEdit    *targetLineEdit;

    KeyMode       currentMode;
    KeyMode       previousAlphaMode; // remembers CAPS or LOWER when entering NUMERIC

    void connectAllLetters();
    void setMode(KeyMode mode);
    void updateBackground();
    QString numericCharForButton(QPushButton *btn) const;
};

#endif // KEYPAD_H
