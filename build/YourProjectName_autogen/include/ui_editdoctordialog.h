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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EditDoctorDialog
{
public:
    QPushButton *btn_save;
    QLabel *snackbar;
    QLabel *label_7;
    QFrame *frame;
    QLineEdit *lineEdit_docName;
    QComboBox *comboBox_lensPresetOne;
    QComboBox *comboBox_lensPresetTwo;
    QComboBox *comboBox_lensPresetThree;
    QComboBox *comboBox_primaryFormula;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_docID;
    QLabel *label_8;
    QPushButton *btn_cancel;
    QLabel *lbl_time;

    void setupUi(QDialog *EditDoctorDialog)
    {
        if (EditDoctorDialog->objectName().isEmpty())
            EditDoctorDialog->setObjectName(QString::fromUtf8("EditDoctorDialog"));
        EditDoctorDialog->resize(800, 600);
        EditDoctorDialog->setStyleSheet(QString::fromUtf8("background-image: url(:/images/5.png);"));
        btn_save = new QPushButton(EditDoctorDialog);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));
        btn_save->setGeometry(QRect(370, 499, 202, 65));
        btn_save->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"color: rgb(255, 255, 255);\n"
"background-color: #1976D2;\n"
"border-radius:5px;"));
        btn_save->setFlat(true);
        snackbar = new QLabel(EditDoctorDialog);
        snackbar->setObjectName(QString::fromUtf8("snackbar"));
        snackbar->setGeometry(QRect(-1, 570, 810, 40));
        snackbar->setStyleSheet(QString::fromUtf8("border-image: url(:/images/alert-red.png);\n"
"background-image:url(empty.png);color:rgb(255,255,255);"));
        snackbar->setIndent(5);
        label_7 = new QLabel(EditDoctorDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(340, 0, 160, 70));
        QFont font;
        font.setPointSize(16);
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label_7->setAlignment(Qt::AlignCenter);
        frame = new QFrame(EditDoctorDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setEnabled(true);
        frame->setGeometry(QRect(10, 70, 780, 420));
        frame->setStyleSheet(QString::fromUtf8("\n"
"background-image: url(:/images/card-big.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        lineEdit_docName = new QLineEdit(frame);
        lineEdit_docName->setObjectName(QString::fromUtf8("lineEdit_docName"));
        lineEdit_docName->setGeometry(QRect(210, 66, 390, 30));
        lineEdit_docName->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        comboBox_lensPresetOne = new QComboBox(frame);
        comboBox_lensPresetOne->setObjectName(QString::fromUtf8("comboBox_lensPresetOne"));
        comboBox_lensPresetOne->setGeometry(QRect(210, 120, 260, 27));
        comboBox_lensPresetOne->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        comboBox_lensPresetTwo = new QComboBox(frame);
        comboBox_lensPresetTwo->setObjectName(QString::fromUtf8("comboBox_lensPresetTwo"));
        comboBox_lensPresetTwo->setGeometry(QRect(210, 170, 260, 27));
        comboBox_lensPresetTwo->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        comboBox_lensPresetThree = new QComboBox(frame);
        comboBox_lensPresetThree->setObjectName(QString::fromUtf8("comboBox_lensPresetThree"));
        comboBox_lensPresetThree->setGeometry(QRect(210, 220, 260, 27));
        comboBox_lensPresetThree->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        comboBox_primaryFormula = new QComboBox(frame);
        comboBox_primaryFormula->addItem(QString());
        comboBox_primaryFormula->addItem(QString());
        comboBox_primaryFormula->addItem(QString());
        comboBox_primaryFormula->addItem(QString());
        comboBox_primaryFormula->addItem(QString());
        comboBox_primaryFormula->setObjectName(QString::fromUtf8("comboBox_primaryFormula"));
        comboBox_primaryFormula->setGeometry(QRect(210, 266, 260, 27));
        comboBox_primaryFormula->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 70, 160, 17));
        label->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 120, 160, 17));
        label_2->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 173, 170, 17));
        label_3->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 225, 180, 17));
        label_4->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 271, 180, 17));
        label_5->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        lineEdit_docID = new QLineEdit(frame);
        lineEdit_docID->setObjectName(QString::fromUtf8("lineEdit_docID"));
        lineEdit_docID->setEnabled(false);
        lineEdit_docID->setGeometry(QRect(210, 16, 390, 30));
        lineEdit_docID->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
""));
        lineEdit_docID->setReadOnly(true);
        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 20, 170, 17));
        label_8->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        btn_cancel = new QPushButton(EditDoctorDialog);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));
        btn_cancel->setGeometry(QRect(580, 499, 202, 65));
        btn_cancel->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"color: #1976D2;\n"
"border: 1px solid #1976D2;border-radius:5px;"));
        btn_cancel->setFlat(true);
        lbl_time = new QLabel(EditDoctorDialog);
        lbl_time->setObjectName(QString::fromUtf8("lbl_time"));
        lbl_time->setGeometry(QRect(680, 0, 120, 40));
        QFont font1;
        font1.setPointSize(9);
        lbl_time->setFont(font1);
        lbl_time->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        lbl_time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(EditDoctorDialog);

        QMetaObject::connectSlotsByName(EditDoctorDialog);
    } // setupUi

    void retranslateUi(QDialog *EditDoctorDialog)
    {
        EditDoctorDialog->setWindowTitle(QCoreApplication::translate("EditDoctorDialog", "Dialog", nullptr));
        btn_save->setText(QCoreApplication::translate("EditDoctorDialog", "Save", nullptr));
        snackbar->setText(QString());
        label_7->setText(QCoreApplication::translate("EditDoctorDialog", "Edit Doctor", nullptr));
        comboBox_primaryFormula->setItemText(0, QCoreApplication::translate("EditDoctorDialog", "SRKT", nullptr));
        comboBox_primaryFormula->setItemText(1, QCoreApplication::translate("EditDoctorDialog", "SRKII", nullptr));
        comboBox_primaryFormula->setItemText(2, QCoreApplication::translate("EditDoctorDialog", "HofferQ", nullptr));
        comboBox_primaryFormula->setItemText(3, QCoreApplication::translate("EditDoctorDialog", "Holladay", nullptr));
        comboBox_primaryFormula->setItemText(4, QCoreApplication::translate("EditDoctorDialog", "Haigis", nullptr));

        label->setText(QCoreApplication::translate("EditDoctorDialog", "Doctor Name", nullptr));
        label_2->setText(QCoreApplication::translate("EditDoctorDialog", "Lens Preset One", nullptr));
        label_3->setText(QCoreApplication::translate("EditDoctorDialog", "Lens Preset Two", nullptr));
        label_4->setText(QCoreApplication::translate("EditDoctorDialog", "Lens Preset Three", nullptr));
        label_5->setText(QCoreApplication::translate("EditDoctorDialog", "Primary Formula", nullptr));
        label_8->setText(QCoreApplication::translate("EditDoctorDialog", "Doctor ID", nullptr));
        btn_cancel->setText(QCoreApplication::translate("EditDoctorDialog", "Cancel", nullptr));
        lbl_time->setText(QCoreApplication::translate("EditDoctorDialog", "10:09", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditDoctorDialog: public Ui_EditDoctorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDOCTORDIALOG_H
