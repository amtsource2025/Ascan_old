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
    QLabel *lbl_time;
    QFrame *frame;
    QLabel *lbl_sectionInfo;
    QLabel *lbl_iolLens;
    QLineEdit *lineEdit_iol;
    QLabel *lbl_company;
    QLineEdit *lineEdit_company;
    QLabel *lbl_type;
    QComboBox *comboBox_lensType;
    QLabel *lbl_sectionConstants;
    QLabel *lbl_asrkt;
    QLineEdit *lineEdit_asrkt;
    QLabel *lbl_asrkii;
    QLineEdit *lineEdit_asrkii;
    QLabel *lbl_acd;
    QLineEdit *lineEdit_acd;
    QLabel *lbl_sf;
    QLineEdit *lineEdit_sf;
    QLabel *lbl_a0;
    QLineEdit *lineEdit_a0;
    QLabel *lbl_a1;
    QLineEdit *lineEdit_a1;
    QLabel *lbl_a2;
    QLineEdit *lineEdit_a2;
    QPushButton *btn_cancel;
    QPushButton *btn_save;
    QLabel *snackbar;

    void setupUi(QDialog *AddLensDialog)
    {
        if (AddLensDialog->objectName().isEmpty())
            AddLensDialog->setObjectName(QString::fromUtf8("AddLensDialog"));
        AddLensDialog->resize(1280, 720);
        AddLensDialog->setStyleSheet(QString::fromUtf8("\n"
"QDialog{\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1,\n"
"		stop:0 #eef2f8, stop:1 #e4ebf5);\n"
"	font-family: \"Segoe UI\";\n"
"}"));
        lbl_title = new QLabel(AddLensDialog);
        lbl_title->setObjectName(QString::fromUtf8("lbl_title"));
        lbl_title->setGeometry(QRect(0, 0, 1280, 72));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        lbl_title->setFont(font);
        lbl_title->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0,\n"
"		stop:0 #1A5FB4, stop:0.55 #1976D2, stop:1 #2E9BDA);\n"
"	color: rgb(255,255,255);\n"
"	border-bottom-left-radius: 18px;\n"
"	border-bottom-right-radius: 18px;\n"
"	letter-spacing: 1px;\n"
"}"));
        lbl_title->setAlignment(Qt::AlignCenter);
        lbl_time = new QLabel(AddLensDialog);
        lbl_time->setObjectName(QString::fromUtf8("lbl_time"));
        lbl_time->setGeometry(QRect(1120, 16, 140, 40));
        QFont font1;
        font1.setPointSize(10);
        lbl_time->setFont(font1);
        lbl_time->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background: transparent;\n"
"	color: rgba(255,255,255,220);\n"
"	letter-spacing: 1px;\n"
"}"));
        lbl_time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        frame = new QFrame(AddLensDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(40, 96, 1200, 492));
        frame->setStyleSheet(QString::fromUtf8("QFrame#frame{\n"
"	background: rgb(255,255,255);\n"
"	border: 1px solid #E2E8F0;\n"
"	border-radius: 16px;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        lbl_sectionInfo = new QLabel(frame);
        lbl_sectionInfo->setObjectName(QString::fromUtf8("lbl_sectionInfo"));
        lbl_sectionInfo->setGeometry(QRect(80, 18, 400, 22));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        lbl_sectionInfo->setFont(font2);
        lbl_sectionInfo->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background: transparent;\n"
"	color: #1976D2;\n"
"	letter-spacing: 2px;\n"
"}"));
        lbl_iolLens = new QLabel(frame);
        lbl_iolLens->setObjectName(QString::fromUtf8("lbl_iolLens"));
        lbl_iolLens->setGeometry(QRect(80, 52, 200, 22));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        lbl_iolLens->setFont(font3);
        lbl_iolLens->setStyleSheet(QString::fromUtf8("QLabel{ background: transparent; color: #2C3E50; }"));
        lineEdit_iol = new QLineEdit(frame);
        lineEdit_iol->setObjectName(QString::fromUtf8("lineEdit_iol"));
        lineEdit_iol->setGeometry(QRect(80, 78, 480, 42));
        QFont font4;
        font4.setPointSize(12);
        lineEdit_iol->setFont(font4);
        lineEdit_iol->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background: #FBFCFE;\n"
