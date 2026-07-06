// #include "calculatordialog.h"
// #include "ui_calculatordialog.h"
// #include "printdialog.h"
// #include "addpatientdialog.h"
// #include "promptdialog.h"
// #include "homescreendialog.h"
// #include "IOLCalculator.h"

// #include <QLineEdit>
// #include <QLabel>
// #include <QComboBox>
// #include <cmath>
// #include <limits>

// // ═════════════════════════════════════════════════════════════
// //  Constructor / Destructor
// // ═════════════════════════════════════════════════════════════
// CalculatorDialog::CalculatorDialog(QWidget *parent)
//     : QDialog(parent)
//     , ui(new Ui::CalculatorDialog)
//     , clockTimer(new QTimer(this))
// {
//     ui->setupUi(this);
//     setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

//     if (!openDatabase())
//         qDebug() << "CalculatorDialog: Failed to open database!";

//     connect(clockTimer, &QTimer::timeout, this, &CalculatorDialog::updateTime);
//     clockTimer->start(1000);
//     updateTime();

//     populateAllCombos();
//     installEventFilters();

//     connect(ui->lbl_alValEdit,    &QLineEdit::editingFinished, this, &CalculatorDialog::calculate);
//     connect(ui->lbl_rxValEdit,    &QLineEdit::editingFinished, this, &CalculatorDialog::calculate);
//     connect(ui->lineEdit_aconst1, &QLineEdit::editingFinished, this, &CalculatorDialog::calculate);
//     connect(ui->lineEdit_aconst2, &QLineEdit::editingFinished, this, &CalculatorDialog::calculate);
//     connect(ui->lineEdit_aconst3, &QLineEdit::editingFinished, this, &CalculatorDialog::calculate);

//     m_formula = IolFormula::SRKII;
//     updateConstantVisibility();
//     calculate();
// }

// CalculatorDialog::~CalculatorDialog() { delete ui; }

// // ═════════════════════════════════════════════════════════════
// //  Public setters
// // ═════════════════════════════════════════════════════════════
// void CalculatorDialog::setPatientId(const QString &id)
// {
//     m_patientId = id;
//     loadPatientHeader();
// }

// void CalculatorDialog::setDoctorId(const QString &id)
// {
//     m_doctorId = id;
//     loadPatientHeader();
//     loadDoctorLensPresets();
// }

// void CalculatorDialog::setBiometerValues(double k1, double k2, double al, double rx)
// {
//     ui->lbl_k1ValEdit1->setText(QString::number(k1,          'f', 2));
//     ui->lbl_k2ValEdit ->setText(QString::number(k2,          'f', 2));
//     ui->lbl_kValEdit  ->setText(QString::number((k1+k2)/2.0, 'f', 2));
//     ui->lbl_alValEdit ->setText(QString::number(al,          'f', 2));
//     ui->lbl_rxValEdit ->setText(QString::number(rx,          'f', 2));
//     calculate();
// }

// // ═════════════════════════════════════════════════════════════
// //  Database
// // ═════════════════════════════════════════════════════════════
// bool CalculatorDialog::openDatabase()
// {
//     const QString conn = "calculator_conn";
//     db = QSqlDatabase::contains(conn)
//              ? QSqlDatabase::database(conn)
//              : QSqlDatabase::database();
//     if (!db.open()) {
//         qDebug() << "DB Error:" << db.lastError().text();
//         return false;
//     }
//     return true;
// }

// // ═════════════════════════════════════════════════════════════
// //  Populate lens combo boxes
// // ═════════════════════════════════════════════════════════════
// void CalculatorDialog::populateAllCombos()
// {
//     populateCombo(ui->comboBox_lensOne);
//     populateCombo(ui->comboBox_lensTwo);
//     populateCombo(ui->comboBox_lensThree);
// }

// void CalculatorDialog::populateCombo(QComboBox *cb)
// {
//     if (!cb) return;
//     cb->blockSignals(true);
//     cb->clear();
//     cb->addItem("-- Select Lens --", -1);

//     QSqlQuery q(db);
//     if (q.exec("SELECT rowid, iol, company FROM lens ORDER BY iol ASC")) {
//         while (q.next()) {
//             int     rowid   = q.value(0).toInt();
//             QString iol     = q.value(1).toString();
//             QString company = q.value(2).toString();
//             QString label   = company.isEmpty() ? iol : QString("%1  (%2)").arg(iol, company);
//             cb->addItem(label, rowid);
//         }
//     } else {
//         qDebug() << "Combo query error:" << q.lastError().text();
//     }
//     cb->blockSignals(false);
// }

// // ═════════════════════════════════════════════════════════════
// //  Load lens constants into panel
// //  FIX: all 3 Haigis constants (a0, a1, a2) now read correctly
// // ═════════════════════════════════════════════════════════════
// void CalculatorDialog::loadLensIntoPanel(int panelNum, int comboIndex)
// {
//     QComboBox *cb = nullptr;
//     if      (panelNum == 1) cb = ui->comboBox_lensOne;
//     else if (panelNum == 2) cb = ui->comboBox_lensTwo;
//     else                    cb = ui->comboBox_lensThree;

//     if (!cb) return;

//     int rowid = cb->itemData(comboIndex).toInt();
//     if (rowid < 0) return;  // "-- Select Lens --" selected, nothing to load

//     QSqlQuery q(db);
//     q.prepare("SELECT asrkt, asrkii, acd, sf, a0, a1, a2 "
//               "FROM lens WHERE rowid = :id");
//     q.bindValue(":id", rowid);

//     if (!q.exec() || !q.next()) {
//         qDebug() << "Lens load error:" << q.lastError().text();
//         return;
//     }

//     double asrkt  = q.value(0).toDouble();
//     double asrkii = q.value(1).toDouble();
//     double acd    = q.value(2).toDouble();
//     double sf     = q.value(3).toDouble();
//     double a0     = q.value(4).toDouble();  // Haigis a0
//     double a1     = q.value(5).toDouble();  // Haigis a1
//     double a2     = q.value(6).toDouble();  // Haigis a2 — FIX: was never read before

//     auto set = [](QLineEdit *le, double v) {
//         if (le) le->setText(QString::number(v, 'f', 4));
//     };

//     if (panelNum == 1) {
//         set(ui->lineEdit_aconst1,  asrkii);  // SRK II A-constant
//         set(ui->lineEdit_aconst12, asrkt);   // SRK/T A-constant
//         set(ui->lineEdit_acd1,     acd);
//         set(ui->lineEdit_acd12,    acd);
//         set(ui->lineEdit_sf1,      sf);
//         set(ui->lineEdit_sf12,     sf);
//         set(ui->lineEdit_A0,       a0);      // Haigis a0
//         set(ui->lineEdit_A02,      a1);      // Haigis a1  (widget named A02)
//         // Note: a2 maps to a3rd Haigis widget if you add one later
//         Q_UNUSED(a2);
//     } else if (panelNum == 2) {
//         set(ui->lineEdit_aconst2,  asrkii);
//         set(ui->lineEdit_aconst22, asrkt);
//         set(ui->lineEdit_acd2,     acd);
//         set(ui->lineEdit_acd22,    acd);
//         set(ui->lineEdit_sf2,      sf);
//         set(ui->lineEdit_sf22,     sf);
//         set(ui->lineEdit_A1,       a0);
//         set(ui->lineEdit_A12,      a1);
//         Q_UNUSED(a2);
//     } else {
//         set(ui->lineEdit_aconst3,  asrkii);
//         set(ui->lineEdit_aconst32, asrkt);
//         set(ui->lineEdit_acd3,     acd);
//         set(ui->lineEdit_acd32,    acd);
//         set(ui->lineEdit_sf3,      sf);
//         set(ui->lineEdit_sf32,     sf);
//         set(ui->lineEdit_A2,       a0);
//         set(ui->lineEdit_A22,      a1);
//         Q_UNUSED(a2);
//     }

