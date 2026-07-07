// #include "waveformdialog.h"
// #include <QFile>
// #include <QTextStream>
// #include <QFileDialog>
// #include <QMessageBox>
// #include <QDataStream>
// #include <cmath>

// // ─────────────────────────────────────────────────────────────────────────────
// //  Constructor / Destructor
// // ─────────────────────────────────────────────────────────────────────────────
// WaveformDialog::WaveformDialog(const QString &patientId,
//                                const QString &doctorId,
//                                int            eye,
//                                int            readingNo,
//                                QWidget       *parent)
//     : QDialog(parent)
//     , m_patientId(patientId)
//     , m_doctorId(doctorId)
//     , m_eye(eye)
// {
//     // ── database ─────────────────────────────────────────────────────────────
//     if (QSqlDatabase::contains("waveform_conn")) {
//         db = QSqlDatabase::database("waveform_conn");
//     } else {
//         db = QSqlDatabase::database();
//     }
//     db.open();

//     setupUi();

//     // ── populate combo with available reading numbers ────────────────────────
//     QSqlQuery q(db);
//     q.prepare(R"(SELECT readingno FROM reading
//                   WHERE patientid=? AND doctorid=? AND rleye=?
//                   ORDER BY readingno ASC)");
//     q.addBindValue(m_patientId);
//     q.addBindValue(m_doctorId);
//     q.addBindValue(m_eye);

//     m_readingCbo->blockSignals(true);
//     if (q.exec()) {
//         while (q.next())
//             m_readingCbo->addItem(QString("Reading %1").arg(q.value(0).toInt()),
//                                   q.value(0).toInt());
//     }
//     m_readingCbo->blockSignals(false);

//     // Select the requested reading
//     int idx = m_readingCbo->findData(readingNo);
//     if (idx < 0) idx = 0;
//     m_readingCbo->setCurrentIndex(idx);
//     loadAndPlot(m_readingCbo->itemData(idx).toInt());
// }

// WaveformDialog::~WaveformDialog()
// {
//     if (db.isOpen()) db.close();
// }

// // ─────────────────────────────────────────────────────────────────────────────
// //  UI
// // ─────────────────────────────────────────────────────────────────────────────
// void WaveformDialog::setupUi()
// {
//     setWindowTitle("A-Scan Waveform");
//     resize(860, 580);
//     setStyleSheet(R"(
//         QDialog          { background: #1a2535; color: #e0e8f0; }
//         QLabel           { color: #a8c4d8; font-size: 12px; }
//         QLabel#val       { color: #29ABE2; font-size: 14px; font-weight: bold; }
//         QComboBox        { background:#253245; color:#e0e8f0; border:1px solid #29ABE2;
//                            border-radius:4px; padding:4px 8px; min-width:120px; }
//         QComboBox::drop-down { border:none; }
//         QPushButton      { background:#29ABE2; color:#fff; border:none;
//                            border-radius:4px; padding:6px 16px; font-size:12px; }
//         QPushButton:hover{ background:#1e8ab5; }
//         QPushButton#close{ background:#3a4a5c; }
//         QPushButton#close:hover{ background:#29ABE2; }
//     )");

//     // ── chart ────────────────────────────────────────────────────────────────
//     m_series = new QLineSeries();
//     m_series->setName("Echo amplitude");
//     QPen wpen(QColor("#29ABE2"));
//     wpen.setWidthF(1.4);
//     m_series->setPen(wpen);

//     // Peak marker series (vertical dashed lines simulated as series)
//     auto mkPeakSeries = [](QColor c, const QString &name) -> QLineSeries* {
//         auto *s = new QLineSeries();
//         s->setName(name);
//         QPen p(c); p.setWidthF(1.2); p.setStyle(Qt::DashLine);
//         s->setPen(p);
//         return s;
//     };
//     m_peakCornea = mkPeakSeries(QColor("#FF6B6B"), "Cornea");
//     m_peakLens1  = mkPeakSeries(QColor("#FFD93D"), "Lens front");
//     m_peakLens2  = mkPeakSeries(QColor("#FFD93D"), "Lens back");
//     m_peakRetina = mkPeakSeries(QColor("#6BCB77"), "Retina");

