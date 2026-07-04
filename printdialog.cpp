// #include "printdialog.h"
// #include "ui_printdialog.h"
// #include "promptdialog.h"

// #include <QDir>
// #include <QFile>
// #include <QSqlQuery>
// #include <QSqlError>
// #include <QDateTime>
// #include <QPainter>
// #include <QFont>
// #include <QFontMetrics>
// #include <QScrollBar>
// #include <QVBoxLayout>
// #include <QResizeEvent>
// #include <cmath>
// #include <algorithm>
// #include "AppManager.h"

// // ── POSIX serial I/O (QSerialPort is unavailable on this cross-compile
// //    toolchain, so the tty is opened/configured directly) ──────────────────
// #include <fcntl.h>
// #include <termios.h>
// #include <unistd.h>
// #include <errno.h>
// #include <QApplication>

// // ─────────────────────────────────────────────────────────────────────────────
// //  ESC/POS helpers  (58 mm paper, 384 px wide, 32 char columns)
// // ─────────────────────────────────────────────────────────────────────────────
// namespace EscPos {
// static constexpr int W = 32;

// static const QByteArray INIT      = QByteArray("\x1B\x40",       2);
// static const QByteArray BOLD_ON   = QByteArray("\x1B\x45\x01",   3);
// static const QByteArray BOLD_OFF  = QByteArray("\x1B\x45\x00",   3);
// static const QByteArray ALIGN_L   = QByteArray("\x1B\x61\x00",   3);
// static const QByteArray ALIGN_C   = QByteArray("\x1B\x61\x01",   3);
// static const QByteArray FEED_3    = QByteArray("\x1B\x64\x03",   3);
// static const QByteArray CUT_FULL  = QByteArray("\x1D\x56\x00",   3);

// // Raster image mode header for one stripe
// static QByteArray rasterHeader(int widthPx, int heightPx)
// {
//     // GS v 0 m xL xH yL yH — store raster image
//     int wBytes = (widthPx + 7) / 8;
//     QByteArray h;
//     h.append('\x1D'); h.append('v'); h.append('0'); h.append('\x00');
//     h.append(static_cast<char>(wBytes & 0xFF));
//     h.append(static_cast<char>((wBytes >> 8) & 0xFF));
//     h.append(static_cast<char>(heightPx & 0xFF));
//     h.append(static_cast<char>((heightPx >> 8) & 0xFF));
//     return h;
// }

// static QString rule(char c = '-') { return QString(W, c) + "\r\n"; }

// static QString centre(const QString &s, int w = W) {
//     if (s.length() >= w) return s.left(w) + "\r\n";
//     int pad = (w - s.length()) / 2;
//     return QString(pad, ' ') + s + "\r\n";
// }
// } // namespace EscPos

// // ─────────────────────────────────────────────────────────────────────────────
// //  Constructor / Destructor
// // ─────────────────────────────────────────────────────────────────────────────
// PrintDialog::PrintDialog(QWidget *parent)
//     : QDialog(parent)
//     , ui(new Ui::PrintDialog)
//     , clockTimer(new QTimer(this))
//     , db(QSqlDatabase::database())
//     , m_previewTimer(new QTimer(this))
// {
//     ui->setupUi(this);
//     setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

//     connect(clockTimer, &QTimer::timeout, this, &PrintDialog::updateTime);
//     clockTimer->start(1000);
//     updateTime();

//     connect(m_previewTimer, &QTimer::timeout, this, &PrintDialog::onPreviewTick);

//     setupLivePreview();
//     showPage(PAGE_MENU);
// }

// PrintDialog::~PrintDialog()
// {
//     if (m_printTimer) {
//         m_printTimer->stop();
//     }
//     if (m_printFd >= 0) {
//         ::close(m_printFd);
//         m_printFd = -1;
//     }
//     delete ui;
// }

// // ─────────────────────────────────────────────────────────────────────────────
// //  Setters
// // ─────────────────────────────────────────────────────────────────────────────
// void PrintDialog::setPatientId(const QString &id) { m_patientId = id; }
// void PrintDialog::setDoctorId (const QString &id) { m_doctorId  = id; }

// void PrintDialog::setScanContext(const ScanContext &ctx)
// {
//     m_scanCtx    = ctx;
//     m_hasScanCtx = true;
// }
// void PrintDialog::setCalcContext(const CalcContext &ctx)
// {
//     m_calcCtx    = ctx;
//     m_hasCalcCtx = true;
// }

// void PrintDialog::resetContext()
// {
//     m_hasScanCtx   = false;
//     m_hasCalcCtx   = false;
//     m_autoPageDone = false;
//     m_scanContent.clear();
//     m_calcContent.clear();
//     m_scanEscPos.clear();
//     m_calcEscPos.clear();
//     m_lastWavePixmap = QPixmap();
// }

// // ─────────────────────────────────────────────────────────────────────────────
// //  showEvent / resizeEvent
// // ─────────────────────────────────────────────────────────────────────────────
// void PrintDialog::showEvent(QShowEvent *event)
// {
//     QDialog::showEvent(event);
//     if (m_autoPageDone) return;
//     m_autoPageDone = true;

//     if (m_hasScanCtx && m_hasCalcCtx) {
//         m_scanContent = buildScanContent();
//         m_calcContent = buildCalcContent();
//         ui->plainTextEdit_all->setPlainText(m_scanContent + "\n" + m_calcContent);
//         showPage(PAGE_BOTH);
//     } else if (m_hasScanCtx) {
//         m_scanContent = buildScanContent();
//         ui->plainTextEdit_scan->setPlainText(m_scanContent);
//         showPage(PAGE_SCAN);
//     } else if (m_hasCalcCtx) {
//         m_calcContent = buildCalcContent();
//         ui->plainTextEdit_calc->setPlainText(m_calcContent);
//         showPage(PAGE_CALC);
//     }
// }

// void PrintDialog::resizeEvent(QResizeEvent *event)
// {
//     QDialog::resizeEvent(event);
//     repositionPreviewWidgets();
// }

// // ─────────────────────────────────────────────────────────────────────────────
// //  Clock
// // ─────────────────────────────────────────────────────────────────────────────
// void PrintDialog::updateTime()
// {
//     ui->lbl_time->setText(QTime::currentTime().toString("hh:mm"));
// }

// void PrintDialog::showPage(int index)
// {
//     ui->stackedWidget->setCurrentIndex(index);
// }

// // ─────────────────────────────────────────────────────────────────────────────
// //  DB helpers
// // ─────────────────────────────────────────────────────────────────────────────
// QString PrintDialog::savedPrinterPort()
// {
//     if (db.isOpen()) {
//         QSqlQuery q(db);
//         q.prepare("SELECT printeraddress FROM preferences LIMIT 1");
//         if (q.exec() && q.next()) {
//             QString p = q.value(0).toString().trimmed();
//             if (!p.isEmpty()) return p;
//         }
//     }
//     return QStringLiteral("/dev/ttyUL1");
// }

// QString PrintDialog::fetchHospitalName()
// {
//     if (!db.isOpen()) return QString();
//     QSqlQuery q(db);
//     q.prepare("SELECT hospitalname FROM preferences LIMIT 1");
//     if (q.exec() && q.next())
//         return q.value(0).toString().trimmed();
//     return QString();
// }

// // ─────────────────────────────────────────────────────────────────────────────
// //  configureSerialPort
// //  Puts the tty into raw 9600-8N1 mode via termios. QFile alone does NOT
// //  configure the line discipline, so without this the CSN-A2 either gets
// //  garbled bytes or the write can hang depending on the port's prior state.
// // ─────────────────────────────────────────────────────────────────────────────
// bool PrintDialog::configureSerialPort(int fd)
// {
//     struct termios tty;
//     if (tcgetattr(fd, &tty) != 0) {
//         qDebug() << "PrintDialog: tcgetattr failed, errno" << errno;
//         return false;
//     }

//     cfsetospeed(&tty, B9600);
//     cfsetispeed(&tty, B9600);

//     tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;   // 8 data bits
//     tty.c_cflag &= ~PARENB;                       // no parity
//     tty.c_cflag &= ~CSTOPB;                       // 1 stop bit
//     tty.c_cflag &= ~CRTSCTS;                      // no HW flow control
//     tty.c_cflag |= (CLOCAL | CREAD);              // ignore modem lines, enable RX

//     tty.c_lflag = 0;                              // raw mode: no echo/canonical/signals
//     tty.c_iflag &= ~(IXON | IXOFF | IXANY);       // no SW flow control
//     tty.c_iflag &= ~(ICRNL | INLCR);              // don't translate CR/NL on input
//     tty.c_oflag = 0;                              // raw output, no translation

//     tty.c_cc[VMIN]  = 0;
//     tty.c_cc[VTIME] = 5;

//     if (tcsetattr(fd, TCSANOW, &tty) != 0) {
//         qDebug() << "PrintDialog: tcsetattr failed, errno" << errno;
//         return false;
//     }
//     tcflush(fd, TCIOFLUSH);
//     return true;
// }

// // ─────────────────────────────────────────────────────────────────────────────
// //  onPrintTimerTick
// //  Sends the pending print buffer to the configured tty fd in small,
// //  printer-buffer-friendly chunks so the UI thread never blocks on the
// //  slow 9600-baud link (mirrors the old sendToPrinterSafe/printTimer
// //  pattern that was known to work).
// // ─────────────────────────────────────────────────────────────────────────────
// void PrintDialog::onPrintTimerTick()
// {
//     if (m_printFd < 0 || m_printIndex >= m_printBuffer.size()) {
//         m_printTimer->stop();
//         if (m_printFd >= 0) {
//             ::close(m_printFd);
//             m_printFd = -1;
//         }
//         return;
//     }

//     const int chunkSize = 256; // CSN-A2 internal buffer-friendly chunk size
//     int remaining = m_printBuffer.size() - m_printIndex;
//     int n = qMin(chunkSize, remaining);

//     ssize_t written = ::write(m_printFd,
//                               m_printBuffer.constData() + m_printIndex, n);
//     if (written < 0) {
//         if (errno == EAGAIN || errno == EWOULDBLOCK) {
//             return; // try again next tick
//         }
//         qDebug() << "PrintDialog: serial write error, errno" << errno << "— aborting print";
//         m_printTimer->stop();
//         ::close(m_printFd);
//         m_printFd = -1;
//         return;
//     }

//     m_printIndex += static_cast<int>(written);
// }

// // ─────────────────────────────────────────────────────────────────────────────
// //  setupLivePreview
// //  Creates a QScrollArea + QLabel + status label + close button, all
// //  parented to the dialog. Positioned on the right side.
// // ─────────────────────────────────────────────────────────────────────────────
// void PrintDialog::setupLivePreview()
// {
//     m_previewScroll = new QScrollArea(this);
//     m_previewScroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//     m_previewScroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
//     m_previewScroll->setStyleSheet("background: white; border: 2px solid #888;");

//     m_previewLabel = new QLabel(m_previewScroll);
//     m_previewLabel->setAlignment(Qt::AlignTop | Qt::AlignLeft);
//     m_previewScroll->setWidget(m_previewLabel);

//     m_previewStatus = new QLabel(this);
//     m_previewStatus->setAlignment(Qt::AlignCenter);
//     m_previewStatus->setStyleSheet(
//         "background:#333; color:white; border-radius:4px; padding:2px 6px; font-weight:bold;");
//     m_previewStatus->setText("Printing...");

//     m_previewCloseBtn = new QPushButton(QStringLiteral("\u2715"), this); // ✕
//     m_previewCloseBtn->setFixedSize(28, 28);
//     m_previewCloseBtn->setCursor(Qt::PointingHandCursor);
//     m_previewCloseBtn->setStyleSheet(
//         "QPushButton { background:#d9534f; color:white; border:none; border-radius:14px; "
//         "font-weight:bold; } "
//         "QPushButton:hover { background:#c9302c; } "
//         "QPushButton:pressed { background:#ac2925; }");
//     connect(m_previewCloseBtn, &QPushButton::clicked, this, &PrintDialog::onPreviewClose);

