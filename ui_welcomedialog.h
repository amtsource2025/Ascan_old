/********************************************************************************
** Form generated from reading UI file 'welcomedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEDIALOG_H
#define UI_WELCOMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "fixedcombobox.h"

QT_BEGIN_NAMESPACE

class Ui_WelcomeDialog
{
public:
    QWidget *centralWidget;
<<<<<<< HEAD
    QFrame *headerBar;
=======
>>>>>>> c45e4e3d7db5a6fc95b663ed077b6e12fe2a2556
    QPushButton *btn_ascan;
    QFrame *frame;
    QPushButton *btn_surgeon;
    QPushButton *btn_enter;
    QPushButton *btn_newDoctor_2;
    FixedComboBox *comboBox_patientSelect;
    QLabel *label;
    QLabel *lbl_time;
    QLabel *lbl_docName;
    QLabel *lbl_softwareVersion;
    QLabel *lbl_serialNumber;
<<<<<<< HEAD
    QPushButton *btn_calibrate;
    QPushButton *btn_calculator;
    QPushButton *btn_doctors;
    QPushButton *btn_patients;
    QPushButton *btn_lenses;
    QPushButton *btn_settings;
    QPushButton *btn_print;
    QLabel *lbl_calibrate;
    QLabel *lbl_calculator;
    QLabel *lbl_doctors;
    QLabel *lbl_patients;
    QLabel *lbl_lenses;
    QLabel *lbl_settings;
    QLabel *lbl_patients_2;
=======
>>>>>>> c45e4e3d7db5a6fc95b663ed077b6e12fe2a2556

    void setupUi(QMainWindow *WelcomeDialog)
    {
        if (WelcomeDialog->objectName().isEmpty())
            WelcomeDialog->setObjectName(QString::fromUtf8("WelcomeDialog"));
        WelcomeDialog->resize(1280, 720);
        QFont font;
        font.setPointSize(15);
        WelcomeDialog->setFont(font);
<<<<<<< HEAD
        WelcomeDialog->setStyleSheet(QString::fromUtf8("background-image: url(:/images/7.png);"));
        centralWidget = new QWidget(WelcomeDialog);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        headerBar = new QFrame(centralWidget);
        headerBar->setObjectName(QString::fromUtf8("headerBar"));
        headerBar->setGeometry(QRect(0, 0, 1280, 75));
        headerBar->setStyleSheet(QString::fromUtf8("QFrame#headerBar {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #1976D2, stop:1 #2E9BDA);\n"
"    border: none;\n"
"}"));
        headerBar->setFrameShape(QFrame::StyledPanel);
        headerBar->setFrameShadow(QFrame::Raised);
        btn_ascan = new QPushButton(centralWidget);
        btn_ascan->setObjectName(QString::fromUtf8("btn_ascan"));
        btn_ascan->setGeometry(QRect(530, 15, 221, 171));
        btn_ascan->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color: rgb(255,255,255);\n"
"	border: 3px solid #FFFFFF;\n"
"	border-radius: 20px;\n"
"	border-image: url(:/images/ascan-select.png);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 3px solid #00BCD4;\n"
"}\n"
=======
        WelcomeDialog->setStyleSheet(QString::fromUtf8("background-image: url(:/images/5.png);"));
        centralWidget = new QWidget(WelcomeDialog);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        btn_ascan = new QPushButton(centralWidget);
        btn_ascan->setObjectName(QString::fromUtf8("btn_ascan"));
        btn_ascan->setGeometry(QRect(530, 0, 231, 191));
        btn_ascan->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/ascan-select.png);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 5px solid #00BCD4;\n"
"}\n"
"\n"
>>>>>>> c45e4e3d7db5a6fc95b663ed077b6e12fe2a2556
""));
        btn_ascan->setFlat(true);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
<<<<<<< HEAD
        frame->setGeometry(QRect(120, 230, 1011, 291));
        frame->setStyleSheet(QString::fromUtf8("QFrame#frame {\n"
"    background-color: qlineargradient(\n"
"        spread:pad,\n"
"        x1:0, y1:0,\n"
"        x2:1, y2:1,\n"
"        stop:0   rgba(168, 211, 242, 235),\n"
"        stop:0.35 rgba(191, 223, 246, 225),\n"
"        stop:0.70 rgba(201, 230, 248, 225),\n"
"        stop:1   rgba(176, 217, 244, 235)\n"
"    );\n"
"    border: 2px solid #7fb3d9;\n"
"    border-radius: 30px;\n"
=======
        frame->setGeometry(QRect(140, 230, 1011, 431));
        frame->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"\n"
"	border-image: url(:/images/card-big.png); \n"
"	background-image:url(:/images/empty.png);\n"
"    background-color: rgb(255,255,255);\n"
"    border: 1px solid rgb(220,225,235);\n"
"    border-radius: 22px;\n"
"\n"
>>>>>>> c45e4e3d7db5a6fc95b663ed077b6e12fe2a2556
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        btn_surgeon = new QPushButton(frame);
        btn_surgeon->setObjectName(QString::fromUtf8("btn_surgeon"));
<<<<<<< HEAD
        btn_surgeon->setGeometry(QRect(150, 50, 141, 141));
=======
        btn_surgeon->setGeometry(QRect(170, 150, 141, 141));
>>>>>>> c45e4e3d7db5a6fc95b663ed077b6e12fe2a2556
        QFont font1;
        font1.setPointSize(13);
        btn_surgeon->setFont(font1);
        btn_surgeon->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/patient-icon.png);"));
        btn_surgeon->setFlat(true);
        btn_enter = new QPushButton(frame);
        btn_enter->setObjectName(QString::fromUtf8("btn_enter"));
<<<<<<< HEAD
        btn_enter->setGeometry(QRect(820, 210, 120, 40));
=======
        btn_enter->setGeometry(QRect(850, 370, 120, 40));
>>>>>>> c45e4e3d7db5a6fc95b663ed077b6e12fe2a2556
        QFont font2;
        font2.setFamily(QString::fromUtf8("Umpush"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setItalic(false);
        btn_enter->setFont(font2);
        btn_enter->setStyleSheet(QString::fromUtf8("\n"
"/*QPushButton {\n"
"    border-image: url(:/images/empty.png);\n"
"    color: rgb(85, 87, 83);\n"
"    border: 2px solid transparent;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #80d4ff;\n"
"    border: 2px solid #006699;\n"
"    border-radius: 10px;\n"
"	color:#00334d\n"
"}*/\n"
"\n"
"QPushButton\n"
"{\n"
"    background-color: #2F6BFF;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"font: 700 14pt \"Umpush\";\n"
"    padding: 8px 20px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #1E56E6;\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"    background-color: #C8D6F5;\n"
"    color: #FFFFFF;\n"
"}\n"
"\n"
<<<<<<< HEAD
"\n"
"QPushButton\n"
"{\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0,\n"
"		stop:0 #1976D2, stop:1 #2E9BDA);\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    font: 700 14pt \"Umpush\";\n"
"    padding: 8px 20px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"    background: qlineargra"
                        "dient(spread:pad, x1:0, y1:0, x2:1, y2:0,\n"
