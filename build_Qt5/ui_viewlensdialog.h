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
    QLabel *header_bg;
    QPushButton *btn_close;
    QLabel *lbl_lenses;
    QLabel *lbl_time;
    QTableWidget *table_lenses;
    QPushButton *btn_delete;
    QPushButton *btn_edit;
    QPushButton *btn_add;

    void setupUi(QDialog *ViewLensDialog)
    {
        if (ViewLensDialog->objectName().isEmpty())
            ViewLensDialog->setObjectName(QString::fromUtf8("ViewLensDialog"));
        ViewLensDialog->resize(1280, 720);
        ViewLensDialog->setStyleSheet(QString::fromUtf8("\n"
"QDialog{\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1,\n"
"		stop:0 #eef2f8, stop:1 #e4ebf5);\n"
"	font-family: \"Segoe UI\";\n"
"}"));
        header_bg = new QLabel(ViewLensDialog);
        header_bg->setObjectName(QString::fromUtf8("header_bg"));
        header_bg->setGeometry(QRect(0, 0, 1280, 90));
        header_bg->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0,\n"
"		stop:0 #1A5FB4, stop:0.55 #1976D2, stop:1 #2E9BDA);\n"
"	border-bottom-left-radius: 18px;\n"
"	border-bottom-right-radius: 18px;\n"
"}"));
        btn_close = new QPushButton(ViewLensDialog);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));
        btn_close->setGeometry(QRect(18, 15, 60, 60));
        btn_close->setCursor(QCursor(Qt::PointingHandCursor));
        btn_close->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgba(255,255,255,25);\n"
"	border: none;\n"
"	border-radius: 30px;\n"
"	border-image: url(:/images/icons/ic_arrow_back_white_48dp.png);\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgba(255,255,255,45);\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(255,255,255,70);\n"
"}"));
        btn_close->setFlat(true);
        lbl_lenses = new QLabel(ViewLensDialog);
        lbl_lenses->setObjectName(QString::fromUtf8("lbl_lenses"));
        lbl_lenses->setGeometry(QRect(0, 0, 1280, 90));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        lbl_lenses->setFont(font);
        lbl_lenses->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255,255,255);\n"
"letter-spacing: 1px;"));
        lbl_lenses->setAlignment(Qt::AlignCenter);
        lbl_time = new QLabel(ViewLensDialog);
        lbl_time->setObjectName(QString::fromUtf8("lbl_time"));
        lbl_time->setGeometry(QRect(1100, 25, 150, 40));
        QFont font1;
        font1.setPointSize(11);
        lbl_time->setFont(font1);
        lbl_time->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgba(255,255,255,220);\n"
"letter-spacing: 1px;"));
        lbl_time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
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
        table_lenses->setGeometry(QRect(40, 110, 1080, 560));
        table_lenses->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #ffffff;\n"
"    alternate-background-color: #f7f9fc;\n"
"    gridline-color: #e2e8f0;\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 16px;\n"
"    font-size: 14px;\n"
"    color: #1f2937;\n"
"    }\n"
"    QTableWidget::item {\n"
"    padding: 12px 14px;\n"
"    border-bottom: 1px solid #eef1f5;\n"
"    }\n"
"    QTableWidget::item:selected {\n"
"    background-color: #E3F0FD;\n"
"    color: #0b3d91;\n"
"    }\n"
"    QHeaderView::section {\n"
"    background-color: #F5F8FC;\n"
"    color: #374151;\n"
"    font-weight: 600;\n"
"    font-size: 13px;\n"
"    padding: 14px 10px;\n"
"    border: none;\n"
"    border-bottom: 2px solid #DCE3EA;\n"
"    }\n"
"    QTableCornerButton::section {\n"
"    background-color: #F5F8FC;\n"
"    border: none;\n"
"    }\n"
"    QScrollBar:vertical {\n"
"    width: 12px;\n"
"    background: #F5F8FC;\n"
"    border-radius: 6px;\n"
"    }\n"
"    QScrollBar::handle:vertical {\n"
"    background: #C3CEDC;\n"
"    border-radius: 6p"
                        "x;\n"
