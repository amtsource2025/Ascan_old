#include "measuredialog.h"
#include "ui_measuredialog.h"
#include "homescreendialog.h"
#include "calculatordialog.h"
#include <QMessageBox>
#include <cmath>
#include <algorithm>

// ─────────────────────────────────────────────────────────────
//  Constructor
// ─────────────────────────────────────────────────────────────
MeasureDialog::MeasureDialog(const QString &patientId,
                             const QString &doctorId,
                             QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MeasureDialog)
    , m_patientId(patientId)
    , m_doctorId(doctorId)
    , m_currentEye(1)      // rleye:      1 = OD  (default start on OD)
    , m_lensType(1)        // apmode:     1 = Phakic (default)
    , m_opMode(0)          // conimmmode: 0 = Contact (default)
    , m_selectedReading(1)
    , m_plot(nullptr)
{
    ui->setupUi(this);

    // ── Set labels BEFORE calling updateLensTypeUI / updateOpModeUI
    //    so those functions read the correct text and set m_lensType
    //    and m_opMode to the right integer values.
    ui->lineEdit_lensType->setText("Phakic");  // apmode = 1
    ui->lbl_opMode->setText("Contact");        // conimmmode = 0
    ui->btn_eye->setText("OD");                // rleye = 1

    updateLensTypeUI();
    updateOpModeUI();

    if (!openDatabase())
        qDebug() << "MeasureDialog: Failed to open database!";

    // Clock
    clockTimer = new QTimer(this);
    connect(clockTimer, &QTimer::timeout,
            this, &MeasureDialog::updateTime);
    clockTimer->start(1000);
    updateTime();

    loadPatientInfo();
    loadDoctorInfo();

    // ── Create QCustomPlot as a direct child of btn_startMeasure ──
    m_plot = new QCustomPlot(ui->btn_startMeasure);
    m_plot->setGeometry(0, 0,
                        ui->btn_startMeasure->width(),
                        ui->btn_startMeasure->height());
    m_plot->show();

    setupPlot();

    // ── Raise play button and markers above the plot ──────────
    ui->btn_play->raise();
    ui->marker_cornea->raise();
    ui->marker_lensOne->raise();
    ui->marker_lensTwo->raise();
    ui->marker_retina->raise();

    m_scanId = QUuid::createUuid().toString(QUuid::WithoutBraces);

    loadReadings();          // loads + auto-plots first reading
    updatePlayButtonVisibility();

    // ── Debug dump: print every reading row for this patient ──
    QSqlQuery diag(db);
    diag.prepare(
        "SELECT readingno, rleye, apmode, conimmmode, al, deviation "
        "FROM reading WHERE patientid = ? AND doctorid = ? "
        "ORDER BY rleye, apmode, conimmmode, readingno");
    diag.addBindValue(m_patientId);
    diag.addBindValue(m_doctorId);
    if (diag.exec()) {
        qDebug() << "=== ALL READINGS for patient" << m_patientId << "===";
        while (diag.next()) {
            qDebug() << "  rno="  << diag.value(0).toInt()
            << " eye="   << diag.value(1).toInt()
            << (diag.value(1).toInt() == 1 ? "(OD)" : "(OS)")
            << " ap="    << diag.value(2).toInt()
            << (diag.value(2).toInt() == 0 ? "(APhakic)"
                : diag.value(2).toInt() == 1 ? "(Phakic)"
                                             : "(DenseCat)")
            << " ci="    << diag.value(3).toInt()
            << (diag.value(3).toInt() == 0 ? "(Contact)" : "(Immersion)")
            << " al="    << diag.value(4).toDouble()
            << " dev="   << diag.value(5).toDouble();
        }
        qDebug() << "=== END ===";
    } else {
        qDebug() << "Diag query failed:" << diag.lastError().text();
    }
}

// ─────────────────────────────────────────────────────────────
//  Destructor
// ─────────────────────────────────────────────────────────────
MeasureDialog::~MeasureDialog()
{
    delete ui;
}

// ─────────────────────────────────────────────────────────────
//  openDatabase
// ─────────────────────────────────────────────────────────────
bool MeasureDialog::openDatabase()
{
    if (QSqlDatabase::contains("measure_conn")) {
        db = QSqlDatabase::database("measure_conn");
    } else {
        db = QSqlDatabase::database();
    }
    if (!db.open()) {
        qDebug() << "MeasureDialog DB Error:" << db.lastError().text();
        return false;
    }
    return true;
}

// ─────────────────────────────────────────────────────────────
//  loadPatientInfo
//  Schema: patient.patientid TEXT, patient.name TEXT
// ─────────────────────────────────────────────────────────────
void MeasureDialog::loadPatientInfo()
{
    QSqlQuery q(db);
    q.prepare("SELECT name FROM patient WHERE patientid = ?");
    q.addBindValue(m_patientId);
    if (q.exec() && q.next())
        ui->lineEdit_patName->setText(q.value(0).toString());
    else
        qDebug() << "loadPatientInfo: no row for patientid=" << m_patientId;
}

// ─────────────────────────────────────────────────────────────
//  loadDoctorInfo
//  Schema: doctor.doctorid TEXT, doctor.name TEXT
// ─────────────────────────────────────────────────────────────
void MeasureDialog::loadDoctorInfo()
{
    QSqlQuery q(db);
    q.prepare("SELECT name FROM doctor WHERE doctorid = ?");
    q.addBindValue(m_doctorId);
    if (q.exec() && q.next())
        ui->lineEdit_docName->setText(q.value(0).toString());
    else
        qDebug() << "loadDoctorInfo: no row for doctorid=" << m_doctorId;
}