//     calculate();
// }

// // ═════════════════════════════════════════════════════════════
// //  Constant visibility
// //  FIX: Panel 3 label visibility was completely missing
// // ═════════════════════════════════════════════════════════════
// void CalculatorDialog::updateConstantVisibility()
// {
//     bool showAconst = (m_formula == IolFormula::SRKII || m_formula == IolFormula::SRKT);
//     bool showSF     = (m_formula == IolFormula::Holladay);
//     bool showAcd    = (m_formula == IolFormula::HofferQ);

//     // ── Panel 1 ──────────────────────────────────────────────
//     if (ui->lbl_aconst1)       ui->lbl_aconst1      ->setVisible(showAconst);
//     if (ui->lbl_sf1)           ui->lbl_sf1           ->setVisible(showSF);
//     if (ui->lbl_acd1)          ui->lbl_acd1          ->setVisible(showAcd);
//     if (ui->lbl_a0)            ui->lbl_a0            ->setVisible(false);   // Haigis — always hidden

//     if (ui->lineEdit_aconst1)  ui->lineEdit_aconst1  ->setVisible(showAconst);
//     if (ui->lineEdit_aconst12) ui->lineEdit_aconst12 ->setVisible(false);
//     if (ui->lineEdit_sf1)      ui->lineEdit_sf1      ->setVisible(showSF);
//     if (ui->lineEdit_sf12)     ui->lineEdit_sf12     ->setVisible(false);
//     if (ui->lineEdit_acd1)     ui->lineEdit_acd1     ->setVisible(showAcd);
//     if (ui->lineEdit_acd12)    ui->lineEdit_acd12    ->setVisible(false);
//     if (ui->lineEdit_A0)       ui->lineEdit_A0       ->setVisible(false);   // Haigis
//     if (ui->lineEdit_A02)      ui->lineEdit_A02      ->setVisible(false);   // Haigis

//     // ── Panel 2 ──────────────────────────────────────────────
//     if (ui->lbl_aconst2)       ui->lbl_aconst2       ->setVisible(showAconst);
//     if (ui->lbl_sf2)           ui->lbl_sf2           ->setVisible(showSF);   // FIX: was missing
//     if (ui->lbl_acd2)          ui->lbl_acd2          ->setVisible(showAcd);  // FIX: was missing

//     if (ui->lineEdit_aconst2)  ui->lineEdit_aconst2  ->setVisible(showAconst);
//     if (ui->lineEdit_aconst22) ui->lineEdit_aconst22 ->setVisible(false);
//     if (ui->lineEdit_sf2)      ui->lineEdit_sf2      ->setVisible(showSF);
//     if (ui->lineEdit_sf22)     ui->lineEdit_sf22     ->setVisible(false);
//     if (ui->lineEdit_acd2)     ui->lineEdit_acd2     ->setVisible(showAcd);
//     if (ui->lineEdit_acd22)    ui->lineEdit_acd22    ->setVisible(false);
//     if (ui->lineEdit_A1)       ui->lineEdit_A1       ->setVisible(false);    // Haigis
//     if (ui->lineEdit_A12)      ui->lineEdit_A12      ->setVisible(false);    // Haigis

//     // ── Panel 3 ── FIX: labels were never toggled before ─────
//     if (ui->lbl_aconst3)       ui->lbl_aconst3       ->setVisible(showAconst);
//     if (ui->lbl_sf3)           ui->lbl_sf3           ->setVisible(showSF);
//     if (ui->lbl_acd3)          ui->lbl_acd3          ->setVisible(showAcd);

//     if (ui->lineEdit_aconst3)  ui->lineEdit_aconst3  ->setVisible(showAconst);
//     if (ui->lineEdit_aconst32) ui->lineEdit_aconst32 ->setVisible(false);
//     if (ui->lineEdit_sf3)      ui->lineEdit_sf3      ->setVisible(showSF);
//     if (ui->lineEdit_sf32)     ui->lineEdit_sf32     ->setVisible(false);
//     if (ui->lineEdit_acd3)     ui->lineEdit_acd3     ->setVisible(showAcd);
//     if (ui->lineEdit_acd32)    ui->lineEdit_acd32    ->setVisible(false);
//     if (ui->lineEdit_A2)       ui->lineEdit_A2       ->setVisible(false);    // Haigis
//     if (ui->lineEdit_A22)      ui->lineEdit_A22      ->setVisible(false);    // Haigis
// }

// // ═════════════════════════════════════════════════════════════
// //  Event filter / Numericpad
// // ═════════════════════════════════════════════════════════════
// void CalculatorDialog::installEventFilters()
// {
//     const QList<QLineEdit*> numericFields = {
//         ui->lbl_alValEdit,
//         ui->lbl_rxValEdit,
//         ui->lineEdit_aconst1,  ui->lineEdit_aconst2,  ui->lineEdit_aconst3,
//         ui->lineEdit_aconst12, ui->lineEdit_aconst22, ui->lineEdit_aconst32,
//         ui->lineEdit_sf1,      ui->lineEdit_sf2,      ui->lineEdit_sf3,
//         ui->lineEdit_sf12,     ui->lineEdit_sf22,     ui->lineEdit_sf32,
//         ui->lineEdit_acd1,     ui->lineEdit_acd2,     ui->lineEdit_acd3,
//         ui->lineEdit_acd12,    ui->lineEdit_acd22,    ui->lineEdit_acd32,
//     };
//     for (QLineEdit *le : numericFields)
//         if (le) le->installEventFilter(this);
// }

// bool CalculatorDialog::eventFilter(QObject *obj, QEvent *event)
// {
//     if (event->type() == QEvent::MouseButtonPress) {
//         QLineEdit *le = qobject_cast<QLineEdit*>(obj);
//         if (le) {
//             Numericpad *np = new Numericpad(le, this);
//             np->exec();
//             delete np;
//             calculate();
//             return true;
//         }
//     }
//     return QDialog::eventFilter(obj, event);
// }

// // ═════════════════════════════════════════════════════════════
// //  Clock
// // ═════════════════════════════════════════════════════════════
// void CalculatorDialog::updateTime()
// {
//     if (ui->lbl_time)
//         ui->lbl_time->setText(QTime::currentTime().toString("hh:mm:ss"));
// }

// // ═════════════════════════════════════════════════════════════
// //  Combo slots
// // ═════════════════════════════════════════════════════════════
// void CalculatorDialog::on_comboBox_lensOne_currentIndexChanged(int index)   { loadLensIntoPanel(1, index); }
// void CalculatorDialog::on_comboBox_lensTwo_currentIndexChanged(int index)   { loadLensIntoPanel(2, index); }
// void CalculatorDialog::on_comboBox_lensThree_currentIndexChanged(int index) { loadLensIntoPanel(3, index); }

// // ═════════════════════════════════════════════════════════════
// //  Formula tab buttons — Haigis button does nothing (empty)
// // ═════════════════════════════════════════════════════════════
// void CalculatorDialog::on_btn_srkii_clicked()    { updateFormula(IolFormula::SRKII);    }
// void CalculatorDialog::on_btn_srkt_clicked()     { updateFormula(IolFormula::SRKT);     }
// void CalculatorDialog::on_btn_hofferq_clicked()  { updateFormula(IolFormula::HofferQ);  }
// void CalculatorDialog::on_btn_holladay_clicked() { updateFormula(IolFormula::Holladay); }
// void CalculatorDialog::on_btn_haigis_clicked()   { /* Haigis not implemented */ }

// void CalculatorDialog::updateFormula(IolFormula f)
// {
//     m_formula = f;
//     updateConstantVisibility();
//     calculate();
// }

