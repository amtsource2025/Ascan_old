#ifndef APPMANAGER_H
#define APPMANAGER_H

#include "welcomedialog.h"
#include "homescreendialog.h"
#include "measuredialog.h"
#include "calculatordialog.h"
#include "printdialog.h"
#include "preferencesdialog.h"

class AppManager
{
public:

    // static void initialize();
    // static void destroy();

    static void initializeEssential();   // creates + shows ONLY welcome — fast
    static void initializeRest();        // creates the heavy dialogs — deferred
    static void destroy();

    static welcomeDialog *welcome;
    static HomeScreenDialog *home;
    static MeasureDialog *measure;
    static CalculatorDialog *calculator;
    static PrintDialog *print;
    static PreferencesDialog *preferences;
};

#endif
