#-------------------------------------------------
#
# Project created by QtCreator 2015-05-09T11:59:31
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

TARGET = 03
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

HEADERS += \
    sharedPointer.h \
    sharedPointerTests.h

QMAKE_CXXFLAGS += -std=c++11
