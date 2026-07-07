/********************************************************************************
** Form generated from reading UI file 'preferencesdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCESDIALOG_H
#define UI_PREFERENCESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PreferencesDialog
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_6;
    QLabel *label_12;
    QLineEdit *lineEdit_hospitalName;
    QLabel *label_13;
    QLineEdit *lineEdit_hospitalAddress;
    QLineEdit *lineEdit_currentDoctor;
    QLabel *label_15;
    QLineEdit *lineEdit_serialNumber;
    QLabel *label_26;
    QLabel *label_27;
    QLineEdit *lineEdit_softwareVersion;
    QLabel *lbl_qr;
    QLabel *lbl_qrImage;
    QPushButton *btn_save;
    QLabel *lbl_time;
    QWidget *page_2;
    QLabel *label_7;
    QLabel *lbl_patCount;
    QLabel *lbl_doctorCount;
    QLabel *lbl_lensCount;
    QLabel *lbl_totDiskSpace;
    QLabel *lbl_availDiskSpace;
    QProgressBar *progressBar_diskSpace;
    QLabel *lbl_scansCount;
    QPushButton *btn_clearScans;
    QWidget *page_3;
    QLabel *label_8;
    QLabel *label_21;
    QComboBox *comboBox_printer;
    QPushButton *btn_testPrint;
    QPushButton *but_save_printer;
    QWidget *page_4;
    QLabel *label_9;
    QLabel *label_22;
    QLineEdit *lineEdit_ssid;
    QLineEdit *lineEdit_psk;
    QLabel *label_23;
    QCheckBox *checkBox_pwdMask;
    QCheckBox *checkBox_clearSSID;
    QWidget *page_5;
    QLabel *label_10;
    QLabel *label_14;
    QTextBrowser *textBrowser;
    QPushButton *btn_restoreAll;
    QPushButton *btn_restoreSettings;
    QPushButton *btn_save_4;
    QWidget *page_6;
    QLabel *label_11;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *lineEdit_day;
    QLabel *label_18;
    QComboBox *comboBox_month;
    QLineEdit *lineEdit_year;
    QLabel *label_19;
    QLabel *label_20;
    QLineEdit *lineEdit_hour;
    QLineEdit *lineEdit_minute;
    QLabel *label_24;
    QLabel *label_25;
    QPushButton *but_save_date;
    QWidget *page_statistics;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLineEdit *lbl_totalScans;
    QLineEdit *lbl_scansPastWeek;
    QLineEdit *lbl_scansPastMonth;
    QLineEdit *lbl_scansToday;
    QWidget *page_7;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QLineEdit *lineEdit_acVelocity;
    QLabel *label_37;
    QLineEdit *lineEdit_lVelocity;
    QLabel *label_38;
    QLineEdit *lineEdit_vitVelocity;
    QLineEdit *lineEdit_avVelocity;
    QLabel *label_39;
    QPushButton *btn_back;
    QPushButton *logo_general;
    QLabel *lbl_general;
    QPushButton *logo_databases;
    QLabel *lbl_databases;
    QLabel *lbl_printer;
    QPushButton *logo_printer;
    QLabel *lbl_backup;
    QPushButton *logo_backuprestore;
    QPushButton *logo_network;
    QLabel *lbl_network;
    QLabel *snackbar;
    QLabel *lbl_datetime;
    QPushButton *logo_datetime;
    QLabel *lbl_stats;
    QPushButton *logo_stats;
    QLabel *lbl_measurement;
    QPushButton *logo_measure;
    QPushButton *btn_measurement;
    QPushButton *btn_backup;
    QPushButton *btn_statistics;
    QPushButton *btn_network;
    QPushButton *btn_printer;
    QPushButton *btn_databases;
    QPushButton *btn_general;
    QPushButton *btn_date_time;

    void setupUi(QDialog *PreferencesDialog)
    {
        if (PreferencesDialog->objectName().isEmpty())
            PreferencesDialog->setObjectName(QString::fromUtf8("PreferencesDialog"));
        PreferencesDialog->resize(1280, 720);
        PreferencesDialog->setStyleSheet(QString::fromUtf8("background-image: url(:/images/quick-settings-notexticon.png);\n"
"\n"
"/*background:rgb(240,240,246);*/"));
        stackedWidget = new QStackedWidget(PreferencesDialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(310, 0, 971, 671));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"background-image:url(empty.png);"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        label_6 = new QLabel(page);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(260, 10, 90, 30));
        QFont font;
        font.setPointSize(16);
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_12 = new QLabel(page);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 80, 140, 17));
        label_12->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        lineEdit_hospitalName = new QLineEdit(page);
        lineEdit_hospitalName->setObjectName(QString::fromUtf8("lineEdit_hospitalName"));
        lineEdit_hospitalName->setGeometry(QRect(160, 76, 260, 25));
        lineEdit_hospitalName->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        label_13 = new QLabel(page);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 120, 140, 17));
        label_13->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        lineEdit_hospitalAddress = new QLineEdit(page);
        lineEdit_hospitalAddress->setObjectName(QString::fromUtf8("lineEdit_hospitalAddress"));
        lineEdit_hospitalAddress->setGeometry(QRect(160, 120, 420, 25));
        lineEdit_hospitalAddress->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        lineEdit_currentDoctor = new QLineEdit(page);
        lineEdit_currentDoctor->setObjectName(QString::fromUtf8("lineEdit_currentDoctor"));
        lineEdit_currentDoctor->setGeometry(QRect(160, 170, 260, 25));
        lineEdit_currentDoctor->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        label_15 = new QLabel(page);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 174, 140, 17));
        label_15->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        lineEdit_serialNumber = new QLineEdit(page);
        lineEdit_serialNumber->setObjectName(QString::fromUtf8("lineEdit_serialNumber"));
        lineEdit_serialNumber->setGeometry(QRect(160, 216, 260, 25));
        lineEdit_serialNumber->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        label_26 = new QLabel(page);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(10, 220, 140, 17));
        label_26->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        label_27 = new QLabel(page);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(10, 264, 140, 17));
        label_27->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        lineEdit_softwareVersion = new QLineEdit(page);
        lineEdit_softwareVersion->setObjectName(QString::fromUtf8("lineEdit_softwareVersion"));
        lineEdit_softwareVersion->setGeometry(QRect(160, 260, 260, 25));
        lineEdit_softwareVersion->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        lbl_qr = new QLabel(page);
        lbl_qr->setObjectName(QString::fromUtf8("lbl_qr"));
        lbl_qr->setGeometry(QRect(20, 310, 130, 17));
        lbl_qr->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        lbl_qrImage = new QLabel(page);
        lbl_qrImage->setObjectName(QString::fromUtf8("lbl_qrImage"));
        lbl_qrImage->setGeometry(QRect(20, 350, 130, 140));
        lbl_qrImage->setStyleSheet(QString::fromUtf8("border-image:url(/home/adityan/res.bmp);background-image:url(empty.png);"));
        btn_save = new QPushButton(page);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));
        btn_save->setGeometry(QRect(880, 580, 80, 80));
        btn_save->setStyleSheet(QString::fromUtf8("border-image: url(:/images/save-icon.png);\n"
"background-image:url(empty.png);\n"
""));
        btn_save->setFlat(true);
        lbl_time = new QLabel(page);
        lbl_time->setObjectName(QString::fromUtf8("lbl_time"));
        lbl_time->setGeometry(QRect(820, 10, 120, 40));
        QFont font1;
        font1.setPointSize(11);
        lbl_time->setFont(font1);
        lbl_time->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        lbl_time->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label_7 = new QLabel(page_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(259, 10, 110, 30));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lbl_patCount = new QLabel(page_2);
        lbl_patCount->setObjectName(QString::fromUtf8("lbl_patCount"));
        lbl_patCount->setGeometry(QRect(20, 70, 220, 17));
        lbl_doctorCount = new QLabel(page_2);
        lbl_doctorCount->setObjectName(QString::fromUtf8("lbl_doctorCount"));
        lbl_doctorCount->setGeometry(QRect(20, 120, 240, 17));
        lbl_lensCount = new QLabel(page_2);
        lbl_lensCount->setObjectName(QString::fromUtf8("lbl_lensCount"));
        lbl_lensCount->setGeometry(QRect(20, 170, 230, 17));
        lbl_totDiskSpace = new QLabel(page_2);
        lbl_totDiskSpace->setObjectName(QString::fromUtf8("lbl_totDiskSpace"));
        lbl_totDiskSpace->setGeometry(QRect(20, 280, 280, 17));
        lbl_availDiskSpace = new QLabel(page_2);
        lbl_availDiskSpace->setObjectName(QString::fromUtf8("lbl_availDiskSpace"));
        lbl_availDiskSpace->setGeometry(QRect(20, 320, 300, 17));
        progressBar_diskSpace = new QProgressBar(page_2);
        progressBar_diskSpace->setObjectName(QString::fromUtf8("progressBar_diskSpace"));
        progressBar_diskSpace->setGeometry(QRect(30, 350, 560, 23));
        progressBar_diskSpace->setValue(0);
        progressBar_diskSpace->setAlignment(Qt::AlignmentFlag::AlignCenter);
        progressBar_diskSpace->setTextDirection(QProgressBar::Direction::TopToBottom);
        lbl_scansCount = new QLabel(page_2);
        lbl_scansCount->setObjectName(QString::fromUtf8("lbl_scansCount"));
        lbl_scansCount->setGeometry(QRect(20, 210, 230, 17));
        btn_clearScans = new QPushButton(page_2);
        btn_clearScans->setObjectName(QString::fromUtf8("btn_clearScans"));
        btn_clearScans->setGeometry(QRect(80, 233, 130, 40));
        btn_clearScans->setAutoFillBackground(false);
        btn_clearScans->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"color: rgb(255, 255, 255);\n"
