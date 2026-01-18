TEMPLATE = app
TARGET = TacticalVehicleGateway

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    MainWindow.cpp \
    RangeSlider.cpp \
    TacticalVehicleData.cpp \
    main.cpp

HEADERS += \
    MainWindow.h \
    RangeSlider.h \
    TacticalVehicle.h \
    TacticalVehicleData.h

RESOURCES += \
    resources.qrc