"	border: 1.5px solid #DCE3EA;\n"
"	border-radius: 9px;\n"
"	padding: 4px 12px;\n"
"	color: #2C3E50;\n"
"	selection-background-color: #90CAF9;\n"
"}\n"
"QLineEdit:focus{\n"
"	border: 1.5px solid #1976D2;\n"
"	background: #FFFFFF;\n"
"}\n"
"QLineEdit:hover{\n"
"	border: 1.5px solid #A9C4E8;\n"
"}"));
        lbl_company = new QLabel(frame);
        lbl_company->setObjectName(QString::fromUtf8("lbl_company"));
        lbl_company->setGeometry(QRect(640, 52, 200, 22));
        lbl_company->setFont(font3);
        lbl_company->setStyleSheet(QString::fromUtf8("QLabel{ background: transparent; color: #2C3E50; }"));
        lineEdit_company = new QLineEdit(frame);
        lineEdit_company->setObjectName(QString::fromUtf8("lineEdit_company"));
        lineEdit_company->setGeometry(QRect(640, 78, 480, 42));
        lineEdit_company->setFont(font4);
        lineEdit_company->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background: #FBFCFE;\n"
"	border: 1.5px solid #DCE3EA;\n"
"	border-radius: 9px;\n"
"	padding: 4px 12px;\n"
"	color: #2C3E50;\n"
"	selection-background-color: #90CAF9;\n"
"}\n"
"QLineEdit:focus{\n"
"	border: 1.5px solid #1976D2;\n"
"	background: #FFFFFF;\n"
"}\n"
"QLineEdit:hover{\n"
"	border: 1.5px solid #A9C4E8;\n"
"}"));
        lbl_type = new QLabel(frame);
        lbl_type->setObjectName(QString::fromUtf8("lbl_type"));
        lbl_type->setGeometry(QRect(80, 150, 200, 22));
        lbl_type->setFont(font3);
        lbl_type->setStyleSheet(QString::fromUtf8("QLabel{ background: transparent; color: #2C3E50; }"));
        comboBox_lensType = new QComboBox(frame);
        comboBox_lensType->addItem(QString());
        comboBox_lensType->addItem(QString());
        comboBox_lensType->setObjectName(QString::fromUtf8("comboBox_lensType"));
        comboBox_lensType->setGeometry(QRect(80, 176, 320, 42));
        comboBox_lensType->setFont(font4);
        comboBox_lensType->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"	background: #FBFCFE;\n"
"	border: 1.5px solid #DCE3EA;\n"
"	border-radius: 9px;\n"
"	padding: 4px 12px;\n"
"	color: #2C3E50;\n"
"}\n"
"QComboBox:hover{\n"
"	border: 1.5px solid #A9C4E8;\n"
"}\n"
"QComboBox:focus, QComboBox:on{\n"
"	border: 1.5px solid #1976D2;\n"
"	background: #FFFFFF;\n"
"}\n"
"QComboBox::drop-down{\n"
"	border: none;\n"
"	width: 28px;\n"
"}\n"
"QComboBox QAbstractItemView{\n"
"	background: #FFFFFF;\n"
"	border: 1px solid #DCE3EA;\n"
"	selection-background-color: #E3F0FD;\n"
"	selection-color: #1976D2;\n"
"	outline: none;\n"
"	padding: 4px;\n"
"}"));
        lbl_sectionConstants = new QLabel(frame);
        lbl_sectionConstants->setObjectName(QString::fromUtf8("lbl_sectionConstants"));
        lbl_sectionConstants->setGeometry(QRect(80, 242, 400, 22));
        lbl_sectionConstants->setFont(font2);
        lbl_sectionConstants->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background: transparent;\n"
"	color: #1976D2;\n"
"	letter-spacing: 2px;\n"
"}"));
        lbl_asrkt = new QLabel(frame);
        lbl_asrkt->setObjectName(QString::fromUtf8("lbl_asrkt"));
        lbl_asrkt->setGeometry(QRect(80, 276, 230, 20));
        lbl_asrkt->setFont(font2);
        lbl_asrkt->setStyleSheet(QString::fromUtf8("QLabel{ background: transparent; color: #64748B; letter-spacing: 1px; }"));
        lineEdit_asrkt = new QLineEdit(frame);
        lineEdit_asrkt->setObjectName(QString::fromUtf8("lineEdit_asrkt"));
        lineEdit_asrkt->setGeometry(QRect(80, 298, 230, 54));
        QFont font5;
        font5.setPointSize(14);
        font5.setBold(true);
        font5.setWeight(75);
        lineEdit_asrkt->setFont(font5);
        lineEdit_asrkt->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background: #F5F9FE;\n"