"		stop:0 #1668BC, stop:1 #2789C4);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #14589F;\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"    background-color: #C8D6F5;\n"
"    color: #FFFFFF;\n"
"}\n"
"\n"
"\n"
=======
>>>>>>> c45e4e3d7db5a6fc95b663ed077b6e12fe2a2556
""));
        btn_enter->setFlat(true);
        btn_newDoctor_2 = new QPushButton(frame);
        btn_newDoctor_2->setObjectName(QString::fromUtf8("btn_newDoctor_2"));
<<<<<<< HEAD
        btn_newDoctor_2->setGeometry(QRect(590, 210, 181, 40));
=======
        btn_newDoctor_2->setGeometry(QRect(630, 370, 181, 40));
>>>>>>> c45e4e3d7db5a6fc95b663ed077b6e12fe2a2556
        btn_newDoctor_2->setFont(font2);
        btn_newDoctor_2->setStyleSheet(QString::fromUtf8("\n"
"/*QPushButton {\n"
"    border-image: url(:/images/empty.png);\n"
"    color: rgb(85, 87, 83);\n"
"    border: 2px solid transparent;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #80d4ff;\n"
"    border: 2px solid #006699;\n"
"    border-radius: 10px;\n"
"	color:#00334d\n"
"}*/\n"
"\n"
"QPushButton\n"
"{\n"
"    background-color: #00B4D8;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    font: 700 14pt \"Umpush\";\n"
"    padding: 8px 20px;\n"
"}\n"
"\n"
"\n"
<<<<<<< HEAD
"QPushButton\n"
"{\n"
"    background-color: #FFFFFF;\n"
"    color: #00B4D8;\n"
"    border: 1.5px solid #00B4D8;\n"
"    border-radius: 12px;\n"
"    font: 700 14pt \"Umpush\";\n"
"    padding: 8px 20px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"    background-color: #E6FAFE;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: #CDF3FB;\n"
"}\n"
"\n"
"\n"
"\n"
=======
>>>>>>> c45e4e3d7db5a6fc95b663ed077b6e12fe2a2556
"\n"
""));
        btn_newDoctor_2->setFlat(true);
        comboBox_patientSelect = new FixedComboBox(frame);
        comboBox_patientSelect->setObjectName(QString::fromUtf8("comboBox_patientSelect"));
