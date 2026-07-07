cmake_minimum_required(VERSION 3.16)
project(Ascan LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
# Find Qt5
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Sql PrintSupport Charts)
#find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Sql PrintSupport Charts)
# Find OpenSSL
find_package(OpenSSL REQUIRED)
# Source files
set(SOURCES
    adddoctordialog.cpp
    addlensdialog.cpp
    addpatientdialog.cpp
    calculatordialog.cpp
    calibrationdialog.cpp
    doctordetaildialog.cpp
    editdoctordialog.cpp
    editlensdialog.cpp
    editpatientdialog.cpp
    homescreendialog.cpp
    keypad.cpp
    main.cpp
    measuredialog.cpp
    numericpad.cpp
    patientdetaildialog.cpp
    preferencesdialog.cpp
    printdialog.cpp
    promptdialog.cpp
    viewdoctordialog.cpp
    viewlensdialog.cpp
    viewpatientdialog.cpp
    waveformdialog.cpp
    welcomedialog.cpp
    Services/qcustomplot.cpp
)

set(HEADERS
    adddoctordialog.h
    addlensdialog.h
    addpatientdialog.h
    calculatordialog.h
    calibrationdialog.h
    doctordetaildialog.h
    editdoctordialog.h
    editlensdialog.h
    editpatientdialog.h
    fixedcombobox.h
    homescreendialog.h
    keypad.h
    measuredialog.h
    numericpad.h
    patientdetaildialog.h
    preferencesdialog.h
    printdialog.h
    promptdialog.h
    viewdoctordialog.h
    viewlensdialog.h
    viewpatientdialog.h
    waveformdialog.h
    welcomedialog.h
    Services/qcustomplot.h
)

set(UI_FILES
    adddoctordialog.ui
    addlensdialog.ui
    addpatientdialog.ui
    calculatordialog.ui
    calibrationdialog.ui
    clock.ui
    dialog.ui
    doctordetaildialog.ui
    editdoctordialog.ui
    editlensdialog.ui
    editpatientdialog.ui
    homescreendialog.ui
    keypad.ui
    measuredialog.ui
    numericpad.ui
    patientdetaildialog.ui
    preferencesdialog.ui
    printdialog.ui
    promptdialog.ui
    viewdoctordialog.ui
    viewlensdialog.ui
    viewpatientdialog.ui
    welcomedialog.ui
)

set(RESOURCE_FILES
    resource.qrc
)

# Create executable
add_executable(Ascan_v2
    ${SOURCES}
    ${HEADERS}
    ${UI_FILES}
    ${RESOURCE_FILES}
    IOLCalculator.h
)

# Include directories
target_include_directories(Ascan_v2 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Services
    ${OPENSSL_INCLUDE_DIR}
    /usr/include
)

# Link Qt5
target_link_libraries(Ascan_v2 PRIVATE
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::Sql
    Qt5::PrintSupport
    Qt5::Charts

    # Qt6::Core
    # Qt6::Gui
    # Qt6::Widgets
    # Qt6::Sql
    # Qt6::PrintSupport
    # Qt6::Charts
)

# Link OpenSSL
target_link_libraries(Ascan_v2 PRIVATE
    OpenSSL::SSL
    OpenSSL::Crypto
)


install(TARGETS Ascan_v2 DESTINATION /opt/Ascan/bin)
target_link_libraries(Ascan_v2 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/libiolcalc.so
)