"	border: 1.5px solid #DCE7F5;\n"
"	border-radius: 12px;\n"
"	color: #1976D2;\n"
"	selection-background-color: #90CAF9;\n"
"}\n"
"QLineEdit:focus{\n"
"	border: 1.5px solid #1976D2;\n"
"	background: #FFFFFF;\n"
"}\n"
"QLineEdit:hover{\n"
"	border: 1.5px solid #A9C4E8;\n"
"}"));
        lineEdit_asrkt->setAlignment(Qt::AlignCenter);
        lbl_asrkii = new QLabel(frame);
        lbl_asrkii->setObjectName(QString::fromUtf8("lbl_asrkii"));
        lbl_asrkii->setGeometry(QRect(350, 276, 230, 20));
        lbl_asrkii->setFont(font2);
        lbl_asrkii->setStyleSheet(QString::fromUtf8("QLabel{ background: transparent; color: #64748B; letter-spacing: 1px; }"));
        lineEdit_asrkii = new QLineEdit(frame);
        lineEdit_asrkii->setObjectName(QString::fromUtf8("lineEdit_asrkii"));
        lineEdit_asrkii->setGeometry(QRect(350, 298, 230, 54));
        lineEdit_asrkii->setFont(font5);
        lineEdit_asrkii->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background: #F5F9FE;\n"
"	border: 1.5px solid #DCE7F5;\n"
"	border-radius: 12px;\n"
"	color: #1976D2;\n"
"	selection-background-color: #90CAF9;\n"
"}\n"
"QLineEdit:focus{\n"
"	border: 1.5px solid #1976D2;\n"
"	background: #FFFFFF;\n"
"}\n"
"QLineEdit:hover{\n"
"	border: 1.5px solid #A9C4E8;\n"
"}"));
        lineEdit_asrkii->setAlignment(Qt::AlignCenter);
        lbl_acd = new QLabel(frame);
        lbl_acd->setObjectName(QString::fromUtf8("lbl_acd"));
        lbl_acd->setGeometry(QRect(620, 276, 230, 20));
        lbl_acd->setFont(font2);
        lbl_acd->setStyleSheet(QString::fromUtf8("QLabel{ background: transparent; color: #64748B; letter-spacing: 1px; }"));
        lineEdit_acd = new QLineEdit(frame);
        lineEdit_acd->setObjectName(QString::fromUtf8("lineEdit_acd"));
        lineEdit_acd->setGeometry(QRect(620, 298, 230, 54));
        lineEdit_acd->setFont(font5);
        lineEdit_acd->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background: #F5F9FE;\n"
"	border: 1.5px solid #DCE7F5;\n"
"	border-radius: 12px;\n"
"	color: #1976D2;\n"
"	selection-background-color: #90CAF9;\n"
"}\n"
"QLineEdit:focus{\n"
"	border: 1.5px solid #1976D2;\n"
"	background: #FFFFFF;\n"
"}\n"
"QLineEdit:hover{\n"
"	border: 1.5px solid #A9C4E8;\n"
"}"));
        lineEdit_acd->setAlignment(Qt::AlignCenter);
        lbl_sf = new QLabel(frame);
        lbl_sf->setObjectName(QString::fromUtf8("lbl_sf"));
        lbl_sf->setGeometry(QRect(890, 276, 230, 20));
        lbl_sf->setFont(font2);
        lbl_sf->setStyleSheet(QString::fromUtf8("QLabel{ background: transparent; color: #64748B; letter-spacing: 1px; }"));
        lineEdit_sf = new QLineEdit(frame);
        lineEdit_sf->setObjectName(QString::fromUtf8("lineEdit_sf"));
        lineEdit_sf->setGeometry(QRect(890, 298, 230, 54));
        lineEdit_sf->setFont(font5);
        lineEdit_sf->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background: #F5F9FE;\n"
"	border: 1.5px solid #DCE7F5;\n"
"	border-radius: 12px;\n"
"	color: #1976D2;\n"
"	selection-background-color: #90CAF9;\n"
"}\n"
"QLineEdit:focus{\n"
"	border: 1.5px solid #1976D2;\n"
"	background: #FFFFFF;\n"
"}\n"
"QLineEdit:hover{\n"
"	border: 1.5px solid #A9C4E8;\n"
"}"));
        lineEdit_sf->setAlignment(Qt::AlignCenter);
        lbl_a0 = new QLabel(frame);
        lbl_a0->setObjectName(QString::fromUtf8("lbl_a0"));
        lbl_a0->setGeometry(QRect(80, 372, 320, 20));
        lbl_a0->setFont(font2);
        lbl_a0->setStyleSheet(QString::fromUtf8("QLabel{ background: transparent; color: #64748B; letter-spacing: 1px; }"));
        lbl_a0->setAlignment(Qt::AlignCenter);
        lineEdit_a0 = new QLineEdit(frame);
        lineEdit_a0->setObjectName(QString::fromUtf8("lineEdit_a0"));
        lineEdit_a0->setGeometry(QRect(80, 394, 320, 54));
        lineEdit_a0->setFont(font5);
        lineEdit_a0->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background: #FDF3E7;\n"