// // ═════════════════════════════════════════════════════════════
// //  calculate()
// //  FIX: guard against empty K field (dialog opened without
// //       setBiometerValues being called)
// // ═════════════════════════════════════════════════════════════
// void CalculatorDialog::calculate()
// {
//     bool okK = false, okAL = false;
//     double k  = ui->lbl_kValEdit ->text().toDouble(&okK);
//     double al = ui->lbl_alValEdit->text().toDouble(&okAL);

//     if (!okK || !okAL || k <= 0.0 || al <= 0.0) {
//         ui->snackbar->setText("  Enter valid K and AL values to calculate.");
//         // Show --- in all panels so user sees no stale data
//         IolResult empty; empty.valid = false;
//         fillPanel(1, empty);
//         fillPanel(2, empty);
//         fillPanel(3, empty);
//         return;
//     }
//     ui->snackbar->setText("");

//     bool okRx = false;
//     double rx = ui->lbl_rxValEdit->text().toDouble(&okRx);
//     if (!okRx) rx = 0.0;

//     runAndFillPanel(1, k, al, rx);
//     runAndFillPanel(2, k, al, rx);
//     runAndFillPanel(3, k, al, rx);
// }

// // ═════════════════════════════════════════════════════════════
// //  Read lens constants from UI
// //  FIX: warn via snackbar if lens not selected (constant = 0)
// // ═════════════════════════════════════════════════════════════
// LensConstants CalculatorDialog::readLensConstants(int p) const
// {
//     auto dbl = [](QLineEdit *le, double def) -> double {
//         if (!le) return def;
//         bool ok = false;
//         double v = le->text().toDouble(&ok);
//         return (ok && v != 0.0) ? v : def;
//     };

//     LensConstants c;
//     if (p == 1) {
//         c.aConst = dbl(ui->lineEdit_aconst1, 118.4);  // FIX: 118.4 safer default
//         c.sf     = dbl(ui->lineEdit_sf1,       1.36);
//         c.pAcd   = dbl(ui->lineEdit_acd1,      4.97);
//     } else if (p == 2) {
//         c.aConst = dbl(ui->lineEdit_aconst2, 118.4);
//         c.sf     = dbl(ui->lineEdit_sf2,       1.36);
//         c.pAcd   = dbl(ui->lineEdit_acd2,      4.97);
//     } else {
//         c.aConst = dbl(ui->lineEdit_aconst3, 118.4);
//         c.sf     = dbl(ui->lineEdit_sf3,       1.36);
//         c.pAcd   = dbl(ui->lineEdit_acd3,      4.97);
//     }
//     return c;
// }

// // ═════════════════════════════════════════════════════════════
// //  runAndFillPanel — uses IOLCalculator lib for all 4 formulas
// // ═════════════════════════════════════════════════════════════
// void CalculatorDialog::runAndFillPanel(int panelNum, double k, double al, double rx)
// {
//     // Haigis not implemented — clear panel
//     if (m_formula == IolFormula::Haigis) {
//         IolResult empty;
//         empty.valid = false;
//         fillPanel(panelNum, empty);
//         return;
//     }

//     LensConstants c = readLensConstants(panelNum);

//     iol::Input inp;
//     inp.axialLength = al;
//     inp.k           = k;
//     inp.targetRx    = rx;

//     switch (m_formula) {
//     case IolFormula::SRKII:    inp.formula = iol::Formula::SRKII;    break;
//     case IolFormula::SRKT:     inp.formula = iol::Formula::SRKT;     break;
//     case IolFormula::HofferQ:  inp.formula = iol::Formula::HofferQ;  break;
//     case IolFormula::Holladay: inp.formula = iol::Formula::Holladay; break;
//     default: return;
//     }

//     // Each formula uses one constant — map correctly
//     switch (m_formula) {
//     case IolFormula::SRKII:
//     case IolFormula::SRKT:     inp.aConstant = c.aConst; break;  // A-constant
//     case IolFormula::HofferQ:  inp.aConstant = c.pAcd;   break;  // pACD
//     case IolFormula::Holladay: inp.aConstant = c.sf;     break;  // Surgeon Factor
//     default: break;
//     }

//     iol::IOLCalculator calc;
//     iol::Result res = calc.calculate(inp);

//     IolResult result;
//     result.valid = res.valid;
//     if (res.valid) {
//         result.emmPower = res.pEmmetropia;
//         for (int i = 0; i < 5; ++i) {
//             result.iolPower[i] = res.iolPower[i];
//             result.predRx[i]   = res.predictedRx[i];
//         }
//     }

//     fillPanel(panelNum, result);
// }

// // ═════════════════════════════════════════════════════════════
// //  fillPanel
// //  NOTE: cdisp naming must match .ui exactly (cdisp1 not cdisp01)
// //        Panel1: cdisp1–5 (IOL), cdisp6–10 (Ref)
// //        Panel2: cdisp11–15 (IOL), cdisp16–20 (Ref)
// //        Panel3: cdisp21–25 (IOL), cdisp26–30 (Ref)
// // ═════════════════════════════════════════════════════════════
// void CalculatorDialog::fillPanel(int panelNum, const IolResult &r)
// {
//     const int base = (panelNum - 1) * 10;

//     auto iolW = [&](int row) -> QLineEdit* {
//         return findChild<QLineEdit*>(QString("cdisp%1").arg(base + 1 + row));
//     };
//     auto refW = [&](int row) -> QLineEdit* {
//         return findChild<QLineEdit*>(QString("cdisp%1").arg(base + 6 + row));
//     };
//     auto emmLbl = [&]() -> QLabel* {
//         return findChild<QLabel*>(QString("cemm%1").arg(panelNum));
//     };

//     if (!r.valid) {
//         for (int i = 0; i < 5; ++i) {
//             if (auto *w = iolW(i)) w->setText("---");
//             if (auto *w = refW(i)) w->setText("---");
//         }
//         if (auto *l = emmLbl()) l->setText("EMM=---");
//         return;
//     }

//     for (int i = 0; i < 5; ++i) {
//         if (auto *w = iolW(i)) w->setText(QString::number(r.iolPower[i], 'f', 2));
//         if (auto *w = refW(i)) w->setText(QString::number(r.predRx[i],   'f', 2));
//     }
//     if (auto *l = emmLbl())
//         l->setText(QString("EMM=%1").arg(QString::number(r.emmPower, 'f', 2)));
// }

// // ═════════════════════════════════════════════════════════════
// //  Warning / Navigation buttons
// // ═════════════════════════════════════════════════════════════
// void CalculatorDialog::on_btn_warning1_clicked() { PromptDialog p("Info", "Lens 1 — no warning details yet.", this); p.exec(); }
// void CalculatorDialog::on_btn_warning2_clicked() { PromptDialog p("Info", "Lens 2 — no warning details yet.", this); p.exec(); }
// void CalculatorDialog::on_btn_warning3_clicked() { PromptDialog p("Info", "Lens 3 — no warning details yet.", this); p.exec(); }

// void CalculatorDialog::on_btn_home_clicked()
// {
//     HomeScreenDialog homeScreen(m_patientId, m_doctorId, this);
//     homeScreen.exec();
// }

// void CalculatorDialog::on_btn_measure_clicked() { accept(); }

// void CalculatorDialog::on_btn_newPatient_clicked()
// {
//     AddPatientDialog *dlg = new AddPatientDialog(this);
//     dlg->exec();
//     delete dlg;
// }

// void CalculatorDialog::on_btn_print_clicked()
// {
//     PrintDialog *dlg = new PrintDialog(this);
//     dlg->setPatientId(m_patientId);
//     dlg->setDoctorId(m_doctorId);
//     dlg->exec();
//     delete dlg;
// }


