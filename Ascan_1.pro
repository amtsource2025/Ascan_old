QT += core gui widgets sql printsupport charts serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TARGET = Ascan.V1

SOURCES += \
    AppManager.cpp \
    adddoctordialog.cpp \
    addlensdialog.cpp \
    addpatientdialog.cpp \
    calculatordialog.cpp \
    calibrationdialog.cpp \
    doctordetaildialog.cpp \
    editdoctordialog.cpp \
    editlensdialog.cpp \
    editpatientdialog.cpp \
    homescreendialog.cpp \
    keypad.cpp \
    main.cpp \
    measuredialog.cpp \
    numericpad.cpp \
    patientdetaildialog.cpp \
    preferencesdialog.cpp \
    printdialog.cpp \
    promptdialog.cpp \
    viewdoctordialog.cpp \
    viewlensdialog.cpp \
    viewpatientdialog.cpp \
    # waveformdialog.cpp \
    welcomedialog.cpp

HEADERS += \
    AppManager.h \
    adddoctordialog.h \
    addlensdialog.h \
    addpatientdialog.h \
    calculatordialog.h \
    calibrationdialog.h \
    doctordetaildialog.h \
    editdoctordialog.h \
    editlensdialog.h \
    editpatientdialog.h \
    fixedcombobox.h \
    homescreendialog.h \
    keypad.h \
    measuredialog.h \
    numericpad.h \
    patientdetaildialog.h \
    preferencesdialog.h \
    printdialog.h \
    promptdialog.h \
    viewdoctordialog.h \
    viewlensdialog.h \
    viewpatientdialog.h \
    # waveformdialog.h \
    welcomedialog.h

FORMS += \
    adddoctordialog.ui \
    addlensdialog.ui \
    addpatientdialog.ui \
    calculatordialog.ui \
    calibrationdialog.ui \
    clock.ui \
    dialog.ui \
    doctordetaildialog.ui \
    editdoctordialog.ui \
    editlensdialog.ui \
    editpatientdialog.ui \
    homescreendialog.ui \
    keypad.ui \
    measuredialog.ui \
    numericpad.ui \
    patientdetaildialog.ui \
    preferencesdialog.ui \
    printdialog.ui \
    promptdialog.ui \
    viewdoctordialog.ui \
    viewlensdialog.ui \
    viewpatientdialog.ui \
    welcomedialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc


INCLUDEPATH += $$PWD/Services

SOURCES += Services/qcustomplot.cpp

HEADERS += Services/qcustomplot.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./release/ -liolcalc
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./debug/ -liolcalc
else:unix: LIBS += -L$$PWD/./ -liolcalc

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
