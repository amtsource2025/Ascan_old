/********************************************************************************
** Form generated from reading UI file 'adddoctordialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDOCTORDIALOG_H
#define UI_ADDDOCTORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddDoctorDialog
{
public:
    QLabel *label_7;
    QLabel *lbl_time;
    QFrame *frame;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label;
    QLineEdit *lineEdit_docName;
    QLabel *label_2;
    QComboBox *comboBox_lensPresetOne;
    QLabel *label_3;
    QComboBox *comboBox_lensPresetTwo;
    QLabel *label_4;
    QComboBox *comboBox_lensPresetThree;
    QLabel *label_5;
    QComboBox *comboBox_primaryFormula;
    QPushButton *btn_cancel;
    QPushButton *btn_save;
    QLabel *snackbar;

    void setupUi(QDialog *AddDoctorDialog)
    {
        if (AddDoctorDialog->objectName().isEmpty())
            AddDoctorDialog->setObjectName(QString::fromUtf8("AddDoctorDialog"));
        AddDoctorDialog->resize(1280, 720);
        AddDoctorDialog->setStyleSheet(QString::fromUtf8("\n"
"QDialog{\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1,\n"
"		stop:0 #eef2f8, stop:1 #e4ebf5);\n"
"	font-family: \"Segoe UI\";\n"
"}"));
        label_7 = new QLabel(AddDoctorDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(0, 0, 1280, 72));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        label_7->setFont(font);
        label_7->setLayoutDirection(Qt::LeftToRight);
        label_7->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0,\n"
"		stop:0 #1A5FB4, stop:0.55 #1976D2, stop:1 #2E9BDA);\n"
"	color: rgb(255,255,255);\n"
"	border-bottom-left-radius: 18px;\n"
"	border-bottom-right-radius: 18px;\n"
"	letter-spacing: 1px;\n"
"}"));
        label_7->setAlignment(Qt::AlignCenter);
        lbl_time = new QLabel(AddDoctorDialog);
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
        frame = new QFrame(AddDoctorDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(40, 100, 1200, 460));
        frame->setStyleSheet(QString::fromUtf8("QFrame#frame{\n"
"	background: rgb(255,255,255);\n"
"	border: 1px solid #E2E8F0;\n"
"	border-radius: 16px;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 36, 64, 64));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setCursor(QCursor(Qt::ArrowCursor));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	/*border-image:url(:/images/doctor_icon.png);*/\n"
"	background-color: #E8F1FC;\n"
"	border-radius: 32px;\n"
"	border: 2px solid #BFDBFE;\n"
"}"));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 118, 64, 64));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #FDEAEC;\n"
"	border-radius: 32px;\n"
"	border: 2px solid #F5C6CB;\n"
"	color: transparent;\n"
"}"));
        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(60, 198, 64, 64));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #EAF7EF;\n"
"	border-radius: 32px;\n"
"	border: 2px solid #C7ECD4;\n"
"	color: transparent;\n"
"}"));
        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(60, 278, 64, 64));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #F3EEFB;\n"
"	border-radius: 32px;\n"
"	border: 2px solid #DCCFF3;\n"
"	color: transparent;\n"
"}"));
        pushButton_5 = new QPushButton(frame);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(60, 358, 64, 64));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #FDEAEC;\n"
