#include "adddoctordialog.h"
#include "ui_adddoctordialog.h"
#include "promptdialog.h"

AddDoctorDialog::AddDoctorDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddDoctorDialog)
{
    ui->setupUi(this);

    if (!openDatabase()) {
        PromptDialog dlg("Database Error", "Failed to connect to database!", this);
        dlg.exec();
        return;
    }

    ui->comboBox_primaryFormula->clear();
    ui->comboBox_primaryFormula->addItems({"SRKT", "HOLLADAY", "HOFFER Q", "BINKHORST"});

    loadLensPresets();

    ui->lineEdit_docName->installEventFilter(this);
}

AddDoctorDialog::~AddDoctorDialog()
{
    if (db.isOpen())
        db.close();
    delete ui;
}

bool AddDoctorDialog::openDatabase()
{
    if (QSqlDatabase::contains("doctor_conn")) {
        db = QSqlDatabase::database("doctor_conn");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE", "doctor_conn");
        db.setDatabaseName("/home/amt-06/Ascan/acuaxis.db");
    }

    if (!db.open()) {
        qDebug() << "DB Error:" << db.lastError().text();
        return false;
    }
    return true;
}

void AddDoctorDialog::loadLensPresets()
{
    QStringList iolNames;
    iolNames << "";

    QSqlQuery query("SELECT iol FROM lens ORDER BY iol ASC", db);
    while (query.next()) {
        iolNames << query.value(0).toString();
    }

    ui->comboBox_lensPresetOne->clear();
    ui->comboBox_lensPresetTwo->clear();
    ui->comboBox_lensPresetThree->clear();

    ui->comboBox_lensPresetOne->addItems(iolNames);
    ui->comboBox_lensPresetTwo->addItems(iolNames);
    ui->comboBox_lensPresetThree->addItems(iolNames);
}

QString AddDoctorDialog::generateDoctorID()
{
    QSqlQuery query(db);
    query.exec("SELECT MAX(id) FROM doctor");
    int nextId = 1;
    if (query.next()) {
        nextId = query.value(0).toInt() + 1;
    }
    return QString("DOC-%1").arg(nextId, 4, 10, QChar('0'));
}

bool AddDoctorDialog::saveDoctor()
{
    QString name            = ui->lineEdit_docName->text().trimmed();
    QString lensPresetOne   = ui->comboBox_lensPresetOne->currentText();
    QString lensPresetTwo   = ui->comboBox_lensPresetTwo->currentText();
    QString lensPresetThree = ui->comboBox_lensPresetThree->currentText();
    QString formula         = ui->comboBox_primaryFormula->currentText();

    if (name.isEmpty()) {
        PromptDialog dlg("Validation", "Doctor Name cannot be empty!", this);
        dlg.exec();
        return false;
    }

    QString doctorID = generateDoctorID();

    QSqlQuery query(db);
    query.prepare(
        "INSERT INTO doctor (doctorid, name, lenspresetone, lenspresettwo, "
        "lenspresetthree, formula) "
        "VALUES (:doctorid, :name, :lenspresetone, :lenspresettwo, "
        ":lenspresetthree, :formula)"
        );

    query.bindValue(":doctorid",        doctorID);
    query.bindValue(":name",            name);
    query.bindValue(":lenspresetone",   lensPresetOne);
    query.bindValue(":lenspresettwo",   lensPresetTwo);
    query.bindValue(":lenspresetthree", lensPresetThree);
    query.bindValue(":formula",         formula);

    if (!query.exec()) {
        qDebug() << "Insert Error:" << query.lastError().text();
        PromptDialog dlg("Database Error",
                         "Failed to save doctor:\n" + query.lastError().text(), this);
        dlg.exec();
        return false;
    }

    ui->snackbar->setText("Doctor saved successfully! ID: " + doctorID);
    return true;
}

void AddDoctorDialog::clearFields()
{
    ui->lineEdit_docName->clear();
    ui->comboBox_lensPresetOne->setCurrentIndex(0);
    ui->comboBox_lensPresetTwo->setCurrentIndex(0);
    ui->comboBox_lensPresetThree->setCurrentIndex(0);
    ui->comboBox_primaryFormula->setCurrentIndex(0);
}

void AddDoctorDialog::on_btn_save_clicked()
{
    if (saveDoctor()) {
        clearFields();
    }
}

void AddDoctorDialog::on_btn_cancel_clicked()
{
    this->reject();
}

bool AddDoctorDialog::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        if (obj == ui->lineEdit_docName) {
            QLineEdit *le = qobject_cast<QLineEdit*>(obj);
            Keypad *kp = new Keypad(le, this);
            kp->exec();
            delete kp;
            return true;
        }
    }
    return QDialog::eventFilter(obj, event);
}
