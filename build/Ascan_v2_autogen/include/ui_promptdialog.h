/********************************************************************************
** Form generated from reading UI file 'promptdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROMPTDIALOG_H
#define UI_PROMPTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PromptDialog
{
public:
    QPushButton *btn_no;
    QPushButton *btn_yes;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *PromptDialog)
    {
        if (PromptDialog->objectName().isEmpty())
            PromptDialog->setObjectName(QString::fromUtf8("PromptDialog"));
        PromptDialog->resize(326, 300);
        PromptDialog->setStyleSheet(QString::fromUtf8("border-image: url(:/images/dialog-yn.png);\n"
"background-image:url(empty.png);"));
        btn_no = new QPushButton(PromptDialog);
        btn_no->setObjectName(QString::fromUtf8("btn_no"));
        btn_no->setGeometry(QRect(128, 235, 80, 40));
        btn_no->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        btn_no->setFlat(true);
        btn_yes = new QPushButton(PromptDialog);
        btn_yes->setObjectName(QString::fromUtf8("btn_yes"));
        btn_yes->setGeometry(QRect(220, 235, 80, 40));
        btn_yes->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        btn_yes->setFlat(true);
        label = new QLabel(PromptDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(36, 50, 250, 130));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        label->setWordWrap(true);
        label_2 = new QLabel(PromptDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 190, 325, 30));
        label_2->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));

        retranslateUi(PromptDialog);

        QMetaObject::connectSlotsByName(PromptDialog);
    } // setupUi

    void retranslateUi(QDialog *PromptDialog)
    {
        PromptDialog->setWindowTitle(QCoreApplication::translate("PromptDialog", "Dialog", nullptr));
        btn_no->setText(QString());
        btn_yes->setText(QString());
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("PromptDialog", "Do you wish to continue?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PromptDialog: public Ui_PromptDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROMPTDIALOG_H
