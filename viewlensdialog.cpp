#include "viewlensdialog.h"
#include "ui_viewlensdialog.h"
#include "promptdialog.h"
#include "editlensdialog.h"

// ─────────────────────────────────────────────────────────────
//  Constructor / Destructor
// ─────────────────────────────────────────────────────────────
ViewLensDialog::ViewLensDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewLensDialog)
    , clockTimer(new QTimer(this))
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    if (!openDatabase()) {
        qDebug() << "ViewLensDialog: Failed to open database!";
    }

    // ── Clock ─────────────────────────────────────────────────
    connect(clockTimer, &QTimer::timeout, this, &ViewLensDialog::updateTime);
    clockTimer->start(1000);
    updateTime();

    // ── Table setup ───────────────────────────────────────────
    // Columns from UI: IOL | Company | Type | ASRKT | ASRKII | Acd | Sf | a0 | a1 | a2
    ui->table_lenses->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_lenses->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->table_lenses->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->table_lenses->horizontalHeader()->setStretchLastSection(true);
    ui->table_lenses->verticalHeader()->setVisible(false);

    loadLenses();
}

ViewLensDialog::~ViewLensDialog()
{
    if (db.isOpen())
        db.close();
    delete ui;
}

// ─────────────────────────────────────────────────────────────
//  Database
// ─────────────────────────────────────────────────────────────
bool ViewLensDialog::openDatabase()
{
    const QString connName = "viewlens_conn";
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
//  Load lenses into table
// ─────────────────────────────────────────────────────────────
void ViewLensDialog::loadLenses()
{
    ui->table_lenses->clearContents();
    ui->table_lenses->setRowCount(0);

    ui->table_lenses->setColumnCount(11);
    ui->table_lenses->setHorizontalHeaderLabels(
        {"S.No", "IOL", "Company", "Type", "ASRKT", "ASRKII", "Acd", "Sf", "a0", "a1", "a2"});

    QSqlQuery query(db);
    query.prepare(
        "SELECT iol, company, type, asrkt, asrkii, acd, sf, a0, a1, a2 "
        "FROM lens ORDER BY iol ASC");

    if (!query.exec()) {
        qDebug() << "loadLenses error:" << query.lastError().text();
        return;
    }

    int row = 0;
    while (query.next()) {
        ui->table_lenses->insertRow(row);

        auto *snoItem = new QTableWidgetItem(QString::number(row + 1));
        snoItem->setTextAlignment(Qt::AlignCenter);
        ui->table_lenses->setItem(row, 0, snoItem);

        for (int col = 0; col < 10; ++col) {
            ui->table_lenses->setItem(
                row, col + 1,
                new QTableWidgetItem(query.value(col).toString()));
        }
        ++row;
    }
}

// ─────────────────────────────────────────────────────────────
//  Clock
// ─────────────────────────────────────────────────────────────
void ViewLensDialog::updateTime()
{
    ui->lbl_time->setText(QTime::currentTime().toString("hh:mm"));
}

// ─────────────────────────────────────────────────────────────
//  Buttons
// ─────────────────────────────────────────────────────────────
void ViewLensDialog::on_btn_add_clicked()
{
    // TODO: open AddLensDialog
    PromptDialog p("Add Lens", "Add Lens — not yet implemented.", this);
    p.exec();
}

void ViewLensDialog::on_btn_edit_clicked()
{
    int row = ui->table_lenses->currentRow();
    if (row < 0) {
        PromptDialog p("Edit Lens", "Please select a lens first.", this);
        p.exec();
        return;
    }

    QString iol = ui->table_lenses->item(row, 1)->text(); // column 0 = iol

    EditLensDialog *dlg = new EditLensDialog(iol, this);
    if (dlg->exec() == QDialog::Accepted) {
        loadLenses();    // refresh table after save
    }
    delete dlg;
}

void ViewLensDialog::on_btn_delete_clicked()
{
    int row = ui->table_lenses->currentRow();
    if (row < 0) {
        PromptDialog p("Delete Lens", "Please select a lens first.", this);
        p.exec();
        return;
    }

    QString iol = ui->table_lenses->item(row, 1)->text();

    PromptDialog confirm("Delete Lens",
                         "Are you sure you want to delete lens: " + iol + "?",
                         this);
    if (confirm.exec() != QDialog::Accepted)
        return;

    QSqlQuery query(db);
    query.prepare("DELETE FROM lens WHERE iol = :iol");
    query.bindValue(":iol", iol);
    if (query.exec()) {
        loadLenses();
    } else {
        qDebug() << "Delete lens error:" << query.lastError().text();
    }
}

void ViewLensDialog::on_btn_close_clicked()
{
    reject();
}
