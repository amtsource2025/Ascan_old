#include "viewdoctordialog.h"
#include "ui_viewdoctordialog.h"
#include "adddoctordialog.h"
#include "promptdialog.h"
#include <QTime>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "editdoctordialog.h"
#include "doctordetaildialog.h"
// ─────────────────────────────────────────────────────────────
//  Normal constructor
// ─────────────────────────────────────────────────────────────
ViewDoctorDialog::ViewDoctorDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewDoctorDialog)
    , clockTimer(new QTimer(this))
    , m_selectionMode(false)
{
    ui->setupUi(this);
    init();
}

// ─────────────────────────────────────────────────────────────
//  Selection-mode constructor (called from AddPatientDialog)
// ─────────────────────────────────────────────────────────────
ViewDoctorDialog::ViewDoctorDialog(QWidget *parent, const QString &patientId)
    : QDialog(parent)
    , ui(new Ui::ViewDoctorDialog)
    , clockTimer(new QTimer(this))
    , m_selectionMode(true)
    , m_patientId(patientId)
{
    ui->setupUi(this);
    init();
    setWindowTitle("Assign Default Doctor — " + patientId);
}

// ─────────────────────────────────────────────────────────────
//  Destructor
// ─────────────────────────────────────────────────────────────
ViewDoctorDialog::~ViewDoctorDialog()
{
    delete ui;
}

// ─────────────────────────────────────────────────────────────
//  Shared init
// ─────────────────────────────────────────────────────────────
void ViewDoctorDialog::init()
{
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    if (!openDatabase())
        qDebug() << "ViewDoctorDialog: Failed to open database!";

    // Clock
    connect(clockTimer, &QTimer::timeout, this, &ViewDoctorDialog::updateTime);
    clockTimer->start(1000);
    updateTime();

    // Table setup
    ui->table_doctor->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_doctor->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->table_doctor->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->table_doctor->horizontalHeader()->setStretchLastSection(true);
    ui->table_doctor->verticalHeader()->setVisible(false);

    // Wire single-click row selection only in selection mode
    if (m_selectionMode) {
        connect(ui->table_doctor, &QTableWidget::cellClicked,
                this, &ViewDoctorDialog::onDoctorRowClicked);


    }

    loadDoctors();
}