"background-color: #1976D2;\n"
"border-radius:5px;"));
        btn_clearScans->setFlat(false);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        label_8 = new QLabel(page_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(260, 10, 90, 30));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_21 = new QLabel(page_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(20, 70, 130, 17));
        label_21->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        comboBox_printer = new QComboBox(page_3);
        comboBox_printer->setObjectName(QString::fromUtf8("comboBox_printer"));
        comboBox_printer->setGeometry(QRect(150, 69, 270, 30));
        comboBox_printer->setStyleSheet(QString::fromUtf8(""));
        btn_testPrint = new QPushButton(page_3);
        btn_testPrint->setObjectName(QString::fromUtf8("btn_testPrint"));
        btn_testPrint->setGeometry(QRect(150, 130, 130, 50));
        btn_testPrint->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"color: rgb(255, 255, 255);\n"
"background-color: #1976D2;\n"
"border-radius:5px;"));
        btn_testPrint->setFlat(true);
        but_save_printer = new QPushButton(page_3);
        but_save_printer->setObjectName(QString::fromUtf8("but_save_printer"));
        but_save_printer->setGeometry(QRect(500, 470, 80, 80));
        but_save_printer->setStyleSheet(QString::fromUtf8("border-image: url(:/images/save-icon.png);\n"
"background-image:url(empty.png);\n"
""));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        label_9 = new QLabel(page_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(260, 10, 90, 30));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label_9->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_22 = new QLabel(page_4);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(30, 80, 67, 17));
        label_22->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        lineEdit_ssid = new QLineEdit(page_4);
        lineEdit_ssid->setObjectName(QString::fromUtf8("lineEdit_ssid"));
        lineEdit_ssid->setGeometry(QRect(110, 80, 260, 25));
        lineEdit_ssid->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        lineEdit_psk = new QLineEdit(page_4);
        lineEdit_psk->setObjectName(QString::fromUtf8("lineEdit_psk"));
        lineEdit_psk->setGeometry(QRect(110, 140, 260, 25));
        lineEdit_psk->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        lineEdit_psk->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        label_23 = new QLabel(page_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(30, 140, 67, 17));
        label_23->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        checkBox_pwdMask = new QCheckBox(page_4);
        checkBox_pwdMask->setObjectName(QString::fromUtf8("checkBox_pwdMask"));
        checkBox_pwdMask->setGeometry(QRect(390, 140, 92, 23));
        checkBox_pwdMask->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        checkBox_clearSSID = new QCheckBox(page_4);
        checkBox_clearSSID->setObjectName(QString::fromUtf8("checkBox_clearSSID"));
        checkBox_clearSSID->setGeometry(QRect(110, 190, 180, 23));
        checkBox_clearSSID->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        checkBox_clearSSID->setChecked(true);
        checkBox_clearSSID->setTristate(false);
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        label_10 = new QLabel(page_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(210, 10, 200, 30));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label_10->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_14 = new QLabel(page_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(80, 60, 110, 30));
        label_14->setFont(font);
        label_14->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label_14->setAlignment(Qt::AlignmentFlag::AlignCenter);
        textBrowser = new QTextBrowser(page_5);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(40, 110, 520, 120));
        textBrowser->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        btn_restoreAll = new QPushButton(page_5);
        btn_restoreAll->setObjectName(QString::fromUtf8("btn_restoreAll"));
        btn_restoreAll->setGeometry(QRect(60, 250, 480, 65));
        btn_restoreAll->setAutoFillBackground(false);
        btn_restoreAll->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"color: rgb(255, 255, 255);\n"
