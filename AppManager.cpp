#include "AppManager.h"
#include "welcomedialog.h"
#include "homescreendialog.h"
#include "measuredialog.h"
#include "calculatordialog.h"
#include "printdialog.h"
#include "preferencesdialog.h"

welcomeDialog*     AppManager::welcome     = nullptr;
HomeScreenDialog*  AppManager::home        = nullptr;
MeasureDialog*     AppManager::measure     = nullptr;
CalculatorDialog*  AppManager::calculator  = nullptr;
PrintDialog*       AppManager::print       = nullptr;
PreferencesDialog* AppManager::preferences = nullptr;

void AppManager::initializeEssential()
{
    welcome = new welcomeDialog();   // only the first screen — must be instant
}

void AppManager::initializeRest()
{
    home        = new HomeScreenDialog();
    measure     = new MeasureDialog();
    calculator  = new CalculatorDialog();
    print       = new PrintDialog();
    preferences = new PreferencesDialog();

    home->hide();
    measure->hide();
    calculator->hide();
    print->hide();
    preferences->hide();
}

void AppManager::destroy()
{
    delete welcome;
    delete home;
    delete measure;
    delete calculator;
    delete print;
    delete preferences;
}