//     // Start hidden — becomes visible when printing starts
//     m_previewScroll->hide();
//     m_previewStatus->hide();
//     m_previewCloseBtn->hide();

//     repositionPreviewWidgets();
// }

// // ─────────────────────────────────────────────────────────────────────────────
// //  repositionPreviewWidgets
// //  Keeps the preview panel, status chip, and close button geometry in sync
// //  with the dialog size (called from setupLivePreview + resizeEvent).
// // ─────────────────────────────────────────────────────────────────────────────
// void PrintDialog::repositionPreviewWidgets()
// {
//     if (!m_previewScroll) return;

//     const int previewX = this->width() - PREVIEW_PX_W - 10;
//     const int previewY = 50;
//     const int previewW = PREVIEW_PX_W;
//     const int previewH = this->height() - 60;

//     m_previewScroll->setGeometry(previewX, previewY, previewW, previewH);

//     if (m_previewStatus) {
//         m_previewStatus->setGeometry(previewX, previewY - 26, previewW - 36, 22);
//     }
//     if (m_previewCloseBtn) {
//         m_previewCloseBtn->setGeometry(previewX + previewW - 28, previewY - 32, 28, 28);
//     }
// }

// // ─────────────────────────────────────────────────────────────────────────────
// //  onPreviewClose
// //  Stops the animation timer and hides the whole preview panel.
// // ─────────────────────────────────────────────────────────────────────────────
// void PrintDialog::onPreviewClose()
// {
//     m_previewTimer->stop();
//     m_previewScroll->hide();
//     m_previewStatus->hide();
//     m_previewCloseBtn->hide();
// }

// // ─────────────────────────────────────────────────────────────────────────────
// //  ensureReceiptPixmapCapacity
// //  Grows m_receiptPixmap if we are about to draw past its bottom.
// // ─────────────────────────────────────────────────────────────────────────────
// void PrintDialog::ensureReceiptPixmapCapacity(int neededY)
// {
//     if (neededY <= m_receiptPixmap.height()) return;

//     int newH = neededY + 400; // grow in chunks
//     QPixmap grown(PREVIEW_PX_W, newH);
//     grown.fill(Qt::white);

//     if (!m_receiptPixmap.isNull()) {
//         QPainter p(&grown);
//         p.drawPixmap(0, 0, m_receiptPixmap);
//     }
//     m_receiptPixmap = grown;
// }

// // ─────────────────────────────────────────────────────────────────────────────
// //  startPreviewAnimation
// //  Splits plainText into lines, resets state, starts the timer.
// //  waveAfterLine: insert waveform pixmap after this many lines (-1 = never).
// // ─────────────────────────────────────────────────────────────────────────────
// void PrintDialog::startPreviewAnimation(const QString &plainText,
//                                         const QPixmap &wavePixmap,
//                                         int            waveAfterLine)
// {
//     m_previewTimer->stop();

//     // Split preserving blank lines
//     m_previewLines      = plainText.split('\n');
//     m_previewLineIdx    = 0;
//     m_previewY          = 8; // top margin
//     m_wavePixmap        = wavePixmap;
//     m_waveInserted      = false;
//     m_waveInsertAtLine  = waveAfterLine;

//     // Fresh white receipt
//     m_receiptPixmap = QPixmap(PREVIEW_PX_W, 600);
//     m_receiptPixmap.fill(Qt::white);

//     m_previewLabel->setPixmap(m_receiptPixmap);
//     m_previewLabel->resize(PREVIEW_PX_W, 600);

//     m_previewStatus->setText("Printing...");
//     m_previewStatus->show();
//     m_previewStatus->raise();

//     m_previewCloseBtn->show();
//     m_previewCloseBtn->raise();

//     m_previewScroll->show();
//     m_previewScroll->raise();

//     m_previewTimer->start(PREVIEW_TICK_MS);
// }

// // ─────────────────────────────────────────────────────────────────────────────
// //  onPreviewTick — called every PREVIEW_TICK_MS ms
// //  Draws one text line (or the waveform block) onto m_receiptPixmap.
// // ─────────────────────────────────────────────────────────────────────────────
// void PrintDialog::onPreviewTick()
// {
//     // Check if we need to insert the waveform at this position
//     if (!m_waveInserted
//         && m_waveInsertAtLine >= 0
//         && m_previewLineIdx == m_waveInsertAtLine
//         && !m_wavePixmap.isNull())
//     {
//         m_waveInserted = true;

//         int wh = m_wavePixmap.height();
//         ensureReceiptPixmapCapacity(m_previewY + wh + 8);

//         QPainter p(&m_receiptPixmap);
//         // Draw waveform scaled to paper width
//         QPixmap scaled = m_wavePixmap.scaledToWidth(PREVIEW_PX_W,
//                                                     Qt::SmoothTransformation);
//         p.drawPixmap(0, m_previewY, scaled);
//         m_previewY += scaled.height() + 4;
//         p.end();

//         m_previewLabel->setPixmap(m_receiptPixmap.copy(0, 0,
//                                                        PREVIEW_PX_W, m_previewY + 4));
//         m_previewLabel->resize(PREVIEW_PX_W, m_previewY + 4);

//         // Scroll to bottom
//         m_previewScroll->verticalScrollBar()->setValue(
//             m_previewScroll->verticalScrollBar()->maximum());
//         return; // let next tick handle the next text line
//     }

//     if (m_previewLineIdx >= m_previewLines.size()) {
//         m_previewTimer->stop();
//         m_previewStatus->setText("Done");
//         return;
//     }

//     QString line = m_previewLines.at(m_previewLineIdx);
//     // Strip \r if present
//     line.remove('\r');
//     ++m_previewLineIdx;

//     // Separator lines → draw a horizontal rule
//     bool isRule = (!line.isEmpty()
//                    && (line.count(line[0]) == line.length())
//                    && (line[0] == '=' || line[0] == '-' || line[0] == '.'));

//     ensureReceiptPixmapCapacity(m_previewY + LINE_H_PX + 4);

//     QPainter p(&m_receiptPixmap);
//     p.setRenderHint(QPainter::Antialiasing, false);

//     if (isRule) {
//         int midY = m_previewY + LINE_H_PX / 2;
//         QPen pen(line[0] == '=' ? Qt::black : QColor(160, 160, 160));
//         pen.setWidth(line[0] == '=' ? 2 : 1);
//         if (line[0] == '.') {
//             pen.setStyle(Qt::DotLine);
//             pen.setColor(Qt::gray);
//         }
//         p.setPen(pen);
//         p.drawLine(4, midY, PREVIEW_PX_W - 4, midY);
//         m_previewY += LINE_H_PX;
//     } else {
//         QFont font("Courier", 9);
//         font.setFixedPitch(true);

//         // Detect header / bold lines by content heuristics
//         bool isBold = (line.startsWith("Patient") || line.startsWith("Doctor")
//                        || line.startsWith("Eye") || line.startsWith("AVG")
//                        || line.startsWith("AL ") || line.startsWith("EMM"));

//         bool isCentre = (line.trimmed().startsWith("AcuAxis")
//                          || line.trimmed().startsWith("IOL CALC")
//                          || line.trimmed().startsWith("A-SCAN")
//                          || line.trimmed().startsWith("Patient Details"));

//         font.setBold(isBold);
//         p.setFont(font);
//         p.setPen(Qt::black);

//         QRect rect(4, m_previewY, PREVIEW_PX_W - 8, LINE_H_PX);
//         Qt::Alignment align = isCentre ? Qt::AlignHCenter : Qt::AlignLeft;
//         p.drawText(rect, align | Qt::AlignVCenter, line);
//         m_previewY += LINE_H_PX;
//     }
//     p.end();

//     // Update label with the grown portion
//     m_previewLabel->setPixmap(m_receiptPixmap.copy(0, 0,
//                                                    PREVIEW_PX_W, m_previewY + 4));
//     m_previewLabel->resize(PREVIEW_PX_W, m_previewY + 4);

//     // Auto-scroll to bottom so it looks like paper feeding
//     m_previewScroll->verticalScrollBar()->setValue(
//         m_previewScroll->verticalScrollBar()->maximum());
// }

// // ─────────────────────────────────────────────────────────────────────────────
// //  doPrint
// //  1. Opens + configures the tty via termios, then streams rawEscPos to it
// //     in small non-blocking chunks via m_printTimer (QSerialPort is not
// //     available on this cross-compile toolchain).
// //  2. Kicks off the live preview animation.
// // ─────────────────────────────────────────────────────────────────────────────
// void PrintDialog::doPrint(const QByteArray &rawEscPos,
//                           const QString    &plainText,
//                           const QPixmap    &wavePixmap)
// {
//     if (rawEscPos.isEmpty()) {
//         qDebug() << "PrintDialog::doPrint — nothing to print.";
//         return;
//     }

//     // ── 1. Physical print ─────────────────────────────────────────────────
//     QString portName = savedPrinterPort();
//     if (portName.isEmpty()) portName = "/dev/ttyUL1";

//     qDebug() << "PrintDialog: sending" << rawEscPos.size() << "bytes to" << portName;

//     int fd = ::open(portName.toLocal8Bit().constData(),
//                     O_WRONLY | O_NOCTTY | O_NONBLOCK);
//     if (fd < 0) {
//         qDebug() << "PrintDialog: cannot open" << portName << "errno" << errno;
//         PromptDialog err("Print Error",
//                          "Cannot open " + portName + ".\nCheck port in Preferences.", this);
//         err.exec();
//         // Still show preview even if port open fails (useful during development)
//     } else if (!configureSerialPort(fd)) {
//         qDebug() << "PrintDialog: failed to configure" << portName;
//         ::close(fd);
//         PromptDialog err("Print Error",
//                          "Cannot configure " + portName + ".", this);
//         err.exec();
//     } else {
//         // Line is configured — switch back to blocking writes so partial
//         // writes don't silently drop bytes, then stream in chunks via timer.
//         int flags = fcntl(fd, F_GETFL, 0);
//         fcntl(fd, F_SETFL, flags & ~O_NONBLOCK);

//         if (m_printTimer) {
//             m_printTimer->stop();
//         } else {
//             m_printTimer = new QTimer(this);
//             connect(m_printTimer, &QTimer::timeout, this, &PrintDialog::onPrintTimerTick);
//         }
//         if (m_printFd >= 0) {
//             ::close(m_printFd);
//         }

//         m_printFd     = fd;
//         m_printBuffer = rawEscPos;
//         m_printIndex  = 0;
//         m_printTimer->start(5); // small chunks — keeps UI responsive at 9600 baud
//     }

//     // ── 2. Live preview ───────────────────────────────────────────────────
//     // Figure out at which text line the waveform should be inserted.
//     // We look for the separator line that comes just after "Rdg# : N" in the scan content.
//     int waveAfterLine = -1;
//     if (!wavePixmap.isNull()) {
//         QStringList lines = plainText.split('\n');
//         for (int i = 0; i < lines.size(); ++i) {
//             if (lines[i].startsWith("Rdg#") || lines[i].startsWith("Rdg :")) {
//                 // Insert waveform after the next separator
//                 for (int j = i + 1; j < lines.size(); ++j) {
//                     if (!lines[j].isEmpty()
//                         && lines[j].count(lines[j][0]) == lines[j].length()
//                         && (lines[j][0] == '-' || lines[j][0] == '='))
//                     {
//                         waveAfterLine = j + 1;
//                         break;
//                     }
//                 }
//                 break;
//             }
//         }
//         // Fallback: insert after header block (after first '----' line)
//         if (waveAfterLine < 0) {
//             QStringList lines2 = plainText.split('\n');
//             for (int i = 0; i < lines2.size(); ++i) {
//                 if (lines2[i].startsWith("----") || lines2[i].startsWith("================================")) {
//                     if (i > 3) { waveAfterLine = i + 1; break; }
//                 }
//             }
//         }
//     }