// ─────────────────────────────────────────────────────────────
//  setupPlot
//  Graph indices:
//    0 = waveform      (white solid)
//    1 = cornea peak   (red    dashed vertical)
//    2 = lens front    (yellow dashed vertical)
//    3 = lens back     (yellow dashed vertical)
//    4 = retina peak   (green  dashed vertical)
// ─────────────────────────────────────────────────────────────
void MeasureDialog::setupPlot()
{
    QCustomPlot *plot = m_plot;

    plot->setBackground(QBrush(QColor(0, 0, 0)));
    plot->axisRect()->setBackground(QBrush(QColor(0, 0, 0)));

    // Graph 0 — main waveform
    plot->addGraph();
    plot->graph(0)->setName("Waveform");
    QPen wavePen(QColor(255, 255, 255));
    wavePen.setWidthF(1.6);
    plot->graph(0)->setPen(wavePen);

    // Graphs 1–4 — anatomical peak markers (dashed vertical lines)
    struct PeakDef { QColor color; QString name; };
    const QList<PeakDef> peaks = {
        { QColor("#FF4444"), "Cornea"     },   // graph 1
        { QColor("#FFD700"), "Lens front" },   // graph 2
        { QColor("#FFD700"), "Lens back"  },   // graph 3
        { QColor("#44FF88"), "Retina"     }    // graph 4
    };
    for (const auto &pk : peaks) {
        plot->addGraph();
        const int idx = plot->graphCount() - 1;
        QPen p(pk.color);
        p.setWidthF(1.4);
        p.setStyle(Qt::DashLine);
        plot->graph(idx)->setPen(p);
        plot->graph(idx)->setName(pk.name);
        plot->graph(idx)->setLineStyle(QCPGraph::lsLine);
    }

    plot->xAxis->setVisible(false);
    plot->yAxis->setVisible(false);
    plot->xAxis2->setVisible(false);
    plot->yAxis2->setVisible(false);

    plot->xAxis->grid()->setPen(QPen(QColor("#1a2f45"), 0.5, Qt::DotLine));
    plot->yAxis->grid()->setPen(QPen(QColor("#1a2f45"), 0.5, Qt::DotLine));

    plot->axisRect()->setAutoMargins(QCP::msNone);
    plot->axisRect()->setMargins(QMargins(2, 2, 2, 2));

    plot->xAxis->setRange(0, 30);
    plot->yAxis->setRange(0, 255);

    plot->legend->setVisible(false);
    plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    plot->replot();
}

