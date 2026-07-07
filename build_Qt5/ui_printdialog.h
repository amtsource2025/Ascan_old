/********************************************************************************
** Form generated from reading UI file 'printdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTDIALOG_H
#define UI_PRINTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include "QtCharts"

QT_BEGIN_NAMESPACE

class Ui_PrintDialog
{
public:
    QPushButton *btn_back;
    QLabel *label;
    QPushButton *btn_scan;
    QPushButton *btn_scan2;
    QPushButton *btn_calculations2;
    QPushButton *btn_calculations;
    QPushButton *btn_both;
    QPushButton *btn_both2;
    QLabel *snackbar;
    QChartView *graphicsView;
    QLabel *lbl_time;
    QPushButton *pushButton;

    void setupUi(QDialog *PrintDialog)
    {
        if (PrintDialog->objectName().isEmpty())
            PrintDialog->setObjectName(QString::fromUtf8("PrintDialog"));
        PrintDialog->resize(1280, 720);
        PrintDialog->setStyleSheet(QString::fromUtf8("background-image: url(:/images/5.png);"));
        btn_back = new QPushButton(PrintDialog);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(1180, 570, 81, 81));
        btn_back->setStyleSheet(QString::fromUtf8("border-image: url(:/images/backbutton.png);"));
        btn_back->setFlat(true);
        label = new QLabel(PrintDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(489, 40, 251, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("/*background-image:url(:/images/empty.png);*/\n"
"\n"
"QLabel {\n"
"    color: #023e8a;\n"
"    font-size: 30px;\n"
"    font-weight: bold;\n"
"    font-family: \"Arial\";\n"
"    background: transparent;\n"
"    border: none;\n"
"}"));
        label->setAlignment(Qt::AlignCenter);
        btn_scan = new QPushButton(PrintDialog);
        btn_scan->setObjectName(QString::fromUtf8("btn_scan"));
        btn_scan->setGeometry(QRect(120, 150, 351, 191));
        QFont font1;
        font1.setBold(true);
        btn_scan->setFont(font1);
        btn_scan->setStyleSheet(QString::fromUtf8("/*border-image: url(:/images/btn-mid.png);\n"
"border-color: rgb(119, 118, 123);\n"
"background-image:url(:/images/empty.png);*/\n"
"\n"
"QPushButton {\n"
"    border-image: url(:/images/btn-mid.png);\n"
"    background-image: url(:/images/empty.png);\n"
"    background-repeat: no-repeat;\n"
"    text-align: centre;\n"
"    padding-left: 90px;   /* leave space for the icon */\n"
"    padding-right: 30px;  /* leave space for the chevron */\n"
"    min-height: 90px;\n"
"    min-width: 200px;\n"
"    font-weight: bold;\n"
"    font-size: 22px;\n"
"    color: #2bb3a3;\n"
"	border-color: rgb(43, 179, 163);\n"
"\n"
"}\n"
""));
        btn_scan2 = new QPushButton(PrintDialog);
        btn_scan2->setObjectName(QString::fromUtf8("btn_scan2"));
        btn_scan2->setGeometry(QRect(140, 190, 111, 111));
        btn_scan2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/graph-icon.png);\n"
"background-image:url(:/images/empty.png);"));
        btn_calculations2 = new QPushButton(PrintDialog);
        btn_calculations2->setObjectName(QString::fromUtf8("btn_calculations2"));
        btn_calculations2->setGeometry(QRect(510, 190, 101, 101));
        btn_calculations2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/calculator-icon.png);\n"