//     startPreviewAnimation(plainText, wavePixmap, waveAfterLine);
// }

// // ─────────────────────────────────────────────────────────────────────────────
// //  renderWaveformPixmap
// //  QCustomPlot-based renderer — single source of truth for the waveform
// //  image. Used both for the on-screen live preview AND as the source
// //  pixmap that gets converted to ESC/POS raster bytes for physical
// //  printing (see waveformToRasterBytes), so the two can never visually
// //  diverge.
// // ─────────────────────────────────────────────────────────────────────────────
// QPixmap PrintDialog::renderWaveformPixmap(const QVector<double> &samples,
//                                           int w, int h)
// {
//     if (samples.isEmpty()) return QPixmap();

//     QCustomPlot plot;
//     plot.setFixedSize(w, h);
//     plot.setAttribute(Qt::WA_DontShowOnScreen, true);
//     plot.show(); // forces internal layout without actually displaying

//     QVector<double> xData;
//     xData.reserve(samples.size());
//     for (int i = 0; i < samples.size(); ++i) xData.append(i);

//     plot.addGraph();
//     QPen pen(Qt::black);
//     pen.setWidth(1);
//     plot.graph(0)->setPen(pen);
//     plot.graph(0)->setData(xData, samples);

//     plot.xAxis->setVisible(false);
//     plot.yAxis->setVisible(false);
//     plot.yAxis->rescale(true);
//     plot.xAxis->setRange(0, samples.size() - 1);

//     QCPItemRect *border = new QCPItemRect(&plot);
//     border->setPen(QPen(Qt::black, 3));
//     border->setBrush(Qt::NoBrush);
//     border->topLeft->setCoords(plot.xAxis->range().lower, plot.yAxis->range().upper);
//     border->bottomRight->setCoords(plot.xAxis->range().upper, plot.yAxis->range().lower);

//     plot.replot();

//     QPixmap px(w, h);
//     px.fill(Qt::white);
//     plot.render(&px);

//     plot.hide();
//     return px;
// }

// // ─────────────────────────────────────────────────────────────────────────────
// //  waveformToRasterBytes
// //  Converts an already-rendered waveform pixmap → ESC/POS GS v 0 raster
// //  bytes. Does NOT redraw anything — it consumes whatever pixmap was
// //  produced by renderWaveformPixmap, guaranteeing the printed image and
// //  the previewed image are pixel-identical.
// //
// //  Uses a plain 50% threshold (matching the known-working
// //  convertToThermalRaster reference implementation) rather than dithering:
// //  dithered noise patterns can confuse some ESC/POS raster decoders.
// // ─────────────────────────────────────────────────────────────────────────────
// QByteArray PrintDialog::waveformToRasterBytes(const QPixmap &wavePixmap)
// {
//     if (wavePixmap.isNull()) return QByteArray();

//     QImage img = wavePixmap.toImage().convertToFormat(QImage::Format_Grayscale8);

//     const int w = img.width();
//     const int h = img.height();
//     const int wBytes = (w + 7) / 8;

//     QByteArray data;
//     data += EscPos::rasterHeader(w, h);

//     for (int y = 0; y < h; ++y) {
//         const uchar *line = img.constScanLine(y);
//         for (int xb = 0; xb < wBytes; ++xb) {
//             unsigned char byte = 0;
//             for (int bit = 0; bit < 8; ++bit) {
//                 int x = xb * 8 + bit;
//                 if (x < w) {
//                     // Dark pixel → set bit (print). Threshold at 128, same as
//                     // the working reference implementation.
//                     if (line[x] <= 128)
//                         byte |= (1 << (7 - bit));
//                 }
//             }
//             data.append(static_cast<char>(byte));
//         }
//     }
//     data.append("\r\n");
//     return data;
// }

// // ─────────────────────────────────────────────────────────────────────────────
// //  buildHeader  (plain text, existing logic unchanged)
// // ─────────────────────────────────────────────────────────────────────────────
// QString PrintDialog::buildHeader(const QString &title)
// {
//     QString patientName, doctorName;
//     const QString hospitalName = fetchHospitalName();

//     if (!m_patientId.isEmpty()) {
//         QSqlQuery q(db);
//         q.prepare("SELECT name FROM patient WHERE patientid = ?");
//         q.addBindValue(m_patientId);
//         if (q.exec() && q.next()) patientName = q.value(0).toString();
//     }
//     if (!m_doctorId.isEmpty()) {
//         QSqlQuery q(db);
//         q.prepare("SELECT name FROM doctor WHERE doctorid = ?");
//         q.addBindValue(m_doctorId);
//         if (q.exec() && q.next()) doctorName = q.value(0).toString();
//     }

//     QString out;
//     out += "================================\r\n";
//     if (!hospitalName.isEmpty()) {
//         QString h = hospitalName.left(30);
//         int pad = (32 - h.length()) / 2;
//         out += QString(pad, ' ') + h + "\r\n";
//     }
//     {
//         QString t = title.left(30);
//         int pad = (32 - t.length()) / 2;
//         out += QString(pad, ' ') + t + "\r\n";
//     }
//     out += "================================\r\n";
//     out += QString("Date : %1\r\n")
//                .arg(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm"));
//     out += "\r\n";
//     out += QString("Patient : %1\r\n").arg(patientName.isEmpty() ? "---" : patientName.left(22));
//     out += QString("ID      : %1\r\n").arg(m_patientId.isEmpty()  ? "---" : m_patientId.left(22));
//     out += "\r\n";
//     out += QString("Doctor  : %1\r\n").arg(doctorName.isEmpty() ? "---" : doctorName.left(22));
//     out += "--------------------------------\r\n";
//     return out;
// }

// // ─────────────────────────────────────────────────────────────────────────────
// //  buildScanEscPos
// //  Full ESC/POS binary stream for a scan report.
// //  Includes raster waveform image from readingdata.
// //  samplesOut → also returns the samples so preview can render them.
// // ─────────────────────────────────────────────────────────────────────────────
// QByteArray PrintDialog::buildScanEscPos(QVector<double> &samplesOut)
// {
//     samplesOut.clear();
//     m_lastWavePixmap = QPixmap();
//     if (!db.isOpen()) return QByteArray();

//     QByteArray b;
//     b += EscPos::INIT;
//     b += EscPos::ALIGN_L;

//     // Plain-text header (reuse existing)
//     b += buildHeader("A-SCAN BIOMETRY").toLocal8Bit();

//     const QStringList apLabels = { "APhakic", "Phakic", "DenseCat" };
//     const QStringList ciLabels = { "Contact", "Immersion" };

//     auto addLine = [&](const QString &s) { b += s.toLocal8Bit(); };

//     if (m_hasScanCtx) {
//         const QString eyeStr = (m_scanCtx.eye == 1) ? "OD" : "OS";
//         addLine(QString("Eye  : %1\r\n").arg(eyeStr));
//         addLine(QString("Mode : %1 / %2\r\n")
//                     .arg(apLabels.value(m_scanCtx.apmode,     "?"))
//                     .arg(ciLabels.value(m_scanCtx.conimmmode, "?")));
//         addLine(QString("Rdg# : %1\r\n").arg(m_scanCtx.readingNo));
//         addLine("--------------------------------\r\n");

//         // ── Fetch reading + waveform data ────────────────────────────────
//         QSqlQuery q(db);
//         q.prepare(R"(
//             SELECT al, acd, lt, vit, deviation, readingdata
//             FROM   reading
//             WHERE  patientid  = ?
//               AND  doctorid   = ?
//               AND  rleye      = ?
//               AND  apmode     = ?
//               AND  conimmmode = ?
//               AND  readingno  = ?
//         )");
//         q.addBindValue(m_patientId);
//         q.addBindValue(m_doctorId);
//         q.addBindValue(m_scanCtx.eye);
//         q.addBindValue(m_scanCtx.apmode);
//         q.addBindValue(m_scanCtx.conimmmode);
//         q.addBindValue(m_scanCtx.readingNo);

//         if (q.exec() && q.next()) {
//             const double  al   = q.value(0).toDouble();
//             const double  acd  = q.value(1).toDouble();
//             const double  lt   = q.value(2).toDouble();
//             const double  vit  = q.value(3).toDouble();
//             const double  dev  = q.value(4).toDouble();
//             const QString csv  = q.value(5).toString();

//             // ── Parse readingdata CSV → samples ───────────────────────
//             if (!csv.trimmed().isEmpty()) {
//                 for (const QString &tok : csv.split(',', Qt::SkipEmptyParts)) {
//                     bool ok = false;
//                     double v = tok.trimmed().toDouble(&ok);
//                     if (ok) samplesOut.append(v);
//                 }
//             }

//             // ── Raster waveform ───────────────────────────────────────
//             if (!samplesOut.isEmpty()) {
//                 // Render once via QCustomPlot — this exact pixmap is reused
//                 // for the live preview by the caller (see on_btn_scan2_clicked).
//                 m_lastWavePixmap = renderWaveformPixmap(samplesOut, PAPER_PX_W, 128);

//                 addLine("\r\n");
//                 b += waveformToRasterBytes(m_lastWavePixmap);
//                 addLine("\r\n");
//             }

//             addLine("--------------------------------\r\n");
//             b += EscPos::BOLD_ON;
//             addLine(QString("AL  : %1 mm\r\n").arg(al,  0, 'f', 2));
//             b += EscPos::BOLD_OFF;
//             addLine(QString("ACD : %1 mm\r\n").arg(acd, 0, 'f', 2));
//             addLine(QString("LT  : %1 mm\r\n").arg(lt,  0, 'f', 2));
//             addLine(QString("VIT : %1 mm\r\n").arg(vit, 0, 'f', 2));
//             addLine(QString("DEV : %1\r\n")   .arg(dev, 0, 'f', 3));
//         } else {
//             addLine("[Reading not found]\r\n");
//         }

//         // ── All readings summary ──────────────────────────────────────
//         addLine("--------------------------------\r\n");
//         addLine("All readings this session:\r\n");

//         QSqlQuery all(db);
//         all.prepare(R"(
//             SELECT readingno, al, deviation FROM reading
//             WHERE  patientid=? AND doctorid=? AND rleye=?
//               AND  apmode=? AND conimmmode=?
//             ORDER  BY readingno ASC
//         )");
//         all.addBindValue(m_patientId); all.addBindValue(m_doctorId);
//         all.addBindValue(m_scanCtx.eye);
//         all.addBindValue(m_scanCtx.apmode); all.addBindValue(m_scanCtx.conimmmode);

//         if (all.exec()) {
//             while (all.next()) {
//                 int    rno = all.value(0).toInt();
//                 double al  = all.value(1).toDouble();
//                 double dev = all.value(2).toDouble();
//                 bool   sel = (rno == m_scanCtx.readingNo);
//                 if (sel) b += EscPos::BOLD_ON;
//                 addLine(QString(" #%1  AL=%2  DEV=%3%4\r\n")
//                             .arg(rno).arg(al, 0,'f',2).arg(dev, 0,'f',3)
//                             .arg(sel ? " <" : "  "));
//                 if (sel) b += EscPos::BOLD_OFF;
//             }
//         }