// ─────────────────────────────────────────────────────────────
//  plotReading
//  Fetches one reading row using all 5 filter keys:
//    patientid, doctorid, rleye, apmode, conimmmode, readingno
//
//  Columns read (index → name):
//    0 = al           REAL   — axial length (mm)
//    1 = acd          REAL   — anterior chamber depth
//    2 = lt           REAL   — lens thickness
//    3 = vit          REAL   — vitreous length
//    4 = cornea       INTEGER — sample index of cornea peak
//    5 = lensone      INTEGER — sample index of lens front peak
//    6 = lenstwo      INTEGER — sample index of lens back peak
//    7 = retina       INTEGER — sample index of retina peak
//    8 = readingdata  TEXT   — CSV waveform samples
// ─────────────────────────────────────────────────────────────
void MeasureDialog::plotReading(int readingNo)
{
    QSqlQuery q(db);
    q.prepare(R"(
        SELECT al, acd, lt, vit,
               cornea, lensone, lenstwo, retina,
               readingdata
        FROM   reading
        WHERE  patientid  = ?
          AND  doctorid   = ?
          AND  rleye      = ?
          AND  apmode     = ?
          AND  conimmmode = ?
          AND  readingno  = ?
    )");
    q.addBindValue(m_patientId);
    q.addBindValue(m_doctorId);
    q.addBindValue(m_currentEye);   // rleye:      1=OD, 0=OS
    q.addBindValue(m_lensType);     // apmode:     0=APhakic, 1=Phakic, 2=DenseCat
    q.addBindValue(m_opMode);       // conimmmode: 0=Contact, 1=Immersion
    q.addBindValue(readingNo);

    if (!q.exec() || !q.next()) {
        qDebug() << "plotReading: no row —"
                 << " patientid="  << m_patientId
                 << " doctorid="   << m_doctorId
                 << " rleye="      << m_currentEye
                 << " apmode="     << m_lensType
                 << " conimmmode=" << m_opMode
                 << " readingno="  << readingNo
                 << " err="        << q.lastError().text();
        clearPlot();
        return;
    }

    const double  al       = q.value(0).toDouble();
    const double  acd      = q.value(1).toDouble();
    const double  lt       = q.value(2).toDouble();
    const double  vit      = q.value(3).toDouble();
    const int     iCornea  = q.value(4).toInt();
    const int     iLens1   = q.value(5).toInt();
    const int     iLens2   = q.value(6).toInt();
    const int     iRetina  = q.value(7).toInt();
    const QString csvData  = q.value(8).toString();

    // Use actual AL; fall back to 24 mm only if zero/null
    const double totalMm = (al > 0.0) ? al : 24.0;

    QVector<double> samples = decodeReadingData(csvData);

    // Peak sample indices — use DB values if samples exist,
    // otherwise synthesise from ACD/LT/VIT
    int pCornea = iCornea;
    int pLens1  = iLens1;
    int pLens2  = iLens2;
    int pRetina = iRetina;

    if (samples.isEmpty()) {
        // No readingdata stored — synthesise a representative waveform
        // using the stored anatomical distances
        const int    N     = 2000;
        const double scale = totalMm / N;   // mm per sample

        pCornea = static_cast<int>(0.5            / scale);
        pLens1  = static_cast<int>(acd            / scale);
        pLens2  = static_cast<int>((acd + lt)     / scale);
        pRetina = static_cast<int>((acd + lt + vit) / scale);

        samples.resize(N);
        std::srand(static_cast<unsigned>(readingNo * 137 + 1));
        for (int i = 0; i < N; ++i) {
            double v = 6.0 + (std::rand() % 8);
            auto gauss = [](double i_, double c,
                            double amp, double sig) -> double {
                const double d = i_ - c;
                return amp * std::exp(-(d * d) / (2.0 * sig * sig));
            };
            v += gauss(i, pCornea, 220.0, 18.0);
            v += gauss(i, pLens1,  160.0, 14.0);
            v += gauss(i, pLens2,  140.0, 12.0);
            v += gauss(i, pRetina, 200.0, 16.0);
            samples[i] = std::min(v, 255.0);
        }
    }

    const int    N           = samples.size();
    const double mmPerSample = (N > 0) ? (totalMm / N) : 0.015;

    QVector<double> xs(N), ys(N);
    for (int i = 0; i < N; ++i) {
        xs[i] = i * mmPerSample;
        ys[i] = samples[i];
    }

    QCustomPlot *plot = m_plot;
    plot->graph(0)->setData(xs, ys);

    // Draw each anatomical peak as a vertical dashed line
    auto setVLine = [&](int graphIdx, int sampleIdx) {
        if (sampleIdx > 0 && sampleIdx < N) {
            const double x = sampleIdx * mmPerSample;
            plot->graph(graphIdx)->setData({x, x}, {0.0, 255.0});
        } else {
            plot->graph(graphIdx)->data()->clear();
        }
    };
    setVLine(1, pCornea);   // red
    setVLine(2, pLens1);    // yellow
    setVLine(3, pLens2);    // yellow
    setVLine(4, pRetina);   // green

    const double maxAmp =
        *std::max_element(samples.constBegin(), samples.constEnd());
    plot->xAxis->setRange(0.0, totalMm * 1.06);
    plot->yAxis->setRange(0.0, std::max(maxAmp * 1.12, 60.0));

    updateMarkerPositions(pCornea * mmPerSample,
                          pLens1  * mmPerSample,
                          pLens2  * mmPerSample,
                          pRetina * mmPerSample,
                          totalMm * 1.06);

    plot->replot();
}

// ─────────────────────────────────────────────────────────────
void MeasureDialog::clearPlot()
{
    for (int i = 0; i < m_plot->graphCount(); ++i)
        m_plot->graph(i)->data()->clear();
    m_plot->replot();
}

// ─────────────────────────────────────────────────────────────
//  updateMarkerPositions
//  Maps mm positions → pixel positions for the 4 marker labels
//  that float above the plot.
// ─────────────────────────────────────────────────────────────
void MeasureDialog::updateMarkerPositions(double xCornea,
                                          double xLens1,
                                          double xLens2,
                                          double xRetina,
                                          double totalMm)
{
    if (totalMm <= 0.0) return;

    // m_plot is a child of btn_startMeasure; map its origin back
    // to dialog coordinates so the floating markers align correctly
    const QPoint plotOriginInDialog =
        ui->btn_startMeasure->mapTo(this, QPoint(0, 0));

    const int axLeft  = plotOriginInDialog.x() + m_plot->axisRect()->left();
    const int axWidth = m_plot->axisRect()->width();
    const int markerY = plotOriginInDialog.y() - 12;

    auto mmToPx = [&](double mm) -> int {
        return axLeft + static_cast<int>((mm / totalMm) * axWidth) - 10;
    };

    ui->marker_cornea ->move(mmToPx(xCornea), markerY);
    ui->marker_lensOne->move(mmToPx(xLens1),  markerY);
    ui->marker_lensTwo->move(mmToPx(xLens2),  markerY);
    ui->marker_retina ->move(mmToPx(xRetina),  markerY);
}

// ─────────────────────────────────────────────────────────────
//  updatePlayButtonVisibility
//  Play button shows only when there are NO readings stored
//  for the current combination of eye + lens type + op mode.
// ─────────────────────────────────────────────────────────────
void MeasureDialog::updatePlayButtonVisibility()
{
    QSqlQuery q(db);
    q.prepare(R"(
        SELECT COUNT(*)
        FROM   reading
        WHERE  patientid  = ?
          AND  doctorid   = ?
          AND  rleye      = ?
          AND  apmode     = ?
          AND  conimmmode = ?
    )");
    q.addBindValue(m_patientId);
    q.addBindValue(m_doctorId);
    q.addBindValue(m_currentEye);
    q.addBindValue(m_lensType);
    q.addBindValue(m_opMode);

    bool hasData = false;
    if (q.exec() && q.next())
        hasData = (q.value(0).toInt() > 0);

    ui->btn_play->setVisible(!hasData);

    // Keep plot sized to the button in case layout changed
    m_plot->setGeometry(0, 0,
                        ui->btn_startMeasure->width(),
                        ui->btn_startMeasure->height());
}