//     m_chart = new QChart();
//     m_chart->addSeries(m_series);
//     m_chart->addSeries(m_peakCornea);
//     m_chart->addSeries(m_peakLens1);
//     m_chart->addSeries(m_peakLens2);
//     m_chart->addSeries(m_peakRetina);
//     m_chart->setBackgroundBrush(QBrush(QColor("#0d1829")));
//     m_chart->setPlotAreaBackgroundBrush(QBrush(QColor("#111f30")));
//     m_chart->setPlotAreaBackgroundVisible(true);
//     m_chart->legend()->setLabelColor(QColor("#a8c4d8"));
//     m_chart->legend()->setVisible(true);

//     m_axisX = new QValueAxis();
//     m_axisX->setTitleText("Distance (mm)");
//     m_axisX->setTitleBrush(QBrush(QColor("#a8c4d8")));
//     m_axisX->setLabelFormat("%.1f");
//     m_axisX->setLabelsColor(QColor("#7a9ab0"));
//     m_axisX->setGridLineColor(QColor("#1e3045"));
//     m_axisX->setLinePenColor(QColor("#29ABE2"));
//     m_axisX->setRange(0, 35);

//     m_axisY = new QValueAxis();
//     m_axisY->setTitleText("Amplitude");
//     m_axisY->setTitleBrush(QBrush(QColor("#a8c4d8")));
//     m_axisY->setLabelFormat("%.0f");
//     m_axisY->setLabelsColor(QColor("#7a9ab0"));
//     m_axisY->setGridLineColor(QColor("#1e3045"));
//     m_axisY->setLinePenColor(QColor("#29ABE2"));
//     m_axisY->setRange(0, 255);

//     m_chart->addAxis(m_axisX, Qt::AlignBottom);
//     m_chart->addAxis(m_axisY, Qt::AlignLeft);

//     for (auto *s : {m_series, m_peakCornea, m_peakLens1, m_peakLens2, m_peakRetina}) {
//         s->attachAxis(m_axisX);
//         s->attachAxis(m_axisY);
//     }

//     m_chart->setTitle(QString("A-Scan Waveform  |  %1")
//                           .arg(m_eye == 0 ? "OD (Right Eye)" : "OS (Left Eye)"));
//     m_chart->setTitleBrush(QBrush(QColor("#e0e8f0")));

//     m_chartView = new QChartView(m_chart);
//     m_chartView->setRenderHint(QPainter::Antialiasing);

//     // ── stats panel ──────────────────────────────────────────────────────────
//     auto makeStatWidget = [](const QString &title, QLabel *&valLabel) -> QWidget* {
//         auto *w = new QWidget();
//         w->setStyleSheet("background:#1e3045; border-radius:6px; padding:6px;");
//         auto *vl = new QVBoxLayout(w);
//         vl->setSpacing(2); vl->setContentsMargins(10,6,10,6);
//         auto *ttl = new QLabel(title); ttl->setAlignment(Qt::AlignCenter);
//         ttl->setStyleSheet("color:#6a8fa8; font-size:11px;");
//         valLabel = new QLabel("—"); valLabel->setObjectName("val");
//         valLabel->setAlignment(Qt::AlignCenter);
//         valLabel->setStyleSheet("color:#29ABE2; font-size:16px; font-weight:bold;");
//         vl->addWidget(ttl);
//         vl->addWidget(valLabel);
//         return w;
//     };

//     auto *statsBar = new QHBoxLayout();
//     statsBar->setSpacing(8);
//     statsBar->addWidget(makeStatWidget("AL (mm)",   m_lblAL));
//     statsBar->addWidget(makeStatWidget("ACD (mm)",  m_lblACD));
//     statsBar->addWidget(makeStatWidget("LT (mm)",   m_lblLT));
//     statsBar->addWidget(makeStatWidget("VIT (mm)",  m_lblVit));
//     statsBar->addWidget(makeStatWidget("Deviation", m_lblDev));

//     // ── toolbar ──────────────────────────────────────────────────────────────
//     auto *toolbar = new QHBoxLayout();
//     toolbar->setSpacing(8);

