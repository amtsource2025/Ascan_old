
#include "printdialog.h"
#include "ui_printdialog.h"
#include "AppManager.h"
#include "homescreendialog.h"
#include "measuredialog.h"
#include "calculatordialog.h"

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
    returnToPreviousPage();
}

void PrintDialog::returnToPreviousPage()
{
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

PrintDialog::ScanContext PrintDialog::buildScanContextFromCurrentReading()
{
    ScanContext ctx; // ctx.valid stays false unless a row is actually found

    if (!AppManager::measure) {
        qWarning() << "[PrintDialog] AppManager::measure not created yet";
        return ctx;
    }

    MeasureDialog *m = AppManager::measure;

    QSqlQuery q;
    q.prepare(R"(
        SELECT al, readingdata
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
    q.addBindValue(m->currentEye());
    q.addBindValue(m->lensType());
    q.addBindValue(m->opMode());
    q.addBindValue(m->selectedReading());

    if (!q.exec() || !q.next()) {
        qWarning() << "[PrintDialog] no reading row for patient=" << m_patientId
                   << "reading=" << m->selectedReading()
                   << q.lastError().text();
        return ctx;
    }

    ctx.axialLength    = QString::number(q.value(0).toDouble(), 'f', 2);
    ctx.eye            = (m->currentEye() == 0) ? "OD" : "OS"; // match your rleye convention
    ctx.dateTime       = QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm");
    ctx.waveformPixmap = m->getWaveformPixmap();

    ctx.valid          = true;

    return ctx;
}
void PrintDialog::on_btn_scan_clicked()
{
    qDebug() << "[PrintDialog] btn_scan clicked";

    m_scanCtx = buildScanContextFromCurrentReading();

    if (!m_scanCtx.valid) {
        qDebug() << "[PrintDialog] no reading found - using DUMMY scan data";
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

// Simple decaying-sine "A-scan spike" so the raster/print path has
// something real to chew on before actual waveform capture is wired in.
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

    // Waveform pixmap comes from MeasureDialog's renderWaveformPixmap();
    // if btn_scan was hit without a scan actually captured, fall back to
    // the dummy trace so there's always something to raster/print.
    if (ctx.waveformPixmap.isNull())
        ctx.waveformPixmap = makeDummyWaveform();
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
// ===========================================================================

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
}void PrintDialog::doPrintScan()
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

    // FIX: this used to send a hardcoded "HELLO WORLD" test job and never
    // touched buildScanPrintJob()/pixmapToEscRaster(), so the waveform never
    // actually reached the printer. Now builds the real scan job (header +
    // rasterized waveform) and cuts at the end.
    QByteArray job = buildScanPrintJob(m_scanCtx, /*withCut=*/true);

    qDebug() << "[PrintDialog] scan job size (bytes):" << job.size();
    qDebug() << job.left(64).toHex(' ');

    bool ok = writeToPrinter(job);
    closePrinterPort();

    qDebug() << "[PrintDialog] doPrintScan() write result:" << ok;
    showSnack(ok ? tr("Scan printed.") : tr("Print failed."), !ok);
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
void PrintDialog::debugDumpPortDiagnostics(const QString &portName)
{
    qDebug() << "[PrintDialog][diag] ---- port diagnostics for" << portName << "----";

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
                          "to open this device.";
            break;
        case QSerialPort::DeviceNotFoundError:
            qWarning() << "[PrintDialog] -> DeviceNotFoundError: portName doesn't match "
                          "any device Qt can see.";
            break;
        case QSerialPort::OpenError:
            qWarning() << "[PrintDialog] -> OpenError: already open elsewhere, or the "
                          "underlying open() syscall failed for another reason.";
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
// QByteArray PrintDialog::pixmapToEscRaster(const QPixmap &pixmapIn)
// {
//     QByteArray out;
//     if (pixmapIn.isNull())
//         return out;

//     QImage img = pixmapIn.toImage();

//     img.invertPixels();

//     if (img.width() != kPrinterWidthPx) {
//         int newHeight = int(double(img.height()) *
//                             (double(kPrinterWidthPx) / double(img.width())));
//         if (newHeight < 1) newHeight = 1;
//         img = img.scaled(kPrinterWidthPx, newHeight,
//                          Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
//     }

//     img = img.convertToFormat(QImage::Format_Mono, Qt::MonoOnly | Qt::ThresholdDither);

//     const int width  = img.width();
//     const int height = img.height();
//     const int bandRows = 24; // ESC * mode 33 covers 24 vertical dots per pass

//     for (int y0 = 0; y0 < height; y0 += bandRows) {
//         QByteArray band;
//         band.reserve(width * 3);

//         for (int x = 0; x < width; ++x) {
//             unsigned char b0 = 0, b1 = 0, b2 = 0;

//             for (int r = 0; r < bandRows; ++r) {
//                 int y = y0 + r;
//                 bool dark = false;
//                 if (y < height) {
//                     QRgb pix = img.pixel(x, y);
//                     dark = (qGray(pix) < 128);
//                 }
//                 if (dark) {
//                     int byteIdx = r / 8;
//                     int bitIdx  = 7 - (r % 8);
//                     if (byteIdx == 0)      b0 |= (1 << bitIdx);
//                     else if (byteIdx == 1)  b1 |= (1 << bitIdx);
//                     else                    b2 |= (1 << bitIdx);
//                 }
//             }

//             band.append(char(b0));
//             band.append(char(b1));
//             band.append(char(b2));
//         }

//         int nL = width % 256;
//         int nH = width / 256;

//         out.append('\x1B');       // ESC
//         out.append('\x2A');       // '*'
//         out.append(char(33));     // mode 33 = 24-dot double density
//         out.append(char(nL));
//         out.append(char(nH));
//         out.append(band);
//         out.append('\x0A');       // line feed to advance to the next band
//     }

//     return out;
// }


QByteArray PrintDialog::pixmapToEscRaster(const QPixmap &pixmapIn)
{
    QByteArray out;
    if (pixmapIn.isNull())
        return out;

    QImage img = pixmapIn.toImage();

    if (img.width() != kPrinterWidthPx) {
        int newHeight = int(double(img.height()) *
                            (double(kPrinterWidthPx) / double(img.width())));
        if (newHeight < 1) newHeight = 1;
        img = img.scaled(kPrinterWidthPx, newHeight,
                         Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    }

    img = img.convertToFormat(QImage::Format_Mono, Qt::MonoOnly | Qt::ThresholdDither);

    const int width      = img.width();
    const int height     = img.height();
    const int widthBytes = (width + 7) / 8;   // 8 pixels packed per byte

    QByteArray data;
    data.fill('\x00', widthBytes * height);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            const bool dark = (qGray(img.pixel(x, y)) < 128);
            if (dark) {
                const int byteIdx = y * widthBytes + (x / 8);
                const int bitIdx  = 7 - (x % 8);
                data[byteIdx] = data[byteIdx] | char(1 << bitIdx);
            }
        }
    }

    const int xL = widthBytes % 256;
    const int xH = widthBytes / 256;
    const int yL = height % 256;
    const int yH = height / 256;

    // GS v 0 m xL xH yL yH d1...dk  -- single raster block, whole image at once
    out.append('\x1D');       // GS
    out.append('\x76');       // 'v'
    out.append('\x30');       // '0'
    out.append(char(0));      // m = 0, normal size (no doubling)
    out.append(char(xL));
    out.append(char(xH));
    out.append(char(yL));
    out.append(char(yH));
    out.append(data);

    return out;
}

// ===========================================================================
// Print job builders
// ===========================================================================
QByteArray PrintDialog::buildScanPrintJob(const ScanContext &ctx, bool withCut)
{
    QByteArray job;

    job += escInit();
    job += escAlignCenter();
    job += escBoldOn();
    job += textLine("AcuAxis A-Scan Report");
    job += escBoldOff();
    job += escAlignLeft();

    job += QString("Patient : %1\n").arg(ctx.patientName).toLatin1();
    job += QString("ID      : %1\n").arg(ctx.patientId).toLatin1();
    job += QString("Doctor  : %1\n").arg(ctx.doctorName).toLatin1();
    job += QString("Date    : %1\n").arg(ctx.dateTime).toLatin1();
    job += QString("Eye     : %1\n").arg(ctx.eye).toLatin1();
    job += QString("AL      : %1 mm\n").arg(ctx.axialLength).toLatin1();
    job += "\n";

    // Rasterize + print the waveform (dummy sine trace or real
    // renderWaveformPixmap() capture from MeasureDialog).
    // if (!ctx.waveformPixmap.isNull()) {
    //     job += escAlignCenter();
    //     job += pixmapToEscRaster(ctx.waveformPixmap);
    //     job += escAlignLeft();
    // } else {
    //     qWarning() << "[PrintDialog] buildScanPrintJob: waveformPixmap is null, skipping raster";
    // }

    if (!ctx.waveformPixmap.isNull()) {
        job += escAlignCenter();
        job += pixmapToEscRaster(applyLayoutOrientation(ctx.waveformPixmap)); // was: pixmapToEscRaster(ctx.waveformPixmap)
        job += escAlignLeft();
    } else {
        qWarning() << "[PrintDialog] buildScanPrintJob: waveformPixmap is null, skipping raster";
    }

    job += escFeedLines(2);

    if (withCut)
        job += escCut();

    return job;
}

QPixmap PrintDialog::applyLayoutOrientation(const QPixmap &waveform) const
{
    if (waveform.isNull())
        return waveform;

    if (!ui->radio_layoutHorizontal->isChecked())
        return waveform; // Default layout — unchanged

    QTransform t;
    t.rotate(90);
    QPixmap rotated = waveform.transformed(t, Qt::SmoothTransformation);

    // Rotating swaps width/height. If left alone, pixmapToEscRaster()
    // scales the narrow (rotated) width back up to the full 384-dot
    // printer width, which also stretches the height ~10x — that flood
    // of raster data is what overflows the printer's buffer and causes
    // the stray '@' + blank print. Scale to the target width HERE, with
    // a capped height, so pixmapToEscRaster() has nothing left to stretch.
    const int targetHeight = 150; // same order of magnitude as default layout
    rotated = rotated.scaled(kPrinterWidthPx, targetHeight,
                             Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    return rotated;
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

    Q_UNUSED(isError);

    QTimer::singleShot(3000, this, [this]() {
        ui->snackbar->setVisible(false);
    });
}


