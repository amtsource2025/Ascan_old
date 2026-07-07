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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "QtCharts"

QT_BEGIN_NAMESPACE

class Ui_PrintDialog
{
public:
    QPushButton *btn_back;
    QLabel *label;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_2;
    QWidget *page_2;
    QPushButton *btn_printScan;
    QTextEdit *plainTextEdit_scan;
    QWidget *page_3;
    QPushButton *btn_printCalc;
    QPlainTextEdit *plainTextEdit_calc;
    QWidget *page_4;
    QPushButton *btn_printAll;
    QPlainTextEdit *plainTextEdit_all;
    QPushButton *btn_scan;
    QPushButton *btn_scan2;
    QPushButton *btn_calculations2;
    QPushButton *btn_calculations;
    QPushButton *btn_both;
    QPushButton *btn_both3;
    QPushButton *btn_both2;
    QLabel *snackbar;
    QComboBox *comboBox;
    QChartView *graphicsView;
    QProgressBar *progressBar;
    QProgressBar *progressBar_2;
    QLabel *lbl_time;
    QPushButton *btn_newPatient;
    QPushButton *btn_newPatient2;
    QProgressBar *progressBar_3;

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
        label->setGeometry(QRect(550, 30, 180, 40));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget = new QStackedWidget(PrintDialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(130, 40, 30, 30));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        label_2 = new QLabel(page);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(330, 160, 110, 40));
        label_2->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        btn_printScan = new QPushButton(page_2);
        btn_printScan->setObjectName(QString::fromUtf8("btn_printScan"));
        btn_printScan->setGeometry(QRect(620, 364, 160, 70));
        btn_printScan->setStyleSheet(QString::fromUtf8("border-image: url(:/images/purple-btn.png);\n"
"color:rgb(255,255,255);\n"
"background-image:url(empty.png);"));
        plainTextEdit_scan = new QTextEdit(page_2);
        plainTextEdit_scan->setObjectName(QString::fromUtf8("plainTextEdit_scan"));
        plainTextEdit_scan->setGeometry(QRect(20, 20, 770, 330));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        btn_printCalc = new QPushButton(page_3);
        btn_printCalc->setObjectName(QString::fromUtf8("btn_printCalc"));
        btn_printCalc->setGeometry(QRect(620, 365, 160, 70));
        btn_printCalc->setStyleSheet(QString::fromUtf8("border-image: url(:/images/purple-btn.png);\n"
"color:rgb(255,255,255);\n"
"background-image:url(empty.png);"));
        plainTextEdit_calc = new QPlainTextEdit(page_3);
        plainTextEdit_calc->setObjectName(QString::fromUtf8("plainTextEdit_calc"));
        plainTextEdit_calc->setGeometry(QRect(20, 20, 770, 330));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        btn_printAll = new QPushButton(page_4);
        btn_printAll->setObjectName(QString::fromUtf8("btn_printAll"));
        btn_printAll->setGeometry(QRect(620, 365, 160, 70));
        btn_printAll->setStyleSheet(QString::fromUtf8("border-image: url(:/images/purple-btn.png);\n"
"color:rgb(255,255,255);\n"
"background-image:url(empty.png);"));
        plainTextEdit_all = new QPlainTextEdit(page_4);
        plainTextEdit_all->setObjectName(QString::fromUtf8("plainTextEdit_all"));
        plainTextEdit_all->setGeometry(QRect(20, 20, 770, 330));
        stackedWidget->addWidget(page_4);
        btn_scan = new QPushButton(PrintDialog);
        btn_scan->setObjectName(QString::fromUtf8("btn_scan"));
        btn_scan->setGeometry(QRect(90, 300, 271, 151));
        btn_scan->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-mid.png);\n"
"background-image:url(empty.png);"));
        btn_scan2 = new QPushButton(PrintDialog);
        btn_scan2->setObjectName(QString::fromUtf8("btn_scan2"));
        btn_scan2->setGeometry(QRect(90, 290, 71, 71));
        btn_scan2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/graph-icon.png);\n"
"background-image:url(empty.png);"));
        btn_calculations2 = new QPushButton(PrintDialog);
        btn_calculations2->setObjectName(QString::fromUtf8("btn_calculations2"));
        btn_calculations2->setGeometry(QRect(510, 280, 71, 71));
        btn_calculations2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/calculator-icon.png);\n"
"background-image:url(empty.png);"));
        btn_calculations = new QPushButton(PrintDialog);
        btn_calculations->setObjectName(QString::fromUtf8("btn_calculations"));
        btn_calculations->setGeometry(QRect(520, 300, 271, 151));
        btn_calculations->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-mid.png);\n"
"background-image:url(empty.png);"));
        btn_both = new QPushButton(PrintDialog);
        btn_both->setObjectName(QString::fromUtf8("btn_both"));
        btn_both->setGeometry(QRect(950, 300, 271, 151));
        btn_both->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-mid.png);\n"
