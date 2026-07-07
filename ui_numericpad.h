/********************************************************************************
** Form generated from reading UI file 'numericpad.ui'
**
** Created by: Qt User Interface Compiler version 5.15.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUMERICPAD_H
#define UI_NUMERICPAD_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Numericpad
{
public:
    QPushButton *Button1;
    QPushButton *Button2;
    QPushButton *Button6;
    QPushButton *Button4;
    QPushButton *Button5;
    QPushButton *Button3;
    QPushButton *Button7;
    QPushButton *Button8;
    QPushButton *Button9;
    QPushButton *Buttondot;
    QPushButton *Button0;
    QPushButton *Buttonbp;
    QPushButton *Buttonclr;
    QPushButton *Buttondne;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Numericpad)
    {
        if (Numericpad->objectName().isEmpty())
            Numericpad->setObjectName(QString::fromUtf8("Numericpad"));
        Numericpad->resize(254, 251);
        Numericpad->setStyleSheet(QString::fromUtf8("border-image: url(:/images/keyboard-number-pad.png);"));
        Numericpad->setLocale(QLocale(QLocale::English, QLocale::India));
        Button1 = new QPushButton(Numericpad);
        Button1->setObjectName(QString::fromUtf8("Button1"));
        Button1->setGeometry(QRect(0, 129, 61, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        Button1->setFont(font);
        Button1->setFocusPolicy(Qt::NoFocus);
        Button1->setAutoFillBackground(false);
        Button1->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-small.png);\n"
"background-image:url(:/images/empty.png);"));
        Button1->setAutoDefault(false);
        Button1->setFlat(true);
        Button2 = new QPushButton(Numericpad);
        Button2->setObjectName(QString::fromUtf8("Button2"));
        Button2->setGeometry(QRect(64, 129, 61, 60));
        Button2->setFont(font);
        Button2->setFocusPolicy(Qt::NoFocus);
        Button2->setAutoFillBackground(false);
        Button2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-small.png);\n"
"background-image:url(:/images/empty.png);"));
        Button2->setAutoDefault(false);
        Button2->setFlat(true);
        Button6 = new QPushButton(Numericpad);
        Button6->setObjectName(QString::fromUtf8("Button6"));
        Button6->setGeometry(QRect(127, 66, 61, 60));
        Button6->setFont(font);
        Button6->setFocusPolicy(Qt::NoFocus);
        Button6->setAutoFillBackground(false);
        Button6->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-small.png);\n"
"background-image:url(:/images/empty.png);"));
        Button6->setAutoDefault(false);
        Button6->setFlat(true);
        Button4 = new QPushButton(Numericpad);
        Button4->setObjectName(QString::fromUtf8("Button4"));
        Button4->setGeometry(QRect(0, 66, 61, 60));
        Button4->setFont(font);
        Button4->setFocusPolicy(Qt::NoFocus);
        Button4->setAutoFillBackground(false);
        Button4->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-small.png);\n"
"background-image:url(:/images/empty.png);"));
        Button4->setAutoDefault(false);
        Button4->setFlat(true);
        Button5 = new QPushButton(Numericpad);
        Button5->setObjectName(QString::fromUtf8("Button5"));
        Button5->setGeometry(QRect(64, 66, 61, 60));
        Button5->setFont(font);
        Button5->setFocusPolicy(Qt::NoFocus);
        Button5->setAutoFillBackground(false);
        Button5->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-small.png);\n"
"background-image:url(:/images/empty.png);"));
        Button5->setAutoDefault(false);
        Button5->setFlat(true);
        Button3 = new QPushButton(Numericpad);
        Button3->setObjectName(QString::fromUtf8("Button3"));
        Button3->setGeometry(QRect(127, 129, 61, 60));
        Button3->setFont(font);
        Button3->setFocusPolicy(Qt::NoFocus);
        Button3->setAutoFillBackground(false);
        Button3->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-small.png);\n"
"background-image:url(:/images/empty.png);"));
        Button3->setAutoDefault(false);
        Button3->setFlat(true);
        Button7 = new QPushButton(Numericpad);
        Button7->setObjectName(QString::fromUtf8("Button7"));
        Button7->setGeometry(QRect(0, 4, 61, 60));
        Button7->setFont(font);
        Button7->setFocusPolicy(Qt::NoFocus);
        Button7->setAutoFillBackground(false);
        Button7->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-small.png);\n"
"background-image:url(:/images/empty.png);"));
        Button7->setAutoDefault(false);
        Button7->setFlat(true);
        Button8 = new QPushButton(Numericpad);
        Button8->setObjectName(QString::fromUtf8("Button8"));
        Button8->setGeometry(QRect(64, 4, 61, 60));
        Button8->setFont(font);
        Button8->setFocusPolicy(Qt::NoFocus);
        Button8->setAutoFillBackground(false);
        Button8->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-small.png);\n"
"background-image:url(:/images/empty.png);"));
        Button8->setAutoDefault(false);
        Button8->setFlat(true);
        Button9 = new QPushButton(Numericpad);
        Button9->setObjectName(QString::fromUtf8("Button9"));
        Button9->setGeometry(QRect(127, 4, 61, 60));
        Button9->setFont(font);
        Button9->setFocusPolicy(Qt::NoFocus);
        Button9->setAutoFillBackground(false);
        Button9->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-small.png);\n"
"background-image:url(:/images/empty.png);"));
        Button9->setAutoDefault(false);
        Button9->setFlat(true);
        Buttondot = new QPushButton(Numericpad);
        Buttondot->setObjectName(QString::fromUtf8("Buttondot"));
        Buttondot->setGeometry(QRect(128, 191, 61, 60));
        Buttondot->setFont(font);
        Buttondot->setFocusPolicy(Qt::NoFocus);
        Buttondot->setAutoFillBackground(false);
        Buttondot->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-small.png);\n"
"background-image:url(:/images/empty.png);"));
        Buttondot->setAutoDefault(false);
        Buttondot->setFlat(true);
        Button0 = new QPushButton(Numericpad);
        Button0->setObjectName(QString::fromUtf8("Button0"));
        Button0->setGeometry(QRect(-3, 191, 132, 60));
        Button0->setFont(font);
        Button0->setFocusPolicy(Qt::NoFocus);
        Button0->setAutoFillBackground(false);
        Button0->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-small.png);\n"
"background-image:url(:/images/empty.png);"));
        Button0->setAutoDefault(false);
        Button0->setFlat(true);
        Buttonbp = new QPushButton(Numericpad);
        Buttonbp->setObjectName(QString::fromUtf8("Buttonbp"));
        Buttonbp->setGeometry(QRect(193, 4, 61, 60));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(1);
        font1.setBold(true);
        font1.setWeight(75);
        Buttonbp->setFont(font1);
        Buttonbp->setFocusPolicy(Qt::NoFocus);
        Buttonbp->setAutoFillBackground(false);
        Buttonbp->setStyleSheet(QString::fromUtf8("border-image: url(:/images/btn-small.png);\n"
"background-image:url(:/images/empty.png);"));
        Buttonbp->setAutoDefault(false);
        Buttonbp->setFlat(true);
        Buttonclr = new QPushButton(Numericpad);
        Buttonclr->setObjectName(QString::fromUtf8("Buttonclr"));
        Buttonclr->setGeometry(QRect(191, 66, 61, 60));
        Buttonclr->setFont(font);
        Buttonclr->setFocusPolicy(Qt::NoFocus);
        Buttonclr->setAutoFillBackground(false);
        Buttonclr->setStyleSheet(QString::fromUtf8("border-image: url(:/images/alert-red.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(255,255,255);"));
        Buttonclr->setAutoDefault(false);
        Buttonclr->setFlat(true);
        Buttondne = new QPushButton(Numericpad);
        Buttondne->setObjectName(QString::fromUtf8("Buttondne"));
        Buttondne->setGeometry(QRect(191, 127, 61, 126));
        Buttondne->setFont(font);
        Buttondne->setFocusPolicy(Qt::NoFocus);
        Buttondne->setAutoFillBackground(false);
        Buttondne->setStyleSheet(QString::fromUtf8("border-image: url(:/images/alert-green.png);\n"
"background-image:url(:/images/empty.png);\n"
"color:rgb(255,255,255);"));
        Buttondne->setAutoDefault(false);
        Buttondne->setFlat(true);
        label = new QLabel(Numericpad);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 270, 40, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu"));
        label->setFont(font2);
        label_2 = new QLabel(Numericpad);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(205, 22, 37, 20));
        QFont font3;
        font3.setPointSize(14);
        label_2->setFont(font3);
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/empty.png);\n"
"background-image:url(:/images/empty.png);"));
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(Numericpad);

        QMetaObject::connectSlotsByName(Numericpad);
    } // setupUi

    void retranslateUi(QDialog *Numericpad)
    {
        Numericpad->setWindowTitle(QCoreApplication::translate("Numericpad", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        Numericpad->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        Button1->setText(QCoreApplication::translate("Numericpad", "1", nullptr));
        Button2->setText(QCoreApplication::translate("Numericpad", "2", nullptr));
        Button6->setText(QCoreApplication::translate("Numericpad", "6", nullptr));
        Button4->setText(QCoreApplication::translate("Numericpad", "4", nullptr));
        Button5->setText(QCoreApplication::translate("Numericpad", "5", nullptr));
        Button3->setText(QCoreApplication::translate("Numericpad", "3", nullptr));
        Button7->setText(QCoreApplication::translate("Numericpad", "7", nullptr));
        Button8->setText(QCoreApplication::translate("Numericpad", "8", nullptr));
        Button9->setText(QCoreApplication::translate("Numericpad", "9", nullptr));
        Buttondot->setText(QCoreApplication::translate("Numericpad", ".", nullptr));
        Button0->setText(QCoreApplication::translate("Numericpad", "0", nullptr));
        Buttonbp->setText(QCoreApplication::translate("Numericpad", "pm", nullptr));
        Buttonclr->setText(QCoreApplication::translate("Numericpad", "CLR", nullptr));
        Buttondne->setText(QCoreApplication::translate("Numericpad", "DONE", nullptr));
        label->setText(QCoreApplication::translate("Numericpad", "     <-", nullptr));
        label_2->setText(QCoreApplication::translate("Numericpad", "+/-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Numericpad: public Ui_Numericpad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUMERICPAD_H
