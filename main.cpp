// #include "welcomedialog.h"

// #include <QApplication>

// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);
//     welcomedialog w;
//     w.show();
//     return a.exec();
// }




#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

#include "addpatientdialog.h"
#include "adddoctordialog.h"
#include "addlensdialog.h"
#include "keypad.h"
#include "numericpad.h"
#include "welcomedialog.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db =
        QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("acuaxis.db");

    if(!db.open())
    {
        qDebug() << "Database Error:"
                 << db.lastError().text();

        return -1;
    }

    qDebug() << "Database Connected";

    welcomedialog w;
    w.show();

    return a.exec();
}
