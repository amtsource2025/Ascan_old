#include "editdoctordialog.h"
#include "ui_editdoctordialog.h"
#include "promptdialog.h"
#include <QTime>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

// ─────────────────────────────────────────────────────────────
//  Constructor / Destructor
// ─────────────────────────────────────────────────────────────
EditDoctorDialog::EditDoctorDialog(const QString &doctorId, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditDoctorDialog)
    , clockTimer(new QTimer(this))
    , m_doctorId(doctorId)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    if (!openDatabase())
        qDebug() << "EditDoctorDialog: Failed to open database!";

    // Clock
    connect(clockTimer, &QTimer::timeout, this, &EditDoctorDialog::updateTime);
    clockTimer->start(1000);
    updateTime();

    // Doctor ID is read-only
    ui->lineEdit_docID->setReadOnly(true);

    loadLensOptions();   // populate comboboxes first
    loadDoctor();        // then fill values
}

EditDoctorDialog::~EditDoctorDialog()
{
    if (db.isOpen())
        db.close();
    delete ui;
}

// ─────────────────────────────────────────────────────────────
//  Database
// ─────────────────────────────────────────────────────────────
bool EditDoctorDialog::openDatabase()
{
    const QString connName = "editdoctor_conn";
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
//  Populate lens comboboxes from lens table
// ─────────────────────────────────────────────────────────────
void EditDoctorDialog::loadLensOptions()
{
    ui->comboBox_lensPresetOne->clear();
    ui->comboBox_lensPresetTwo->clear();
    ui->comboBox_lensPresetThree->clear();

    // Add blank option first
    ui->comboBox_lensPresetOne->addItem("");
    ui->comboBox_lensPresetTwo->addItem("");
    ui->comboBox_lensPresetThree->addItem("");

    QSqlQuery query(db);
    query.prepare("SELECT iol FROM lens ORDER BY iol ASC");
    if (!query.exec()) {
        qDebug() << "loadLensOptions error:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        QString iol = query.value(0).toString();
        ui->comboBox_lensPresetOne->addItem(iol);
        ui->comboBox_lensPresetTwo->addItem(iol);
        ui->comboBox_lensPresetThree->addItem(iol);
    }

    // Formula options
    ui->comboBox_primaryFormula->clear();
    ui->comboBox_primaryFormula->addItems({"SRKT", "SRK II", "Holladay 1", "HofferQ", "Haigis"});
}

// ─────────────────────────────────────────────────────────────
//  Load existing doctor data into fields
// ─────────────────────────────────────────────────────────────
void EditDoctorDialog::loadDoctor()
{
    QSqlQuery query(db);
    query.prepare("SELECT doctorid, name, lenspresetone, lenspresettwo, "
                  "lenspresetthree, formula FROM doctor WHERE doctorid = :id");
    query.bindValue(":id", m_doctorId);

    if (!query.exec() || !query.next()) {
        qDebug() << "loadDoctor error:" << query.lastError().text();
        return;
    }

    ui->lineEdit_docID->setText(query.value(0).toString());
    ui->lineEdit_docName->setText(query.value(1).toString());

    // Set combobox selections — find matching index
    auto setCombo = [](QComboBox *cb, const QString &val) {
        int idx = cb->findText(val);
        cb->setCurrentIndex(idx >= 0 ? idx : 0);
    };

    setCombo(ui->comboBox_lensPresetOne,   query.value(2).toString());
    setCombo(ui->comboBox_lensPresetTwo,   query.value(3).toString());
    setCombo(ui->comboBox_lensPresetThree, query.value(4).toString());
    setCombo(ui->comboBox_primaryFormula,  query.value(5).toString());
}

// ─────────────────────────────────────────────────────────────
//  Clock
// ─────────────────────────────────────────────────────────────
void EditDoctorDialog::updateTime()
{
    ui->lbl_time->setText(QTime::currentTime().toString("hh:mm"));
}

// ─────────────────────────────────────────────────────────────
//  Save
// ─────────────────────────────────────────────────────────────
void EditDoctorDialog::on_btn_save_clicked()
{
    QString name    = ui->lineEdit_docName->text().trimmed();
    QString lens1   = ui->comboBox_lensPresetOne->currentText();
    QString lens2   = ui->comboBox_lensPresetTwo->currentText();
    QString lens3   = ui->comboBox_lensPresetThree->currentText();
    QString formula = ui->comboBox_primaryFormula->currentText();

    if (name.isEmpty()) {
        PromptDialog p("Validation", "Doctor Name cannot be empty.", this);
        p.exec();
        return;
    }

    QSqlQuery query(db);
    query.prepare("UPDATE doctor SET name = :name, "
                  "lenspresetone = :l1, lenspresettwo = :l2, "
                  "lenspresetthree = :l3, formula = :formula "
                  "WHERE doctorid = :id");
    query.bindValue(":name",    name);
    query.bindValue(":l1",      lens1);
    query.bindValue(":l2",      lens2);
    query.bindValue(":l3",      lens3);
    query.bindValue(":formula", formula);
    query.bindValue(":id",      m_doctorId);

    if (!query.exec()) {
        qDebug() << "Save doctor error:" << query.lastError().text();
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
void EditDoctorDialog::on_btn_cancel_clicked()
{
    reject();
}

