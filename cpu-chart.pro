QT     += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/cpuchart.cpp \
    src/cpudataprovider.cpp \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS += \
    include/cpuchart.h \
    include/cpudataprovider.h \
    include/mainwindow.h \
    include/ui_mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    cpu-chart_en_US.ts

INCLUDEPATH += \
    $$PWD/include/ \
    $$PWD/3rdparty/

DEPENDPATH += $$PWD/3rdparty/*/include

LIBS += -L$$PWD/3rdparty/sys-monitor/build/ -lsys_monitor

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

