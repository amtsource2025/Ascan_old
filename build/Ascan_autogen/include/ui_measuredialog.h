/********************************************************************************
** Form generated from reading UI file 'measuredialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
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
#include "Services/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MeasureDialog
{
public:
    QPushButton *btn_lensType;
    QPushButton *btn_opMode;
    QFrame *frame;
    QLabel *lbl_alOne;
    QLabel *lbl_devOne;
    QLabel *lbl_alTwo;
    QLabel *lbl_devTwo;
    QLabel *lbl_alThree;
    QLabel *lbl_devThree;
    QLabel *lbl_devFour;
    QLabel *lbl_alFour;
    QLabel *lbl_devFive;
    QLabel *lbl_alFive;
    QLabel *lbl_devSix;
    QLabel *lbl_alSix;
    QLabel *lbl_devSeven;
    QLabel *lbl_alSeven;
    QLabel *lbl_alEight;
    QLabel *lbl_devEight;
    QLabel *lbl_devNine;
    QLabel *lbl_alNine;
    QLabel *lbl_alTen;
    QLabel *lbl_devTen;
    QFrame *frame_graphOne;
    QFrame *frame_graphTwo;
    QFrame *frame_graphThree;
    QFrame *frame_graphFour;
    QFrame *frame_graphFive;
    QFrame *frame_graphSix;
    QFrame *frame_graphSeven;
    QFrame *frame_graphEight;
    QFrame *frame_graphNine;
    QFrame *frame_graphTen;
    QPushButton *btn_graphOne;
    QPushButton *btn_graphTwo;
    QPushButton *btn_graphThree;
    QPushButton *btn_graphFour;
    QPushButton *btn_graphFive;
    QPushButton *btn_graphSix;
    QPushButton *btn_graphSeven;
    QPushButton *btn_graphEight;
    QPushButton *btn_graphNine;
    QPushButton *btn_graphTen;
    QLineEdit *lineEdit_patName;
    QLineEdit *lineEdit_docName;
    QLabel *lineEdit_lensType;
    QLabel *lbl_opMode;
    QPushButton *btn_calculator;
    QPushButton *btn_home;
    QLabel *lbl_home;
    QLabel *lbl_calculator;
    QPushButton *btn_play;
    QPushButton *btn_startMeasure;
    QFrame *wm_plt;
    QCustomPlot *graphicsView;
    QLabel *lbl_time;
    QPushButton *marker_cornea;
    QPushButton *marker_lensOne;
    QPushButton *marker_lensTwo;
    QPushButton *marker_retina;
    QPushButton *marker_cornea_2;
    QFrame *frame_2;
    QLineEdit *lineEdit_avgAl;
    QLineEdit *lineEdit_vit;
    QLineEdit *lineEdit_acd;
    QLabel *lbl_avgAl;
    QLineEdit *lineEdit_lt;
    QLabel *lbl_avgAl_4;
    QLabel *lbl_avgAl_2;
    QLineEdit *lineEdit_sd;
    QLabel *lbl_avgAl_5;
    QLabel *lbl_sd;
    QLabel *lbl_avgAl_3;
    QLineEdit *lineEdit_al;
    QPushButton *btn_eye;
    QPushButton *butDelete;

    void setupUi(QDialog *MeasureDialog)
    {
        if (MeasureDialog->objectName().isEmpty())
            MeasureDialog->setObjectName(QString::fromUtf8("MeasureDialog"));
        MeasureDialog->resize(800, 600);
        MeasureDialog->setStyleSheet(QString::fromUtf8("background-image: url(:/images/5.png);"));
        btn_lensType = new QPushButton(MeasureDialog);
        btn_lensType->setObjectName(QString::fromUtf8("btn_lensType"));
        btn_lensType->setGeometry(QRect(120, 60, 70, 70));
        btn_lensType->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"border-image: url(:/images/aphakic-icon.png);"));
        btn_lensType->setFlat(true);
        btn_opMode = new QPushButton(MeasureDialog);
        btn_opMode->setObjectName(QString::fromUtf8("btn_opMode"));
        btn_opMode->setGeometry(QRect(390, 60, 70, 70));
        btn_opMode->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"border-image: url(:/images/contact.png);"));
        btn_opMode->setFlat(true);
        frame = new QFrame(MeasureDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(-5, 500, 808, 100));
        frame->setStyleSheet(QString::fromUtf8("border-image: url(:/images/card.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        lbl_alOne = new QLabel(frame);
        lbl_alOne->setObjectName(QString::fromUtf8("lbl_alOne"));
        lbl_alOne->setGeometry(QRect(10, 10, 67, 31));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        lbl_alOne->setFont(font);
        lbl_alOne->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_alOne->setAlignment(Qt::AlignCenter);
        lbl_devOne = new QLabel(frame);
        lbl_devOne->setObjectName(QString::fromUtf8("lbl_devOne"));
        lbl_devOne->setGeometry(QRect(10, 56, 67, 31));
        lbl_devOne->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_devOne->setAlignment(Qt::AlignCenter);
        lbl_alTwo = new QLabel(frame);
        lbl_alTwo->setObjectName(QString::fromUtf8("lbl_alTwo"));
        lbl_alTwo->setGeometry(QRect(90, 10, 67, 31));
        lbl_alTwo->setFont(font);
        lbl_alTwo->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_alTwo->setAlignment(Qt::AlignCenter);
        lbl_devTwo = new QLabel(frame);
        lbl_devTwo->setObjectName(QString::fromUtf8("lbl_devTwo"));
        lbl_devTwo->setGeometry(QRect(90, 56, 67, 31));
        lbl_devTwo->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_devTwo->setAlignment(Qt::AlignCenter);
        lbl_alThree = new QLabel(frame);
        lbl_alThree->setObjectName(QString::fromUtf8("lbl_alThree"));
        lbl_alThree->setGeometry(QRect(170, 10, 67, 31));
        lbl_alThree->setFont(font);
        lbl_alThree->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_alThree->setAlignment(Qt::AlignCenter);
        lbl_devThree = new QLabel(frame);
        lbl_devThree->setObjectName(QString::fromUtf8("lbl_devThree"));
        lbl_devThree->setGeometry(QRect(170, 56, 67, 31));
        lbl_devThree->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_devThree->setAlignment(Qt::AlignCenter);
        lbl_devFour = new QLabel(frame);
        lbl_devFour->setObjectName(QString::fromUtf8("lbl_devFour"));
        lbl_devFour->setGeometry(QRect(250, 56, 67, 31));
        lbl_devFour->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_devFour->setAlignment(Qt::AlignCenter);
        lbl_alFour = new QLabel(frame);
        lbl_alFour->setObjectName(QString::fromUtf8("lbl_alFour"));
        lbl_alFour->setGeometry(QRect(250, 10, 67, 31));
        lbl_alFour->setFont(font);
        lbl_alFour->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_alFour->setAlignment(Qt::AlignCenter);
        lbl_devFive = new QLabel(frame);
        lbl_devFive->setObjectName(QString::fromUtf8("lbl_devFive"));
        lbl_devFive->setGeometry(QRect(330, 56, 67, 31));
        lbl_devFive->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_devFive->setAlignment(Qt::AlignCenter);
        lbl_alFive = new QLabel(frame);
        lbl_alFive->setObjectName(QString::fromUtf8("lbl_alFive"));
        lbl_alFive->setGeometry(QRect(330, 10, 67, 31));
        lbl_alFive->setFont(font);
        lbl_alFive->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_alFive->setAlignment(Qt::AlignCenter);
        lbl_devSix = new QLabel(frame);
        lbl_devSix->setObjectName(QString::fromUtf8("lbl_devSix"));
        lbl_devSix->setGeometry(QRect(410, 56, 67, 31));
        lbl_devSix->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_devSix->setAlignment(Qt::AlignCenter);
        lbl_alSix = new QLabel(frame);
        lbl_alSix->setObjectName(QString::fromUtf8("lbl_alSix"));
        lbl_alSix->setGeometry(QRect(410, 10, 67, 31));
        lbl_alSix->setFont(font);
        lbl_alSix->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_alSix->setAlignment(Qt::AlignCenter);
        lbl_devSeven = new QLabel(frame);
        lbl_devSeven->setObjectName(QString::fromUtf8("lbl_devSeven"));
        lbl_devSeven->setGeometry(QRect(490, 56, 67, 31));
        lbl_devSeven->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_devSeven->setAlignment(Qt::AlignCenter);
        lbl_alSeven = new QLabel(frame);
        lbl_alSeven->setObjectName(QString::fromUtf8("lbl_alSeven"));
        lbl_alSeven->setGeometry(QRect(490, 10, 67, 31));
        lbl_alSeven->setFont(font);
        lbl_alSeven->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_alSeven->setAlignment(Qt::AlignCenter);
        lbl_alEight = new QLabel(frame);
        lbl_alEight->setObjectName(QString::fromUtf8("lbl_alEight"));
        lbl_alEight->setGeometry(QRect(570, 10, 67, 31));
        lbl_alEight->setFont(font);
        lbl_alEight->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_alEight->setAlignment(Qt::AlignCenter);
        lbl_devEight = new QLabel(frame);
        lbl_devEight->setObjectName(QString::fromUtf8("lbl_devEight"));
        lbl_devEight->setGeometry(QRect(570, 56, 67, 31));
        lbl_devEight->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_devEight->setAlignment(Qt::AlignCenter);
        lbl_devNine = new QLabel(frame);
        lbl_devNine->setObjectName(QString::fromUtf8("lbl_devNine"));
        lbl_devNine->setGeometry(QRect(650, 56, 67, 31));
        lbl_devNine->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_devNine->setAlignment(Qt::AlignCenter);
        lbl_alNine = new QLabel(frame);
        lbl_alNine->setObjectName(QString::fromUtf8("lbl_alNine"));
        lbl_alNine->setGeometry(QRect(650, 12, 67, 31));
        lbl_alNine->setFont(font);
        lbl_alNine->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_alNine->setAlignment(Qt::AlignCenter);
        lbl_alTen = new QLabel(frame);
        lbl_alTen->setObjectName(QString::fromUtf8("lbl_alTen"));
        lbl_alTen->setGeometry(QRect(730, 10, 67, 31));
        lbl_alTen->setFont(font);
        lbl_alTen->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_alTen->setAlignment(Qt::AlignCenter);
        lbl_devTen = new QLabel(frame);
        lbl_devTen->setObjectName(QString::fromUtf8("lbl_devTen"));
        lbl_devTen->setGeometry(QRect(730, 56, 67, 31));
        lbl_devTen->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_devTen->setAlignment(Qt::AlignCenter);
        frame_graphOne = new QFrame(frame);
        frame_graphOne->setObjectName(QString::fromUtf8("frame_graphOne"));
        frame_graphOne->setGeometry(QRect(9, 6, 70, 40));
        frame_graphOne->setFont(font);
        frame_graphOne->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        frame_graphOne->setFrameShape(QFrame::StyledPanel);
        frame_graphOne->setFrameShadow(QFrame::Raised);
        frame_graphTwo = new QFrame(frame);
        frame_graphTwo->setObjectName(QString::fromUtf8("frame_graphTwo"));
        frame_graphTwo->setGeometry(QRect(89, 6, 70, 40));
        frame_graphTwo->setFont(font);
        frame_graphTwo->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        frame_graphTwo->setFrameShape(QFrame::StyledPanel);
        frame_graphTwo->setFrameShadow(QFrame::Raised);
        frame_graphThree = new QFrame(frame);
        frame_graphThree->setObjectName(QString::fromUtf8("frame_graphThree"));
        frame_graphThree->setGeometry(QRect(169, 6, 70, 40));
        frame_graphThree->setFont(font);
        frame_graphThree->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        frame_graphThree->setFrameShape(QFrame::StyledPanel);
        frame_graphThree->setFrameShadow(QFrame::Raised);
        frame_graphFour = new QFrame(frame);
        frame_graphFour->setObjectName(QString::fromUtf8("frame_graphFour"));
        frame_graphFour->setGeometry(QRect(249, 6, 70, 40));
        frame_graphFour->setFont(font);
        frame_graphFour->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        frame_graphFour->setFrameShape(QFrame::StyledPanel);
        frame_graphFour->setFrameShadow(QFrame::Raised);
        frame_graphFive = new QFrame(frame);
        frame_graphFive->setObjectName(QString::fromUtf8("frame_graphFive"));
        frame_graphFive->setGeometry(QRect(329, 6, 70, 40));
        frame_graphFive->setFont(font);
        frame_graphFive->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        frame_graphFive->setFrameShape(QFrame::StyledPanel);
        frame_graphFive->setFrameShadow(QFrame::Raised);
        frame_graphSix = new QFrame(frame);
        frame_graphSix->setObjectName(QString::fromUtf8("frame_graphSix"));
        frame_graphSix->setGeometry(QRect(409, 6, 70, 40));
        frame_graphSix->setFont(font);
        frame_graphSix->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        frame_graphSix->setFrameShape(QFrame::StyledPanel);
        frame_graphSix->setFrameShadow(QFrame::Raised);
        frame_graphSeven = new QFrame(frame);
        frame_graphSeven->setObjectName(QString::fromUtf8("frame_graphSeven"));
        frame_graphSeven->setGeometry(QRect(489, 6, 70, 40));
        frame_graphSeven->setFont(font);
        frame_graphSeven->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        frame_graphSeven->setFrameShape(QFrame::StyledPanel);
        frame_graphSeven->setFrameShadow(QFrame::Raised);
        frame_graphEight = new QFrame(frame);
        frame_graphEight->setObjectName(QString::fromUtf8("frame_graphEight"));
        frame_graphEight->setGeometry(QRect(569, 6, 70, 40));
        frame_graphEight->setFont(font);
        frame_graphEight->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        frame_graphEight->setFrameShape(QFrame::StyledPanel);
        frame_graphEight->setFrameShadow(QFrame::Raised);
        frame_graphNine = new QFrame(frame);
        frame_graphNine->setObjectName(QString::fromUtf8("frame_graphNine"));
        frame_graphNine->setGeometry(QRect(649, 6, 70, 40));
        frame_graphNine->setFont(font);
        frame_graphNine->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        frame_graphNine->setFrameShape(QFrame::StyledPanel);
        frame_graphNine->setFrameShadow(QFrame::Raised);
        frame_graphTen = new QFrame(frame);
        frame_graphTen->setObjectName(QString::fromUtf8("frame_graphTen"));
        frame_graphTen->setGeometry(QRect(729, 6, 70, 40));
        frame_graphTen->setFont(font);
        frame_graphTen->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        frame_graphTen->setFrameShape(QFrame::StyledPanel);
        frame_graphTen->setFrameShadow(QFrame::Raised);
        btn_graphOne = new QPushButton(frame);
        btn_graphOne->setObjectName(QString::fromUtf8("btn_graphOne"));
        btn_graphOne->setGeometry(QRect(6, 1, 72, 51));
        btn_graphOne->setFont(font);
        btn_graphOne->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        btn_graphOne->setFlat(true);
        btn_graphTwo = new QPushButton(frame);
        btn_graphTwo->setObjectName(QString::fromUtf8("btn_graphTwo"));
        btn_graphTwo->setGeometry(QRect(90, 1, 72, 51));
        btn_graphTwo->setFont(font);
        btn_graphTwo->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        btn_graphTwo->setFlat(true);
        btn_graphThree = new QPushButton(frame);
        btn_graphThree->setObjectName(QString::fromUtf8("btn_graphThree"));
        btn_graphThree->setGeometry(QRect(169, 1, 72, 51));
        btn_graphThree->setFont(font);
        btn_graphThree->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        btn_graphThree->setFlat(true);
        btn_graphFour = new QPushButton(frame);
        btn_graphFour->setObjectName(QString::fromUtf8("btn_graphFour"));
        btn_graphFour->setGeometry(QRect(249, 1, 72, 51));
        btn_graphFour->setFont(font);
        btn_graphFour->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        btn_graphFour->setFlat(true);
        btn_graphFive = new QPushButton(frame);
        btn_graphFive->setObjectName(QString::fromUtf8("btn_graphFive"));
        btn_graphFive->setGeometry(QRect(329, 1, 72, 51));
        btn_graphFive->setFont(font);
        btn_graphFive->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        btn_graphFive->setFlat(true);
        btn_graphSix = new QPushButton(frame);
        btn_graphSix->setObjectName(QString::fromUtf8("btn_graphSix"));
        btn_graphSix->setGeometry(QRect(409, 1, 72, 51));
        btn_graphSix->setFont(font);
        btn_graphSix->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        btn_graphSix->setFlat(true);
        btn_graphSeven = new QPushButton(frame);
        btn_graphSeven->setObjectName(QString::fromUtf8("btn_graphSeven"));
        btn_graphSeven->setGeometry(QRect(488, 1, 72, 51));
        btn_graphSeven->setFont(font);
        btn_graphSeven->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        btn_graphSeven->setFlat(true);
        btn_graphEight = new QPushButton(frame);
        btn_graphEight->setObjectName(QString::fromUtf8("btn_graphEight"));
        btn_graphEight->setGeometry(QRect(568, 1, 72, 51));
        btn_graphEight->setFont(font);
        btn_graphEight->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        btn_graphEight->setFlat(true);
        btn_graphNine = new QPushButton(frame);
        btn_graphNine->setObjectName(QString::fromUtf8("btn_graphNine"));
        btn_graphNine->setGeometry(QRect(648, 1, 72, 51));
        btn_graphNine->setFont(font);
        btn_graphNine->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        btn_graphNine->setFlat(true);
        btn_graphTen = new QPushButton(frame);
        btn_graphTen->setObjectName(QString::fromUtf8("btn_graphTen"));
        btn_graphTen->setGeometry(QRect(728, 1, 72, 51));
        btn_graphTen->setFont(font);
        btn_graphTen->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        btn_graphTen->setFlat(true);
        lbl_alSix->raise();
        lbl_alFive->raise();
        lbl_alOne->raise();
        lbl_alTen->raise();
        lbl_alThree->raise();
        lbl_alFour->raise();
        lbl_alTwo->raise();
        lbl_alNine->raise();
        lbl_alEight->raise();
        lbl_alSeven->raise();
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
        btn_graphSix->raise();
        btn_graphTen->raise();
        btn_graphOne->raise();
        btn_graphEight->raise();
        btn_graphTwo->raise();
        btn_graphNine->raise();
        btn_graphThree->raise();
        btn_graphFive->raise();
        btn_graphSeven->raise();
        btn_graphFour->raise();
        lbl_devOne->raise();
        lbl_devTwo->raise();
        lbl_devThree->raise();
        lbl_devFour->raise();
        lbl_devFive->raise();
        lbl_devSix->raise();
        lbl_devSeven->raise();
        lbl_devEight->raise();
        lbl_devNine->raise();
        lbl_devTen->raise();
        lineEdit_patName = new QLineEdit(MeasureDialog);
        lineEdit_patName->setObjectName(QString::fromUtf8("lineEdit_patName"));
        lineEdit_patName->setGeometry(QRect(130, 0, 230, 41));
        QFont font1;
        font1.setPointSize(14);
        lineEdit_patName->setFont(font1);
        lineEdit_patName->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(empty.png);\n"
"color:rgb(0,0,0);"));
        lineEdit_docName = new QLineEdit(MeasureDialog);
        lineEdit_docName->setObjectName(QString::fromUtf8("lineEdit_docName"));
        lineEdit_docName->setGeometry(QRect(380, 0, 281, 41));
        lineEdit_docName->setFont(font1);
        lineEdit_docName->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(empty.png);\n"
"color:rgb(21,21,21);"));
        lineEdit_lensType = new QLabel(MeasureDialog);
        lineEdit_lensType->setObjectName(QString::fromUtf8("lineEdit_lensType"));
        lineEdit_lensType->setGeometry(QRect(190, 60, 201, 61));
        QFont font2;
        font2.setPointSize(18);
        lineEdit_lensType->setFont(font2);
        lineEdit_lensType->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lineEdit_lensType->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lbl_opMode = new QLabel(MeasureDialog);
        lbl_opMode->setObjectName(QString::fromUtf8("lbl_opMode"));
        lbl_opMode->setGeometry(QRect(460, 60, 141, 61));
        lbl_opMode->setFont(font2);
        lbl_opMode->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_opMode->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        btn_calculator = new QPushButton(MeasureDialog);
        btn_calculator->setObjectName(QString::fromUtf8("btn_calculator"));
        btn_calculator->setGeometry(QRect(730, 60, 70, 70));
        btn_calculator->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"border-image: url(:/images/calculator-icon.png);"));
        btn_calculator->setFlat(true);
        btn_home = new QPushButton(MeasureDialog);
        btn_home->setObjectName(QString::fromUtf8("btn_home"));
        btn_home->setGeometry(QRect(660, 60, 70, 70));
        btn_home->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"border-image: url(:/images/home.png);"));
        btn_home->setFlat(true);
        lbl_home = new QLabel(MeasureDialog);
        lbl_home->setObjectName(QString::fromUtf8("lbl_home"));
        lbl_home->setGeometry(QRect(650, 40, 80, 16));
        lbl_home->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_home->setAlignment(Qt::AlignCenter);
        lbl_calculator = new QLabel(MeasureDialog);
        lbl_calculator->setObjectName(QString::fromUtf8("lbl_calculator"));
        lbl_calculator->setGeometry(QRect(720, 40, 90, 16));
        lbl_calculator->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        lbl_calculator->setAlignment(Qt::AlignCenter);
        btn_play = new QPushButton(MeasureDialog);
        btn_play->setObjectName(QString::fromUtf8("btn_play"));
        btn_play->setGeometry(QRect(230, 240, 100, 100));
        btn_play->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/icons/ic_play_circle_outline_white_48dp.png);"));
        btn_play->setFlat(true);
        btn_startMeasure = new QPushButton(MeasureDialog);
        btn_startMeasure->setObjectName(QString::fromUtf8("btn_startMeasure"));
        btn_startMeasure->setGeometry(QRect(-10, 170, 512, 331));
        btn_startMeasure->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);"));
        btn_startMeasure->setFlat(true);
        wm_plt = new QFrame(MeasureDialog);
        wm_plt->setObjectName(QString::fromUtf8("wm_plt"));
        wm_plt->setGeometry(QRect(0, 130, 512, 350));
        wm_plt->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"background-image:url(empty.png);"));
        wm_plt->setFrameShape(QFrame::StyledPanel);
        wm_plt->setFrameShadow(QFrame::Raised);
        graphicsView = new QCustomPlot(MeasureDialog);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 130, 512, 255));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image:url(empty.png);\n"
"background-color: rgb(0, 0, 0);"));
        lbl_time = new QLabel(MeasureDialog);
        lbl_time->setObjectName(QString::fromUtf8("lbl_time"));
        lbl_time->setGeometry(QRect(680, 10, 120, 21));
        QFont font3;
        font3.setPointSize(9);
        lbl_time->setFont(font3);
        lbl_time->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        lbl_time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        marker_cornea = new QPushButton(MeasureDialog);
        marker_cornea->setObjectName(QString::fromUtf8("marker_cornea"));
        marker_cornea->setGeometry(QRect(0, 150, 20, 20));
        marker_cornea->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/marker.png);\n"
""));
        marker_cornea->setFlat(true);
        marker_lensOne = new QPushButton(MeasureDialog);
        marker_lensOne->setObjectName(QString::fromUtf8("marker_lensOne"));
        marker_lensOne->setGeometry(QRect(80, 150, 20, 20));
        marker_lensOne->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/marker.png);\n"
""));
        marker_lensOne->setFlat(true);
        marker_lensTwo = new QPushButton(MeasureDialog);
        marker_lensTwo->setObjectName(QString::fromUtf8("marker_lensTwo"));
        marker_lensTwo->setGeometry(QRect(150, 150, 20, 20));
        marker_lensTwo->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/marker.png);\n"
""));
        marker_lensTwo->setFlat(true);
        marker_retina = new QPushButton(MeasureDialog);
        marker_retina->setObjectName(QString::fromUtf8("marker_retina"));
        marker_retina->setGeometry(QRect(490, 150, 20, 20));
        marker_retina->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/marker.png);\n"
""));
        marker_retina->setFlat(true);
        marker_cornea_2 = new QPushButton(MeasureDialog);
        marker_cornea_2->setObjectName(QString::fromUtf8("marker_cornea_2"));
        marker_cornea_2->setGeometry(QRect(0, 480, 513, 20));
        marker_cornea_2->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/scale.png);\n"
""));
        marker_cornea_2->setFlat(true);
        frame_2 = new QFrame(MeasureDialog);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(512, 130, 290, 370));
        frame_2->setStyleSheet(QString::fromUtf8("background-color:rgb(0,0,0);background-image:url(empty.png);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        lineEdit_avgAl = new QLineEdit(frame_2);
        lineEdit_avgAl->setObjectName(QString::fromUtf8("lineEdit_avgAl"));
        lineEdit_avgAl->setGeometry(QRect(130, 9, 120, 52));
        QFont font4;
        font4.setPointSize(24);
        font4.setBold(true);
        lineEdit_avgAl->setFont(font4);
        lineEdit_avgAl->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(empty.png);\n"
"color:rgb(21,21,21);\n"
"border-radius:5px;"));
        lineEdit_avgAl->setAlignment(Qt::AlignCenter);
        lineEdit_vit = new QLineEdit(frame_2);
        lineEdit_vit->setObjectName(QString::fromUtf8("lineEdit_vit"));
        lineEdit_vit->setGeometry(QRect(130, 189, 120, 52));
        lineEdit_vit->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(empty.png);\n"
"color:rgb(21,21,21);\n"
"border-radius:5px;"));
        lineEdit_vit->setAlignment(Qt::AlignCenter);
        lineEdit_acd = new QLineEdit(frame_2);
        lineEdit_acd->setObjectName(QString::fromUtf8("lineEdit_acd"));
        lineEdit_acd->setGeometry(QRect(130, 130, 120, 52));
        lineEdit_acd->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(empty.png);\n"
"color:rgb(21,21,21);\n"
"border-radius:5px;"));
        lineEdit_acd->setAlignment(Qt::AlignCenter);
        lbl_avgAl = new QLabel(frame_2);
        lbl_avgAl->setObjectName(QString::fromUtf8("lbl_avgAl"));
        lbl_avgAl->setGeometry(QRect(43, 10, 90, 50));
        lbl_avgAl->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"color:rgb(255,255,255);\n"
"background-color: #2196F3;border-radius:5px;"));
        lbl_avgAl->setAlignment(Qt::AlignCenter);
        lineEdit_lt = new QLineEdit(frame_2);
        lineEdit_lt->setObjectName(QString::fromUtf8("lineEdit_lt"));
        lineEdit_lt->setGeometry(QRect(130, 249, 120, 52));
        lineEdit_lt->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(empty.png);\n"
"color:rgb(21,21,21);\n"
"border-radius:5px;"));
        lineEdit_lt->setAlignment(Qt::AlignCenter);
        lbl_avgAl_4 = new QLabel(frame_2);
        lbl_avgAl_4->setObjectName(QString::fromUtf8("lbl_avgAl_4"));
        lbl_avgAl_4->setGeometry(QRect(43, 310, 90, 50));
        lbl_avgAl_4->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"color:rgb(255,255,255);\n"
"background-color: #2196F3;border-radius:5px;"));
        lbl_avgAl_4->setAlignment(Qt::AlignCenter);
        lbl_avgAl_2 = new QLabel(frame_2);
        lbl_avgAl_2->setObjectName(QString::fromUtf8("lbl_avgAl_2"));
        lbl_avgAl_2->setGeometry(QRect(43, 131, 90, 50));
        lbl_avgAl_2->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"color:rgb(255,255,255);\n"
"background-color: #2196F3;border-radius:5px;"));
        lbl_avgAl_2->setAlignment(Qt::AlignCenter);
        lineEdit_sd = new QLineEdit(frame_2);
        lineEdit_sd->setObjectName(QString::fromUtf8("lineEdit_sd"));
        lineEdit_sd->setGeometry(QRect(130, 70, 120, 52));
        QFont font5;
        font5.setPointSize(18);
        font5.setBold(true);
        lineEdit_sd->setFont(font5);
        lineEdit_sd->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(empty.png);\n"
"color:rgb(21,21,21);\n"
"border-radius:5px;"));
        lineEdit_sd->setAlignment(Qt::AlignCenter);
        lbl_avgAl_5 = new QLabel(frame_2);
        lbl_avgAl_5->setObjectName(QString::fromUtf8("lbl_avgAl_5"));
        lbl_avgAl_5->setGeometry(QRect(43, 190, 90, 50));
        lbl_avgAl_5->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"color:rgb(255,255,255);\n"
"background-color: #2196F3;border-radius:5px;"));
        lbl_avgAl_5->setAlignment(Qt::AlignCenter);
        lbl_sd = new QLabel(frame_2);
        lbl_sd->setObjectName(QString::fromUtf8("lbl_sd"));
        lbl_sd->setGeometry(QRect(43, 71, 90, 50));
        lbl_sd->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"color:rgb(255,255,255);\n"
"background-color: #2196F3;border-radius:5px;"));
        lbl_sd->setAlignment(Qt::AlignCenter);
        lbl_avgAl_3 = new QLabel(frame_2);
        lbl_avgAl_3->setObjectName(QString::fromUtf8("lbl_avgAl_3"));
        lbl_avgAl_3->setGeometry(QRect(43, 250, 90, 50));
        lbl_avgAl_3->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"color:rgb(255,255,255);\n"
"background-color: #2196F3;border-radius:5px;"));
        lbl_avgAl_3->setAlignment(Qt::AlignCenter);
        lineEdit_al = new QLineEdit(frame_2);
        lineEdit_al->setObjectName(QString::fromUtf8("lineEdit_al"));
        lineEdit_al->setGeometry(QRect(130, 309, 120, 52));
        QFont font6;
        font6.setPointSize(20);
        lineEdit_al->setFont(font6);
        lineEdit_al->setStyleSheet(QString::fromUtf8("border-image: url(:/images/searchbar.png);\n"
"background-image:url(empty.png);\n"
"color:rgb(21,21,21);\n"
"border-radius:5px;"));
        lineEdit_al->setAlignment(Qt::AlignCenter);
        lbl_avgAl->raise();
        lbl_avgAl_4->raise();
        lbl_avgAl_2->raise();
        lbl_avgAl_5->raise();
        lbl_sd->raise();
        lbl_avgAl_3->raise();
        lineEdit_al->raise();
        lineEdit_avgAl->raise();
        lineEdit_sd->raise();
        lineEdit_acd->raise();
        lineEdit_vit->raise();
        lineEdit_lt->raise();
        btn_eye = new QPushButton(MeasureDialog);
        btn_eye->setObjectName(QString::fromUtf8("btn_eye"));
        btn_eye->setEnabled(true);
        btn_eye->setGeometry(QRect(0, 0, 111, 60));
        QFont font7;
        font7.setPointSize(30);
        btn_eye->setFont(font7);
        btn_eye->setStyleSheet(QString::fromUtf8("border-image:url(:/images/empty.png);\n"
"border-image: url(:/images/btn-small.png);\n"
""));
        btn_eye->setCheckable(false);
        btn_eye->setFlat(true);
        butDelete = new QPushButton(MeasureDialog);
        butDelete->setObjectName(QString::fromUtf8("butDelete"));
        butDelete->setGeometry(QRect(620, 90, 41, 41));
        butDelete->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/delete-icon.png);"));
        graphicsView->raise();
        wm_plt->raise();
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
        btn_play->raise();
        btn_startMeasure->raise();
        lbl_time->raise();
        marker_cornea->raise();
        marker_lensOne->raise();
        marker_lensTwo->raise();
        marker_retina->raise();
        marker_cornea_2->raise();
        frame_2->raise();
        btn_eye->raise();
        butDelete->raise();

        retranslateUi(MeasureDialog);

        QMetaObject::connectSlotsByName(MeasureDialog);
    } // setupUi

    void retranslateUi(QDialog *MeasureDialog)
    {
        MeasureDialog->setWindowTitle(QCoreApplication::translate("MeasureDialog", "Dialog", nullptr));
        btn_lensType->setText(QString());
        btn_opMode->setText(QString());
        lbl_alOne->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_devOne->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_alTwo->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_devTwo->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_alThree->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_devThree->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_devFour->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_alFour->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_devFive->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_alFive->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_devSix->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_alSix->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_devSeven->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_alSeven->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_alEight->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_devEight->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_devNine->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_alNine->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_alTen->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        lbl_devTen->setText(QCoreApplication::translate("MeasureDialog", "0.00", nullptr));
        btn_graphOne->setText(QString());
        btn_graphTwo->setText(QString());
        btn_graphThree->setText(QString());
        btn_graphFour->setText(QString());
        btn_graphFive->setText(QString());
        btn_graphSix->setText(QString());
        btn_graphSeven->setText(QString());
        btn_graphEight->setText(QString());
        btn_graphNine->setText(QString());
        btn_graphTen->setText(QString());
        lineEdit_lensType->setText(QCoreApplication::translate("MeasureDialog", "Dense Cataract", nullptr));
        lbl_opMode->setText(QCoreApplication::translate("MeasureDialog", "Contact", nullptr));
        btn_calculator->setText(QString());
        btn_home->setText(QString());
        lbl_home->setText(QCoreApplication::translate("MeasureDialog", "Home", nullptr));
        lbl_calculator->setText(QCoreApplication::translate("MeasureDialog", "Calculator", nullptr));
        btn_play->setText(QString());
        btn_startMeasure->setText(QString());
        lbl_time->setText(QCoreApplication::translate("MeasureDialog", "10:09", nullptr));
        marker_cornea->setText(QString());
        marker_lensOne->setText(QString());
        marker_lensTwo->setText(QString());
        marker_retina->setText(QString());
        marker_cornea_2->setText(QString());
        lbl_avgAl->setText(QCoreApplication::translate("MeasureDialog", "AVG AL:", nullptr));
        lbl_avgAl_4->setText(QCoreApplication::translate("MeasureDialog", "AL:", nullptr));
        lbl_avgAl_2->setText(QCoreApplication::translate("MeasureDialog", "ACD:", nullptr));
        lbl_avgAl_5->setText(QCoreApplication::translate("MeasureDialog", "VIT:", nullptr));
        lbl_sd->setText(QCoreApplication::translate("MeasureDialog", "SD:", nullptr));
        lbl_avgAl_3->setText(QCoreApplication::translate("MeasureDialog", "LT:", nullptr));
        btn_eye->setText(QCoreApplication::translate("MeasureDialog", "OS", nullptr));
        butDelete->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MeasureDialog: public Ui_MeasureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEASUREDIALOG_H
