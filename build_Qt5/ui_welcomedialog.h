/********************************************************************************
** Form generated from reading UI file 'welcomedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
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

    void setupUi(QMainWindow *WelcomeDialog)
    {
        if (WelcomeDialog->objectName().isEmpty())
            WelcomeDialog->setObjectName(QString::fromUtf8("WelcomeDialog"));
        WelcomeDialog->resize(1280, 720);
        QFont font;
        font.setPointSize(15);
        WelcomeDialog->setFont(font);
        WelcomeDialog->setStyleSheet(QString::fromUtf8("background-image: url(:/images/7.png);\n"
""));
        centralWidget = new QWidget(WelcomeDialog);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        btn_ascan = new QPushButton(centralWidget);
        btn_ascan->setObjectName(QString::fromUtf8("btn_ascan"));
        btn_ascan->setGeometry(QRect(530, 0, 231, 191));
        btn_ascan->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/ascan-select1.png);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 5px solid #00BCD4;\n"
"}\n"
"\n"
"\n"
"QPushButton{\n"
"	background-color: rgb(255,255,255);\n"
"	border: 1.5px solid #E2E8F0;\n"
"	border-radius: 20px;\n"
"	border-image: url(:/images/ascan-select.png);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 3px solid #00BCD4;\n"
"}\n"
"\n"
"\n"
"\n"
""));
        btn_ascan->setFlat(true);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(130, 230, 1011, 431));
        frame->setStyleSheet(QString::fromUtf8("QFrame#frame\n"
"{\n"
"    background-color: rgb(255,255,255);\n"
"    border: 1px solid rgb(226,232,240);\n"
"    border-radius: 22px;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        btn_surgeon = new QPushButton(frame);
        btn_surgeon->setObjectName(QString::fromUtf8("btn_surgeon"));
        btn_surgeon->setGeometry(QRect(170, 150, 141, 141));
        QFont font1;
        font1.setPointSize(13);
        btn_surgeon->setFont(font1);
        btn_surgeon->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/patient-icon.png);"));
        btn_surgeon->setFlat(true);
        btn_enter = new QPushButton(frame);
        btn_enter->setObjectName(QString::fromUtf8("btn_enter"));
        btn_enter->setGeometry(QRect(850, 370, 120, 40));
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
""));
        btn_enter->setFlat(true);
        btn_newDoctor_2 = new QPushButton(frame);
        btn_newDoctor_2->setObjectName(QString::fromUtf8("btn_newDoctor_2"));
        btn_newDoctor_2->setGeometry(QRect(630, 370, 181, 40));
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
"\n"
""));
        btn_newDoctor_2->setFlat(true);
        comboBox_patientSelect = new FixedComboBox(frame);
        comboBox_patientSelect->setObjectName(QString::fromUtf8("comboBox_patientSelect"));
        comboBox_patientSelect->setGeometry(QRect(330, 190, 541, 61));
        comboBox_patientSelect->setStyleSheet(QString::fromUtf8("/*QComboBox\n"
"{\n"
"    background-color: white;\n"
"    border: 1px solid #E2E8F0;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    color: #334155;\n"
"    outline: none;\n"
"}\n"
"\n"
"QComboBox:focus\n"
"{\n"
"    border: 1px solid #3B82F6;\n"
"    outline: none;\n"
"}\n"
"\n"
"QComboBox:on\n"
"{\n"
"    border: 1px solid #3B82F6;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView\n"
"{\n"
"    background: white;\n"
"    border: 1px solid #80c0e4;\n"
"    selection-background-color: #DCEEFF;\n"
"    selection-color: #1E40AF;\n"
"    outline: 0;\n"
"}*/\n"
"\n"
"QComboBox\n"
"{\n"
"    background-color: #FBFCFE;\n"
"    border: 1.5px solid #DCE3EA;\n"
"    border-radius: 12px;\n"
"    padding: 8px 18px;\n"
"    color: #334155;\n"
"    outline: none;\n"
"}\n"
"\n"
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
""
                        "    width: 34px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView\n"
"{\n"
"    background: white;\n"
"    border: 1px solid #DCE3EA;\n"
"    selection-background-color: #E3F0FD;\n"
"    selection-color: #1976D2;\n"
"    outline: 0;\n"
"    padding: 4px;\n"
"}"));
        comboBox_patientSelect->setFrame(true);
        btn_newDoctor_2->raise();
        btn_surgeon->raise();
        btn_enter->raise();
        comboBox_patientSelect->raise();
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(550, 200, 192, 17));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: #2C3E50;\n"
"letter-spacing: 1px;"));
        label->setAlignment(Qt::AlignCenter);
        lbl_time = new QLabel(centralWidget);
        lbl_time->setObjectName(QString::fromUtf8("lbl_time"));
        lbl_time->setGeometry(QRect(1129, 10, 131, 41));
        lbl_time->setFont(font1);
        lbl_time->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        lbl_time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lbl_docName = new QLabel(centralWidget);
        lbl_docName->setObjectName(QString::fromUtf8("lbl_docName"));
        lbl_docName->setGeometry(QRect(20, 0, 261, 61));
        lbl_docName->setFont(font);
        lbl_docName->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color:rgb(21,21,21);\n"
"border-image:url(:/images/empty.png);"));
        lbl_softwareVersion = new QLabel(centralWidget);
        lbl_softwareVersion->setObjectName(QString::fromUtf8("lbl_softwareVersion"));
        lbl_softwareVersion->setGeometry(QRect(10, 670, 151, 41));
        lbl_softwareVersion->setStyleSheet(QString::fromUtf8("color:rgb(21,21,21);\n"
"background-image:url(:/images/empty.png);"));
        lbl_serialNumber = new QLabel(centralWidget);
        lbl_serialNumber->setObjectName(QString::fromUtf8("lbl_serialNumber"));
        lbl_serialNumber->setGeometry(QRect(660, 570, 140, 28));
        lbl_serialNumber->setStyleSheet(QString::fromUtf8("color:rgb(21,21,21);\n"
"background-image:url(:/images/empty.png);"));
        lbl_serialNumber->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        WelcomeDialog->setCentralWidget(centralWidget);
        btn_ascan->raise();
        label->raise();
        lbl_time->raise();
        lbl_docName->raise();
        lbl_softwareVersion->raise();
        lbl_serialNumber->raise();
        frame->raise();

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
    } // retranslateUi

};

namespace Ui {
    class WelcomeDialog: public Ui_WelcomeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEDIALOG_H