//         // ── Group average + SD ────────────────────────────────────────
//         addLine("--------------------------------\r\n");
//         QSqlQuery avg(db);
//         avg.prepare(R"(
//             SELECT aval, stddeviation FROM reading
//             WHERE  patientid=? AND doctorid=? AND rleye=?
//               AND  apmode=? AND conimmmode=?
//             ORDER  BY readingno DESC LIMIT 1
//         )");
//         avg.addBindValue(m_patientId); avg.addBindValue(m_doctorId);
//         avg.addBindValue(m_scanCtx.eye);
//         avg.addBindValue(m_scanCtx.apmode); avg.addBindValue(m_scanCtx.conimmmode);
//         if (avg.exec() && avg.next()) {
//             b += EscPos::BOLD_ON;
//             addLine(QString("AVG AL : %1 mm\r\n").arg(avg.value(0).toDouble(), 0,'f',2));
//             b += EscPos::BOLD_OFF;
//             addLine(QString("SD     : %1\r\n")   .arg(avg.value(1).toDouble(), 0,'f',3));
//         }

//     } else {
//         // ── FALLBACK: full dump (no waveform) ────────────────────────
//         const QList<QPair<int,QString>> eyes    = {{1,"OD"},{0,"OS"}};
//         const QList<QPair<int,QString>> apmodes = {{0,"APhakic"},{1,"Phakic"},{2,"DenseCat"}};
//         const QList<QPair<int,QString>> cimodes = {{0,"Contact"},{1,"Immersion"}};

//         for (const auto &eye : eyes) {
//             bool eyeHasData = false;
//             for (const auto &ap : apmodes) {
//                 for (const auto &ci : cimodes) {
//                     QSqlQuery q(db);
//                     q.prepare(R"(
//                         SELECT readingno, al, deviation FROM reading
//                         WHERE  patientid=? AND doctorid=?
//                           AND  rleye=? AND apmode=? AND conimmmode=?
//                         ORDER  BY readingno ASC
//                     )");
//                     q.addBindValue(m_patientId); q.addBindValue(m_doctorId);
//                     q.addBindValue(eye.first); q.addBindValue(ap.first); q.addBindValue(ci.first);

//                     QStringList rows;
//                     if (q.exec())
//                         while (q.next())
//                             rows << QString(" #%1  AL=%2  DEV=%3")
//                                         .arg(q.value(0).toInt())
//                                         .arg(q.value(1).toDouble(), 0,'f',2)
//                                         .arg(q.value(2).toDouble(), 0,'f',3);

//                     if (rows.isEmpty()) continue;
//                     if (!eyeHasData) {
//                         b += EscPos::BOLD_ON;
//                         addLine(QString("\n--- %1 ---\r\n").arg(eye.second));
//                         b += EscPos::BOLD_OFF;
//                         eyeHasData = true;
//                     }
//                     addLine(QString("[%1 / %2]\r\n").arg(ap.second, ci.second));
//                     for (const QString &row : rows) addLine(row + "\r\n");

//                     QSqlQuery gavg(db);
//                     gavg.prepare(R"(
//                         SELECT aval, stddeviation FROM reading
//                         WHERE  patientid=? AND doctorid=?
//                           AND  rleye=? AND apmode=? AND conimmmode=?
//                         ORDER  BY readingno DESC LIMIT 1
//                     )");
//                     gavg.addBindValue(m_patientId); gavg.addBindValue(m_doctorId);
//                     gavg.addBindValue(eye.first); gavg.addBindValue(ap.first); gavg.addBindValue(ci.first);
//                     if (gavg.exec() && gavg.next())
//                         addLine(QString(" AVG=%1  SD=%2\r\n")
//                                     .arg(gavg.value(0).toDouble(), 0,'f',2)
//                                     .arg(gavg.value(1).toDouble(), 0,'f',3));
//                     addLine("................................\r\n");
//                 }
//             }
//         }
//     }

//     addLine("================================\r\n");
//     b += EscPos::FEED_3;
//     b += EscPos::CUT_FULL;
//     return b;
// }

// // ─────────────────────────────────────────────────────────────────────────────
// //  buildCalcEscPos  (unchanged logic, just wrapped in ESC/POS)
// // ─────────────────────────────────────────────────────────────────────────────
// QByteArray PrintDialog::buildCalcEscPos()
// {
//     if (!db.isOpen()) return QByteArray();

//     QByteArray b;
//     b += EscPos::INIT;
//     b += EscPos::ALIGN_L;
//     b += buildHeader("IOL CALCULATION").toLocal8Bit();

//     struct FE { iol::Formula f; QString label; };
//     const QList<FE> allFormulas = {
//                                    { iol::Formula::SRKII,    "SRK II"   },
//                                    { iol::Formula::SRKT,     "SRK/T"    },
//                                    { iol::Formula::HofferQ,  "Hoffer Q" },
//                                    { iol::Formula::Holladay, "Holladay" },
//                                    };

//     auto addLine = [&](const QString &s) { b += s.toLocal8Bit(); };

//     auto getK = [&](int eye, double &k1, double &k2, double &kAvg) {
//         k1 = k2 = kAvg = 0.0;
//         QSqlQuery q(db);
//         q.prepare(eye == 1
//                       ? "SELECT rk1, rk2 FROM patient WHERE patientid = ?"
//                       : "SELECT lk1, lk2 FROM patient WHERE patientid = ?");
//         q.addBindValue(m_patientId);
//         if (q.exec() && q.next()) { k1 = q.value(0).toDouble(); k2 = q.value(1).toDouble(); }
//         kAvg = (k1 > 0 && k2 > 0) ? (k1 + k2) / 2.0 : 43.5;
//         if (k1 <= 0 && k2 <= 0) k1 = k2 = 43.5;
//     };

//     auto bestAL = [&](int eye) -> double {
//         QSqlQuery q(db);
//         q.prepare(R"(SELECT al FROM reading
//                      WHERE patientid=? AND doctorid=? AND rleye=?
//                        AND apmode=1 AND conimmmode=0
//                      ORDER BY deviation ASC LIMIT 1)");
//         q.addBindValue(m_patientId); q.addBindValue(m_doctorId); q.addBindValue(eye);
//         if (q.exec() && q.next()) return q.value(0).toDouble();
//         return 0.0;
//     };

//     auto runLens = [&](int rowid, const FE &fe, double al, double k) {
//         if (rowid < 0) return;
//         QSqlQuery lq(db);
//         lq.prepare("SELECT iol, company, asrkt, asrkii, acd, sf FROM lens WHERE id=?");
//         lq.addBindValue(rowid);
//         if (!lq.exec() || !lq.next()) return;

//         QString lensName = lq.value(0).toString();
//         QString company  = lq.value(1).toString();
//         double asrkt = lq.value(2).toDouble(), asrkii = lq.value(3).toDouble();
//         double pacd  = lq.value(4).toDouble(), sf     = lq.value(5).toDouble();

//         b += EscPos::BOLD_ON;
//         addLine(company.isEmpty()
//                     ? QString("Lens : %1\r\n").arg(lensName.left(26))
//                     : QString("Lens : %1 (%2)\r\n").arg(lensName.left(18)).arg(company.left(8)));
//         b += EscPos::BOLD_OFF;

//         if (al <= 0.0) { addLine("  No biometry data\r\n"); return; }

//         iol::Input inp;
//         inp.formula = fe.f; inp.axialLength = al; inp.k = k; inp.targetRx = 0.0;
//         switch (fe.f) {
//         case iol::Formula::SRKII:    inp.aConstant = asrkii; break;
//         case iol::Formula::SRKT:     inp.aConstant = asrkt;  break;
//         case iol::Formula::HofferQ:  inp.aConstant = pacd;   break;
//         case iol::Formula::Holladay: inp.aConstant = sf;     break;
//         default:                     inp.aConstant = asrkii; break;
//         }

//         iol::IOLCalculator calc;
//         iol::Result res = calc.calculate(inp);
//         if (!res.valid) { addLine("  Calculation error\r\n"); return; }

//         b += EscPos::BOLD_ON;
//         addLine(QString("EMM  : %1 D\r\n").arg(res.pEmmetropia, 0,'f',2));
//         b += EscPos::BOLD_OFF;
//         addLine("IOL  :");
//         for (int i = 0; i < 5; ++i)
//             addLine(QString(" %1").arg(res.iolPower[i], 5,'f',2));
//         addLine("\r\n");
//         addLine("Ref  :");
//         for (int i = 0; i < 5; ++i)
//             addLine(QString(" %1").arg(res.predictedRx[i], 5,'f',2));
//         addLine("\r\n");
//     };

//     if (m_hasCalcCtx) {
//         double k1, k2, kAvg;
//         getK(m_calcCtx.eye, k1, k2, kAvg);
//         double al = bestAL(m_calcCtx.eye);
//         int fIdx = qBound(0, m_calcCtx.formulaIndex, allFormulas.size() - 1);
//         const FE &fe = allFormulas[fIdx];
//         const QString eyeStr = (m_calcCtx.eye == 1) ? "OD" : "OS";

//         b += EscPos::BOLD_ON;
//         addLine(QString("Eye     : %1\r\n").arg(eyeStr));
//         b += EscPos::BOLD_OFF;
//         addLine(QString("K1      : %1 D\r\n").arg(k1,   0,'f',2));
//         addLine(QString("K2      : %1 D\r\n").arg(k2,   0,'f',2));
//         addLine(QString("K avg   : %1 D\r\n").arg(kAvg, 0,'f',2));
//         b += EscPos::BOLD_ON;
//         addLine(QString("AL      : %1 mm\r\n").arg(al,  0,'f',2));
//         b += EscPos::BOLD_OFF;
//         addLine(QString("Formula : %1\r\n").arg(fe.label));
//         addLine("--------------------------------\r\n");

//         bool anyLens = false;
//         for (int rowid : {m_calcCtx.lensRowidOne,
//                           m_calcCtx.lensRowidTwo,
//                           m_calcCtx.lensRowidThree}) {
//             if (rowid < 0) continue;
//             anyLens = true;
//             runLens(rowid, fe, al, kAvg);
//             addLine("................................\r\n");
//         }
//         if (!anyLens) addLine("  [No lens selected]\r\n");

//     } else {
//         for (int eye : {1, 0}) {
//             double k1, k2, kAvg;
//             getK(eye, k1, k2, kAvg);
//             double al = bestAL(eye);
//             const QString eyeStr = (eye == 1) ? "OD" : "OS";

//             b += EscPos::BOLD_ON;
//             addLine(QString("\n--- %1 ---\r\n").arg(eyeStr));
//             b += EscPos::BOLD_OFF;
//             addLine(QString("K1=%1 K2=%2 K=%3 D\r\n")
//                         .arg(k1,0,'f',2).arg(k2,0,'f',2).arg(kAvg,0,'f',2));
//             addLine(QString("AL=%1 mm\r\n").arg(al, 0,'f',2));
//             addLine("--------------------------------\r\n");

//             QSqlQuery lq(db);
//             lq.prepare("SELECT id FROM lens ORDER BY iol ASC");
//             if (!lq.exec()) continue;
//             while (lq.next()) {
//                 int rowid = lq.value(0).toInt();
//                 for (const auto &fe : allFormulas) {
//                     addLine(QString("[%1]\r\n").arg(fe.label));
//                     runLens(rowid, fe, al, kAvg);
//                 }
//                 addLine("................................\r\n");
//             }
//         }
//     }

//     addLine("================================\r\n");
//     b += EscPos::FEED_3;
//     b += EscPos::CUT_FULL;
//     return b;
// }

// // ─────────────────────────────────────────────────────────────────────────────
// //  buildScanContent / buildCalcContent  (plain text, for QPlainTextEdit)
// // ─────────────────────────────────────────────────────────────────────────────
// QString PrintDialog::buildScanContent()
// {
//     if (!db.isOpen()) return QString();

//     QString out = buildHeader("A-SCAN BIOMETRY");
//     const QStringList apLabels = { "APhakic", "Phakic", "DenseCat" };
//     const QStringList ciLabels = { "Contact", "Immersion" };