// ─────────────────────────────────────────────────────────────
//  Database
// ─────────────────────────────────────────────────────────────
bool ViewDoctorDialog::openDatabase()
{
    const QString connName = "viewdoctor_conn";
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
//  Load doctors into table
// ─────────────────────────────────────────────────────────────
void ViewDoctorDialog::loadDoctors()
{
    ui->table_doctor->clearContents();
    ui->table_doctor->setRowCount(0);
    ui->table_doctor->setColumnCount(6);
    ui->table_doctor->setHorizontalHeaderLabels(
        {"ID", "Name", "Lens1", "Lens2", "Lens3", "Formula"});

    QSqlQuery query(db);
    // ✅ FIXED column names to match actual schema
    query.prepare("SELECT doctorid, name, lenspresetone, lenspresettwo, lenspresetthree, formula "
                  "FROM doctor ORDER BY name ASC");

    if (!query.exec()) {
        qDebug() << "loadDoctors error:" << query.lastError().text(); // ← check this in logs
        return;
    }

    int row = 0;
    while (query.next()) {
        ui->table_doctor->insertRow(row);
        for (int col = 0; col < 6; ++col) {
            ui->table_doctor->setItem(
                row, col,
                new QTableWidgetItem(query.value(col).toString()));
        }
        ++row;
    }
}

// ─────────────────────────────────────────────────────────────
//  Clock
// ─────────────────────────────────────────────────────────────
void ViewDoctorDialog::updateTime()
{
    ui->lbl_time->setText(QTime::currentTime().toString("hh:mm"));
}

// ─────────────────────────────────────────────────────────────
//  Single-click row handler — links doctor to patient in DB
// ─────────────────────────────────────────────────────────────
void ViewDoctorDialog::onDoctorRowClicked(int row, int /*column*/)
{
    if (row < 0 || row >= ui->table_doctor->rowCount())
        return;

    QString doctorId   = ui->table_doctor->item(row, 0)->text();
    QString doctorName = ui->table_doctor->item(row, 1)->text();

    QSqlQuery query(db);
    query.prepare("UPDATE patient SET doctorid = :did WHERE patientid = :pid");
    query.bindValue(":did", doctorId);
    query.bindValue(":pid", m_patientId);

    if (!query.exec()) {
        qDebug() << "Link error:" << query.lastError().text();
        PromptDialog err("Database Error",
                         "Failed to assign doctor:\n" + query.lastError().text(),
                         this);
        err.exec();
        return;
    }

    m_selectedDoctorId = doctorId;


    // Brief pause so the user sees the confirmation, then close
    QTimer::singleShot(1000, this, [this]() { accept(); });
}

// ─────────────────────────────────────────────────────────────
//  btn_add
// ─────────────────────────────────────────────────────────────
void ViewDoctorDialog::on_btn_add_clicked()
{
    AddDoctorDialog *dlg = new AddDoctorDialog(this);
    if (dlg->exec() == QDialog::Accepted) {
        loadDoctors();

        // In selection mode, auto-assign the newly added doctor
        // (last row after name-sorted reload)
        if (m_selectionMode) {
            int lastRow = ui->table_doctor->rowCount() - 1;
            if (lastRow >= 0) {
                ui->table_doctor->selectRow(lastRow);
                onDoctorRowClicked(lastRow, 0);
            }
        }
    }
    delete dlg;
}

// ─────────────────────────────────────────────────────────────
//  btn_edit
// ─────────────────────────────────────────────────────────────
void ViewDoctorDialog::on_btn_edit_clicked()
{
    int row = ui->table_doctor->currentRow();
    if (row < 0) {
        PromptDialog p("Edit Doctor", "Please select a doctor first.", this);
        p.exec();
        return;
    }

    QString doctorId = ui->table_doctor->item(row, 0)->text(); // column 0 = doctorid

    EditDoctorDialog *dlg = new EditDoctorDialog(doctorId, this);
    if (dlg->exec() == QDialog::Accepted) {
        loadDoctors();   // refresh table after save
    }
    delete dlg;
}

// ─────────────────────────────────────────────────────────────
//  btn_delete
// ─────────────────────────────────────────────────────────────
void ViewDoctorDialog::on_btn_delete_clicked()
{
    int row = ui->table_doctor->currentRow();
    if (row < 0) {
        PromptDialog p("Delete Doctor", "Please select a doctor first.", this);
        p.exec();
        return;
    }

    QString id   = ui->table_doctor->item(row, 0)->text();
    QString name = ui->table_doctor->item(row, 1)->text();

    PromptDialog confirm("Delete Doctor",
                         "Are you sure you want to delete Dr. " + name + "?",
                         this);
    if (confirm.exec() != QDialog::Accepted)
        return;

    QSqlQuery query(db);
    query.prepare("DELETE FROM doctor WHERE doctorid = :id");
    query.bindValue(":id", id);
    if (query.exec()) {
        loadDoctors();
    } else {
        qDebug() << "Delete error:" << query.lastError().text();
        PromptDialog err("Database Error",
                         "Failed to delete doctor:\n" + query.lastError().text(),
                         this);
        err.exec();
    }
}

// ─────────────────────────────────────────────────────────────
//  btn_view
// ─────────────────────────────────────────────────────────────
void ViewDoctorDialog::on_btn_view_clicked()
{
    int row = ui->table_doctor->currentRow();
    if (row < 0) {
        PromptDialog p("View Doctor", "Please select a doctor first.", this);
        p.exec();
        return;
    }
    QString doctorId = ui->table_doctor->item(row, 0)->text();
    DoctorDetailDialog *dlg = new DoctorDetailDialog(doctorId, this);
    dlg->exec();
    delete dlg;
}

// ─────────────────────────────────────────────────────────────
//  btn_close
// ─────────────────────────────────────────────────────────────
void ViewDoctorDialog::on_btn_close_clicked()
{
    reject();
}