// // ═════════════════════════════════════════════════════════════
// //  Show current patient + doctor on the calculator header
// // ═════════════════════════════════════════════════════════════
// void CalculatorDialog::loadPatientHeader()
// {
//     // Patient name + ID
//     if (!m_patientId.isEmpty()) {
//         QSqlQuery q(db);
//         q.prepare("SELECT name FROM patient WHERE patientid = :pid LIMIT 1");
//         q.bindValue(":pid", m_patientId);

//         if (q.exec() && q.next()) {
//             if (ui->lineEdit_patName) ui->lineEdit_patName->setText(q.value(0).toString());
//         } else {
//             if (ui->lineEdit_patName) ui->lineEdit_patName->setText("");
//             qDebug() << "loadPatientHeader: patient lookup failed for" << m_patientId
//                      << q.lastError().text();
//         }
//         if (ui->lineEdit_patID) ui->lineEdit_patID->setText(m_patientId);
//     } else {
//         if (ui->lineEdit_patName) ui->lineEdit_patName->setText("");
//         if (ui->lineEdit_patID)   ui->lineEdit_patID->setText("");
//     }

//     // Doctor name
//     if (!m_doctorId.isEmpty()) {
//         QSqlQuery q(db);
//         q.prepare("SELECT name FROM doctor WHERE doctorid = :did LIMIT 1");
//         q.bindValue(":did", m_doctorId);

//         if (q.exec() && q.next()) {
//             if (ui->lineEdit_docName) ui->lineEdit_docName->setText(q.value(0).toString());
//         } else {
//             if (ui->lineEdit_docName) ui->lineEdit_docName->setText("");
//             qDebug() << "loadPatientHeader: doctor lookup failed for" << m_doctorId
//                      << q.lastError().text();
//         }
//     } else {
//         if (ui->lineEdit_docName) ui->lineEdit_docName->setText("");
//     }
// }

// // ═════════════════════════════════════════════════════════════
// //  Auto-select lenses based on doctor's saved presets
// // ═════════════════════════════════════════════════════════════
// void CalculatorDialog::loadDoctorLensPresets()
// {
//     if (m_doctorId.isEmpty()) return;

//     QSqlQuery q(db);
//     q.prepare("SELECT lenspresetone, lenspresettwo, lenspresetthree "
//               "FROM doctor WHERE doctorid = :did LIMIT 1");
//     q.bindValue(":did", m_doctorId);

//     if (!q.exec() || !q.next()) {
//         qDebug() << "loadDoctorLensPresets: no row for" << m_doctorId
//                  << q.lastError().text();
//         return;
//     }

//     selectLensInCombo(ui->comboBox_lensOne,   q.value(0).toString());
//     selectLensInCombo(ui->comboBox_lensTwo,   q.value(1).toString());
//     selectLensInCombo(ui->comboBox_lensThree, q.value(2).toString());
// }

// void CalculatorDialog::selectLensInCombo(QComboBox *cb, const QString &preset)
// {
//     if (!cb || preset.isEmpty()) return;

//     int idx = -1;

//     // Try as rowid first (in case preset stores the lens id)
//     bool isNum = false;
//     int rowid = preset.toInt(&isNum);
//     if (isNum)
//         idx = cb->findData(rowid);

//     // Fall back to matching by IOL name (combo text is "iol  (company)")
//     if (idx < 0) {
//         for (int i = 1; i < cb->count(); ++i) {   // skip "-- Select Lens --"
//             if (cb->itemText(i).startsWith(preset, Qt::CaseInsensitive)) {
//                 idx = i;
//                 break;
//             }
//         }
//     }

//     if (idx >= 0)
//         cb->setCurrentIndex(idx);   // fires currentIndexChanged -> loadLensIntoPanel -> calculate()
//     else
//         qDebug() << "selectLensInCombo: no match for preset" << preset;
// }



#include "calculatordialog.h"
#include "ui_calculatordialog.h"
#include "printdialog.h"
#include "addpatientdialog.h"
#include "promptdialog.h"
#include "homescreendialog.h"
#include "IOLCalculator.h"
#include "AppManager.h"

#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <cmath>
#include <limits>

// ═════════════════════════════════════════════════════════════
//  Constructor / Destructor
// ═════════════════════════════════════════════════════════════
// CalculatorDialog::CalculatorDialog(QWidget *parent)
//     : QDialog(parent)
//     , ui(new Ui::CalculatorDialog)
//     , clockTimer(new QTimer(this))
// {
//     ui->setupUi(this);
//     setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

//     updateEyeButtonText();   // keep btn_eye text in sync with m_eye on open

//     if (!openDatabase())
//         qDebug() << "CalculatorDialog: Failed to open database!";

//     connect(clockTimer, &QTimer::timeout, this, &CalculatorDialog::updateTime);
//     clockTimer->start(1000);
//     updateTime();

//     populateAllCombos();
//     installEventFilters();

//     connect(ui->lbl_alValEdit,    &QLineEdit::editingFinished, this, &CalculatorDialog::calculate);
//     connect(ui->lbl_rxValEdit,    &QLineEdit::editingFinished, this, &CalculatorDialog::calculate);
//     connect(ui->lineEdit_aconst1, &QLineEdit::editingFinished, this, &CalculatorDialog::calculate);
//     connect(ui->lineEdit_aconst2, &QLineEdit::editingFinished, this, &CalculatorDialog::calculate);
//     connect(ui->lineEdit_aconst3, &QLineEdit::editingFinished, this, &CalculatorDialog::calculate);

//     m_formula = IolFormula::SRKII;
//     updateConstantVisibility();
//     calculate();
// }

CalculatorDialog::~CalculatorDialog() { delete ui; }

// // ═════════════════════════════════════════════════════════════
// //  Public setters
// // ═════════════════════════════════════════════════════════════
// void CalculatorDialog::setPatientId(const QString &id)
// {
//     m_patientId = id;
//     loadPatientHeader();
// }

// void CalculatorDialog::setDoctorId(const QString &id)
// {
//     m_doctorId = id;
//     loadPatientHeader();
//     loadDoctorLensPresets();
//     loadBiometerForEye();   // both ids are set by now — safe to query
// }


// ═════════════════════════════════════════════════════════════
//  Constructor / Destructor
// ═════════════════════════════════════════════════════════════
CalculatorDialog::CalculatorDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CalculatorDialog)
    , clockTimer(new QTimer(this))
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    if (!openDatabase())
        qDebug() << "CalculatorDialog: Failed to open database!";

    connect(clockTimer, &QTimer::timeout, this, &CalculatorDialog::updateTime);
    clockTimer->start(1000);
    updateTime();

    populateAllCombos();
    installEventFilters();

    connect(ui->lbl_alValEdit,    &QLineEdit::editingFinished, this, &CalculatorDialog::calculate);
    connect(ui->lbl_rxValEdit,    &QLineEdit::editingFinished, this, &CalculatorDialog::calculate);
    connect(ui->lineEdit_aconst1, &QLineEdit::editingFinished, this, &CalculatorDialog::calculate);
    connect(ui->lineEdit_aconst2, &QLineEdit::editingFinished, this, &CalculatorDialog::calculate);
    connect(ui->lineEdit_aconst3, &QLineEdit::editingFinished, this, &CalculatorDialog::calculate);

    m_formula = IolFormula::SRKII;
    updateConstantVisibility();
    updateEyeButtonText();

    // ── DO NOT call calculate() or loadBiometerForEye() here ──
    // Those run after setPatientId() + setDoctorId() are both set.
    // Show --- in panels until real data arrives.
    IolResult empty;
    fillPanel(1, empty);
    fillPanel(2, empty);
    fillPanel(3, empty);
}

// ═════════════════════════════════════════════════════════════
//  Public setters  — order: caller sets patientId first,
//  then doctorId. setDoctorId triggers the full data load.
// ═════════════════════════════════════════════════════════════
void CalculatorDialog::setPatientId(const QString &id)
{
    m_patientId = id;
    // Don't load yet — wait until doctorId is also set
}