// ─────────────────────────────────────────────────────────────
//  decodeReadingData
//  Schema: readingdata TEXT — stored as comma-separated doubles
//  Returns empty vector if field is NULL or empty.
// ─────────────────────────────────────────────────────────────
QVector<double> MeasureDialog::decodeReadingData(const QString &csv)
{
    QVector<double> out;
    if (csv.trimmed().isEmpty()) return out;

    const QStringList parts = csv.split(',', Qt::SkipEmptyParts);
    out.reserve(parts.size());
    for (const QString &p : parts) {
        bool ok = false;
        const double v = p.trimmed().toDouble(&ok);
        if (ok) out.append(v);
    }
    return out;
}

// ─────────────────────────────────────────────────────────────
//  loadReadings
//  Fetches up to 10 readings filtered by ALL FIVE keys:
//    patientid + doctorid + rleye + apmode + conimmmode
//
//  Columns read:
//    0 = readingno  INTEGER
//    1 = al         REAL
//    2 = acd        REAL
//    3 = lt         REAL
//    4 = vit        REAL
//    5 = deviation  REAL  (per-reading deviation from mean)
// ─────────────────────────────────────────────────────────────
void MeasureDialog::loadReadings()
{
    clearAllReadingLabels();

    QSqlQuery q(db);
    q.prepare(R"(
        SELECT readingno, al, acd, lt, vit, deviation
        FROM   reading
        WHERE  patientid  = ?
          AND  doctorid   = ?
          AND  rleye      = ?
          AND  apmode     = ?
          AND  conimmmode = ?
        ORDER  BY readingno ASC
        LIMIT  10
    )");
    q.addBindValue(m_patientId);
    q.addBindValue(m_doctorId);
    q.addBindValue(m_currentEye);   // rleye
    q.addBindValue(m_lensType);     // apmode
    q.addBindValue(m_opMode);       // conimmmode

    const QList<QLabel*> alLabels = {
        ui->lbl_alOne,   ui->lbl_alTwo,   ui->lbl_alThree,
        ui->lbl_alFour,  ui->lbl_alFive,  ui->lbl_alSix,
        ui->lbl_alSeven, ui->lbl_alEight, ui->lbl_alNine,
        ui->lbl_alTen
    };
    const QList<QLabel*> devLabels = {
        ui->lbl_devOne,   ui->lbl_devTwo,   ui->lbl_devThree,
        ui->lbl_devFour,  ui->lbl_devFive,  ui->lbl_devSix,
        ui->lbl_devSeven, ui->lbl_devEight, ui->lbl_devNine,
        ui->lbl_devTen
    };

    int firstReadingNo = -1;

    if (q.exec()) {
        while (q.next()) {
            // readingno is 1-based; convert to 0-based for array index
            const int    rNo = q.value(0).toInt() - 1;
            const double al  = q.value(1).toDouble();
            const double dev = q.value(5).toDouble();   // deviation column

            if (rNo >= 0 && rNo < 10) {
                alLabels [rNo]->setText(QString::number(al,  'f', 2));
                devLabels[rNo]->setText(QString::number(dev, 'f', 2));
                if (firstReadingNo < 0)
                    firstReadingNo = rNo + 1;   // back to 1-based
            }
        }
    } else {
        qDebug() << "loadReadings error:" << q.lastError().text();
    }

    // Compute and display average AL and SD across loaded readings
    updateAverageAndSD();

    // Auto-select and plot the first available reading
    if (firstReadingNo > 0) {
        m_selectedReading = firstReadingNo;
        // Draw thumbnails first, then apply highlight on top
        refreshAllButtonWaveforms();
        highlightGraphButton(firstReadingNo);
        plotReading(firstReadingNo);
    } else {
        refreshAllButtonWaveforms();
        clearPlot();
    }

    updatePlayButtonVisibility();
}

// ─────────────────────────────────────────────────────────────
//  clearAllReadingLabels
//  Resets all 10 AL + deviation labels and all stat fields.
// ─────────────────────────────────────────────────────────────
void MeasureDialog::clearAllReadingLabels()
{
    const QList<QLabel*> alLabels = {
        ui->lbl_alOne,   ui->lbl_alTwo,   ui->lbl_alThree,
        ui->lbl_alFour,  ui->lbl_alFive,  ui->lbl_alSix,
        ui->lbl_alSeven, ui->lbl_alEight, ui->lbl_alNine,
        ui->lbl_alTen
    };
    const QList<QLabel*> devLabels = {
        ui->lbl_devOne,   ui->lbl_devTwo,   ui->lbl_devThree,
        ui->lbl_devFour,  ui->lbl_devFive,  ui->lbl_devSix,
        ui->lbl_devSeven, ui->lbl_devEight, ui->lbl_devNine,
        ui->lbl_devTen
    };

    for (auto *l : alLabels)  l->setText("0.00");
    for (auto *l : devLabels) l->setText("0.00");

    ui->lineEdit_al    ->clear();
    ui->lineEdit_acd   ->clear();
    ui->lineEdit_lt    ->clear();
    ui->lineEdit_vit   ->clear();
    ui->lineEdit_sd    ->clear();
    ui->lineEdit_avgAl ->clear();
}