<<<<<<< HEAD
        comboBox_patientSelect->setGeometry(QRect(330, 90, 541, 61));
        comboBox_patientSelect->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QComboBox\n"
"{\n"
"    background-color: #FBFCFE;\n"
"    border: 1.5px solid #DCE3EA;\n"
"    border: 2px solid #7fb3d9;\n"
"    border-radius: 12px;\n"
"    padding: 8px 18px;\n"
=======
        comboBox_patientSelect->setGeometry(QRect(330, 190, 541, 61));
        comboBox_patientSelect->setStyleSheet(QString::fromUtf8("/*QComboBox\n"
"{\n"
"    background-color: white;\n"
"    border: 1px solid #E2E8F0;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
>>>>>>> c45e4e3d7db5a6fc95b663ed077b6e12fe2a2556
"    color: #334155;\n"
"    outline: none;\n"
"}\n"
"\n"
<<<<<<< HEAD
"QComboBox:hover\n"
"{\n"
"    border: 1.5px solid #A9C4E8;\n"
"}\n"
"\n"
"QComboBox:focus, QComboBox:on\n"
"{\n"
"    border: 1.5px solid #1976D2;\n"
"    background: #FFFFFF;\n"
"}\n"
"\n"
"QComboBox::drop-down\n"
"{\n"
"    border: none;\n"
"    width: 34px;\n"
=======
"QComboBox:focus\n"
"{\n"
"    border: 1px solid #3B82F6;\n"
"    outline: none;\n"
"}\n"
"\n"
"QComboBox:on\n"
"{\n"
"    border: 1px solid #3B82F6;\n"
>>>>>>> c45e4e3d7db5a6fc95b663ed077b6e12fe2a2556
"}\n"
"\n"
"QComboBox QAbstractItemView\n"
"{\n"
"    background: white;\n"
<<<<<<< HEAD
"    border: 1px solid #DCE3EA;\n"
"    selection-background-color: #E3F0FD;\n"
"    selection-color: #1976D2;\n"
"    outline: 0;\n"
"    padding: 4px;\n"
"}"));
=======
"    border: 1px solid #80c0e4;\n"
"    selection-background-color: #DCEEFF;\n"
"    selection-color: #1E40AF;\n"
"    outline: 0;\n"
"}*/"));
>>>>>>> c45e4e3d7db5a6fc95b663ed077b6e12fe2a2556
        comboBox_patientSelect->setFrame(true);
        btn_newDoctor_2->raise();
        btn_surgeon->raise();
        btn_enter->raise();
        comboBox_patientSelect->raise();
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(550, 200, 192, 17));
<<<<<<< HEAD
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(true);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: #1A2B3C;\n"
"font-weight: 700;\n"
"letter-spacing: 1px;"));
=======
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
>>>>>>> c45e4e3d7db5a6fc95b663ed077b6e12fe2a2556
        label->setAlignment(Qt::AlignCenter);
        lbl_time = new QLabel(centralWidget);
        lbl_time->setObjectName(QString::fromUtf8("lbl_time"));
        lbl_time->setGeometry(QRect(1129, 10, 131, 41));
<<<<<<< HEAD
        QFont font4;
        font4.setPointSize(13);
        font4.setBold(true);
        lbl_time->setFont(font4);
        lbl_time->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: #FFFFFF;\n"
"font-weight: 600;"));
=======
        lbl_time->setFont(font1);
        lbl_time->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
>>>>>>> c45e4e3d7db5a6fc95b663ed077b6e12fe2a2556
        lbl_time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lbl_docName = new QLabel(centralWidget);
        lbl_docName->setObjectName(QString::fromUtf8("lbl_docName"));
        lbl_docName->setGeometry(QRect(20, 0, 261, 61));
