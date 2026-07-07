/********************************************************************************
** Form generated from reading UI file 'viewdoctordialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWDOCTORDIALOG_H
#define UI_VIEWDOCTORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewDoctorDialog
{
public:
    QTableWidget *table_doctor;
    QPushButton *btn_delete;
    QPushButton *btn_edit;
    QPushButton *btn_close;
    QPushButton *btn_add;
    QPushButton *btn_view;
    QLabel *label;
    QLabel *lbl_time;
    QLabel *snackbar;

    void setupUi(QDialog *ViewDoctorDialog)
    {
        if (ViewDoctorDialog->objectName().isEmpty())
            ViewDoctorDialog->setObjectName(QString::fromUtf8("ViewDoctorDialog"));
        ViewDoctorDialog->resize(1280, 720);
        ViewDoctorDialog->setStyleSheet(QString::fromUtf8("background-image: url(:/images/5.png);"));
        table_doctor = new QTableWidget(ViewDoctorDialog);
        if (table_doctor->columnCount() < 6)
            table_doctor->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_doctor->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_doctor->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_doctor->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_doctor->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_doctor->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_doctor->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        table_doctor->setObjectName(QString::fromUtf8("table_doctor"));
        table_doctor->setGeometry(QRect(30, 70, 1221, 591));
        table_doctor->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        table_doctor->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        table_doctor->horizontalHeader()->setDefaultSectionSize(133);
        btn_delete = new QPushButton(ViewDoctorDialog);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));
        btn_delete->setGeometry(QRect(1160, 390, 85, 85));
        btn_delete->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/delete-icon.png);"));
        btn_delete->setFlat(true);
        btn_edit = new QPushButton(ViewDoctorDialog);
        btn_edit->setObjectName(QString::fromUtf8("btn_edit"));
        btn_edit->setGeometry(QRect(1160, 480, 85, 85));
        btn_edit->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/edit-icon.png);"));
        btn_edit->setFlat(true);
        btn_close = new QPushButton(ViewDoctorDialog);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));
        btn_close->setGeometry(QRect(0, 0, 71, 61));
        btn_close->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/icons/ic_arrow_back_white_48dp.png);"));
        btn_close->setFlat(true);
        btn_add = new QPushButton(ViewDoctorDialog);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));
        btn_add->setGeometry(QRect(1160, 570, 85, 85));
        btn_add->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/add-icon.png);"));
        btn_add->setFlat(true);
        btn_view = new QPushButton(ViewDoctorDialog);
        btn_view->setObjectName(QString::fromUtf8("btn_view"));
        btn_view->setGeometry(QRect(1160, 300, 85, 85));
        btn_view->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/view-icon.png);"));
        btn_view->setFlat(true);
        label = new QLabel(ViewDoctorDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(540, 0, 160, 70));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lbl_time = new QLabel(ViewDoctorDialog);
        lbl_time->setObjectName(QString::fromUtf8("lbl_time"));
        lbl_time->setGeometry(QRect(1139, 10, 131, 41));
        QFont font1;
        font1.setPointSize(11);
        lbl_time->setFont(font1);
        lbl_time->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        lbl_time->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        snackbar = new QLabel(ViewDoctorDialog);
        snackbar->setObjectName(QString::fromUtf8("snackbar"));
        snackbar->setGeometry(QRect(0, 670, 1281, 40));
        snackbar->setStyleSheet(QString::fromUtf8("border-image: url(:/images/alert-red.png);\n"
"background-image:url(empty.png);color:rgb(255,255,255);"));
        snackbar->setIndent(5);

        retranslateUi(ViewDoctorDialog);

        QMetaObject::connectSlotsByName(ViewDoctorDialog);
    } // setupUi

    void retranslateUi(QDialog *ViewDoctorDialog)
    {
        ViewDoctorDialog->setWindowTitle(QCoreApplication::translate("ViewDoctorDialog", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table_doctor->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ViewDoctorDialog", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table_doctor->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ViewDoctorDialog", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table_doctor->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ViewDoctorDialog", "Lens1", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table_doctor->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ViewDoctorDialog", "Lens2", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table_doctor->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ViewDoctorDialog", "Lens3", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table_doctor->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ViewDoctorDialog", "Formula", nullptr));
        btn_delete->setText(QString());
        btn_edit->setText(QString());
        btn_close->setText(QString());
        btn_add->setText(QString());
        btn_view->setText(QString());
        label->setText(QCoreApplication::translate("ViewDoctorDialog", "Doctors", nullptr));
        lbl_time->setText(QCoreApplication::translate("ViewDoctorDialog", "10:09", nullptr));
        snackbar->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ViewDoctorDialog: public Ui_ViewDoctorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWDOCTORDIALOG_H
