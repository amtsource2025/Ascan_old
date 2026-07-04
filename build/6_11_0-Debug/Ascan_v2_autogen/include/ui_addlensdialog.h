/********************************************************************************
** Form generated from reading UI file 'addlensdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDLENSDIALOG_H
#define UI_ADDLENSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddLensDialog
{
public:
    QLabel *lbl_title;
    QPushButton *btn_cancel;
    QLabel *snackbar;
    QFrame *frame;
    QLineEdit *lineEdit_iol;
    QComboBox *comboBox_lensType;
    QLabel *lbl_iolLens;
    QLabel *lbl_company;
    QLabel *lbl_type;
    QLabel *lbl_asrkt;
    QLabel *lbl_asrkii;
    QLineEdit *lineEdit_company;
    QLineEdit *lineEdit_asrkt;
    QLabel *lbl_acd;
    QLineEdit *lineEdit_asrkii;
    QLineEdit *lineEdit_acd;
    QLineEdit *lineEdit_sf;
    QLabel *lbl_sf;
    QLabel *lbl_a1;
    QLineEdit *lineEdit_a0;
    QLineEdit *lineEdit_a1;
    QLabel *lbl_a0;
    QLineEdit *lineEdit_a2;
    QLabel *lbl_a2;
    QLabel *lbl_time;
    QPushButton *btn_save;

    void setupUi(QDialog *AddLensDialog)
    {
        if (AddLensDialog->objectName().isEmpty())
            AddLensDialog->setObjectName(QString::fromUtf8("AddLensDialog"));
        AddLensDialog->resize(1280, 720);
        AddLensDialog->setStyleSheet(QString::fromUtf8("border-image: url(:/images/5.png);"));
        lbl_title = new QLabel(AddLensDialog);
        lbl_title->setObjectName(QString::fromUtf8("lbl_title"));
        lbl_title->setGeometry(QRect(570, 0, 160, 70));
        QFont font;
        font.setPointSize(16);
        lbl_title->setFont(font);
        lbl_title->setStyleSheet(QString::fromUtf8("border-image: url(:/images/alert-red.png);\n"
"background-image:url(empty.png);\n"
"color:rgb(255,255,255);"));
        lbl_title->setAlignment(Qt::AlignmentFlag::AlignCenter);
        btn_cancel = new QPushButton(AddLensDialog);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));
        btn_cancel->setGeometry(QRect(1070, 590, 202, 65));
        btn_cancel->setStyleSheet(QString::fromUtf8("color: rgb(25, 118, 210);\n"
"border: 1px solid rgb(25, 118, 210);\n"
"border-radius:5px;\n"
"border-image:url(empty.png);"));
        btn_cancel->setFlat(true);
        snackbar = new QLabel(AddLensDialog);
        snackbar->setObjectName(QString::fromUtf8("snackbar"));
        snackbar->setGeometry(QRect(0, 670, 1281, 40));
        snackbar->setStyleSheet(QString::fromUtf8("border-image: url(:/images/alert-red.png);\n"
"background-image:url(empty.png);\n"
"color:rgb(255,255,255);"));
        snackbar->setIndent(5);
        frame = new QFrame(AddLensDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(6, 73, 1261, 511));
        frame->setStyleSheet(QString::fromUtf8("background-image: url(:/images/card-big.png);\n"
"border-image:url(empty.png);\n"
"background:rgb(255,255,255);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit_iol = new QLineEdit(frame);
        lineEdit_iol->setObjectName(QString::fromUtf8("lineEdit_iol"));
        lineEdit_iol->setGeometry(QRect(180, 23, 390, 30));
        lineEdit_iol->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        comboBox_lensType = new QComboBox(frame);
        comboBox_lensType->addItem(QString());
        comboBox_lensType->addItem(QString());
        comboBox_lensType->setObjectName(QString::fromUtf8("comboBox_lensType"));
        comboBox_lensType->setGeometry(QRect(180, 130, 260, 27));
        comboBox_lensType->setStyleSheet(QString::fromUtf8(""));
        lbl_iolLens = new QLabel(frame);
        lbl_iolLens->setObjectName(QString::fromUtf8("lbl_iolLens"));
        lbl_iolLens->setGeometry(QRect(20, 30, 100, 17));
        lbl_iolLens->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        lbl_company = new QLabel(frame);
        lbl_company->setObjectName(QString::fromUtf8("lbl_company"));
        lbl_company->setGeometry(QRect(20, 80, 120, 17));
        lbl_company->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        lbl_type = new QLabel(frame);
        lbl_type->setObjectName(QString::fromUtf8("lbl_type"));
        lbl_type->setGeometry(QRect(20, 133, 120, 17));
        lbl_type->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        lbl_asrkt = new QLabel(frame);
        lbl_asrkt->setObjectName(QString::fromUtf8("lbl_asrkt"));
        lbl_asrkt->setGeometry(QRect(20, 185, 130, 17));
        lbl_asrkt->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        lbl_asrkii = new QLabel(frame);
        lbl_asrkii->setObjectName(QString::fromUtf8("lbl_asrkii"));
        lbl_asrkii->setGeometry(QRect(130, 186, 130, 17));
        lbl_asrkii->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        lineEdit_company = new QLineEdit(frame);
        lineEdit_company->setObjectName(QString::fromUtf8("lineEdit_company"));
        lineEdit_company->setGeometry(QRect(180, 76, 390, 30));
        lineEdit_company->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        lineEdit_asrkt = new QLineEdit(frame);
        lineEdit_asrkt->setObjectName(QString::fromUtf8("lineEdit_asrkt"));
        lineEdit_asrkt->setGeometry(QRect(20, 210, 70, 40));
        lineEdit_asrkt->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        lbl_acd = new QLabel(frame);
        lbl_acd->setObjectName(QString::fromUtf8("lbl_acd"));
        lbl_acd->setGeometry(QRect(250, 185, 130, 17));
        lbl_acd->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        lineEdit_asrkii = new QLineEdit(frame);
        lineEdit_asrkii->setObjectName(QString::fromUtf8("lineEdit_asrkii"));
        lineEdit_asrkii->setGeometry(QRect(130, 210, 70, 40));
        lineEdit_asrkii->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        lineEdit_acd = new QLineEdit(frame);
        lineEdit_acd->setObjectName(QString::fromUtf8("lineEdit_acd"));
        lineEdit_acd->setGeometry(QRect(250, 210, 70, 40));
        lineEdit_acd->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        lineEdit_sf = new QLineEdit(frame);
        lineEdit_sf->setObjectName(QString::fromUtf8("lineEdit_sf"));
        lineEdit_sf->setGeometry(QRect(350, 210, 70, 40));
        lineEdit_sf->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        lbl_sf = new QLabel(frame);
        lbl_sf->setObjectName(QString::fromUtf8("lbl_sf"));
        lbl_sf->setGeometry(QRect(350, 185, 130, 17));
        lbl_sf->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        lbl_a1 = new QLabel(frame);
        lbl_a1->setObjectName(QString::fromUtf8("lbl_a1"));
        lbl_a1->setGeometry(QRect(130, 261, 60, 17));
        lbl_a1->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        lbl_a1->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_a0 = new QLineEdit(frame);
        lineEdit_a0->setObjectName(QString::fromUtf8("lineEdit_a0"));
        lineEdit_a0->setGeometry(QRect(20, 285, 70, 40));
        lineEdit_a0->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        lineEdit_a1 = new QLineEdit(frame);
        lineEdit_a1->setObjectName(QString::fromUtf8("lineEdit_a1"));
        lineEdit_a1->setGeometry(QRect(130, 285, 70, 40));
        lineEdit_a1->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        lbl_a0 = new QLabel(frame);
        lbl_a0->setObjectName(QString::fromUtf8("lbl_a0"));
        lbl_a0->setGeometry(QRect(20, 260, 60, 17));
        lbl_a0->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        lbl_a0->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_a2 = new QLineEdit(frame);
        lineEdit_a2->setObjectName(QString::fromUtf8("lineEdit_a2"));
        lineEdit_a2->setGeometry(QRect(250, 285, 70, 40));
        lineEdit_a2->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        lbl_a2 = new QLabel(frame);
        lbl_a2->setObjectName(QString::fromUtf8("lbl_a2"));
        lbl_a2->setGeometry(QRect(250, 260, 60, 17));
        lbl_a2->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        lbl_a2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lbl_time = new QLabel(AddLensDialog);
        lbl_time->setObjectName(QString::fromUtf8("lbl_time"));
        lbl_time->setGeometry(QRect(1160, 0, 120, 40));
        QFont font1;
        font1.setPointSize(9);
        lbl_time->setFont(font1);
        lbl_time->setStyleSheet(QString::fromUtf8("border-image: url(:/images/alert-red.png);\n"
"background-image:url(empty.png);\n"
"color:rgb(255,255,255);"));
        lbl_time->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        btn_save = new QPushButton(AddLensDialog);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));
        btn_save->setGeometry(QRect(850, 590, 202, 65));
        btn_save->setAutoFillBackground(false);
        btn_save->setStyleSheet(QString::fromUtf8("border-image:url(empty.png);\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(25, 118, 210);\n"
"border-radius:5px;"));
        btn_save->setFlat(false);

        retranslateUi(AddLensDialog);

        QMetaObject::connectSlotsByName(AddLensDialog);
    } // setupUi

    void retranslateUi(QDialog *AddLensDialog)
    {
        AddLensDialog->setWindowTitle(QCoreApplication::translate("AddLensDialog", "Dialog", nullptr));
        lbl_title->setText(QCoreApplication::translate("AddLensDialog", "Add Lens", nullptr));
        btn_cancel->setText(QCoreApplication::translate("AddLensDialog", "Cancel", nullptr));
        snackbar->setText(QString());
        comboBox_lensType->setItemText(0, QCoreApplication::translate("AddLensDialog", "Anterior", nullptr));
        comboBox_lensType->setItemText(1, QCoreApplication::translate("AddLensDialog", "Posterior", nullptr));

        lbl_iolLens->setText(QCoreApplication::translate("AddLensDialog", "Lens IOL", nullptr));
        lbl_company->setText(QCoreApplication::translate("AddLensDialog", "Company", nullptr));
        lbl_type->setText(QCoreApplication::translate("AddLensDialog", "Type", nullptr));
        lbl_asrkt->setText(QCoreApplication::translate("AddLensDialog", "ASRKT", nullptr));
        lbl_asrkii->setText(QCoreApplication::translate("AddLensDialog", "ASRKII", nullptr));
        lineEdit_asrkt->setText(QCoreApplication::translate("AddLensDialog", "118.01", nullptr));
        lbl_acd->setText(QCoreApplication::translate("AddLensDialog", "ACD", nullptr));
        lineEdit_asrkii->setText(QCoreApplication::translate("AddLensDialog", "117.9", nullptr));
        lineEdit_acd->setText(QCoreApplication::translate("AddLensDialog", "4.97", nullptr));
        lineEdit_sf->setText(QCoreApplication::translate("AddLensDialog", "1.23", nullptr));
        lbl_sf->setText(QCoreApplication::translate("AddLensDialog", "SF", nullptr));
        lbl_a1->setText(QCoreApplication::translate("AddLensDialog", "A1", nullptr));
        lineEdit_a0->setText(QCoreApplication::translate("AddLensDialog", "0.4", nullptr));
        lineEdit_a1->setText(QCoreApplication::translate("AddLensDialog", "0.1", nullptr));
        lbl_a0->setText(QCoreApplication::translate("AddLensDialog", "A0", nullptr));
        lineEdit_a2->setText(QCoreApplication::translate("AddLensDialog", "1.28", nullptr));
        lbl_a2->setText(QCoreApplication::translate("AddLensDialog", "A2", nullptr));
        lbl_time->setText(QCoreApplication::translate("AddLensDialog", "10:09", nullptr));
        btn_save->setText(QCoreApplication::translate("AddLensDialog", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddLensDialog: public Ui_AddLensDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDLENSDIALOG_H