<<<<<<< HEAD
        lbl_docName->setFont(font3);
        lbl_docName->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: #FFFFFF;\n"
"font-weight: 600;"));
        lbl_softwareVersion = new QLabel(centralWidget);
        lbl_softwareVersion->setObjectName(QString::fromUtf8("lbl_softwareVersion"));
        lbl_softwareVersion->setGeometry(QRect(1110, 680, 151, 41));
=======
        lbl_docName->setFont(font);
        lbl_docName->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color:rgb(21,21,21);\n"
"border-image:url(:/images/empty.png);"));
        lbl_softwareVersion = new QLabel(centralWidget);
        lbl_softwareVersion->setObjectName(QString::fromUtf8("lbl_softwareVersion"));
        lbl_softwareVersion->setGeometry(QRect(10, 670, 151, 41));
>>>>>>> c45e4e3d7db5a6fc95b663ed077b6e12fe2a2556
        lbl_softwareVersion->setStyleSheet(QString::fromUtf8("color:rgb(21,21,21);\n"
"background-image:url(:/images/empty.png);"));
        lbl_serialNumber = new QLabel(centralWidget);
        lbl_serialNumber->setObjectName(QString::fromUtf8("lbl_serialNumber"));
        lbl_serialNumber->setGeometry(QRect(660, 570, 140, 28));
        lbl_serialNumber->setStyleSheet(QString::fromUtf8("color:rgb(21,21,21);\n"
"background-image:url(:/images/empty.png);"));
        lbl_serialNumber->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
<<<<<<< HEAD
        btn_calibrate = new QPushButton(centralWidget);
        btn_calibrate->setObjectName(QString::fromUtf8("btn_calibrate"));
        btn_calibrate->setGeometry(QRect(70, 570, 91, 91));
        btn_calibrate->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/calibrate-icon.png);\n"
"}\n"
"QPushButton:pressed {\n"
"    border: 5px solid #00BCD4;\n"
"}"));
        btn_calculator = new QPushButton(centralWidget);
        btn_calculator->setObjectName(QString::fromUtf8("btn_calculator"));
        btn_calculator->setGeometry(QRect(210, 550, 111, 121));
        btn_calculator->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/calculator-icon.png);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 5px solid #00BCD4;\n"
"}"));
        btn_doctors = new QPushButton(centralWidget);
        btn_doctors->setObjectName(QString::fromUtf8("btn_doctors"));
        btn_doctors->setGeometry(QRect(380, 560, 101, 101));
        btn_doctors->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton{\n"
"background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/doctor_icon.png);\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"    border: 5px solid #00BCD4;\n"
"}"));
        btn_patients = new QPushButton(centralWidget);
        btn_patients->setObjectName(QString::fromUtf8("btn_patients"));
        btn_patients->setGeometry(QRect(550, 570, 91, 91));
        btn_patients->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"\n"
"background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/patient-icon.png);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 5px solid #00BCD4;\n"
"}"));
        btn_lenses = new QPushButton(centralWidget);
        btn_lenses->setObjectName(QString::fromUtf8("btn_lenses"));
        btn_lenses->setGeometry(QRect(710, 570, 101, 101));
        btn_lenses->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/iol-icon.png);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 5px solid #00BCD4;\n"
"}"));
        btn_settings = new QPushButton(centralWidget);
        btn_settings->setObjectName(QString::fromUtf8("btn_settings"));
        btn_settings->setGeometry(QRect(860, 570, 91, 91));
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
        btn_print = new QPushButton(centralWidget);
        btn_print->setObjectName(QString::fromUtf8("btn_print"));
        btn_print->setGeometry(QRect(1010, 570, 91, 91));
        btn_print->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/print-icon.png);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 5px solid #00BCD4;\n"