void CalculatorDialog::setDoctorId(const QString &id)
{
    m_doctorId = id;
    // Both IDs are available now — run the full init sequence
    loadPatientHeader();
    loadDoctorLensPresets();   // fires currentIndexChanged → loadLensIntoPanel → calculate()
    loadBiometerForEye();      // loads K1/K2/AL, calls setBiometerValues → calculate()
}

void CalculatorDialog::setBiometerValues(double k1, double k2, double k, double al, double rx)
{
    // Set both duplicate widgets to be safe
    if (ui->lbl_k1ValEdit)  ui->lbl_k1ValEdit ->setText(QString::number(k1, 'f', 2));
    if (ui->lbl_k1ValEdit1) ui->lbl_k1ValEdit1->setText(QString::number(k1, 'f', 2));
    if (ui->lbl_k2ValEdit)  ui->lbl_k2ValEdit ->setText(QString::number(k2, 'f', 2));
    if (ui->lbl_k2ValEdit2) ui->lbl_k2ValEdit2->setText(QString::number(k2, 'f', 2));
    if (ui->lbl_kValEdit)   ui->lbl_kValEdit  ->setText(QString::number(k,  'f', 2));
    if (ui->lbl_kValEdit2)  ui->lbl_kValEdit2 ->setText(QString::number(k,  'f', 2));
    if (ui->lbl_alValEdit)  ui->lbl_alValEdit ->setText(QString::number(al, 'f', 2));
    if (ui->lbl_alValEdit2) ui->lbl_alValEdit2->setText(QString::number(al, 'f', 2));
    if (ui->lbl_rxValEdit)  ui->lbl_rxValEdit ->setText(QString::number(rx, 'f', 2));
    if (ui->lbl_rxValEdit2) ui->lbl_rxValEdit2->setText(QString::number(rx, 'f', 2));
    calculate();
}


// ═════════════════════════════════════════════════════════════
//  Header — show current patient name/ID + doctor name
// ═════════════════════════════════════════════════════════════
void CalculatorDialog::loadPatientHeader()
{
    // Patient name + ID
    if (!m_patientId.isEmpty()) {
        QSqlQuery q(db);
        q.prepare("SELECT name FROM patient WHERE patientid = :pid LIMIT 1");
        q.bindValue(":pid", m_patientId);

        if (q.exec() && q.next()) {
            if (ui->lineEdit_patName) ui->lineEdit_patName->setText(q.value(0).toString());
        } else {
            if (ui->lineEdit_patName) ui->lineEdit_patName->setText("");
            qDebug() << "loadPatientHeader: patient lookup failed for" << m_patientId
                     << q.lastError().text();
        }
        if (ui->lineEdit_patID) ui->lineEdit_patID->setText(m_patientId);
    } else {
        if (ui->lineEdit_patName) ui->lineEdit_patName->setText("");
        if (ui->lineEdit_patID)   ui->lineEdit_patID->setText("");
    }

    // Doctor name
    if (!m_doctorId.isEmpty()) {
        QSqlQuery q(db);
        q.prepare("SELECT name FROM doctor WHERE doctorid = :did LIMIT 1");
        q.bindValue(":did", m_doctorId);

        if (q.exec() && q.next()) {
            if (ui->lineEdit_docName) ui->lineEdit_docName->setText(q.value(0).toString());
        } else {
            if (ui->lineEdit_docName) ui->lineEdit_docName->setText("");
            qDebug() << "loadPatientHeader: doctor lookup failed for" << m_doctorId
                     << q.lastError().text();
        }
    } else {
        if (ui->lineEdit_docName) ui->lineEdit_docName->setText("");
    }
}

// ═════════════════════════════════════════════════════════════
//  Auto-select lenses based on doctor's saved presets
//  Never leaves a panel on the blank "-- Select Lens --" placeholder:
//  falls back to the first real lens if no preset is saved / matched.
// ═════════════════════════════════════════════════════════════
void CalculatorDialog::loadDoctorLensPresets()
{
    if (m_doctorId.isEmpty()) return;

    QSqlQuery q(db);
    q.prepare("SELECT lenspresetone, lenspresettwo, lenspresetthree "
              "FROM doctor WHERE doctorid = :did LIMIT 1");
    q.bindValue(":did", m_doctorId);

    QString preset1, preset2, preset3;
    if (q.exec() && q.next()) {
        preset1 = q.value(0).toString();
        preset2 = q.value(1).toString();
        preset3 = q.value(2).toString();
    } else {
        qDebug() << "loadDoctorLensPresets: no row for" << m_doctorId << q.lastError().text();
    }

    selectLensInCombo(ui->comboBox_lensOne,   preset1);
    selectLensInCombo(ui->comboBox_lensTwo,   preset2);
    selectLensInCombo(ui->comboBox_lensThree, preset3);
}

void CalculatorDialog::selectLensInCombo(QComboBox *cb, const QString &preset)
{
    if (!cb) return;

    int idx = -1;

    if (!preset.isEmpty()) {
        // Try as rowid first (in case preset stores the lens id)
        bool isNum = false;
        int rowid = preset.toInt(&isNum);
        if (isNum)
            idx = cb->findData(rowid);

        // Fall back to matching by IOL name (combo text is "iol  (company)")
        if (idx < 0) {
            for (int i = 1; i < cb->count(); ++i) {   // skip "-- Select Lens --"
                if (cb->itemText(i).startsWith(preset, Qt::CaseInsensitive)) {
                    idx = i;
                    break;
                }
            }
        }
    }

    // No preset saved, or no match found — still never leave it on the
    // blank placeholder. Default to the first real lens; user can change it.
    if (idx < 0 && cb->count() > 1)
        idx = 1;

    if (idx >= 0)
        cb->setCurrentIndex(idx);   // fires currentIndexChanged -> loadLensIntoPanel -> calculate()
}

// ═════════════════════════════════════════════════════════════
//  Eye toggle (OS/OD)
// ═════════════════════════════════════════════════════════════
void CalculatorDialog::on_btn_eye_clicked()
{
    m_eye = (m_eye == 1) ? 0 : 1;   // flip: 1 = OD, 0 = OS
    updateEyeButtonText();
    loadBiometerForEye();
}

void CalculatorDialog::updateEyeButtonText()
{
    if (ui->btn_eye)
        ui->btn_eye->setText(m_eye == 1 ? "OD" : "OS");
}

// void CalculatorDialog::loadBiometerForEye()
// {
//     if (m_patientId.isEmpty()) return;

//     double k1 = 0.0, k2 = 0.0, al = 0.0;

//     // K1/K2 live on the patient row — right eye (rk1/rk2) or left eye (lk1/lk2)
//     QSqlQuery pq(db);
//     pq.prepare(m_eye == 1
//                    ? "SELECT rk1, rk2 FROM patient WHERE patientid = :pid LIMIT 1"
//                    : "SELECT lk1, lk2 FROM patient WHERE patientid = :pid LIMIT 1");
//     pq.bindValue(":pid", m_patientId);
//     if (pq.exec() && pq.next()) {
//         k1 = pq.value(0).toDouble();
//         k2 = pq.value(1).toDouble();
//     } else {
//         qDebug() << "loadBiometerForEye: patient K lookup failed" << pq.lastError().text();
//     }

//     // AL comes from the most recent reading for this patient/doctor/eye
//     QSqlQuery rq(db);
//     rq.prepare("SELECT al FROM reading "
//                "WHERE patientid = :pid AND doctorid = :did AND rleye = :eye "
//                "ORDER BY id DESC LIMIT 1");
//     rq.bindValue(":pid", m_patientId);
//     rq.bindValue(":did", m_doctorId);
//     rq.bindValue(":eye", m_eye);
//     if (rq.exec() && rq.next()) {
//         al = rq.value(0).toDouble();
//     } else {
//         qDebug() << "loadBiometerForEye: reading lookup failed" << rq.lastError().text();
//     }