"	border: 1.5px solid #F6DFC0;\n"
"	border-radius: 12px;\n"
"	color: #B26A00;\n"
"	selection-background-color: #FCE0B0;\n"
"}\n"
"QLineEdit:focus{\n"
"	border: 1.5px solid #E08E00;\n"
"	background: #FFFFFF;\n"
"}\n"
"QLineEdit:hover{\n"
"	border: 1.5px solid #EBBE7C;\n"
"}"));
        lineEdit_a0->setAlignment(Qt::AlignCenter);
        lbl_a1 = new QLabel(frame);
        lbl_a1->setObjectName(QString::fromUtf8("lbl_a1"));
        lbl_a1->setGeometry(QRect(440, 372, 320, 20));
        lbl_a1->setFont(font2);
        lbl_a1->setStyleSheet(QString::fromUtf8("QLabel{ background: transparent; color: #64748B; letter-spacing: 1px; }"));
        lbl_a1->setAlignment(Qt::AlignCenter);
        lineEdit_a1 = new QLineEdit(frame);
        lineEdit_a1->setObjectName(QString::fromUtf8("lineEdit_a1"));
        lineEdit_a1->setGeometry(QRect(440, 394, 320, 54));
        lineEdit_a1->setFont(font5);
        lineEdit_a1->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background: #FDF3E7;\n"
"	border: 1.5px solid #F6DFC0;\n"
"	border-radius: 12px;\n"
"	color: #B26A00;\n"
"	selection-background-color: #FCE0B0;\n"
"}\n"
"QLineEdit:focus{\n"
"	border: 1.5px solid #E08E00;\n"
"	background: #FFFFFF;\n"
"}\n"
"QLineEdit:hover{\n"
"	border: 1.5px solid #EBBE7C;\n"
"}"));
        lineEdit_a1->setAlignment(Qt::AlignCenter);
        lbl_a2 = new QLabel(frame);
        lbl_a2->setObjectName(QString::fromUtf8("lbl_a2"));
        lbl_a2->setGeometry(QRect(800, 372, 320, 20));
        lbl_a2->setFont(font2);
        lbl_a2->setStyleSheet(QString::fromUtf8("QLabel{ background: transparent; color: #64748B; letter-spacing: 1px; }"));
        lbl_a2->setAlignment(Qt::AlignCenter);
        lineEdit_a2 = new QLineEdit(frame);
        lineEdit_a2->setObjectName(QString::fromUtf8("lineEdit_a2"));
        lineEdit_a2->setGeometry(QRect(800, 394, 320, 54));
        lineEdit_a2->setFont(font5);
        lineEdit_a2->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background: #FDF3E7;\n"
"	border: 1.5px solid #F6DFC0;\n"
"	border-radius: 12px;\n"
"	color: #B26A00;\n"
"	selection-background-color: #FCE0B0;\n"
"}\n"
"QLineEdit:focus{\n"
"	border: 1.5px solid #E08E00;\n"
"	background: #FFFFFF;\n"
"}\n"
"QLineEdit:hover{\n"
"	border: 1.5px solid #EBBE7C;\n"
"}"));
        lineEdit_a2->setAlignment(Qt::AlignCenter);
        btn_cancel = new QPushButton(AddLensDialog);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));
        btn_cancel->setGeometry(QRect(898, 608, 170, 56));
        btn_cancel->setFont(font3);
        btn_cancel->setCursor(QCursor(Qt::PointingHandCursor));
        btn_cancel->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background: #FFFFFF;\n"
"	color: #1976D2;\n"
"	border: 1.5px solid #1976D2;\n"
"	border-radius: 10px;\n"
"}\n"
"QPushButton:hover{\n"
"	background: #EAF3FC;\n"
"}\n"
"QPushButton:pressed{\n"
"	background: #D7E9FA;\n"
"}"));
        btn_cancel->setFlat(false);
        btn_save = new QPushButton(AddLensDialog);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));
        btn_save->setGeometry(QRect(1088, 608, 170, 56));
        btn_save->setFont(font3);
        btn_save->setAutoFillBackground(false);
        btn_save->setCursor(QCursor(Qt::PointingHandCursor));
        btn_save->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: rgb(255, 255, 255);\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0,\n"
