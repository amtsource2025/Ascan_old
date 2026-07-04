// #ifndef PRINTDIALOG_H
// #define PRINTDIALOG_H

// #include <QDialog>
// #include <QTimer>
// #include <QSqlDatabase>
// #include <QByteArray>
// #include <QVector>
// #include <QPixmap>
// #include <QLabel>
// #include <QScrollArea>
// #include <QPushButton>
// #include "qcustomplot.h"

// #include "IOLCalculator.h"

// namespace Ui { class PrintDialog; }

// // ─── Context structs ──────────────────────────────────────────────────────────
// struct ScanContext {
//     int eye        = 1;   // 1=OD, 0=OS
//     int apmode     = 1;   // 0=APhakic 1=Phakic 2=DenseCat
//     int conimmmode = 0;   // 0=Contact 1=Immersion
//     int readingNo  = 1;
//     QPixmap wavePixmap;
// };

// struct CalcContext {
//     int eye            = 1;
//     int formulaIndex   = 0;
//     int lensRowidOne   = -1;
//     int lensRowidTwo   = -1;
//     int lensRowidThree = -1;
// };

// // ─── PrintDialog ──────────────────────────────────────────────────────────────
// class PrintDialog : public QDialog {
//     Q_OBJECT

// public:
//     using ScanContext = ::ScanContext;
//     using CalcContext = ::CalcContext;

//     explicit PrintDialog(QWidget *parent = nullptr);
//     ~PrintDialog();

//     void setPatientId(const QString &patientId);
//     void setDoctorId (const QString &doctorId);
//     void setScanContext(const ScanContext &ctx);
//     void setCalcContext(const CalcContext &ctx);
//     void resetContext();

//     QPixmap fetchAndRenderWaveform(int eye, int apmode, int conimmmode, int readingNo);

//     enum PreviousPage
//     {
//         HomePage,
//         CalculatorPage
//     };

//     void setPreviousPage(PreviousPage page);

// protected:
//     void showEvent(QShowEvent *event) override;
//     void resizeEvent(QResizeEvent *event) override;

// private slots:
//     void updateTime();
//     void on_btn_back_clicked();
//     void on_btn_scan_clicked();
//     void on_btn_calculations_clicked();
//     void on_btn_both_clicked();
//     void on_btn_scan2_clicked();
//     void on_btn_calculations2_clicked();
//     void on_btn_both2_clicked();


//     // Live preview tick — advances one "line" per timer fire
//     void onPreviewTick();

//     // Close button on the live preview panel
//     void onPreviewClose();

// private:
//     QTimer     *m_printTimer = nullptr;
//     QByteArray  m_printBuffer;
//     int         m_printIndex = 0;
//     int         m_printFd    = -1;

//     bool configureSerialPort(int fd);
//     void onPrintTimerTick();

//     static constexpr int PAGE_MENU = 0;
//     static constexpr int PAGE_SCAN = 1;
//     static constexpr int PAGE_CALC = 2;
//     static constexpr int PAGE_BOTH = 3;

//     // Thermal paper constants (58 mm / CSN-A2)
//     static constexpr int PAPER_PX_W    = 384;   // raster width in pixels
//     static constexpr int PAPER_CHAR_W  = 32;    // text columns
//     static constexpr int PREVIEW_PX_W  = 384;   // preview pixmap width
//     static constexpr int LINE_H_PX     = 20;    // pixels per text line in preview
//     static constexpr int WAVE_H_PX     = 96;    // waveform height in preview

//     Ui::PrintDialog *ui;
//     QTimer          *clockTimer;
//     QSqlDatabase     db;

//     QString m_patientId;
//     QString m_doctorId;

//     ::ScanContext m_scanCtx;
//     ::CalcContext m_calcCtx;
//     bool m_hasScanCtx   = false;
//     bool m_hasCalcCtx   = false;
//     bool m_autoPageDone = false;

//     QString    m_scanContent;
//     QString    m_calcContent;
//     QByteArray m_scanEscPos;
//     QByteArray m_calcEscPos;