//     if (m_hasScanCtx) {
//         const QString eyeStr = (m_scanCtx.eye == 1) ? "OD" : "OS";
//         out += QString("Eye  : %1\r\n").arg(eyeStr);
//         out += QString("Mode : %1 / %2\r\n")
//                    .arg(apLabels.value(m_scanCtx.apmode,     "?"))
//                    .arg(ciLabels.value(m_scanCtx.conimmmode, "?"));
//         out += QString("Rdg# : %1\r\n").arg(m_scanCtx.readingNo);
//         out += "--------------------------------\r\n";

//         QSqlQuery q(db);
//         q.prepare(R"(
//             SELECT al, acd, lt, vit, deviation FROM reading
//             WHERE  patientid=? AND doctorid=? AND rleye=?
//               AND  apmode=? AND conimmmode=? AND readingno=?
//         )");
//         q.addBindValue(m_patientId); q.addBindValue(m_doctorId);
//         q.addBindValue(m_scanCtx.eye); q.addBindValue(m_scanCtx.apmode);
//         q.addBindValue(m_scanCtx.conimmmode); q.addBindValue(m_scanCtx.readingNo);

//         if (q.exec() && q.next()) {
//             out += QString("AL  : %1 mm\r\n").arg(q.value(0).toDouble(), 0,'f',2);
//             out += QString("ACD : %1 mm\r\n").arg(q.value(1).toDouble(), 0,'f',2);
//             out += QString("LT  : %1 mm\r\n").arg(q.value(2).toDouble(), 0,'f',2);
//             out += QString("VIT : %1 mm\r\n").arg(q.value(3).toDouble(), 0,'f',2);
//             out += QString("DEV : %1\r\n")   .arg(q.value(4).toDouble(), 0,'f',3);
//         } else {
//             out += "[Reading not found in DB]\r\n";
//         }

//         out += "--------------------------------\r\n";
//         out += "All readings this session:\r\n";

//         QSqlQuery all(db);
//         all.prepare(R"(
//             SELECT readingno, al, deviation FROM reading
//             WHERE  patientid=? AND doctorid=? AND rleye=?
//               AND  apmode=? AND conimmmode=?
//             ORDER  BY readingno ASC
//         )");
//         all.addBindValue(m_patientId); all.addBindValue(m_doctorId);
//         all.addBindValue(m_scanCtx.eye);
//         all.addBindValue(m_scanCtx.apmode); all.addBindValue(m_scanCtx.conimmmode);

//         if (all.exec())
//             while (all.next()) {
//                 int rno = all.value(0).toInt();
//                 out += QString(" #%1  AL=%2  DEV=%3%4\r\n")
//                            .arg(rno)
//                            .arg(all.value(1).toDouble(), 0,'f',2)
//                            .arg(all.value(2).toDouble(), 0,'f',3)
//                            .arg(rno == m_scanCtx.readingNo ? " <" : "  ");
//             }

//         out += "--------------------------------\r\n";
//         QSqlQuery avg(db);
//         avg.prepare(R"(
//             SELECT aval, stddeviation FROM reading
//             WHERE  patientid=? AND doctorid=? AND rleye=?
//               AND  apmode=? AND conimmmode=?
//             ORDER  BY readingno DESC LIMIT 1
//         )");
//         avg.addBindValue(m_patientId); avg.addBindValue(m_doctorId);
//         avg.addBindValue(m_scanCtx.eye);
//         avg.addBindValue(m_scanCtx.apmode); avg.addBindValue(m_scanCtx.conimmmode);
//         if (avg.exec() && avg.next()) {
//             out += QString("AVG AL : %1 mm\r\n").arg(avg.value(0).toDouble(), 0,'f',2);
//             out += QString("SD     : %1\r\n")   .arg(avg.value(1).toDouble(), 0,'f',3);
//         }
//     } else {
//         const QList<QPair<int,QString>> eyes    = {{1,"OD"},{0,"OS"}};
//         const QList<QPair<int,QString>> apmodes = {{0,"APhakic"},{1,"Phakic"},{2,"DenseCat"}};
//         const QList<QPair<int,QString>> cimodes = {{0,"Contact"},{1,"Immersion"}};
//         for (const auto &eye : eyes) {
//             bool eyeHasData = false;
//             for (const auto &ap : apmodes) {
//                 for (const auto &ci : cimodes) {
//                     QSqlQuery q(db);
//                     q.prepare(R"(
//                         SELECT readingno, al, deviation FROM reading
//                         WHERE  patientid=? AND doctorid=?
//                           AND  rleye=? AND apmode=? AND conimmmode=?
//                         ORDER  BY readingno ASC
//                     )");
//                     q.addBindValue(m_patientId); q.addBindValue(m_doctorId);
//                     q.addBindValue(eye.first); q.addBindValue(ap.first); q.addBindValue(ci.first);
//                     QStringList rows;
//                     if (q.exec())
//                         while (q.next())
//                             rows << QString(" #%1  AL=%2  DEV=%3")
//                                         .arg(q.value(0).toInt())
//                                         .arg(q.value(1).toDouble(), 0,'f',2)
//                                         .arg(q.value(2).toDouble(), 0,'f',3);
//                     if (rows.isEmpty()) continue;
//                     if (!eyeHasData) { out += QString("\n--- %1 ---\r\n").arg(eye.second); eyeHasData = true; }
//                     out += QString("[%1 / %2]\r\n").arg(ap.second, ci.second);
//                     for (const QString &row : rows) out += row + "\r\n";
//                     QSqlQuery gavg(db);
//                     gavg.prepare(R"(
//                         SELECT aval, stddeviation FROM reading
//                         WHERE  patientid=? AND doctorid=?
//                           AND  rleye=? AND apmode=? AND conimmmode=?
//                         ORDER  BY readingno DESC LIMIT 1
//                     )");
//                     gavg.addBindValue(m_patientId); gavg.addBindValue(m_doctorId);
//                     gavg.addBindValue(eye.first); gavg.addBindValue(ap.first); gavg.addBindValue(ci.first);
//                     if (gavg.exec() && gavg.next())
//                         out += QString(" AVG=%1  SD=%2\r\n")
//                                    .arg(gavg.value(0).toDouble(), 0,'f',2)
//                                    .arg(gavg.value(1).toDouble(), 0,'f',3);
//                     out += "................................\r\n";
//                 }
//             }
//         }
//     }

//     out += "================================\r\n";
//     out += "\r\n\r\n\r\n";
//     return out;
// }

// QString PrintDialog::buildCalcContent()
// {
//     if (!db.isOpen()) return QString();

//     QString out = buildHeader("IOL CALCULATION");

//     struct FE { iol::Formula f; QString label; };
//     const QList<FE> allFormulas = {
//                                    { iol::Formula::SRKII,    "SRK II"   },
//                                    { iol::Formula::SRKT,     "SRK/T"    },
//                                    { iol::Formula::HofferQ,  "Hoffer Q" },
//                                    { iol::Formula::Holladay, "Holladay" },
//                                    };

//     auto getK = [&](int eye, double &k1, double &k2, double &kAvg) {
//         k1 = k2 = kAvg = 0.0;
//         QSqlQuery q(db);
//         q.prepare(eye == 1
//                       ? "SELECT rk1, rk2 FROM patient WHERE patientid = ?"
//                       : "SELECT lk1, lk2 FROM patient WHERE patientid = ?");
//         q.addBindValue(m_patientId);
//         if (q.exec() && q.next()) { k1 = q.value(0).toDouble(); k2 = q.value(1).toDouble(); }
//         kAvg = (k1 > 0 && k2 > 0) ? (k1 + k2) / 2.0 : 43.5;
//         if (k1 <= 0 && k2 <= 0) k1 = k2 = 43.5;
//     };

//     auto bestAL = [&](int eye) -> double {
//         QSqlQuery q(db);
//         q.prepare(R"(SELECT al FROM reading
//                      WHERE patientid=? AND doctorid=? AND rleye=?
//                        AND apmode=1 AND conimmmode=0
//                      ORDER BY deviation ASC LIMIT 1)");
//         q.addBindValue(m_patientId); q.addBindValue(m_doctorId); q.addBindValue(eye);
//         if (q.exec() && q.next()) return q.value(0).toDouble();
//         return 0.0;
//     };

//     auto runLens = [&](int rowid, const FE &fe, double al, double k, QString &o) {
//         if (rowid < 0) return;
//         QSqlQuery lq(db);
//         lq.prepare("SELECT iol, company, asrkt, asrkii, acd, sf FROM lens WHERE id=?");
//         lq.addBindValue(rowid);
//         if (!lq.exec() || !lq.next()) return;
//         QString lensName = lq.value(0).toString(), company = lq.value(1).toString();
//         double asrkt = lq.value(2).toDouble(), asrkii = lq.value(3).toDouble();
//         double pacd  = lq.value(4).toDouble(), sf     = lq.value(5).toDouble();
//         o += company.isEmpty()
//                  ? QString("Lens : %1\r\n").arg(lensName.left(26))
//                  : QString("Lens : %1 (%2)\r\n").arg(lensName.left(18)).arg(company.left(8));
//         if (al <= 0.0) { o += "  No biometry data\r\n"; return; }
//         iol::Input inp;
//         inp.formula = fe.f; inp.axialLength = al; inp.k = k; inp.targetRx = 0.0;
//         switch (fe.f) {
//         case iol::Formula::SRKII:    inp.aConstant = asrkii; break;
//         case iol::Formula::SRKT:     inp.aConstant = asrkt;  break;
//         case iol::Formula::HofferQ:  inp.aConstant = pacd;   break;
//         case iol::Formula::Holladay: inp.aConstant = sf;     break;
//         default:                     inp.aConstant = asrkii; break;
//         }
//         iol::IOLCalculator calc;
//         iol::Result res = calc.calculate(inp);
//         if (!res.valid) { o += "  Calculation error\r\n"; return; }
//         o += QString("EMM  : %1 D\r\n").arg(res.pEmmetropia, 0,'f',2);
//         o += "IOL  :";
//         for (int i = 0; i < 5; ++i) o += QString(" %1").arg(res.iolPower[i],    5,'f',2);
//         o += "\r\n";
//         o += "Ref  :";
//         for (int i = 0; i < 5; ++i) o += QString(" %1").arg(res.predictedRx[i], 5,'f',2);
//         o += "\r\n";
//     };

//     if (m_hasCalcCtx) {
//         double k1, k2, kAvg;
//         getK(m_calcCtx.eye, k1, k2, kAvg);
//         double al = bestAL(m_calcCtx.eye);
//         int fIdx = qBound(0, m_calcCtx.formulaIndex, allFormulas.size() - 1);
//         const FE &fe = allFormulas[fIdx];
//         const QString eyeStr = (m_calcCtx.eye == 1) ? "OD" : "OS";
//         out += QString("Eye     : %1\r\n").arg(eyeStr);
//         out += QString("K1      : %1 D\r\n").arg(k1,   0,'f',2);
//         out += QString("K2      : %1 D\r\n").arg(k2,   0,'f',2);
//         out += QString("K avg   : %1 D\r\n").arg(kAvg, 0,'f',2);
//         out += QString("AL      : %1 mm\r\n").arg(al,  0,'f',2);
//         out += QString("Formula : %1\r\n").arg(fe.label);
//         out += "--------------------------------\r\n";
//         bool anyLens = false;
//         for (int rowid : {m_calcCtx.lensRowidOne,
//                           m_calcCtx.lensRowidTwo,
//                           m_calcCtx.lensRowidThree}) {
//             if (rowid < 0) continue;
//             anyLens = true;
//             runLens(rowid, fe, al, kAvg, out);
//             out += "................................\r\n";
//         }
//         if (!anyLens) out += "  [No lens selected]\r\n";
//     } else {
//         for (int eye : {1, 0}) {
//             double k1, k2, kAvg;
//             getK(eye, k1, k2, kAvg);
//             double al = bestAL(eye);
//             const QString eyeStr = (eye == 1) ? "OD" : "OS";
//             out += QString("\n--- %1 ---\r\n").arg(eyeStr);
//             out += QString("K1=%1 K2=%2 K=%3 D\r\n")
//                        .arg(k1,0,'f',2).arg(k2,0,'f',2).arg(kAvg,0,'f',2);
//             out += QString("AL=%1 mm\r\n").arg(al, 0,'f',2);
//             out += "--------------------------------\r\n";
//             QSqlQuery lq(db);
//             lq.prepare("SELECT id FROM lens ORDER BY iol ASC");
//             if (!lq.exec()) continue;
//             while (lq.next()) {
//                 int rowid = lq.value(0).toInt();
//                 for (const auto &fe : allFormulas) {
//                     out += QString("[%1]\r\n").arg(fe.label);
//                     runLens(rowid, fe, al, kAvg, out);
//                 }
//                 out += "................................\r\n";
//             }
//         }
//     }

