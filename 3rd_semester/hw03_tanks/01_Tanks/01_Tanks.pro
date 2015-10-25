#-------------------------------------------------
#
# Project created by QtCreator 2015-10-23T19:16:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 01_Tanks
TEMPLATE = app


SOURCES += main.cpp\
        tanksWindow.cpp \
    tank.cpp \
    gun.cpp

HEADERS  += tanksWindow.h \
    tank.h \
    gun.h

FORMS    += tanksWindow.ui