//     // The single canonical waveform image — built once per scan job and
//     // reused for BOTH the physical ESC/POS raster bytes and the on-screen
//     // live preview, so they can never visually drift apart.
//     QPixmap    m_lastWavePixmap;

//     // ── Live preview state ────────────────────────────────────────────────────
//     QLabel      *m_previewLabel    = nullptr;
//     QScrollArea *m_previewScroll   = nullptr;
//     QPushButton *m_previewCloseBtn = nullptr;
//     QLabel      *m_previewStatus   = nullptr;   // "Printing..." / "Done"

//     // The receipt pixmap we draw into incrementally
//     QPixmap      m_receiptPixmap;

//     // Lines of the current job split for animation
//     QStringList  m_previewLines;          // plain-text lines to render one-by-one
//     int          m_previewLineIdx = 0;    // next line to render
//     int          m_previewY       = 0;    // current draw Y in pixmap

//     // Waveform pixmap inserted once per job (scan jobs only)
//     QPixmap      m_wavePixmap;
//     bool         m_waveInserted   = false;// true once waveform row has been drawn

//     // Index in m_previewLines at which the waveform should be inserted
//     int          m_waveInsertAtLine = -1;

//     QTimer      *m_previewTimer  = nullptr;
//     static constexpr int PREVIEW_TICK_MS = 30; // ms per line — feels like printing

//     // ── Helpers ───────────────────────────────────────────────────────────────
//     void       showPage(int index);
//     QString    savedPrinterPort();
//     QString    fetchHospitalName();

//     // doPrint: sends bytes AND starts the live preview animation
//     void       doPrint(const QByteArray &rawEscPos,
//                  const QString    &plainText,
//                  const QPixmap    &wavePixmap = QPixmap());

//     QString    buildHeader(const QString &title);   // plain-text header (existing)
//     QString    buildScanContent();
//     QString    buildCalcContent();

//     // ESC/POS binary builders (used for actual printing)
//     QByteArray buildScanEscPos(QVector<double> &samplesOut);
//     QByteArray buildCalcEscPos();

//     // Waveform rendering — QCustomPlot based, single source of truth.
//     // Renders samples to a pixmap (used for preview AND as the source image
//     // for ESC/POS raster conversion).
//     QPixmap    renderWaveformPixmap(const QVector<double> &samples,
//                                  int w = PREVIEW_PX_W,
//                                  int h = WAVE_H_PX);

//     // Converts an already-rendered pixmap into ESC/POS GS v 0 raster bytes.
//     static QByteArray waveformToRasterBytes(const QPixmap &wavePixmap);

//     // Live preview
//     void setupLivePreview();
//     void repositionPreviewWidgets();
//     void startPreviewAnimation(const QString &plainText,
//                                const QPixmap &wavePixmap,
//                                int            waveAfterLine);
//     void drawNextPreviewLine();
//     void ensureReceiptPixmapCapacity(int neededY);

//     void showGraphPreview(const QPixmap &wavePixmap,
//                           std::function<void()> onDone);

//     QDialog    *m_graphPreviewDlg   = nullptr;
//     QLabel     *m_graphPreviewLabel = nullptr;
//     QPushButton *m_graphPreviewCloseBtn = nullptr;
//     QTimer     *m_graphPreviewTimer = nullptr;

//     PreviousPage m_previousPage;



// };

// #endif // PRINTDIALOG_H

#ifndef PRINTDIALOG_H
#define PRINTDIALOG_H

#include <QDialog>
#include <QPixmap>
#include <QString>
#include <QByteArray>
#include <QTimer>

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

private slots:
    void on_btn_back_clicked();
    void on_btn_scan_clicked();
    void on_btn_calculations_clicked();
    void on_btn_both_clicked();

    // Clock in the top-right corner (lbl_time in the .ui).
    void updateTime();

private:
    Ui::PrintDialog *ui;

    QString      m_patientId;
    QString      m_doctorId;
    QString      m_patientName;
    QString      m_doctorName;
    PreviousPage m_previousPage;

    ScanContext m_scanCtx;
    CalcContext m_calcCtx;

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
};

#endif // PRINTDIALOG_H