"background-color: #1976D2;\n"
"border-radius:5px;"));
        btn_restoreAll->setFlat(false);
        btn_restoreSettings = new QPushButton(page_5);
        btn_restoreSettings->setObjectName(QString::fromUtf8("btn_restoreSettings"));
        btn_restoreSettings->setGeometry(QRect(60, 340, 480, 65));
        btn_restoreSettings->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"color: #1976D2;\n"
"border: 1px solid #1976D2;\n"
"border-radius:5px;"));
        btn_restoreSettings->setFlat(true);
        btn_save_4 = new QPushButton(page_5);
        btn_save_4->setObjectName(QString::fromUtf8("btn_save_4"));
        btn_save_4->setGeometry(QRect(40, 60, 30, 30));
        btn_save_4->setAutoFillBackground(false);
        btn_save_4->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
"border-image: url(:/images/icons/ic_warning_white_96dp.png);\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(239, 41, 41);\n"
"border-radius:15px;"));
        btn_save_4->setFlat(false);
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        label_11 = new QLabel(page_6);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(260, 10, 130, 30));
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        label_11->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_16 = new QLabel(page_6);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 90, 130, 30));
        label_16->setFont(font);
        label_16->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        label_16->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_17 = new QLabel(page_6);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(20, 140, 60, 30));
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        label_17->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_day = new QLineEdit(page_6);
        lineEdit_day->setObjectName(QString::fromUtf8("lineEdit_day"));
        lineEdit_day->setGeometry(QRect(30, 180, 70, 50));
        lineEdit_day->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        label_18 = new QLabel(page_6);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(120, 140, 80, 30));
        label_18->setFont(font);
        label_18->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        label_18->setAlignment(Qt::AlignmentFlag::AlignCenter);
        comboBox_month = new QComboBox(page_6);
        comboBox_month->addItem(QString());
        comboBox_month->addItem(QString());
        comboBox_month->addItem(QString());
        comboBox_month->addItem(QString());
        comboBox_month->addItem(QString());
        comboBox_month->addItem(QString());
        comboBox_month->addItem(QString());
        comboBox_month->addItem(QString());
        comboBox_month->addItem(QString());
        comboBox_month->addItem(QString());
        comboBox_month->addItem(QString());
        comboBox_month->addItem(QString());
        comboBox_month->setObjectName(QString::fromUtf8("comboBox_month"));
        comboBox_month->setGeometry(QRect(130, 180, 130, 25));
        comboBox_month->setStyleSheet(QString::fromUtf8(""));
        lineEdit_year = new QLineEdit(page_6);
        lineEdit_year->setObjectName(QString::fromUtf8("lineEdit_year"));
        lineEdit_year->setGeometry(QRect(290, 180, 90, 50));
        lineEdit_year->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        label_19 = new QLabel(page_6);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(280, 140, 60, 30));
        label_19->setFont(font);
        label_19->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        label_19->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_20 = new QLabel(page_6);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(20, 280, 60, 30));
        label_20->setFont(font);
        label_20->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        label_20->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_hour = new QLineEdit(page_6);
        lineEdit_hour->setObjectName(QString::fromUtf8("lineEdit_hour"));
        lineEdit_hour->setGeometry(QRect(30, 320, 70, 50));
        lineEdit_hour->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        lineEdit_minute = new QLineEdit(page_6);
        lineEdit_minute->setObjectName(QString::fromUtf8("lineEdit_minute"));
        lineEdit_minute->setGeometry(QRect(130, 320, 70, 50));
        lineEdit_minute->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        label_24 = new QLabel(page_6);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(120, 280, 80, 30));
        label_24->setFont(font);
        label_24->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        label_24->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_25 = new QLabel(page_6);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(0, 240, 310, 30));
        label_25->setFont(font);
        label_25->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        label_25->setAlignment(Qt::AlignmentFlag::AlignCenter);
        but_save_date = new QPushButton(page_6);
        but_save_date->setObjectName(QString::fromUtf8("but_save_date"));
        but_save_date->setGeometry(QRect(500, 470, 80, 80));
        but_save_date->setStyleSheet(QString::fromUtf8("border-image: url(:/images/save-icon.png);\n"
"background-image:url(empty.png);\n"
""));
        stackedWidget->addWidget(page_6);
        page_statistics = new QWidget();
        page_statistics->setObjectName(QString::fromUtf8("page_statistics"));
        label_29 = new QLabel(page_statistics);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(260, 10, 110, 30));
        QFont font2;
        font2.setPointSize(14);
        label_29->setFont(font2);
        label_29->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);color:rgb(21,21,21);"));
        label_29->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_30 = new QLabel(page_statistics);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(30, 70, 120, 30));
        label_30->setFont(font2);
        label_30->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);color:rgb(21,21,21);"));
        label_30->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_31 = new QLabel(page_statistics);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(30, 130, 180, 30));
        label_31->setFont(font2);
        label_31->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);color:rgb(21,21,21);"));
        label_31->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_32 = new QLabel(page_statistics);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(30, 190, 190, 30));
        label_32->setFont(font2);
        label_32->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);color:rgb(21,21,21);"));
        label_32->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_33 = new QLabel(page_statistics);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(30, 250, 220, 30));
        label_33->setFont(font2);
        label_33->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);color:rgb(21,21,21);"));
        label_33->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lbl_totalScans = new QLineEdit(page_statistics);
        lbl_totalScans->setObjectName(QString::fromUtf8("lbl_totalScans"));
        lbl_totalScans->setGeometry(QRect(260, 60, 120, 50));
        lbl_totalScans->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        lbl_scansPastWeek = new QLineEdit(page_statistics);
        lbl_scansPastWeek->setObjectName(QString::fromUtf8("lbl_scansPastWeek"));
        lbl_scansPastWeek->setGeometry(QRect(260, 120, 120, 50));
        lbl_scansPastWeek->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        lbl_scansPastMonth = new QLineEdit(page_statistics);
        lbl_scansPastMonth->setObjectName(QString::fromUtf8("lbl_scansPastMonth"));
        lbl_scansPastMonth->setGeometry(QRect(260, 180, 120, 50));
        lbl_scansPastMonth->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        lbl_scansToday = new QLineEdit(page_statistics);
        lbl_scansToday->setObjectName(QString::fromUtf8("lbl_scansToday"));
        lbl_scansToday->setGeometry(QRect(260, 240, 120, 50));
        lbl_scansToday->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        stackedWidget->addWidget(page_statistics);
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        label_34 = new QLabel(page_7);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(260, 10, 130, 30));
        label_34->setFont(font2);
        label_34->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);color:rgb(21,21,21);"));
        label_34->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_35 = new QLabel(page_7);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(10, 60, 130, 30));
        label_35->setFont(font2);
        label_35->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);color:rgb(21,21,21);"));
        label_35->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_36 = new QLabel(page_7);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(30, 110, 180, 30));
        label_36->setFont(font2);
        label_36->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);color:rgb(21,21,21);"));
        label_36->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_acVelocity = new QLineEdit(page_7);
        lineEdit_acVelocity->setObjectName(QString::fromUtf8("lineEdit_acVelocity"));
        lineEdit_acVelocity->setGeometry(QRect(60, 150, 100, 60));
        lineEdit_acVelocity->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        label_37 = new QLabel(page_7);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(220, 110, 180, 30));
        label_37->setFont(font2);
        label_37->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);color:rgb(21,21,21);"));
        label_37->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_lVelocity = new QLineEdit(page_7);
        lineEdit_lVelocity->setObjectName(QString::fromUtf8("lineEdit_lVelocity"));
        lineEdit_lVelocity->setGeometry(QRect(260, 150, 100, 60));
        lineEdit_lVelocity->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        label_38 = new QLabel(page_7);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(420, 110, 180, 30));
        label_38->setFont(font2);
        label_38->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);color:rgb(21,21,21);"));
        label_38->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_vitVelocity = new QLineEdit(page_7);
        lineEdit_vitVelocity->setObjectName(QString::fromUtf8("lineEdit_vitVelocity"));
        lineEdit_vitVelocity->setGeometry(QRect(460, 150, 100, 60));
        lineEdit_vitVelocity->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        lineEdit_avVelocity = new QLineEdit(page_7);
        lineEdit_avVelocity->setObjectName(QString::fromUtf8("lineEdit_avVelocity"));
        lineEdit_avVelocity->setGeometry(QRect(60, 260, 100, 60));
        lineEdit_avVelocity->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);border-image:url(empty.png);"));
        label_39 = new QLabel(page_7);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(30, 220, 180, 30));
        label_39->setFont(font2);
        label_39->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);color:rgb(21,21,21);"));
        label_39->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(page_7);
        btn_back = new QPushButton(PreferencesDialog);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(1, 0, 71, 71));
        btn_back->setStyleSheet(QString::fromUtf8("border-image: url(:/images/icons/ic_arrow_back_white_48dp.png);"));
        btn_back->setFlat(true);
        logo_general = new QPushButton(PreferencesDialog);
        logo_general->setObjectName(QString::fromUtf8("logo_general"));
        logo_general->setGeometry(QRect(0, 70, 61, 61));
        logo_general->setStyleSheet(QString::fromUtf8("border-image: url(:/images/icons/ic_info_white_48dp.png);"));
        logo_general->setFlat(true);
        lbl_general = new QLabel(PreferencesDialog);
        lbl_general->setObjectName(QString::fromUtf8("lbl_general"));
        lbl_general->setGeometry(QRect(80, 90, 120, 17));
        lbl_general->setFont(font2);
        lbl_general->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        logo_databases = new QPushButton(PreferencesDialog);
        logo_databases->setObjectName(QString::fromUtf8("logo_databases"));
        logo_databases->setGeometry(QRect(0, 140, 61, 61));
        logo_databases->setStyleSheet(QString::fromUtf8("border-image: url(:/images/icons/ic_folder_shared_white_48dp.png);"));
        logo_databases->setFlat(true);
        lbl_databases = new QLabel(PreferencesDialog);
        lbl_databases->setObjectName(QString::fromUtf8("lbl_databases"));
        lbl_databases->setGeometry(QRect(80, 160, 100, 17));
        lbl_databases->setFont(font2);
        lbl_databases->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        lbl_printer = new QLabel(PreferencesDialog);
        lbl_printer->setObjectName(QString::fromUtf8("lbl_printer"));
        lbl_printer->setGeometry(QRect(80, 240, 70, 17));
        lbl_printer->setFont(font2);
        lbl_printer->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        logo_printer = new QPushButton(PreferencesDialog);
        logo_printer->setObjectName(QString::fromUtf8("logo_printer"));
        logo_printer->setGeometry(QRect(0, 210, 61, 61));
        logo_printer->setStyleSheet(QString::fromUtf8("border-image:url(:/images/icons/ic_print_white_48dp.png)"));
        logo_printer->setFlat(true);
        lbl_backup = new QLabel(PreferencesDialog);
        lbl_backup->setObjectName(QString::fromUtf8("lbl_backup"));
        lbl_backup->setGeometry(QRect(80, 550, 120, 17));
        lbl_backup->setFont(font2);
        lbl_backup->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        logo_backuprestore = new QPushButton(PreferencesDialog);
        logo_backuprestore->setObjectName(QString::fromUtf8("logo_backuprestore"));
        logo_backuprestore->setGeometry(QRect(0, 530, 61, 61));
        logo_backuprestore->setStyleSheet(QString::fromUtf8("border-image: url(:/images/icons/ic_settings_backup_restore_white_48dp.png);"));
        logo_backuprestore->setFlat(true);
        logo_network = new QPushButton(PreferencesDialog);
        logo_network->setObjectName(QString::fromUtf8("logo_network"));
        logo_network->setGeometry(QRect(4, 280, 61, 61));
        logo_network->setStyleSheet(QString::fromUtf8("border-image: url(:/images/icons/ic_network_wifi_white_48dp.png);"));
        logo_network->setFlat(true);
        lbl_network = new QLabel(PreferencesDialog);
        lbl_network->setObjectName(QString::fromUtf8("lbl_network"));
        lbl_network->setGeometry(QRect(80, 300, 120, 17));
        lbl_network->setFont(font2);
        lbl_network->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        snackbar = new QLabel(PreferencesDialog);
        snackbar->setObjectName(QString::fromUtf8("snackbar"));
        snackbar->setGeometry(QRect(0, 680, 1281, 43));
        snackbar->setStyleSheet(QString::fromUtf8("border-image: url(:/images/alert-red.png);\n"
"background-image:url(empty.png);color:rgb(255,255,255);"));
        snackbar->setIndent(5);
        lbl_datetime = new QLabel(PreferencesDialog);
        lbl_datetime->setObjectName(QString::fromUtf8("lbl_datetime"));
        lbl_datetime->setGeometry(QRect(80, 380, 120, 17));
        lbl_datetime->setFont(font2);
        lbl_datetime->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        logo_datetime = new QPushButton(PreferencesDialog);
        logo_datetime->setObjectName(QString::fromUtf8("logo_datetime"));
        logo_datetime->setGeometry(QRect(0, 360, 61, 61));
        logo_datetime->setStyleSheet(QString::fromUtf8("border-image: url(:/images/icons/ic_access_time_white_48dp.png);"));
        logo_datetime->setFlat(true);
        lbl_stats = new QLabel(PreferencesDialog);
        lbl_stats->setObjectName(QString::fromUtf8("lbl_stats"));
        lbl_stats->setGeometry(QRect(80, 470, 120, 17));
        lbl_stats->setFont(font2);
        lbl_stats->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        logo_stats = new QPushButton(PreferencesDialog);
        logo_stats->setObjectName(QString::fromUtf8("logo_stats"));
        logo_stats->setGeometry(QRect(0, 450, 61, 61));
        logo_stats->setStyleSheet(QString::fromUtf8("border-image: url(:/images/icons/ic_assessment_white_48dp.png);"));
        logo_stats->setFlat(true);
        lbl_measurement = new QLabel(PreferencesDialog);
        lbl_measurement->setObjectName(QString::fromUtf8("lbl_measurement"));
        lbl_measurement->setGeometry(QRect(90, 630, 120, 17));
        lbl_measurement->setFont(font2);
        lbl_measurement->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        logo_measure = new QPushButton(PreferencesDialog);
        logo_measure->setObjectName(QString::fromUtf8("logo_measure"));
        logo_measure->setGeometry(QRect(10, 610, 61, 61));
        logo_measure->setStyleSheet(QString::fromUtf8("border-image: url(:/images/icons/ic_developer_board_white_48dp.png);"));
        logo_measure->setFlat(true);
        btn_measurement = new QPushButton(PreferencesDialog);
        btn_measurement->setObjectName(QString::fromUtf8("btn_measurement"));
        btn_measurement->setGeometry(QRect(0, 610, 311, 61));
        btn_measurement->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        btn_measurement->setFlat(true);
        btn_backup = new QPushButton(PreferencesDialog);
        btn_backup->setObjectName(QString::fromUtf8("btn_backup"));
        btn_backup->setGeometry(QRect(-1, 529, 311, 61));
        btn_backup->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        btn_backup->setFlat(true);
        btn_statistics = new QPushButton(PreferencesDialog);
        btn_statistics->setObjectName(QString::fromUtf8("btn_statistics"));
        btn_statistics->setGeometry(QRect(0, 450, 311, 61));
        btn_statistics->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        btn_statistics->setFlat(true);
        btn_network = new QPushButton(PreferencesDialog);
        btn_network->setObjectName(QString::fromUtf8("btn_network"));
        btn_network->setGeometry(QRect(0, 280, 311, 61));
        btn_network->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        btn_network->setFlat(true);
        btn_printer = new QPushButton(PreferencesDialog);
        btn_printer->setObjectName(QString::fromUtf8("btn_printer"));
        btn_printer->setGeometry(QRect(0, 200, 311, 71));
        btn_printer->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        btn_printer->setFlat(true);
        btn_databases = new QPushButton(PreferencesDialog);
        btn_databases->setObjectName(QString::fromUtf8("btn_databases"));
        btn_databases->setGeometry(QRect(0, 130, 311, 61));
        btn_databases->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        btn_databases->setFlat(true);
        btn_general = new QPushButton(PreferencesDialog);
        btn_general->setObjectName(QString::fromUtf8("btn_general"));
        btn_general->setGeometry(QRect(0, 70, 311, 61));
        btn_general->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);"));
        btn_general->setFlat(true);
        btn_date_time = new QPushButton(PreferencesDialog);
        btn_date_time->setObjectName(QString::fromUtf8("btn_date_time"));
        btn_date_time->setGeometry(QRect(0, 360, 311, 61));
        btn_date_time->setStyleSheet(QString::fromUtf8("background-image:url(empty.png);\n"
""));
        btn_date_time->setFlat(true);

        retranslateUi(PreferencesDialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PreferencesDialog);
    } // setupUi

    void retranslateUi(QDialog *PreferencesDialog)
    {
        PreferencesDialog->setWindowTitle(QCoreApplication::translate("PreferencesDialog", "Dialog", nullptr));
        label_6->setText(QCoreApplication::translate("PreferencesDialog", "General", nullptr));
        label_12->setText(QCoreApplication::translate("PreferencesDialog", "Hospital Name", nullptr));
        label_13->setText(QCoreApplication::translate("PreferencesDialog", "Address", nullptr));
        label_15->setText(QCoreApplication::translate("PreferencesDialog", "Current Doctor", nullptr));
        label_26->setText(QCoreApplication::translate("PreferencesDialog", "Serial Number", nullptr));
        label_27->setText(QCoreApplication::translate("PreferencesDialog", "Software Version", nullptr));
        lbl_qr->setText(QCoreApplication::translate("PreferencesDialog", "More Info", nullptr));
        lbl_qrImage->setText(QString());
        btn_save->setText(QString());
        lbl_time->setText(QCoreApplication::translate("PreferencesDialog", "10:09", nullptr));
        label_7->setText(QCoreApplication::translate("PreferencesDialog", "Databases", nullptr));
        lbl_patCount->setStyleSheet(QCoreApplication::translate("PreferencesDialog", "background-image:url(empty.png);border-image:url(empty.png);", nullptr));
        lbl_patCount->setText(QCoreApplication::translate("PreferencesDialog", "Patients", nullptr));
        lbl_doctorCount->setStyleSheet(QCoreApplication::translate("PreferencesDialog", "background-image:url(empty.png);border-image:url(empty.png);", nullptr));
        lbl_doctorCount->setText(QCoreApplication::translate("PreferencesDialog", "Doctors", nullptr));
        lbl_lensCount->setStyleSheet(QCoreApplication::translate("PreferencesDialog", "background-image:url(empty.png);border-image:url(empty.png);", nullptr));
        lbl_lensCount->setText(QCoreApplication::translate("PreferencesDialog", "Lens", nullptr));
        lbl_totDiskSpace->setStyleSheet(QCoreApplication::translate("PreferencesDialog", "background-image:url(empty.png);border-image:url(empty.png);", nullptr));
        lbl_totDiskSpace->setText(QCoreApplication::translate("PreferencesDialog", "Total Disk Space", nullptr));
        lbl_availDiskSpace->setStyleSheet(QCoreApplication::translate("PreferencesDialog", "background-image:url(empty.png);border-image:url(empty.png);", nullptr));
        lbl_availDiskSpace->setText(QCoreApplication::translate("PreferencesDialog", "Available Disk Space", nullptr));
        lbl_scansCount->setStyleSheet(QCoreApplication::translate("PreferencesDialog", "background-image:url(empty.png);border-image:url(empty.png);", nullptr));
        lbl_scansCount->setText(QCoreApplication::translate("PreferencesDialog", "Scans", nullptr));
        btn_clearScans->setText(QCoreApplication::translate("PreferencesDialog", "Clear scans", nullptr));
        label_8->setText(QCoreApplication::translate("PreferencesDialog", "Printer", nullptr));
        label_21->setText(QCoreApplication::translate("PreferencesDialog", "Printer Port", nullptr));
        btn_testPrint->setText(QCoreApplication::translate("PreferencesDialog", "Test port", nullptr));
        but_save_printer->setText(QString());
        label_9->setText(QCoreApplication::translate("PreferencesDialog", "Network", nullptr));
        label_22->setText(QCoreApplication::translate("PreferencesDialog", "SSID", nullptr));
        label_23->setText(QCoreApplication::translate("PreferencesDialog", "PSK", nullptr));
        checkBox_pwdMask->setText(QCoreApplication::translate("PreferencesDialog", "Show", nullptr));
        checkBox_clearSSID->setText(QCoreApplication::translate("PreferencesDialog", "Clear existing entries", nullptr));
        label_10->setText(QCoreApplication::translate("PreferencesDialog", "Backup & Restore", nullptr));
        label_14->setText(QCoreApplication::translate("PreferencesDialog", "Warning", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("PreferencesDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">All database and system settings including scans saved would be reverted to the factory defaults if you press the Restore All button. Changes cannot be undone.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right"
                        ":0px; -qt-block-indent:0; text-indent:0px;\"> If you wish to not disturb the scan records please press the Restore Settings button. </p></body></html>", nullptr));
        btn_restoreAll->setText(QCoreApplication::translate("PreferencesDialog", " Restore All to Factory Settings ( Includes Scans)", nullptr));
        btn_restoreSettings->setText(QCoreApplication::translate("PreferencesDialog", " Restore Preferences to Factory Settings (Excludes Scans)", nullptr));
        btn_save_4->setText(QString());
        label_11->setText(QCoreApplication::translate("PreferencesDialog", "Date & Time", nullptr));
        label_16->setText(QCoreApplication::translate("PreferencesDialog", "Set Date", nullptr));
        label_17->setText(QCoreApplication::translate("PreferencesDialog", "Day", nullptr));
        label_18->setText(QCoreApplication::translate("PreferencesDialog", "Month", nullptr));
        comboBox_month->setItemText(0, QCoreApplication::translate("PreferencesDialog", "January", nullptr));
        comboBox_month->setItemText(1, QCoreApplication::translate("PreferencesDialog", "February", nullptr));
        comboBox_month->setItemText(2, QCoreApplication::translate("PreferencesDialog", "March", nullptr));
        comboBox_month->setItemText(3, QCoreApplication::translate("PreferencesDialog", "April", nullptr));
        comboBox_month->setItemText(4, QCoreApplication::translate("PreferencesDialog", "May", nullptr));
        comboBox_month->setItemText(5, QCoreApplication::translate("PreferencesDialog", "June", nullptr));
        comboBox_month->setItemText(6, QCoreApplication::translate("PreferencesDialog", "July", nullptr));
        comboBox_month->setItemText(7, QCoreApplication::translate("PreferencesDialog", "August", nullptr));
        comboBox_month->setItemText(8, QCoreApplication::translate("PreferencesDialog", "September", nullptr));
        comboBox_month->setItemText(9, QCoreApplication::translate("PreferencesDialog", "October", nullptr));
        comboBox_month->setItemText(10, QCoreApplication::translate("PreferencesDialog", "November", nullptr));
        comboBox_month->setItemText(11, QCoreApplication::translate("PreferencesDialog", "December", nullptr));

        label_19->setText(QCoreApplication::translate("PreferencesDialog", "Year", nullptr));
        label_20->setText(QCoreApplication::translate("PreferencesDialog", "Hour", nullptr));
        label_24->setText(QCoreApplication::translate("PreferencesDialog", "Minute", nullptr));
        label_25->setText(QCoreApplication::translate("PreferencesDialog", "Set Time (24 hour format)", nullptr));
        but_save_date->setText(QString());
        label_29->setText(QCoreApplication::translate("PreferencesDialog", "Statistics", nullptr));
        label_30->setText(QCoreApplication::translate("PreferencesDialog", "Total Scans", nullptr));
        label_31->setText(QCoreApplication::translate("PreferencesDialog", "Scans in past week", nullptr));
        label_32->setText(QCoreApplication::translate("PreferencesDialog", "Scans in past month", nullptr));
        label_33->setText(QCoreApplication::translate("PreferencesDialog", "Scans performed today", nullptr));
        label_34->setText(QCoreApplication::translate("PreferencesDialog", "Measurement", nullptr));
        label_35->setText(QCoreApplication::translate("PreferencesDialog", "Velocity", nullptr));
        label_36->setText(QCoreApplication::translate("PreferencesDialog", "Anterior Chamber", nullptr));
        label_37->setText(QCoreApplication::translate("PreferencesDialog", "Lens", nullptr));
        label_38->setText(QCoreApplication::translate("PreferencesDialog", "Vitreous", nullptr));
        label_39->setText(QCoreApplication::translate("PreferencesDialog", "Average Velocity", nullptr));
        btn_back->setText(QString());
        logo_general->setText(QString());
        lbl_general->setText(QCoreApplication::translate("PreferencesDialog", "General", nullptr));
        logo_databases->setText(QString());
        lbl_databases->setText(QCoreApplication::translate("PreferencesDialog", "Databases", nullptr));
        lbl_printer->setText(QCoreApplication::translate("PreferencesDialog", "Printer", nullptr));
        logo_printer->setText(QString());
        lbl_backup->setText(QCoreApplication::translate("PreferencesDialog", "Backup & Restore", nullptr));
        logo_backuprestore->setText(QString());
        logo_network->setText(QString());
        lbl_network->setText(QCoreApplication::translate("PreferencesDialog", "Network", nullptr));
        snackbar->setText(QString());
        lbl_datetime->setText(QCoreApplication::translate("PreferencesDialog", "Date & Time", nullptr));
        logo_datetime->setText(QString());
        lbl_stats->setText(QCoreApplication::translate("PreferencesDialog", "Statistics", nullptr));
        logo_stats->setText(QString());
        lbl_measurement->setText(QCoreApplication::translate("PreferencesDialog", "Measurement", nullptr));
        logo_measure->setText(QString());
        btn_measurement->setText(QString());
        btn_backup->setText(QString());
        btn_statistics->setText(QString());
        btn_network->setText(QString());
        btn_printer->setText(QString());
        btn_databases->setText(QString());
        btn_general->setText(QString());
        btn_date_time->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PreferencesDialog: public Ui_PreferencesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCESDIALOG_H
