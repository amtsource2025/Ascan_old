#include "keypad.h"
#include "ui_keypad.h"

// ─────────────────────────────────────────────────────────────────────────────
//  NUMERIC MODE symbol map (Image 4 layout)
//
//  The same 26 letter-position buttons are reused for symbols in NUMERIC mode.
//  Positions follow QWERTY physical order:
//
//  Row 1 (top):    q w e r t y u i o p      → 1 2 3 4 5 6 7 8 9 0
//  Row 2 (middle): a s d f g h j k l '      → - / : ; ( ) $ & @  [apostrophe pos stays apostrophe → not a letter btn]
//  Row 3 (bottom): z x c v b n m , . ?      → ↑ . , ? ! ' " # _  [↑ and specials handled separately]
//
//  Letter buttons only cover a-z (26 letters).
//  Row 2 apostrophe and Row 3 comma/fstop/question are separate buttons,
//  so they handle their own numeric output.
// ─────────────────────────────────────────────────────────────────────────────

// Map: button object name  →  numeric-mode character
static const QMap<QString, QString> kNumericMap = {
    // Row 1 — 1..0
    {"qbutton", "1"}, {"wbutton", "2"}, {"ebutton", "3"}, {"rbutton", "4"},
    {"tbutton", "5"}, {"ybutton", "6"}, {"ubutton", "7"}, {"ibutton", "8"},
    {"obutton", "9"}, {"pbutton", "0"},

    // Row 2 — symbols
    {"abutton", "-"}, {"sbutton", "/"}, {"dbutton", ":"}, {"fbutton", ";"},
    {"gbutton", "("}, {"hbutton", ")"}, {"jbutton", "$"}, {"kbutton", "&"},
    {"lbutton", "@"},
    // vbutton sits at row-3 position after z x c v ...
    // Row 3 letter buttons (z x c v b n m) map to symbols
    {"zbutton", "."}, {"xbutton", ","}, {"cbutton", "?"}, {"vbutton", "!"},
    {"bbutton", "'"}, {"nbutton", "\""}, {"mbutton", "#"},
    };

// ─────────────────────────────────────────────────────────────────────────────
Keypad::Keypad(QLineEdit *targetInput, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Keypad)
    , targetLineEdit(targetInput)
    , currentMode(KeyMode::CAPS)
    , previousAlphaMode(KeyMode::CAPS)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    connectAllLetters();

    // Start in CAPS mode
    setMode(KeyMode::CAPS);
}

Keypad::~Keypad()
{
    delete ui;
}

// ─── Connect every letter button to one generic slot ─────────────────────────
void Keypad::connectAllLetters()
{
    QList<QPushButton*> letterButtons = {
        ui->abutton, ui->bbutton, ui->cbutton, ui->dbutton,
        ui->ebutton, ui->fbutton, ui->gbutton, ui->hbutton,
        ui->ibutton, ui->jbutton, ui->kbutton, ui->lbutton,
        ui->mbutton, ui->nbutton, ui->obutton, ui->pbutton,
        ui->qbutton, ui->rbutton, ui->sbutton, ui->tbutton,
        ui->ubutton, ui->vbutton, ui->wbutton, ui->xbutton,
        ui->ybutton, ui->zbutton
    };

    for (QPushButton *btn : letterButtons)
        connect(btn, &QPushButton::clicked, this, &Keypad::onLetterPressed);
}

// ─── Mode switching ──────────────────────────────────────────────────────────
void Keypad::setMode(KeyMode mode)
{
    currentMode = mode;
    updateBackground();
}

void Keypad::updateBackground()
{
    QString image;
    switch (currentMode) {
    case KeyMode::CAPS:
        // Uppercase keyboard image  (Touch-Keyboard1.png)
        image = "background-image: url(:/images/Touch-Keyboard1.png);";
        break;
    case KeyMode::LOWER:
        // Lowercase keyboard image  (Touch-Keyboard.png)
        image = "background-image: url(:/images/Touch-Keyboard.png);";
        break;
    case KeyMode::NUMERIC:
        // Numeric/symbol keyboard image  (Touch-Keyboard2.png)
        image = "background-image: url(:/images/Touch-Keyboard2.png);";
        break;
    }
    this->setStyleSheet(image);
}

// ─── Numeric character lookup ─────────────────────────────────────────────────
QString Keypad::numericCharForButton(QPushButton *btn) const
{
    return kNumericMap.value(btn->objectName(), "");
}

