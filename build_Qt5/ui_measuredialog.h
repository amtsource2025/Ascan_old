/********************************************************************************
** Form generated from reading UI file 'measuredialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEASUREDIALOG_H
#define UI_MEASUREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Services/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MeasureDialog
{
public:
    QPushButton *btn_lensType;
    QPushButton *btn_opMode;
    QFrame *frame;
    QFrame *frame_graphOne;
    QLabel *lbl_alOne;
    QPushButton *btn_graphOne;
    QFrame *frame_graphTwo;
    QPushButton *btn_graphTwo;
    QLabel *lbl_alTwo;
    QFrame *frame_graphThree;
    QPushButton *btn_graphThree;
    QLabel *lbl_alThree;
    QFrame *frame_graphFour;
    QPushButton *btn_graphFour;
    QLabel *lbl_alFour;
    QFrame *frame_graphFive;
    QPushButton *btn_graphFive;
    QLabel *lbl_alFive;
    QFrame *frame_graphSix;
    QPushButton *btn_graphSix;
    QLabel *lbl_alSix;
    QFrame *frame_graphSeven;
    QLabel *lbl_alSeven;
    QPushButton *btn_graphSeven;
    QFrame *frame_graphEight;
    QLabel *lbl_alEight;
    QPushButton *btn_graphEight;
    QFrame *frame_graphNine;
    QLabel *lbl_alNine;
    QPushButton *btn_graphNine;
    QFrame *frame_graphTen;
    QLabel *lbl_alTen;
    QPushButton *btn_graphTen;
    QLabel *lbl_devOne;
    QLabel *lbl_devTen;
    QLabel *lbl_devEight;
    QLabel *lbl_devFive;
    QLabel *lbl_devTwo;
    QLabel *lbl_devNine;
    QLabel *lbl_devSeven;
    QLabel *lbl_devFour;
    QLabel *lbl_devSix;
    QLabel *lbl_devThree;
    QLineEdit *lineEdit_patName;
    QLineEdit *lineEdit_docName;
    QLabel *lineEdit_lensType;
    QLabel *lbl_opMode;
    QPushButton *btn_calculator;
    QPushButton *btn_home;
    QLabel *lbl_home;
    QLabel *lbl_calculator;
    QCustomPlot *graphicsView;
    QLabel *lbl_time;
    QPushButton *marker_cornea_2;
    QPushButton *btn_eye;
    QPushButton *butDelete;
    QFrame *wm_plt;
    QPushButton *btn_startMeasure;
    QPushButton *marker_cornea;
    QPushButton *marker_lensOne;
    QPushButton *marker_lensTwo;
    QPushButton *marker_retina;
    QPushButton *btn_play;
    QFrame *frame_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_avgAl;
    QLineEdit *lineEdit_sd;
    QLineEdit *lineEdit_acd;
    QLineEdit *lineEdit_vit;
    QLineEdit *lineEdit_lt;
    QLineEdit *lineEdit_al;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *lbl_avgAl;
    QLabel *lbl_sd;
    QLabel *lbl_avgAl_2;
    QLabel *lbl_avgAl_5;
    QLabel *lbl_avgAl_3;
    QLabel *lbl_avgAl_4;

    void setupUi(QDialog *MeasureDialog)
    {
        if (MeasureDialog->objectName().isEmpty())
            MeasureDialog->setObjectName(QString::fromUtf8("MeasureDialog"));
        MeasureDialog->resize(1280, 720);
        MeasureDialog->setStyleSheet(QString::fromUtf8("background-image: url(:/images/5.png);"));
        btn_lensType = new QPushButton(MeasureDialog);
        btn_lensType->setObjectName(QString::fromUtf8("btn_lensType"));
        btn_lensType->setGeometry(QRect(319, 69, 95, 95));
        btn_lensType->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"border-image: url(:/images/aphakic-icon.png);"));
        btn_lensType->setFlat(true);
        btn_opMode = new QPushButton(MeasureDialog);
        btn_opMode->setObjectName(QString::fromUtf8("btn_opMode"));
        btn_opMode->setGeometry(QRect(650, 60, 101, 101));
        btn_opMode->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"border-image: url(:/images/contact.png);"));
        btn_opMode->setFlat(true);
        frame = new QFrame(MeasureDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(-10, 599, 1301, 121));
        frame->setStyleSheet(QString::fromUtf8("border-image: url(:/images/card.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_graphOne = new QFrame(frame);
        frame_graphOne->setObjectName(QString::fromUtf8("frame_graphOne"));
        frame_graphOne->setGeometry(QRect(30, 10, 90, 60));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        frame_graphOne->setFont(font);
        frame_graphOne->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);border-image:url(:/images/empty.png);"));
        frame_graphOne->setFrameShape(QFrame::StyledPanel);
        frame_graphOne->setFrameShadow(QFrame::Raised);
        lbl_alOne = new QLabel(frame_graphOne);
        lbl_alOne->setObjectName(QString::fromUtf8("lbl_alOne"));
        lbl_alOne->setGeometry(QRect(10, 10, 67, 31));
        lbl_alOne->setFont(font);
        lbl_alOne->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        lbl_alOne->setAlignment(Qt::AlignCenter);
        btn_graphOne = new QPushButton(frame_graphOne);
        btn_graphOne->setObjectName(QString::fromUtf8("btn_graphOne"));
        btn_graphOne->setGeometry(QRect(0, 0, 90, 60));
        btn_graphOne->setFont(font);
        btn_graphOne->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        btn_graphOne->setFlat(true);
        frame_graphTwo = new QFrame(frame);
        frame_graphTwo->setObjectName(QString::fromUtf8("frame_graphTwo"));
        frame_graphTwo->setGeometry(QRect(160, 10, 90, 60));
        frame_graphTwo->setFont(font);
        frame_graphTwo->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);border-image:url(:/images/empty.png);"));
        frame_graphTwo->setFrameShape(QFrame::StyledPanel);
        frame_graphTwo->setFrameShadow(QFrame::Raised);
        btn_graphTwo = new QPushButton(frame_graphTwo);
        btn_graphTwo->setObjectName(QString::fromUtf8("btn_graphTwo"));
        btn_graphTwo->setGeometry(QRect(0, 0, 90, 60));
        btn_graphTwo->setFont(font);
        btn_graphTwo->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        btn_graphTwo->setFlat(true);
        lbl_alTwo = new QLabel(frame_graphTwo);
        lbl_alTwo->setObjectName(QString::fromUtf8("lbl_alTwo"));
        lbl_alTwo->setGeometry(QRect(10, 10, 67, 31));
        lbl_alTwo->setFont(font);
        lbl_alTwo->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        lbl_alTwo->setAlignment(Qt::AlignCenter);
        lbl_alTwo->raise();
        btn_graphTwo->raise();
        frame_graphThree = new QFrame(frame);
        frame_graphThree->setObjectName(QString::fromUtf8("frame_graphThree"));
        frame_graphThree->setGeometry(QRect(290, 10, 90, 60));
        frame_graphThree->setFont(font);
        frame_graphThree->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);border-image:url(:/images/empty.png);"));
        frame_graphThree->setFrameShape(QFrame::StyledPanel);
        frame_graphThree->setFrameShadow(QFrame::Raised);
        btn_graphThree = new QPushButton(frame_graphThree);
        btn_graphThree->setObjectName(QString::fromUtf8("btn_graphThree"));
        btn_graphThree->setGeometry(QRect(0, 0, 90, 60));
        btn_graphThree->setFont(font);
        btn_graphThree->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        btn_graphThree->setFlat(true);
        lbl_alThree = new QLabel(frame_graphThree);
        lbl_alThree->setObjectName(QString::fromUtf8("lbl_alThree"));
        lbl_alThree->setGeometry(QRect(10, 10, 67, 31));
        lbl_alThree->setFont(font);
        lbl_alThree->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        lbl_alThree->setAlignment(Qt::AlignCenter);
        lbl_alThree->raise();
        btn_graphThree->raise();
        frame_graphFour = new QFrame(frame);
        frame_graphFour->setObjectName(QString::fromUtf8("frame_graphFour"));
        frame_graphFour->setGeometry(QRect(420, 10, 90, 60));
        frame_graphFour->setFont(font);
        frame_graphFour->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);border-image:url(:/images/empty.png);"));
        frame_graphFour->setFrameShape(QFrame::StyledPanel);
        frame_graphFour->setFrameShadow(QFrame::Raised);
        btn_graphFour = new QPushButton(frame_graphFour);
        btn_graphFour->setObjectName(QString::fromUtf8("btn_graphFour"));
        btn_graphFour->setGeometry(QRect(0, 0, 91, 61));
        btn_graphFour->setFont(font);
        btn_graphFour->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        btn_graphFour->setFlat(true);
        lbl_alFour = new QLabel(frame_graphFour);
        lbl_alFour->setObjectName(QString::fromUtf8("lbl_alFour"));
        lbl_alFour->setGeometry(QRect(10, 10, 67, 31));
        lbl_alFour->setFont(font);
        lbl_alFour->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        lbl_alFour->setAlignment(Qt::AlignCenter);
        lbl_alFour->raise();
        btn_graphFour->raise();
        frame_graphFive = new QFrame(frame);
        frame_graphFive->setObjectName(QString::fromUtf8("frame_graphFive"));
        frame_graphFive->setGeometry(QRect(540, 10, 90, 60));
        frame_graphFive->setFont(font);
        frame_graphFive->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);border-image:url(:/images/empty.png);"));
        frame_graphFive->setFrameShape(QFrame::StyledPanel);
        frame_graphFive->setFrameShadow(QFrame::Raised);
        btn_graphFive = new QPushButton(frame_graphFive);
        btn_graphFive->setObjectName(QString::fromUtf8("btn_graphFive"));
        btn_graphFive->setGeometry(QRect(0, 0, 90, 60));
        btn_graphFive->setFont(font);
        btn_graphFive->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        btn_graphFive->setFlat(true);
        lbl_alFive = new QLabel(frame_graphFive);
        lbl_alFive->setObjectName(QString::fromUtf8("lbl_alFive"));
        lbl_alFive->setGeometry(QRect(10, 10, 67, 31));
        lbl_alFive->setFont(font);
        lbl_alFive->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        lbl_alFive->setAlignment(Qt::AlignCenter);
        lbl_alFive->raise();
        btn_graphFive->raise();
        frame_graphSix = new QFrame(frame);
        frame_graphSix->setObjectName(QString::fromUtf8("frame_graphSix"));
        frame_graphSix->setGeometry(QRect(660, 10, 90, 60));
        frame_graphSix->setFont(font);
        frame_graphSix->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);border-image:url(:/images/empty.png);"));
        frame_graphSix->setFrameShape(QFrame::StyledPanel);
        frame_graphSix->setFrameShadow(QFrame::Raised);
        btn_graphSix = new QPushButton(frame_graphSix);
        btn_graphSix->setObjectName(QString::fromUtf8("btn_graphSix"));
        btn_graphSix->setGeometry(QRect(0, 0, 90, 60));
        btn_graphSix->setFont(font);
        btn_graphSix->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        btn_graphSix->setFlat(true);
        lbl_alSix = new QLabel(frame_graphSix);
        lbl_alSix->setObjectName(QString::fromUtf8("lbl_alSix"));
        lbl_alSix->setGeometry(QRect(10, 10, 67, 31));
        lbl_alSix->setFont(font);
        lbl_alSix->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        lbl_alSix->setAlignment(Qt::AlignCenter);
        lbl_alSix->raise();
        btn_graphSix->raise();
        frame_graphSeven = new QFrame(frame);
        frame_graphSeven->setObjectName(QString::fromUtf8("frame_graphSeven"));
        frame_graphSeven->setGeometry(QRect(780, 10, 90, 60));
        frame_graphSeven->setFont(font);
        frame_graphSeven->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);border-image:url(:/images/empty.png);"));
        frame_graphSeven->setFrameShape(QFrame::StyledPanel);
        frame_graphSeven->setFrameShadow(QFrame::Raised);
        lbl_alSeven = new QLabel(frame_graphSeven);
        lbl_alSeven->setObjectName(QString::fromUtf8("lbl_alSeven"));
        lbl_alSeven->setGeometry(QRect(10, 10, 67, 31));
        lbl_alSeven->setFont(font);
        lbl_alSeven->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        lbl_alSeven->setAlignment(Qt::AlignCenter);
        btn_graphSeven = new QPushButton(frame_graphSeven);
        btn_graphSeven->setObjectName(QString::fromUtf8("btn_graphSeven"));
        btn_graphSeven->setGeometry(QRect(0, 0, 90, 60));
        btn_graphSeven->setFont(font);
        btn_graphSeven->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        btn_graphSeven->setFlat(true);
        frame_graphEight = new QFrame(frame);
        frame_graphEight->setObjectName(QString::fromUtf8("frame_graphEight"));
        frame_graphEight->setGeometry(QRect(910, 10, 90, 60));
        frame_graphEight->setFont(font);
        frame_graphEight->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);border-image:url(:/images/empty.png);"));
        frame_graphEight->setFrameShape(QFrame::StyledPanel);
        frame_graphEight->setFrameShadow(QFrame::Raised);
        lbl_alEight = new QLabel(frame_graphEight);
        lbl_alEight->setObjectName(QString::fromUtf8("lbl_alEight"));
        lbl_alEight->setGeometry(QRect(10, 10, 67, 31));
        lbl_alEight->setFont(font);
        lbl_alEight->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        lbl_alEight->setAlignment(Qt::AlignCenter);
        btn_graphEight = new QPushButton(frame_graphEight);
        btn_graphEight->setObjectName(QString::fromUtf8("btn_graphEight"));
        btn_graphEight->setGeometry(QRect(0, 0, 90, 60));
        btn_graphEight->setFont(font);
        btn_graphEight->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        btn_graphEight->setFlat(true);
        frame_graphNine = new QFrame(frame);
        frame_graphNine->setObjectName(QString::fromUtf8("frame_graphNine"));
        frame_graphNine->setGeometry(QRect(1030, 10, 90, 60));
        frame_graphNine->setFont(font);
        frame_graphNine->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);border-image:url(:/images/empty.png);"));
        frame_graphNine->setFrameShape(QFrame::StyledPanel);
        frame_graphNine->setFrameShadow(QFrame::Raised);
        lbl_alNine = new QLabel(frame_graphNine);
        lbl_alNine->setObjectName(QString::fromUtf8("lbl_alNine"));
        lbl_alNine->setGeometry(QRect(10, 10, 67, 31));
        lbl_alNine->setFont(font);
        lbl_alNine->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        lbl_alNine->setAlignment(Qt::AlignCenter);
        btn_graphNine = new QPushButton(frame_graphNine);
        btn_graphNine->setObjectName(QString::fromUtf8("btn_graphNine"));
        btn_graphNine->setGeometry(QRect(0, 0, 90, 60));
        btn_graphNine->setFont(font);
        btn_graphNine->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        btn_graphNine->setFlat(true);
        frame_graphTen = new QFrame(frame);
        frame_graphTen->setObjectName(QString::fromUtf8("frame_graphTen"));
        frame_graphTen->setGeometry(QRect(1150, 10, 90, 60));
        frame_graphTen->setFont(font);
        frame_graphTen->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);border-image:url(:/images/empty.png);"));
        frame_graphTen->setFrameShape(QFrame::StyledPanel);
        frame_graphTen->setFrameShadow(QFrame::Raised);
        lbl_alTen = new QLabel(frame_graphTen);
        lbl_alTen->setObjectName(QString::fromUtf8("lbl_alTen"));
        lbl_alTen->setGeometry(QRect(10, 10, 67, 31));
        lbl_alTen->setFont(font);
        lbl_alTen->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        lbl_alTen->setAlignment(Qt::AlignCenter);
        btn_graphTen = new QPushButton(frame_graphTen);
        btn_graphTen->setObjectName(QString::fromUtf8("btn_graphTen"));
        btn_graphTen->setGeometry(QRect(0, 0, 90, 60));
        btn_graphTen->setFont(font);
        btn_graphTen->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        btn_graphTen->setFlat(true);
        lbl_devOne = new QLabel(frame);
        lbl_devOne->setObjectName(QString::fromUtf8("lbl_devOne"));
        lbl_devOne->setGeometry(QRect(60, 81, 30, 17));
        lbl_devOne->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        lbl_devOne->setAlignment(Qt::AlignCenter);
        lbl_devTen = new QLabel(frame);
        lbl_devTen->setObjectName(QString::fromUtf8("lbl_devTen"));
        lbl_devTen->setGeometry(QRect(1180, 81, 30, 17));
        lbl_devTen->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        lbl_devTen->setAlignment(Qt::AlignCenter);
        lbl_devEight = new QLabel(frame);
        lbl_devEight->setObjectName(QString::fromUtf8("lbl_devEight"));
        lbl_devEight->setGeometry(QRect(940, 81, 30, 17));
        lbl_devEight->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        lbl_devEight->setAlignment(Qt::AlignCenter);
        lbl_devFive = new QLabel(frame);
        lbl_devFive->setObjectName(QString::fromUtf8("lbl_devFive"));
        lbl_devFive->setGeometry(QRect(570, 81, 30, 17));
        lbl_devFive->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        lbl_devFive->setAlignment(Qt::AlignCenter);
        lbl_devTwo = new QLabel(frame);
        lbl_devTwo->setObjectName(QString::fromUtf8("lbl_devTwo"));
        lbl_devTwo->setGeometry(QRect(190, 81, 30, 17));
        lbl_devTwo->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        lbl_devTwo->setAlignment(Qt::AlignCenter);
        lbl_devNine = new QLabel(frame);
        lbl_devNine->setObjectName(QString::fromUtf8("lbl_devNine"));
        lbl_devNine->setGeometry(QRect(1060, 81, 30, 17));
        lbl_devNine->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        lbl_devNine->setAlignment(Qt::AlignCenter);
        lbl_devSeven = new QLabel(frame);
        lbl_devSeven->setObjectName(QString::fromUtf8("lbl_devSeven"));
        lbl_devSeven->setGeometry(QRect(810, 81, 30, 17));
        lbl_devSeven->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        lbl_devSeven->setAlignment(Qt::AlignCenter);
        lbl_devFour = new QLabel(frame);
        lbl_devFour->setObjectName(QString::fromUtf8("lbl_devFour"));
        lbl_devFour->setGeometry(QRect(450, 81, 30, 17));
        lbl_devFour->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        lbl_devFour->setAlignment(Qt::AlignCenter);
        lbl_devSix = new QLabel(frame);
        lbl_devSix->setObjectName(QString::fromUtf8("lbl_devSix"));
        lbl_devSix->setGeometry(QRect(690, 81, 30, 17));
        lbl_devSix->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        lbl_devSix->setAlignment(Qt::AlignCenter);
        lbl_devThree = new QLabel(frame);
        lbl_devThree->setObjectName(QString::fromUtf8("lbl_devThree"));
        lbl_devThree->setGeometry(QRect(320, 81, 30, 17));
        lbl_devThree->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        lbl_devThree->setAlignment(Qt::AlignCenter);
        lbl_devOne->raise();
        lbl_devTen->raise();
        lbl_devEight->raise();
        lbl_devFive->raise();
        lbl_devTwo->raise();
        lbl_devNine->raise();
        lbl_devSeven->raise();
        lbl_devFour->raise();
        lbl_devSix->raise();
        lbl_devThree->raise();
        frame_graphTen->raise();
        frame_graphEight->raise();
        frame_graphTwo->raise();
        frame_graphFour->raise();
        frame_graphOne->raise();
        frame_graphNine->raise();
        frame_graphSix->raise();
        frame_graphFive->raise();
        frame_graphSeven->raise();
        frame_graphThree->raise();
        lineEdit_patName = new QLineEdit(MeasureDialog);
        lineEdit_patName->setObjectName(QString::fromUtf8("lineEdit_patName"));
        lineEdit_patName->setGeometry(QRect(270, 10, 321, 41));
        QFont font1;
        font1.setPointSize(18);
        lineEdit_patName->setFont(font1);
        lineEdit_patName->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(0,0,0);"));
        lineEdit_docName = new QLineEdit(MeasureDialog);
        lineEdit_docName->setObjectName(QString::fromUtf8("lineEdit_docName"));
        lineEdit_docName->setGeometry(QRect(640, 10, 321, 41));
        lineEdit_docName->setFont(font1);
        lineEdit_docName->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);"));
        lineEdit_lensType = new QLabel(MeasureDialog);
        lineEdit_lensType->setObjectName(QString::fromUtf8("lineEdit_lensType"));
        lineEdit_lensType->setGeometry(QRect(430, 80, 201, 61));
        QFont font2;
        font2.setPointSize(20);
        lineEdit_lensType->setFont(font2);
        lineEdit_lensType->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        lineEdit_lensType->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lbl_opMode = new QLabel(MeasureDialog);
        lbl_opMode->setObjectName(QString::fromUtf8("lbl_opMode"));
        lbl_opMode->setGeometry(QRect(760, 80, 141, 61));
        lbl_opMode->setFont(font2);
        lbl_opMode->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        lbl_opMode->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        btn_calculator = new QPushButton(MeasureDialog);
        btn_calculator->setObjectName(QString::fromUtf8("btn_calculator"));
        btn_calculator->setGeometry(QRect(1180, 60, 91, 111));
        btn_calculator->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"border-image: url(:/images/calculator-icon.png);"));
        btn_calculator->setFlat(true);
        btn_home = new QPushButton(MeasureDialog);
        btn_home->setObjectName(QString::fromUtf8("btn_home"));
        btn_home->setGeometry(QRect(1069, 60, 101, 111));
        btn_home->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"border-image: url(:/images/home.png);"));
        btn_home->setFlat(true);
        lbl_home = new QLabel(MeasureDialog);
        lbl_home->setObjectName(QString::fromUtf8("lbl_home"));
        lbl_home->setGeometry(QRect(1080, 40, 80, 16));
        QFont font3;
        font3.setPointSize(13);
        lbl_home->setFont(font3);
        lbl_home->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        lbl_home->setAlignment(Qt::AlignCenter);
        lbl_calculator = new QLabel(MeasureDialog);
        lbl_calculator->setObjectName(QString::fromUtf8("lbl_calculator"));
        lbl_calculator->setGeometry(QRect(1180, 40, 90, 16));
        lbl_calculator->setFont(font3);
        lbl_calculator->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        lbl_calculator->setAlignment(Qt::AlignCenter);
        graphicsView = new QCustomPlot(MeasureDialog);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 170, 861, 401));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);\n"
"background-color: rgb(0, 0, 0);"));
        lbl_time = new QLabel(MeasureDialog);
        lbl_time->setObjectName(QString::fromUtf8("lbl_time"));
        lbl_time->setGeometry(QRect(1150, 10, 120, 21));
        QFont font4;
        font4.setPointSize(14);
        lbl_time->setFont(font4);
        lbl_time->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        lbl_time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        marker_cornea_2 = new QPushButton(MeasureDialog);
        marker_cornea_2->setObjectName(QString::fromUtf8("marker_cornea_2"));
        marker_cornea_2->setGeometry(QRect(0, 570, 861, 20));
        marker_cornea_2->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/scale.png);\n"
""));
        marker_cornea_2->setFlat(true);
        btn_eye = new QPushButton(MeasureDialog);
        btn_eye->setObjectName(QString::fromUtf8("btn_eye"));
        btn_eye->setEnabled(true);
        btn_eye->setGeometry(QRect(0, 0, 141, 81));
        QFont font5;
        font5.setPointSize(30);
        btn_eye->setFont(font5);
        btn_eye->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"border-image: url(:/images/btn-small.png);\n"
""));
        btn_eye->setCheckable(false);
        btn_eye->setFlat(true);
        butDelete = new QPushButton(MeasureDialog);
        butDelete->setObjectName(QString::fromUtf8("butDelete"));
        butDelete->setGeometry(QRect(990, 90, 81, 81));
        butDelete->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/Delete_btn.png);"));
        wm_plt = new QFrame(MeasureDialog);
        wm_plt->setObjectName(QString::fromUtf8("wm_plt"));
        wm_plt->setGeometry(QRect(0, 170, 861, 401));
        wm_plt->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"background-image:url(:/images/empty.png);"));
        wm_plt->setFrameShape(QFrame::StyledPanel);
        wm_plt->setFrameShadow(QFrame::Raised);
        btn_startMeasure = new QPushButton(wm_plt);
        btn_startMeasure->setObjectName(QString::fromUtf8("btn_startMeasure"));
        btn_startMeasure->setGeometry(QRect(0, 0, 861, 401));
        btn_startMeasure->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image:url(:/images/empty.png);"));
        btn_startMeasure->setFlat(true);
        marker_cornea = new QPushButton(wm_plt);
        marker_cornea->setObjectName(QString::fromUtf8("marker_cornea"));
        marker_cornea->setGeometry(QRect(10, 10, 20, 20));
        marker_cornea->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/marker.png);\n"
""));
        marker_cornea->setFlat(true);
        marker_lensOne = new QPushButton(wm_plt);
        marker_lensOne->setObjectName(QString::fromUtf8("marker_lensOne"));
        marker_lensOne->setGeometry(QRect(80, 10, 20, 20));
        marker_lensOne->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/marker.png);\n"
""));
        marker_lensOne->setFlat(true);
        marker_lensTwo = new QPushButton(wm_plt);
        marker_lensTwo->setObjectName(QString::fromUtf8("marker_lensTwo"));
        marker_lensTwo->setGeometry(QRect(160, 10, 20, 20));
        marker_lensTwo->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/marker.png);\n"
""));
        marker_lensTwo->setFlat(true);
        marker_retina = new QPushButton(wm_plt);
        marker_retina->setObjectName(QString::fromUtf8("marker_retina"));
        marker_retina->setGeometry(QRect(490, 10, 20, 20));
        marker_retina->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/marker.png);\n"
""));
        marker_retina->setFlat(true);
        btn_play = new QPushButton(wm_plt);
        btn_play->setObjectName(QString::fromUtf8("btn_play"));
        btn_play->setGeometry(QRect(400, 150, 100, 100));
        btn_play->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"border-image: url(:/images/icons/ic_play_circle_outline_white_48dp.png);"));
        btn_play->setFlat(true);
        frame_2 = new QFrame(MeasureDialog);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(860, 170, 421, 411));
        frame_2->setStyleSheet(QString::fromUtf8("background-color:rgb(0,0,0);background-image:url(:/images/empty.png);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(frame_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(200, 10, 191, 381));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_avgAl = new QLineEdit(layoutWidget);
        lineEdit_avgAl->setObjectName(QString::fromUtf8("lineEdit_avgAl"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_avgAl->sizePolicy().hasHeightForWidth());
        lineEdit_avgAl->setSizePolicy(sizePolicy);
        QFont font6;
        font6.setPointSize(24);
        font6.setBold(true);
        lineEdit_avgAl->setFont(font6);
        lineEdit_avgAl->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);\n"
"border-radius:5px;"));
        lineEdit_avgAl->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lineEdit_avgAl);

        lineEdit_sd = new QLineEdit(layoutWidget);
        lineEdit_sd->setObjectName(QString::fromUtf8("lineEdit_sd"));
        sizePolicy.setHeightForWidth(lineEdit_sd->sizePolicy().hasHeightForWidth());
        lineEdit_sd->setSizePolicy(sizePolicy);
        QFont font7;
        font7.setPointSize(18);
        font7.setBold(true);
        lineEdit_sd->setFont(font7);
        lineEdit_sd->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);\n"
"border-radius:5px;"));
        lineEdit_sd->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lineEdit_sd);

        lineEdit_acd = new QLineEdit(layoutWidget);
        lineEdit_acd->setObjectName(QString::fromUtf8("lineEdit_acd"));
        sizePolicy.setHeightForWidth(lineEdit_acd->sizePolicy().hasHeightForWidth());
        lineEdit_acd->setSizePolicy(sizePolicy);
        lineEdit_acd->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);\n"
"border-radius:5px;"));
        lineEdit_acd->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lineEdit_acd);

        lineEdit_vit = new QLineEdit(layoutWidget);
        lineEdit_vit->setObjectName(QString::fromUtf8("lineEdit_vit"));
        sizePolicy.setHeightForWidth(lineEdit_vit->sizePolicy().hasHeightForWidth());
        lineEdit_vit->setSizePolicy(sizePolicy);
        lineEdit_vit->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);\n"
"border-radius:5px;"));
        lineEdit_vit->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lineEdit_vit);

        lineEdit_lt = new QLineEdit(layoutWidget);
        lineEdit_lt->setObjectName(QString::fromUtf8("lineEdit_lt"));
        sizePolicy.setHeightForWidth(lineEdit_lt->sizePolicy().hasHeightForWidth());
        lineEdit_lt->setSizePolicy(sizePolicy);
        lineEdit_lt->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);\n"
"border-radius:5px;"));
        lineEdit_lt->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lineEdit_lt);

        lineEdit_al = new QLineEdit(layoutWidget);
        lineEdit_al->setObjectName(QString::fromUtf8("lineEdit_al"));
        sizePolicy.setHeightForWidth(lineEdit_al->sizePolicy().hasHeightForWidth());
        lineEdit_al->setSizePolicy(sizePolicy);
        lineEdit_al->setFont(font2);
        lineEdit_al->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(21,21,21);\n"
"border-radius:5px;"));
        lineEdit_al->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lineEdit_al);

        layoutWidget1 = new QWidget(frame_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 10, 161, 381));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lbl_avgAl = new QLabel(layoutWidget1);
        lbl_avgAl->setObjectName(QString::fromUtf8("lbl_avgAl"));
        lbl_avgAl->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"color:rgb(255,255,255);\n"
"background-color: #2196F3;border-radius:5px;"));
        lbl_avgAl->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lbl_avgAl);

        lbl_sd = new QLabel(layoutWidget1);
        lbl_sd->setObjectName(QString::fromUtf8("lbl_sd"));
        lbl_sd->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"color:rgb(255,255,255);\n"
"background-color: #2196F3;border-radius:5px;"));
        lbl_sd->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lbl_sd);

        lbl_avgAl_2 = new QLabel(layoutWidget1);
        lbl_avgAl_2->setObjectName(QString::fromUtf8("lbl_avgAl_2"));
        lbl_avgAl_2->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"color:rgb(255,255,255);\n"
"background-color: #2196F3;border-radius:5px;"));
        lbl_avgAl_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lbl_avgAl_2);

        lbl_avgAl_5 = new QLabel(layoutWidget1);
        lbl_avgAl_5->setObjectName(QString::fromUtf8("lbl_avgAl_5"));
        lbl_avgAl_5->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"color:rgb(255,255,255);\n"
"background-color: #2196F3;border-radius:5px;"));
        lbl_avgAl_5->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lbl_avgAl_5);

        lbl_avgAl_3 = new QLabel(layoutWidget1);
        lbl_avgAl_3->setObjectName(QString::fromUtf8("lbl_avgAl_3"));
        lbl_avgAl_3->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"color:rgb(255,255,255);\n"
"background-color: #2196F3;border-radius:5px;"));
        lbl_avgAl_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lbl_avgAl_3);

        lbl_avgAl_4 = new QLabel(layoutWidget1);
        lbl_avgAl_4->setObjectName(QString::fromUtf8("lbl_avgAl_4"));
        lbl_avgAl_4->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);\n"
"color:rgb(255,255,255);\n"
"background-color: #2196F3;border-radius:5px;"));
        lbl_avgAl_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lbl_avgAl_4);

        graphicsView->raise();
        btn_lensType->raise();
        btn_opMode->raise();
        frame->raise();
        lineEdit_patName->raise();
        lineEdit_docName->raise();
        lineEdit_lensType->raise();
        lbl_opMode->raise();
        btn_calculator->raise();
        btn_home->raise();
        lbl_home->raise();
        lbl_calculator->raise();
        lbl_time->raise();
        marker_cornea_2->raise();
        btn_eye->raise();
        butDelete->raise();
        wm_plt->raise();
        frame_2->raise();

        retranslateUi(MeasureDialog);

        QMetaObject::connectSlotsByName(MeasureDialog);
    } // setupUi

    void retranslateUi(QDialog *MeasureDialog)
    {
        MeasureDialog->setWindowTitle(QCoreApplication::translate("MeasureDialog", "Dialog", nullptr));
        btn_lensType->setText(QString());
        btn_opMode->setText(QString());
        lbl_alOne->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        btn_graphOne->setText(QString());
        btn_graphTwo->setText(QString());
        lbl_alTwo->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        btn_graphThree->setText(QString());
        lbl_alThree->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        btn_graphFour->setText(QString());
        lbl_alFour->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        btn_graphFive->setText(QString());
        lbl_alFive->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        btn_graphSix->setText(QString());
        lbl_alSix->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_alSeven->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        btn_graphSeven->setText(QString());
        lbl_alEight->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        btn_graphEight->setText(QString());
        lbl_alNine->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        btn_graphNine->setText(QString());
        lbl_alTen->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        btn_graphTen->setText(QString());
        lbl_devOne->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_devTen->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_devEight->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_devFive->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_devTwo->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_devNine->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_devSeven->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_devFour->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_devSix->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_devThree->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lineEdit_lensType->setText(QCoreApplication::translate("MeasureDialog", "Dense Cataract", nullptr));
        lbl_opMode->setText(QCoreApplication::translate("MeasureDialog", "Contact", nullptr));
        btn_calculator->setText(QString());
        btn_home->setText(QString());
        lbl_home->setText(QCoreApplication::translate("MeasureDialog", "Home", nullptr));
        lbl_calculator->setText(QCoreApplication::translate("MeasureDialog", "Calculator", nullptr));
        lbl_time->setText(QCoreApplication::translate("MeasureDialog", "10:09", nullptr));
        marker_cornea_2->setText(QString());
        btn_eye->setText(QCoreApplication::translate("MeasureDialog", "OS", nullptr));
        butDelete->setText(QString());
        btn_startMeasure->setText(QString());
        marker_cornea->setText(QString());
        marker_lensOne->setText(QString());
        marker_lensTwo->setText(QString());
        marker_retina->setText(QString());
        btn_play->setText(QString());
        lbl_avgAl->setText(QCoreApplication::translate("MeasureDialog", "AVG AL:", nullptr));
        lbl_sd->setText(QCoreApplication::translate("MeasureDialog", "SD:", nullptr));
        lbl_avgAl_2->setText(QCoreApplication::translate("MeasureDialog", "ACD:", nullptr));
        lbl_avgAl_5->setText(QCoreApplication::translate("MeasureDialog", "VIT:", nullptr));
        lbl_avgAl_3->setText(QCoreApplication::translate("MeasureDialog", "LT:", nullptr));
        lbl_avgAl_4->setText(QCoreApplication::translate("MeasureDialog", "AL:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MeasureDialog: public Ui_MeasureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEASUREDIALOG_H