"	border-radius: 32px;\n"
"	border: 2px solid #F5C6CB;\n"
"	color: transparent;\n"
"}"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 38, 171, 28));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("QLabel{ background: transparent; color: #2C3E50; }"));
        lineEdit_docName = new QLineEdit(frame);
        lineEdit_docName->setObjectName(QString::fromUtf8("lineEdit_docName"));
        lineEdit_docName->setGeometry(QRect(350, 34, 420, 38));
        QFont font3;
        font3.setPointSize(12);
        lineEdit_docName->setFont(font3);
        lineEdit_docName->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
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
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 133, 171, 28));
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("QLabel{ background: transparent; color: #2C3E50; }"));
        comboBox_lensPresetOne = new QComboBox(frame);
        comboBox_lensPresetOne->setObjectName(QString::fromUtf8("comboBox_lensPresetOne"));
        comboBox_lensPresetOne->setGeometry(QRect(350, 128, 280, 38));
        comboBox_lensPresetOne->setFont(font3);
        comboBox_lensPresetOne->setStyleSheet(QString::fromUtf8("QComboBox{\n"
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
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 213, 171, 28));
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("QLabel{ background: transparent; color: #2C3E50; }"));
        comboBox_lensPresetTwo = new QComboBox(frame);
        comboBox_lensPresetTwo->setObjectName(QString::fromUtf8("comboBox_lensPresetTwo"));
        comboBox_lensPresetTwo->setGeometry(QRect(350, 208, 280, 38));
        comboBox_lensPresetTwo->setFont(font3);
        comboBox_lensPresetTwo->setStyleSheet(QString::fromUtf8("QComboBox{\n"
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
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(160, 293, 171, 28));
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("QLabel{ background: transparent; color: #2C3E50; }"));
        comboBox_lensPresetThree = new QComboBox(frame);
        comboBox_lensPresetThree->setObjectName(QString::fromUtf8("comboBox_lensPresetThree"));
        comboBox_lensPresetThree->setGeometry(QRect(350, 288, 280, 38));
        comboBox_lensPresetThree->setFont(font3);
        comboBox_lensPresetThree->setStyleSheet(QString::fromUtf8("QComboBox{\n"
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
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(160, 373, 171, 28));
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("QLabel{ background: transparent; color: #2C3E50; }"));
        comboBox_primaryFormula = new QComboBox(frame);
        comboBox_primaryFormula->addItem(QString());
        comboBox_primaryFormula->addItem(QString());
        comboBox_primaryFormula->addItem(QString());
        comboBox_primaryFormula->addItem(QString());
        comboBox_primaryFormula->addItem(QString());
        comboBox_primaryFormula->setObjectName(QString::fromUtf8("comboBox_primaryFormula"));
        comboBox_primaryFormula->setGeometry(QRect(350, 368, 280, 38));
        comboBox_primaryFormula->setFont(font3);
        comboBox_primaryFormula->setStyleSheet(QString::fromUtf8("QComboBox{\n"
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
        btn_cancel = new QPushButton(AddDoctorDialog);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));
        btn_cancel->setGeometry(QRect(898, 600, 170, 56));
        btn_cancel->setFont(font2);
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
        btn_save = new QPushButton(AddDoctorDialog);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));
        btn_save->setGeometry(QRect(1088, 600, 170, 56));
        btn_save->setFont(font2);
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
        snackbar = new QLabel(AddDoctorDialog);
        snackbar->setObjectName(QString::fromUtf8("snackbar"));
        snackbar->setGeometry(QRect(340, 660, 600, 44));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(true);
        snackbar->setFont(font4);
        snackbar->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0,\n"
"		stop:0 #E53935, stop:1 #EF5350);\n"
"	color: rgb(255,255,255);\n"
"	border-radius: 22px;\n"
"	padding: 0px 18px;\n"
"}"));
        snackbar->setAlignment(Qt::AlignCenter);
        snackbar->setIndent(0);

        retranslateUi(AddDoctorDialog);

        QMetaObject::connectSlotsByName(AddDoctorDialog);
    } // setupUi

    void retranslateUi(QDialog *AddDoctorDialog)
    {
        AddDoctorDialog->setWindowTitle(QCoreApplication::translate("AddDoctorDialog", "Dialog", nullptr));
        label_7->setText(QCoreApplication::translate("AddDoctorDialog", "Add Doctor", nullptr));
        lbl_time->setText(QCoreApplication::translate("AddDoctorDialog", "10:09", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("AddDoctorDialog", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("AddDoctorDialog", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("AddDoctorDialog", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("AddDoctorDialog", "Doctor Name", nullptr));
        label_2->setText(QCoreApplication::translate("AddDoctorDialog", "Lens Preset One", nullptr));
        label_3->setText(QCoreApplication::translate("AddDoctorDialog", "Lens Preset Two", nullptr));
        label_4->setText(QCoreApplication::translate("AddDoctorDialog", "Lens Preset Three", nullptr));
        label_5->setText(QCoreApplication::translate("AddDoctorDialog", "Primary Formula", nullptr));
        comboBox_primaryFormula->setItemText(0, QCoreApplication::translate("AddDoctorDialog", "SRKT", nullptr));
        comboBox_primaryFormula->setItemText(1, QCoreApplication::translate("AddDoctorDialog", "SRKII", nullptr));
        comboBox_primaryFormula->setItemText(2, QCoreApplication::translate("AddDoctorDialog", "HofferQ", nullptr));
        comboBox_primaryFormula->setItemText(3, QCoreApplication::translate("AddDoctorDialog", "Holladay", nullptr));
        comboBox_primaryFormula->setItemText(4, QCoreApplication::translate("AddDoctorDialog", "Haigis", nullptr));

        btn_cancel->setText(QCoreApplication::translate("AddDoctorDialog", "Cancel", nullptr));
        btn_save->setText(QCoreApplication::translate("AddDoctorDialog", "Save", nullptr));
        snackbar->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddDoctorDialog: public Ui_AddDoctorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDOCTORDIALOG_H
