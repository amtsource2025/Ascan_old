/********************************************************************************
** Form generated from reading UI file 'clock.ui'
**
** Created by: Qt User Interface Compiler version 5.15.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOCK_H
#define UI_CLOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Clock
{
public:
    QLabel *label;

    void setupUi(QDialog *Clock)
    {
        if (Clock->objectName().isEmpty())
            Clock->setObjectName(QString::fromUtf8("Clock"));
        Clock->resize(180, 24);
        Clock->setStyleSheet(QString::fromUtf8("background-image:url(:/images/empty.png);"));
        label = new QLabel(Clock);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, -2, 180, 27));
        label->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(Clock);

        QMetaObject::connectSlotsByName(Clock);
    } // setupUi

    void retranslateUi(QDialog *Clock)
    {
        Clock->setWindowTitle(QCoreApplication::translate("Clock", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Clock", "June 13 2018, 10:09", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Clock: public Ui_Clock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOCK_H
