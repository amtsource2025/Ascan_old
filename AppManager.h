#ifndef APPMANAGER_H
#define APPMANAGER_H

// Forward declarations only — pointers don't need full definitions here.
// This breaks the circular include: printdialog.h -> AppManager.h -> printdialog.h
class welcomeDialog;
class HomeScreenDialog;
class MeasureDialog;
class CalculatorDialog;
class PrintDialog;
class PreferencesDialog;

class AppManager
{
public:
    static void initializeEssential();   // creates + shows ONLY welcome — fast
    static void initializeRest();        // creates the heavy dialogs — deferred
    static void destroy();

    static welcomeDialog     *welcome;
    static HomeScreenDialog  *home;
    static MeasureDialog     *measure;
    static CalculatorDialog  *calculator;
    static PrintDialog       *print;
    static PreferencesDialog *preferences;
};

#endif
