#include "viewpatientdialog.h"
#include "ui_viewpatientdialog.h"
#include "addpatientdialog.h"
#include "promptdialog.h"
#include "editpatientdialog.h"
#include "patientdetaildialog.h"


// ─────────────────────────────────────────────────────────────
//  Constructor / Destructor
// ─────────────────────────────────────────────────────────────
ViewPatientDialog::ViewPatientDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewPatientDialog)
    , clockTimer(new QTimer(this))
    , db(QSqlDatabase::database())   // ✅ reuse main.cpp's connection
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    if (!db.isOpen()) {
        qDebug() << "ViewPatientDialog: Database is not open!";
    }

    // ── Clock ─────────────────────────────────────────────────
    connect(clockTimer, &QTimer::timeout, this, &ViewPatientDialog::updateTime);
    clockTimer->start(1000);
    updateTime();

    // ── Table setup ───────────────────────────────────────────
    ui->table_patient->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_patient->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->table_patient->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->table_patient->horizontalHeader()->setStretchLastSection(true);
    ui->table_patient->verticalHeader()->setVisible(false);

    loadPatients();
}

ViewPatientDialog::~ViewPatientDialog()
{
    // ✅ Do NOT close db here — it's owned by main.cpp
    delete ui;
}

// ─────────────────────────────────────────────────────────────
//  Load patients into table
// ─────────────────────────────────────────────────────────────
void ViewPatientDialog::loadPatients()
{
    ui->table_patient->clearContents();
    ui->table_patient->setRowCount(0);
    ui->table_patient->setColumnCount(6);
    ui->table_patient->setHorizontalHeaderLabels(
        {"ID", "PatientID", "Name", "Gender", "Age", "Phone"});

    QSqlQuery query(db);
    query.prepare(
        "SELECT id, custPatientID, name, gender, age, phone "
        "FROM patient ORDER BY name ASC");

    if (!query.exec()) {
        qDebug() << "loadPatients error:" << query.lastError().text();
        return;
    }

    int row = 0;
    while (query.next()) {
        ui->table_patient->insertRow(row);
        for (int col = 0; col < 6; ++col) {
            auto *item = new QTableWidgetItem(query.value(col).toString());
            if (col == 3) {  // Gender: 0 = Male, 1 = Female
                item->setText(query.value(col).toInt() == 0 ? "Male" : "Female");
            }
            ui->table_patient->setItem(row, col, item);
        }
        ++row;
    }
}

// ─────────────────────────────────────────────────────────────
//  Clock
// ─────────────────────────────────────────────────────────────
void ViewPatientDialog::updateTime()
{
    ui->lbl_time->setText(QTime::currentTime().toString("hh:mm"));
}

// ─────────────────────────────────────────────────────────────
//  Buttons
// ─────────────────────────────────────────────────────────────
void ViewPatientDialog::on_btn_add_clicked()
{
    AddPatientDialog *dlg = new AddPatientDialog(this);
    if (dlg->exec() == QDialog::Accepted) {
        loadPatients();
    }
    delete dlg;
}

void ViewPatientDialog::on_btn_edit_clicked()
{
    int row = ui->table_patient->currentRow();
    if (row < 0) {
        PromptDialog p("Edit Patient", "Please select a patient first.", this);
        p.exec();
        return;
    }

    int dbId = ui->table_patient->item(row, 0)->text().toInt();
    EditPatientDialog *dlg = new EditPatientDialog(dbId, this);
    if (dlg->exec() == QDialog::Accepted) {
        loadPatients();
    }
    delete dlg;
}

void ViewPatientDialog::on_btn_delete_clicked()
{
    int row = ui->table_patient->currentRow();
    if (row < 0) {
        PromptDialog p("Delete Patient", "Please select a patient first.", this);
        p.exec();
        return;
    }

    QString id   = ui->table_patient->item(row, 0)->text();  // column 0 = id
    QString name = ui->table_patient->item(row, 2)->text();

    PromptDialog confirm("Delete Patient",
                         "Are you sure you want to delete patient: " + name + "?",
                         this);
    if (confirm.exec() != QDialog::Accepted)
        return;

    QSqlQuery query(db);
    query.prepare("DELETE FROM patient WHERE id = :id");  // ✅ fixed: 'id' not 'patientid'
    query.bindValue(":id", id);
    if (query.exec()) {
        loadPatients();
    } else {
        qDebug() << "Delete error:" << query.lastError().text();
    }
}

void ViewPatientDialog::on_btn_view_clicked()
{
    int row = ui->table_patient->currentRow();
    if (row < 0) {
        PromptDialog p("View Patient", "Please select a patient first.", this);
        p.exec();
        return;
    }
    int dbId = ui->table_patient->item(row, 0)->text().toInt();
    PatientDetailDialog *dlg = new PatientDetailDialog(dbId, this);
    dlg->exec();
    delete dlg;
}

void ViewPatientDialog::on_btn_close_clicked()
{
    reject();
}
