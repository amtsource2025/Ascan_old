/********************************************************************************
** Form generated from reading UI file 'editdoctordialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDOCTORDIALOG_H
#define UI_EDITDOCTORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditDoctorDialog
{
public:
    QPushButton *btn_save;
    QLabel *snackbar;
    QLabel *label_7;
    QFrame *frame;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_8;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_docID;
    QLineEdit *lineEdit_docName;
    QComboBox *comboBox_lensPresetOne;
    QComboBox *comboBox_lensPresetTwo;
    QComboBox *comboBox_lensPresetThree;
    QComboBox *comboBox_primaryFormula;
    QPushButton *btn_cancel;
    QLabel *lbl_time;

    void setupUi(QDialog *EditDoctorDialog)
    {
        if (EditDoctorDialog->objectName().isEmpty())
            EditDoctorDialog->setObjectName(QString::fromUtf8("EditDoctorDialog"));
        EditDoctorDialog->resize(1280, 720);
        EditDoctorDialog->setStyleSheet(QString::fromUtf8("background-image: url(:/images/5.png);"));
        btn_save = new QPushButton(EditDoctorDialog);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));
        btn_save->setGeometry(QRect(840, 590, 202, 65));
        btn_save->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"color: rgb(255, 255, 255);\n"
"background-color: #1976D2;\n"
"border-radius:5px;"));
        btn_save->setFlat(true);
        snackbar = new QLabel(EditDoctorDialog);
        snackbar->setObjectName(QString::fromUtf8("snackbar"));
        snackbar->setGeometry(QRect(0, 670, 1281, 40));
        snackbar->setStyleSheet(QString::fromUtf8("border-image: url(:/images/alert-red.png);\n"
"background-image:url(empty.png);color:rgb(255,255,255);"));
        snackbar->setIndent(5);
        label_7 = new QLabel(EditDoctorDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(560, 0, 160, 70));
        QFont font;
        font.setPointSize(16);
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        frame = new QFrame(EditDoctorDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setEnabled(true);
        frame->setGeometry(QRect(10, 70, 1261, 511));
        frame->setStyleSheet(QString::fromUtf8("\n"
"/*background-image: url(:/images/card-big.png);*/\n"
"\n"
"background:rgb(255,255,255);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 20, 821, 471));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QFont font1;
        font1.setPointSize(14);
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));

        verticalLayout->addWidget(label_8);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));

        verticalLayout->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_docID = new QLineEdit(widget);
        lineEdit_docID->setObjectName(QString::fromUtf8("lineEdit_docID"));
        lineEdit_docID->setEnabled(false);
        lineEdit_docID->setFont(font1);
        lineEdit_docID->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        lineEdit_docID->setReadOnly(true);

        verticalLayout_2->addWidget(lineEdit_docID);

        lineEdit_docName = new QLineEdit(widget);
        lineEdit_docName->setObjectName(QString::fromUtf8("lineEdit_docName"));
        lineEdit_docName->setFont(font1);
        lineEdit_docName->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));

        verticalLayout_2->addWidget(lineEdit_docName);

        comboBox_lensPresetOne = new QComboBox(widget);
        comboBox_lensPresetOne->setObjectName(QString::fromUtf8("comboBox_lensPresetOne"));
        comboBox_lensPresetOne->setFont(font1);
        comboBox_lensPresetOne->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(comboBox_lensPresetOne);

        comboBox_lensPresetTwo = new QComboBox(widget);
        comboBox_lensPresetTwo->setObjectName(QString::fromUtf8("comboBox_lensPresetTwo"));
        comboBox_lensPresetTwo->setFont(font1);
        comboBox_lensPresetTwo->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(comboBox_lensPresetTwo);

        comboBox_lensPresetThree = new QComboBox(widget);
        comboBox_lensPresetThree->setObjectName(QString::fromUtf8("comboBox_lensPresetThree"));
        comboBox_lensPresetThree->setFont(font1);
        comboBox_lensPresetThree->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(comboBox_lensPresetThree);

        comboBox_primaryFormula = new QComboBox(widget);
        comboBox_primaryFormula->addItem(QString());
        comboBox_primaryFormula->addItem(QString());
        comboBox_primaryFormula->addItem(QString());
        comboBox_primaryFormula->addItem(QString());
        comboBox_primaryFormula->addItem(QString());
        comboBox_primaryFormula->setObjectName(QString::fromUtf8("comboBox_primaryFormula"));
        comboBox_primaryFormula->setFont(font1);
        comboBox_primaryFormula->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(comboBox_primaryFormula);


        horizontalLayout->addLayout(verticalLayout_2);

        btn_cancel = new QPushButton(EditDoctorDialog);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));
        btn_cancel->setGeometry(QRect(1070, 590, 202, 65));
        btn_cancel->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"color: #1976D2;\n"
"border: 1px solid #1976D2;border-radius:5px;"));
        btn_cancel->setFlat(true);
        lbl_time = new QLabel(EditDoctorDialog);
        lbl_time->setObjectName(QString::fromUtf8("lbl_time"));
        lbl_time->setGeometry(QRect(1150, 10, 120, 40));
        QFont font2;
        font2.setPointSize(9);
        lbl_time->setFont(font2);
        lbl_time->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        lbl_time->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        retranslateUi(EditDoctorDialog);

        QMetaObject::connectSlotsByName(EditDoctorDialog);
    } // setupUi

    void retranslateUi(QDialog *EditDoctorDialog)
    {
        EditDoctorDialog->setWindowTitle(QCoreApplication::translate("EditDoctorDialog", "Dialog", nullptr));
        btn_save->setText(QCoreApplication::translate("EditDoctorDialog", "Save", nullptr));
        snackbar->setText(QString());
        label_7->setText(QCoreApplication::translate("EditDoctorDialog", "Edit Doctor", nullptr));
        label_8->setText(QCoreApplication::translate("EditDoctorDialog", "Doctor ID", nullptr));
        label->setText(QCoreApplication::translate("EditDoctorDialog", "Doctor Name", nullptr));
        label_2->setText(QCoreApplication::translate("EditDoctorDialog", "Lens Preset One", nullptr));
        label_3->setText(QCoreApplication::translate("EditDoctorDialog", "Lens Preset Two", nullptr));
        label_4->setText(QCoreApplication::translate("EditDoctorDialog", "Lens Preset Three", nullptr));
        label_5->setText(QCoreApplication::translate("EditDoctorDialog", "Primary Formula", nullptr));
        comboBox_primaryFormula->setItemText(0, QCoreApplication::translate("EditDoctorDialog", "SRKT", nullptr));
        comboBox_primaryFormula->setItemText(1, QCoreApplication::translate("EditDoctorDialog", "SRKII", nullptr));
        comboBox_primaryFormula->setItemText(2, QCoreApplication::translate("EditDoctorDialog", "HofferQ", nullptr));
        comboBox_primaryFormula->setItemText(3, QCoreApplication::translate("EditDoctorDialog", "Holladay", nullptr));
        comboBox_primaryFormula->setItemText(4, QCoreApplication::translate("EditDoctorDialog", "Haigis", nullptr));

        btn_cancel->setText(QCoreApplication::translate("EditDoctorDialog", "Cancel", nullptr));
        lbl_time->setText(QCoreApplication::translate("EditDoctorDialog", "10:09", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditDoctorDialog: public Ui_EditDoctorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDOCTORDIALOG_H