//     out += "================================\r\n";
//     out += "\r\n\r\n\r\n";
//     return out;
// }

// // ─────────────────────────────────────────────────────────────────────────────
// //  Main-menu buttons
// // ─────────────────────────────────────────────────────────────────────────────
// void PrintDialog::on_btn_back_clicked()
// {
//     if (m_previousPage == CalculatorPage)
//     {
//         AppManager::calculator->show();
//     }
//     else
//     {
//         AppManager::home->show();
//     }

//     this->hide();
// }

// void PrintDialog::on_btn_scan_clicked()
// {
//     m_scanContent = buildScanContent();
//     ui->plainTextEdit_scan->setPlainText(m_scanContent);
//     showPage(PAGE_SCAN);
// }

// void PrintDialog::on_btn_calculations_clicked()
// {
//     m_calcContent = buildCalcContent();
//     ui->plainTextEdit_calc->setPlainText(m_calcContent);
//     showPage(PAGE_CALC);
// }

// void PrintDialog::on_btn_both_clicked()
// {
//     m_scanContent = buildScanContent();
//     m_calcContent = buildCalcContent();
//     ui->plainTextEdit_all->setPlainText(m_scanContent + "\n" + m_calcContent);
//     showPage(PAGE_BOTH);
// }



// void PrintDialog::on_btn_scan2_clicked()
// {
//     QVector<double> samples;
//     m_scanEscPos = buildScanEscPos(samples);

//     if (m_scanContent.isEmpty())
//         m_scanContent = buildScanContent();

//     QPixmap wave = m_lastWavePixmap;
//     QByteArray escpos = m_scanEscPos;
//     QString content = m_scanContent;

//     showGraphPreview(wave, [this, escpos, content, wave]() {
//         doPrint(escpos, content, wave);
//     });
// }

// void PrintDialog::on_btn_calculations2_clicked()
// {
//     m_calcEscPos = buildCalcEscPos();
//     if (m_calcContent.isEmpty())
//         m_calcContent = buildCalcContent();
//     doPrint(m_calcEscPos, m_calcContent, QPixmap());
// }

// void PrintDialog::on_btn_both2_clicked()
// {
//     QVector<double> samples;
//     m_scanEscPos = buildScanEscPos(samples);
//     m_calcEscPos = buildCalcEscPos();

//     if (m_scanContent.isEmpty()) m_scanContent = buildScanContent();
//     if (m_calcContent.isEmpty()) m_calcContent = buildCalcContent();

//     QPixmap wave = m_lastWavePixmap;
//     QByteArray escpos = m_scanEscPos + m_calcEscPos;
//     QString content = m_scanContent + "\n" + m_calcContent;

//     showGraphPreview(wave, [this, escpos, content, wave]() {
//         doPrint(escpos, content, wave);
//     });
// }


// void PrintDialog::showGraphPreview(const QPixmap &wavePixmap, std::function<void()> onDone)
// {
//     if (wavePixmap.isNull()) {
//         // Nothing to show — go straight to print flow
//         onDone();
//         return;
//     }

//     m_graphPreviewDlg = new QDialog(this);
//     m_graphPreviewDlg->setWindowTitle("Scan Graph Preview");
//     m_graphPreviewDlg->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
//     m_graphPreviewDlg->setAttribute(Qt::WA_DeleteOnClose);

//     QVBoxLayout *layout = new QVBoxLayout(m_graphPreviewDlg);

//     m_graphPreviewLabel = new QLabel(m_graphPreviewDlg);
//     m_graphPreviewLabel->setAlignment(Qt::AlignCenter);
//     m_graphPreviewLabel->setPixmap(wavePixmap);
//     layout->addWidget(m_graphPreviewLabel);

//     m_graphPreviewCloseBtn = new QPushButton(QStringLiteral("\u2715 Close"), m_graphPreviewDlg);
//     connect(m_graphPreviewCloseBtn, &QPushButton::clicked,
//             m_graphPreviewDlg, &QDialog::accept);
//     layout->addWidget(m_graphPreviewCloseBtn, 0, Qt::AlignCenter);

//     m_graphPreviewTimer = new QTimer(m_graphPreviewDlg);
//     m_graphPreviewTimer->setSingleShot(true);
//     connect(m_graphPreviewTimer, &QTimer::timeout,
//             m_graphPreviewDlg, &QDialog::accept);
//     m_graphPreviewTimer->start(5000); // 5 seconds

//     // Whether closed manually or by timer, proceed to print flow exactly once.
//     connect(m_graphPreviewDlg, &QDialog::finished, this, [this, onDone](int) {
//         m_graphPreviewTimer = nullptr;
//         m_graphPreviewDlg   = nullptr;
//         onDone();
//     });

//     m_graphPreviewDlg->exec(); // modal — blocks until closed/timeout
// }

// void PrintDialog::setPreviousPage(PreviousPage page)
// {
//     m_previousPage = page;
// }

#include "printdialog.h"
#include "ui_printdialog.h"
#include "AppManager.h"

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QTime>
#include <QImage>
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QMetaEnum>
#include <QFileInfo>
#include <QFile>
#include <cmath>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <QThread>

// ===========================================================================
// Construction / teardown
// ===========================================================================
PrintDialog::PrintDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrintDialog),
    m_previousPage(HomePage),
    m_printerPort(nullptr),
    m_clockTimer(nullptr)
{
    ui->setupUi(this);

    ui->snackbar->clear();
    ui->snackbar->setVisible(false);

    // lbl_time clock, ticking every second.
    m_clockTimer = new QTimer(this);
    connect(m_clockTimer, &QTimer::timeout, this, &PrintDialog::updateTime);
    m_clockTimer->start(1000);
    updateTime();
}

PrintDialog::~PrintDialog()
{
    closePrinterPort();
    delete ui;
}

void PrintDialog::updateTime()
{
    ui->lbl_time->setText(QTime::currentTime().toString("hh:mm"));
}

// ===========================================================================
// Context setters (call these BEFORE dialog->exec()/show())
// ===========================================================================
void PrintDialog::setScanContext(const ScanContext &ctx)
{
    m_scanCtx = ctx;
    m_scanCtx.valid = true;
}

void PrintDialog::setCalcContext(const CalcContext &ctx)
{
    m_calcCtx = ctx;
    m_calcCtx.valid = true; // presence of a context from the caller implies it's usable
}

void PrintDialog::setPatientId(const QString &patientId)
{
    qDebug() << "[PrintDialog] setPatientId:" << patientId;
    m_patientId = patientId;
    loadPatientDoctorNames();
}

void PrintDialog::setDoctorId(const QString &doctorId)
{
    qDebug() << "[PrintDialog] setDoctorId:" << doctorId;
    m_doctorId = doctorId;
    loadPatientDoctorNames();
}

void PrintDialog::setPreviousPage(PreviousPage page)
{
    qDebug() << "[PrintDialog] setPreviousPage:" << page;
    m_previousPage = page;
}

// ===========================================================================
// Resolve patient/doctor NAMES from their IDs so the printout isn't blank.
// NOTE: column names (patientid/patientname/doctorid/doctorname) are my best
// guess based on your table conventions - if the SELECT fails, the qWarning
// below will print the exact QSqlError so you can correct the column names.
// ===========================================================================
void PrintDialog::loadPatientDoctorNames()
{
    if (!m_patientId.isEmpty()) {
        QSqlQuery q;
        if (!q.prepare("SELECT name FROM patient WHERE patientid = :pid")) {
            qWarning() << "[PrintDialog] patient query FAILED TO PREPARE:" << q.lastError().text();
        } else {
            q.bindValue(":pid", m_patientId);
            if (q.exec()) {
                if (q.next()) {
                    m_patientName = q.value(0).toString();
                    qDebug() << "[PrintDialog] patientName resolved:" << m_patientName;
                } else {
                    qWarning() << "[PrintDialog] no patient row found for patientid" << m_patientId;
                }
            } else {
                qWarning() << "[PrintDialog] patient query exec failed:" << q.lastError().text();
            }
        }
    }

    if (!m_doctorId.isEmpty()) {
        QSqlQuery q;
        if (!q.prepare("SELECT name FROM doctor WHERE doctorid = :did")) {
            qWarning() << "[PrintDialog] doctor query FAILED TO PREPARE:" << q.lastError().text();
        } else {
            q.bindValue(":did", m_doctorId);
            if (q.exec()) {
                if (q.next()) {
                    m_doctorName = q.value(0).toString();
                    qDebug() << "[PrintDialog] doctorName resolved:" << m_doctorName;
                } else {
                    qWarning() << "[PrintDialog] no doctor row found for doctorid" << m_doctorId;
                }
            } else {
                qWarning() << "[PrintDialog] doctor query exec failed:" << q.lastError().text();
            }
        }
    }
}

// ===========================================================================
// Navigation
// ===========================================================================
void PrintDialog::on_btn_back_clicked()
{
    // Single-page dialog now (no stackedWidget) - back always leaves PrintDialog.
    returnToPreviousPage();
}

void PrintDialog::returnToPreviousPage()
{
    // PrintDialog is a persistent AppManager singleton (show()/hide()),
    // not exec()'d, so "going back" means hiding this and re-showing
    // whichever dialog launched it - mirroring HomeScreenDialog::on_btn_print_clicked().
    //
    // NOTE: adjust AppManager::home / AppManager::calculator / AppManager::measure
    // below to match your actual AppManager member names if they differ.
    this->hide();

    switch (m_previousPage) {
    case CalculatorPage:
        AppManager::calculator->show();
        break;
    case MeasurePage:
        AppManager::measure->show();
        break;
    case HomePage:
    default:
        AppManager::home->show();
        break;
    }
}

void PrintDialog::on_btn_scan_clicked()
{
    qDebug() << "[PrintDialog] btn_scan clicked, scan valid =" << m_scanCtx.valid;

    if (!m_scanCtx.valid) {
        // Stage 1: no real data / DB wiring yet - print dummy data so the
        // physical print path can be tested end to end.
        qDebug() << "[PrintDialog] no scan context set - using DUMMY scan data";
        m_scanCtx = makeDummyScanContext();
    } else {
        fillScanHeaderInfo(m_scanCtx);
    }

    doPrintScan();
}

void PrintDialog::on_btn_calculations_clicked()
{
    qDebug() << "[PrintDialog] btn_calculations clicked, calc valid =" << m_calcCtx.valid;

    if (!m_calcCtx.valid) {
        qDebug() << "[PrintDialog] no calc context set - using DUMMY calc data";
        m_calcCtx = makeDummyCalcContext();
    } else {
        fillCalcHeaderInfo(m_calcCtx);
    }

    doPrintCalc();
}

void PrintDialog::on_btn_both_clicked()
{
    qDebug() << "[PrintDialog] btn_both clicked, scan valid =" << m_scanCtx.valid
             << "calc valid =" << m_calcCtx.valid;

    if (!m_scanCtx.valid) {
        qDebug() << "[PrintDialog] no scan context set - using DUMMY scan data";
        m_scanCtx = makeDummyScanContext();
    } else {
        fillScanHeaderInfo(m_scanCtx);
    }

    if (!m_calcCtx.valid) {
        qDebug() << "[PrintDialog] no calc context set - using DUMMY calc data";
        m_calcCtx = makeDummyCalcContext();
    } else {
        fillCalcHeaderInfo(m_calcCtx);
    }

    doPrintAll();
}