//     auto *lblReading = new QLabel("Reading:");
//     lblReading->setStyleSheet("color:#a8c4d8; font-size:12px;");
//     m_readingCbo = new QComboBox();
//     connect(m_readingCbo, QOverload<int>::of(&QComboBox::currentIndexChanged),
//             this, &WaveformDialog::onReadingChanged);

//     auto *btnExport = new QPushButton("Export CSV");
//     connect(btnExport, &QPushButton::clicked, this, &WaveformDialog::onExportClicked);

//     auto *btnClose = new QPushButton("Close"); btnClose->setObjectName("close");
//     connect(btnClose, &QPushButton::clicked, this, &QDialog::accept);

//     toolbar->addWidget(lblReading);
//     toolbar->addWidget(m_readingCbo);
//     toolbar->addStretch();
//     toolbar->addWidget(btnExport);
//     toolbar->addWidget(btnClose);

//     // ── root layout ──────────────────────────────────────────────────────────
//     auto *root = new QVBoxLayout(this);
//     root->setContentsMargins(12, 12, 12, 12);
//     root->setSpacing(8);
//     root->addLayout(toolbar);
//     root->addLayout(statsBar);
//     root->addWidget(m_chartView, 1);
// }

// // ─────────────────────────────────────────────────────────────────────────────
// //  Load & plot
// // ─────────────────────────────────────────────────────────────────────────────
// void WaveformDialog::loadAndPlot(int readingNo)
// {
//     QSqlQuery q(db);
//     q.prepare(R"(
//         SELECT al, acd, lt, vit, deviation,
//                cornea, lensone, lenstwo, retina,
//                readingdata
//         FROM reading
//         WHERE patientid=? AND doctorid=? AND rleye=? AND readingno=?
//     )");
//     q.addBindValue(m_patientId);
//     q.addBindValue(m_doctorId);
//     q.addBindValue(m_eye);
//     q.addBindValue(readingNo);

//     if (!q.exec() || !q.next()) {
//         m_series->clear();
//         m_peakCornea->clear(); m_peakLens1->clear();
//         m_peakLens2->clear();  m_peakRetina->clear();
//         return;
//     }

//     double al  = q.value(0).toDouble();
//     double acd = q.value(1).toDouble();
//     double lt  = q.value(2).toDouble();
//     double vit = q.value(3).toDouble();
//     double dev = q.value(4).toDouble();

//     // Raw peak sample indices stored in DB (integer columns)
//     int iCornea = q.value(5).toInt();
//     int iLens1  = q.value(6).toInt();
//     int iLens2  = q.value(7).toInt();
//     int iRetina = q.value(8).toInt();

//     QByteArray rawData = q.value(9).toByteArray();

//     // ── update stat labels ────────────────────────────────────────────────────
//     m_lblAL ->setText(QString::number(al,  'f', 2));
//     m_lblACD->setText(QString::number(acd, 'f', 2));
//     m_lblLT ->setText(QString::number(lt,  'f', 2));
//     m_lblVit->setText(QString::number(vit, 'f', 2));
//     m_lblDev->setText(QString::number(dev, 'f', 2));

//     // ── decode waveform ───────────────────────────────────────────────────────
//     QVector<double> samples = decodeReadingData(rawData);

//     if (samples.isEmpty()) {
//         // No stored waveform — generate a synthetic one for display purposes
//         // based on the four peak positions derived from the AL components
//         // (cornea ≈ 0 mm, ACD, ACD+LT, ACD+LT+VIT=AL)
//         const int N = 2000;
//         samples.resize(N);
//         double scale = al / N;   // mm per sample

//         double posCornea = 0.5    / scale;
//         double posLens1  = acd    / scale;
//         double posLens2  = (acd + lt) / scale;
//         double posRetina = (acd + lt + vit) / scale;

//         // Build a noise floor + four Gaussian peaks
//         for (int i = 0; i < N; ++i) {
//             double v = 8.0 + (rand() % 6);   // noise floor ~8
//             auto gauss = [&](double centre, double amp, double sigma) {
//                 double d = i - centre;
//                 return amp * std::exp(-(d * d) / (2.0 * sigma * sigma));
//             };
//             v += gauss(posCornea, 220.0, 18.0);
//             v += gauss(posLens1,  160.0, 14.0);
//             v += gauss(posLens2,  140.0, 12.0);
//             v += gauss(posRetina, 200.0, 16.0);
//             samples[i] = std::min(v, 255.0);
//         }