//     setBiometerValues(k1, k2, al, 0.0);   // Rx resets to 0.00 on eye switch
// }

void CalculatorDialog::loadBiometerForEye()
{
    if (m_patientId.isEmpty()) return;

    double k1 = 0.0, k2 = 0.0, k = 0.0, al = 0.0;

    // ── K1, K2, K from patient table ─────────────────────────
    QSqlQuery pq(db);
    if (m_eye == 1)
        pq.prepare("SELECT rk1, rk2, rk FROM patient WHERE patientid = :pid LIMIT 1");
    else
        pq.prepare("SELECT lk1, lk2, lk FROM patient WHERE patientid = :pid LIMIT 1");

    pq.bindValue(":pid", m_patientId);

    if (pq.exec() && pq.next()) {
        k1 = pq.value(0).toDouble();
        k2 = pq.value(1).toDouble();
        k  = pq.value(2).toDouble();
        // fallback: if rk/lk not stored, compute from k1/k2
        if (k <= 0.0 && (k1 > 0.0 || k2 > 0.0))
            k = (k1 + k2) / 2.0;
    } else {
        qDebug() << "loadBiometerForEye: patient K lookup failed" << pq.lastError().text();
    }

    // ── AL from aval (average AL) of most recent reading ─────
    QSqlQuery rq(db);
    rq.prepare(R"(
        SELECT aval FROM reading
        WHERE  patientid  = :pid
          AND  doctorid   = :did
          AND  rleye      = :eye
          AND  aval       > 0
        ORDER  BY id DESC
        LIMIT  1
    )");
    rq.bindValue(":pid", m_patientId);
    rq.bindValue(":did", m_doctorId);
    rq.bindValue(":eye", m_eye);

    if (rq.exec() && rq.next()) {
        al = rq.value(0).toDouble();
    } else {
        qDebug() << "loadBiometerForEye: no aval reading for eye=" << m_eye;
    }

    setBiometerValues(k1, k2, k, al, 0.0);
}

// ═════════════════════════════════════════════════════════════
//  Database
// ═════════════════════════════════════════════════════════════
bool CalculatorDialog::openDatabase()
{
    const QString conn = "calculator_conn";
    db = QSqlDatabase::contains(conn)
             ? QSqlDatabase::database(conn)
             : QSqlDatabase::database();
    if (!db.open()) {
        qDebug() << "DB Error:" << db.lastError().text();
        return false;
    }
    return true;
}

// ═════════════════════════════════════════════════════════════
//  Populate lens combo boxes
// ═════════════════════════════════════════════════════════════
void CalculatorDialog::populateAllCombos()
{
    populateCombo(ui->comboBox_lensOne);
    populateCombo(ui->comboBox_lensTwo);
    populateCombo(ui->comboBox_lensThree);
}

void CalculatorDialog::populateCombo(QComboBox *cb)
{
    if (!cb) return;
    cb->blockSignals(true);
    cb->clear();
    cb->addItem("-- Select Lens --", -1);

    QSqlQuery q(db);
    if (q.exec("SELECT rowid, iol, company FROM lens ORDER BY iol ASC")) {
        while (q.next()) {
            int     rowid   = q.value(0).toInt();
            QString iol     = q.value(1).toString();
            QString company = q.value(2).toString();
            QString label   = company.isEmpty() ? iol : QString("%1  (%2)").arg(iol, company);
            cb->addItem(label, rowid);
        }
    } else {
        qDebug() << "Combo query error:" << q.lastError().text();
    }
    cb->blockSignals(false);
}

// ═════════════════════════════════════════════════════════════
//  Load lens constants into panel
//  FIX: all 3 Haigis constants (a0, a1, a2) now read correctly
// ═════════════════════════════════════════════════════════════
void CalculatorDialog::loadLensIntoPanel(int panelNum, int comboIndex)
{
    QComboBox *cb = nullptr;
    if      (panelNum == 1) cb = ui->comboBox_lensOne;
    else if (panelNum == 2) cb = ui->comboBox_lensTwo;
    else                    cb = ui->comboBox_lensThree;

    if (!cb) return;

    int rowid = cb->itemData(comboIndex).toInt();
    if (rowid < 0) return;  // "-- Select Lens --" selected, nothing to load

    QSqlQuery q(db);
    q.prepare("SELECT asrkt, asrkii, acd, sf, a0, a1, a2 "
              "FROM lens WHERE rowid = :id");
    q.bindValue(":id", rowid);

    if (!q.exec() || !q.next()) {
        qDebug() << "Lens load error:" << q.lastError().text();
        return;
    }

    double asrkt  = q.value(0).toDouble();
    double asrkii = q.value(1).toDouble();
    double acd    = q.value(2).toDouble();
    double sf     = q.value(3).toDouble();
    double a0     = q.value(4).toDouble();  // Haigis a0
    double a1     = q.value(5).toDouble();  // Haigis a1
    double a2     = q.value(6).toDouble();  // Haigis a2 — FIX: was never read before

    auto set = [](QLineEdit *le, double v) {
        if (le) le->setText(QString::number(v, 'f', 4));
    };

    if (panelNum == 1) {
        set(ui->lineEdit_aconst1,  asrkii);  // SRK II A-constant
        set(ui->lineEdit_aconst12, asrkt);   // SRK/T A-constant
        set(ui->lineEdit_acd1,     acd);
        set(ui->lineEdit_acd12,    acd);
        set(ui->lineEdit_sf1,      sf);
        set(ui->lineEdit_sf12,     sf);
        set(ui->lineEdit_A0,       a0);      // Haigis a0
        set(ui->lineEdit_A02,      a1);      // Haigis a1  (widget named A02)
        // Note: a2 maps to a3rd Haigis widget if you add one later
        Q_UNUSED(a2);
    } else if (panelNum == 2) {
        set(ui->lineEdit_aconst2,  asrkii);
        set(ui->lineEdit_aconst22, asrkt);
        set(ui->lineEdit_acd2,     acd);
        set(ui->lineEdit_acd22,    acd);
        set(ui->lineEdit_sf2,      sf);
        set(ui->lineEdit_sf22,     sf);
        set(ui->lineEdit_A1,       a0);
        set(ui->lineEdit_A12,      a1);
        Q_UNUSED(a2);
    } else {
        set(ui->lineEdit_aconst3,  asrkii);
        set(ui->lineEdit_aconst32, asrkt);
        set(ui->lineEdit_acd3,     acd);
        set(ui->lineEdit_acd32,    acd);
        set(ui->lineEdit_sf3,      sf);
        set(ui->lineEdit_sf32,     sf);
        set(ui->lineEdit_A2,       a0);
        set(ui->lineEdit_A22,      a1);
        Q_UNUSED(a2);
    }

    calculate();
}