// ===========================================================================
// Dummy data (Stage 1 - no DB wiring yet)
// Lets btn_scan / btn_calculations / btn_both be tested standalone, without
// a caller having populated setScanContext()/setCalcContext() first.
// ===========================================================================
PrintDialog::ScanContext PrintDialog::makeDummyScanContext()
{
    ScanContext ctx;
    ctx.patientName    = m_patientName.isEmpty() ? QStringLiteral("Test Patient") : m_patientName;
    ctx.patientId      = m_patientId.isEmpty()   ? QStringLiteral("P-0001")       : m_patientId;
    ctx.doctorName     = m_doctorName.isEmpty()  ? QStringLiteral("Dr. Test")     : m_doctorName;
    ctx.dateTime       = QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm");
    ctx.eye            = QStringLiteral("OD");
    ctx.axialLength    = QStringLiteral("23.45");
    ctx.waveformPixmap = makeDummyWaveform();
    ctx.valid          = true;
    return ctx;
}

PrintDialog::CalcContext PrintDialog::makeDummyCalcContext()
{
    CalcContext ctx;
    ctx.patientName         = m_patientName.isEmpty() ? QStringLiteral("Test Patient") : m_patientName;
    ctx.patientId           = m_patientId.isEmpty()   ? QStringLiteral("P-0001")       : m_patientId;
    ctx.doctorName          = m_doctorName.isEmpty()  ? QStringLiteral("Dr. Test")     : m_doctorName;
    ctx.dateTime            = QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm");
    ctx.eye                 = QStringLiteral("OD");
    ctx.formulaIndex        = 1; // SRK/T
    ctx.k1                  = QStringLiteral("44.00");
    ctx.k2                  = QStringLiteral("44.50");
    ctx.axialLength         = QStringLiteral("23.45");
    ctx.aConstant           = QStringLiteral("118.0");
    ctx.iolPower            = QStringLiteral("21.50");
    ctx.predictedRefraction = QStringLiteral("-0.25");
    ctx.lensRowidOne        = 1;
    ctx.lensRowidTwo        = 2;
    ctx.lensRowidThree      = -1;
    ctx.valid               = true;
    return ctx;
}

// Simple decaying-sine "A-scan spike" so the raster/print path (and the
// waveform-to-ESC/POS conversion) has something real to chew on before the
// actual waveform capture is wired in.
QPixmap PrintDialog::makeDummyWaveform()
{
    const int w = kPrinterWidthPx;
    const int h = 120;

    QPixmap px(w, h);
    px.fill(Qt::white);

    QPainter p(&px);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.setPen(QPen(Qt::black, 2));

    QPointF prev(0, h / 2.0);
    for (int x = 1; x < w; ++x) {
        double t = (x / double(w)) * 4.0 * M_PI;
        double decay = std::exp(-x / double(w) * 1.5);
        double y = h / 2.0 - (h / 2.5) * std::sin(t) * decay;
        QPointF cur(x, y);
        p.drawLine(prev, cur);
        prev = cur;
    }

    p.setPen(QPen(Qt::black, 1));
    p.drawRect(0, 0, w - 1, h - 1);

    return px;
}

void PrintDialog::fillScanHeaderInfo(ScanContext &ctx)
{
    if (ctx.patientName.isEmpty()) ctx.patientName = m_patientName;
    if (ctx.patientId.isEmpty())   ctx.patientId   = m_patientId;
    if (ctx.doctorName.isEmpty())  ctx.doctorName  = m_doctorName;
    if (ctx.dateTime.isEmpty())    ctx.dateTime    = QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm");
}

void PrintDialog::fillCalcHeaderInfo(CalcContext &ctx)
{
    if (ctx.patientName.isEmpty()) ctx.patientName = m_patientName;
    if (ctx.patientId.isEmpty())   ctx.patientId   = m_patientId;
    if (ctx.doctorName.isEmpty())  ctx.doctorName  = m_doctorName;
    if (ctx.dateTime.isEmpty())    ctx.dateTime    = QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm");
}

// ===========================================================================
// Print flows
// (triggered directly from on_btn_scan/calculations/both_clicked above -
// there's no separate preview page/print button in the current .ui)
// ===========================================================================
void PrintDialog::doPrintScan()
{
    qDebug() << "[PrintDialog] doPrintScan() called. valid =" << m_scanCtx.valid
             << "patient =" << m_scanCtx.patientName
             << "waveform null =" << m_scanCtx.waveformPixmap.isNull();

    if (!m_scanCtx.valid) {
        showSnack(tr("Nothing to print - no scan captured."));
        return;
    }

    if (!openPrinterPort()) {
        showSnack(tr("Printer not responding. Check connection."));
        return;
    }

    QByteArray job;
    job += "HELLO WORLD\r\n";
    job += "PATIENT : TEST\r\n";
    job += "DOCTOR  : TEST\r\n";
    job += "1234567890\r\n";

    qDebug() << "[PrintDialog] scan job size (bytes):" << job.size();
    qDebug() << "Job Size =" << job.size();
    qDebug() << job.left(64).toHex(' ');

    bool ok = writeToPrinter(job);
    closePrinterPort();

    qDebug() << "[PrintDialog] doPrintScan() write result:" << ok;
    showSnack(ok ? tr("Scan printed.") : tr("Print failed."), !ok);
}

void PrintDialog::doPrintCalc()
{
    qDebug() << "[PrintDialog] doPrintCalc() called. valid =" << m_calcCtx.valid
             << "patient =" << m_calcCtx.patientName
             << "formulaIndex =" << m_calcCtx.formulaIndex;

    if (!m_calcCtx.valid) {
        showSnack(tr("Nothing to print - no calculation available."));
        return;
    }

    if (!openPrinterPort()) {
        showSnack(tr("Printer not responding. Check connection."));
        return;
    }

    QByteArray job = buildCalcPrintJob(m_calcCtx, /*withCut=*/true);
    qDebug() << "[PrintDialog] calc job size (bytes):" << job.size();

    bool ok = writeToPrinter(job);
    closePrinterPort();

    qDebug() << "[PrintDialog] doPrintCalc() write result:" << ok;
    showSnack(ok ? tr("Calculation printed.") : tr("Print failed."), !ok);
}

void PrintDialog::doPrintAll()
{
    qDebug() << "[PrintDialog] doPrintAll() called. scan valid =" << m_scanCtx.valid
             << "calc valid =" << m_calcCtx.valid;

    if (!m_scanCtx.valid && !m_calcCtx.valid) {
        showSnack(tr("Nothing to print."));
        return;
    }

    if (!openPrinterPort()) {
        showSnack(tr("Printer not responding. Check connection."));
        return;
    }

    // Build both sections WITHOUT their own cut, then cut once at the very end.
    QByteArray job = escInit();

    if (m_scanCtx.valid)
        job += buildScanPrintJob(m_scanCtx, /*withCut=*/false);

    if (m_calcCtx.valid)
        job += buildCalcPrintJob(m_calcCtx, /*withCut=*/false);

    job += escFeedLines(2);
    job += escCut();

    qDebug() << "[PrintDialog] combined job size (bytes):" << job.size();

    bool ok = writeToPrinter(job);
    closePrinterPort();

    qDebug() << "[PrintDialog] doPrintAll() write result:" << ok;
    showSnack(ok ? tr("Printed.") : tr("Print failed."), !ok);
}

// ===========================================================================
// Serial port handling  (/dev/ttyUL1, ARM board UART -> CSN-A2 thermal printer)
// ===========================================================================

// Dumps everything relevant to "why can't Qt open/write this port" in one
// place: who we're running as, file permissions on the node itself, whether
// Qt's own enumeration even sees it, and whether something else already has
// it open. Call this BEFORE attempting QSerialPort::open() so the log always
// has this context even when open() itself fails.
void PrintDialog::debugDumpPortDiagnostics(const QString &portName)
{
    qDebug() << "[PrintDialog][diag] ---- port diagnostics for" << portName << "----";

    // Who is this process running as? (root vs some app user missing
    // dialout/tty group membership is the #1 cause of "works in my root
    // shell, fails in the app".)
    uid_t uid = getuid();
    uid_t euid = geteuid();
    struct passwd *pw = getpwuid(euid);
    qDebug() << "[PrintDialog][diag] running as uid=" << uid << "euid=" << euid
             << "user=" << (pw ? pw->pw_name : "?");

    gid_t groups[32];
    int ngroups = 32;
    if (pw && getgrouplist(pw->pw_name, pw->pw_gid, groups, &ngroups) >= 0) {
        QStringList groupNames;
        for (int i = 0; i < ngroups; ++i) {
            struct group *gr = getgrgid(groups[i]);
            groupNames << (gr ? QString(gr->gr_name) : QString::number(groups[i]));
        }
        qDebug() << "[PrintDialog][diag] process groups:" << groupNames.join(", ");
    }

    // Does the device node exist, and what are its permissions/owner?
    QFileInfo fi(portName);
    if (!fi.exists()) {
        qWarning() << "[PrintDialog][diag]" << portName << "DOES NOT EXIST on this filesystem.";
    } else {
        qDebug() << "[PrintDialog][diag] node exists — owner:" << fi.owner()
            << "group:" << fi.group()
            << "perms:" << QString::number(fi.permissions(), 8)
            << "readable:" << fi.isReadable()
            << "writable:" << fi.isWritable();
    }

    // Does Qt's own serial port enumeration see it at all? If a port is
    // missing here but the raw device node exists, that's usually a udev/
    // sysfs metadata issue rather than a plain permissions issue.
    bool foundInQtEnum = false;
    const auto ports = QSerialPortInfo::availablePorts();
    qDebug() << "[PrintDialog][diag] QSerialPortInfo sees" << ports.size() << "port(s) total";
    for (const QSerialPortInfo &info : ports) {
        qDebug() << "[PrintDialog][diag]   -" << info.systemLocation()
        << "busy:" << info.isBusy()
        << "desc:" << info.description();
        if (info.systemLocation() == portName || info.portName() == portName)
            foundInQtEnum = true;
    }
    if (!foundInQtEnum) {
        qWarning() << "[PrintDialog][diag]" << portName
                   << "was NOT found by QSerialPortInfo::availablePorts() — "
                      "QSerialPort::open() may fail even though the raw node exists "
                      "and a plain echo/redirect to it works.";
    }

    qDebug() << "[PrintDialog][diag] -------------------------------------------";
}

