#include "editlensdialog.h"
#include "ui_editlensdialog.h"
#include "promptdialog.h"
#include "keypad.h"
#include "numericpad.h"
#include <QTime>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

// ─────────────────────────────────────────────────────────────
//  Constructor / Destructor
// ─────────────────────────────────────────────────────────────
EditLensDialog::EditLensDialog(const QString &iol, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditLensDialog)
    , clockTimer(new QTimer(this))
    , m_iol(iol)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    if (!openDatabase())
        qDebug() << "EditLensDialog: Failed to open database!";

    // Clock
    connect(clockTimer, &QTimer::timeout, this, &EditLensDialog::updateTime);
    clockTimer->start(1000);
    updateTime();

    // IOL name is read-only (it is the primary key)
    ui->lineEdit_iol->setReadOnly(true);

    // Type combobox options
    ui->comboBox_lensType->clear();
    ui->comboBox_lensType->addItems({"Anterior", "Posterior"});

    loadLens();

    // ── Event filters for on-screen input ────────────────────
    ui->lineEdit_company->installEventFilter(this);

    ui->lineEdit_asrkt->installEventFilter(this);
    ui->lineEdit_asrkii->installEventFilter(this);
    ui->lineEdit_acd->installEventFilter(this);
    ui->lineEdit_sf->installEventFilter(this);
    ui->lineEdit_a0->installEventFilter(this);
    ui->lineEdit_a1->installEventFilter(this);
    ui->lineEdit_a2->installEventFilter(this);
}

EditLensDialog::~EditLensDialog()
{
    if (db.isOpen())
        db.close();
    delete ui;
}

// ─────────────────────────────────────────────────────────────
//  Database
// ─────────────────────────────────────────────────────────────
bool EditLensDialog::openDatabase()
{
    const QString connName = "editlens_conn";
    if (QSqlDatabase::contains(connName)) {
        db = QSqlDatabase::database(connName);
    } else {
        db = QSqlDatabase::database();
    }
    if (!db.open()) {
        qDebug() << "DB Error:" << db.lastError().text();
        return false;
    }
    return true;
}

// ─────────────────────────────────────────────────────────────
//  Load existing lens data into fields
// ─────────────────────────────────────────────────────────────
void EditLensDialog::loadLens()
{
    QSqlQuery query(db);
    query.prepare("SELECT iol, company, type, asrkt, asrkii, acd, sf, a0, a1, a2 "
                  "FROM lens WHERE iol = :iol");
    query.bindValue(":iol", m_iol);

    if (!query.exec() || !query.next()) {
        qDebug() << "loadLens error:" << query.lastError().text();
        return;
    }

    ui->lineEdit_iol->setText(query.value(0).toString());
    ui->lineEdit_company->setText(query.value(1).toString());

    // type: 0 = Anterior, 1 = Posterior
    int typeIdx = query.value(2).toInt();
    ui->comboBox_lensType->setCurrentIndex(typeIdx == 1 ? 1 : 0);

    ui->lineEdit_asrkt->setText(query.value(3).toString());
    ui->lineEdit_asrkii->setText(query.value(4).toString());
    ui->lineEdit_acd->setText(query.value(5).toString());
    ui->lineEdit_sf->setText(query.value(6).toString());
    ui->lineEdit_a0->setText(query.value(7).toString());
    ui->lineEdit_a1->setText(query.value(8).toString());
    ui->lineEdit_a2->setText(query.value(9).toString());
}

// ─────────────────────────────────────────────────────────────
//  Clock
// ─────────────────────────────────────────────────────────────
void EditLensDialog::updateTime()
{
    ui->lbl_time->setText(QTime::currentTime().toString("hh:mm"));
}

// ─────────────────────────────────────────────────────────────
//  Save
// ─────────────────────────────────────────────────────────────
void EditLensDialog::on_btn_save_clicked()
{
    QString company = ui->lineEdit_company->text().trimmed();
    int     type    = ui->comboBox_lensType->currentIndex(); // 0=Anterior, 1=Posterior
    double  asrkt   = ui->lineEdit_asrkt->text().toDouble();
    double  asrkii  = ui->lineEdit_asrkii->text().toDouble();
    double  acd     = ui->lineEdit_acd->text().toDouble();
    double  sf      = ui->lineEdit_sf->text().toDouble();
    double  a0      = ui->lineEdit_a0->text().toDouble();
    double  a1      = ui->lineEdit_a1->text().toDouble();
    double  a2      = ui->lineEdit_a2->text().toDouble();

    QSqlQuery query(db);
    query.prepare("UPDATE lens SET company = :company, type = :type, "
                  "asrkt = :asrkt, asrkii = :asrkii, acd = :acd, sf = :sf, "
                  "a0 = :a0, a1 = :a1, a2 = :a2 "
                  "WHERE iol = :iol");
    query.bindValue(":company", company);
    query.bindValue(":type",    type);
    query.bindValue(":asrkt",   asrkt);
    query.bindValue(":asrkii",  asrkii);
    query.bindValue(":acd",     acd);
    query.bindValue(":sf",      sf);
    query.bindValue(":a0",      a0);
    query.bindValue(":a1",      a1);
    query.bindValue(":a2",      a2);
    query.bindValue(":iol",     m_iol);

    if (!query.exec()) {
        qDebug() << "Save lens error:" << query.lastError().text();
        PromptDialog err("Database Error",
                         "Failed to save:\n" + query.lastError().text(), this);
        err.exec();
        return;
    }

    QTimer::singleShot(800, this, [this]() { accept(); });
}

// ─────────────────────────────────────────────────────────────
//  Cancel
// ─────────────────────────────────────────────────────────────
void EditLensDialog::on_btn_cancel_clicked()
{
    reject();
}

// ─────────────────────────────────────────────────────────────
//  Event Filter — on-screen keypads
// ─────────────────────────────────────────────────────────────
bool EditLensDialog::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        if (obj == ui->lineEdit_company) {
            QLineEdit *le = qobject_cast<QLineEdit*>(obj);
            Keypad *kp = new Keypad(le, this);
            kp->exec();
            delete kp;
            return true;
        }

        if (obj == ui->lineEdit_asrkt  ||
            obj == ui->lineEdit_asrkii ||
            obj == ui->lineEdit_acd    ||
            obj == ui->lineEdit_sf     ||
            obj == ui->lineEdit_a0     ||
            obj == ui->lineEdit_a1     ||
            obj == ui->lineEdit_a2)
        {
            QLineEdit *le = qobject_cast<QLineEdit*>(obj);
            Numericpad *np = new Numericpad(le, this);
            np->exec();
            delete np;
            return true;
        }
    }
    return QDialog::eventFilter(obj, event);
}
