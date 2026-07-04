#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QTimer>
#include "addpatientdialog.h"
#include "adddoctordialog.h"
#include "addlensdialog.h"
#include "keypad.h"
#include "numericpad.h"
#include "welcomedialog.h"
#include "AppManager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setOverrideCursor(Qt::ArrowCursor);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("acuaxis.db");
    if (!db.open()) {
        qDebug() << "Database Error:" << db.lastError().text();
        return -1;
    }
    qDebug() << "Database Connected";

    // ── Step 1: create + show ONLY the welcome screen — fast ──
    AppManager::initializeEssential();
    AppManager::welcome->show();

    // ── Step 2: force the welcome screen to actually paint NOW,
    //    before we start the heavy background work ─────────────
    qApp->processEvents();

    // ── Step 3: load the rest (Home/Measure/Calculator/Print/
    //    Preferences) right after, without blocking the paint ──
    QTimer::singleShot(0, []() {
        AppManager::initializeRest();
    });

    int ret = a.exec();
    AppManager::destroy();
    return ret;
}
