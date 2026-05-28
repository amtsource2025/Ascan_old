#include "addlensdialog.h"
#include "ui_addlensdialog.h"
#include "promptdialog.h"

AddLensDialog::AddLensDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddLensDialog)
{
    ui->setupUi(this);

    if (!openDatabase()) {
        PromptDialog dlg("Database Error", "Failed to connect to database!", this);
        dlg.exec();
        return;
    }

    ui->comboBox_lensType->clear();
    ui->comboBox_lensType->addItems({"Anterior", "Posterior"});

    ui->lineEdit_asrkt->setText("118.01");
    ui->lineEdit_asrkii->setText("117.9");
    ui->lineEdit_acd->setText("4.97");
    ui->lineEdit_sf->setText("1.23");
    ui->lineEdit_a0->setText("0.4");
    ui->lineEdit_a1->setText("0.1");
    ui->lineEdit_a2->setText("1.28");

    ui->lineEdit_iol->installEventFilter(this);
    ui->lineEdit_company->installEventFilter(this);
    ui->lineEdit_asrkt->installEventFilter(this);
    ui->lineEdit_asrkii->installEventFilter(this);
    ui->lineEdit_acd->installEventFilter(this);
    ui->lineEdit_sf->installEventFilter(this);
    ui->lineEdit_a0->installEventFilter(this);
    ui->lineEdit_a1->installEventFilter(this);
    ui->lineEdit_a2->installEventFilter(this);
}

AddLensDialog::~AddLensDialog()
{
    if (db.isOpen())
        db.close();
    delete ui;
}

bool AddLensDialog::openDatabase()
{
    if (QSqlDatabase::contains("lens_conn")) {
        db = QSqlDatabase::database("lens_conn");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE", "lens_conn");
        db = QSqlDatabase::database();
    }

    if (!db.open()) {
        qDebug() << "DB Error:" << db.lastError().text();
        return false;
    }
    return true;
}

bool AddLensDialog::saveLens()
{
    QString iol     = ui->lineEdit_iol->text().trimmed();
    QString company = ui->lineEdit_company->text().trimmed();
    int     type    = ui->comboBox_lensType->currentIndex();

    double asrkt  = ui->lineEdit_asrkt->text().toDouble();
    double asrkii = ui->lineEdit_asrkii->text().toDouble();
    double acd    = ui->lineEdit_acd->text().toDouble();
    double sf     = ui->lineEdit_sf->text().toDouble();
    double a0     = ui->lineEdit_a0->text().toDouble();
    double a1     = ui->lineEdit_a1->text().toDouble();
    double a2     = ui->lineEdit_a2->text().toDouble();

    if (iol.isEmpty()) {
        PromptDialog dlg("Validation", "Lens IOL name cannot be empty!", this);
        dlg.exec();
        return false;
    }

    QSqlQuery query(db);
    query.prepare(
        "INSERT INTO lens (iol, company, type, asrkt, asrkii, acd, sf, a0, a1, a2) "
        "VALUES (:iol, :company, :type, :asrkt, :asrkii, :acd, :sf, :a0, :a1, :a2)"
        );

    query.bindValue(":iol",     iol);
    query.bindValue(":company", company);
    query.bindValue(":type",    type);
    query.bindValue(":asrkt",   asrkt);
    query.bindValue(":asrkii",  asrkii);
    query.bindValue(":acd",     acd);
    query.bindValue(":sf",      sf);
    query.bindValue(":a0",      a0);
    query.bindValue(":a1",      a1);
    query.bindValue(":a2",      a2);

    if (!query.exec()) {
        qDebug() << "Insert Error:" << query.lastError().text();
        PromptDialog dlg("Database Error",
                         "Failed to save lens:\n" + query.lastError().text(), this);
        dlg.exec();
        return false;
    }

    return true;
}

void AddLensDialog::clearFields()
{
    ui->lineEdit_iol->clear();
    ui->lineEdit_company->clear();
    ui->comboBox_lensType->setCurrentIndex(0);
    ui->lineEdit_asrkt->setText("118.01");
    ui->lineEdit_asrkii->setText("117.9");
    ui->lineEdit_acd->setText("4.97");
    ui->lineEdit_sf->setText("1.23");
    ui->lineEdit_a0->setText("0.4");
    ui->lineEdit_a1->setText("0.1");
    ui->lineEdit_a2->setText("1.28");
}

void AddLensDialog::on_btn_save_clicked()
{
    if (saveLens()) {
        clearFields();
    }
}

void AddLensDialog::on_btn_cancel_clicked()
{
    this->reject();
}

bool AddLensDialog::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {

        if (obj == ui->lineEdit_iol ||
            obj == ui->lineEdit_company)
        {
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