// ─── Generic letter press ─────────────────────────────────────────────────────
void Keypad::onLetterPressed()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (!btn || !targetLineEdit) return;

    QString text;

    if (currentMode == KeyMode::NUMERIC) {
        // Output the symbol mapped to this button's position
        text = numericCharForButton(btn);
    } else {
        // Use the button's object name to derive the letter (e.g. "abutton" → "a")
        // Object names are all lowercase letters + "button"
        QString letter = btn->objectName().left(1); // first char = the letter
        text = (currentMode == KeyMode::CAPS) ? letter.toUpper() : letter.toLower();
    }

    if (!text.isEmpty()) {
        targetLineEdit->insert(text);

        // After typing ANY character in CAPS mode → auto-switch to LOWER
        if (currentMode == KeyMode::CAPS) {
            setMode(KeyMode::LOWER);
        }
    }
}

// ─── Space ───────────────────────────────────────────────────────────────────
void Keypad::on_spacebutton_clicked()
{
    if (!targetLineEdit) return;
    targetLineEdit->insert(" ");

    // Space also counts as a character — switch CAPS → LOWER
    if (currentMode == KeyMode::CAPS)
        setMode(KeyMode::LOWER);
}

// ─── Apostrophe ──────────────────────────────────────────────────────────────
void Keypad::on_apostrophe_clicked()
{
    if (!targetLineEdit) return;

    // In NUMERIC mode the apostrophe position shows '@'
    QString ch = (currentMode == KeyMode::NUMERIC) ? "@" : "'";
    targetLineEdit->insert(ch);

    if (currentMode == KeyMode::CAPS)
        setMode(KeyMode::LOWER);
}

// ─── Comma ───────────────────────────────────────────────────────────────────
void Keypad::on_comma_clicked()
{
    if (!targetLineEdit) return;
    // Numeric mode: comma position → '_'  (underscore, per image 4 row 3)
    QString ch = (currentMode == KeyMode::NUMERIC) ? "_" : ",";
    targetLineEdit->insert(ch);

    if (currentMode == KeyMode::CAPS)
        setMode(KeyMode::LOWER);
}

// ─── Full-stop ────────────────────────────────────────────────────────────────
void Keypad::on_fstop_clicked()
{
    if (!targetLineEdit) return;
    // Numeric mode: dot stays as '.'
    targetLineEdit->insert(".");

    if (currentMode == KeyMode::CAPS)
        setMode(KeyMode::LOWER);
}

// ─── Question mark ───────────────────────────────────────────────────────────
void Keypad::on_question_clicked()
{
    if (!targetLineEdit) return;
    // Numeric mode: question position → (empty / not used separately)
    targetLineEdit->insert("?");

    if (currentMode == KeyMode::CAPS)
        setMode(KeyMode::LOWER);
}

// ─── Backspace ───────────────────────────────────────────────────────────────
void Keypad::on_bpbutton_clicked()
{
    if (targetLineEdit) targetLineEdit->backspace();
    // No mode change on backspace
}

// ─── ↑ Caps Lock — LEFT (numbutton) ──────────────────────────────────────────
void Keypad::on_numbutton_clicked()
{
    if (currentMode == KeyMode::NUMERIC) return; // ignore in numeric mode

    if (currentMode == KeyMode::LOWER)
        setMode(KeyMode::CAPS);
    else
        setMode(KeyMode::LOWER);
}

// ─── ↑ Caps Lock — RIGHT (numbutton_2) ───────────────────────────────────────
void Keypad::on_numbutton_2_clicked()
{
    on_numbutton_clicked(); // same behaviour
}

// ─── ?123 / ABC — LEFT (numbutton_3) ─────────────────────────────────────────
void Keypad::on_numbutton_3_clicked()
{
    if (currentMode == KeyMode::NUMERIC) {
        // Currently NUMERIC → go back to previous alpha mode (CAPS or LOWER)
        setMode(previousAlphaMode);
    } else {
        // Currently alpha → switch to NUMERIC, remember where we came from
        previousAlphaMode = currentMode;
        setMode(KeyMode::NUMERIC);
    }
}

// ─── ?123 / ABC — RIGHT (numbutton_4) ────────────────────────────────────────
void Keypad::on_numbutton_4_clicked()
{
    on_numbutton_3_clicked(); // same behaviour
}

// ─── Enter / Accept ──────────────────────────────────────────────────────────
void Keypad::on_donebutton_clicked()
{
    this->accept();
}

// ─── Close / Reject ──────────────────────────────────────────────────────────
void Keypad::on_donebutton_2_clicked()
{
    this->reject();
}
