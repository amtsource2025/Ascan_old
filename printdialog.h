

#ifndef PRINTDIALOG_H
#define PRINTDIALOG_H

#include <QDialog>
#include <QPixmap>
#include <QString>
#include <QByteArray>
#include <QTimer>
#include "AppManager.h"
#include "measuredialog.h"

class QSerialPort;

namespace Ui {
class PrintDialog;
}

class PrintDialog : public QDialog
{
    Q_OBJECT

public:
    // Which screen launched PrintDialog -> where btn_back should return to.
    enum PreviousPage {
        HomePage,
        MeasurePage,
        CalculatorPage
    };

    // Filled by MeasureDialog before showing PrintDialog.
    struct ScanContext
    {
        QString patientName;
        QString patientId;
        QString doctorName;
        QString dateTime;
        QString eye;            // "OD" / "OS"
        QString axialLength;    // formatted AL value (mm)
        QPixmap waveformPixmap; // rendered QCustomPlot::toPixmap()
        bool    valid = false;
    };

    // Filled by CalculatorDialog before showing PrintDialog.
    struct CalcContext
    {
        QString patientName;
        QString patientId;
        QString doctorName;
        QString dateTime;
        QString eye;              // "OD" / "OS"

        int formulaIndex = 0;     // 0=SRK/II, 1=SRK/T, 2=Hoffer Q, 3=Holladay
        int lensRowidOne   = -1;  // rowid into `lens` table, -1 = not selected
        int lensRowidTwo   = -1;
        int lensRowidThree = -1;

        // Optional pre-formatted values. If left empty, PrintDialog will
        // still print the formula name + lens rowids above; fill these in
        // once CalculatorDialog has the actual computed K1/K2/IOL results
        // to display, otherwise the printout just shows the raw selection.
        QString k1;
        QString k2;
        QString axialLength;
        QString aConstant;
        QString iolPower;
        QString predictedRefraction;

        bool valid = false;
    };

    explicit PrintDialog(QWidget *parent = nullptr);
    ~PrintDialog();

    // Identity - who/what we're printing for. Called from HomeScreenDialog /
    // CalculatorDialog right before show().
    void setPatientId(const QString &patientId);
    void setDoctorId(const QString &doctorId);
    void setPreviousPage(PreviousPage page);

    // Content - full context for scan / calc printing.
    void setScanContext(const ScanContext &ctx);
    void setCalcContext(const CalcContext &ctx);

    PrintDialog::ScanContext buildScanContextFromCurrentReading();
<<<<<<< HEAD


=======
>>>>>>> c45e4e3d7db5a6fc95b663ed077b6e12fe2a2556

private slots:
    void on_btn_back_clicked();
    void on_btn_scan_clicked();
    void on_btn_calculations_clicked();
    void on_btn_both_clicked();

    // Clock in the top-right corner (lbl_time in the .ui).
    void updateTime();
<<<<<<< HEAD

=======
>>>>>>> c45e4e3d7db5a6fc95b663ed077b6e12fe2a2556

private:
    Ui::PrintDialog *ui;

    QString      m_patientId;
    QString      m_doctorId;
    QString      m_patientName;
    QString      m_doctorName;
    PreviousPage m_previousPage;

    ScanContext m_scanCtx;
    CalcContext m_calcCtx;
<<<<<<< HEAD

    QSerialPort *m_printerPort;
    QTimer      *m_clockTimer;

    // CSN-A2 58mm thermal printer: 384 dots wide.
    static const int kPrinterWidthPx = 384;

    // --- Serial port helpers -------------------------------------------------
    bool openPrinterPort();
    void closePrinterPort();
    bool writeToPrinter(const QByteArray &data);
    void debugDumpPortDiagnostics(const QString &portName);

    // --- ESC/POS command builders -------------------------------------------
    QByteArray escInit();
    QByteArray escCut();
    QByteArray escAlignCenter();
    QByteArray escAlignLeft();
    QByteArray escBoldOn();
    QByteArray escBoldOff();
    QByteArray escFeedLines(int n);
    QByteArray textLine(const QString &text);

    QByteArray pixmapToEscRaster(const QPixmap &pixmap);

    // --- Content builders ----------------------------------------------------
    QByteArray buildScanPrintJob(const ScanContext &ctx, bool withCut);
    QByteArray buildCalcPrintJob(const CalcContext &ctx, bool withCut);
    QString    buildCalcContent(const CalcContext &ctx);

    // --- UI helpers -----------------------------------------------------------
    void fillScanHeaderInfo(ScanContext &ctx);
    void fillCalcHeaderInfo(CalcContext &ctx);
    void loadPatientDoctorNames();
    void showSnack(const QString &msg, bool isError = true);
    void returnToPreviousPage();

    // --- Dummy data (Stage 1 - no DB yet) -------------------------------------
    // Used when a button is pressed without a real context having been set
    // via setScanContext()/setCalcContext(), so printing can be tested before
    // the database wiring is in place. Remove/bypass once real data flows in.
    ScanContext makeDummyScanContext();
    CalcContext makeDummyCalcContext();
    QPixmap     makeDummyWaveform();

    // --- Print flows ------------------------------------------------------------
    void doPrintScan();
    void doPrintCalc();
    void doPrintAll();

    QPixmap applyLayoutOrientation(const QPixmap &waveform) const;

=======

    QSerialPort *m_printerPort;
    QTimer      *m_clockTimer;

    // CSN-A2 58mm thermal printer: 384 dots wide.
    static const int kPrinterWidthPx = 384;

    // --- Serial port helpers -------------------------------------------------
    bool openPrinterPort();
    void closePrinterPort();
    bool writeToPrinter(const QByteArray &data);
    void debugDumpPortDiagnostics(const QString &portName);

    // --- ESC/POS command builders -------------------------------------------
    QByteArray escInit();
    QByteArray escCut();
    QByteArray escAlignCenter();
    QByteArray escAlignLeft();
    QByteArray escBoldOn();
    QByteArray escBoldOff();
    QByteArray escFeedLines(int n);
    QByteArray textLine(const QString &text);

    QByteArray pixmapToEscRaster(const QPixmap &pixmap);

    // --- Content builders ----------------------------------------------------
    QByteArray buildScanPrintJob(const ScanContext &ctx, bool withCut);
    QByteArray buildCalcPrintJob(const CalcContext &ctx, bool withCut);
    QString    buildCalcContent(const CalcContext &ctx);

    // --- UI helpers -----------------------------------------------------------
    void fillScanHeaderInfo(ScanContext &ctx);
    void fillCalcHeaderInfo(CalcContext &ctx);
    void loadPatientDoctorNames();
    void showSnack(const QString &msg, bool isError = true);
    void returnToPreviousPage();

    // --- Dummy data (Stage 1 - no DB yet) -------------------------------------
    // Used when a button is pressed without a real context having been set
    // via setScanContext()/setCalcContext(), so printing can be tested before
    // the database wiring is in place. Remove/bypass once real data flows in.
    ScanContext makeDummyScanContext();
    CalcContext makeDummyCalcContext();
    QPixmap     makeDummyWaveform();

    // --- Print flows ------------------------------------------------------------
    void doPrintScan();
    void doPrintCalc();
    void doPrintAll();
>>>>>>> c45e4e3d7db5a6fc95b663ed077b6e12fe2a2556
};

#endif // PRINTDIALOG_H
