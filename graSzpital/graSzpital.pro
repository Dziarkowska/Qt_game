#-------------------------------------------------
#
# Project created by QtCreator 2018-01-04T17:54:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = graSzpital
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    game.cpp \
    person.cpp \
    patient.cpp \
    guard.cpp \
    doctor.cpp \
    readfile.cpp \
    dispstatistics.cpp \
    position.cpp \
    room.cpp \
    kitchen.cpp \
    message.cpp \
    animal.cpp \
    dog.cpp \
    cat.cpp \
    food.cpp \
    pineapple.cpp \
    peach.cpp \
    grapes.cpp \
    greenmessage.cpp \
    wall.cpp

HEADERS += \
        mainwindow.h \
    game.h \
    person.h \
    patient.h \
    guard.h \
    doctor.h \
    readfile.h \
    dispstatistics.h \
    position.h \
    room.h \
    kitchen.h \
    message.h \
    animal.h \
    dog.h \
    cat.h \
    food.h \
    pineapple.h \
    peach.h \
    grapes.h \
    greenmessage.h \
    wall.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    res.qrc