// ═════════════════════════════════════════════════════════════
//  Constant visibility
//  FIX: Panel 3 label visibility was completely missing
// ═════════════════════════════════════════════════════════════
void CalculatorDialog::updateConstantVisibility()
{
    bool showAconst = (m_formula == IolFormula::SRKII || m_formula == IolFormula::SRKT);
    bool showSF     = (m_formula == IolFormula::Holladay);
    bool showAcd    = (m_formula == IolFormula::HofferQ);

    // ── Panel 1 ──────────────────────────────────────────────
    if (ui->lbl_aconst1)       ui->lbl_aconst1      ->setVisible(showAconst);
    if (ui->lbl_sf1)           ui->lbl_sf1           ->setVisible(showSF);
    if (ui->lbl_acd1)          ui->lbl_acd1          ->setVisible(showAcd);
    if (ui->lbl_a0)            ui->lbl_a0            ->setVisible(false);   // Haigis — always hidden

    if (ui->lineEdit_aconst1)  ui->lineEdit_aconst1  ->setVisible(showAconst);
    if (ui->lineEdit_aconst12) ui->lineEdit_aconst12 ->setVisible(false);
    if (ui->lineEdit_sf1)      ui->lineEdit_sf1      ->setVisible(showSF);
    if (ui->lineEdit_sf12)     ui->lineEdit_sf12     ->setVisible(false);
    if (ui->lineEdit_acd1)     ui->lineEdit_acd1     ->setVisible(showAcd);
    if (ui->lineEdit_acd12)    ui->lineEdit_acd12    ->setVisible(false);
    if (ui->lineEdit_A0)       ui->lineEdit_A0       ->setVisible(false);   // Haigis
    if (ui->lineEdit_A02)      ui->lineEdit_A02      ->setVisible(false);   // Haigis

    // ── Panel 2 ──────────────────────────────────────────────
    if (ui->lbl_aconst2)       ui->lbl_aconst2       ->setVisible(showAconst);
    if (ui->lbl_sf2)           ui->lbl_sf2           ->setVisible(showSF);   // FIX: was missing
    if (ui->lbl_acd2)          ui->lbl_acd2          ->setVisible(showAcd);  // FIX: was missing

    if (ui->lineEdit_aconst2)  ui->lineEdit_aconst2  ->setVisible(showAconst);
    if (ui->lineEdit_aconst22) ui->lineEdit_aconst22 ->setVisible(false);
    if (ui->lineEdit_sf2)      ui->lineEdit_sf2      ->setVisible(showSF);
    if (ui->lineEdit_sf22)     ui->lineEdit_sf22     ->setVisible(false);
    if (ui->lineEdit_acd2)     ui->lineEdit_acd2     ->setVisible(showAcd);
    if (ui->lineEdit_acd22)    ui->lineEdit_acd22    ->setVisible(false);
    if (ui->lineEdit_A1)       ui->lineEdit_A1       ->setVisible(false);    // Haigis
    if (ui->lineEdit_A12)      ui->lineEdit_A12      ->setVisible(false);    // Haigis

    // ── Panel 3 ── FIX: labels were never toggled before ─────
    if (ui->lbl_aconst3)       ui->lbl_aconst3       ->setVisible(showAconst);
    if (ui->lbl_sf3)           ui->lbl_sf3           ->setVisible(showSF);
    if (ui->lbl_acd3)          ui->lbl_acd3          ->setVisible(showAcd);

    if (ui->lineEdit_aconst3)  ui->lineEdit_aconst3  ->setVisible(showAconst);
    if (ui->lineEdit_aconst32) ui->lineEdit_aconst32 ->setVisible(false);
    if (ui->lineEdit_sf3)      ui->lineEdit_sf3      ->setVisible(showSF);
    if (ui->lineEdit_sf32)     ui->lineEdit_sf32     ->setVisible(false);
    if (ui->lineEdit_acd3)     ui->lineEdit_acd3     ->setVisible(showAcd);
    if (ui->lineEdit_acd32)    ui->lineEdit_acd32    ->setVisible(false);
    if (ui->lineEdit_A2)       ui->lineEdit_A2       ->setVisible(false);    // Haigis
    if (ui->lineEdit_A22)      ui->lineEdit_A22      ->setVisible(false);    // Haigis
}

// ═════════════════════════════════════════════════════════════
//  Event filter / Numericpad
// ═════════════════════════════════════════════════════════════
void CalculatorDialog::installEventFilters()
{
    const QList<QLineEdit*> numericFields = {
        ui->lbl_alValEdit,
        ui->lbl_rxValEdit,
        ui->lineEdit_aconst1,  ui->lineEdit_aconst2,  ui->lineEdit_aconst3,
        ui->lineEdit_aconst12, ui->lineEdit_aconst22, ui->lineEdit_aconst32,
        ui->lineEdit_sf1,      ui->lineEdit_sf2,      ui->lineEdit_sf3,
        ui->lineEdit_sf12,     ui->lineEdit_sf22,     ui->lineEdit_sf32,
        ui->lineEdit_acd1,     ui->lineEdit_acd2,     ui->lineEdit_acd3,
        ui->lineEdit_acd12,    ui->lineEdit_acd22,    ui->lineEdit_acd32,
    };
    for (QLineEdit *le : numericFields)
        if (le) le->installEventFilter(this);
}

bool CalculatorDialog::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QLineEdit *le = qobject_cast<QLineEdit*>(obj);
        if (le) {
            Numericpad *np = new Numericpad(le, this);
            np->exec();
            delete np;
            calculate();
            return true;
        }
    }
    return QDialog::eventFilter(obj, event);
}

// ═════════════════════════════════════════════════════════════
//  Clock
// ═════════════════════════════════════════════════════════════
void CalculatorDialog::updateTime()
{
    if (ui->lbl_time)
        ui->lbl_time->setText(QTime::currentTime().toString("hh:mm:ss"));
}

// ═════════════════════════════════════════════════════════════
//  Combo slots
// ═════════════════════════════════════════════════════════════
void CalculatorDialog::on_comboBox_lensOne_currentIndexChanged(int index)   { loadLensIntoPanel(1, index); }
void CalculatorDialog::on_comboBox_lensTwo_currentIndexChanged(int index)   { loadLensIntoPanel(2, index); }
void CalculatorDialog::on_comboBox_lensThree_currentIndexChanged(int index) { loadLensIntoPanel(3, index); }

// ═════════════════════════════════════════════════════════════
//  Formula tab buttons — Haigis button does nothing (empty)
// ═════════════════════════════════════════════════════════════
void CalculatorDialog::on_btn_srkii_clicked()    {
    updateFormula(IolFormula::SRKII);

    updateFormulaButtonStyle(ui->btn_srkii);
}
void CalculatorDialog::on_btn_srkt_clicked()     {
    updateFormula(IolFormula::SRKT);
    updateFormulaButtonStyle(ui->btn_srkt);
}
void CalculatorDialog::on_btn_hofferq_clicked()  {

    updateFormula(IolFormula::HofferQ);

    updateFormulaButtonStyle(ui->btn_hofferq);
}
void CalculatorDialog::on_btn_holladay_clicked() {

    updateFormula(IolFormula::Holladay);

    updateFormulaButtonStyle(ui->btn_holladay);

}
void CalculatorDialog::on_btn_haigis_clicked()   { /* Haigis not implemented */ }

void CalculatorDialog::updateFormula(IolFormula f)
{
    m_formula = f;
    updateConstantVisibility();
    calculate();
}

void CalculatorDialog::updateFormulaButtonStyle(QPushButton *selectedButton)
{
    const QString normalStyle =
        "border-radius:5px;"
        "background-color: rgb(255,255,255);"
        "color: rgb(0,0,0);"
        "background-image:url(:/images/empty.png);";

    const QString selectedStyle =
        "border-radius:5px;"
        "background-color: rgb(244,67,54);"
        "color: rgb(255,255,255);"
        "background-image:url(:/images/empty.png);";

    QList<QPushButton*> buttons = {
        ui->btn_srkii,
        ui->btn_srkt,
        ui->btn_hofferq,
        ui->btn_holladay,
        ui->btn_haigis       // Include if you want this to reset too
    };

    // Reset all buttons to white
    for (QPushButton *btn : buttons)
        btn->setStyleSheet(normalStyle);

    // Highlight only the selected button
    if (selectedButton)
        selectedButton->setStyleSheet(selectedStyle);
}