//         iCornea = static_cast<int>(posCornea);
//         iLens1  = static_cast<int>(posLens1);
//         iLens2  = static_cast<int>(posLens2);
//         iRetina = static_cast<int>(posRetina);
//     }

//     // ── build main series ─────────────────────────────────────────────────────
//     m_series->clear();
//     const int N = samples.size();
//     // Map sample index → distance in mm using total AL
//     double mmPerSample = (N > 0 && al > 0) ? al / N : 0.015;

//     QVector<QPointF> pts;
//     pts.reserve(N);
//     for (int i = 0; i < N; ++i)
//         pts.append(QPointF(i * mmPerSample, samples[i]));
//     m_series->replace(pts);

//     // ── peak marker lines ─────────────────────────────────────────────────────
//     auto setPeakLine = [&](QLineSeries *s, int sampleIdx) {
//         s->clear();
//         if (sampleIdx <= 0 || sampleIdx >= N) return;
//         double x = sampleIdx * mmPerSample;
//         s->append(x, 0);
//         s->append(x, 255);
//     };
//     setPeakLine(m_peakCornea, iCornea);
//     setPeakLine(m_peakLens1,  iLens1);
//     setPeakLine(m_peakLens2,  iLens2);
//     setPeakLine(m_peakRetina, iRetina);

//     // ── axis range ───────────────────────────────────────────────────────────
//     double maxAmp = *std::max_element(samples.constBegin(), samples.constEnd());
//     m_axisX->setRange(0, al * 1.05);
//     m_axisY->setRange(0, std::max(maxAmp * 1.1, 60.0));
// }

// // ─────────────────────────────────────────────────────────────────────────────
// //  Decode readingdata blob
// //  The field is stored as a BLOB of raw 8-bit unsigned samples,
// //  or as a comma-separated text string "12,45,200,…"
// // ─────────────────────────────────────────────────────────────────────────────
// QVector<double> WaveformDialog::decodeReadingData(const QByteArray &raw)
// {
//     QVector<double> out;
//     if (raw.isEmpty()) return out;

//     // Try text CSV first
//     QString text = QString::fromLatin1(raw).trimmed();
//     if (text.contains(',')) {
//         const QStringList parts = text.split(',', Qt::SkipEmptyParts);
//         out.reserve(parts.size());
//         for (const QString &p : parts) {
//             bool ok = false;
//             double v = p.trimmed().toDouble(&ok);
//             if (ok) out.append(v);
//         }
//         if (!out.isEmpty()) return out;
//     }

//     // Fall back: treat as raw uint8 binary
//     out.reserve(raw.size());
//     for (unsigned char c : raw)
//         out.append(static_cast<double>(c));

//     return out;
// }

// // ─────────────────────────────────────────────────────────────────────────────
// //  Slots
// // ─────────────────────────────────────────────────────────────────────────────
// void WaveformDialog::onReadingChanged(int index)
// {
//     if (index < 0) return;
//     int readingNo = m_readingCbo->itemData(index).toInt();
//     loadAndPlot(readingNo);
// }

// void WaveformDialog::onExportClicked()
// {
//     QString path = QFileDialog::getSaveFileName(this, "Export waveform",
//                                                 QString(), "CSV files (*.csv)");
//     if (path.isEmpty()) return;

//     QFile f(path);
//     if (!f.open(QIODevice::WriteOnly | QIODevice::Text)) {
//         QMessageBox::warning(this, "Export failed", f.errorString());
//         return;
//     }
//     QTextStream ts(&f);
//     ts << "distance_mm,amplitude\n";
//     const auto &pts = m_series->pointsVector();
//     for (const QPointF &p : pts)
//         ts << QString::number(p.x(), 'f', 4) << ","
//            << QString::number(p.y(), 'f', 1) << "\n";

//     QMessageBox::information(this, "Exported",
//                              QString("Saved %1 points to:\n%2")
//                                  .arg(pts.size()).arg(path));
// }