"background-image:url(:/images/empty.png);"));
        btn_calculations = new QPushButton(PrintDialog);
        btn_calculations->setObjectName(QString::fromUtf8("btn_calculations"));
        btn_calculations->setGeometry(QRect(490, 150, 351, 191));
        btn_calculations->setFont(font1);
        btn_calculations->setStyleSheet(QString::fromUtf8("/*border-image: url(:/images/btn-mid.png);\n"
"background-image:url(:/images/empty.png);*/\n"
"\n"
"QPushButton {\n"
"    border-image: url(:/images/btn-mid.png);\n"
"    background-image: url(:/images/empty.png);\n"
"    background-repeat: no-repeat;\n"
"    text-align: centre;\n"
"    padding-left: 90px;   /* leave space for the icon */\n"
"    padding-right: 30px;  /* leave space for the chevron */\n"
"    min-height: 90px;\n"
"    min-width: 200px;\n"
"    font-weight: bold;\n"
"    font-size: 22px;\n"
"    color: #0077b6;\n"
"}\n"
"\n"
"\n"
""));
        btn_both = new QPushButton(PrintDialog);
        btn_both->setObjectName(QString::fromUtf8("btn_both"));
        btn_both->setGeometry(QRect(120, 360, 731, 181));
        btn_both->setFont(font1);
        btn_both->setStyleSheet(QString::fromUtf8("/*border-image: url(:/images/btn-mid.png);\n"
"background-image:url(:/images/empty.png);*/\n"
"\n"
"QPushButton {\n"
"    border-image: url(:/images/btn-mid.png);\n"
"    background-image: url(:/images/empty.png);\n"
"    background-repeat: no-repeat;\n"
"    text-align: centre;\n"
"    padding-left: 90px;   /* leave space for the icon */\n"
"    padding-right: 30px;  /* leave space for the chevron */\n"
"    min-height: 90px;\n"
"    min-width: 200px;\n"
"    font-weight: bold;\n"
"    font-size: 22px;\n"
"    color: #9b5de5;\n"
"}\n"
"\n"
"\n"
""));
        btn_both2 = new QPushButton(PrintDialog);
        btn_both2->setObjectName(QString::fromUtf8("btn_both2"));
        btn_both2->setGeometry(QRect(150, 390, 121, 121));
        btn_both2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/calc-icon-shrt.png);\n"
"background-image:url(:/images/empty.png);"));
        snackbar = new QLabel(PrintDialog);
        snackbar->setObjectName(QString::fromUtf8("snackbar"));
        snackbar->setGeometry(QRect(0, 660, 1281, 47));
        QFont font2;
        font2.setPointSize(16);
        snackbar->setFont(font2);
        snackbar->setStyleSheet(QString::fromUtf8("border-image: url(:/images/alert-red.png);\n"
"background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        snackbar->setIndent(5);
        graphicsView = new QChartView(PrintDialog);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, -360, 510, 350));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"background-color: rgb(255,255, 255);"));
        lbl_time = new QLabel(PrintDialog);
        lbl_time->setObjectName(QString::fromUtf8("lbl_time"));
        lbl_time->setGeometry(QRect(1150, 10, 120, 40));
        QFont font3;
        font3.setPointSize(11);
        lbl_time->setFont(font3);
        lbl_time->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        lbl_time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton = new QPushButton(PrintDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(480, 20, 91, 91));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/images/calc-icon-shrt(1).png);\n"
"background-image:url(:/images/empty.png);"));
        graphicsView->raise();
        btn_both->raise();
        btn_scan->raise();
        snackbar->raise();
        btn_back->raise();
        label->raise();
        btn_calculations->raise();
        lbl_time->raise();
        btn_scan2->raise();
        btn_calculations2->raise();
        btn_both2->raise();
        pushButton->raise();

        retranslateUi(PrintDialog);

        QMetaObject::connectSlotsByName(PrintDialog);
    } // setupUi

    void retranslateUi(QDialog *PrintDialog)
    {
        PrintDialog->setWindowTitle(QCoreApplication::translate("PrintDialog", "Dialog", nullptr));
        btn_back->setText(QString());
        label->setText(QCoreApplication::translate("PrintDialog", "Print", nullptr));
        btn_scan->setText(QCoreApplication::translate("PrintDialog", "Print Scan", nullptr));
        btn_scan2->setText(QString());
        btn_calculations2->setText(QString());
        btn_calculations->setText(QCoreApplication::translate("PrintDialog", "Print Calculations", nullptr));
        btn_both->setText(QCoreApplication::translate("PrintDialog", "Print Scan && Calculation", nullptr));
        btn_both2->setText(QString());
        snackbar->setText(QString());
        lbl_time->setText(QCoreApplication::translate("PrintDialog", "10:09", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PrintDialog: public Ui_PrintDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTDIALOG_H
