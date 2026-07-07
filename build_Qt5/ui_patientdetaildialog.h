/********************************************************************************
** Form generated from reading UI file 'patientdetaildialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTDETAILDIALOG_H
#define UI_PATIENTDETAILDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientDetailDialog
{
public:
    QPushButton *btn_close;
    QLabel *label;
    QFrame *frame;
    QLineEdit *lineEdit_patName;
    QLabel *label_2;
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
    QLabel *label_7;
    QLineEdit *lineEdit_patID;
    QCheckBox *checkBox_dense;
    QFrame *frame_2;
    QLabel *label_9;
    QLabel *label_13;
    QLabel *label_14;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_rk1;
    QLineEdit *lineEdit_rk2;
    QLineEdit *lineEdit_rk;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_lk1;
    QLineEdit *lineEdit_lk2;
    QLineEdit *lineEdit_lk;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_16;
    QLabel *label_15;
    QLabel *label_17;
    QLabel *lbl_time;

    void setupUi(QDialog *PatientDetailDialog)
    {
        if (PatientDetailDialog->objectName().isEmpty())
            PatientDetailDialog->setObjectName(QString::fromUtf8("PatientDetailDialog"));
        PatientDetailDialog->resize(1280, 720);
        PatientDetailDialog->setStyleSheet(QString::fromUtf8("background-image: url(:/images/5.png);"));
        btn_close = new QPushButton(PatientDetailDialog);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));
        btn_close->setGeometry(QRect(0, 0, 91, 81));
        btn_close->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/icons/ic_arrow_back_white_48dp.png);"));
        btn_close->setFlat(true);
        label = new QLabel(PatientDetailDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(580, 0, 160, 70));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        label->setAlignment(Qt::AlignCenter);
        frame = new QFrame(PatientDetailDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(9, 80, 701, 621));
        frame->setStyleSheet(QString::fromUtf8("\n"
"/*background-image: url(:/images/card-big.png);*/\n"
"\n"
"background:rgb(255,255,255);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        lineEdit_patName = new QLineEdit(frame);
        lineEdit_patName->setObjectName(QString::fromUtf8("lineEdit_patName"));
        lineEdit_patName->setGeometry(QRect(180, 80, 310, 20));
        QFont font1;
        font1.setPointSize(13);
        lineEdit_patName->setFont(font1);
        lineEdit_patName->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 80, 131, 21));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 183, 120, 17));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 235, 130, 17));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 400, 121, 21));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 280, 150, 17));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        lineEdit_phone = new QLineEdit(frame);
        lineEdit_phone->setObjectName(QString::fromUtf8("lineEdit_phone"));
        lineEdit_phone->setGeometry(QRect(180, 230, 310, 20));
        lineEdit_phone->setFont(font1);
        lineEdit_phone->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 340, 150, 21));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        lineEdit_age = new QLineEdit(frame);
        lineEdit_age->setObjectName(QString::fromUtf8("lineEdit_age"));
        lineEdit_age->setGeometry(QRect(180, 121, 60, 40));
        lineEdit_age->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        label_18 = new QLabel(frame);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(20, 130, 130, 21));
        label_18->setFont(font1);
        label_18->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        checkBox_male = new QCheckBox(frame);
        checkBox_male->setObjectName(QString::fromUtf8("checkBox_male"));
        checkBox_male->setGeometry(QRect(190, 180, 112, 23));
        checkBox_male->setFont(font1);
        checkBox_male->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        checkBox_male->setChecked(true);
        checkBox_female = new QCheckBox(frame);
        checkBox_female->setObjectName(QString::fromUtf8("checkBox_female"));
        checkBox_female->setGeometry(QRect(310, 180, 112, 23));
        checkBox_female->setFont(font1);
        checkBox_female->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        checkBox_aphakic = new QCheckBox(frame);
        checkBox_aphakic->setObjectName(QString::fromUtf8("checkBox_aphakic"));
        checkBox_aphakic->setGeometry(QRect(190, 274, 112, 23));
        checkBox_aphakic->setFont(font1);
        checkBox_aphakic->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        checkBox_aphakic->setChecked(true);
        checkBox_phakic = new QCheckBox(frame);
        checkBox_phakic->setObjectName(QString::fromUtf8("checkBox_phakic"));
        checkBox_phakic->setGeometry(QRect(310, 274, 112, 23));
        checkBox_phakic->setFont(font1);
        checkBox_phakic->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        checkBox_immersion = new QCheckBox(frame);
        checkBox_immersion->setObjectName(QString::fromUtf8("checkBox_immersion"));
        checkBox_immersion->setGeometry(QRect(310, 340, 112, 23));
        checkBox_immersion->setFont(font1);
        checkBox_immersion->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        checkBox_contact = new QCheckBox(frame);
        checkBox_contact->setObjectName(QString::fromUtf8("checkBox_contact"));
        checkBox_contact->setGeometry(QRect(190, 340, 112, 23));
        checkBox_contact->setFont(font1);
        checkBox_contact->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        checkBox_contact->setChecked(true);
        checkBox_right = new QCheckBox(frame);
        checkBox_right->setObjectName(QString::fromUtf8("checkBox_right"));
        checkBox_right->setGeometry(QRect(310, 400, 112, 23));
        checkBox_right->setFont(font1);
        checkBox_right->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        checkBox_left = new QCheckBox(frame);
        checkBox_left->setObjectName(QString::fromUtf8("checkBox_left"));
        checkBox_left->setGeometry(QRect(190, 400, 112, 23));
        checkBox_left->setFont(font1);
        checkBox_left->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        checkBox_left->setChecked(true);
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 30, 100, 17));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        lineEdit_patID = new QLineEdit(frame);
        lineEdit_patID->setObjectName(QString::fromUtf8("lineEdit_patID"));
        lineEdit_patID->setGeometry(QRect(180, 30, 310, 20));
        lineEdit_patID->setFont(font1);
        lineEdit_patID->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        checkBox_dense = new QCheckBox(frame);
        checkBox_dense->setObjectName(QString::fromUtf8("checkBox_dense"));
        checkBox_dense->setGeometry(QRect(410, 274, 92, 23));
        checkBox_dense->setFont(font1);
        frame_2 = new QFrame(PatientDetailDialog);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(719, 80, 541, 621));
        frame_2->setStyleSheet(QString::fromUtf8("\n"
"/*background-image: url(:/images/card-big.png);*/\n"
"\n"
"background:rgb(255,255,255);\n"
""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 40, 171, 41));
        QFont font2;
        font2.setPointSize(14);
        label_9->setFont(font2);
        label_9->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        label_13 = new QLabel(frame_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 260, 40, 20));
        label_13->setFont(font1);
        label_13->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        label_14 = new QLabel(frame_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 110, 40, 21));
        label_14->setFont(font1);
        label_14->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        widget = new QWidget(frame_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 340, 485, 23));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_rk1 = new QLineEdit(widget);
        lineEdit_rk1->setObjectName(QString::fromUtf8("lineEdit_rk1"));
        lineEdit_rk1->setFont(font1);
        lineEdit_rk1->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));

        horizontalLayout->addWidget(lineEdit_rk1);

        lineEdit_rk2 = new QLineEdit(widget);
        lineEdit_rk2->setObjectName(QString::fromUtf8("lineEdit_rk2"));
        lineEdit_rk2->setFont(font1);
        lineEdit_rk2->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));

        horizontalLayout->addWidget(lineEdit_rk2);

        lineEdit_rk = new QLineEdit(widget);
        lineEdit_rk->setObjectName(QString::fromUtf8("lineEdit_rk"));
        lineEdit_rk->setFont(font1);
        lineEdit_rk->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));

        horizontalLayout->addWidget(lineEdit_rk);

        widget1 = new QWidget(frame_2);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 300, 491, 22));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(widget1);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));

        horizontalLayout_2->addWidget(label_10);

        label_11 = new QLabel(widget1);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));

        horizontalLayout_2->addWidget(label_11);

        label_12 = new QLabel(widget1);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font1);
        label_12->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));

        horizontalLayout_2->addWidget(label_12);

        widget2 = new QWidget(frame_2);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(10, 200, 485, 23));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEdit_lk1 = new QLineEdit(widget2);
        lineEdit_lk1->setObjectName(QString::fromUtf8("lineEdit_lk1"));
        lineEdit_lk1->setFont(font1);
        lineEdit_lk1->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));

        horizontalLayout_3->addWidget(lineEdit_lk1);

        lineEdit_lk2 = new QLineEdit(widget2);
        lineEdit_lk2->setObjectName(QString::fromUtf8("lineEdit_lk2"));
        lineEdit_lk2->setFont(font1);
        lineEdit_lk2->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));

        horizontalLayout_3->addWidget(lineEdit_lk2);

        lineEdit_lk = new QLineEdit(widget2);
        lineEdit_lk->setObjectName(QString::fromUtf8("lineEdit_lk"));
        lineEdit_lk->setFont(font1);
        lineEdit_lk->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));

        horizontalLayout_3->addWidget(lineEdit_lk);

        widget3 = new QWidget(frame_2);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(10, 150, 501, 22));
        horizontalLayout_4 = new QHBoxLayout(widget3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(widget3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font1);
        label_16->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));

        horizontalLayout_4->addWidget(label_16);

        label_15 = new QLabel(widget3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font1);
        label_15->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));

        horizontalLayout_4->addWidget(label_15);

        label_17 = new QLabel(widget3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font1);
        label_17->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));

        horizontalLayout_4->addWidget(label_17);

        lbl_time = new QLabel(PatientDetailDialog);
        lbl_time->setObjectName(QString::fromUtf8("lbl_time"));
        lbl_time->setGeometry(QRect(1130, 10, 141, 51));
        QFont font3;
        font3.setPointSize(9);
        lbl_time->setFont(font3);
        lbl_time->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);border-image:url(:/images/empty.png);"));
        lbl_time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(PatientDetailDialog);

        QMetaObject::connectSlotsByName(PatientDetailDialog);
    } // setupUi

    void retranslateUi(QDialog *PatientDetailDialog)
    {
        PatientDetailDialog->setWindowTitle(QCoreApplication::translate("PatientDetailDialog", "Dialog", nullptr));
        btn_close->setText(QString());
        label->setText(QCoreApplication::translate("PatientDetailDialog", "Patient Details", nullptr));
        label_2->setText(QCoreApplication::translate("PatientDetailDialog", "Patient Name", nullptr));
        label_3->setText(QCoreApplication::translate("PatientDetailDialog", "Gender", nullptr));
        label_4->setText(QCoreApplication::translate("PatientDetailDialog", "Phone", nullptr));
        label_5->setText(QCoreApplication::translate("PatientDetailDialog", "Operating Eye", nullptr));
        label_6->setText(QCoreApplication::translate("PatientDetailDialog", "Operating Method", nullptr));
        label_8->setText(QCoreApplication::translate("PatientDetailDialog", "Operating Mode", nullptr));
        label_18->setText(QCoreApplication::translate("PatientDetailDialog", "Age", nullptr));
        checkBox_male->setText(QCoreApplication::translate("PatientDetailDialog", "Male", nullptr));
        checkBox_female->setText(QCoreApplication::translate("PatientDetailDialog", "Female", nullptr));
        checkBox_aphakic->setText(QCoreApplication::translate("PatientDetailDialog", "Aphakic", nullptr));
        checkBox_phakic->setText(QCoreApplication::translate("PatientDetailDialog", "Phakic", nullptr));
        checkBox_immersion->setText(QCoreApplication::translate("PatientDetailDialog", "Immersion", nullptr));
        checkBox_contact->setText(QCoreApplication::translate("PatientDetailDialog", "Contact", nullptr));
        checkBox_right->setText(QCoreApplication::translate("PatientDetailDialog", "Right", nullptr));
        checkBox_left->setText(QCoreApplication::translate("PatientDetailDialog", "Left", nullptr));
        label_7->setText(QCoreApplication::translate("PatientDetailDialog", "Patient ID", nullptr));
        checkBox_dense->setText(QCoreApplication::translate("PatientDetailDialog", "Dense", nullptr));
        label_9->setText(QCoreApplication::translate("PatientDetailDialog", "Keratometer", nullptr));
        label_13->setText(QCoreApplication::translate("PatientDetailDialog", "Right", nullptr));
        label_14->setText(QCoreApplication::translate("PatientDetailDialog", "Left", nullptr));
        lineEdit_rk1->setText(QCoreApplication::translate("PatientDetailDialog", "45.00", nullptr));
        lineEdit_rk2->setText(QCoreApplication::translate("PatientDetailDialog", "45.00", nullptr));
        lineEdit_rk->setText(QCoreApplication::translate("PatientDetailDialog", "45.00", nullptr));
        label_10->setText(QCoreApplication::translate("PatientDetailDialog", "RK1", nullptr));
        label_11->setText(QCoreApplication::translate("PatientDetailDialog", "RK2", nullptr));
        label_12->setText(QCoreApplication::translate("PatientDetailDialog", "RK", nullptr));
        lineEdit_lk1->setText(QCoreApplication::translate("PatientDetailDialog", "45.00", nullptr));
        lineEdit_lk2->setText(QCoreApplication::translate("PatientDetailDialog", "45.00", nullptr));
        lineEdit_lk->setText(QCoreApplication::translate("PatientDetailDialog", "45.00", nullptr));
        label_16->setText(QCoreApplication::translate("PatientDetailDialog", "LK1", nullptr));
        label_15->setText(QCoreApplication::translate("PatientDetailDialog", "LK2", nullptr));
        label_17->setText(QCoreApplication::translate("PatientDetailDialog", "LK", nullptr));
        lbl_time->setText(QCoreApplication::translate("PatientDetailDialog", "10:09", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientDetailDialog: public Ui_PatientDetailDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTDETAILDIALOG_H
