/********************************************************************************
** Form generated from reading UI file 'viewlensdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWLENSDIALOG_H
#define UI_VIEWLENSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewLensDialog
{
public:
    QPushButton *btn_add;
    QPushButton *btn_delete;
    QPushButton *btn_edit;
    QPushButton *btn_close;
    QTableWidget *table_lenses;
    QLabel *lbl_lenses;
    QLabel *lbl_time;

    void setupUi(QDialog *ViewLensDialog)
    {
        if (ViewLensDialog->objectName().isEmpty())
            ViewLensDialog->setObjectName(QString::fromUtf8("ViewLensDialog"));
        ViewLensDialog->resize(1280, 720);
        ViewLensDialog->setStyleSheet(QString::fromUtf8("background-image: url(:/images/5.png);"));
        btn_add = new QPushButton(ViewLensDialog);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));
        btn_add->setGeometry(QRect(1140, 540, 85, 85));
        btn_add->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/add-icon.png);"));
        btn_add->setFlat(true);
        btn_delete = new QPushButton(ViewLensDialog);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));
        btn_delete->setGeometry(QRect(1140, 360, 85, 85));
        btn_delete->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/delete-icon.png);"));
        btn_delete->setFlat(true);
        btn_edit = new QPushButton(ViewLensDialog);
        btn_edit->setObjectName(QString::fromUtf8("btn_edit"));
        btn_edit->setGeometry(QRect(1140, 450, 85, 85));
        btn_edit->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/edit-icon.png);"));
        btn_edit->setFlat(true);
        btn_close = new QPushButton(ViewLensDialog);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));
        btn_close->setGeometry(QRect(0, 3, 81, 71));
        btn_close->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/icons/ic_arrow_back_white_48dp.png);"));
        btn_close->setFlat(true);
        table_lenses = new QTableWidget(ViewLensDialog);
        if (table_lenses->columnCount() < 10)
            table_lenses->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_lenses->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_lenses->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_lenses->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_lenses->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_lenses->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_lenses->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table_lenses->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table_lenses->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        table_lenses->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        table_lenses->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        if (table_lenses->rowCount() < 1)
            table_lenses->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        table_lenses->setVerticalHeaderItem(0, __qtablewidgetitem10);
        table_lenses->setObjectName(QString::fromUtf8("table_lenses"));
        table_lenses->setGeometry(QRect(50, 70, 1181, 631));
        table_lenses->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        table_lenses->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        table_lenses->horizontalHeader()->setDefaultSectionSize(79);
        lbl_lenses = new QLabel(ViewLensDialog);
        lbl_lenses->setObjectName(QString::fromUtf8("lbl_lenses"));
        lbl_lenses->setGeometry(QRect(540, 20, 160, 41));
        QFont font;
        font.setPointSize(16);
        lbl_lenses->setFont(font);
        lbl_lenses->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        lbl_lenses->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lbl_time = new QLabel(ViewLensDialog);
        lbl_time->setObjectName(QString::fromUtf8("lbl_time"));
        lbl_time->setGeometry(QRect(1119, 10, 151, 51));
        QFont font1;
        font1.setPointSize(11);
        lbl_time->setFont(font1);
        lbl_time->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        lbl_time->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        btn_close->raise();
        table_lenses->raise();
        lbl_lenses->raise();
        btn_delete->raise();
        btn_edit->raise();
        btn_add->raise();
        lbl_time->raise();

        retranslateUi(ViewLensDialog);

        QMetaObject::connectSlotsByName(ViewLensDialog);
    } // setupUi

    void retranslateUi(QDialog *ViewLensDialog)
    {
        ViewLensDialog->setWindowTitle(QCoreApplication::translate("ViewLensDialog", "Dialog", nullptr));
        btn_add->setText(QString());
        btn_delete->setText(QString());
        btn_edit->setText(QString());
        btn_close->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = table_lenses->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ViewLensDialog", "IOL", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table_lenses->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ViewLensDialog", "Company", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table_lenses->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ViewLensDialog", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table_lenses->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ViewLensDialog", "ASRKT", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table_lenses->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ViewLensDialog", "ASRKII", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table_lenses->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ViewLensDialog", "Acd", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = table_lenses->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("ViewLensDialog", "Sf", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = table_lenses->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("ViewLensDialog", "a0", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = table_lenses->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("ViewLensDialog", "a1", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = table_lenses->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("ViewLensDialog", "a2", nullptr));
        lbl_lenses->setText(QCoreApplication::translate("ViewLensDialog", "Lenses", nullptr));
        lbl_time->setText(QCoreApplication::translate("ViewLensDialog", "10:09", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewLensDialog: public Ui_ViewLensDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWLENSDIALOG_H
