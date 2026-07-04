/********************************************************************************
** Form generated from reading UI file 'doctordetaildialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTORDETAILDIALOG_H
#define UI_DOCTORDETAILDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DoctorDetailDialog
{
public:
    QLabel *label;
    QPushButton *btn_close;
    QFrame *frame;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTabWidget *tabWidget_currentDoctor;
    QWidget *tab;
    QLabel *lbl_iolLensOne;
    QLabel *lbl_asrktLensOne;
    QLabel *lbl_asrktiiLensOne;
    QLabel *lbl_acdLensOne;
    QLabel *lbl_sfLensOne;
    QLabel *lbl_a0LensOne;
    QLabel *lbl_a1LensOne;
    QLabel *lbl_a2LensOne;
    QLineEdit *lbl_asrktLensOneValue;
    QLineEdit *lbl_asrkiiLensOneValue;
    QLineEdit *lbl_acdLensOneValue;
    QLineEdit *lbl_sfLensOneValue;
    QLineEdit *lbl_a0LensOneValue;
    QLineEdit *lbl_a1LensOneValue;
    QLineEdit *lbl_a2LensOneValue;
    QWidget *tab_2;
    QLabel *lbl_sfLensTwo;
    QLineEdit *lbl_sfLensTwoValue;
    QLineEdit *lbl_asrktLensTwoValue;
    QLineEdit *lbl_a2LensTwoValue;
    QLineEdit *lbl_asrkiiLensTwoValue;
    QLabel *lbl_acdLensTwo;
    QLabel *lbl_asrkiiLensTwo;
    QLabel *lbl_a1LensTwo;
    QLineEdit *lbl_a0LensTwoValue;
    QLabel *lbl_a2LensTwo;
    QLineEdit *lbl_a1LensTwoValue;
    QLabel *lbl_iolLensTwo;
    QLabel *lbl_asrktLensTwo;
    QLineEdit *lbl_acdLensTwoValue;
    QLabel *lbl_a0LensTwo;
    QWidget *tab_3;
    QLabel *lbl_sfLensThree;
    QLineEdit *lbl_sfLensThreeValue;
    QLineEdit *lbl_asrktLensThreeValue;
    QLineEdit *lbl_a2LensThreeValue;
    QLineEdit *lbl_asrkiiLensThreeValue;
    QLabel *lbl_acdLensThree;
    QLabel *lbl_asrkiiLensThree;
    QLabel *lbl_a1LensThree;
    QLineEdit *lbl_a0LensThreeValue;
    QLabel *lbl_a2LensThree;
    QLineEdit *lbl_a1LensThreeValue;
    QLabel *lbl_iolLensThree;
    QLabel *lbl_asrktLensThree;
    QLineEdit *lbl_acdLensThreeValue;
    QLabel *lbl_a0LensThree;
    QLabel *label_5;
    QComboBox *comboBox_patient;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lbl_currentPatientLK2Value;
    QLabel *lbl_currentPatientLK;
    QLabel *lbl_currentPatientRK2;
    QLabel *lbl_currentPatientRK1;
    QLabel *lbl_currentPatientRK;
    QLineEdit *lbl_currentPatientLKValue;
    QLineEdit *lbl_currentPatientRKValue;
    QLineEdit *lbl_currentPatientRK2Value;
    QLabel *lbl_currentPatientLK2;
    QLabel *lbl_currentPatientLK1;
    QLineEdit *lbl_currentPatientLK1Value;
    QLineEdit *lbl_currentPatientRK1Value;
    QLabel *lineEdit_docID;
    QLabel *lineEdit_docName;
    QLabel *lineEdit_primaryFormula;
    QLineEdit *lineEdit_patName;
    QLineEdit *lineEdit_patientAge;
    QLineEdit *lineEdit_patientGender;
    QLineEdit *lineEdit_patientContact;
    QLabel *lineEdit_patOpEye;
    QLabel *lineEdit_patOpMethod;
    QLabel *lineEdit_patOpMode;
    QLabel *lbl_time;
    QPushButton *pushButton;

    void setupUi(QDialog *DoctorDetailDialog)
    {
        if (DoctorDetailDialog->objectName().isEmpty())
            DoctorDetailDialog->setObjectName(QString::fromUtf8("DoctorDetailDialog"));
        DoctorDetailDialog->resize(1280, 720);
        DoctorDetailDialog->setStyleSheet(QString::fromUtf8("background-image: url(:/images/5.png);"));
        label = new QLabel(DoctorDetailDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(550, 10, 160, 70));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        btn_close = new QPushButton(DoctorDetailDialog);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));
        btn_close->setGeometry(QRect(0, 0, 81, 71));
        btn_close->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/icons/ic_arrow_back_white_48dp.png);"));
        btn_close->setFlat(true);
        frame = new QFrame(DoctorDetailDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(30, 90, 1231, 611));
        frame->setStyleSheet(QString::fromUtf8("border-image: url(:/images/card-image.png);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 70, 67, 17));
        label_2->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"background-image:url(:/images/empty.png);"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 120, 100, 17));
        label_3->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"background-image:url(:/images/empty.png);"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 170, 120, 17));
        label_4->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"background-image:url(:/images/empty.png);"));
        tabWidget_currentDoctor = new QTabWidget(frame);
        tabWidget_currentDoctor->setObjectName(QString::fromUtf8("tabWidget_currentDoctor"));
        tabWidget_currentDoctor->setGeometry(QRect(540, 0, 581, 321));
        tabWidget_currentDoctor->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);border-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        lbl_iolLensOne = new QLabel(tab);
        lbl_iolLensOne->setObjectName(QString::fromUtf8("lbl_iolLensOne"));
        lbl_iolLensOne->setGeometry(QRect(1, 4, 185, 17));
        lbl_iolLensOne->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_asrktLensOne = new QLabel(tab);
        lbl_asrktLensOne->setObjectName(QString::fromUtf8("lbl_asrktLensOne"));
        lbl_asrktLensOne->setGeometry(QRect(10, 30, 60, 17));
        lbl_asrktLensOne->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_asrktiiLensOne = new QLabel(tab);
        lbl_asrktiiLensOne->setObjectName(QString::fromUtf8("lbl_asrktiiLensOne"));
        lbl_asrktiiLensOne->setGeometry(QRect(10, 63, 60, 17));
        lbl_asrktiiLensOne->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_acdLensOne = new QLabel(tab);
        lbl_acdLensOne->setObjectName(QString::fromUtf8("lbl_acdLensOne"));
        lbl_acdLensOne->setGeometry(QRect(10, 90, 60, 17));
        lbl_acdLensOne->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_sfLensOne = new QLabel(tab);
        lbl_sfLensOne->setObjectName(QString::fromUtf8("lbl_sfLensOne"));
        lbl_sfLensOne->setGeometry(QRect(10, 120, 60, 17));
        lbl_sfLensOne->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_a0LensOne = new QLabel(tab);
        lbl_a0LensOne->setObjectName(QString::fromUtf8("lbl_a0LensOne"));
        lbl_a0LensOne->setGeometry(QRect(10, 150, 40, 17));
        lbl_a0LensOne->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_a1LensOne = new QLabel(tab);
        lbl_a1LensOne->setObjectName(QString::fromUtf8("lbl_a1LensOne"));
        lbl_a1LensOne->setGeometry(QRect(70, 150, 40, 17));
        lbl_a1LensOne->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_a2LensOne = new QLabel(tab);
        lbl_a2LensOne->setObjectName(QString::fromUtf8("lbl_a2LensOne"));
        lbl_a2LensOne->setGeometry(QRect(130, 150, 40, 17));
        lbl_a2LensOne->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_asrktLensOneValue = new QLineEdit(tab);
        lbl_asrktLensOneValue->setObjectName(QString::fromUtf8("lbl_asrktLensOneValue"));
        lbl_asrktLensOneValue->setGeometry(QRect(90, 30, 70, 20));
        lbl_asrktLensOneValue->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lbl_asrkiiLensOneValue = new QLineEdit(tab);
        lbl_asrkiiLensOneValue->setObjectName(QString::fromUtf8("lbl_asrkiiLensOneValue"));
        lbl_asrkiiLensOneValue->setGeometry(QRect(90, 60, 70, 20));
        lbl_asrkiiLensOneValue->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lbl_acdLensOneValue = new QLineEdit(tab);
        lbl_acdLensOneValue->setObjectName(QString::fromUtf8("lbl_acdLensOneValue"));
        lbl_acdLensOneValue->setGeometry(QRect(90, 90, 70, 20));
        lbl_acdLensOneValue->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lbl_sfLensOneValue = new QLineEdit(tab);
        lbl_sfLensOneValue->setObjectName(QString::fromUtf8("lbl_sfLensOneValue"));
        lbl_sfLensOneValue->setGeometry(QRect(90, 120, 70, 20));
        lbl_sfLensOneValue->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lbl_a0LensOneValue = new QLineEdit(tab);
        lbl_a0LensOneValue->setObjectName(QString::fromUtf8("lbl_a0LensOneValue"));
        lbl_a0LensOneValue->setGeometry(QRect(10, 170, 40, 30));
        lbl_a0LensOneValue->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lbl_a1LensOneValue = new QLineEdit(tab);
        lbl_a1LensOneValue->setObjectName(QString::fromUtf8("lbl_a1LensOneValue"));
        lbl_a1LensOneValue->setGeometry(QRect(70, 170, 40, 30));
        lbl_a1LensOneValue->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lbl_a2LensOneValue = new QLineEdit(tab);
        lbl_a2LensOneValue->setObjectName(QString::fromUtf8("lbl_a2LensOneValue"));
        lbl_a2LensOneValue->setGeometry(QRect(130, 170, 40, 30));
        lbl_a2LensOneValue->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        tabWidget_currentDoctor->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        lbl_sfLensTwo = new QLabel(tab_2);
        lbl_sfLensTwo->setObjectName(QString::fromUtf8("lbl_sfLensTwo"));
        lbl_sfLensTwo->setGeometry(QRect(10, 170, 60, 17));
        QFont font1;
        font1.setPointSize(13);
        lbl_sfLensTwo->setFont(font1);
        lbl_sfLensTwo->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_sfLensTwoValue = new QLineEdit(tab_2);
        lbl_sfLensTwoValue->setObjectName(QString::fromUtf8("lbl_sfLensTwoValue"));
        lbl_sfLensTwoValue->setGeometry(QRect(90, 170, 70, 20));
        lbl_sfLensTwoValue->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lbl_asrktLensTwoValue = new QLineEdit(tab_2);
        lbl_asrktLensTwoValue->setObjectName(QString::fromUtf8("lbl_asrktLensTwoValue"));
        lbl_asrktLensTwoValue->setGeometry(QRect(90, 50, 70, 20));
        lbl_asrktLensTwoValue->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lbl_a2LensTwoValue = new QLineEdit(tab_2);
        lbl_a2LensTwoValue->setObjectName(QString::fromUtf8("lbl_a2LensTwoValue"));
        lbl_a2LensTwoValue->setGeometry(QRect(190, 240, 50, 40));
        lbl_a2LensTwoValue->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lbl_asrkiiLensTwoValue = new QLineEdit(tab_2);
        lbl_asrkiiLensTwoValue->setObjectName(QString::fromUtf8("lbl_asrkiiLensTwoValue"));
        lbl_asrkiiLensTwoValue->setGeometry(QRect(90, 90, 70, 20));
        lbl_asrkiiLensTwoValue->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lbl_acdLensTwo = new QLabel(tab_2);
        lbl_acdLensTwo->setObjectName(QString::fromUtf8("lbl_acdLensTwo"));
        lbl_acdLensTwo->setGeometry(QRect(10, 130, 60, 17));
        lbl_acdLensTwo->setFont(font1);
        lbl_acdLensTwo->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_asrkiiLensTwo = new QLabel(tab_2);
        lbl_asrkiiLensTwo->setObjectName(QString::fromUtf8("lbl_asrkiiLensTwo"));
        lbl_asrkiiLensTwo->setGeometry(QRect(10, 90, 60, 17));
        lbl_asrkiiLensTwo->setFont(font1);
        lbl_asrkiiLensTwo->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_a1LensTwo = new QLabel(tab_2);
        lbl_a1LensTwo->setObjectName(QString::fromUtf8("lbl_a1LensTwo"));
        lbl_a1LensTwo->setGeometry(QRect(110, 210, 40, 17));
        lbl_a1LensTwo->setFont(font1);
        lbl_a1LensTwo->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_a0LensTwoValue = new QLineEdit(tab_2);
        lbl_a0LensTwoValue->setObjectName(QString::fromUtf8("lbl_a0LensTwoValue"));
        lbl_a0LensTwoValue->setGeometry(QRect(10, 240, 50, 40));
        lbl_a0LensTwoValue->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lbl_a2LensTwo = new QLabel(tab_2);
        lbl_a2LensTwo->setObjectName(QString::fromUtf8("lbl_a2LensTwo"));
        lbl_a2LensTwo->setGeometry(QRect(200, 210, 40, 17));
        lbl_a2LensTwo->setFont(font1);
        lbl_a2LensTwo->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_a1LensTwoValue = new QLineEdit(tab_2);
        lbl_a1LensTwoValue->setObjectName(QString::fromUtf8("lbl_a1LensTwoValue"));
        lbl_a1LensTwoValue->setGeometry(QRect(100, 240, 50, 40));
        lbl_a1LensTwoValue->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lbl_iolLensTwo = new QLabel(tab_2);
        lbl_iolLensTwo->setObjectName(QString::fromUtf8("lbl_iolLensTwo"));
        lbl_iolLensTwo->setGeometry(QRect(1, 4, 185, 17));
        QFont font2;
        font2.setPointSize(14);
        lbl_iolLensTwo->setFont(font2);
        lbl_iolLensTwo->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_asrktLensTwo = new QLabel(tab_2);
        lbl_asrktLensTwo->setObjectName(QString::fromUtf8("lbl_asrktLensTwo"));
        lbl_asrktLensTwo->setGeometry(QRect(10, 50, 60, 17));
        lbl_asrktLensTwo->setFont(font1);
        lbl_asrktLensTwo->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_acdLensTwoValue = new QLineEdit(tab_2);
        lbl_acdLensTwoValue->setObjectName(QString::fromUtf8("lbl_acdLensTwoValue"));
        lbl_acdLensTwoValue->setGeometry(QRect(90, 130, 70, 20));
        lbl_acdLensTwoValue->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lbl_a0LensTwo = new QLabel(tab_2);
        lbl_a0LensTwo->setObjectName(QString::fromUtf8("lbl_a0LensTwo"));
        lbl_a0LensTwo->setGeometry(QRect(20, 210, 40, 17));
        lbl_a0LensTwo->setFont(font1);
        lbl_a0LensTwo->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        tabWidget_currentDoctor->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        lbl_sfLensThree = new QLabel(tab_3);
        lbl_sfLensThree->setObjectName(QString::fromUtf8("lbl_sfLensThree"));
        lbl_sfLensThree->setGeometry(QRect(10, 120, 60, 17));
        lbl_sfLensThree->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_sfLensThreeValue = new QLineEdit(tab_3);
        lbl_sfLensThreeValue->setObjectName(QString::fromUtf8("lbl_sfLensThreeValue"));
        lbl_sfLensThreeValue->setGeometry(QRect(90, 120, 70, 20));
        lbl_sfLensThreeValue->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lbl_asrktLensThreeValue = new QLineEdit(tab_3);
        lbl_asrktLensThreeValue->setObjectName(QString::fromUtf8("lbl_asrktLensThreeValue"));
        lbl_asrktLensThreeValue->setGeometry(QRect(90, 30, 70, 20));
        lbl_asrktLensThreeValue->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lbl_a2LensThreeValue = new QLineEdit(tab_3);
        lbl_a2LensThreeValue->setObjectName(QString::fromUtf8("lbl_a2LensThreeValue"));
        lbl_a2LensThreeValue->setGeometry(QRect(130, 170, 40, 30));
        lbl_a2LensThreeValue->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lbl_asrkiiLensThreeValue = new QLineEdit(tab_3);
        lbl_asrkiiLensThreeValue->setObjectName(QString::fromUtf8("lbl_asrkiiLensThreeValue"));
        lbl_asrkiiLensThreeValue->setGeometry(QRect(90, 60, 70, 20));
        lbl_asrkiiLensThreeValue->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lbl_acdLensThree = new QLabel(tab_3);
        lbl_acdLensThree->setObjectName(QString::fromUtf8("lbl_acdLensThree"));
        lbl_acdLensThree->setGeometry(QRect(10, 90, 60, 17));
        lbl_acdLensThree->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_asrkiiLensThree = new QLabel(tab_3);
        lbl_asrkiiLensThree->setObjectName(QString::fromUtf8("lbl_asrkiiLensThree"));
        lbl_asrkiiLensThree->setGeometry(QRect(10, 63, 60, 17));
        lbl_asrkiiLensThree->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_a1LensThree = new QLabel(tab_3);
        lbl_a1LensThree->setObjectName(QString::fromUtf8("lbl_a1LensThree"));
        lbl_a1LensThree->setGeometry(QRect(70, 150, 40, 17));
        lbl_a1LensThree->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_a0LensThreeValue = new QLineEdit(tab_3);
        lbl_a0LensThreeValue->setObjectName(QString::fromUtf8("lbl_a0LensThreeValue"));
        lbl_a0LensThreeValue->setGeometry(QRect(10, 170, 40, 30));
        lbl_a0LensThreeValue->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lbl_a2LensThree = new QLabel(tab_3);
        lbl_a2LensThree->setObjectName(QString::fromUtf8("lbl_a2LensThree"));
        lbl_a2LensThree->setGeometry(QRect(130, 150, 40, 17));
        lbl_a2LensThree->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_a1LensThreeValue = new QLineEdit(tab_3);
        lbl_a1LensThreeValue->setObjectName(QString::fromUtf8("lbl_a1LensThreeValue"));
        lbl_a1LensThreeValue->setGeometry(QRect(70, 170, 40, 30));
        lbl_a1LensThreeValue->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lbl_iolLensThree = new QLabel(tab_3);
        lbl_iolLensThree->setObjectName(QString::fromUtf8("lbl_iolLensThree"));
        lbl_iolLensThree->setGeometry(QRect(1, 4, 185, 17));
        lbl_iolLensThree->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_asrktLensThree = new QLabel(tab_3);
        lbl_asrktLensThree->setObjectName(QString::fromUtf8("lbl_asrktLensThree"));
        lbl_asrktLensThree->setGeometry(QRect(10, 30, 60, 17));
        lbl_asrktLensThree->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        lbl_acdLensThreeValue = new QLineEdit(tab_3);
        lbl_acdLensThreeValue->setObjectName(QString::fromUtf8("lbl_acdLensThreeValue"));
        lbl_acdLensThreeValue->setGeometry(QRect(90, 90, 70, 20));
        lbl_acdLensThreeValue->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
""));
        lbl_a0LensThree = new QLabel(tab_3);
        lbl_a0LensThree->setObjectName(QString::fromUtf8("lbl_a0LensThree"));
        lbl_a0LensThree->setGeometry(QRect(10, 150, 40, 17));
        lbl_a0LensThree->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);color:rgb(21,21,21);"));
        tabWidget_currentDoctor->addTab(tab_3, QString());
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 300, 120, 17));
        label_5->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"background-image:url(:/images/empty.png);"));
        comboBox_patient = new QComboBox(frame);
        comboBox_patient->setObjectName(QString::fromUtf8("comboBox_patient"));
        comboBox_patient->setGeometry(QRect(170, 300, 320, 25));
        comboBox_patient->setStyleSheet(QString::fromUtf8(""));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 350, 110, 17));
        label_6->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"background-image:url(:/images/empty.png);"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 400, 110, 17));
        label_7->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"background-image:url(:/images/empty.png);"));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 450, 110, 17));
        label_8->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"background-image:url(:/images/empty.png);"));
        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(30, 500, 110, 17));
        label_9->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"background-image:url(:/images/empty.png);"));
        label_10 = new QLabel(frame);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(30, 550, 110, 17));
        label_10->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"background-image:url(:/images/empty.png);"));
        label_11 = new QLabel(frame);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(540, 350, 110, 17));
        label_11->setFont(font2);
        label_11->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"background-image:url(:/images/empty.png);"));
        lbl_currentPatientLK2Value = new QLineEdit(frame);
        lbl_currentPatientLK2Value->setObjectName(QString::fromUtf8("lbl_currentPatientLK2Value"));
        lbl_currentPatientLK2Value->setGeometry(QRect(620, 420, 50, 40));
        lbl_currentPatientLK2Value->setStyleSheet(QString::fromUtf8("border-image: url(:/images/empty.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_currentPatientLK = new QLabel(frame);
        lbl_currentPatientLK->setObjectName(QString::fromUtf8("lbl_currentPatientLK"));
        lbl_currentPatientLK->setGeometry(QRect(700, 390, 40, 17));
        lbl_currentPatientLK->setStyleSheet(QString::fromUtf8("border-image: url(:/images/empty.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_currentPatientRK2 = new QLabel(frame);
        lbl_currentPatientRK2->setObjectName(QString::fromUtf8("lbl_currentPatientRK2"));
        lbl_currentPatientRK2->setGeometry(QRect(620, 470, 40, 17));
        lbl_currentPatientRK2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/empty.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_currentPatientRK1 = new QLabel(frame);
        lbl_currentPatientRK1->setObjectName(QString::fromUtf8("lbl_currentPatientRK1"));
        lbl_currentPatientRK1->setGeometry(QRect(540, 470, 40, 17));
        lbl_currentPatientRK1->setStyleSheet(QString::fromUtf8("border-image: url(:/images/empty.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_currentPatientRK = new QLabel(frame);
        lbl_currentPatientRK->setObjectName(QString::fromUtf8("lbl_currentPatientRK"));
        lbl_currentPatientRK->setGeometry(QRect(700, 470, 40, 17));
        lbl_currentPatientRK->setStyleSheet(QString::fromUtf8("border-image: url(:/images/empty.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_currentPatientLKValue = new QLineEdit(frame);
        lbl_currentPatientLKValue->setObjectName(QString::fromUtf8("lbl_currentPatientLKValue"));
        lbl_currentPatientLKValue->setGeometry(QRect(700, 420, 50, 40));
        lbl_currentPatientLKValue->setStyleSheet(QString::fromUtf8("border-image: url(:/images/empty.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_currentPatientRKValue = new QLineEdit(frame);
        lbl_currentPatientRKValue->setObjectName(QString::fromUtf8("lbl_currentPatientRKValue"));
        lbl_currentPatientRKValue->setGeometry(QRect(700, 500, 50, 40));
        lbl_currentPatientRKValue->setStyleSheet(QString::fromUtf8("border-image: url(:/images/empty.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_currentPatientRK2Value = new QLineEdit(frame);
        lbl_currentPatientRK2Value->setObjectName(QString::fromUtf8("lbl_currentPatientRK2Value"));
        lbl_currentPatientRK2Value->setGeometry(QRect(620, 500, 50, 40));
        lbl_currentPatientRK2Value->setStyleSheet(QString::fromUtf8("border-image: url(:/images/empty.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_currentPatientLK2 = new QLabel(frame);
        lbl_currentPatientLK2->setObjectName(QString::fromUtf8("lbl_currentPatientLK2"));
        lbl_currentPatientLK2->setGeometry(QRect(620, 390, 40, 17));
        lbl_currentPatientLK2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/empty.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_currentPatientLK1 = new QLabel(frame);
        lbl_currentPatientLK1->setObjectName(QString::fromUtf8("lbl_currentPatientLK1"));
        lbl_currentPatientLK1->setGeometry(QRect(540, 390, 40, 17));
        lbl_currentPatientLK1->setStyleSheet(QString::fromUtf8("border-image: url(:/images/empty.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_currentPatientLK1Value = new QLineEdit(frame);
        lbl_currentPatientLK1Value->setObjectName(QString::fromUtf8("lbl_currentPatientLK1Value"));
        lbl_currentPatientLK1Value->setGeometry(QRect(540, 420, 50, 40));
        lbl_currentPatientLK1Value->setStyleSheet(QString::fromUtf8("border-image: url(:/images/empty.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_currentPatientRK1Value = new QLineEdit(frame);
        lbl_currentPatientRK1Value->setObjectName(QString::fromUtf8("lbl_currentPatientRK1Value"));
        lbl_currentPatientRK1Value->setGeometry(QRect(540, 500, 50, 40));
        lbl_currentPatientRK1Value->setStyleSheet(QString::fromUtf8("border-image: url(:/images/empty.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lineEdit_docID = new QLabel(frame);
        lineEdit_docID->setObjectName(QString::fromUtf8("lineEdit_docID"));
        lineEdit_docID->setGeometry(QRect(170, 66, 210, 23));
        lineEdit_docID->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"background-image: url(:/images/searchbar.png);"));
        lineEdit_docName = new QLabel(frame);
        lineEdit_docName->setObjectName(QString::fromUtf8("lineEdit_docName"));
        lineEdit_docName->setGeometry(QRect(170, 120, 230, 23));
        lineEdit_docName->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"background-image: url(:/images/searchbar.png);"));
        lineEdit_primaryFormula = new QLabel(frame);
        lineEdit_primaryFormula->setObjectName(QString::fromUtf8("lineEdit_primaryFormula"));
        lineEdit_primaryFormula->setGeometry(QRect(170, 170, 210, 23));
        lineEdit_primaryFormula->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"background-image: url(:/images/searchbar.png);"));
        lineEdit_patName = new QLineEdit(frame);
        lineEdit_patName->setObjectName(QString::fromUtf8("lineEdit_patName"));
        lineEdit_patName->setGeometry(QRect(170, 350, 210, 20));
        lineEdit_patName->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"background-image: url(:/images/searchbar.png);"));
        lineEdit_patientAge = new QLineEdit(frame);
        lineEdit_patientAge->setObjectName(QString::fromUtf8("lineEdit_patientAge"));
        lineEdit_patientAge->setGeometry(QRect(170, 400, 60, 20));
        lineEdit_patientAge->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"background-image: url(:/images/searchbar.png);"));
        lineEdit_patientGender = new QLineEdit(frame);
        lineEdit_patientGender->setObjectName(QString::fromUtf8("lineEdit_patientGender"));
        lineEdit_patientGender->setGeometry(QRect(170, 450, 110, 20));
        lineEdit_patientGender->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"background-image: url(:/images/searchbar.png);"));
        lineEdit_patientContact = new QLineEdit(frame);
        lineEdit_patientContact->setObjectName(QString::fromUtf8("lineEdit_patientContact"));
        lineEdit_patientContact->setGeometry(QRect(170, 500, 180, 20));
        lineEdit_patientContact->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"background-image: url(:/images/searchbar.png);"));
        lineEdit_patOpEye = new QLabel(frame);
        lineEdit_patOpEye->setObjectName(QString::fromUtf8("lineEdit_patOpEye"));
        lineEdit_patOpEye->setGeometry(QRect(30, 580, 80, 20));
        lineEdit_patOpEye->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"background-image: url(:/images/searchbar.png);"));
        lineEdit_patOpMethod = new QLabel(frame);
        lineEdit_patOpMethod->setObjectName(QString::fromUtf8("lineEdit_patOpMethod"));
        lineEdit_patOpMethod->setGeometry(QRect(150, 580, 80, 20));
        lineEdit_patOpMethod->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"background-image: url(:/images/searchbar.png);"));
        lineEdit_patOpMode = new QLabel(frame);
        lineEdit_patOpMode->setObjectName(QString::fromUtf8("lineEdit_patOpMode"));
        lineEdit_patOpMode->setGeometry(QRect(270, 580, 90, 20));
        lineEdit_patOpMode->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"background-image: url(:/images/searchbar.png);"));
        lbl_time = new QLabel(DoctorDetailDialog);
        lbl_time->setObjectName(QString::fromUtf8("lbl_time"));
        lbl_time->setGeometry(QRect(1160, 0, 120, 40));
        QFont font3;
        font3.setPointSize(11);
        lbl_time->setFont(font3);
        lbl_time->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);border-image:url(:/images/empty.png);"));
        lbl_time->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        pushButton = new QPushButton(DoctorDetailDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 50, 90, 90));
        pushButton->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/surgeon-icon.png);"));

        retranslateUi(DoctorDetailDialog);

        tabWidget_currentDoctor->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(DoctorDetailDialog);
    } // setupUi

    void retranslateUi(QDialog *DoctorDetailDialog)
    {
        DoctorDetailDialog->setWindowTitle(QCoreApplication::translate("DoctorDetailDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DoctorDetailDialog", "Doctor Details", nullptr));
        btn_close->setText(QString());
        label_2->setText(QCoreApplication::translate("DoctorDetailDialog", "Doctor ID", nullptr));
        label_3->setText(QCoreApplication::translate("DoctorDetailDialog", "Doctor Name", nullptr));
        label_4->setText(QCoreApplication::translate("DoctorDetailDialog", "Primary Formula", nullptr));
        lbl_iolLensOne->setText(QCoreApplication::translate("DoctorDetailDialog", "IOL", nullptr));
        lbl_asrktLensOne->setText(QCoreApplication::translate("DoctorDetailDialog", "ASRKT", nullptr));
        lbl_asrktiiLensOne->setText(QCoreApplication::translate("DoctorDetailDialog", "ASRKII", nullptr));
        lbl_acdLensOne->setText(QCoreApplication::translate("DoctorDetailDialog", "ACD", nullptr));
        lbl_sfLensOne->setText(QCoreApplication::translate("DoctorDetailDialog", "SF", nullptr));
        lbl_a0LensOne->setText(QCoreApplication::translate("DoctorDetailDialog", "A0", nullptr));
        lbl_a1LensOne->setText(QCoreApplication::translate("DoctorDetailDialog", "A1", nullptr));
        lbl_a2LensOne->setText(QCoreApplication::translate("DoctorDetailDialog", "A2", nullptr));
        tabWidget_currentDoctor->setTabText(tabWidget_currentDoctor->indexOf(tab), QCoreApplication::translate("DoctorDetailDialog", "Lens1", nullptr));
        lbl_sfLensTwo->setText(QCoreApplication::translate("DoctorDetailDialog", "SF", nullptr));
        lbl_acdLensTwo->setText(QCoreApplication::translate("DoctorDetailDialog", "ACD", nullptr));
        lbl_asrkiiLensTwo->setText(QCoreApplication::translate("DoctorDetailDialog", "ASRKII", nullptr));
        lbl_a1LensTwo->setText(QCoreApplication::translate("DoctorDetailDialog", "A1", nullptr));
        lbl_a2LensTwo->setText(QCoreApplication::translate("DoctorDetailDialog", "A2", nullptr));
        lbl_iolLensTwo->setText(QCoreApplication::translate("DoctorDetailDialog", "IOL", nullptr));
        lbl_asrktLensTwo->setText(QCoreApplication::translate("DoctorDetailDialog", "ASRKT", nullptr));
        lbl_a0LensTwo->setText(QCoreApplication::translate("DoctorDetailDialog", "A0", nullptr));
        tabWidget_currentDoctor->setTabText(tabWidget_currentDoctor->indexOf(tab_2), QCoreApplication::translate("DoctorDetailDialog", "Lens2", nullptr));
        lbl_sfLensThree->setText(QCoreApplication::translate("DoctorDetailDialog", "SF", nullptr));
        lbl_acdLensThree->setText(QCoreApplication::translate("DoctorDetailDialog", "ACD", nullptr));
        lbl_asrkiiLensThree->setText(QCoreApplication::translate("DoctorDetailDialog", "ASRKII", nullptr));
        lbl_a1LensThree->setText(QCoreApplication::translate("DoctorDetailDialog", "A1", nullptr));
        lbl_a2LensThree->setText(QCoreApplication::translate("DoctorDetailDialog", "A2", nullptr));
        lbl_iolLensThree->setText(QCoreApplication::translate("DoctorDetailDialog", "IOL", nullptr));
        lbl_asrktLensThree->setText(QCoreApplication::translate("DoctorDetailDialog", "ASRKT", nullptr));
        lbl_a0LensThree->setText(QCoreApplication::translate("DoctorDetailDialog", "A0", nullptr));
        tabWidget_currentDoctor->setTabText(tabWidget_currentDoctor->indexOf(tab_3), QCoreApplication::translate("DoctorDetailDialog", "Lens3", nullptr));
        label_5->setText(QCoreApplication::translate("DoctorDetailDialog", "Patients", nullptr));
        label_6->setText(QCoreApplication::translate("DoctorDetailDialog", "Patient Name", nullptr));
        label_7->setText(QCoreApplication::translate("DoctorDetailDialog", "Age", nullptr));
        label_8->setText(QCoreApplication::translate("DoctorDetailDialog", "Gender", nullptr));
        label_9->setText(QCoreApplication::translate("DoctorDetailDialog", "Contact", nullptr));
        label_10->setText(QCoreApplication::translate("DoctorDetailDialog", "Settings", nullptr));
        label_11->setText(QCoreApplication::translate("DoctorDetailDialog", "Keratometry", nullptr));
        lbl_currentPatientLK2Value->setText(QString());
        lbl_currentPatientLK->setText(QCoreApplication::translate("DoctorDetailDialog", "LK", nullptr));
        lbl_currentPatientRK2->setText(QCoreApplication::translate("DoctorDetailDialog", "RK2", nullptr));
        lbl_currentPatientRK1->setText(QCoreApplication::translate("DoctorDetailDialog", "RK1", nullptr));
        lbl_currentPatientRK->setText(QCoreApplication::translate("DoctorDetailDialog", "RK", nullptr));
        lbl_currentPatientLKValue->setText(QString());
        lbl_currentPatientRKValue->setText(QString());
        lbl_currentPatientRK2Value->setText(QString());
        lbl_currentPatientLK2->setText(QCoreApplication::translate("DoctorDetailDialog", "LK2", nullptr));
        lbl_currentPatientLK1->setText(QCoreApplication::translate("DoctorDetailDialog", "LK1", nullptr));
        lineEdit_docID->setText(QString());
        lineEdit_docName->setText(QString());
        lineEdit_primaryFormula->setText(QString());
        lineEdit_patOpEye->setText(QString());
        lineEdit_patOpMethod->setText(QString());
        lineEdit_patOpMode->setText(QString());
        lbl_time->setText(QCoreApplication::translate("DoctorDetailDialog", "10:09", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DoctorDetailDialog: public Ui_DoctorDetailDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORDETAILDIALOG_H
