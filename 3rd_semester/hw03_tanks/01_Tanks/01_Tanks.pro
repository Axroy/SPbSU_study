#-------------------------------------------------
#
# Project created by QtCreator 2015-10-23T19:16:49
#
#-------------------------------------------------

QT       += core gui
QT       += network
QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 01_Tanks
TEMPLATE = app


SOURCES += main.cpp\
        tanksWindow.cpp \
    tank.cpp \
    gun.cpp \
    missile.cpp \
    landscape.cpp \
    explosion.cpp \
    lightMissile.cpp \
    heavyMissile.cpp \
    network.cpp \
    networkClient.cpp \
    networkServer.cpp

HEADERS  += tanksWindow.h \
    tank.h \
    gun.h \
    missile.h \
    landscape.h \
    explosion.h \
    lightMissile.h \
    heavyMissile.h \
    constants.h \
    network.h \
    networkEnums.h \
    networkClient.h \
    networkServer.h

FORMS    += tanksWindow.ui
