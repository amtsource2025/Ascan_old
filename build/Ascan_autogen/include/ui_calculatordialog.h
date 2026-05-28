/********************************************************************************
** Form generated from reading UI file 'calculatordialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATORDIALOG_H
#define UI_CALCULATORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CalculatorDialog
{
public:
    QLabel *lbl_patName;
    QLabel *lbl_patID;
    QLineEdit *lineEdit_docName;
    QLabel *lbl_docName;
    QLineEdit *lineEdit_patName;
    QLineEdit *lineEdit_patID;
    QPushButton *btn_eye;
    QLineEdit *lbl_kValEdit;
    QLineEdit *lbl_rxValEdit;
    QLabel *lbl_rxval;
    QLabel *lbl_k1val;
    QLabel *lbl_alval;
    QLabel *lbl_kval;
    QLineEdit *lbl_alValEdit;
    QLabel *lbl_k2val;
    QFrame *frame;
    QComboBox *comboBox_lensOne;
    QLabel *lbl_a0;
    QLabel *lbl_sf1;
    QLabel *lbl_acd1;
    QLabel *lbl_aconst1;
    QLineEdit *cdisp6;
    QLineEdit *cdisp9;
    QLineEdit *cdisp1;
    QLineEdit *cdisp3;
    QLineEdit *cdisp10;
    QLineEdit *cdisp4;
    QLabel *lbl_iolOne;
    QLabel *lbl_refOne;
    QLineEdit *cdisp5;
    QLineEdit *cdisp2;
    QLineEdit *cdisp7;
    QLineEdit *cdisp8;
    QPushButton *btn_hofferq;
    QPushButton *btn_holladay;
    QPushButton *btn_srkt;
    QPushButton *btn_srkii;
    QPushButton *btn_haigis;
    QLabel *cemm2;
    QLabel *cemm3;
    QLabel *cemm1;
    QPushButton *btn_home;
    QPushButton *btn_measure;
    QPushButton *btn_print;
    QLabel *lbl_k1val_2;
    QLabel *lbl_k1val_3;
    QLabel *lbl_k1val_4;
    QFrame *frame_2;
    QComboBox *comboBox_lensTwo;
    QLabel *lbl_a1;
    QLabel *lbl_sf2;
    QLabel *lbl_acd2;
    QLabel *lbl_aconst2;
    QLineEdit *cdisp16;
    QLineEdit *cdisp19;
    QLineEdit *cdisp11;
    QLineEdit *cdisp13;
    QLineEdit *cdisp20;
    QLineEdit *cdisp14;
    QLabel *lbl_iolOne2;
    QLabel *lbl_refOne2;
    QLineEdit *cdisp15;
    QLineEdit *cdisp12;
    QLineEdit *cdisp17;
    QLineEdit *cdisp18;
    QFrame *frame_3;
    QComboBox *comboBox_lensThree;
    QLabel *lbl_a2;
    QLabel *lbl_sf3;
    QLabel *lbl_acd3;
    QLabel *lbl_aconst3;
    QLineEdit *cdisp26;
    QLineEdit *cdisp29;
    QLineEdit *cdisp21;
    QLineEdit *cdisp23;
    QLineEdit *cdisp30;
    QLineEdit *cdisp24;
    QLabel *lbl_iolOne3;
    QLabel *lbl_refOne3;
    QLineEdit *cdisp25;
    QLineEdit *cdisp22;
    QLineEdit *cdisp27;
    QLineEdit *cdisp28;
    QLabel *snackbar;
    QLineEdit *lbl_k1ValEdit1;
    QLineEdit *lbl_k2ValEdit;
    QLineEdit *lbl_k1ValEdit;
    QLineEdit *lbl_k2ValEdit2;
    QLineEdit *lbl_rxValEdit2;
    QLineEdit *lbl_kValEdit2;
    QLineEdit *lbl_alValEdit2;
    QLabel *lbl_time;
    QPushButton *btn_warning1;
    QPushButton *btn_warning2;
    QPushButton *btn_warning3;
    QLineEdit *lineEdit_sf12;
    QLineEdit *lineEdit_sf1;
    QLineEdit *lineEdit_A02;
    QLineEdit *lineEdit_acd1;
    QLineEdit *lineEdit_aconst12;
    QLineEdit *lineEdit_acd12;
    QLineEdit *lineEdit_A0;
    QLineEdit *lineEdit_aconst1;
    QLineEdit *lineEdit_acd2;
    QLineEdit *lineEdit_aconst2;
    QLineEdit *lineEdit_A12;
    QLineEdit *lineEdit_acd22;
    QLineEdit *lineEdit_aconst22;
    QLineEdit *lineEdit_A1;
    QLineEdit *lineEdit_sf22;
    QLineEdit *lineEdit_sf2;
    QLineEdit *lineEdit_A22;
    QLineEdit *lineEdit_sf3;
    QLineEdit *lineEdit_acd32;
    QLineEdit *lineEdit_A2;
    QLineEdit *lineEdit_aconst32;
    QLineEdit *lineEdit_acd3;
    QLineEdit *lineEdit_aconst3;
    QLineEdit *lineEdit_sf32;
    QPushButton *btn_newPatient;
    QLabel *lbl_k1val_5;

    void setupUi(QDialog *CalculatorDialog)
    {
        if (CalculatorDialog->objectName().isEmpty())
            CalculatorDialog->setObjectName(QString::fromUtf8("CalculatorDialog"));
        CalculatorDialog->resize(800, 600);
        CalculatorDialog->setAutoFillBackground(false);
        CalculatorDialog->setStyleSheet(QString::fromUtf8("background-image: url(:/images/5.png);"));
        lbl_patName = new QLabel(CalculatorDialog);
        lbl_patName->setObjectName(QString::fromUtf8("lbl_patName"));
        lbl_patName->setGeometry(QRect(210, 4, 70, 16));
        lbl_patName->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_patName->setAlignment(Qt::AlignCenter);
        lbl_patID = new QLabel(CalculatorDialog);
        lbl_patID->setObjectName(QString::fromUtf8("lbl_patID"));
        lbl_patID->setGeometry(QRect(-10, 4, 100, 16));
        lbl_patID->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_patID->setAlignment(Qt::AlignCenter);
        lineEdit_docName = new QLineEdit(CalculatorDialog);
        lineEdit_docName->setObjectName(QString::fromUtf8("lineEdit_docName"));
        lineEdit_docName->setGeometry(QRect(520, 4, 150, 20));
        lineEdit_docName->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(empty.png);\n"
"color:rgb(21,21,21);"));
        lbl_docName = new QLabel(CalculatorDialog);
        lbl_docName->setObjectName(QString::fromUtf8("lbl_docName"));
        lbl_docName->setGeometry(QRect(450, 4, 80, 16));
        lbl_docName->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_docName->setAlignment(Qt::AlignCenter);
        lineEdit_patName = new QLineEdit(CalculatorDialog);
        lineEdit_patName->setObjectName(QString::fromUtf8("lineEdit_patName"));
        lineEdit_patName->setGeometry(QRect(280, 4, 177, 20));
        lineEdit_patName->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(empty.png);\n"
"color:rgb(21,21,21);"));
        lineEdit_patID = new QLineEdit(CalculatorDialog);
        lineEdit_patID->setObjectName(QString::fromUtf8("lineEdit_patID"));
        lineEdit_patID->setGeometry(QRect(80, 4, 140, 20));
        lineEdit_patID->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(empty.png);\n"
"color:rgb(21,21,21);"));
        btn_eye = new QPushButton(CalculatorDialog);
        btn_eye->setObjectName(QString::fromUtf8("btn_eye"));
        btn_eye->setGeometry(QRect(0, 30, 100, 100));
        QFont font;
        font.setPointSize(25);
        btn_eye->setFont(font);
        btn_eye->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/btn-small.png);"));
        btn_eye->setFlat(true);
        lbl_kValEdit = new QLineEdit(CalculatorDialog);
        lbl_kValEdit->setObjectName(QString::fromUtf8("lbl_kValEdit"));
        lbl_kValEdit->setGeometry(QRect(430, 64, 125, 90));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(26);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        lbl_kValEdit->setFont(font1);
        lbl_kValEdit->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-mid.png);\n"
"background-image:url(empty.png);"));
        lbl_kValEdit->setAlignment(Qt::AlignCenter);
        lbl_kValEdit->setReadOnly(true);
        lbl_rxValEdit = new QLineEdit(CalculatorDialog);
        lbl_rxValEdit->setObjectName(QString::fromUtf8("lbl_rxValEdit"));
        lbl_rxValEdit->setGeometry(QRect(333, 64, 80, 60));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu"));
        font2.setPointSize(18);
        font2.setBold(false);
        font2.setWeight(50);
        lbl_rxValEdit->setFont(font2);
        lbl_rxValEdit->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-mid.png);\n"
"background-image:url(empty.png);"));
        lbl_rxValEdit->setAlignment(Qt::AlignCenter);
        lbl_rxval = new QLabel(CalculatorDialog);
        lbl_rxval->setObjectName(QString::fromUtf8("lbl_rxval"));
        lbl_rxval->setGeometry(QRect(330, 30, 80, 40));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Ubuntu"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        lbl_rxval->setFont(font3);
        lbl_rxval->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);background-image:url(empty.png);"));
        lbl_rxval->setAlignment(Qt::AlignCenter);
        lbl_k1val = new QLabel(CalculatorDialog);
        lbl_k1val->setObjectName(QString::fromUtf8("lbl_k1val"));
        lbl_k1val->setGeometry(QRect(130, 30, 85, 40));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Ubuntu"));
        font4.setPointSize(14);
        font4.setBold(false);
        font4.setWeight(50);
        lbl_k1val->setFont(font4);
        lbl_k1val->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);background-image:url(empty.png);"));
        lbl_k1val->setAlignment(Qt::AlignCenter);
        lbl_alval = new QLabel(CalculatorDialog);
        lbl_alval->setObjectName(QString::fromUtf8("lbl_alval"));
        lbl_alval->setGeometry(QRect(548, 43, 130, 16));
        lbl_alval->setFont(font4);
        lbl_alval->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);background-image:url(empty.png);"));
        lbl_alval->setAlignment(Qt::AlignCenter);
        lbl_kval = new QLabel(CalculatorDialog);
        lbl_kval->setObjectName(QString::fromUtf8("lbl_kval"));
        lbl_kval->setGeometry(QRect(450, 34, 90, 31));
        lbl_kval->setFont(font4);
        lbl_kval->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);background-image:url(empty.png);"));
        lbl_kval->setAlignment(Qt::AlignCenter);
        lbl_alValEdit = new QLineEdit(CalculatorDialog);
        lbl_alValEdit->setObjectName(QString::fromUtf8("lbl_alValEdit"));
        lbl_alValEdit->setGeometry(QRect(563, 64, 125, 90));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Ubuntu"));
        font5.setPointSize(28);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setWeight(75);
        lbl_alValEdit->setFont(font5);
        lbl_alValEdit->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-mid.png);\n"
"background-image:url(empty.png);"));
        lbl_alValEdit->setAlignment(Qt::AlignCenter);
        lbl_alValEdit->setReadOnly(false);
        lbl_k2val = new QLabel(CalculatorDialog);
        lbl_k2val->setObjectName(QString::fromUtf8("lbl_k2val"));
        lbl_k2val->setGeometry(QRect(230, 30, 85, 40));
        lbl_k2val->setFont(font4);
        lbl_k2val->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);background-image:url(empty.png);"));
        lbl_k2val->setAlignment(Qt::AlignCenter);
        frame = new QFrame(CalculatorDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 160, 229, 350));
        frame->setStyleSheet(QString::fromUtf8("background-image: url(empty.png);\n"
"background-color: rgb(96, 125, 139);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        comboBox_lensOne = new QComboBox(frame);
        comboBox_lensOne->setObjectName(QString::fromUtf8("comboBox_lensOne"));
        comboBox_lensOne->setGeometry(QRect(4, 4, 220, 30));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Ubuntu"));
        font6.setPointSize(16);
        comboBox_lensOne->setFont(font6);
        comboBox_lensOne->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color:rgb(33,33,33);\n"
"background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_a0 = new QLabel(frame);
        lbl_a0->setObjectName(QString::fromUtf8("lbl_a0"));
        lbl_a0->setGeometry(QRect(20, 40, 80, 40));
        lbl_a0->setFont(font4);
        lbl_a0->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lbl_a0->setAlignment(Qt::AlignCenter);
        lbl_sf1 = new QLabel(frame);
        lbl_sf1->setObjectName(QString::fromUtf8("lbl_sf1"));
        lbl_sf1->setGeometry(QRect(17, 48, 90, 30));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Ubuntu"));
        font7.setPointSize(15);
        font7.setBold(false);
        font7.setWeight(50);
        lbl_sf1->setFont(font7);
        lbl_sf1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lbl_sf1->setAlignment(Qt::AlignCenter);
        lbl_acd1 = new QLabel(frame);
        lbl_acd1->setObjectName(QString::fromUtf8("lbl_acd1"));
        lbl_acd1->setGeometry(QRect(28, 40, 80, 50));
        lbl_acd1->setFont(font7);
        lbl_acd1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lbl_acd1->setAlignment(Qt::AlignCenter);
        lbl_aconst1 = new QLabel(frame);
        lbl_aconst1->setObjectName(QString::fromUtf8("lbl_aconst1"));
        lbl_aconst1->setGeometry(QRect(7, 44, 102, 40));
        lbl_aconst1->setFont(font7);
        lbl_aconst1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lbl_aconst1->setAlignment(Qt::AlignCenter);
        cdisp6 = new QLineEdit(frame);
        cdisp6->setObjectName(QString::fromUtf8("cdisp6"));
        cdisp6->setGeometry(QRect(120, 140, 90, 30));
        cdisp6->setFont(font7);
        cdisp6->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);"));
        cdisp6->setAlignment(Qt::AlignCenter);
        cdisp6->setReadOnly(true);
        cdisp9 = new QLineEdit(frame);
        cdisp9->setObjectName(QString::fromUtf8("cdisp9"));
        cdisp9->setGeometry(QRect(120, 267, 90, 30));
        cdisp9->setFont(font7);
        cdisp9->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);"));
        cdisp9->setAlignment(Qt::AlignCenter);
        cdisp9->setReadOnly(true);
        cdisp1 = new QLineEdit(frame);
        cdisp1->setObjectName(QString::fromUtf8("cdisp1"));
        cdisp1->setGeometry(QRect(20, 140, 90, 30));
        cdisp1->setFont(font7);
        cdisp1->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);"));
        cdisp1->setAlignment(Qt::AlignCenter);
        cdisp1->setReadOnly(true);
        cdisp3 = new QLineEdit(frame);
        cdisp3->setObjectName(QString::fromUtf8("cdisp3"));
        cdisp3->setGeometry(QRect(10, 210, 100, 50));
        QFont font8;
        font8.setFamily(QString::fromUtf8("Ubuntu"));
        font8.setPointSize(18);
        font8.setBold(true);
        font8.setWeight(75);
        cdisp3->setFont(font8);
        cdisp3->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"color: rgb(13, 71, 161);\n"
"background-color: rgb(172, 224, 251);\n"
""));
        cdisp3->setAlignment(Qt::AlignCenter);
        cdisp3->setReadOnly(true);
        cdisp10 = new QLineEdit(frame);
        cdisp10->setObjectName(QString::fromUtf8("cdisp10"));
        cdisp10->setGeometry(QRect(120, 300, 90, 30));
        cdisp10->setFont(font7);
        cdisp10->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);"));
        cdisp10->setAlignment(Qt::AlignCenter);
        cdisp10->setReadOnly(true);
        cdisp4 = new QLineEdit(frame);
        cdisp4->setObjectName(QString::fromUtf8("cdisp4"));
        cdisp4->setGeometry(QRect(20, 267, 90, 30));
        cdisp4->setFont(font7);
        cdisp4->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);"));
        cdisp4->setAlignment(Qt::AlignCenter);
        cdisp4->setReadOnly(true);
        lbl_iolOne = new QLabel(frame);
        lbl_iolOne->setObjectName(QString::fromUtf8("lbl_iolOne"));
        lbl_iolOne->setGeometry(QRect(8, 110, 120, 20));
        lbl_iolOne->setFont(font7);
        lbl_iolOne->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);"));
        lbl_iolOne->setAlignment(Qt::AlignCenter);
        lbl_refOne = new QLabel(frame);
        lbl_refOne->setObjectName(QString::fromUtf8("lbl_refOne"));
        lbl_refOne->setGeometry(QRect(95, 110, 130, 20));
        lbl_refOne->setFont(font7);
        lbl_refOne->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);"));
        lbl_refOne->setAlignment(Qt::AlignCenter);
        cdisp5 = new QLineEdit(frame);
        cdisp5->setObjectName(QString::fromUtf8("cdisp5"));
        cdisp5->setGeometry(QRect(20, 300, 90, 30));
        cdisp5->setFont(font7);
        cdisp5->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);"));
        cdisp5->setAlignment(Qt::AlignCenter);
        cdisp5->setReadOnly(true);
        cdisp2 = new QLineEdit(frame);
        cdisp2->setObjectName(QString::fromUtf8("cdisp2"));
        cdisp2->setGeometry(QRect(20, 173, 90, 30));
        cdisp2->setFont(font7);
        cdisp2->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);"));
        cdisp2->setAlignment(Qt::AlignCenter);
        cdisp2->setReadOnly(true);
        cdisp7 = new QLineEdit(frame);
        cdisp7->setObjectName(QString::fromUtf8("cdisp7"));
        cdisp7->setGeometry(QRect(120, 173, 90, 30));
        cdisp7->setFont(font7);
        cdisp7->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);"));
        cdisp7->setAlignment(Qt::AlignCenter);
        cdisp7->setReadOnly(true);
        cdisp8 = new QLineEdit(frame);
        cdisp8->setObjectName(QString::fromUtf8("cdisp8"));
        cdisp8->setGeometry(QRect(120, 210, 100, 50));
        cdisp8->setFont(font8);
        cdisp8->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"color: rgb(13, 71, 161);\n"
"background-color: rgb(172, 224, 251);\n"
""));
        cdisp8->setAlignment(Qt::AlignCenter);
        cdisp8->setReadOnly(true);
        btn_hofferq = new QPushButton(CalculatorDialog);
        btn_hofferq->setObjectName(QString::fromUtf8("btn_hofferq"));
        btn_hofferq->setGeometry(QRect(320, 544, 160, 55));
        QFont font9;
        font9.setFamily(QString::fromUtf8("Ubuntu"));
        font9.setPointSize(14);
        btn_hofferq->setFont(font9);
        btn_hofferq->setFocusPolicy(Qt::NoFocus);
        btn_hofferq->setStyleSheet(QString::fromUtf8("border-radius:5px;background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);\n"
"background-image:url(empty.png);"));
        btn_hofferq->setFlat(true);
        btn_holladay = new QPushButton(CalculatorDialog);
        btn_holladay->setObjectName(QString::fromUtf8("btn_holladay"));
        btn_holladay->setGeometry(QRect(480, 544, 160, 55));
        btn_holladay->setFont(font9);
        btn_holladay->setFocusPolicy(Qt::NoFocus);
        btn_holladay->setStyleSheet(QString::fromUtf8("border-radius:5px;background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);\n"
"background-image:url(empty.png);"));
        btn_holladay->setFlat(true);
        btn_srkt = new QPushButton(CalculatorDialog);
        btn_srkt->setObjectName(QString::fromUtf8("btn_srkt"));
        btn_srkt->setGeometry(QRect(160, 544, 160, 55));
        btn_srkt->setFont(font9);
        btn_srkt->setFocusPolicy(Qt::NoFocus);
        btn_srkt->setStyleSheet(QString::fromUtf8("border-radius:5px;background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);\n"
"background-image:url(empty.png);"));
        btn_srkt->setFlat(true);
        btn_srkii = new QPushButton(CalculatorDialog);
        btn_srkii->setObjectName(QString::fromUtf8("btn_srkii"));
        btn_srkii->setGeometry(QRect(1, 544, 160, 54));
        btn_srkii->setFont(font9);
        btn_srkii->setFocusPolicy(Qt::NoFocus);
        btn_srkii->setStyleSheet(QString::fromUtf8("border-radius:5px;background-color: rgb(244, 67, 54);\n"
"color:rgb(255,255,255);\n"
"background-image:url(empty.png);"));
        btn_srkii->setFlat(true);
        btn_haigis = new QPushButton(CalculatorDialog);
        btn_haigis->setObjectName(QString::fromUtf8("btn_haigis"));
        btn_haigis->setGeometry(QRect(640, 544, 160, 55));
        btn_haigis->setFont(font9);
        btn_haigis->setFocusPolicy(Qt::NoFocus);
        btn_haigis->setStyleSheet(QString::fromUtf8("border-radius:5px;background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);\n"
"background-image:url(empty.png);"));
        btn_haigis->setFlat(true);
        cemm2 = new QLabel(CalculatorDialog);
        cemm2->setObjectName(QString::fromUtf8("cemm2"));
        cemm2->setGeometry(QRect(230, 500, 230, 40));
        cemm2->setFont(font8);
        cemm2->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"color: rgb(13, 71, 161);\n"
"background-color: rgb(172, 224, 251);\n"
"background-image:url(empty.png);"));
        cemm2->setAlignment(Qt::AlignCenter);
        cemm3 = new QLabel(CalculatorDialog);
        cemm3->setObjectName(QString::fromUtf8("cemm3"));
        cemm3->setGeometry(QRect(460, 500, 230, 40));
        cemm3->setFont(font8);
        cemm3->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"color: rgb(13, 71, 161);\n"
"background-color: rgb(172, 224, 251);\n"
"background-image:url(empty.png);"));
        cemm3->setAlignment(Qt::AlignCenter);
        cemm1 = new QLabel(CalculatorDialog);
        cemm1->setObjectName(QString::fromUtf8("cemm1"));
        cemm1->setGeometry(QRect(0, 500, 230, 40));
        cemm1->setFont(font8);
        cemm1->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"color: rgb(13, 71, 161);\n"
"background-color: rgb(172, 224, 251);\n"
"background-image:url(empty.png);"));
        cemm1->setAlignment(Qt::AlignCenter);
        btn_home = new QPushButton(CalculatorDialog);
        btn_home->setObjectName(QString::fromUtf8("btn_home"));
        btn_home->setGeometry(QRect(694, 50, 100, 100));
        btn_home->setFont(font);
        btn_home->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/home.png);"));
        btn_home->setFlat(true);
        btn_measure = new QPushButton(CalculatorDialog);
        btn_measure->setObjectName(QString::fromUtf8("btn_measure"));
        btn_measure->setGeometry(QRect(694, 174, 100, 100));
        btn_measure->setFont(font);
        btn_measure->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/graph-icon.png);"));
        btn_measure->setFlat(true);
        btn_print = new QPushButton(CalculatorDialog);
        btn_print->setObjectName(QString::fromUtf8("btn_print"));
        btn_print->setGeometry(QRect(694, 416, 100, 100));
        btn_print->setFont(font);
        btn_print->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/print-icon.png);"));
        btn_print->setFlat(true);
        lbl_k1val_2 = new QLabel(CalculatorDialog);
        lbl_k1val_2->setObjectName(QString::fromUtf8("lbl_k1val_2"));
        lbl_k1val_2->setGeometry(QRect(702, 150, 85, 20));
        QFont font10;
        font10.setFamily(QString::fromUtf8("Ubuntu"));
        font10.setPointSize(11);
        font10.setBold(false);
        font10.setWeight(50);
        lbl_k1val_2->setFont(font10);
        lbl_k1val_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);background-image:url(empty.png);"));
        lbl_k1val_2->setAlignment(Qt::AlignCenter);
        lbl_k1val_3 = new QLabel(CalculatorDialog);
        lbl_k1val_3->setObjectName(QString::fromUtf8("lbl_k1val_3"));
        lbl_k1val_3->setGeometry(QRect(702, 270, 85, 20));
        lbl_k1val_3->setFont(font10);
        lbl_k1val_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);background-image:url(empty.png);"));
        lbl_k1val_3->setAlignment(Qt::AlignCenter);
        lbl_k1val_4 = new QLabel(CalculatorDialog);
        lbl_k1val_4->setObjectName(QString::fromUtf8("lbl_k1val_4"));
        lbl_k1val_4->setGeometry(QRect(703, 510, 85, 20));
        lbl_k1val_4->setFont(font10);
        lbl_k1val_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);background-image:url(empty.png);"));
        lbl_k1val_4->setAlignment(Qt::AlignCenter);
        frame_2 = new QFrame(CalculatorDialog);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(231, 160, 229, 350));
        frame_2->setStyleSheet(QString::fromUtf8("background-image: url(empty.png);\n"
"background-color: rgb(96, 125, 139);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        comboBox_lensTwo = new QComboBox(frame_2);
        comboBox_lensTwo->setObjectName(QString::fromUtf8("comboBox_lensTwo"));
        comboBox_lensTwo->setGeometry(QRect(4, 4, 220, 30));
        comboBox_lensTwo->setFont(font6);
        comboBox_lensTwo->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color:rgb(33,33,33);\n"
"background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_a1 = new QLabel(frame_2);
        lbl_a1->setObjectName(QString::fromUtf8("lbl_a1"));
        lbl_a1->setGeometry(QRect(20, 40, 80, 40));
        lbl_a1->setFont(font4);
        lbl_a1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lbl_a1->setAlignment(Qt::AlignCenter);
        lbl_sf2 = new QLabel(frame_2);
        lbl_sf2->setObjectName(QString::fromUtf8("lbl_sf2"));
        lbl_sf2->setGeometry(QRect(17, 48, 90, 30));
        lbl_sf2->setFont(font7);
        lbl_sf2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lbl_sf2->setAlignment(Qt::AlignCenter);
        lbl_acd2 = new QLabel(frame_2);
        lbl_acd2->setObjectName(QString::fromUtf8("lbl_acd2"));
        lbl_acd2->setGeometry(QRect(28, 40, 80, 50));
        lbl_acd2->setFont(font7);
        lbl_acd2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lbl_acd2->setAlignment(Qt::AlignCenter);
        lbl_aconst2 = new QLabel(frame_2);
        lbl_aconst2->setObjectName(QString::fromUtf8("lbl_aconst2"));
        lbl_aconst2->setGeometry(QRect(7, 44, 102, 40));
        lbl_aconst2->setFont(font7);
        lbl_aconst2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lbl_aconst2->setAlignment(Qt::AlignCenter);
        cdisp16 = new QLineEdit(frame_2);
        cdisp16->setObjectName(QString::fromUtf8("cdisp16"));
        cdisp16->setGeometry(QRect(120, 140, 90, 30));
        cdisp16->setFont(font7);
        cdisp16->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);"));
        cdisp16->setAlignment(Qt::AlignCenter);
        cdisp16->setReadOnly(true);
        cdisp19 = new QLineEdit(frame_2);
        cdisp19->setObjectName(QString::fromUtf8("cdisp19"));
        cdisp19->setGeometry(QRect(120, 267, 90, 30));
        cdisp19->setFont(font7);
        cdisp19->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);"));
        cdisp19->setAlignment(Qt::AlignCenter);
        cdisp19->setReadOnly(true);
        cdisp11 = new QLineEdit(frame_2);
        cdisp11->setObjectName(QString::fromUtf8("cdisp11"));
        cdisp11->setGeometry(QRect(20, 140, 90, 30));
        cdisp11->setFont(font7);
        cdisp11->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);"));
        cdisp11->setAlignment(Qt::AlignCenter);
        cdisp11->setReadOnly(true);
        cdisp13 = new QLineEdit(frame_2);
        cdisp13->setObjectName(QString::fromUtf8("cdisp13"));
        cdisp13->setGeometry(QRect(10, 210, 100, 50));
        cdisp13->setFont(font8);
        cdisp13->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"color: rgb(13, 71, 161);\n"
"background-color: rgb(172, 224, 251);\n"
""));
        cdisp13->setAlignment(Qt::AlignCenter);
        cdisp13->setReadOnly(true);
        cdisp20 = new QLineEdit(frame_2);
        cdisp20->setObjectName(QString::fromUtf8("cdisp20"));
        cdisp20->setGeometry(QRect(120, 300, 90, 30));
        cdisp20->setFont(font7);
        cdisp20->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);"));
        cdisp20->setAlignment(Qt::AlignCenter);
        cdisp20->setReadOnly(true);
        cdisp14 = new QLineEdit(frame_2);
        cdisp14->setObjectName(QString::fromUtf8("cdisp14"));
        cdisp14->setGeometry(QRect(20, 267, 90, 30));
        cdisp14->setFont(font7);
        cdisp14->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);"));
        cdisp14->setAlignment(Qt::AlignCenter);
        cdisp14->setReadOnly(true);
        lbl_iolOne2 = new QLabel(frame_2);
        lbl_iolOne2->setObjectName(QString::fromUtf8("lbl_iolOne2"));
        lbl_iolOne2->setGeometry(QRect(8, 110, 120, 20));
        lbl_iolOne2->setFont(font7);
        lbl_iolOne2->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);"));
        lbl_iolOne2->setAlignment(Qt::AlignCenter);
        lbl_refOne2 = new QLabel(frame_2);
        lbl_refOne2->setObjectName(QString::fromUtf8("lbl_refOne2"));
        lbl_refOne2->setGeometry(QRect(95, 110, 130, 20));
        lbl_refOne2->setFont(font7);
        lbl_refOne2->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);"));
        lbl_refOne2->setAlignment(Qt::AlignCenter);
        cdisp15 = new QLineEdit(frame_2);
        cdisp15->setObjectName(QString::fromUtf8("cdisp15"));
        cdisp15->setGeometry(QRect(20, 300, 90, 30));
        cdisp15->setFont(font7);
        cdisp15->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);"));
        cdisp15->setAlignment(Qt::AlignCenter);
        cdisp15->setReadOnly(true);
        cdisp12 = new QLineEdit(frame_2);
        cdisp12->setObjectName(QString::fromUtf8("cdisp12"));
        cdisp12->setGeometry(QRect(20, 173, 90, 30));
        cdisp12->setFont(font7);
        cdisp12->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);"));
        cdisp12->setAlignment(Qt::AlignCenter);
        cdisp12->setReadOnly(true);
        cdisp17 = new QLineEdit(frame_2);
        cdisp17->setObjectName(QString::fromUtf8("cdisp17"));
        cdisp17->setGeometry(QRect(120, 173, 90, 30));
        cdisp17->setFont(font7);
        cdisp17->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);"));
        cdisp17->setAlignment(Qt::AlignCenter);
        cdisp17->setReadOnly(true);
        cdisp18 = new QLineEdit(frame_2);
        cdisp18->setObjectName(QString::fromUtf8("cdisp18"));
        cdisp18->setGeometry(QRect(120, 210, 100, 50));
        cdisp18->setFont(font8);
        cdisp18->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"color: rgb(13, 71, 161);\n"
"background-color: rgb(172, 224, 251);\n"
""));
        cdisp18->setAlignment(Qt::AlignCenter);
        cdisp18->setReadOnly(true);
        frame_3 = new QFrame(CalculatorDialog);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(461, 160, 229, 350));
        frame_3->setStyleSheet(QString::fromUtf8("background-image: url(empty.png);\n"
"background-color: rgb(96, 125, 139);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        comboBox_lensThree = new QComboBox(frame_3);
        comboBox_lensThree->setObjectName(QString::fromUtf8("comboBox_lensThree"));
        comboBox_lensThree->setGeometry(QRect(4, 4, 220, 30));
        comboBox_lensThree->setFont(font6);
        comboBox_lensThree->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color:rgb(33,33,33);\n"
"background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_a2 = new QLabel(frame_3);
        lbl_a2->setObjectName(QString::fromUtf8("lbl_a2"));
        lbl_a2->setGeometry(QRect(20, 40, 80, 40));
        lbl_a2->setFont(font4);
        lbl_a2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lbl_a2->setAlignment(Qt::AlignCenter);
        lbl_sf3 = new QLabel(frame_3);
        lbl_sf3->setObjectName(QString::fromUtf8("lbl_sf3"));
        lbl_sf3->setGeometry(QRect(17, 48, 90, 30));
        lbl_sf3->setFont(font7);
        lbl_sf3->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"color:rgb(255,255,255);"));
        lbl_sf3->setAlignment(Qt::AlignCenter);
        lbl_acd3 = new QLabel(frame_3);
        lbl_acd3->setObjectName(QString::fromUtf8("lbl_acd3"));
        lbl_acd3->setGeometry(QRect(28, 40, 80, 50));
        lbl_acd3->setFont(font7);
        lbl_acd3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lbl_acd3->setAlignment(Qt::AlignCenter);
        lbl_aconst3 = new QLabel(frame_3);
        lbl_aconst3->setObjectName(QString::fromUtf8("lbl_aconst3"));
        lbl_aconst3->setGeometry(QRect(7, 44, 102, 40));
        lbl_aconst3->setFont(font7);
        lbl_aconst3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lbl_aconst3->setAlignment(Qt::AlignCenter);
        cdisp26 = new QLineEdit(frame_3);
        cdisp26->setObjectName(QString::fromUtf8("cdisp26"));
        cdisp26->setGeometry(QRect(120, 140, 90, 30));
        cdisp26->setFont(font7);
        cdisp26->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);"));
        cdisp26->setAlignment(Qt::AlignCenter);
        cdisp26->setReadOnly(true);
        cdisp29 = new QLineEdit(frame_3);
        cdisp29->setObjectName(QString::fromUtf8("cdisp29"));
        cdisp29->setGeometry(QRect(120, 267, 90, 30));
        cdisp29->setFont(font7);
        cdisp29->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);"));
        cdisp29->setAlignment(Qt::AlignCenter);
        cdisp29->setReadOnly(true);
        cdisp21 = new QLineEdit(frame_3);
        cdisp21->setObjectName(QString::fromUtf8("cdisp21"));
        cdisp21->setGeometry(QRect(20, 140, 90, 30));
        cdisp21->setFont(font7);
        cdisp21->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);"));
        cdisp21->setAlignment(Qt::AlignCenter);
        cdisp21->setReadOnly(true);
        cdisp23 = new QLineEdit(frame_3);
        cdisp23->setObjectName(QString::fromUtf8("cdisp23"));
        cdisp23->setGeometry(QRect(10, 210, 100, 50));
        cdisp23->setFont(font8);
        cdisp23->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"color: rgb(13, 71, 161);\n"
"background-color: rgb(172, 224, 251);\n"
""));
        cdisp23->setAlignment(Qt::AlignCenter);
        cdisp23->setReadOnly(true);
        cdisp30 = new QLineEdit(frame_3);
        cdisp30->setObjectName(QString::fromUtf8("cdisp30"));
        cdisp30->setGeometry(QRect(120, 300, 90, 30));
        cdisp30->setFont(font7);
        cdisp30->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);"));
        cdisp30->setAlignment(Qt::AlignCenter);
        cdisp30->setReadOnly(true);
        cdisp24 = new QLineEdit(frame_3);
        cdisp24->setObjectName(QString::fromUtf8("cdisp24"));
        cdisp24->setGeometry(QRect(20, 267, 90, 30));
        cdisp24->setFont(font7);
        cdisp24->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);"));
        cdisp24->setAlignment(Qt::AlignCenter);
        cdisp24->setReadOnly(true);
        lbl_iolOne3 = new QLabel(frame_3);
        lbl_iolOne3->setObjectName(QString::fromUtf8("lbl_iolOne3"));
        lbl_iolOne3->setGeometry(QRect(8, 110, 120, 20));
        lbl_iolOne3->setFont(font7);
        lbl_iolOne3->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);"));
        lbl_iolOne3->setAlignment(Qt::AlignCenter);
        lbl_refOne3 = new QLabel(frame_3);
        lbl_refOne3->setObjectName(QString::fromUtf8("lbl_refOne3"));
        lbl_refOne3->setGeometry(QRect(95, 110, 130, 20));
        lbl_refOne3->setFont(font7);
        lbl_refOne3->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);"));
        lbl_refOne3->setAlignment(Qt::AlignCenter);
        cdisp25 = new QLineEdit(frame_3);
        cdisp25->setObjectName(QString::fromUtf8("cdisp25"));
        cdisp25->setGeometry(QRect(20, 300, 90, 30));
        cdisp25->setFont(font7);
        cdisp25->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);"));
        cdisp25->setAlignment(Qt::AlignCenter);
        cdisp25->setReadOnly(true);
        cdisp22 = new QLineEdit(frame_3);
        cdisp22->setObjectName(QString::fromUtf8("cdisp22"));
        cdisp22->setGeometry(QRect(20, 173, 90, 30));
        cdisp22->setFont(font7);
        cdisp22->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);"));
        cdisp22->setAlignment(Qt::AlignCenter);
        cdisp22->setReadOnly(true);
        cdisp27 = new QLineEdit(frame_3);
        cdisp27->setObjectName(QString::fromUtf8("cdisp27"));
        cdisp27->setGeometry(QRect(120, 173, 90, 30));
        cdisp27->setFont(font7);
        cdisp27->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"color:rgb(33,33,33);"));
        cdisp27->setAlignment(Qt::AlignCenter);
        cdisp27->setReadOnly(true);
        cdisp28 = new QLineEdit(frame_3);
        cdisp28->setObjectName(QString::fromUtf8("cdisp28"));
        cdisp28->setGeometry(QRect(120, 210, 100, 50));
        cdisp28->setFont(font8);
        cdisp28->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"color: rgb(13, 71, 161);\n"
"background-color: rgb(172, 224, 251);\n"
""));
        cdisp28->setAlignment(Qt::AlignCenter);
        cdisp28->setReadOnly(true);
        snackbar = new QLabel(CalculatorDialog);
        snackbar->setObjectName(QString::fromUtf8("snackbar"));
        snackbar->setGeometry(QRect(-2, 0, 805, 40));
        snackbar->setStyleSheet(QString::fromUtf8("border-image: url(:/images/alert-red.png);\n"
"background-image:url(empty.png);color:rgb(255,255,255);"));
        snackbar->setIndent(10);
        lbl_k1ValEdit1 = new QLineEdit(CalculatorDialog);
        lbl_k1ValEdit1->setObjectName(QString::fromUtf8("lbl_k1ValEdit1"));
        lbl_k1ValEdit1->setGeometry(QRect(146, 64, 80, 60));
        QFont font11;
        font11.setPointSize(18);
        lbl_k1ValEdit1->setFont(font11);
        lbl_k1ValEdit1->setAutoFillBackground(false);
        lbl_k1ValEdit1->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-mid.png);\n"
"background-image:url(empty.png);"));
        lbl_k1ValEdit1->setAlignment(Qt::AlignCenter);
        lbl_k1ValEdit1->setReadOnly(true);
        lbl_k2ValEdit = new QLineEdit(CalculatorDialog);
        lbl_k2ValEdit->setObjectName(QString::fromUtf8("lbl_k2ValEdit"));
        lbl_k2ValEdit->setGeometry(QRect(240, 64, 80, 60));
        lbl_k2ValEdit->setFont(font11);
        lbl_k2ValEdit->setAutoFillBackground(false);
        lbl_k2ValEdit->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-mid.png);\n"
"background-image:url(empty.png);"));
        lbl_k2ValEdit->setAlignment(Qt::AlignCenter);
        lbl_k2ValEdit->setReadOnly(false);
        lbl_k1ValEdit = new QLineEdit(CalculatorDialog);
        lbl_k1ValEdit->setObjectName(QString::fromUtf8("lbl_k1ValEdit"));
        lbl_k1ValEdit->setGeometry(QRect(146, 64, 80, 60));
        lbl_k1ValEdit->setFont(font11);
        lbl_k1ValEdit->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-mid.png);\n"
"background-image:url(empty.png);"));
        lbl_k1ValEdit->setAlignment(Qt::AlignCenter);
        lbl_k2ValEdit2 = new QLineEdit(CalculatorDialog);
        lbl_k2ValEdit2->setObjectName(QString::fromUtf8("lbl_k2ValEdit2"));
        lbl_k2ValEdit2->setGeometry(QRect(240, 64, 80, 60));
        lbl_k2ValEdit2->setFont(font11);
        lbl_k2ValEdit2->setAutoFillBackground(false);
        lbl_k2ValEdit2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-mid.png);\n"
"background-image:url(empty.png);"));
        lbl_k2ValEdit2->setAlignment(Qt::AlignCenter);
        lbl_k2ValEdit2->setReadOnly(false);
        lbl_rxValEdit2 = new QLineEdit(CalculatorDialog);
        lbl_rxValEdit2->setObjectName(QString::fromUtf8("lbl_rxValEdit2"));
        lbl_rxValEdit2->setGeometry(QRect(333, 64, 80, 60));
        lbl_rxValEdit2->setFont(font2);
        lbl_rxValEdit2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-mid.png);\n"
"background-image:url(empty.png);"));
        lbl_rxValEdit2->setAlignment(Qt::AlignCenter);
        lbl_kValEdit2 = new QLineEdit(CalculatorDialog);
        lbl_kValEdit2->setObjectName(QString::fromUtf8("lbl_kValEdit2"));
        lbl_kValEdit2->setGeometry(QRect(430, 64, 125, 90));
        lbl_kValEdit2->setFont(font1);
        lbl_kValEdit2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-mid.png);\n"
"background-image:url(empty.png);"));
        lbl_kValEdit2->setAlignment(Qt::AlignCenter);
        lbl_kValEdit2->setReadOnly(true);
        lbl_alValEdit2 = new QLineEdit(CalculatorDialog);
        lbl_alValEdit2->setObjectName(QString::fromUtf8("lbl_alValEdit2"));
        lbl_alValEdit2->setGeometry(QRect(563, 64, 125, 90));
        lbl_alValEdit2->setFont(font5);
        lbl_alValEdit2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-mid.png);\n"
"background-image:url(empty.png);"));
        lbl_alValEdit2->setAlignment(Qt::AlignCenter);
        lbl_alValEdit2->setReadOnly(false);
        lbl_time = new QLabel(CalculatorDialog);
        lbl_time->setObjectName(QString::fromUtf8("lbl_time"));
        lbl_time->setGeometry(QRect(680, 0, 120, 40));
        QFont font12;
        font12.setPointSize(9);
        lbl_time->setFont(font12);
        lbl_time->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        lbl_time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        btn_warning1 = new QPushButton(CalculatorDialog);
        btn_warning1->setObjectName(QString::fromUtf8("btn_warning1"));
        btn_warning1->setGeometry(QRect(190, 164, 30, 30));
        btn_warning1->setFont(font9);
        btn_warning1->setFocusPolicy(Qt::NoFocus);
        btn_warning1->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"border-image: url(:/images/icons/ic_warning_black_96dp.png);\n"
"color:rgb(255,255,255);\n"
"background-image:url(empty.png);"));
        btn_warning1->setFlat(true);
        btn_warning2 = new QPushButton(CalculatorDialog);
        btn_warning2->setObjectName(QString::fromUtf8("btn_warning2"));
        btn_warning2->setGeometry(QRect(420, 164, 30, 30));
        btn_warning2->setFont(font9);
        btn_warning2->setFocusPolicy(Qt::NoFocus);
        btn_warning2->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"border-image: url(:/images/icons/ic_warning_black_96dp.png);\n"
"color:rgb(255,255,255);\n"
"background-image:url(empty.png);"));
        btn_warning2->setFlat(true);
        btn_warning3 = new QPushButton(CalculatorDialog);
        btn_warning3->setObjectName(QString::fromUtf8("btn_warning3"));
        btn_warning3->setGeometry(QRect(650, 164, 30, 30));
        btn_warning3->setFont(font9);
        btn_warning3->setFocusPolicy(Qt::NoFocus);
        btn_warning3->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"border-image: url(:/images/icons/ic_warning_black_96dp.png);\n"
"color:rgb(255,255,255);\n"
"background-image:url(empty.png);"));
        btn_warning3->setFlat(true);
        lineEdit_sf12 = new QLineEdit(CalculatorDialog);
        lineEdit_sf12->setObjectName(QString::fromUtf8("lineEdit_sf12"));
        lineEdit_sf12->setGeometry(QRect(110, 200, 95, 50));
        lineEdit_sf12->setFont(font2);
        lineEdit_sf12->setAutoFillBackground(false);
        lineEdit_sf12->setStyleSheet(QString::fromUtf8("border-image: url(empty.png);\n"
"background-image:url(empty.png);\n"
"background-color:rgb(255,255,255);\n"
"color:rgb(0,0,0);"));
        lineEdit_sf12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_sf1 = new QLineEdit(CalculatorDialog);
        lineEdit_sf1->setObjectName(QString::fromUtf8("lineEdit_sf1"));
        lineEdit_sf1->setGeometry(QRect(110, 200, 95, 50));
        lineEdit_sf1->setFont(font2);
        lineEdit_sf1->setAutoFillBackground(false);
        lineEdit_sf1->setStyleSheet(QString::fromUtf8("border-image: url(empty.png);\n"
"background-image:url(empty.png);\n"
"background-color:rgb(255,255,255);\n"
"color:rgb(0,0,0);"));
        lineEdit_sf1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_A02 = new QLineEdit(CalculatorDialog);
        lineEdit_A02->setObjectName(QString::fromUtf8("lineEdit_A02"));
        lineEdit_A02->setGeometry(QRect(110, 200, 95, 50));
        lineEdit_A02->setFont(font2);
        lineEdit_A02->setAutoFillBackground(false);
        lineEdit_A02->setStyleSheet(QString::fromUtf8("border-image: url(empty.png);\n"
"background-image:url(empty.png);\n"
"background-color:rgb(255,255,255);\n"
"color:rgb(0,0,0);"));
        lineEdit_A02->setAlignment(Qt::AlignCenter);
        lineEdit_acd1 = new QLineEdit(CalculatorDialog);
        lineEdit_acd1->setObjectName(QString::fromUtf8("lineEdit_acd1"));
        lineEdit_acd1->setGeometry(QRect(111, 200, 95, 50));
        lineEdit_acd1->setFont(font2);
        lineEdit_acd1->setAutoFillBackground(false);
        lineEdit_acd1->setStyleSheet(QString::fromUtf8("border-image: url(empty.png);\n"
"background-image:url(empty.png);\n"
"background-color:rgb(255,255,255);\n"
"color:rgb(0,0,0);"));
        lineEdit_acd1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_aconst12 = new QLineEdit(CalculatorDialog);
        lineEdit_aconst12->setObjectName(QString::fromUtf8("lineEdit_aconst12"));
        lineEdit_aconst12->setGeometry(QRect(110, 200, 95, 50));
        lineEdit_aconst12->setFont(font2);
        lineEdit_aconst12->setAutoFillBackground(false);
        lineEdit_aconst12->setStyleSheet(QString::fromUtf8("border-image: url(empty.png);\n"
"background-image:url(empty.png);\n"
"background-color:rgb(255,255,255);\n"
"color:rgb(0,0,0);"));
        lineEdit_aconst12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_acd12 = new QLineEdit(CalculatorDialog);
        lineEdit_acd12->setObjectName(QString::fromUtf8("lineEdit_acd12"));
        lineEdit_acd12->setGeometry(QRect(110, 200, 95, 50));
        lineEdit_acd12->setFont(font2);
        lineEdit_acd12->setAutoFillBackground(false);
        lineEdit_acd12->setStyleSheet(QString::fromUtf8("border-image: url(empty.png);\n"
"background-image:url(empty.png);\n"
"background-color:rgb(255,255,255);\n"
"color:rgb(0,0,0);"));
        lineEdit_acd12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_A0 = new QLineEdit(CalculatorDialog);
        lineEdit_A0->setObjectName(QString::fromUtf8("lineEdit_A0"));
        lineEdit_A0->setGeometry(QRect(110, 200, 95, 50));
        lineEdit_A0->setFont(font2);
        lineEdit_A0->setAutoFillBackground(false);
        lineEdit_A0->setStyleSheet(QString::fromUtf8("border-image: url(empty.png);\n"
"background-image:url(empty.png);\n"
"background-color:rgb(255,255,255);\n"
"color:rgb(0,0,0);"));
        lineEdit_A0->setAlignment(Qt::AlignCenter);
        lineEdit_aconst1 = new QLineEdit(CalculatorDialog);
        lineEdit_aconst1->setObjectName(QString::fromUtf8("lineEdit_aconst1"));
        lineEdit_aconst1->setGeometry(QRect(110, 200, 95, 50));
        lineEdit_aconst1->setFont(font2);
        lineEdit_aconst1->setAutoFillBackground(false);
        lineEdit_aconst1->setStyleSheet(QString::fromUtf8("border-image: url(empty.png);\n"
"background-image:url(empty.png);\n"
"background-color:rgb(255,255,255);\n"
"color:rgb(0,0,0);"));
        lineEdit_aconst1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_acd2 = new QLineEdit(CalculatorDialog);
        lineEdit_acd2->setObjectName(QString::fromUtf8("lineEdit_acd2"));
        lineEdit_acd2->setGeometry(QRect(351, 200, 95, 50));
        lineEdit_acd2->setFont(font2);
        lineEdit_acd2->setStyleSheet(QString::fromUtf8("border-image: url(empty.png);\n"
"background-image:url(empty.png);\n"
""));
        lineEdit_acd2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_aconst2 = new QLineEdit(CalculatorDialog);
        lineEdit_aconst2->setObjectName(QString::fromUtf8("lineEdit_aconst2"));
        lineEdit_aconst2->setGeometry(QRect(350, 200, 95, 50));
        lineEdit_aconst2->setFont(font2);
        lineEdit_aconst2->setStyleSheet(QString::fromUtf8("border-image: url(empty.png);\n"
"background-image:url(empty.png);\n"
""));
        lineEdit_aconst2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_A12 = new QLineEdit(CalculatorDialog);
        lineEdit_A12->setObjectName(QString::fromUtf8("lineEdit_A12"));
        lineEdit_A12->setGeometry(QRect(350, 200, 95, 50));
        lineEdit_A12->setFont(font2);
        lineEdit_A12->setStyleSheet(QString::fromUtf8("border-image: url(empty.png);\n"
"background-image:url(empty.png);\n"
""));
        lineEdit_A12->setAlignment(Qt::AlignCenter);
        lineEdit_acd22 = new QLineEdit(CalculatorDialog);
        lineEdit_acd22->setObjectName(QString::fromUtf8("lineEdit_acd22"));
        lineEdit_acd22->setGeometry(QRect(350, 200, 95, 50));
        lineEdit_acd22->setFont(font2);
        lineEdit_acd22->setStyleSheet(QString::fromUtf8("border-image: url(empty.png);\n"
"background-image:url(empty.png);\n"
""));
        lineEdit_acd22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_aconst22 = new QLineEdit(CalculatorDialog);
        lineEdit_aconst22->setObjectName(QString::fromUtf8("lineEdit_aconst22"));
        lineEdit_aconst22->setGeometry(QRect(350, 200, 95, 50));
        lineEdit_aconst22->setFont(font2);
        lineEdit_aconst22->setStyleSheet(QString::fromUtf8("border-image: url(empty.png);\n"
"background-image:url(empty.png);\n"
""));
        lineEdit_aconst22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_A1 = new QLineEdit(CalculatorDialog);
        lineEdit_A1->setObjectName(QString::fromUtf8("lineEdit_A1"));
        lineEdit_A1->setGeometry(QRect(350, 200, 95, 50));
        lineEdit_A1->setFont(font2);
        lineEdit_A1->setStyleSheet(QString::fromUtf8("border-image: url(empty.png);\n"
"background-image:url(empty.png);\n"
""));
        lineEdit_A1->setAlignment(Qt::AlignCenter);
        lineEdit_sf22 = new QLineEdit(CalculatorDialog);
        lineEdit_sf22->setObjectName(QString::fromUtf8("lineEdit_sf22"));
        lineEdit_sf22->setGeometry(QRect(350, 200, 95, 50));
        lineEdit_sf22->setFont(font2);
        lineEdit_sf22->setStyleSheet(QString::fromUtf8("border-image: url(empty.png);\n"
"background-image:url(empty.png);\n"
""));
        lineEdit_sf22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_sf2 = new QLineEdit(CalculatorDialog);
        lineEdit_sf2->setObjectName(QString::fromUtf8("lineEdit_sf2"));
        lineEdit_sf2->setGeometry(QRect(350, 200, 95, 50));
        lineEdit_sf2->setFont(font2);
        lineEdit_sf2->setStyleSheet(QString::fromUtf8("border-image: url(empty.png);\n"
"background-image:url(empty.png);\n"
""));
        lineEdit_sf2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_A22 = new QLineEdit(CalculatorDialog);
        lineEdit_A22->setObjectName(QString::fromUtf8("lineEdit_A22"));
        lineEdit_A22->setGeometry(QRect(580, 200, 95, 50));
        lineEdit_A22->setFont(font2);
        lineEdit_A22->setStyleSheet(QString::fromUtf8("border-image: url(empty.png);\n"
"background-image:url(empty.png);"));
        lineEdit_A22->setAlignment(Qt::AlignCenter);
        lineEdit_sf3 = new QLineEdit(CalculatorDialog);
        lineEdit_sf3->setObjectName(QString::fromUtf8("lineEdit_sf3"));
        lineEdit_sf3->setGeometry(QRect(580, 200, 95, 50));
        lineEdit_sf3->setFont(font2);
        lineEdit_sf3->setStyleSheet(QString::fromUtf8("border-image: url(empty.png);\n"
"background-image:url(empty.png);"));
        lineEdit_sf3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_acd32 = new QLineEdit(CalculatorDialog);
        lineEdit_acd32->setObjectName(QString::fromUtf8("lineEdit_acd32"));
        lineEdit_acd32->setGeometry(QRect(580, 200, 95, 50));
        lineEdit_acd32->setFont(font2);
        lineEdit_acd32->setStyleSheet(QString::fromUtf8("border-image: url(empty.png);\n"
"background-image:url(empty.png);"));
        lineEdit_acd32->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_A2 = new QLineEdit(CalculatorDialog);
        lineEdit_A2->setObjectName(QString::fromUtf8("lineEdit_A2"));
        lineEdit_A2->setGeometry(QRect(580, 200, 95, 50));
        lineEdit_A2->setFont(font2);
        lineEdit_A2->setStyleSheet(QString::fromUtf8("border-image: url(empty.png);\n"
"background-image:url(empty.png);"));
        lineEdit_A2->setAlignment(Qt::AlignCenter);
        lineEdit_aconst32 = new QLineEdit(CalculatorDialog);
        lineEdit_aconst32->setObjectName(QString::fromUtf8("lineEdit_aconst32"));
        lineEdit_aconst32->setGeometry(QRect(580, 200, 95, 50));
        lineEdit_aconst32->setFont(font2);
        lineEdit_aconst32->setStyleSheet(QString::fromUtf8("border-image: url(empty.png);\n"
"background-image:url(empty.png);"));
        lineEdit_aconst32->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_acd3 = new QLineEdit(CalculatorDialog);
        lineEdit_acd3->setObjectName(QString::fromUtf8("lineEdit_acd3"));
        lineEdit_acd3->setGeometry(QRect(581, 200, 95, 50));
        lineEdit_acd3->setFont(font2);
        lineEdit_acd3->setStyleSheet(QString::fromUtf8("border-image: url(empty.png);\n"
"background-image:url(empty.png);"));
        lineEdit_acd3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_aconst3 = new QLineEdit(CalculatorDialog);
        lineEdit_aconst3->setObjectName(QString::fromUtf8("lineEdit_aconst3"));
        lineEdit_aconst3->setGeometry(QRect(580, 200, 95, 50));
        lineEdit_aconst3->setFont(font2);
        lineEdit_aconst3->setStyleSheet(QString::fromUtf8("border-image: url(empty.png);\n"
"background-image:url(empty.png);"));
        lineEdit_aconst3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_sf32 = new QLineEdit(CalculatorDialog);
        lineEdit_sf32->setObjectName(QString::fromUtf8("lineEdit_sf32"));
        lineEdit_sf32->setGeometry(QRect(580, 200, 95, 50));
        lineEdit_sf32->setFont(font2);
        lineEdit_sf32->setStyleSheet(QString::fromUtf8("border-image: url(empty.png);\n"
"background-image:url(empty.png);"));
        lineEdit_sf32->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        btn_newPatient = new QPushButton(CalculatorDialog);
        btn_newPatient->setObjectName(QString::fromUtf8("btn_newPatient"));
        btn_newPatient->setGeometry(QRect(694, 300, 100, 100));
        btn_newPatient->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/patient-icon.png);"));
        btn_newPatient->setFlat(true);
        lbl_k1val_5 = new QLabel(CalculatorDialog);
        lbl_k1val_5->setObjectName(QString::fromUtf8("lbl_k1val_5"));
        lbl_k1val_5->setGeometry(QRect(700, 390, 85, 20));
        lbl_k1val_5->setFont(font10);
        lbl_k1val_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);background-image:url(empty.png);"));
        lbl_k1val_5->setAlignment(Qt::AlignCenter);
        frame_3->raise();
        frame->raise();
        lineEdit_acd32->raise();
        lineEdit_acd12->raise();
        lineEdit_acd3->raise();
        frame_2->raise();
        lineEdit_acd1->raise();
        lineEdit_acd22->raise();
        lineEdit_acd2->raise();
        lineEdit_sf32->raise();
        lbl_time->raise();
        lbl_alValEdit2->raise();
        lbl_kValEdit2->raise();
        lbl_rxValEdit2->raise();
        lbl_k2ValEdit2->raise();
        lbl_k1ValEdit1->raise();
        lbl_k1ValEdit->raise();
        lbl_patName->raise();
        lbl_patID->raise();
        lineEdit_docName->raise();
        lbl_docName->raise();
        lineEdit_patName->raise();
        lineEdit_patID->raise();
        btn_eye->raise();
        lbl_rxval->raise();
        lbl_k1val->raise();
        lbl_alval->raise();
        lbl_kval->raise();
        lbl_k2val->raise();
        btn_hofferq->raise();
        btn_holladay->raise();
        btn_srkt->raise();
        btn_srkii->raise();
        btn_haigis->raise();
        cemm2->raise();
        cemm3->raise();
        cemm1->raise();
        btn_home->raise();
        btn_measure->raise();
        btn_print->raise();
        lbl_k1val_2->raise();
        lbl_k1val_3->raise();
        lbl_k1val_4->raise();
        snackbar->raise();
        lbl_rxValEdit->raise();
        lbl_kValEdit->raise();
        lbl_alValEdit->raise();
        lbl_k2ValEdit->raise();
        btn_warning1->raise();
        btn_warning2->raise();
        btn_warning3->raise();
        lineEdit_sf12->raise();
        lineEdit_sf1->raise();
        lineEdit_A02->raise();
        lineEdit_aconst12->raise();
        lineEdit_A0->raise();
        lineEdit_aconst1->raise();
        lineEdit_A12->raise();
        lineEdit_aconst22->raise();
        lineEdit_A1->raise();
        lineEdit_sf22->raise();
        lineEdit_sf2->raise();
        lineEdit_A22->raise();
        lineEdit_sf3->raise();
        lineEdit_A2->raise();
        lineEdit_aconst32->raise();
        lineEdit_aconst2->raise();
        lbl_k1val_5->raise();
        btn_newPatient->raise();
        lineEdit_aconst3->raise();

        retranslateUi(CalculatorDialog);

        QMetaObject::connectSlotsByName(CalculatorDialog);
    } // setupUi

    void retranslateUi(QDialog *CalculatorDialog)
    {
        CalculatorDialog->setWindowTitle(QCoreApplication::translate("CalculatorDialog", "Dialog", nullptr));
        lbl_patName->setText(QCoreApplication::translate("CalculatorDialog", "Name", nullptr));
        lbl_patID->setText(QCoreApplication::translate("CalculatorDialog", "Patient ID", nullptr));
        lbl_docName->setText(QCoreApplication::translate("CalculatorDialog", "Doctor", nullptr));
        btn_eye->setText(QCoreApplication::translate("CalculatorDialog", "OS", nullptr));
        lbl_kValEdit->setText(QCoreApplication::translate("CalculatorDialog", "45.00", nullptr));
        lbl_rxValEdit->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        lbl_rxval->setText(QCoreApplication::translate("CalculatorDialog", "Rx (mm)", nullptr));
        lbl_k1val->setText(QCoreApplication::translate("CalculatorDialog", "K1(D)", nullptr));
        lbl_alval->setText(QCoreApplication::translate("CalculatorDialog", "AL  (mm)", nullptr));
        lbl_kval->setText(QCoreApplication::translate("CalculatorDialog", "K  (D)", nullptr));
        lbl_alValEdit->setText(QCoreApplication::translate("CalculatorDialog", "23.00", nullptr));
        lbl_k2val->setText(QCoreApplication::translate("CalculatorDialog", "K2(D)", nullptr));
        lbl_a0->setText(QCoreApplication::translate("CalculatorDialog", "a0 =", nullptr));
        lbl_sf1->setText(QCoreApplication::translate("CalculatorDialog", "SF =", nullptr));
        lbl_acd1->setText(QCoreApplication::translate("CalculatorDialog", "ACD =", nullptr));
        lbl_aconst1->setText(QCoreApplication::translate("CalculatorDialog", "ACONST =", nullptr));
        cdisp6->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        cdisp9->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        cdisp1->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        cdisp3->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        cdisp10->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        cdisp4->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        lbl_iolOne->setText(QCoreApplication::translate("CalculatorDialog", "IOL", nullptr));
        lbl_refOne->setText(QCoreApplication::translate("CalculatorDialog", "REF", nullptr));
        cdisp5->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        cdisp2->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        cdisp7->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        cdisp8->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        btn_hofferq->setText(QCoreApplication::translate("CalculatorDialog", "Hoffer Q", nullptr));
        btn_holladay->setText(QCoreApplication::translate("CalculatorDialog", "Holladay", nullptr));
        btn_srkt->setText(QCoreApplication::translate("CalculatorDialog", "SRK T", nullptr));
        btn_srkii->setText(QCoreApplication::translate("CalculatorDialog", "SRK II", nullptr));
        btn_haigis->setText(QCoreApplication::translate("CalculatorDialog", "Haigis", nullptr));
        cemm2->setText(QCoreApplication::translate("CalculatorDialog", "EMM=0.00", nullptr));
        cemm3->setText(QCoreApplication::translate("CalculatorDialog", "EMM=0.00", nullptr));
        cemm1->setText(QCoreApplication::translate("CalculatorDialog", "EMM=0.00", nullptr));
        btn_home->setText(QString());
        btn_measure->setText(QString());
        btn_print->setText(QString());
        lbl_k1val_2->setText(QCoreApplication::translate("CalculatorDialog", "Home", nullptr));
        lbl_k1val_3->setText(QCoreApplication::translate("CalculatorDialog", "Measure", nullptr));
        lbl_k1val_4->setText(QCoreApplication::translate("CalculatorDialog", "Print", nullptr));
        lbl_a1->setText(QCoreApplication::translate("CalculatorDialog", "a0 =", nullptr));
        lbl_sf2->setText(QCoreApplication::translate("CalculatorDialog", "SF =", nullptr));
        lbl_acd2->setText(QCoreApplication::translate("CalculatorDialog", "ACD =", nullptr));
        lbl_aconst2->setText(QCoreApplication::translate("CalculatorDialog", "ACONST =", nullptr));
        cdisp16->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        cdisp19->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        cdisp11->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        cdisp13->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        cdisp20->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        cdisp14->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        lbl_iolOne2->setText(QCoreApplication::translate("CalculatorDialog", "IOL", nullptr));
        lbl_refOne2->setText(QCoreApplication::translate("CalculatorDialog", "REF", nullptr));
        cdisp15->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        cdisp12->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        cdisp17->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        cdisp18->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        lbl_a2->setText(QCoreApplication::translate("CalculatorDialog", "a0 =", nullptr));
        lbl_sf3->setText(QCoreApplication::translate("CalculatorDialog", "SF =", nullptr));
        lbl_acd3->setText(QCoreApplication::translate("CalculatorDialog", "ACD =", nullptr));
        lbl_aconst3->setText(QCoreApplication::translate("CalculatorDialog", "ACONST =", nullptr));
        cdisp26->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        cdisp29->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        cdisp21->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        cdisp23->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        cdisp30->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        cdisp24->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        lbl_iolOne3->setText(QCoreApplication::translate("CalculatorDialog", "IOL", nullptr));
        lbl_refOne3->setText(QCoreApplication::translate("CalculatorDialog", "REF", nullptr));
        cdisp25->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        cdisp22->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        cdisp27->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        cdisp28->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        snackbar->setText(QString());
        lbl_k1ValEdit1->setText(QCoreApplication::translate("CalculatorDialog", "45.00", nullptr));
        lbl_k2ValEdit->setText(QCoreApplication::translate("CalculatorDialog", "45.00", nullptr));
        lbl_k1ValEdit->setText(QCoreApplication::translate("CalculatorDialog", "45.00", nullptr));
        lbl_k2ValEdit2->setText(QCoreApplication::translate("CalculatorDialog", "45.00", nullptr));
        lbl_rxValEdit2->setText(QCoreApplication::translate("CalculatorDialog", "0.00", nullptr));
        lbl_kValEdit2->setText(QCoreApplication::translate("CalculatorDialog", "45.00", nullptr));
        lbl_alValEdit2->setText(QCoreApplication::translate("CalculatorDialog", "23.00", nullptr));
        lbl_time->setText(QCoreApplication::translate("CalculatorDialog", "10:09", nullptr));
        btn_warning1->setText(QString());
        btn_warning2->setText(QString());
        btn_warning3->setText(QString());
        lineEdit_sf12->setText(QCoreApplication::translate("CalculatorDialog", "2", nullptr));
        lineEdit_sf1->setText(QCoreApplication::translate("CalculatorDialog", "2", nullptr));
        lineEdit_A02->setText(QCoreApplication::translate("CalculatorDialog", "1.28", nullptr));
        lineEdit_acd1->setText(QCoreApplication::translate("CalculatorDialog", "4.97", nullptr));
        lineEdit_aconst12->setText(QCoreApplication::translate("CalculatorDialog", "118", nullptr));
        lineEdit_acd12->setText(QCoreApplication::translate("CalculatorDialog", "4.97", nullptr));
        lineEdit_A0->setText(QCoreApplication::translate("CalculatorDialog", "1.28", nullptr));
        lineEdit_aconst1->setText(QCoreApplication::translate("CalculatorDialog", "118", nullptr));
        lineEdit_acd2->setText(QCoreApplication::translate("CalculatorDialog", "4.97", nullptr));
        lineEdit_aconst2->setText(QCoreApplication::translate("CalculatorDialog", "118", nullptr));
        lineEdit_A12->setText(QCoreApplication::translate("CalculatorDialog", "1.28", nullptr));
        lineEdit_acd22->setText(QCoreApplication::translate("CalculatorDialog", "4.97", nullptr));
        lineEdit_aconst22->setText(QCoreApplication::translate("CalculatorDialog", "118", nullptr));
        lineEdit_A1->setText(QCoreApplication::translate("CalculatorDialog", "1.28", nullptr));
        lineEdit_sf22->setText(QCoreApplication::translate("CalculatorDialog", "2", nullptr));
        lineEdit_sf2->setText(QCoreApplication::translate("CalculatorDialog", "2", nullptr));
        lineEdit_A22->setText(QCoreApplication::translate("CalculatorDialog", "1.28", nullptr));
        lineEdit_sf3->setText(QCoreApplication::translate("CalculatorDialog", "118", nullptr));
        lineEdit_acd32->setText(QCoreApplication::translate("CalculatorDialog", "4.97", nullptr));
        lineEdit_A2->setText(QCoreApplication::translate("CalculatorDialog", "1.28", nullptr));
        lineEdit_aconst32->setText(QCoreApplication::translate("CalculatorDialog", "118", nullptr));
        lineEdit_acd3->setText(QCoreApplication::translate("CalculatorDialog", "4.97", nullptr));
        lineEdit_aconst3->setText(QCoreApplication::translate("CalculatorDialog", "118", nullptr));
        lineEdit_sf32->setText(QCoreApplication::translate("CalculatorDialog", "118", nullptr));
        btn_newPatient->setText(QString());
        lbl_k1val_5->setText(QCoreApplication::translate("CalculatorDialog", "New Patient", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalculatorDialog: public Ui_CalculatorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATORDIALOG_H