// ─────────────────────────────────────────────────────────────
//  selectReading
//  Called by every graph button.
//  Populates the right-side stat panel from the DB row and
//  plots the waveform.
//
//  Columns read (index → schema name):
//    0 = al            REAL
//    1 = acd           REAL
//    2 = lt            REAL
//    3 = vit           REAL
//    4 = aval          REAL  — stored average AL for this session
//    5 = stddeviation  REAL  — stored standard deviation (exact column name)
// ─────────────────────────────────────────────────────────────
void MeasureDialog::selectReading(int readingNo)
{
    m_selectedReading = readingNo;
    highlightGraphButton(readingNo);

    QSqlQuery q(db);
    q.prepare(R"(
        SELECT al, acd, lt, vit, aval, stddeviation
        FROM   reading
        WHERE  patientid  = ?
          AND  doctorid   = ?
          AND  rleye      = ?
          AND  apmode     = ?
          AND  conimmmode = ?
          AND  readingno  = ?
    )");
    q.addBindValue(m_patientId);
    q.addBindValue(m_doctorId);
    q.addBindValue(m_currentEye);   // rleye
    q.addBindValue(m_lensType);     // apmode
    q.addBindValue(m_opMode);       // conimmmode
    q.addBindValue(readingNo);

    if (q.exec() && q.next()) {
        ui->lineEdit_al    ->setText(
            QString::number(q.value(0).toDouble(), 'f', 2));   // al
        ui->lineEdit_acd   ->setText(
            QString::number(q.value(1).toDouble(), 'f', 2));   // acd
        ui->lineEdit_lt    ->setText(
            QString::number(q.value(2).toDouble(), 'f', 2));   // lt
        ui->lineEdit_vit   ->setText(
            QString::number(q.value(3).toDouble(), 'f', 2));   // vit
        ui->lineEdit_avgAl ->setText(
            QString::number(q.value(4).toDouble(), 'f', 2));   // aval
        ui->lineEdit_sd    ->setText(
            QString::number(q.value(5).toDouble(), 'f', 2));   // stddeviation
    } else {
        qDebug() << "selectReading: no row —"
                 << " rno=" << readingNo
                 << " eye=" << m_currentEye
                 << " ap="  << m_lensType
                 << " ci="  << m_opMode
                 << q.lastError().text();
        ui->lineEdit_al    ->clear();
        ui->lineEdit_acd   ->clear();
        ui->lineEdit_lt    ->clear();
        ui->lineEdit_vit   ->clear();
        ui->lineEdit_avgAl ->clear();
        ui->lineEdit_sd    ->clear();
    }

    plotReading(readingNo);
}

// ─────────────────────────────────────────────────────────────
//  updateAverageAndSD
//  Computes average AL and SD across all loaded readings for
//  the current eye + lens type + op mode combination.
//  (Computed in C++ rather than trusting stored aval/stddeviation
//   so the display is always accurate after add/delete.)
// ─────────────────────────────────────────────────────────────
void MeasureDialog::updateAverageAndSD()
{
    QSqlQuery q(db);
    q.prepare(R"(
        SELECT al
        FROM   reading
        WHERE  patientid  = ?
          AND  doctorid   = ?
          AND  rleye      = ?
          AND  apmode     = ?
          AND  conimmmode = ?
        ORDER  BY readingno ASC
        LIMIT  10
    )");
    q.addBindValue(m_patientId);
    q.addBindValue(m_doctorId);
    q.addBindValue(m_currentEye);
    q.addBindValue(m_lensType);
    q.addBindValue(m_opMode);

    QList<double> vals;
    if (q.exec())
        while (q.next())
            vals << q.value(0).toDouble();

    if (vals.isEmpty()) {
        ui->lineEdit_avgAl->clear();
        ui->lineEdit_sd   ->clear();
        return;
    }

    double sum = 0.0;
    for (double v : vals) sum += v;
    const double avg = sum / vals.size();

    double varSum = 0.0;
    for (double v : vals) varSum += (v - avg) * (v - avg);
    const double sd = std::sqrt(varSum / vals.size());

    ui->lineEdit_avgAl->setText(QString::number(avg, 'f', 2));
    ui->lineEdit_sd   ->setText(QString::number(sd,  'f', 2));
}

// ─────────────────────────────────────────────────────────────
//  highlightGraphButton
//  Applies a white border to the selected button; resets others.
// ─────────────────────────────────────────────────────────────
void MeasureDialog::highlightGraphButton(int readingNo)
{
    const QList<QPushButton*> btns = {
        ui->btn_graphOne,   ui->btn_graphTwo,   ui->btn_graphThree,
        ui->btn_graphFour,  ui->btn_graphFive,  ui->btn_graphSix,
        ui->btn_graphSeven, ui->btn_graphEight, ui->btn_graphNine,
        ui->btn_graphTen
    };

    for (int i = 0; i < btns.size(); ++i) {
        if (i + 1 == readingNo) {
            // Selected — bright white border, dark blue background
            btns[i]->setStyleSheet(
                "QPushButton { border: 2px solid #ffffff;"
                "              border-radius: 4px;"
                "              background: #0d3050; padding: 0px; }");
        } else {
            // Unselected — cyan border, transparent background
            btns[i]->setStyleSheet(
                "QPushButton { border: 1px solid #29ABE2;"
                "              border-radius: 4px;"
                "              background: transparent; padding: 0px; }");
        }
    }
}

