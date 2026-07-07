/********************************************************************************
** Form generated from reading UI file 'addpatientdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPATIENTDIALOG_H
#define UI_ADDPATIENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddPatientDialog
{
public:
    QFrame *frame;
    QLineEdit *lineEdit_patName;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_phone;
    QLabel *label_8;
    QLineEdit *lineEdit_age;
    QLabel *label_18;
    QCheckBox *checkBox_male;
    QCheckBox *checkBox_female;
    QCheckBox *checkBox_aphakic;
    QCheckBox *checkBox_phakic;
    QCheckBox *checkBox_immersion;
    QCheckBox *checkBox_contact;
    QCheckBox *checkBox_right;
    QCheckBox *checkBox_left;
    QCheckBox *checkBox_dense;
    QLabel *lblPatID;
    QLineEdit *lineEdit_CustPatId;
    QLineEdit *lineEdit_patid;
    QPushButton *btn_save;
    QLabel *snackbar;
    QPushButton *btn_cancel;
    QLabel *label_7;
    QFrame *frame_2;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *lineEdit_rk1;
    QLineEdit *lineEdit_rk2;
    QLineEdit *lineEdit_rk;
    QLabel *label_14;
    QLineEdit *lineEdit_lk;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *lineEdit_lk1;
    QLineEdit *lineEdit_lk2;
    QLabel *lbl_time;

    void setupUi(QDialog *AddPatientDialog)
    {
        if (AddPatientDialog->objectName().isEmpty())
            AddPatientDialog->setObjectName(QString::fromUtf8("AddPatientDialog"));
        AddPatientDialog->resize(1280, 720);
        AddPatientDialog->setStyleSheet(QString::fromUtf8("background-image: url(:/images/5.png);"));
        frame = new QFrame(AddPatientDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 40, 951, 541));
        frame->setStyleSheet(QString::fromUtf8("\n"
"background-image: url(:/images/card-big.png);\n"
"background:rgb(255,255,255);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit_patName = new QLineEdit(frame);
        lineEdit_patName->setObjectName(QString::fromUtf8("lineEdit_patName"));
        lineEdit_patName->setGeometry(QRect(180, 73, 310, 30));
        lineEdit_patName->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 80, 130, 17));
        label->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 183, 120, 17));
        label_3->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 235, 130, 17));
        label_4->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 363, 130, 17));
        label_5->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 276, 160, 17));
        label_6->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        lineEdit_phone = new QLineEdit(frame);
        lineEdit_phone->setObjectName(QString::fromUtf8("lineEdit_phone"));
        lineEdit_phone->setGeometry(QRect(180, 225, 310, 30));
        lineEdit_phone->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 320, 150, 17));
        label_8->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        lineEdit_age = new QLineEdit(frame);
        lineEdit_age->setObjectName(QString::fromUtf8("lineEdit_age"));
        lineEdit_age->setGeometry(QRect(180, 121, 60, 40));
        lineEdit_age->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        label_18 = new QLabel(frame);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(20, 130, 130, 17));
        label_18->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        checkBox_male = new QCheckBox(frame);
        checkBox_male->setObjectName(QString::fromUtf8("checkBox_male"));
        checkBox_male->setGeometry(QRect(190, 180, 112, 23));
        checkBox_male->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        checkBox_male->setChecked(true);
        checkBox_female = new QCheckBox(frame);
        checkBox_female->setObjectName(QString::fromUtf8("checkBox_female"));
        checkBox_female->setGeometry(QRect(310, 180, 112, 23));
        checkBox_female->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        checkBox_aphakic = new QCheckBox(frame);
        checkBox_aphakic->setObjectName(QString::fromUtf8("checkBox_aphakic"));
        checkBox_aphakic->setGeometry(QRect(190, 274, 112, 23));
        checkBox_aphakic->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        checkBox_aphakic->setChecked(false);
        checkBox_phakic = new QCheckBox(frame);
        checkBox_phakic->setObjectName(QString::fromUtf8("checkBox_phakic"));
        checkBox_phakic->setGeometry(QRect(310, 274, 101, 23));
        checkBox_phakic->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        checkBox_phakic->setChecked(true);
        checkBox_immersion = new QCheckBox(frame);
        checkBox_immersion->setObjectName(QString::fromUtf8("checkBox_immersion"));
        checkBox_immersion->setGeometry(QRect(310, 320, 112, 23));
        checkBox_immersion->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        checkBox_contact = new QCheckBox(frame);
        checkBox_contact->setObjectName(QString::fromUtf8("checkBox_contact"));
        checkBox_contact->setGeometry(QRect(190, 320, 112, 23));
        checkBox_contact->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        checkBox_contact->setChecked(true);
        checkBox_right = new QCheckBox(frame);
        checkBox_right->setObjectName(QString::fromUtf8("checkBox_right"));
        checkBox_right->setGeometry(QRect(310, 360, 112, 23));
        checkBox_right->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        checkBox_left = new QCheckBox(frame);
        checkBox_left->setObjectName(QString::fromUtf8("checkBox_left"));
        checkBox_left->setGeometry(QRect(190, 360, 112, 23));
        checkBox_left->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        checkBox_left->setChecked(true);
        checkBox_dense = new QCheckBox(frame);
        checkBox_dense->setObjectName(QString::fromUtf8("checkBox_dense"));
        checkBox_dense->setGeometry(QRect(400, 274, 92, 23));
        lblPatID = new QLabel(frame);
        lblPatID->setObjectName(QString::fromUtf8("lblPatID"));
        lblPatID->setGeometry(QRect(20, 30, 100, 17));
        lineEdit_CustPatId = new QLineEdit(frame);
        lineEdit_CustPatId->setObjectName(QString::fromUtf8("lineEdit_CustPatId"));
        lineEdit_CustPatId->setGeometry(QRect(180, 30, 311, 30));
        lineEdit_CustPatId->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        lineEdit_patid = new QLineEdit(frame);
        lineEdit_patid->setObjectName(QString::fromUtf8("lineEdit_patid"));
        lineEdit_patid->setGeometry(QRect(180, 30, 311, 31));
        lineEdit_patid->raise();
        lineEdit_patName->raise();
        label->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        lineEdit_phone->raise();
        label_8->raise();
        lineEdit_age->raise();
        label_18->raise();
        checkBox_male->raise();
        checkBox_female->raise();
        checkBox_aphakic->raise();
        checkBox_phakic->raise();
        checkBox_immersion->raise();
        checkBox_contact->raise();
        checkBox_right->raise();
        checkBox_left->raise();
        checkBox_dense->raise();
        lblPatID->raise();
        lineEdit_CustPatId->raise();
        btn_save = new QPushButton(AddPatientDialog);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));
        btn_save->setGeometry(QRect(850, 590, 202, 65));
        btn_save->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(25, 118, 210);\n"
"border-radius:5px;"));
        btn_save->setFlat(true);
        snackbar = new QLabel(AddPatientDialog);
        snackbar->setObjectName(QString::fromUtf8("snackbar"));
        snackbar->setGeometry(QRect(0, 670, 1281, 40));
        snackbar->setStyleSheet(QString::fromUtf8("border-image: url(:/images/alert-red.png);\n"
"background-image:url(empty.png);color:rgb(255,255,255);"));
        snackbar->setIndent(5);
        btn_cancel = new QPushButton(AddPatientDialog);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));
        btn_cancel->setGeometry(QRect(1070, 590, 202, 65));
        btn_cancel->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"color: #1976D2;\n"
"border: 1px solid #1976D2;border-radius:5px;"));
        btn_cancel->setFlat(true);
        label_7 = new QLabel(AddPatientDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(590, -10, 160, 70));
        QFont font;
        font.setPointSize(16);
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        frame_2 = new QFrame(AddPatientDialog);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(970, 40, 301, 541));
        frame_2->setStyleSheet(QString::fromUtf8("\n"
"background-image: url(:/images/card-big.png);\n"
"background:rgb(255,255,255);"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 10, 130, 17));
        label_9->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 160, 40, 20));
        label_10->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label_11 = new QLabel(frame_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(90, 160, 40, 20));
        label_11->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label_12 = new QLabel(frame_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(180, 160, 40, 20));
        label_12->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label_13 = new QLabel(frame_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 140, 40, 20));
        label_13->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        lineEdit_rk1 = new QLineEdit(frame_2);
        lineEdit_rk1->setObjectName(QString::fromUtf8("lineEdit_rk1"));
        lineEdit_rk1->setGeometry(QRect(9, 182, 60, 40));
        lineEdit_rk1->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        lineEdit_rk2 = new QLineEdit(frame_2);
        lineEdit_rk2->setObjectName(QString::fromUtf8("lineEdit_rk2"));
        lineEdit_rk2->setGeometry(QRect(91, 182, 60, 40));
        lineEdit_rk2->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        lineEdit_rk = new QLineEdit(frame_2);
        lineEdit_rk->setObjectName(QString::fromUtf8("lineEdit_rk"));
        lineEdit_rk->setGeometry(QRect(180, 182, 60, 40));
        lineEdit_rk->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        label_14 = new QLabel(frame_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(9, 47, 40, 21));
        label_14->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        lineEdit_lk = new QLineEdit(frame_2);
        lineEdit_lk->setObjectName(QString::fromUtf8("lineEdit_lk"));
        lineEdit_lk->setGeometry(QRect(179, 90, 60, 40));
        lineEdit_lk->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        label_15 = new QLabel(frame_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(89, 68, 40, 20));
        label_15->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label_16 = new QLabel(frame_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(9, 68, 40, 20));
        label_16->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label_17 = new QLabel(frame_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(179, 68, 40, 20));
        label_17->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        lineEdit_lk1 = new QLineEdit(frame_2);
        lineEdit_lk1->setObjectName(QString::fromUtf8("lineEdit_lk1"));
        lineEdit_lk1->setGeometry(QRect(8, 90, 60, 40));
        lineEdit_lk1->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        lineEdit_lk2 = new QLineEdit(frame_2);
        lineEdit_lk2->setObjectName(QString::fromUtf8("lineEdit_lk2"));
        lineEdit_lk2->setGeometry(QRect(90, 90, 60, 40));
        lineEdit_lk2->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        lbl_time = new QLabel(AddPatientDialog);
        lbl_time->setObjectName(QString::fromUtf8("lbl_time"));
        lbl_time->setGeometry(QRect(1150, 10, 120, 40));
        QFont font1;
        font1.setPointSize(9);
        lbl_time->setFont(font1);
        lbl_time->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        lbl_time->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        retranslateUi(AddPatientDialog);

        QMetaObject::connectSlotsByName(AddPatientDialog);
    } // setupUi

    void retranslateUi(QDialog *AddPatientDialog)
    {
        AddPatientDialog->setWindowTitle(QCoreApplication::translate("AddPatientDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddPatientDialog", "Patient Name", nullptr));
        label_3->setText(QCoreApplication::translate("AddPatientDialog", "Gender", nullptr));
        label_4->setText(QCoreApplication::translate("AddPatientDialog", "Phone", nullptr));
        label_5->setText(QCoreApplication::translate("AddPatientDialog", "Operating Eye", nullptr));
        label_6->setText(QCoreApplication::translate("AddPatientDialog", "Operating Method", nullptr));
        label_8->setText(QCoreApplication::translate("AddPatientDialog", "Operating Mode", nullptr));
        label_18->setText(QCoreApplication::translate("AddPatientDialog", "Age", nullptr));
        checkBox_male->setText(QCoreApplication::translate("AddPatientDialog", "Male", nullptr));
        checkBox_female->setText(QCoreApplication::translate("AddPatientDialog", "Female", nullptr));
        checkBox_aphakic->setText(QCoreApplication::translate("AddPatientDialog", "Aphakic", nullptr));
        checkBox_phakic->setText(QCoreApplication::translate("AddPatientDialog", "Phakic", nullptr));
        checkBox_immersion->setText(QCoreApplication::translate("AddPatientDialog", "Immersion", nullptr));
        checkBox_contact->setText(QCoreApplication::translate("AddPatientDialog", "Contact", nullptr));
        checkBox_right->setText(QCoreApplication::translate("AddPatientDialog", "Right", nullptr));
        checkBox_left->setText(QCoreApplication::translate("AddPatientDialog", "Left", nullptr));
        checkBox_dense->setText(QCoreApplication::translate("AddPatientDialog", "Dense", nullptr));
        lblPatID->setText(QCoreApplication::translate("AddPatientDialog", "Cus_Patient ID", nullptr));
        btn_save->setText(QCoreApplication::translate("AddPatientDialog", "Save", nullptr));
        snackbar->setText(QString());
        btn_cancel->setText(QCoreApplication::translate("AddPatientDialog", "Cancel", nullptr));
        label_7->setText(QCoreApplication::translate("AddPatientDialog", "Add Patient", nullptr));
        label_9->setText(QCoreApplication::translate("AddPatientDialog", "Keratometer", nullptr));
        label_10->setText(QCoreApplication::translate("AddPatientDialog", "RK1", nullptr));
        label_11->setText(QCoreApplication::translate("AddPatientDialog", "RK2", nullptr));
        label_12->setText(QCoreApplication::translate("AddPatientDialog", "RK", nullptr));
        label_13->setText(QCoreApplication::translate("AddPatientDialog", "Right", nullptr));
        lineEdit_rk1->setText(QCoreApplication::translate("AddPatientDialog", "45.00", nullptr));
        lineEdit_rk2->setText(QCoreApplication::translate("AddPatientDialog", "45.00", nullptr));
        lineEdit_rk->setText(QCoreApplication::translate("AddPatientDialog", "45.00", nullptr));
        label_14->setText(QCoreApplication::translate("AddPatientDialog", "Left", nullptr));
        lineEdit_lk->setText(QCoreApplication::translate("AddPatientDialog", "45.00", nullptr));
        label_15->setText(QCoreApplication::translate("AddPatientDialog", "LK2", nullptr));
        label_16->setText(QCoreApplication::translate("AddPatientDialog", "LK1", nullptr));
        label_17->setText(QCoreApplication::translate("AddPatientDialog", "LK", nullptr));
        lineEdit_lk1->setText(QCoreApplication::translate("AddPatientDialog", "45.00", nullptr));
        lineEdit_lk2->setText(QCoreApplication::translate("AddPatientDialog", "45.00", nullptr));
        lbl_time->setText(QCoreApplication::translate("AddPatientDialog", "10:09", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPatientDialog: public Ui_AddPatientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPATIENTDIALOG_H