// ═════════════════════════════════════════════════════════════
//  calculate()
//  FIX: guard against empty K field (dialog opened without
//       setBiometerValues being called)
// ═════════════════════════════════════════════════════════════
void CalculatorDialog::calculate()
{
    bool okK = false, okAL = false;
    double k  = ui->lbl_kValEdit ->text().toDouble(&okK);
    double al = ui->lbl_alValEdit->text().toDouble(&okAL);

    if (!okK || !okAL || k <= 0.0 || al <= 0.0) {
        ui->snackbar->setText("  Enter valid K and AL values to calculate.");
        // Show --- in all panels so user sees no stale data
        IolResult empty; empty.valid = false;
        fillPanel(1, empty);
        fillPanel(2, empty);
        fillPanel(3, empty);
        return;
    }
    ui->snackbar->setText("");

    bool okRx = false;
    double rx = ui->lbl_rxValEdit->text().toDouble(&okRx);
    if (!okRx) rx = 0.0;

    runAndFillPanel(1, k, al, rx);
    runAndFillPanel(2, k, al, rx);
    runAndFillPanel(3, k, al, rx);
}

// ═════════════════════════════════════════════════════════════
//  Read lens constants from UI
//  FIX: warn via snackbar if lens not selected (constant = 0)
// ═════════════════════════════════════════════════════════════
LensConstants CalculatorDialog::readLensConstants(int p) const
{
    auto dbl = [](QLineEdit *le, double def) -> double {
        if (!le) return def;
        bool ok = false;
        double v = le->text().toDouble(&ok);
        return (ok && v != 0.0) ? v : def;
    };

    LensConstants c;
    if (p == 1) {
        c.aConst = dbl(ui->lineEdit_aconst1, 118.4);  // FIX: 118.4 safer default
        c.sf     = dbl(ui->lineEdit_sf1,       1.36);
        c.pAcd   = dbl(ui->lineEdit_acd1,      4.97);
    } else if (p == 2) {
        c.aConst = dbl(ui->lineEdit_aconst2, 118.4);
        c.sf     = dbl(ui->lineEdit_sf2,       1.36);
        c.pAcd   = dbl(ui->lineEdit_acd2,      4.97);
    } else {
        c.aConst = dbl(ui->lineEdit_aconst3, 118.4);
        c.sf     = dbl(ui->lineEdit_sf3,       1.36);
        c.pAcd   = dbl(ui->lineEdit_acd3,      4.97);
    }
    return c;
}

// ═════════════════════════════════════════════════════════════
//  runAndFillPanel — uses IOLCalculator lib for all 4 formulas
// ═════════════════════════════════════════════════════════════
void CalculatorDialog::runAndFillPanel(int panelNum, double k, double al, double rx)
{
    // Haigis not implemented — clear panel
    if (m_formula == IolFormula::Haigis) {
        IolResult empty;
        empty.valid = false;
        fillPanel(panelNum, empty);
        return;
    }

    LensConstants c = readLensConstants(panelNum);

    iol::Input inp;
    inp.axialLength = al;
    inp.k           = k;
    inp.targetRx    = rx;

    switch (m_formula) {
    case IolFormula::SRKII:    inp.formula = iol::Formula::SRKII;    break;
    case IolFormula::SRKT:     inp.formula = iol::Formula::SRKT;     break;
    case IolFormula::HofferQ:  inp.formula = iol::Formula::HofferQ;  break;
    case IolFormula::Holladay: inp.formula = iol::Formula::Holladay; break;
    default: return;
    }

    // Each formula uses one constant — map correctly
    switch (m_formula) {
    case IolFormula::SRKII:
    case IolFormula::SRKT:     inp.aConstant = c.aConst; break;  // A-constant
    case IolFormula::HofferQ:  inp.aConstant = c.pAcd;   break;  // pACD
    case IolFormula::Holladay: inp.aConstant = c.sf;     break;  // Surgeon Factor
    default: break;
    }

    iol::IOLCalculator calc;
    iol::Result res = calc.calculate(inp);

    IolResult result;
    result.valid = res.valid;
    if (res.valid) {
        result.emmPower = res.pEmmetropia;
        for (int i = 0; i < 5; ++i) {
            result.iolPower[i] = res.iolPower[i];
            result.predRx[i]   = res.predictedRx[i];
        }
    }

    fillPanel(panelNum, result);
}

// ═════════════════════════════════════════════════════════════
//  fillPanel
//  NOTE: cdisp naming must match .ui exactly (cdisp1 not cdisp01)
//        Panel1: cdisp1–5 (IOL), cdisp6–10 (Ref)
//        Panel2: cdisp11–15 (IOL), cdisp16–20 (Ref)
//        Panel3: cdisp21–25 (IOL), cdisp26–30 (Ref)
// ═════════════════════════════════════════════════════════════
void CalculatorDialog::fillPanel(int panelNum, const IolResult &r)
{
    const int base = (panelNum - 1) * 10;

    auto iolW = [&](int row) -> QLineEdit* {
        return findChild<QLineEdit*>(QString("cdisp%1").arg(base + 1 + row));
    };
    auto refW = [&](int row) -> QLineEdit* {
        return findChild<QLineEdit*>(QString("cdisp%1").arg(base + 6 + row));
    };
    auto emmLbl = [&]() -> QLabel* {
        return findChild<QLabel*>(QString("cemm%1").arg(panelNum));
    };

    if (!r.valid) {
        for (int i = 0; i < 5; ++i) {
            if (auto *w = iolW(i)) w->setText("---");
            if (auto *w = refW(i)) w->setText("---");
        }
        if (auto *l = emmLbl()) l->setText("EMM=---");
        return;
    }

    for (int i = 0; i < 5; ++i) {
        if (auto *w = iolW(i)) w->setText(QString::number(r.iolPower[i], 'f', 2));
        if (auto *w = refW(i)) w->setText(QString::number(r.predRx[i],   'f', 2));
    }
    if (auto *l = emmLbl())
        l->setText(QString("EMM=%1").arg(QString::number(r.emmPower, 'f', 2)));
}

// ═════════════════════════════════════════════════════════════
//  Warning / Navigation buttons
// ═════════════════════════════════════════════════════════════
void CalculatorDialog::on_btn_warning1_clicked() { PromptDialog p("Info", "Lens 1 — no warning details yet.", this); p.exec(); }
void CalculatorDialog::on_btn_warning2_clicked() { PromptDialog p("Info", "Lens 2 — no warning details yet.", this); p.exec(); }
void CalculatorDialog::on_btn_warning3_clicked() { PromptDialog p("Info", "Lens 3 — no warning details yet.", this); p.exec(); }

void CalculatorDialog::on_btn_home_clicked()
{
    AppManager::home->loadContext(m_patientId, m_doctorId);
    this->hide();
    AppManager::home->show();
}

void CalculatorDialog::on_btn_measure_clicked()
{
    this->hide();
    AppManager::measure->show();
}

void CalculatorDialog::on_btn_newPatient_clicked()
{
    AddPatientDialog *dlg = new AddPatientDialog(this);
    dlg->exec();
    delete dlg;
}

void CalculatorDialog::on_btn_print_clicked()
{
    AppManager::print->setPatientId(m_patientId);
    AppManager::print->setDoctorId(m_doctorId);

    AppManager::print->setPreviousPage(PrintDialog::CalculatorPage);

    PrintDialog::CalcContext ctx;
    ctx.eye = m_eye;

    switch (m_formula) {
    case IolFormula::SRKII:    ctx.formulaIndex = 0; break;
    case IolFormula::SRKT:     ctx.formulaIndex = 1; break;
    case IolFormula::HofferQ:  ctx.formulaIndex = 2; break;
    case IolFormula::Holladay: ctx.formulaIndex = 3; break;
    default:                   ctx.formulaIndex = 0; break;
    }

    ctx.lensRowidOne   = ui->comboBox_lensOne->currentData(Qt::UserRole).toInt();
    ctx.lensRowidTwo   = ui->comboBox_lensTwo->currentData(Qt::UserRole).toInt();
    ctx.lensRowidThree = ui->comboBox_lensThree->currentData(Qt::UserRole).toInt();

    AppManager::print->setCalcContext(ctx);

    this->hide();
    AppManager::print->show();
}