// ─────────────────────────────────────────────────────────────
//  updateLensTypeUI
//  Reads the current text from lineEdit_lensType, sets
//  m_lensType to the correct apmode integer and updates
//  the btn_lensType icon.
//
//  apmode: 0 = APhakic, 1 = Phakic, 2 = Dense Cataract
// ─────────────────────────────────────────────────────────────
void MeasureDialog::updateLensTypeUI()
{
    const QString t = ui->lineEdit_lensType->text();
    if (t == "APhakic") {
        m_lensType = 0;
        ui->btn_lensType->setStyleSheet(
            "border-image: url(:/images/aphakic-icon.png);");
    } else if (t == "Phakic") {
        m_lensType = 1;
        ui->btn_lensType->setStyleSheet(
            "border-image: url(:/images/phakic.png);");
    } else if (t == "Dense Cataract") {
        m_lensType = 2;
        ui->btn_lensType->setStyleSheet(
            "border-image: url(:/images/aphakic-icon.png);");
    }
}

// ─────────────────────────────────────────────────────────────
//  updateOpModeUI
//  Reads the current text from lbl_opMode, sets m_opMode to
//  the correct conimmmode integer and updates btn_opMode icon.
//
//  conimmmode: 0 = Contact, 1 = Immersion
// ─────────────────────────────────────────────────────────────
void MeasureDialog::updateOpModeUI()
{
    const QString m = ui->lbl_opMode->text();
    if (m == "Contact") {
        m_opMode = 0;
        ui->btn_opMode->setStyleSheet(
            "border-image: url(:/images/contact.png);");
    } else if (m == "Immersion") {
        m_opMode = 1;
        ui->btn_opMode->setStyleSheet(
            "border-image: url(:/images/immersion.png);");
    }
}

// ─────────────────────────────────────────────────────────────
//  Clock
// ─────────────────────────────────────────────────────────────
void MeasureDialog::updateTime()
{
    ui->lbl_time->setText(QTime::currentTime().toString("hh:mm:ss"));
}

// ─────────────────────────────────────────────────────────────
//  Button: eye toggle OD ↔ OS
//  rleye: OD = 1, OS = 0
// ─────────────────────────────────────────────────────────────
void MeasureDialog::on_btn_eye_clicked()
{
    m_currentEye = (m_currentEye == 1) ? 0 : 1;            // toggle 1 ↔ 0
    ui->btn_eye->setText(m_currentEye == 1 ? "OD" : "OS"); // 1→OD, 0→OS
    loadReadings();
}

// ─────────────────────────────────────────────────────────────
//  Button: lens type cycle
//  apmode: 0=APhakic → 1=Phakic → 2=Dense Cataract → 0=APhakic …
// ─────────────────────────────────────────────────────────────
void MeasureDialog::on_btn_lensType_clicked()
{
    m_lensType = (m_lensType + 1) % 3;
    const QStringList types = {"APhakic", "Phakic", "Dense Cataract"};
    ui->lineEdit_lensType->setText(types[m_lensType]);
    updateLensTypeUI();
    loadReadings();
}

// ─────────────────────────────────────────────────────────────
//  Button: op mode toggle
//  conimmmode: 0=Contact → 1=Immersion → 0=Contact …
// ─────────────────────────────────────────────────────────────
void MeasureDialog::on_btn_opMode_clicked()
{
    m_opMode = (m_opMode + 1) % 2;
    ui->lbl_opMode->setText(m_opMode == 0 ? "Contact" : "Immersion");
    updateOpModeUI();
    loadReadings();
}

// ─────────────────────────────────────────────────────────────
//  Button: start measure
//  Hardware integration point.
//  When hardware saves a new row it MUST use:
//    rleye      = m_currentEye   (1=OD, 0=OS)
//    apmode     = m_lensType     (0=APhakic, 1=Phakic, 2=DenseCat)
//    conimmmode = m_opMode       (0=Contact, 1=Immersion)
//    patientid  = m_patientId
//    doctorid   = m_doctorId
//  Then call loadReadings() to refresh the UI.
// ─────────────────────────────────────────────────────────────
void MeasureDialog::on_btn_startMeasure_clicked()
{
    // TODO: trigger hardware scan
    loadReadings();
}

// ─────────────────────────────────────────────────────────────
//  Button: play — replot currently selected reading
// ─────────────────────────────────────────────────────────────
void MeasureDialog::on_btn_play_clicked()
{
    if (m_selectedReading >= 1)
        plotReading(m_selectedReading);
}

// ─────────────────────────────────────────────────────────────
//  Button: home / calculator
// ─────────────────────────────────────────────────────────────
void MeasureDialog::on_btn_home_clicked()
{
    HomeScreenDialog homeScreen(m_patientId, m_doctorId, this);
    homeScreen.exec();
}

void MeasureDialog::on_btn_calculator_clicked()
{
    CalculatorDialog dlg(this);
    dlg.exec();
}

