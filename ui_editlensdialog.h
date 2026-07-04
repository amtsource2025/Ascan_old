/********************************************************************************
** Form generated from reading UI file 'editlensdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITLENSDIALOG_H
#define UI_EDITLENSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EditLensDialog
{
public:
    QPushButton *btn_save;
    QLabel *snackbar;
    QPushButton *btn_cancel;
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
    QLabel *lbl_title;
    QLabel *lbl_time;

    void setupUi(QDialog *EditLensDialog)
    {
        if (EditLensDialog->objectName().isEmpty())
            EditLensDialog->setObjectName(QString::fromUtf8("EditLensDialog"));
        EditLensDialog->resize(1280, 720);
        EditLensDialog->setStyleSheet(QString::fromUtf8("background-image:url(:/images/5.png)"));
        btn_save = new QPushButton(EditLensDialog);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));
        btn_save->setGeometry(QRect(850, 590, 202, 65));
        btn_save->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"color: rgb(255, 255, 255);\n"
"background-color: #1976D2;\n"
"border-radius:5px;"));
        btn_save->setFlat(true);
        snackbar = new QLabel(EditLensDialog);
        snackbar->setObjectName(QString::fromUtf8("snackbar"));
        snackbar->setGeometry(QRect(0, 670, 1281, 40));
        snackbar->setStyleSheet(QString::fromUtf8("border-image: url(:/images/alert-red.png);\n"
"background-image:url(:/images/empty.png);color:rgb(255,255,255);"));
        snackbar->setIndent(5);
        btn_cancel = new QPushButton(EditLensDialog);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));
        btn_cancel->setGeometry(QRect(1070, 590, 202, 65));
        btn_cancel->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"color: #1976D2;\n"
"border: 1px solid #1976D2;border-radius:5px;"));
        btn_cancel->setFlat(true);
        frame = new QFrame(EditLensDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(6, 70, 1261, 511));
        frame->setStyleSheet(QString::fromUtf8("background-image: url(:/images/card-big.png);\n"
"border-image:url(:/images/empty.png);\n"
"background:rgb(255,255,255);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        lineEdit_iol = new QLineEdit(frame);
        lineEdit_iol->setObjectName(QString::fromUtf8("lineEdit_iol"));
        lineEdit_iol->setEnabled(false);
        lineEdit_iol->setGeometry(QRect(180, 40, 390, 30));
        QFont font;
        font.setPointSize(13);
        lineEdit_iol->setFont(font);
        lineEdit_iol->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        comboBox_lensType = new QComboBox(frame);
        comboBox_lensType->addItem(QString());
        comboBox_lensType->addItem(QString());
        comboBox_lensType->setObjectName(QString::fromUtf8("comboBox_lensType"));
        comboBox_lensType->setGeometry(QRect(180, 150, 260, 30));
        comboBox_lensType->setFont(font);
        comboBox_lensType->setStyleSheet(QString::fromUtf8(""));
        lbl_iolLens = new QLabel(frame);
        lbl_iolLens->setObjectName(QString::fromUtf8("lbl_iolLens"));
        lbl_iolLens->setGeometry(QRect(20, 40, 100, 17));
        lbl_iolLens->setFont(font);
        lbl_iolLens->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        lbl_company = new QLabel(frame);
        lbl_company->setObjectName(QString::fromUtf8("lbl_company"));
        lbl_company->setGeometry(QRect(20, 90, 120, 31));
        lbl_company->setFont(font);
        lbl_company->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        lbl_type = new QLabel(frame);
        lbl_type->setObjectName(QString::fromUtf8("lbl_type"));
        lbl_type->setGeometry(QRect(20, 160, 120, 21));
        lbl_type->setFont(font);
        lbl_type->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        lbl_asrkt = new QLabel(frame);
        lbl_asrkt->setObjectName(QString::fromUtf8("lbl_asrkt"));
        lbl_asrkt->setGeometry(QRect(20, 220, 61, 17));
        lbl_asrkt->setFont(font);
        lbl_asrkt->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        lbl_asrkii = new QLabel(frame);
        lbl_asrkii->setObjectName(QString::fromUtf8("lbl_asrkii"));
        lbl_asrkii->setGeometry(QRect(140, 220, 51, 17));
        lbl_asrkii->setFont(font);
        lbl_asrkii->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        lineEdit_company = new QLineEdit(frame);
        lineEdit_company->setObjectName(QString::fromUtf8("lineEdit_company"));
        lineEdit_company->setGeometry(QRect(180, 90, 390, 30));
        lineEdit_company->setFont(font);
        lineEdit_company->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lineEdit_asrkt = new QLineEdit(frame);
        lineEdit_asrkt->setObjectName(QString::fromUtf8("lineEdit_asrkt"));
        lineEdit_asrkt->setGeometry(QRect(20, 260, 70, 40));
        lineEdit_asrkt->setFont(font);
        lineEdit_asrkt->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lbl_acd = new QLabel(frame);
        lbl_acd->setObjectName(QString::fromUtf8("lbl_acd"));
        lbl_acd->setGeometry(QRect(260, 220, 61, 17));
        lbl_acd->setFont(font);
        lbl_acd->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        lineEdit_asrkii = new QLineEdit(frame);
        lineEdit_asrkii->setObjectName(QString::fromUtf8("lineEdit_asrkii"));
        lineEdit_asrkii->setGeometry(QRect(140, 260, 70, 40));
        lineEdit_asrkii->setFont(font);
        lineEdit_asrkii->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lineEdit_acd = new QLineEdit(frame);
        lineEdit_acd->setObjectName(QString::fromUtf8("lineEdit_acd"));
        lineEdit_acd->setGeometry(QRect(260, 260, 70, 40));
        lineEdit_acd->setFont(font);
        lineEdit_acd->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lineEdit_sf = new QLineEdit(frame);
        lineEdit_sf->setObjectName(QString::fromUtf8("lineEdit_sf"));
        lineEdit_sf->setGeometry(QRect(360, 260, 70, 40));
        lineEdit_sf->setFont(font);
        lineEdit_sf->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lbl_sf = new QLabel(frame);
        lbl_sf->setObjectName(QString::fromUtf8("lbl_sf"));
        lbl_sf->setGeometry(QRect(360, 220, 31, 17));
        lbl_sf->setFont(font);
        lbl_sf->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        lbl_a1 = new QLabel(frame);
        lbl_a1->setObjectName(QString::fromUtf8("lbl_a1"));
        lbl_a1->setGeometry(QRect(150, 340, 60, 17));
        lbl_a1->setFont(font);
        lbl_a1->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        lbl_a1->setAlignment(Qt::AlignCenter);
        lineEdit_a0 = new QLineEdit(frame);
        lineEdit_a0->setObjectName(QString::fromUtf8("lineEdit_a0"));
        lineEdit_a0->setGeometry(QRect(40, 380, 70, 21));
        lineEdit_a0->setFont(font);
        lineEdit_a0->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lineEdit_a1 = new QLineEdit(frame);
        lineEdit_a1->setObjectName(QString::fromUtf8("lineEdit_a1"));
        lineEdit_a1->setGeometry(QRect(170, 380, 70, 21));
        lineEdit_a1->setFont(font);
        lineEdit_a1->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lbl_a0 = new QLabel(frame);
        lbl_a0->setObjectName(QString::fromUtf8("lbl_a0"));
        lbl_a0->setGeometry(QRect(20, 340, 60, 17));
        lbl_a0->setFont(font);
        lbl_a0->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        lbl_a0->setAlignment(Qt::AlignCenter);
        lineEdit_a2 = new QLineEdit(frame);
        lineEdit_a2->setObjectName(QString::fromUtf8("lineEdit_a2"));
        lineEdit_a2->setGeometry(QRect(320, 380, 70, 21));
        lineEdit_a2->setFont(font);
        lineEdit_a2->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lbl_a2 = new QLabel(frame);
        lbl_a2->setObjectName(QString::fromUtf8("lbl_a2"));
        lbl_a2->setGeometry(QRect(310, 340, 60, 17));
        lbl_a2->setFont(font);
        lbl_a2->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        lbl_a2->setAlignment(Qt::AlignCenter);
        lbl_title = new QLabel(EditLensDialog);
        lbl_title->setObjectName(QString::fromUtf8("lbl_title"));
        lbl_title->setGeometry(QRect(550, 0, 160, 70));
        QFont font1;
        font1.setPointSize(16);
        lbl_title->setFont(font1);
        lbl_title->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        lbl_title->setAlignment(Qt::AlignCenter);
        lbl_time = new QLabel(EditLensDialog);
        lbl_time->setObjectName(QString::fromUtf8("lbl_time"));
        lbl_time->setGeometry(QRect(1150, 10, 120, 40));
        QFont font2;
        font2.setPointSize(9);
        lbl_time->setFont(font2);
        lbl_time->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);border-image:url(:/images/empty.png);"));
        lbl_time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(EditLensDialog);

        QMetaObject::connectSlotsByName(EditLensDialog);
    } // setupUi

    void retranslateUi(QDialog *EditLensDialog)
    {
        EditLensDialog->setWindowTitle(QCoreApplication::translate("EditLensDialog", "Dialog", nullptr));
        btn_save->setText(QCoreApplication::translate("EditLensDialog", "Save", nullptr));
        snackbar->setText(QString());
        btn_cancel->setText(QCoreApplication::translate("EditLensDialog", "Cancel", nullptr));
        comboBox_lensType->setItemText(0, QCoreApplication::translate("EditLensDialog", "Anterior", nullptr));
        comboBox_lensType->setItemText(1, QCoreApplication::translate("EditLensDialog", "Posterior", nullptr));

        lbl_iolLens->setText(QCoreApplication::translate("EditLensDialog", "Lens IOL", nullptr));
        lbl_company->setText(QCoreApplication::translate("EditLensDialog", "Company", nullptr));
        lbl_type->setText(QCoreApplication::translate("EditLensDialog", "Type", nullptr));
        lbl_asrkt->setText(QCoreApplication::translate("EditLensDialog", "ASRKT", nullptr));
        lbl_asrkii->setText(QCoreApplication::translate("EditLensDialog", "ASRKII", nullptr));
        lineEdit_asrkt->setText(QCoreApplication::translate("EditLensDialog", "118.01", nullptr));
        lbl_acd->setText(QCoreApplication::translate("EditLensDialog", "ACD", nullptr));
        lineEdit_asrkii->setText(QCoreApplication::translate("EditLensDialog", "117.9", nullptr));
        lineEdit_acd->setText(QCoreApplication::translate("EditLensDialog", "4.97", nullptr));
        lineEdit_sf->setText(QCoreApplication::translate("EditLensDialog", "1.23", nullptr));
        lbl_sf->setText(QCoreApplication::translate("EditLensDialog", "SF", nullptr));
        lbl_a1->setText(QCoreApplication::translate("EditLensDialog", "A1", nullptr));
        lineEdit_a0->setText(QCoreApplication::translate("EditLensDialog", "0.4", nullptr));
        lineEdit_a1->setText(QCoreApplication::translate("EditLensDialog", "0.1", nullptr));
        lbl_a0->setText(QCoreApplication::translate("EditLensDialog", "A0", nullptr));
        lineEdit_a2->setText(QCoreApplication::translate("EditLensDialog", "1.28", nullptr));
        lbl_a2->setText(QCoreApplication::translate("EditLensDialog", "A2", nullptr));
        lbl_title->setText(QCoreApplication::translate("EditLensDialog", "Edit Lens", nullptr));
        lbl_time->setText(QCoreApplication::translate("EditLensDialog", "10:09", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditLensDialog: public Ui_EditLensDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITLENSDIALOG_H