"    min-height: 30px;\n"
"    }\n"
"    QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"    }"));
        table_lenses->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_lenses->setAlternatingRowColors(true);
        table_lenses->horizontalHeader()->setDefaultSectionSize(108);
        btn_delete = new QPushButton(ViewLensDialog);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));
        btn_delete->setGeometry(QRect(1150, 235, 70, 70));
        btn_delete->setCursor(QCursor(Qt::PointingHandCursor));
        btn_delete->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #FDEAEC;\n"
"	border: 2px solid #F5C6CB;\n"
"	border-radius: 35px;\n"
"	border-image: url(:/images/delete-icon.png);\n"
"}\n"
"QPushButton:hover{\n"
"	border: 2px solid #EFA3AB;\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: #F9D2D7;\n"
"}"));
        btn_delete->setFlat(true);
        btn_edit = new QPushButton(ViewLensDialog);
        btn_edit->setObjectName(QString::fromUtf8("btn_edit"));
        btn_edit->setGeometry(QRect(1150, 335, 70, 70));
        btn_edit->setCursor(QCursor(Qt::PointingHandCursor));
        btn_edit->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #FDF3E7;\n"
"	border: 2px solid #F6DFC0;\n"
"	border-radius: 35px;\n"
"	border-image: url(:/images/edit-icon.png);\n"
"}\n"
"QPushButton:hover{\n"
"	border: 2px solid #EBC48C;\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: #F8E6C7;\n"
"}"));
        btn_edit->setFlat(true);
        btn_add = new QPushButton(ViewLensDialog);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));
        btn_add->setGeometry(QRect(1150, 435, 70, 70));
        btn_add->setCursor(QCursor(Qt::PointingHandCursor));
        btn_add->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #EAF7EF;\n"
"	border: 2px solid #C7ECD4;\n"
"	border-radius: 35px;\n"
"	border-image: url(:/images/add-icon.png);\n"
"}\n"
"QPushButton:hover{\n"
"	border: 2px solid #98DBAF;\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: #CFEEDA;\n"
"}"));
        btn_add->setFlat(true);
        header_bg->raise();
        lbl_lenses->raise();
        btn_close->raise();
        lbl_time->raise();
        table_lenses->raise();
        btn_delete->raise();
        btn_edit->raise();
        btn_add->raise();

        retranslateUi(ViewLensDialog);

        QMetaObject::connectSlotsByName(ViewLensDialog);
    } // setupUi

    void retranslateUi(QDialog *ViewLensDialog)
    {
        ViewLensDialog->setWindowTitle(QCoreApplication::translate("ViewLensDialog", "Dialog", nullptr));
        header_bg->setText(QString());
        btn_close->setText(QString());
        lbl_lenses->setText(QCoreApplication::translate("ViewLensDialog", "Lenses", nullptr));
        lbl_time->setText(QCoreApplication::translate("ViewLensDialog", "10:09", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table_lenses->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ViewLensDialog", "S.No", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table_lenses->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ViewLensDialog", "IOL", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table_lenses->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ViewLensDialog", "Company", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table_lenses->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ViewLensDialog", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table_lenses->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ViewLensDialog", "ASRKT", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table_lenses->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ViewLensDialog", "ASRKII", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = table_lenses->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("ViewLensDialog", "Acd", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = table_lenses->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("ViewLensDialog", "Sf", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = table_lenses->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("ViewLensDialog", "a0", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = table_lenses->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("ViewLensDialog", "a1", nullptr));
        btn_delete->setText(QString());
        btn_edit->setText(QString());
        btn_add->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ViewLensDialog: public Ui_ViewLensDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWLENSDIALOG_H
