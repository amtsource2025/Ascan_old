#include "addpatientdialog.h"
#include "ui_addpatientdialog.h"
#include "promptdialog.h"
#include "viewdoctordialog.h"

AddPatientDialog::AddPatientDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddPatientDialog)
{
    ui->setupUi(this);

    if (!openDatabase()) {
        PromptDialog dlg("Database Error", "Failed to connect to database!", this);
        dlg.exec();
    }

    // ── Enforce mutually exclusive checkboxes ─────────────────
    // Gender: Male / Female — only one at a time
    ui->checkBox_male->setChecked(true);
    ui->checkBox_female->setChecked(false);
    connect(ui->checkBox_male, &QCheckBox::toggled, this, [this](bool checked) {
        if (checked) {
            QSignalBlocker b(ui->checkBox_female);
            ui->checkBox_female->setChecked(false);
        } else {
            // Prevent both unchecked — re-check Female
            if (!ui->checkBox_female->isChecked()) {
                QSignalBlocker b(ui->checkBox_male);
                ui->checkBox_male->setChecked(true);
            }
        }
    });
    connect(ui->checkBox_female, &QCheckBox::toggled, this, [this](bool checked) {
        if (checked) {
            QSignalBlocker b(ui->checkBox_male);
            ui->checkBox_male->setChecked(false);
        } else {
            if (!ui->checkBox_male->isChecked()) {
                QSignalBlocker b(ui->checkBox_female);
                ui->checkBox_female->setChecked(true);
            }
        }
    });

    // Operating Method: Aphakic / Phakic / Dense — only one at a time
    ui->checkBox_phakic->setChecked(true);
    ui->checkBox_aphakic->setChecked(false);
    ui->checkBox_dense->setChecked(false);
    auto exclusiveMethod = [this](QCheckBox *selected,
                                  QCheckBox *other1,
                                  QCheckBox *other2) {
        connect(selected, &QCheckBox::toggled, this, [selected, other1, other2](bool checked) {
            if (checked) {
                QSignalBlocker b1(other1);
                QSignalBlocker b2(other2);
                other1->setChecked(false);
                other2->setChecked(false);
            } else {
                // Prevent all unchecked — re-check self
                if (!other1->isChecked() && !other2->isChecked()) {
                    QSignalBlocker b(selected);
                    selected->setChecked(true);
                }
            }
        });
    };
    exclusiveMethod(ui->checkBox_aphakic, ui->checkBox_phakic,  ui->checkBox_dense);
    exclusiveMethod(ui->checkBox_phakic,  ui->checkBox_aphakic, ui->checkBox_dense);
    exclusiveMethod(ui->checkBox_dense,   ui->checkBox_aphakic, ui->checkBox_phakic);

    // Operating Mode: Contact / Immersion — only one at a time
    ui->checkBox_contact->setChecked(true);
    ui->checkBox_immersion->setChecked(false);
    connect(ui->checkBox_contact, &QCheckBox::toggled, this, [this](bool checked) {
        if (checked) {
            QSignalBlocker b(ui->checkBox_immersion);
            ui->checkBox_immersion->setChecked(false);
        } else {
            if (!ui->checkBox_immersion->isChecked()) {
                QSignalBlocker b(ui->checkBox_contact);
                ui->checkBox_contact->setChecked(true);
            }
        }
    });
    connect(ui->checkBox_immersion, &QCheckBox::toggled, this, [this](bool checked) {
        if (checked) {
            QSignalBlocker b(ui->checkBox_contact);
            ui->checkBox_contact->setChecked(false);
        } else {
            if (!ui->checkBox_contact->isChecked()) {
                QSignalBlocker b(ui->checkBox_immersion);
                ui->checkBox_immersion->setChecked(true);
            }
        }
    });

    // Operating Eye: Left / Right — only one at a time
    ui->checkBox_left->setChecked(true);
    ui->checkBox_right->setChecked(false);
    connect(ui->checkBox_left, &QCheckBox::toggled, this, [this](bool checked) {
        if (checked) {
            QSignalBlocker b(ui->checkBox_right);
            ui->checkBox_right->setChecked(false);
        } else {
            if (!ui->checkBox_right->isChecked()) {
                QSignalBlocker b(ui->checkBox_left);
                ui->checkBox_left->setChecked(true);
            }
        }
    });
    connect(ui->checkBox_right, &QCheckBox::toggled, this, [this](bool checked) {
        if (checked) {
            QSignalBlocker b(ui->checkBox_left);
            ui->checkBox_left->setChecked(false);
        } else {
            if (!ui->checkBox_left->isChecked()) {
                QSignalBlocker b(ui->checkBox_right);
                ui->checkBox_right->setChecked(true);
            }
        }
    });

    // ── Event filters for on-screen input ────────────────────
    ui->lineEdit_CustPatId->installEventFilter(this);
    ui->lineEdit_patName->installEventFilter(this);
    ui->lineEdit_phone->installEventFilter(this);

    ui->lineEdit_age->installEventFilter(this);
    ui->lineEdit_lk1->installEventFilter(this);
    ui->lineEdit_lk2->installEventFilter(this);
    ui->lineEdit_lk->installEventFilter(this);
    ui->lineEdit_rk1->installEventFilter(this);
    ui->lineEdit_rk2->installEventFilter(this);
    ui->lineEdit_rk->installEventFilter(this);
}

AddPatientDialog::~AddPatientDialog()
{
    delete ui;
}

bool AddPatientDialog::openDatabase()
{
    db = QSqlDatabase::database(); // ✅ just reuse main.cpp's connection
    if (!db.isOpen()) {
        qDebug() << "DB Error: database is not open";
        return false;
    }
    return true;
}