// ─────────────────────────────────────────────────────────────
//  Button: delete selected reading
//  Deletes the exact row (all 5 keys + readingno), then
//  renumbers remaining rows for this combination 1…N.
// ─────────────────────────────────────────────────────────────
void MeasureDialog::on_butDelete_clicked()
{
    if (m_selectedReading < 1) return;

    const QMessageBox::StandardButton confirm = QMessageBox::question(
        this, "Delete Reading",
        QString("Delete reading %1?").arg(m_selectedReading),
        QMessageBox::Yes | QMessageBox::No);
    if (confirm != QMessageBox::Yes) return;

    // ── Step 1: delete the row ────────────────────────────────
    QSqlQuery del(db);
    del.prepare(R"(
        DELETE FROM reading
        WHERE  patientid  = ?
          AND  doctorid   = ?
          AND  rleye      = ?
          AND  apmode     = ?
          AND  conimmmode = ?
          AND  readingno  = ?
    )");
    del.addBindValue(m_patientId);
    del.addBindValue(m_doctorId);
    del.addBindValue(m_currentEye);
    del.addBindValue(m_lensType);
    del.addBindValue(m_opMode);
    del.addBindValue(m_selectedReading);

    if (!del.exec()) {
        qDebug() << "Delete failed:" << del.lastError().text();
        return;
    }

    // ── Step 2: renumber remaining rows sequentially 1…N ─────
    //    Fetch by id (the autoincrement PK) so order is stable
    QSqlQuery fetch(db);
    fetch.prepare(R"(
        SELECT id FROM reading
        WHERE  patientid  = ?
          AND  doctorid   = ?
          AND  rleye      = ?
          AND  apmode     = ?
          AND  conimmmode = ?
        ORDER  BY readingno ASC
    )");
    fetch.addBindValue(m_patientId);
    fetch.addBindValue(m_doctorId);
    fetch.addBindValue(m_currentEye);
    fetch.addBindValue(m_lensType);
    fetch.addBindValue(m_opMode);

    if (fetch.exec()) {
        int newNo = 1;
        while (fetch.next()) {
            QSqlQuery upd(db);
            upd.prepare("UPDATE reading SET readingno = ? WHERE id = ?");
            upd.addBindValue(newNo++);
            upd.addBindValue(fetch.value(0).toInt());
            upd.exec();
        }
    } else {
        qDebug() << "Renumber fetch failed:" << fetch.lastError().text();
    }

    loadReadings();   // refresh UI (updatePlayButtonVisibility called inside)
}

// ─────────────────────────────────────────────────────────────
//  Graph buttons 1–10
// ─────────────────────────────────────────────────────────────
void MeasureDialog::on_btn_graphOne_clicked()   { selectReading(1);  }
void MeasureDialog::on_btn_graphTwo_clicked()   { selectReading(2);  }
void MeasureDialog::on_btn_graphThree_clicked() { selectReading(3);  }
void MeasureDialog::on_btn_graphFour_clicked()  { selectReading(4);  }
void MeasureDialog::on_btn_graphFive_clicked()  { selectReading(5);  }
void MeasureDialog::on_btn_graphSix_clicked()   { selectReading(6);  }
void MeasureDialog::on_btn_graphSeven_clicked() { selectReading(7);  }
void MeasureDialog::on_btn_graphEight_clicked() { selectReading(8);  }
void MeasureDialog::on_btn_graphNine_clicked()  { selectReading(9);  }
void MeasureDialog::on_btn_graphTen_clicked()   { selectReading(10); }

