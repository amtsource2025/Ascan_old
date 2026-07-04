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
        WelcomeDialog->setStyleSheet(QString::fromUtf8("background-image: url(:/images/5.png);"));
        centralWidget = new QWidget(WelcomeDialog);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        btn_ascan = new QPushButton(centralWidget);
        btn_ascan->setObjectName(QString::fromUtf8("btn_ascan"));
        btn_ascan->setGeometry(QRect(530, 0, 211, 151));
        btn_ascan->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"background-image:url(empty.png);\n"
"border-image: url(:/images/ascan-select.png);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 5px solid #00BCD4;\n"
"}\n"
"\n"
""));
        btn_ascan->setFlat(true);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(140, 170, 1011, 491));
        frame->setStyleSheet(QString::fromUtf8("border-image: url(:/images/card-big.png);\n"
"background-image:url(empty.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        btn_surgeon = new QPushButton(frame);
        btn_surgeon->setObjectName(QString::fromUtf8("btn_surgeon"));
        btn_surgeon->setGeometry(QRect(170, 210, 141, 141));
        QFont font1;
        font1.setPointSize(13);
        btn_surgeon->setFont(font1);
        btn_surgeon->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/patient-icon.png);"));
        btn_surgeon->setFlat(true);
        btn_enter = new QPushButton(frame);
        btn_enter->setObjectName(QString::fromUtf8("btn_enter"));
        btn_enter->setGeometry(QRect(870, 450, 120, 40));
        QFont font2;
        font2.setPointSize(16);
        btn_enter->setFont(font2);
        btn_enter->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"    border-image: url(empty.png);\n"
"    color: rgb(85, 87, 83);\n"
"    border: 2px solid transparent;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #80d4ff;\n"
"    border: 2px solid #006699;\n"
"    border-radius: 10px;\n"
"	color:#00334d\n"
"}\n"
"\n"
""));
        btn_enter->setFlat(true);
        btn_newDoctor_2 = new QPushButton(frame);
        btn_newDoctor_2->setObjectName(QString::fromUtf8("btn_newDoctor_2"));
        btn_newDoctor_2->setGeometry(QRect(710, 450, 130, 40));
        btn_newDoctor_2->setFont(font2);
        btn_newDoctor_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-image: url(empty.png);\n"
"    color: rgb(33, 150, 243);\n"
"    border: 2px solid transparent;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #80d4ff;\n"
"    border: 2px solid #006699;\n"
"    border-radius: 10px;\n"
"	color:#00334d\n"
"}"));
        btn_newDoctor_2->setFlat(true);
        comboBox_patientSelect = new FixedComboBox(frame);
        comboBox_patientSelect->setObjectName(QString::fromUtf8("comboBox_patientSelect"));
        comboBox_patientSelect->setGeometry(QRect(340, 250, 541, 61));
        comboBox_patientSelect->setFrame(true);
        btn_newDoctor_2->raise();
        btn_surgeon->raise();
        btn_enter->raise();
        comboBox_patientSelect->raise();
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(550, 150, 192, 17));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label->setAlignment(Qt::AlignCenter);
        lbl_time = new QLabel(centralWidget);
        lbl_time->setObjectName(QString::fromUtf8("lbl_time"));
        lbl_time->setGeometry(QRect(1129, 10, 131, 41));
        lbl_time->setFont(font1);
        lbl_time->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        lbl_time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lbl_docName = new QLabel(centralWidget);
        lbl_docName->setObjectName(QString::fromUtf8("lbl_docName"));
        lbl_docName->setGeometry(QRect(20, 0, 261, 61));
        lbl_docName->setFont(font);
        lbl_docName->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color:rgb(21,21,21);\n"
"border-image:url(empty.png);"));
        lbl_softwareVersion = new QLabel(centralWidget);
        lbl_softwareVersion->setObjectName(QString::fromUtf8("lbl_softwareVersion"));
        lbl_softwareVersion->setGeometry(QRect(10, 670, 151, 41));
        lbl_softwareVersion->setStyleSheet(QString::fromUtf8("color:rgb(21,21,21);\n"
"background-image:url(empty.png);"));
        lbl_serialNumber = new QLabel(centralWidget);
        lbl_serialNumber->setObjectName(QString::fromUtf8("lbl_serialNumber"));
        lbl_serialNumber->setGeometry(QRect(660, 570, 140, 28));
        lbl_serialNumber->setStyleSheet(QString::fromUtf8("color:rgb(21,21,21);\n"
"background-image:url(empty.png);"));
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
        btn_enter->setText(QCoreApplication::translate("WelcomeDialog", "ENTER", nullptr));
        btn_newDoctor_2->setText(QCoreApplication::translate("WelcomeDialog", "NEW", nullptr));
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