"background-image:url(empty.png);"));
        btn_both3 = new QPushButton(PrintDialog);
        btn_both3->setObjectName(QString::fromUtf8("btn_both3"));
        btn_both3->setGeometry(QRect(980, 280, 71, 71));
        btn_both3->setStyleSheet(QString::fromUtf8("border-image: url(:/images/calculator-icon.png);\n"
"background-image:url(empty.png);"));
        btn_both2 = new QPushButton(PrintDialog);
        btn_both2->setObjectName(QString::fromUtf8("btn_both2"));
        btn_both2->setGeometry(QRect(940, 280, 71, 71));
        btn_both2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/graph-icon.png);\n"
"background-image:url(empty.png);"));
        snackbar = new QLabel(PrintDialog);
        snackbar->setObjectName(QString::fromUtf8("snackbar"));
        snackbar->setGeometry(QRect(0, 660, 1281, 47));
        snackbar->setFont(font);
        snackbar->setStyleSheet(QString::fromUtf8("border-image: url(:/images/alert-red.png);\n"
"background-image:url(empty.png);color:rgb(255,255,255);"));
        snackbar->setIndent(5);
        comboBox = new QComboBox(PrintDialog);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(1040, 60, 220, 40));
        comboBox->setStyleSheet(QString::fromUtf8(""));
        graphicsView = new QChartView(PrintDialog);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, -360, 510, 350));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"background-color: rgb(255,255, 255);"));
        progressBar = new QProgressBar(PrintDialog);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(100, 310, 260, 10));
        progressBar->setValue(0);
        progressBar_2 = new QProgressBar(PrintDialog);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setGeometry(QRect(950, 310, 260, 10));
        progressBar_2->setValue(0);
        lbl_time = new QLabel(PrintDialog);
        lbl_time->setObjectName(QString::fromUtf8("lbl_time"));
        lbl_time->setGeometry(QRect(1150, 10, 120, 40));
        QFont font1;
        font1.setPointSize(11);
        lbl_time->setFont(font1);
        lbl_time->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        lbl_time->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        btn_newPatient = new QPushButton(PrintDialog);
        btn_newPatient->setObjectName(QString::fromUtf8("btn_newPatient"));
        btn_newPatient->setGeometry(QRect(110, 120, 221, 91));
        btn_newPatient->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-mid.png);\n"
"background-image:url(empty.png);"));
        btn_newPatient2 = new QPushButton(PrintDialog);
        btn_newPatient2->setObjectName(QString::fromUtf8("btn_newPatient2"));
        btn_newPatient2->setGeometry(QRect(130, 130, 60, 60));
        btn_newPatient2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/patient-icon.png);\n"
"background-image:url(empty.png);"));
        progressBar_3 = new QProgressBar(PrintDialog);
        progressBar_3->setObjectName(QString::fromUtf8("progressBar_3"));
        progressBar_3->setGeometry(QRect(530, 310, 260, 10));
        progressBar_3->setValue(0);
        graphicsView->raise();
        btn_both->raise();
        btn_scan->raise();
        snackbar->raise();
        btn_back->raise();
        label->raise();
        stackedWidget->raise();
        btn_calculations->raise();
        comboBox->raise();
        progressBar->raise();
        progressBar_2->raise();
        lbl_time->raise();
        btn_newPatient->raise();
        btn_newPatient2->raise();
        btn_scan2->raise();
        btn_both3->raise();
        btn_both2->raise();
        progressBar_3->raise();
        btn_calculations2->raise();

        retranslateUi(PrintDialog);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(PrintDialog);
    } // setupUi

    void retranslateUi(QDialog *PrintDialog)
    {
        PrintDialog->setWindowTitle(QCoreApplication::translate("PrintDialog", "Dialog", nullptr));
        btn_back->setText(QString());
        label->setText(QCoreApplication::translate("PrintDialog", "Print", nullptr));
        label_2->setText(QCoreApplication::translate("PrintDialog", "Select a mode", nullptr));
        btn_printScan->setText(QCoreApplication::translate("PrintDialog", "Print", nullptr));
        btn_printCalc->setText(QCoreApplication::translate("PrintDialog", "Print", nullptr));
        btn_printAll->setText(QCoreApplication::translate("PrintDialog", "Print", nullptr));
        btn_scan->setText(QCoreApplication::translate("PrintDialog", "Print Scan", nullptr));
        btn_scan2->setText(QString());
        btn_calculations2->setText(QString());
        btn_calculations->setText(QCoreApplication::translate("PrintDialog", "Print Calculations", nullptr));
        btn_both->setText(QCoreApplication::translate("PrintDialog", "Print Scan && Calculation", nullptr));
        btn_both3->setText(QString());
        btn_both2->setText(QString());
        snackbar->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("PrintDialog", "Thermal", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("PrintDialog", "Wireless", nullptr));

        progressBar->setFormat(QString());
        progressBar_2->setFormat(QString());
        lbl_time->setText(QCoreApplication::translate("PrintDialog", "10:09", nullptr));
        btn_newPatient->setText(QCoreApplication::translate("PrintDialog", "New\n"
"Patient", nullptr));
        btn_newPatient2->setText(QString());
        progressBar_3->setFormat(QString());
    } // retranslateUi

};

namespace Ui {
    class PrintDialog: public Ui_PrintDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTDIALOG_H
