#-------------------------------------------------
#
# Project created by QtCreator 2023-07-11T17:19:39
#
#-------------------------------------------------

QT       += core gui
QT+=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = logindialog
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        dialog.cpp \
    titlewidget.cpp \
    common.cpp \
    des.c \
    mainwindow.cpp \
    buttongroup.cpp \
    myfile.cpp \
    mymenu.cpp \
    analyjsondata.cpp

HEADERS += \
        dialog.h \
    titlewidget.h \
    common.h \
    C:/Users/A/Desktop/des.h \
    des.h \
    mainwindow.h \
    buttongroup.h \
    myfile.h \
    mymenu.h \
    analyjsondata.h

FORMS += \
        dialog.ui \
    titlewidget.ui \
    mainwindow.ui \
    buttongroup.ui \
    myfile.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
