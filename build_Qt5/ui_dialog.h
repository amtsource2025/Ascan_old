/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Keypad
{
public:
    QPushButton *qbutton;

    void setupUi(QDialog *Keypad)
    {
        if (Keypad->objectName().isEmpty())
            Keypad->setObjectName(QString::fromUtf8("Keypad"));
        Keypad->resize(800, 208);
        Keypad->setStyleSheet(QString::fromUtf8("background-image: url(:/images/Touch-Keyboard.png);"));
        qbutton = new QPushButton(Keypad);
        qbutton->setObjectName(QString::fromUtf8("qbutton"));
        qbutton->setGeometry(QRect(0, 14, 71, 31));

        retranslateUi(Keypad);

        QMetaObject::connectSlotsByName(Keypad);
    } // setupUi

    void retranslateUi(QDialog *Keypad)
    {
        Keypad->setWindowTitle(QCoreApplication::translate("Keypad", "Dialog", nullptr));
        qbutton->setText(QCoreApplication::translate("Keypad", "q", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Keypad: public Ui_Keypad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