"}"));
        lbl_calibrate = new QLabel(centralWidget);
        lbl_calibrate->setObjectName(QString::fromUtf8("lbl_calibrate"));
        lbl_calibrate->setGeometry(QRect(70, 670, 81, 21));
        lbl_calibrate->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_calculator = new QLabel(centralWidget);
        lbl_calculator->setObjectName(QString::fromUtf8("lbl_calculator"));
        lbl_calculator->setGeometry(QRect(230, 670, 81, 17));
        lbl_calculator->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_doctors = new QLabel(centralWidget);
        lbl_doctors->setObjectName(QString::fromUtf8("lbl_doctors"));
        lbl_doctors->setGeometry(QRect(400, 670, 67, 17));
        lbl_doctors->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_patients = new QLabel(centralWidget);
        lbl_patients->setObjectName(QString::fromUtf8("lbl_patients"));
        lbl_patients->setGeometry(QRect(560, 670, 67, 17));
        lbl_patients->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_lenses = new QLabel(centralWidget);
        lbl_lenses->setObjectName(QString::fromUtf8("lbl_lenses"));
        lbl_lenses->setGeometry(QRect(730, 670, 67, 17));
        lbl_lenses->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_settings = new QLabel(centralWidget);
        lbl_settings->setObjectName(QString::fromUtf8("lbl_settings"));
        lbl_settings->setGeometry(QRect(870, 670, 67, 17));
        lbl_settings->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_patients_2 = new QLabel(centralWidget);
        lbl_patients_2->setObjectName(QString::fromUtf8("lbl_patients_2"));
        lbl_patients_2->setGeometry(QRect(1030, 670, 67, 17));
        lbl_patients_2->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        WelcomeDialog->setCentralWidget(centralWidget);
        headerBar->raise();
=======
        WelcomeDialog->setCentralWidget(centralWidget);
>>>>>>> c45e4e3d7db5a6fc95b663ed077b6e12fe2a2556
        btn_ascan->raise();
        label->raise();
        lbl_time->raise();
        lbl_docName->raise();
        lbl_softwareVersion->raise();
        lbl_serialNumber->raise();
        frame->raise();
<<<<<<< HEAD
        btn_calibrate->raise();
        btn_calculator->raise();
        btn_doctors->raise();
        btn_patients->raise();
        btn_lenses->raise();
        btn_settings->raise();
        btn_print->raise();
        lbl_calibrate->raise();
        lbl_calculator->raise();
        lbl_doctors->raise();
        lbl_patients->raise();
        lbl_lenses->raise();
        lbl_settings->raise();
        lbl_patients_2->raise();
=======
>>>>>>> c45e4e3d7db5a6fc95b663ed077b6e12fe2a2556

        retranslateUi(WelcomeDialog);

        QMetaObject::connectSlotsByName(WelcomeDialog);
    } // setupUi

    void retranslateUi(QMainWindow *WelcomeDialog)
    {
        WelcomeDialog->setWindowTitle(QCoreApplication::translate("WelcomeDialog", "WelcomeDialog", nullptr));
        btn_ascan->setText(QString());
        btn_surgeon->setText(QString());
        btn_enter->setText(QCoreApplication::translate("WelcomeDialog", "Enter", nullptr));
        btn_newDoctor_2->setText(QCoreApplication::translate("WelcomeDialog", "+ New Patient", nullptr));
        label->setText(QCoreApplication::translate("WelcomeDialog", "A-Scan", nullptr));
        lbl_time->setText(QCoreApplication::translate("WelcomeDialog", "10:09", nullptr));
        lbl_docName->setText(QCoreApplication::translate("WelcomeDialog", "Welcome, Dr. J Doe, M.D. ", nullptr));
        lbl_softwareVersion->setText(QCoreApplication::translate("WelcomeDialog", "Version:", nullptr));
        lbl_serialNumber->setText(QString());
<<<<<<< HEAD
        btn_calibrate->setText(QString());
        btn_calculator->setText(QString());
        btn_doctors->setText(QString());
        btn_patients->setText(QString());
        btn_lenses->setText(QString());
        btn_settings->setText(QString());
        btn_print->setText(QString());
        lbl_calibrate->setText(QCoreApplication::translate("WelcomeDialog", "Calibration", nullptr));
        lbl_calculator->setText(QCoreApplication::translate("WelcomeDialog", "Calculator", nullptr));
        lbl_doctors->setText(QCoreApplication::translate("WelcomeDialog", "Doctors", nullptr));
        lbl_patients->setText(QCoreApplication::translate("WelcomeDialog", "Patients", nullptr));
        lbl_lenses->setText(QCoreApplication::translate("WelcomeDialog", "Lenses", nullptr));
        lbl_settings->setText(QCoreApplication::translate("WelcomeDialog", "Settings", nullptr));
        lbl_patients_2->setText(QCoreApplication::translate("WelcomeDialog", "Print", nullptr));
=======
>>>>>>> c45e4e3d7db5a6fc95b663ed077b6e12fe2a2556
    } // retranslateUi

};

namespace Ui {
    class WelcomeDialog: public Ui_WelcomeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEDIALOG_H
