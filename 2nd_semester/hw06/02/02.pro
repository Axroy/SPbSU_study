#-------------------------------------------------
#
# Project created by QtCreator 2015-04-28T21:54:57
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

TARGET = 02
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

HEADERS += \
    set.h \
    setTests.h

QMAKE_CXXFLAGS += -std=c++11