bool PrintDialog::openPrinterPort()
{
    static const QString kPortName = QStringLiteral("/dev/ttyUL1");

    if (m_printerPort && m_printerPort->isOpen()) {
        qDebug() << "[PrintDialog] port already open";
        return true;
    }

    debugDumpPortDiagnostics(kPortName);

    if (!m_printerPort)
        m_printerPort = new QSerialPort(this);

    m_printerPort->setPortName(kPortName);

    // NOTE: CSN-A2 clones ship at 9600 baud by default; some are jumpered/
    // configured for 19200. Change this ONE line if your printer disagrees.
    m_printerPort->setBaudRate(QSerialPort::Baud9600);

    m_printerPort->setDataBits(QSerialPort::Data8);
    m_printerPort->setParity(QSerialPort::NoParity);
    m_printerPort->setStopBits(QSerialPort::OneStop);
    m_printerPort->setFlowControl(QSerialPort::NoFlowControl);

    m_printerPort->setReadBufferSize(0);
    m_printerPort->clear();

    qDebug() << "[PrintDialog] opening" << kPortName << "...";
    if (!m_printerPort->open(QIODevice::ReadWrite)) {
        QSerialPort::SerialPortError err = m_printerPort->error();
        QMetaEnum me = QMetaEnum::fromType<QSerialPort::SerialPortError>();
        qWarning() << "[PrintDialog] FAILED to open" << kPortName
                   << "| errorString:" << m_printerPort->errorString()
                   << "| errorEnum:" << me.valueToKey(err) << "(" << int(err) << ")";

        switch (err) {
        case QSerialPort::PermissionError:
            qWarning() << "[PrintDialog] -> PermissionError: process user is not allowed "
                          "to open this device. Check group membership above against "
                          "the device's group (usually dialout/tty).";
            break;
        case QSerialPort::DeviceNotFoundError:
            qWarning() << "[PrintDialog] -> DeviceNotFoundError: portName doesn't match "
                          "any device Qt can see (see availablePorts() dump above).";
            break;
        case QSerialPort::OpenError:
            qWarning() << "[PrintDialog] -> OpenError: already open elsewhere, or the "
                          "underlying open() syscall failed for another reason (check "
                          "'lsof " << kPortName << "' on the device).";
            break;
        default:
            break;
        }
        return false;
    }

    qDebug() << "[PrintDialog]" << kPortName << "opened OK — actual settings:"
             << "baud=" << m_printerPort->baudRate()
             << "dataBits=" << m_printerPort->dataBits()
             << "parity=" << m_printerPort->parity()
             << "stopBits=" << m_printerPort->stopBits()
             << "flowControl=" << m_printerPort->flowControl();
    return true;
}

void PrintDialog::closePrinterPort()
{
    if (m_printerPort && m_printerPort->isOpen()) {
        qDebug() << "[PrintDialog] closing /dev/ttyUL1";
        m_printerPort->close();
    }
}

// bool PrintDialog::writeToPrinter(const QByteArray &data)
// {
//     if (!m_printerPort || !m_printerPort->isOpen()) {
//         qWarning() << "[PrintDialog] writeToPrinter: port not open, aborting";
//         return false;
//     }

//     // Hex-dump the first bytes so we can confirm the ESC/POS bytes themselves
//     // are sane (and not, say, accidentally double-escaped or truncated)
//     // before blaming the transport.
//     const int dumpLen = qMin(data.size(), 48);
//     qDebug() << "[PrintDialog] writing" << data.size() << "bytes to printer. First"
//              << dumpLen << "bytes (hex):" << data.left(dumpLen).toHex(' ');

//     qint64 written = m_printerPort->write(data);
//     if (written == -1) {
//         QMetaEnum me = QMetaEnum::fromType<QSerialPort::SerialPortError>();
//         qWarning() << "[PrintDialog] write() failed:" << m_printerPort->errorString()
//                    << "| errorEnum:" << me.valueToKey(m_printerPort->error());
//         return false;
//     }
//     qDebug() << "[PrintDialog] write() queued" << written << "of" << data.size()
//              << "bytes | bytesToWrite() now:" << m_printerPort->bytesToWrite();

//     if (!m_printerPort->waitForBytesWritten(3000)) {
//         QMetaEnum me = QMetaEnum::fromType<QSerialPort::SerialPortError>();
//         qWarning() << "[PrintDialog] waitForBytesWritten timed out:"
//                    << m_printerPort->errorString()
//                    << "| errorEnum:" << me.valueToKey(m_printerPort->error())
//                    << "| bytesToWrite() still pending:" << m_printerPort->bytesToWrite();
//         return false;
//     }

//     qDebug() << "[PrintDialog] all bytes flushed to printer OK";
//     // Give the thermal head a moment to actually consume the buffer before
//     // the port is closed / the dialog moves on.
//     m_printerPort->flush();
//     return true;
// }

bool PrintDialog::writeToPrinter(const QByteArray &data)
{
    if (!m_printerPort || !m_printerPort->isOpen()) {
        qWarning() << "[PrintDialog] Port is not open!";
        return false;
    }

    const int chunkSize = 128;      // Send 128 bytes at a time

    for (int i = 0; i < data.size(); i += chunkSize)
    {
        QByteArray chunk = data.mid(i, chunkSize);

        qint64 written = m_printerPort->write(chunk);

        if (written != chunk.size()) {
            qWarning() << "Write failed at chunk" << i;
            return false;
        }

        if (!m_printerPort->waitForBytesWritten(2000)) {
            qWarning() << "Timeout while writing chunk";
            return false;
        }

        m_printerPort->flush();

        QThread::msleep(20);     // Allow printer UART buffer to empty
    }

    return true;
}

// ===========================================================================
// ESC/POS primitives
// ===========================================================================
QByteArray PrintDialog::escInit()
{
    return QByteArray("\x1B\x40", 2); // ESC @  - initialize printer
}

QByteArray PrintDialog::escCut()
{
    return QByteArray("\x1D\x56\x00", 3); // GS V 0 - full cut
}

QByteArray PrintDialog::escAlignCenter()
{
    return QByteArray("\x1B\x61\x01", 3); // ESC a 1
}

QByteArray PrintDialog::escAlignLeft()
{
    return QByteArray("\x1B\x61\x00", 3); // ESC a 0
}

QByteArray PrintDialog::escBoldOn()
{
    return QByteArray("\x1B\x45\x01", 3); // ESC E 1
}

QByteArray PrintDialog::escBoldOff()
{
    return QByteArray("\x1B\x45\x00", 3); // ESC E 0
}

QByteArray PrintDialog::escFeedLines(int n)
{
    QByteArray out;
    out.append('\x1B');
    out.append('\x64'); // ESC d n
    out.append(char(n));
    return out;
}

QByteArray PrintDialog::textLine(const QString &text)
{
    QByteArray out = text.toLatin1();
    out.append('\n');
    return out;
}

// ===========================================================================
// Waveform pixmap -> ESC * (mode 33, 24-dot double density) raster bit image
// ===========================================================================
QByteArray PrintDialog::pixmapToEscRaster(const QPixmap &pixmapIn)
{
    QByteArray out;
    if (pixmapIn.isNull())
        return out;

    QImage img = pixmapIn.toImage();

    // Scale to the printer's dot width, preserving aspect ratio.
    if (img.width() != kPrinterWidthPx) {
        int newHeight = int(double(img.height()) *
                            (double(kPrinterWidthPx) / double(img.width())));
        if (newHeight < 1) newHeight = 1;
        img = img.scaled(kPrinterWidthPx, newHeight,
                         Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    }

    // Convert to 1-bit monochrome with threshold dithering.
    img = img.convertToFormat(QImage::Format_Mono, Qt::MonoOnly | Qt::ThresholdDither);

    const int width  = img.width();
    const int height = img.height();
    const int bandRows = 24; // ESC * mode 33 covers 24 vertical dots per pass

    for (int y0 = 0; y0 < height; y0 += bandRows) {
        QByteArray band;
        band.reserve(width * 3);

        for (int x = 0; x < width; ++x) {
            unsigned char b0 = 0, b1 = 0, b2 = 0;

            for (int r = 0; r < bandRows; ++r) {
                int y = y0 + r;
                bool dark = false;
                if (y < height) {
                    QRgb pix = img.pixel(x, y);
                    dark = (qGray(pix) < 128);
                }
                if (dark) {
                    int byteIdx = r / 8;
                    int bitIdx  = 7 - (r % 8);
                    if (byteIdx == 0)      b0 |= (1 << bitIdx);
                    else if (byteIdx == 1)  b1 |= (1 << bitIdx);
                    else                    b2 |= (1 << bitIdx);
                }
            }

            band.append(char(b0));
            band.append(char(b1));
            band.append(char(b2));
        }

        int nL = width % 256;
        int nH = width / 256;

        out.append('\x1B');       // ESC
        out.append('\x2A');       // '*'
        out.append(char(33));     // mode 33 = 24-dot double density
        out.append(char(nL));
        out.append(char(nH));
        out.append(band);
        out.append('\x0A');       // line feed to advance to the next band
    }

    return out;
}

// ===========================================================================
// Print job builders
// ===========================================================================
QByteArray PrintDialog::buildScanPrintJob(const ScanContext &ctx, bool withCut)
{
    QByteArray job;

    // Remove all ESC commands for testing.

    job += "AcuAxis A-Scan Report\r\n";
    job += "-------------------------\r\n";
    job += QString("Patient : %1\r\n").arg(ctx.patientName).toLatin1();
    job += QString("Patient ID : %1\r\n").arg(ctx.patientId).toLatin1();
    job += QString("Doctor : %1\r\n").arg(ctx.doctorName).toLatin1();
    job += QString("Eye : %1\r\n").arg(ctx.eye).toLatin1();
    job += QString("AL : %1 mm\r\n").arg(ctx.axialLength).toLatin1();

    job += "\r\n\r\n";

    return job;
}

QByteArray PrintDialog::buildCalcPrintJob(const CalcContext &ctx, bool withCut)
{
    QByteArray job;
    job += escInit();
    job += escAlignCenter();
    job += escBoldOn();
    job += textLine("AcuAxis IOL Calculation");
    job += escBoldOff();
    job += escAlignLeft();

    job += buildCalcContent(ctx).toLatin1();

    job += escFeedLines(2);

    if (withCut)
        job += escCut();

    return job;
}

QString PrintDialog::buildCalcContent(const CalcContext &ctx)
{
    static const char *kFormulaNames[] = { "SRK/II", "SRK/T", "Hoffer Q", "Holladay" };
    QString formulaName = (ctx.formulaIndex >= 0 && ctx.formulaIndex < 4)
                              ? kFormulaNames[ctx.formulaIndex]
                              : "Unknown";

    QString content;
    content += QString("Patient : %1 (%2)\n").arg(ctx.patientName, ctx.patientId);
    content += QString("Doctor  : %1\n").arg(ctx.doctorName);
    content += QString("Date    : %1\n").arg(ctx.dateTime);
    content += QString("Eye     : %1\n").arg(ctx.eye);
    content += QString("Formula : %1\n").arg(formulaName);
    content += "\n";

    // Optional pre-formatted biometry/result strings - only print lines that
    // CalculatorDialog actually populated.
    if (!ctx.k1.isEmpty())
        content += QString("K1      : %1 D\n").arg(ctx.k1);
    if (!ctx.k2.isEmpty())
        content += QString("K2      : %1 D\n").arg(ctx.k2);
    if (!ctx.axialLength.isEmpty())
        content += QString("AL      : %1 mm\n").arg(ctx.axialLength);
    if (!ctx.aConstant.isEmpty())
        content += QString("A-Const : %1\n").arg(ctx.aConstant);
    if (!ctx.iolPower.isEmpty())
        content += QString("IOL Pwr : %1 D\n").arg(ctx.iolPower);
    if (!ctx.predictedRefraction.isEmpty())
        content += QString("Pred Rx : %1 D\n").arg(ctx.predictedRefraction);

    // Lens presets selected for comparison (by rowid until the caller wires
    // up actual lens name/power lookups against the `lens` table).
    content += "\n";
    if (ctx.lensRowidOne >= 0)
        content += QString("Lens 1 (rowid) : %1\n").arg(ctx.lensRowidOne);
    if (ctx.lensRowidTwo >= 0)
        content += QString("Lens 2 (rowid) : %1\n").arg(ctx.lensRowidTwo);
    if (ctx.lensRowidThree >= 0)
        content += QString("Lens 3 (rowid) : %1\n").arg(ctx.lensRowidThree);

    return content;
}

// ===========================================================================
// Snackbar helper
// ===========================================================================
void PrintDialog::showSnack(const QString &msg, bool isError)
{
    ui->snackbar->setText(msg);
    ui->snackbar->setVisible(true);

    // isError flag reserved for future styling (red vs green background);
    // snackbar image is currently fixed to alert-red.png in the .ui file.
    Q_UNUSED(isError);

    QTimer::singleShot(3000, this, [this]() {
        ui->snackbar->setVisible(false);
    });
}
