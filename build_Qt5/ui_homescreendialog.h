/********************************************************************************
** Form generated from reading UI file 'homescreendialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMESCREENDIALOG_H
#define UI_HOMESCREENDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeScreenDialog
{
public:
    QFrame *frame_sidebar;
    QPushButton *btn_currentDoctorLogo;
    QPushButton *btn_currentPatientLogo;
    QLabel *lbl_currentDoctor;
    QLabel *lbl_currentPatient;
    QLabel *lbl_currentDoctorName;
    QLabel *lbl_currentDoctorFormula;
    QTabWidget *tabWidget_currentDoctor;
    QWidget *tab;
    QLabel *lbl_iolLensOne;
    QLabel *lbl_asrktLensOne;
    QLabel *lbl_asrktiiLensOne;
    QLabel *lbl_acdLensOne;
    QLabel *lbl_sfLensOne;
    QLabel *lbl_a0LensOne;
    QLabel *lbl_a1LensOne;
    QLabel *lbl_a2LensOne;
    QLineEdit *lbl_asrktLensOneValue;
    QLineEdit *lbl_asrkiiLensOneValue;
    QLineEdit *lbl_acdLensOneValue;
    QLineEdit *lbl_sfLensOneValue;
    QLineEdit *lbl_a0LensOneValue;
    QLineEdit *lbl_a1LensOneValue;
    QLineEdit *lbl_a2LensOneValue;
    QWidget *tab_2;
    QLabel *lbl_sfLensTwo;
    QLineEdit *lbl_sfLensTwoValue;
    QLineEdit *lbl_asrktLensTwoValue;
    QLineEdit *lbl_a2LensTwoValue;
    QLineEdit *lbl_asrkiiLensTwoValue;
    QLabel *lbl_acdLensTwo;
    QLabel *lbl_asrkiiLensTwo;
    QLabel *lbl_a1LensTwo;
    QLineEdit *lbl_a0LensTwoValue;
    QLabel *lbl_a2LensTwo;
    QLineEdit *lbl_a1LensTwoValue;
    QLabel *lbl_iolLensTwo;
    QLabel *lbl_asrktLensTwo;
    QLineEdit *lbl_acdLensTwoValue;
    QLabel *lbl_a0LensTwo;
    QWidget *tab_3;
    QLabel *lbl_sfLensThree;
    QLineEdit *lbl_sfLensThreeValue;
    QLineEdit *lbl_asrktLensThreeValue;
    QLineEdit *lbl_a2LensThreeValue;
    QLineEdit *lbl_asrkiiLensThreeValue;
    QLabel *lbl_acdLensThree;
    QLabel *lbl_asrkiiLensThree;
    QLabel *lbl_a1LensThree;
    QLineEdit *lbl_a0LensThreeValue;
    QLabel *lbl_a2LensThree;
    QLineEdit *lbl_a1LensThreeValue;
    QLabel *lbl_iolLensThree;
    QLabel *lbl_asrktLensThree;
    QLineEdit *lbl_acdLensThreeValue;
    QLabel *lbl_a0LensThree;
    QPushButton *btn_currentDoctorMore;
    QPushButton *btn_currentPatientMore;
    QLabel *lbl_currentPatientName;
    QLineEdit *lbl_currentPatientLK1Value;
    QLabel *lbl_currentPatientLK1;
    QLabel *lbl_currentPatientLK2;
    QLineEdit *lbl_currentPatientLK2Value;
    QLabel *lbl_currentPatientLK;
    QLineEdit *lbl_currentPatientLKValue;
    QLabel *lbl_currentPatientRK2;
    QLabel *lbl_currentPatientRK1;
    QLineEdit *lbl_currentPatientRKValue;
    QLineEdit *lbl_currentPatientRK1Value;
    QLineEdit *lbl_currentPatientRK2Value;
    QLabel *lbl_currentPatientRK;
    QPushButton *btn_currentPatientChooser;
    QPushButton *btn_currentDoctorChooser;
    QPushButton *btn_currentDocAdd;
    QPushButton *btn_currentDocEdit;
    QPushButton *btn_currentDocView;
    QPushButton *btn_currentPatientAdd;
    QPushButton *btn_currentPatientEdit;
    QPushButton *btn_currentPatientView;
    QLabel *snackbar;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *btn_calculator;
    QLabel *lbl_calculator;
    QPushButton *btn_measure;
    QLabel *lbl_measure;
    QPushButton *btn_print;
    QLabel *lbl_print;
    QPushButton *btn_doctors;
    QLabel *lbl_doctors;
    QPushButton *btn_patients;
    QLabel *lbl_patients;
    QPushButton *btn_lenses;
    QLabel *lbl_lenses;
    QPushButton *btn_settings;
    QLabel *lbl_settings;
    QPushButton *btn_calibrate;
    QLabel *lbl_calibrate;
    QPushButton *btn_back;
    QWidget *page_2;
    QLabel *lbl_currentPatient_2;
    QTableWidget *table_patients;
    QPushButton *btn_currentPatientLoad;
    QPushButton *btn_currentPatientChooserExit;
    QWidget *page_3;
    QTableWidget *table_doctors;
    QLabel *lbl_currentPatient_3;
    QPushButton *btn_currentDoctorLoad;
    QPushButton *btn_currentDoctorChooserExit;
    QLabel *lbl_time;
    QLabel *lbl_lenses_2;
    QLabel *label;

    void setupUi(QDialog *HomeScreenDialog)
    {
        if (HomeScreenDialog->objectName().isEmpty())
            HomeScreenDialog->setObjectName(QString::fromUtf8("HomeScreenDialog"));
        HomeScreenDialog->resize(1280, 720);
        HomeScreenDialog->setStyleSheet(QString::fromUtf8("background-image: url(:/images/5.png);"));
        frame_sidebar = new QFrame(HomeScreenDialog);
        frame_sidebar->setObjectName(QString::fromUtf8("frame_sidebar"));
        frame_sidebar->setGeometry(QRect(0, 0, 351, 681));
        frame_sidebar->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);\n"
"background-image:url(:/images/empty.png)"));
        frame_sidebar->setFrameShape(QFrame::StyledPanel);
        frame_sidebar->setFrameShadow(QFrame::Raised);
        btn_currentDoctorLogo = new QPushButton(frame_sidebar);
        btn_currentDoctorLogo->setObjectName(QString::fromUtf8("btn_currentDoctorLogo"));
        btn_currentDoctorLogo->setGeometry(QRect(0, 60, 55, 55));
        btn_currentDoctorLogo->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/surgeon-icon.png);"));
        btn_currentPatientLogo = new QPushButton(frame_sidebar);
        btn_currentPatientLogo->setObjectName(QString::fromUtf8("btn_currentPatientLogo"));
        btn_currentPatientLogo->setGeometry(QRect(0, 440, 55, 55));
        btn_currentPatientLogo->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/patient-icon.png);"));
        lbl_currentDoctor = new QLabel(frame_sidebar);
        lbl_currentDoctor->setObjectName(QString::fromUtf8("lbl_currentDoctor"));
        lbl_currentDoctor->setGeometry(QRect(10, 30, 160, 17));
        lbl_currentDoctor->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_currentPatient = new QLabel(frame_sidebar);
        lbl_currentPatient->setObjectName(QString::fromUtf8("lbl_currentPatient"));
        lbl_currentPatient->setGeometry(QRect(10, 420, 140, 17));
        lbl_currentPatient->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_currentDoctorName = new QLabel(frame_sidebar);
        lbl_currentDoctorName->setObjectName(QString::fromUtf8("lbl_currentDoctorName"));
        lbl_currentDoctorName->setGeometry(QRect(0, 120, 250, 17));
        lbl_currentDoctorName->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_currentDoctorFormula = new QLabel(frame_sidebar);
        lbl_currentDoctorFormula->setObjectName(QString::fromUtf8("lbl_currentDoctorFormula"));
        lbl_currentDoctorFormula->setGeometry(QRect(0, 140, 250, 17));
        lbl_currentDoctorFormula->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        tabWidget_currentDoctor = new QTabWidget(frame_sidebar);
        tabWidget_currentDoctor->setObjectName(QString::fromUtf8("tabWidget_currentDoctor"));
        tabWidget_currentDoctor->setGeometry(QRect(0, 159, 291, 251));
        tabWidget_currentDoctor->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        lbl_iolLensOne = new QLabel(tab);
        lbl_iolLensOne->setObjectName(QString::fromUtf8("lbl_iolLensOne"));
        lbl_iolLensOne->setGeometry(QRect(1, 4, 185, 17));
        lbl_iolLensOne->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_asrktLensOne = new QLabel(tab);
        lbl_asrktLensOne->setObjectName(QString::fromUtf8("lbl_asrktLensOne"));
        lbl_asrktLensOne->setGeometry(QRect(40, 24, 60, 17));
        lbl_asrktLensOne->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_asrktiiLensOne = new QLabel(tab);
        lbl_asrktiiLensOne->setObjectName(QString::fromUtf8("lbl_asrktiiLensOne"));
        lbl_asrktiiLensOne->setGeometry(QRect(140, 24, 60, 17));
        lbl_asrktiiLensOne->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_acdLensOne = new QLabel(tab);
        lbl_acdLensOne->setObjectName(QString::fromUtf8("lbl_acdLensOne"));
        lbl_acdLensOne->setGeometry(QRect(40, 90, 60, 17));
        lbl_acdLensOne->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_sfLensOne = new QLabel(tab);
        lbl_sfLensOne->setObjectName(QString::fromUtf8("lbl_sfLensOne"));
        lbl_sfLensOne->setGeometry(QRect(140, 90, 60, 17));
        lbl_sfLensOne->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_a0LensOne = new QLabel(tab);
        lbl_a0LensOne->setObjectName(QString::fromUtf8("lbl_a0LensOne"));
        lbl_a0LensOne->setGeometry(QRect(20, 152, 40, 17));
        lbl_a0LensOne->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_a1LensOne = new QLabel(tab);
        lbl_a1LensOne->setObjectName(QString::fromUtf8("lbl_a1LensOne"));
        lbl_a1LensOne->setGeometry(QRect(100, 152, 40, 17));
        lbl_a1LensOne->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_a2LensOne = new QLabel(tab);
        lbl_a2LensOne->setObjectName(QString::fromUtf8("lbl_a2LensOne"));
        lbl_a2LensOne->setGeometry(QRect(180, 152, 40, 17));
        lbl_a2LensOne->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_asrktLensOneValue = new QLineEdit(tab);
        lbl_asrktLensOneValue->setObjectName(QString::fromUtf8("lbl_asrktLensOneValue"));
        lbl_asrktLensOneValue->setGeometry(QRect(40, 46, 70, 40));
        lbl_asrktLensOneValue->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_asrkiiLensOneValue = new QLineEdit(tab);
        lbl_asrkiiLensOneValue->setObjectName(QString::fromUtf8("lbl_asrkiiLensOneValue"));
        lbl_asrkiiLensOneValue->setGeometry(QRect(140, 46, 70, 40));
        lbl_asrkiiLensOneValue->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_acdLensOneValue = new QLineEdit(tab);
        lbl_acdLensOneValue->setObjectName(QString::fromUtf8("lbl_acdLensOneValue"));
        lbl_acdLensOneValue->setGeometry(QRect(40, 110, 70, 40));
        lbl_acdLensOneValue->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_sfLensOneValue = new QLineEdit(tab);
        lbl_sfLensOneValue->setObjectName(QString::fromUtf8("lbl_sfLensOneValue"));
        lbl_sfLensOneValue->setGeometry(QRect(140, 110, 70, 40));
        lbl_sfLensOneValue->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_a0LensOneValue = new QLineEdit(tab);
        lbl_a0LensOneValue->setObjectName(QString::fromUtf8("lbl_a0LensOneValue"));
        lbl_a0LensOneValue->setGeometry(QRect(20, 172, 50, 30));
        lbl_a0LensOneValue->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_a1LensOneValue = new QLineEdit(tab);
        lbl_a1LensOneValue->setObjectName(QString::fromUtf8("lbl_a1LensOneValue"));
        lbl_a1LensOneValue->setGeometry(QRect(100, 172, 50, 30));
        lbl_a1LensOneValue->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_a2LensOneValue = new QLineEdit(tab);
        lbl_a2LensOneValue->setObjectName(QString::fromUtf8("lbl_a2LensOneValue"));
        lbl_a2LensOneValue->setGeometry(QRect(180, 172, 50, 30));
        lbl_a2LensOneValue->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        tabWidget_currentDoctor->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        lbl_sfLensTwo = new QLabel(tab_2);
        lbl_sfLensTwo->setObjectName(QString::fromUtf8("lbl_sfLensTwo"));
        lbl_sfLensTwo->setGeometry(QRect(140, 90, 60, 17));
        lbl_sfLensTwo->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_sfLensTwoValue = new QLineEdit(tab_2);
        lbl_sfLensTwoValue->setObjectName(QString::fromUtf8("lbl_sfLensTwoValue"));
        lbl_sfLensTwoValue->setGeometry(QRect(140, 110, 70, 40));
        lbl_sfLensTwoValue->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_asrktLensTwoValue = new QLineEdit(tab_2);
        lbl_asrktLensTwoValue->setObjectName(QString::fromUtf8("lbl_asrktLensTwoValue"));
        lbl_asrktLensTwoValue->setGeometry(QRect(40, 46, 70, 40));
        lbl_asrktLensTwoValue->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_a2LensTwoValue = new QLineEdit(tab_2);
        lbl_a2LensTwoValue->setObjectName(QString::fromUtf8("lbl_a2LensTwoValue"));
        lbl_a2LensTwoValue->setGeometry(QRect(180, 172, 50, 30));
        lbl_a2LensTwoValue->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_asrkiiLensTwoValue = new QLineEdit(tab_2);
        lbl_asrkiiLensTwoValue->setObjectName(QString::fromUtf8("lbl_asrkiiLensTwoValue"));
        lbl_asrkiiLensTwoValue->setGeometry(QRect(140, 46, 70, 40));
        lbl_asrkiiLensTwoValue->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_acdLensTwo = new QLabel(tab_2);
        lbl_acdLensTwo->setObjectName(QString::fromUtf8("lbl_acdLensTwo"));
        lbl_acdLensTwo->setGeometry(QRect(40, 90, 60, 17));
        lbl_acdLensTwo->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_asrkiiLensTwo = new QLabel(tab_2);
        lbl_asrkiiLensTwo->setObjectName(QString::fromUtf8("lbl_asrkiiLensTwo"));
        lbl_asrkiiLensTwo->setGeometry(QRect(140, 24, 60, 17));
        lbl_asrkiiLensTwo->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_a1LensTwo = new QLabel(tab_2);
        lbl_a1LensTwo->setObjectName(QString::fromUtf8("lbl_a1LensTwo"));
        lbl_a1LensTwo->setGeometry(QRect(100, 152, 40, 17));
        lbl_a1LensTwo->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_a0LensTwoValue = new QLineEdit(tab_2);
        lbl_a0LensTwoValue->setObjectName(QString::fromUtf8("lbl_a0LensTwoValue"));
        lbl_a0LensTwoValue->setGeometry(QRect(20, 172, 50, 30));
        lbl_a0LensTwoValue->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_a2LensTwo = new QLabel(tab_2);
        lbl_a2LensTwo->setObjectName(QString::fromUtf8("lbl_a2LensTwo"));
        lbl_a2LensTwo->setGeometry(QRect(180, 152, 40, 17));
        lbl_a2LensTwo->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_a1LensTwoValue = new QLineEdit(tab_2);
        lbl_a1LensTwoValue->setObjectName(QString::fromUtf8("lbl_a1LensTwoValue"));
        lbl_a1LensTwoValue->setGeometry(QRect(100, 172, 50, 30));
        lbl_a1LensTwoValue->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_iolLensTwo = new QLabel(tab_2);
        lbl_iolLensTwo->setObjectName(QString::fromUtf8("lbl_iolLensTwo"));
        lbl_iolLensTwo->setGeometry(QRect(1, 4, 240, 17));
        lbl_iolLensTwo->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_asrktLensTwo = new QLabel(tab_2);
        lbl_asrktLensTwo->setObjectName(QString::fromUtf8("lbl_asrktLensTwo"));
        lbl_asrktLensTwo->setGeometry(QRect(40, 24, 60, 17));
        lbl_asrktLensTwo->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_acdLensTwoValue = new QLineEdit(tab_2);
        lbl_acdLensTwoValue->setObjectName(QString::fromUtf8("lbl_acdLensTwoValue"));
        lbl_acdLensTwoValue->setGeometry(QRect(40, 110, 70, 40));
        lbl_acdLensTwoValue->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_a0LensTwo = new QLabel(tab_2);
        lbl_a0LensTwo->setObjectName(QString::fromUtf8("lbl_a0LensTwo"));
        lbl_a0LensTwo->setGeometry(QRect(20, 152, 40, 17));
        lbl_a0LensTwo->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        tabWidget_currentDoctor->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        lbl_sfLensThree = new QLabel(tab_3);
        lbl_sfLensThree->setObjectName(QString::fromUtf8("lbl_sfLensThree"));
        lbl_sfLensThree->setGeometry(QRect(160, 90, 60, 17));
        lbl_sfLensThree->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_sfLensThreeValue = new QLineEdit(tab_3);
        lbl_sfLensThreeValue->setObjectName(QString::fromUtf8("lbl_sfLensThreeValue"));
        lbl_sfLensThreeValue->setGeometry(QRect(140, 110, 70, 40));
        lbl_sfLensThreeValue->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_asrktLensThreeValue = new QLineEdit(tab_3);
        lbl_asrktLensThreeValue->setObjectName(QString::fromUtf8("lbl_asrktLensThreeValue"));
        lbl_asrktLensThreeValue->setGeometry(QRect(40, 46, 70, 40));
        lbl_asrktLensThreeValue->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_a2LensThreeValue = new QLineEdit(tab_3);
        lbl_a2LensThreeValue->setObjectName(QString::fromUtf8("lbl_a2LensThreeValue"));
        lbl_a2LensThreeValue->setGeometry(QRect(180, 172, 50, 30));
        lbl_a2LensThreeValue->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_asrkiiLensThreeValue = new QLineEdit(tab_3);
        lbl_asrkiiLensThreeValue->setObjectName(QString::fromUtf8("lbl_asrkiiLensThreeValue"));
        lbl_asrkiiLensThreeValue->setGeometry(QRect(140, 46, 70, 40));
        lbl_asrkiiLensThreeValue->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_acdLensThree = new QLabel(tab_3);
        lbl_acdLensThree->setObjectName(QString::fromUtf8("lbl_acdLensThree"));
        lbl_acdLensThree->setGeometry(QRect(60, 90, 60, 17));
        lbl_acdLensThree->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_asrkiiLensThree = new QLabel(tab_3);
        lbl_asrkiiLensThree->setObjectName(QString::fromUtf8("lbl_asrkiiLensThree"));
        lbl_asrkiiLensThree->setGeometry(QRect(150, 20, 60, 17));
        lbl_asrkiiLensThree->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_a1LensThree = new QLabel(tab_3);
        lbl_a1LensThree->setObjectName(QString::fromUtf8("lbl_a1LensThree"));
        lbl_a1LensThree->setGeometry(QRect(120, 150, 40, 17));
        lbl_a1LensThree->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_a0LensThreeValue = new QLineEdit(tab_3);
        lbl_a0LensThreeValue->setObjectName(QString::fromUtf8("lbl_a0LensThreeValue"));
        lbl_a0LensThreeValue->setGeometry(QRect(20, 172, 50, 30));
        lbl_a0LensThreeValue->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_a2LensThree = new QLabel(tab_3);
        lbl_a2LensThree->setObjectName(QString::fromUtf8("lbl_a2LensThree"));
        lbl_a2LensThree->setGeometry(QRect(200, 150, 40, 17));
        lbl_a2LensThree->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_a1LensThreeValue = new QLineEdit(tab_3);
        lbl_a1LensThreeValue->setObjectName(QString::fromUtf8("lbl_a1LensThreeValue"));
        lbl_a1LensThreeValue->setGeometry(QRect(100, 172, 50, 30));
        lbl_a1LensThreeValue->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_iolLensThree = new QLabel(tab_3);
        lbl_iolLensThree->setObjectName(QString::fromUtf8("lbl_iolLensThree"));
        lbl_iolLensThree->setGeometry(QRect(1, 4, 185, 17));
        lbl_iolLensThree->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_asrktLensThree = new QLabel(tab_3);
        lbl_asrktLensThree->setObjectName(QString::fromUtf8("lbl_asrktLensThree"));
        lbl_asrktLensThree->setGeometry(QRect(50, 20, 60, 17));
        lbl_asrktLensThree->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_acdLensThreeValue = new QLineEdit(tab_3);
        lbl_acdLensThreeValue->setObjectName(QString::fromUtf8("lbl_acdLensThreeValue"));
        lbl_acdLensThreeValue->setGeometry(QRect(40, 110, 70, 40));
        lbl_acdLensThreeValue->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_a0LensThree = new QLabel(tab_3);
        lbl_a0LensThree->setObjectName(QString::fromUtf8("lbl_a0LensThree"));
        lbl_a0LensThree->setGeometry(QRect(40, 150, 40, 17));
        lbl_a0LensThree->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        tabWidget_currentDoctor->addTab(tab_3, QString());
        btn_currentDoctorMore = new QPushButton(frame_sidebar);
        btn_currentDoctorMore->setObjectName(QString::fromUtf8("btn_currentDoctorMore"));
        btn_currentDoctorMore->setGeometry(QRect(309, 25, 35, 35));
        btn_currentDoctorMore->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/icons/ic_more_vert_white_48dp.png);"));
        btn_currentPatientMore = new QPushButton(frame_sidebar);
        btn_currentPatientMore->setObjectName(QString::fromUtf8("btn_currentPatientMore"));
        btn_currentPatientMore->setGeometry(QRect(309, 402, 35, 35));
        btn_currentPatientMore->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/icons/ic_more_vert_white_48dp.png);"));
        lbl_currentPatientName = new QLabel(frame_sidebar);
        lbl_currentPatientName->setObjectName(QString::fromUtf8("lbl_currentPatientName"));
        lbl_currentPatientName->setGeometry(QRect(8, 490, 190, 17));
        lbl_currentPatientName->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_currentPatientLK1Value = new QLineEdit(frame_sidebar);
        lbl_currentPatientLK1Value->setObjectName(QString::fromUtf8("lbl_currentPatientLK1Value"));
        lbl_currentPatientLK1Value->setGeometry(QRect(20, 570, 60, 40));
        QFont font;
        font.setPointSize(10);
        lbl_currentPatientLK1Value->setFont(font);
        lbl_currentPatientLK1Value->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_currentPatientLK1 = new QLabel(frame_sidebar);
        lbl_currentPatientLK1->setObjectName(QString::fromUtf8("lbl_currentPatientLK1"));
        lbl_currentPatientLK1->setGeometry(QRect(30, 540, 40, 17));
        lbl_currentPatientLK1->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_currentPatientLK2 = new QLabel(frame_sidebar);
        lbl_currentPatientLK2->setObjectName(QString::fromUtf8("lbl_currentPatientLK2"));
        lbl_currentPatientLK2->setGeometry(QRect(100, 540, 40, 17));
        lbl_currentPatientLK2->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_currentPatientLK2Value = new QLineEdit(frame_sidebar);
        lbl_currentPatientLK2Value->setObjectName(QString::fromUtf8("lbl_currentPatientLK2Value"));
        lbl_currentPatientLK2Value->setGeometry(QRect(90, 570, 60, 40));
        lbl_currentPatientLK2Value->setFont(font);
        lbl_currentPatientLK2Value->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_currentPatientLK = new QLabel(frame_sidebar);
        lbl_currentPatientLK->setObjectName(QString::fromUtf8("lbl_currentPatientLK"));
        lbl_currentPatientLK->setGeometry(QRect(10, 630, 40, 30));
        lbl_currentPatientLK->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_currentPatientLKValue = new QLineEdit(frame_sidebar);
        lbl_currentPatientLKValue->setObjectName(QString::fromUtf8("lbl_currentPatientLKValue"));
        lbl_currentPatientLKValue->setGeometry(QRect(50, 620, 60, 47));
        lbl_currentPatientLKValue->setFont(font);
        lbl_currentPatientLKValue->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_currentPatientRK2 = new QLabel(frame_sidebar);
        lbl_currentPatientRK2->setObjectName(QString::fromUtf8("lbl_currentPatientRK2"));
        lbl_currentPatientRK2->setGeometry(QRect(240, 540, 40, 17));
        lbl_currentPatientRK2->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_currentPatientRK1 = new QLabel(frame_sidebar);
        lbl_currentPatientRK1->setObjectName(QString::fromUtf8("lbl_currentPatientRK1"));
        lbl_currentPatientRK1->setGeometry(QRect(170, 540, 40, 17));
        lbl_currentPatientRK1->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        lbl_currentPatientRKValue = new QLineEdit(frame_sidebar);
        lbl_currentPatientRKValue->setObjectName(QString::fromUtf8("lbl_currentPatientRKValue"));
        lbl_currentPatientRKValue->setGeometry(QRect(190, 620, 60, 47));
        lbl_currentPatientRKValue->setFont(font);
        lbl_currentPatientRKValue->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_currentPatientRK1Value = new QLineEdit(frame_sidebar);
        lbl_currentPatientRK1Value->setObjectName(QString::fromUtf8("lbl_currentPatientRK1Value"));
        lbl_currentPatientRK1Value->setGeometry(QRect(160, 570, 60, 40));
        lbl_currentPatientRK1Value->setFont(font);
        lbl_currentPatientRK1Value->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_currentPatientRK2Value = new QLineEdit(frame_sidebar);
        lbl_currentPatientRK2Value->setObjectName(QString::fromUtf8("lbl_currentPatientRK2Value"));
        lbl_currentPatientRK2Value->setGeometry(QRect(230, 570, 60, 40));
        lbl_currentPatientRK2Value->setFont(font);
        lbl_currentPatientRK2Value->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_currentPatientRK = new QLabel(frame_sidebar);
        lbl_currentPatientRK->setObjectName(QString::fromUtf8("lbl_currentPatientRK"));
        lbl_currentPatientRK->setGeometry(QRect(140, 630, 40, 30));
        lbl_currentPatientRK->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        btn_currentPatientChooser = new QPushButton(frame_sidebar);
        btn_currentPatientChooser->setObjectName(QString::fromUtf8("btn_currentPatientChooser"));
        btn_currentPatientChooser->setGeometry(QRect(60, 450, 241, 41));
        btn_currentPatientChooser->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/card.png);"));
        btn_currentDoctorChooser = new QPushButton(frame_sidebar);
        btn_currentDoctorChooser->setObjectName(QString::fromUtf8("btn_currentDoctorChooser"));
        btn_currentDoctorChooser->setGeometry(QRect(60, 70, 241, 41));
        btn_currentDoctorChooser->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/card.png);"));
        btn_currentDocAdd = new QPushButton(frame_sidebar);
        btn_currentDocAdd->setObjectName(QString::fromUtf8("btn_currentDocAdd"));
        btn_currentDocAdd->setGeometry(QRect(300, 65, 50, 50));
        btn_currentDocAdd->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/add-icon.png);"));
        btn_currentDocEdit = new QPushButton(frame_sidebar);
        btn_currentDocEdit->setObjectName(QString::fromUtf8("btn_currentDocEdit"));
        btn_currentDocEdit->setGeometry(QRect(300, 125, 50, 50));
        btn_currentDocEdit->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/edit-icon.png);"));
        btn_currentDocView = new QPushButton(frame_sidebar);
        btn_currentDocView->setObjectName(QString::fromUtf8("btn_currentDocView"));
        btn_currentDocView->setGeometry(QRect(300, 185, 50, 50));
        btn_currentDocView->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/view-icon.png);"));
        btn_currentPatientAdd = new QPushButton(frame_sidebar);
        btn_currentPatientAdd->setObjectName(QString::fromUtf8("btn_currentPatientAdd"));
        btn_currentPatientAdd->setGeometry(QRect(300, 440, 50, 50));
        btn_currentPatientAdd->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/add-icon.png);"));
        btn_currentPatientEdit = new QPushButton(frame_sidebar);
        btn_currentPatientEdit->setObjectName(QString::fromUtf8("btn_currentPatientEdit"));
        btn_currentPatientEdit->setGeometry(QRect(300, 500, 50, 50));
        btn_currentPatientEdit->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/edit-icon.png);"));
        btn_currentPatientView = new QPushButton(frame_sidebar);
        btn_currentPatientView->setObjectName(QString::fromUtf8("btn_currentPatientView"));
        btn_currentPatientView->setGeometry(QRect(300, 560, 50, 50));
        btn_currentPatientView->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/view-icon.png);"));
        lbl_currentPatientRK->raise();
        btn_currentDoctorLogo->raise();
        btn_currentPatientLogo->raise();
        lbl_currentDoctor->raise();
        lbl_currentPatient->raise();
        lbl_currentDoctorName->raise();
        lbl_currentDoctorFormula->raise();
        tabWidget_currentDoctor->raise();
        btn_currentDoctorMore->raise();
        btn_currentPatientMore->raise();
        lbl_currentPatientName->raise();
        lbl_currentPatientLK1Value->raise();
        lbl_currentPatientLK1->raise();
        lbl_currentPatientLK2->raise();
        lbl_currentPatientLK2Value->raise();
        lbl_currentPatientLK->raise();
        lbl_currentPatientLKValue->raise();
        lbl_currentPatientRK2->raise();
        lbl_currentPatientRK1->raise();
        lbl_currentPatientRKValue->raise();
        lbl_currentPatientRK1Value->raise();
        lbl_currentPatientRK2Value->raise();
        btn_currentPatientChooser->raise();
        btn_currentDoctorChooser->raise();
        btn_currentDocEdit->raise();
        btn_currentDocView->raise();
        btn_currentDocAdd->raise();
        btn_currentPatientAdd->raise();
        btn_currentPatientEdit->raise();
        btn_currentPatientView->raise();
        snackbar = new QLabel(HomeScreenDialog);
        snackbar->setObjectName(QString::fromUtf8("snackbar"));
        snackbar->setGeometry(QRect(-1, 680, 1281, 40));
        snackbar->setStyleSheet(QString::fromUtf8("border-image: url(:/images/alert-red.png);\n"
"background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        snackbar->setIndent(5);
        stackedWidget = new QStackedWidget(HomeScreenDialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(350, 30, 811, 621));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);border-image:url(:/images/empty.png);"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        btn_calculator = new QPushButton(page);
        btn_calculator->setObjectName(QString::fromUtf8("btn_calculator"));
        btn_calculator->setGeometry(QRect(305, 40, 100, 110));
        btn_calculator->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/calculator-icon.png);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 5px solid #00BCD4;\n"
"}"));
        lbl_calculator = new QLabel(page);
        lbl_calculator->setObjectName(QString::fromUtf8("lbl_calculator"));
        lbl_calculator->setGeometry(QRect(305, 150, 90, 17));
        lbl_calculator->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_calculator->setAlignment(Qt::AlignCenter);
        btn_measure = new QPushButton(page);
        btn_measure->setObjectName(QString::fromUtf8("btn_measure"));
        btn_measure->setGeometry(QRect(520, 40, 101, 101));
        btn_measure->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/graph-icon.png);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 5px solid #00BCD4;\n"
"}"));
        lbl_measure = new QLabel(page);
        lbl_measure->setObjectName(QString::fromUtf8("lbl_measure"));
        lbl_measure->setGeometry(QRect(530, 150, 90, 20));
        lbl_measure->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_measure->setAlignment(Qt::AlignCenter);
        btn_print = new QPushButton(page);
        btn_print->setObjectName(QString::fromUtf8("btn_print"));
        btn_print->setGeometry(QRect(305, 400, 100, 110));
        btn_print->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/print-icon.png);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 5px solid #00BCD4;\n"
"}"));
        lbl_print = new QLabel(page);
        lbl_print->setObjectName(QString::fromUtf8("lbl_print"));
        lbl_print->setGeometry(QRect(305, 510, 90, 17));
        lbl_print->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_print->setAlignment(Qt::AlignCenter);
        btn_doctors = new QPushButton(page);
        btn_doctors->setObjectName(QString::fromUtf8("btn_doctors"));
        btn_doctors->setGeometry(QRect(80, 240, 90, 100));
        btn_doctors->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/surgeon-icon.png);\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"    border: 5px solid #00BCD4;\n"
"}"));
        lbl_doctors = new QLabel(page);
        lbl_doctors->setObjectName(QString::fromUtf8("lbl_doctors"));
        lbl_doctors->setGeometry(QRect(80, 350, 90, 17));
        lbl_doctors->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_doctors->setAlignment(Qt::AlignCenter);
        btn_patients = new QPushButton(page);
        btn_patients->setObjectName(QString::fromUtf8("btn_patients"));
        btn_patients->setGeometry(QRect(305, 240, 100, 110));
        btn_patients->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"\n"
"background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/patient-icon.png);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 5px solid #00BCD4;\n"
"}"));
        lbl_patients = new QLabel(page);
        lbl_patients->setObjectName(QString::fromUtf8("lbl_patients"));
        lbl_patients->setGeometry(QRect(305, 350, 90, 17));
        lbl_patients->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_patients->setAlignment(Qt::AlignCenter);
        btn_lenses = new QPushButton(page);
        btn_lenses->setObjectName(QString::fromUtf8("btn_lenses"));
        btn_lenses->setGeometry(QRect(530, 240, 100, 110));
        btn_lenses->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/iol-icon.png);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 5px solid #00BCD4;\n"
"}"));
        lbl_lenses = new QLabel(page);
        lbl_lenses->setObjectName(QString::fromUtf8("lbl_lenses"));
        lbl_lenses->setGeometry(QRect(530, 350, 90, 17));
        lbl_lenses->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_lenses->setAlignment(Qt::AlignCenter);
        btn_settings = new QPushButton(page);
        btn_settings->setObjectName(QString::fromUtf8("btn_settings"));
        btn_settings->setGeometry(QRect(80, 400, 100, 110));
        btn_settings->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"\n"
"background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/settings-icon.png);\n"
"\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 5px solid #00BCD4;\n"
"}"));
        lbl_settings = new QLabel(page);
        lbl_settings->setObjectName(QString::fromUtf8("lbl_settings"));
        lbl_settings->setGeometry(QRect(80, 510, 90, 17));
        lbl_settings->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_settings->setAlignment(Qt::AlignCenter);
        btn_calibrate = new QPushButton(page);
        btn_calibrate->setObjectName(QString::fromUtf8("btn_calibrate"));
        btn_calibrate->setGeometry(QRect(80, 40, 100, 110));
        btn_calibrate->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/calibrate-icon.png);\n"
"}\n"
"QPushButton:pressed {\n"
"    border: 5px solid #00BCD4;\n"
"}"));
        lbl_calibrate = new QLabel(page);
        lbl_calibrate->setObjectName(QString::fromUtf8("lbl_calibrate"));
        lbl_calibrate->setGeometry(QRect(80, 150, 90, 17));
        lbl_calibrate->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_calibrate->setAlignment(Qt::AlignCenter);
        btn_back = new QPushButton(page);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(530, 410, 100, 100));
        btn_back->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"\n"
"background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/backbutton.png);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 5px solid #00BCD4;\n"
"}"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        lbl_currentPatient_2 = new QLabel(page_2);
        lbl_currentPatient_2->setObjectName(QString::fromUtf8("lbl_currentPatient_2"));
        lbl_currentPatient_2->setGeometry(QRect(390, 10, 120, 17));
        lbl_currentPatient_2->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(33,33,33);"));
        table_patients = new QTableWidget(page_2);
        if (table_patients->columnCount() < 2)
            table_patients->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_patients->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_patients->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        table_patients->setObjectName(QString::fromUtf8("table_patients"));
        table_patients->setGeometry(QRect(22, 50, 781, 491));
        table_patients->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        table_patients->horizontalHeader()->setDefaultSectionSize(240);
        btn_currentPatientLoad = new QPushButton(page_2);
        btn_currentPatientLoad->setObjectName(QString::fromUtf8("btn_currentPatientLoad"));
        btn_currentPatientLoad->setGeometry(QRect(560, 560, 111, 51));
        btn_currentPatientLoad->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/purple-btn.png);color:rgb(255,255,255)"));
        btn_currentPatientChooserExit = new QPushButton(page_2);
        btn_currentPatientChooserExit->setObjectName(QString::fromUtf8("btn_currentPatientChooserExit"));
        btn_currentPatientChooserExit->setGeometry(QRect(690, 560, 111, 51));
        btn_currentPatientChooserExit->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/btn-mid.png);\n"
"color:rgb(33,33,33);"));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        table_doctors = new QTableWidget(page_3);
        if (table_doctors->columnCount() < 2)
            table_doctors->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_doctors->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_doctors->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        table_doctors->setObjectName(QString::fromUtf8("table_doctors"));
        table_doctors->setGeometry(QRect(22, 50, 781, 481));
        table_doctors->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        table_doctors->horizontalHeader()->setDefaultSectionSize(240);
        lbl_currentPatient_3 = new QLabel(page_3);
        lbl_currentPatient_3->setObjectName(QString::fromUtf8("lbl_currentPatient_3"));
        lbl_currentPatient_3->setGeometry(QRect(330, 10, 120, 17));
        lbl_currentPatient_3->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(33,33,33);"));
        btn_currentDoctorLoad = new QPushButton(page_3);
        btn_currentDoctorLoad->setObjectName(QString::fromUtf8("btn_currentDoctorLoad"));
        btn_currentDoctorLoad->setGeometry(QRect(540, 550, 121, 51));
        btn_currentDoctorLoad->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/purple-btn.png);color:rgb(255,255,255)"));
        btn_currentDoctorChooserExit = new QPushButton(page_3);
        btn_currentDoctorChooserExit->setObjectName(QString::fromUtf8("btn_currentDoctorChooserExit"));
        btn_currentDoctorChooserExit->setGeometry(QRect(680, 550, 121, 51));
        btn_currentDoctorChooserExit->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/btn-mid.png);\n"
"color:rgb(33,33,33);"));
        stackedWidget->addWidget(page_3);
        lbl_time = new QLabel(HomeScreenDialog);
        lbl_time->setObjectName(QString::fromUtf8("lbl_time"));
        lbl_time->setGeometry(QRect(1139, 10, 121, 41));
        QFont font1;
        font1.setPointSize(9);
        lbl_time->setFont(font1);
        lbl_time->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        lbl_time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lbl_lenses_2 = new QLabel(HomeScreenDialog);
        lbl_lenses_2->setObjectName(QString::fromUtf8("lbl_lenses_2"));
        lbl_lenses_2->setGeometry(QRect(1080, 640, 90, 17));
        lbl_lenses_2->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_lenses_2->setAlignment(Qt::AlignCenter);
        label = new QLabel(HomeScreenDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(610, 640, 290, 30));
        QFont font2;
        font2.setPointSize(14);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        frame_sidebar->raise();
        stackedWidget->raise();
        snackbar->raise();
        lbl_time->raise();
        lbl_lenses_2->raise();
        label->raise();

        retranslateUi(HomeScreenDialog);

        tabWidget_currentDoctor->setCurrentIndex(2);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(HomeScreenDialog);
    } // setupUi

    void retranslateUi(QDialog *HomeScreenDialog)
    {
        HomeScreenDialog->setWindowTitle(QCoreApplication::translate("HomeScreenDialog", "Dialog", nullptr));
        btn_currentDoctorLogo->setText(QString());
        btn_currentPatientLogo->setText(QString());
        lbl_currentDoctor->setText(QCoreApplication::translate("HomeScreenDialog", "Current Doctor", nullptr));
        lbl_currentPatient->setText(QCoreApplication::translate("HomeScreenDialog", "Current Patient", nullptr));
        lbl_currentDoctorName->setText(QCoreApplication::translate("HomeScreenDialog", "Name:", nullptr));
        lbl_currentDoctorFormula->setText(QCoreApplication::translate("HomeScreenDialog", "Formula:", nullptr));
        lbl_iolLensOne->setText(QCoreApplication::translate("HomeScreenDialog", "IOL", nullptr));
        lbl_asrktLensOne->setText(QCoreApplication::translate("HomeScreenDialog", "ASRKT", nullptr));
        lbl_asrktiiLensOne->setText(QCoreApplication::translate("HomeScreenDialog", "ASRKII", nullptr));
        lbl_acdLensOne->setText(QCoreApplication::translate("HomeScreenDialog", "ACD", nullptr));
        lbl_sfLensOne->setText(QCoreApplication::translate("HomeScreenDialog", "SF", nullptr));
        lbl_a0LensOne->setText(QCoreApplication::translate("HomeScreenDialog", "a0", nullptr));
        lbl_a1LensOne->setText(QCoreApplication::translate("HomeScreenDialog", "a1", nullptr));
        lbl_a2LensOne->setText(QCoreApplication::translate("HomeScreenDialog", "a2", nullptr));
        tabWidget_currentDoctor->setTabText(tabWidget_currentDoctor->indexOf(tab), QCoreApplication::translate("HomeScreenDialog", "Lens1", nullptr));
        lbl_sfLensTwo->setText(QCoreApplication::translate("HomeScreenDialog", "SF", nullptr));
        lbl_acdLensTwo->setText(QCoreApplication::translate("HomeScreenDialog", "ACD", nullptr));
        lbl_asrkiiLensTwo->setText(QCoreApplication::translate("HomeScreenDialog", "ASRKII", nullptr));
        lbl_a1LensTwo->setText(QCoreApplication::translate("HomeScreenDialog", "a1", nullptr));
        lbl_a2LensTwo->setText(QCoreApplication::translate("HomeScreenDialog", "a2", nullptr));
        lbl_iolLensTwo->setText(QCoreApplication::translate("HomeScreenDialog", "IOL", nullptr));
        lbl_asrktLensTwo->setText(QCoreApplication::translate("HomeScreenDialog", "ASRKT", nullptr));
        lbl_a0LensTwo->setText(QCoreApplication::translate("HomeScreenDialog", "a0", nullptr));
        tabWidget_currentDoctor->setTabText(tabWidget_currentDoctor->indexOf(tab_2), QCoreApplication::translate("HomeScreenDialog", "Lens2", nullptr));
        lbl_sfLensThree->setText(QCoreApplication::translate("HomeScreenDialog", "SF", nullptr));
        lbl_acdLensThree->setText(QCoreApplication::translate("HomeScreenDialog", "ACD", nullptr));
        lbl_asrkiiLensThree->setText(QCoreApplication::translate("HomeScreenDialog", "ASRKII", nullptr));
        lbl_a1LensThree->setText(QCoreApplication::translate("HomeScreenDialog", "a1", nullptr));
        lbl_a2LensThree->setText(QCoreApplication::translate("HomeScreenDialog", "a2", nullptr));
        lbl_iolLensThree->setText(QCoreApplication::translate("HomeScreenDialog", "IOL", nullptr));
        lbl_asrktLensThree->setText(QCoreApplication::translate("HomeScreenDialog", "ASRKT", nullptr));
        lbl_a0LensThree->setText(QCoreApplication::translate("HomeScreenDialog", "a0", nullptr));
        tabWidget_currentDoctor->setTabText(tabWidget_currentDoctor->indexOf(tab_3), QCoreApplication::translate("HomeScreenDialog", "Lens3", nullptr));
        btn_currentDoctorMore->setText(QString());
        btn_currentPatientMore->setText(QString());
        lbl_currentPatientName->setText(QCoreApplication::translate("HomeScreenDialog", "Name:", nullptr));
        lbl_currentPatientLK1->setText(QCoreApplication::translate("HomeScreenDialog", "LK1", nullptr));
        lbl_currentPatientLK2->setText(QCoreApplication::translate("HomeScreenDialog", "LK2", nullptr));
        lbl_currentPatientLK2Value->setText(QString());
        lbl_currentPatientLK->setText(QCoreApplication::translate("HomeScreenDialog", "LK", nullptr));
        lbl_currentPatientLKValue->setText(QString());
        lbl_currentPatientRK2->setText(QCoreApplication::translate("HomeScreenDialog", "RK2", nullptr));
        lbl_currentPatientRK1->setText(QCoreApplication::translate("HomeScreenDialog", "RK1", nullptr));
        lbl_currentPatientRKValue->setText(QString());
        lbl_currentPatientRK2Value->setText(QString());
        lbl_currentPatientRK->setText(QCoreApplication::translate("HomeScreenDialog", "RK", nullptr));
        btn_currentPatientChooser->setText(QString());
        btn_currentDoctorChooser->setText(QString());
        btn_currentDocAdd->setText(QString());
        btn_currentDocEdit->setText(QString());
        btn_currentDocView->setText(QString());
        btn_currentPatientAdd->setText(QString());
        btn_currentPatientEdit->setText(QString());
        btn_currentPatientView->setText(QString());
        snackbar->setText(QString());
        btn_calculator->setText(QString());
        lbl_calculator->setText(QCoreApplication::translate("HomeScreenDialog", "Calculator", nullptr));
        btn_measure->setText(QString());
        lbl_measure->setText(QCoreApplication::translate("HomeScreenDialog", "Measure", nullptr));
        btn_print->setText(QString());
        lbl_print->setText(QCoreApplication::translate("HomeScreenDialog", "Print", nullptr));
        btn_doctors->setText(QString());
        lbl_doctors->setText(QCoreApplication::translate("HomeScreenDialog", "Doctors", nullptr));
        btn_patients->setText(QString());
        lbl_patients->setText(QCoreApplication::translate("HomeScreenDialog", "Patients", nullptr));
        btn_lenses->setText(QString());
        lbl_lenses->setText(QCoreApplication::translate("HomeScreenDialog", "Lenses", nullptr));
        btn_settings->setText(QString());
        lbl_settings->setText(QCoreApplication::translate("HomeScreenDialog", "Settings", nullptr));
        btn_calibrate->setText(QString());
        lbl_calibrate->setText(QCoreApplication::translate("HomeScreenDialog", "Calibration", nullptr));
        btn_back->setText(QString());
        lbl_currentPatient_2->setText(QCoreApplication::translate("HomeScreenDialog", "Select Patient", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table_patients->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("HomeScreenDialog", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table_patients->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("HomeScreenDialog", "Name", nullptr));
        btn_currentPatientLoad->setText(QCoreApplication::translate("HomeScreenDialog", "Load", nullptr));
        btn_currentPatientChooserExit->setText(QCoreApplication::translate("HomeScreenDialog", "Exit", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table_doctors->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("HomeScreenDialog", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table_doctors->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("HomeScreenDialog", "Name", nullptr));
        lbl_currentPatient_3->setText(QCoreApplication::translate("HomeScreenDialog", "Select Doctor", nullptr));
        btn_currentDoctorLoad->setText(QCoreApplication::translate("HomeScreenDialog", "Load", nullptr));
        btn_currentDoctorChooserExit->setText(QCoreApplication::translate("HomeScreenDialog", "Exit", nullptr));
        lbl_time->setText(QCoreApplication::translate("HomeScreenDialog", "10:09", nullptr));
        lbl_lenses_2->setText(QString());
        label->setText(QCoreApplication::translate("HomeScreenDialog", "Adithya Meditech", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomeScreenDialog: public Ui_HomeScreenDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMESCREENDIALOG_H