// ─────────────────────────────────────────────────────────────
//  drawMiniWaveformOnButton
//  Renders a thumbnail waveform onto one graph button face.
//  Uses all 5 filter keys to fetch the exact reading row.
//
//  Columns read (index → schema name):
//    0 = al          REAL
//    1 = acd         REAL
//    2 = lt          REAL
//    3 = vit         REAL
//    4 = cornea      INTEGER  (unused in thumbnail but fetched for completeness)
//    5 = lensone     INTEGER
//    6 = lenstwo     INTEGER
//    7 = retina      INTEGER
//    8 = readingdata TEXT
// ─────────────────────────────────────────────────────────────
void MeasureDialog::drawMiniWaveformOnButton(QPushButton *btn, int readingNo)
{
    const int W = btn->width();
    const int H = btn->height();
    if (W <= 0 || H <= 0) return;

    QPixmap pix(W, H);
    pix.fill(QColor(0, 0, 0));

    QSqlQuery q(db);
    q.prepare(R"(
        SELECT al, acd, lt, vit,
               cornea, lensone, lenstwo, retina,
               readingdata
        FROM   reading
        WHERE  patientid  = ?
          AND  doctorid   = ?
          AND  rleye      = ?
          AND  apmode     = ?
          AND  conimmmode = ?
          AND  readingno  = ?
    )");
    q.addBindValue(m_patientId);
    q.addBindValue(m_doctorId);
    q.addBindValue(m_currentEye);
    q.addBindValue(m_lensType);
    q.addBindValue(m_opMode);
    q.addBindValue(readingNo);

    QPainter painter(&pix);
    painter.setRenderHint(QPainter::Antialiasing);

    if (q.exec() && q.next()) {
        const double  al  = q.value(0).toDouble();   // al
        const double  acd = q.value(1).toDouble();   // acd
        const double  lt  = q.value(2).toDouble();   // lt
        const double  vit = q.value(3).toDouble();   // vit
        const QString csv = q.value(8).toString();   // readingdata

        QVector<double> samples = decodeReadingData(csv);
        const double totalMm = (al > 0.0) ? al : 24.0;

        // Synthesise if no CSV data stored
        if (samples.isEmpty()) {
            const int    N     = 500;
            const double scale = totalMm / N;
            const double pC    = 0.5            / scale;
            const double pL1   = acd            / scale;
            const double pL2   = (acd + lt)     / scale;
            const double pR    = (acd + lt + vit) / scale;
            samples.resize(N);
            std::srand(static_cast<unsigned>(readingNo * 137 + 1));
            for (int i = 0; i < N; ++i) {
                double v = 4.0 + (std::rand() % 5);
                auto g = [](double i_, double c,
                            double a, double s) -> double {
                    const double d = i_ - c;
                    return a * std::exp(-(d * d) / (2.0 * s * s));
                };
                v += g(i, pC,  220.0, 18.0);
                v += g(i, pL1, 160.0, 14.0);
                v += g(i, pL2, 140.0, 12.0);
                v += g(i, pR,  200.0, 16.0);
                samples[i] = std::min(v, 255.0);
            }
        }

        const int    N        = samples.size();
        const double maxAmp   = *std::max_element(samples.constBegin(), samples.constEnd());
        const double minAmp   = *std::min_element(samples.constBegin(), samples.constEnd());
        const double ampRange = (maxAmp - minAmp > 0.0) ? (maxAmp - minAmp) : 1.0;

        const int padX = 3, padY = 4;
        const int drawW = W - 2 * padX;
        const int drawH = H - 2 * padY;

        QPolygonF poly;
        poly.reserve(N);
        for (int i = 0; i < N; ++i) {
            const float x = padX + (float(i) / float(N - 1)) * drawW;
            const float y = padY + drawH -
                            float((samples[i] - minAmp) / ampRange) * drawH;
            poly.append(QPointF(x, y));
        }

        // Gradient fill under the waveform line
        QPainterPath path;
        path.moveTo(poly.first().x(), H);
        for (const QPointF &pt : poly) path.lineTo(pt);
        path.lineTo(poly.last().x(), H);
        path.closeSubpath();

        QLinearGradient grad(0, 0, 0, H);
        grad.setColorAt(0.0, QColor(41, 171, 226, 80));
        grad.setColorAt(1.0, QColor(41, 171, 226,  0));
        painter.fillPath(path, grad);

        // Waveform line
        QPen wavePen(QColor("#29ABE2"));
        wavePen.setWidthF(1.2);
        painter.setPen(wavePen);
        painter.drawPolyline(poly);

        // AL value in bottom-right corner
        painter.setPen(QColor("#ffffff"));
        painter.setFont(QFont("Arial", 7, QFont::Bold));
        painter.drawText(QRect(0, H - 13, W - 2, 12),
                         Qt::AlignRight,
                         QString::number(al, 'f', 2));

    } else {
        // No data for this slot — flat dashed line + slot number
        painter.setPen(QPen(QColor("#3a5060"), 1, Qt::DashLine));
        painter.drawLine(4, H / 2, W - 4, H / 2);
        painter.setPen(QColor("#4a6070"));
        painter.setFont(QFont("Arial", 7));
        painter.drawText(pix.rect(), Qt::AlignCenter,
                         QString::number(readingNo));
    }

    painter.end();

    btn->setIcon(QIcon(pix));
    btn->setIconSize(QSize(W, H));
    btn->setStyleSheet(
        "QPushButton { border: 1px solid #29ABE2; border-radius: 4px;"
        "              background: transparent; padding: 0px; }"
        "QPushButton:pressed { border: 2px solid #ffffff; }");
}

// ─────────────────────────────────────────────────────────────
//  refreshAllButtonWaveforms
//  Queries which readingno values exist for the current
//  eye + lens type + op mode, draws thumbnails for occupied
//  slots, blanks empty slots.
// ─────────────────────────────────────────────────────────────
void MeasureDialog::refreshAllButtonWaveforms()
{
    const QList<QPushButton*> btns = {
        ui->btn_graphOne,   ui->btn_graphTwo,   ui->btn_graphThree,
        ui->btn_graphFour,  ui->btn_graphFive,  ui->btn_graphSix,
        ui->btn_graphSeven, ui->btn_graphEight, ui->btn_graphNine,
        ui->btn_graphTen
    };

    // Find which reading numbers actually exist for this combination
    QSqlQuery q(db);
    q.prepare(R"(
        SELECT readingno FROM reading
        WHERE  patientid  = ?
          AND  doctorid   = ?
          AND  rleye      = ?
          AND  apmode     = ?
          AND  conimmmode = ?
        ORDER  BY readingno ASC
        LIMIT  10
    )");
    q.addBindValue(m_patientId);
    q.addBindValue(m_doctorId);
    q.addBindValue(m_currentEye);
    q.addBindValue(m_lensType);
    q.addBindValue(m_opMode);

    QSet<int> existing;
    if (q.exec())
        while (q.next())
            existing.insert(q.value(0).toInt());

    for (int i = 0; i < btns.size(); ++i) {
        const int rno = i + 1;
        if (existing.contains(rno)) {
            drawMiniWaveformOnButton(btns[i], rno);
        } else {
            // Empty slot — dark background, no icon
            btns[i]->setIcon(QIcon());
            btns[i]->setStyleSheet(
                "QPushButton { border: 1px solid #121212;"
                "              border-radius: 4px;"
                "              background: #121212; }");
        }
    }
}
