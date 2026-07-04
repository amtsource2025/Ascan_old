/********************************************************************************
** Form generated from reading UI file 'calibrationdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATIONDIALOG_H
#define UI_CALIBRATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CalibrationDialog
{
public:
    QFrame *wm_plt;
    QPushButton *marker_cornea_2;
    QLabel *lbl_avgAl;
    QLineEdit *lineEdit_avgAl;
    QPushButton *btn_start;
    QPushButton *btn_back;
    QLabel *label;

    void setupUi(QDialog *CalibrationDialog)
    {
        if (CalibrationDialog->objectName().isEmpty())
            CalibrationDialog->setObjectName(QString::fromUtf8("CalibrationDialog"));
        CalibrationDialog->resize(1280, 720);
        CalibrationDialog->setStyleSheet(QString::fromUtf8("background-image: url(:/images/5.png);"));
        wm_plt = new QFrame(CalibrationDialog);
        wm_plt->setObjectName(QString::fromUtf8("wm_plt"));
        wm_plt->setGeometry(QRect(0, 130, 971, 431));
        wm_plt->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"background-image:url(empty.png);"));
        wm_plt->setFrameShape(QFrame::Shape::StyledPanel);
        wm_plt->setFrameShadow(QFrame::Shadow::Raised);
        marker_cornea_2 = new QPushButton(CalibrationDialog);
        marker_cornea_2->setObjectName(QString::fromUtf8("marker_cornea_2"));
        marker_cornea_2->setGeometry(QRect(0, 560, 971, 21));
        marker_cornea_2->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/scale.png);\n"
""));
        marker_cornea_2->setFlat(true);
        lbl_avgAl = new QLabel(CalibrationDialog);
        lbl_avgAl->setObjectName(QString::fromUtf8("lbl_avgAl"));
        lbl_avgAl->setGeometry(QRect(1020, 70, 80, 30));
        lbl_avgAl->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_avgAl->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_avgAl = new QLineEdit(CalibrationDialog);
        lineEdit_avgAl->setObjectName(QString::fromUtf8("lineEdit_avgAl"));
        lineEdit_avgAl->setGeometry(QRect(1120, 50, 130, 80));
        QFont font;
        font.setPointSize(32);
        lineEdit_avgAl->setFont(font);
        lineEdit_avgAl->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(empty.png);\n"
"color:rgb(21,21,21);"));
        lineEdit_avgAl->setAlignment(Qt::AlignmentFlag::AlignCenter);
        btn_start = new QPushButton(CalibrationDialog);
        btn_start->setObjectName(QString::fromUtf8("btn_start"));
        btn_start->setGeometry(QRect(1020, 630, 240, 70));
        btn_start->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"color: rgb(255, 255, 255);\n"
"background-color: #1976D2;\n"
"border-radius:5px;"));
        btn_back = new QPushButton(CalibrationDialog);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(10, 10, 81, 81));
        btn_back->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/backbutton.png);"));
        label = new QLabel(CalibrationDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(560, 40, 110, 40));
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        wm_plt->raise();
        marker_cornea_2->raise();
        lbl_avgAl->raise();
        lineEdit_avgAl->raise();
        btn_back->raise();
        label->raise();
        btn_start->raise();

        retranslateUi(CalibrationDialog);

        QMetaObject::connectSlotsByName(CalibrationDialog);
    } // setupUi

    void retranslateUi(QDialog *CalibrationDialog)
    {
        CalibrationDialog->setWindowTitle(QCoreApplication::translate("CalibrationDialog", "Dialog", nullptr));
        marker_cornea_2->setText(QString());
        lbl_avgAl->setText(QCoreApplication::translate("CalibrationDialog", "AVG AL:", nullptr));
        lineEdit_avgAl->setText(QString());
        btn_start->setText(QCoreApplication::translate("CalibrationDialog", "Start", nullptr));
        btn_back->setText(QString());
        label->setText(QCoreApplication::translate("CalibrationDialog", "Calibration", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalibrationDialog: public Ui_CalibrationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATIONDIALOG_H
