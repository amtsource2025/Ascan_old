#include "viewpatientdialog.h"
#include "ui_viewpatientdialog.h"
#include "addpatientdialog.h"
#include "promptdialog.h"
#include "editpatientdialog.h"
#include "patientdetaildialog.h"
#include "homescreendialog.h"


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



    // connect(ui->table_patient,
    //         &QTableWidget::cellClicked,
    //         this,
    //         [this](int row, int)
    //         {
    //             if (row < 0)
    //                 return;

    //             const QString patientId =
    //                 ui->table_patient->item(row, 0)->text();

    //             const QString patientName =
    //                 ui->table_patient->item(row, 2)->text();

    //             PromptDialog dlg(
    //                 "Change Patient",
    //                 "Do you want to continue with the selected patient?",
    //                 this);

    //             if (dlg.exec() != QDialog::Accepted)
    //                 return;

    //             HomeScreenDialog *home =
    //                 qobject_cast<HomeScreenDialog*>(parent());

    //             if (home)
    //                 home->setCurrentPatient(patientId, patientName);

    //             accept();
    //         });


    longPressTimer = new QTimer(this);
    longPressTimer->setSingleShot(true);

    connect(longPressTimer,
            &QTimer::timeout,
            this,
            &ViewPatientDialog::onLongPressTimeout);

    ui->table_patient->viewport()->installEventFilter(this);

    loadPatients();
}

bool ViewPatientDialog::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->table_patient->viewport())
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *me =
                static_cast<QMouseEvent*>(event);

            QModelIndex index =
                ui->table_patient->indexAt(me->pos());

            if (index.isValid())
            {
                m_pressedRow = index.row();
                longPressTimer->start(1000);
            }
        }
        else if (event->type() == QEvent::MouseButtonRelease)
        {
            longPressTimer->stop();
        }
    }

    return QDialog::eventFilter(obj, event);
}

void ViewPatientDialog::onLongPressTimeout()
{
    if (m_pressedRow < 0)
        return;

    int dbId =
        ui->table_patient->item(m_pressedRow, 1)->text().toInt();

    QString patientId;



    QSqlQuery q(db);
    q.prepare("SELECT patientid FROM patient WHERE id = :id");
    q.bindValue(":id", dbId);

    if (!q.exec() || !q.next())
    {
        qDebug() << "patientId lookup failed:"
                 << q.lastError().text();
        return;
    }

    patientId = q.value(0).toString();

    QString patientName = ui->table_patient->item(m_pressedRow, 3)->text();

    PromptDialog dlg(
        "Change Patient",
        "Do you want to continue with the selected patient?\n\n"
            + patientName,
        this);

    if (dlg.exec() == QDialog::Accepted)
    {
        emit patientSelected(patientId);
        accept();
    }
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
    ui->table_patient->setColumnCount(7);
    ui->table_patient->setHorizontalHeaderLabels(
        {"S.No", "ID", "PatientID", "Name", "Gender", "Age", "Phone"});

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

        auto *snoItem = new QTableWidgetItem(QString::number(row + 1));
        snoItem->setTextAlignment(Qt::AlignCenter);
        ui->table_patient->setItem(row, 0, snoItem);

        for (int col = 0; col < 6; ++col) {
            auto *item = new QTableWidgetItem(query.value(col).toString());
            if (col == 3) {  // Gender: 0 = Male, 1 = Female
                item->setText(query.value(col).toInt() == 0 ? "Male" : "Female");
            }
            ui->table_patient->setItem(row, col + 1, item);
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

    int dbId = ui->table_patient->item(row, 1)->text().toInt();
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

    QString id   = ui->table_patient->item(row, 1)->text();  // column 0 = id
    QString name = ui->table_patient->item(row, 3)->text();

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


    int dbId = ui->table_patient->item(row, 1)->text().toInt();

    QString patientId;
    QSqlQuery q(db);
    q.prepare("SELECT patientid FROM patient WHERE id = :id");
    q.bindValue(":id", dbId);
    if (q.exec() && q.next())
        patientId = q.value(0).toString();
    else
        qDebug() << "patientId lookup failed:" << q.lastError().text();

    qDebug() << "dbId=" << dbId << "patientId=" << patientId;

    PatientDetailDialog *dlg = new PatientDetailDialog(dbId, this);
    dlg->exec();
    delete dlg;

    // if (!patientId.isEmpty())
    //     emit patientSelected(patientId);
}

void ViewPatientDialog::on_btn_close_clicked()
{
    reject();
}