QString AddPatientDialog::generatePatientID()
{
    QSqlQuery query(db);
    query.exec("SELECT MAX(id) FROM patient");
    int nextId = 1;
    if (query.next()) {
        nextId = query.value(0).toInt() + 1;
    }
    return QString("PAT-%1").arg(nextId, 4, 10, QChar('0'));
}

bool AddPatientDialog::savePatient()
{
    QString custPatientID = ui->lineEdit_CustPatId->text().trimmed();
    QString name          = ui->lineEdit_patName->text().trimmed();
    int     age           = ui->lineEdit_age->text().toInt();
    QString phone         = ui->lineEdit_phone->text().trimmed();

    // ── Read exclusive checkbox values ────────────────────────
    int gender = ui->checkBox_male->isChecked() ? 0 : 1;

    int operatingMethod = 0;
    if      (ui->checkBox_aphakic->isChecked()) operatingMethod = 0;
    else if (ui->checkBox_phakic->isChecked())  operatingMethod = 1;
    else if (ui->checkBox_dense->isChecked())   operatingMethod = 2;

    int operatingMode = ui->checkBox_contact->isChecked() ? 0 : 1;
    int operatingEye  = ui->checkBox_left->isChecked()    ? 0 : 1;

    double lk1 = ui->lineEdit_lk1->text().toDouble();
    double lk2 = ui->lineEdit_lk2->text().toDouble();
    double lk  = ui->lineEdit_lk->text().toDouble();
    double rk1 = ui->lineEdit_rk1->text().toDouble();
    double rk2 = ui->lineEdit_rk2->text().toDouble();
    double rk  = ui->lineEdit_rk->text().toDouble();

    if (custPatientID.isEmpty()) {
        PromptDialog dlg("Validation", "Customer Patient ID cannot be empty!", this);
        dlg.exec();
        return false;
    }

    if (name.isEmpty()) {
        PromptDialog dlg("Validation", "Patient Name cannot be empty!", this);
        dlg.exec();
        return false;
    }

    QString patientID = generatePatientID();

    QSqlQuery query(db);
    query.prepare(
        "INSERT INTO patient "
        "(custPatientID, name, phone, rk1, rk2, rk, lk1, lk2, lk, "
        " operatingeye, operatingmethod, operatingmode, age, gender, patientid) "
        "VALUES "
        "(:custPatientID, :name, :phone, :rk1, :rk2, :rk, :lk1, :lk2, :lk, "
        " :operatingeye, :operatingmethod, :operatingmode, :age, :gender, :patientid)"
        );

    query.bindValue(":custPatientID",    custPatientID);
    query.bindValue(":name",             name);
    query.bindValue(":phone",            phone);
    query.bindValue(":rk1",             rk1);
    query.bindValue(":rk2",             rk2);
    query.bindValue(":rk",              rk);
    query.bindValue(":lk1",             lk1);
    query.bindValue(":lk2",             lk2);
    query.bindValue(":lk",              lk);
    query.bindValue(":operatingeye",    operatingEye);
    query.bindValue(":operatingmethod", operatingMethod);
    query.bindValue(":operatingmode",   operatingMode);
    query.bindValue(":age",             age);
    query.bindValue(":gender",          gender);
    query.bindValue(":patientid",       patientID);

    if (!query.exec()) {
        qDebug() << "Insert Error:" << query.lastError().text();
        PromptDialog dlg("Database Error",
                         "Failed to save patient:\n" + query.lastError().text(), this);
        dlg.exec();
        return false;
    }

    // Store the generated PAT-XXXX id so the caller can retrieve it via
    // getNewPatientId() after this dialog returns QDialog::Accepted.
    m_newPatientId = patientID;

    return true;
}

void AddPatientDialog::clearFields()
{
    ui->lineEdit_CustPatId->clear();
    ui->lineEdit_patName->clear();
    ui->lineEdit_age->clear();
    ui->lineEdit_phone->clear();
    ui->lineEdit_lk1->setText("45.00");
    ui->lineEdit_lk2->setText("45.00");
    ui->lineEdit_lk->setText("45.00");
    ui->lineEdit_rk1->setText("45.00");
    ui->lineEdit_rk2->setText("45.00");
    ui->lineEdit_rk->setText("45.00");

    // Reset checkboxes to defaults (connections above keep them exclusive)
    ui->checkBox_male->setChecked(true);
    ui->checkBox_phakic->setChecked(true);
    ui->checkBox_contact->setChecked(true);
    ui->checkBox_left->setChecked(true);
}

void AddPatientDialog::on_btn_save_clicked()
{
    if (!savePatient())
        return;

    clearFields();

    PromptDialog dlg("Assign Doctor",
                     "Patient saved successfully!\n\n"
                     "Would you like to assign a default doctor for this patient?",
                     this);

    if (dlg.exec() == QDialog::Accepted) {
        ViewDoctorDialog vdd(this, m_newPatientId);
        vdd.exec();
    }

    this->accept();
}

void AddPatientDialog::on_btn_cancel_clicked()
{
    this->reject();
}

bool AddPatientDialog::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {

        if (obj == ui->lineEdit_CustPatId ||
            obj == ui->lineEdit_patName   ||
            obj == ui->lineEdit_phone)
        {
            QLineEdit *le = qobject_cast<QLineEdit*>(obj);
            Keypad *kp = new Keypad(le, this);
            kp->exec();
            delete kp;
            return true;
        }

        if (obj == ui->lineEdit_age ||
            obj == ui->lineEdit_lk1 ||
            obj == ui->lineEdit_lk2 ||
            obj == ui->lineEdit_lk  ||
            obj == ui->lineEdit_rk1 ||
            obj == ui->lineEdit_rk2 ||
            obj == ui->lineEdit_rk)
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