"		stop:0 #1976D2, stop:1 #2E9BDA);\n"
"	border: none;\n"
"	border-radius: 10px;\n"
"}\n"
"QPushButton:hover{\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0,\n"
"		stop:0 #1668BC, stop:1 #2789C4);\n"
"}\n"
"QPushButton:pressed{\n"
"	background: #14589F;\n"
"}"));
        btn_save->setFlat(false);
        snackbar = new QLabel(AddLensDialog);
        snackbar->setObjectName(QString::fromUtf8("snackbar"));
        snackbar->setGeometry(QRect(340, 668, 600, 44));
        QFont font6;
        font6.setPointSize(11);
        font6.setBold(true);
        font6.setWeight(75);
        snackbar->setFont(font6);
        snackbar->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0,\n"
"		stop:0 #E53935, stop:1 #EF5350);\n"
"	color: rgb(255,255,255);\n"
"	border-radius: 22px;\n"
"	padding: 0px 18px;\n"
"}"));
        snackbar->setAlignment(Qt::AlignCenter);
        snackbar->setIndent(0);

        retranslateUi(AddLensDialog);

        QMetaObject::connectSlotsByName(AddLensDialog);
    } // setupUi

    void retranslateUi(QDialog *AddLensDialog)
    {
        AddLensDialog->setWindowTitle(QCoreApplication::translate("AddLensDialog", "Dialog", nullptr));
        lbl_title->setText(QCoreApplication::translate("AddLensDialog", "Add Lens", nullptr));
        lbl_time->setText(QCoreApplication::translate("AddLensDialog", "10:09", nullptr));
        lbl_sectionInfo->setText(QCoreApplication::translate("AddLensDialog", "LENS INFORMATION", nullptr));
        lbl_iolLens->setText(QCoreApplication::translate("AddLensDialog", "Lens IOL", nullptr));
        lbl_company->setText(QCoreApplication::translate("AddLensDialog", "Company", nullptr));
        lbl_type->setText(QCoreApplication::translate("AddLensDialog", "Type", nullptr));
        comboBox_lensType->setItemText(0, QCoreApplication::translate("AddLensDialog", "Anterior", nullptr));
        comboBox_lensType->setItemText(1, QCoreApplication::translate("AddLensDialog", "Posterior", nullptr));

        lbl_sectionConstants->setText(QCoreApplication::translate("AddLensDialog", "IOL CONSTANTS", nullptr));
        lbl_asrkt->setText(QCoreApplication::translate("AddLensDialog", "ASRKT", nullptr));
        lineEdit_asrkt->setText(QCoreApplication::translate("AddLensDialog", "118.01", nullptr));
        lbl_asrkii->setText(QCoreApplication::translate("AddLensDialog", "ASRKII", nullptr));
        lineEdit_asrkii->setText(QCoreApplication::translate("AddLensDialog", "117.9", nullptr));
        lbl_acd->setText(QCoreApplication::translate("AddLensDialog", "ACD", nullptr));
        lineEdit_acd->setText(QCoreApplication::translate("AddLensDialog", "4.97", nullptr));
        lbl_sf->setText(QCoreApplication::translate("AddLensDialog", "SF", nullptr));
        lineEdit_sf->setText(QCoreApplication::translate("AddLensDialog", "1.23", nullptr));
        lbl_a0->setText(QCoreApplication::translate("AddLensDialog", "A0", nullptr));
        lineEdit_a0->setText(QCoreApplication::translate("AddLensDialog", "0.4", nullptr));
        lbl_a1->setText(QCoreApplication::translate("AddLensDialog", "A1", nullptr));
        lineEdit_a1->setText(QCoreApplication::translate("AddLensDialog", "0.1", nullptr));
        lbl_a2->setText(QCoreApplication::translate("AddLensDialog", "A2", nullptr));
        lineEdit_a2->setText(QCoreApplication::translate("AddLensDialog", "1.28", nullptr));
        btn_cancel->setText(QCoreApplication::translate("AddLensDialog", "Cancel", nullptr));
        btn_save->setText(QCoreApplication::translate("AddLensDialog", "Save", nullptr));
        snackbar->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddLensDialog: public Ui_AddLensDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDLENSDIALOG_H
