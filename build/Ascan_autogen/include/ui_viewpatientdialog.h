/********************************************************************************
** Form generated from reading UI file 'viewpatientdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWPATIENTDIALOG_H
#define UI_VIEWPATIENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewPatientDialog
{
public:
    QPushButton *btn_view;
    QPushButton *btn_delete;
    QTableWidget *table_patient;
    QPushButton *btn_edit;
    QLabel *label;
    QPushButton *btn_close;
    QPushButton *btn_add;
    QLabel *lbl_time;
    QLabel *snackbar;

    void setupUi(QDialog *ViewPatientDialog)
    {
        if (ViewPatientDialog->objectName().isEmpty())
            ViewPatientDialog->setObjectName(QString::fromUtf8("ViewPatientDialog"));
        ViewPatientDialog->resize(800, 600);
        ViewPatientDialog->setStyleSheet(QString::fromUtf8("background-image: url(:/images/5.png);"));
        btn_view = new QPushButton(ViewPatientDialog);
        btn_view->setObjectName(QString::fromUtf8("btn_view"));
        btn_view->setGeometry(QRect(690, 229, 85, 85));
        btn_view->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/view-icon.png);"));
        btn_view->setFlat(true);
        btn_delete = new QPushButton(ViewPatientDialog);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));
        btn_delete->setGeometry(QRect(690, 321, 85, 85));
        btn_delete->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/delete-icon.png);"));
        btn_delete->setFlat(true);
        table_patient = new QTableWidget(ViewPatientDialog);
        if (table_patient->columnCount() < 7)
            table_patient->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_patient->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_patient->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_patient->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_patient->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_patient->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_patient->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        table_patient->setObjectName(QString::fromUtf8("table_patient"));
        table_patient->setGeometry(QRect(0, 94, 801, 511));
        table_patient->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        table_patient->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_patient->setColumnCount(7);
        table_patient->horizontalHeader()->setDefaultSectionSize(133);
        btn_edit = new QPushButton(ViewPatientDialog);
        btn_edit->setObjectName(QString::fromUtf8("btn_edit"));
        btn_edit->setGeometry(QRect(690, 414, 85, 85));
        btn_edit->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/edit-icon.png);"));
        btn_edit->setFlat(true);
        label = new QLabel(ViewPatientDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(340, 4, 160, 70));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label->setAlignment(Qt::AlignCenter);
        btn_close = new QPushButton(ViewPatientDialog);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));
        btn_close->setGeometry(QRect(0, 4, 70, 60));
        btn_close->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/icons/ic_arrow_back_white_48dp.png);"));
        btn_close->setFlat(true);
        btn_add = new QPushButton(ViewPatientDialog);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));
        btn_add->setGeometry(QRect(690, 510, 85, 85));
        btn_add->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/add-icon.png);"));
        btn_add->setFlat(true);
        lbl_time = new QLabel(ViewPatientDialog);
        lbl_time->setObjectName(QString::fromUtf8("lbl_time"));
        lbl_time->setGeometry(QRect(680, 0, 120, 40));
        QFont font1;
        font1.setPointSize(9);
        lbl_time->setFont(font1);
        lbl_time->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        lbl_time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        snackbar = new QLabel(ViewPatientDialog);
        snackbar->setObjectName(QString::fromUtf8("snackbar"));
        snackbar->setGeometry(QRect(-1, 563, 810, 40));
        snackbar->setStyleSheet(QString::fromUtf8("border-image: url(:/images/alert-red.png);\n"
"background-image:url(empty.png);color:rgb(255,255,255);"));
        snackbar->setIndent(5);
        table_patient->raise();
        btn_edit->raise();
        label->raise();
        btn_close->raise();
        btn_add->raise();
        btn_delete->raise();
        btn_view->raise();
        lbl_time->raise();
        snackbar->raise();

        retranslateUi(ViewPatientDialog);

        QMetaObject::connectSlotsByName(ViewPatientDialog);
    } // setupUi

    void retranslateUi(QDialog *ViewPatientDialog)
    {
        ViewPatientDialog->setWindowTitle(QCoreApplication::translate("ViewPatientDialog", "Dialog", nullptr));
        btn_view->setText(QString());
        btn_delete->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = table_patient->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ViewPatientDialog", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table_patient->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ViewPatientDialog", "pID", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table_patient->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ViewPatientDialog", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table_patient->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ViewPatientDialog", "Gender", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table_patient->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ViewPatientDialog", "Age", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table_patient->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ViewPatientDialog", "Contact", nullptr));
        btn_edit->setText(QString());
        label->setText(QCoreApplication::translate("ViewPatientDialog", "Patients", nullptr));
        btn_close->setText(QString());
        btn_add->setText(QString());
        lbl_time->setText(QCoreApplication::translate("ViewPatientDialog", "10:09", nullptr));
        snackbar->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ViewPatientDialog: public Ui_ViewPatientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWPATIENTDIALOG_H
