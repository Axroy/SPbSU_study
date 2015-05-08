#-------------------------------------------------
#
# Project created by QtCreator 2015-05-08T13:32:31
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

TARGET = 02
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    uniqueList.cpp

HEADERS += \
    uniqueList.h \
    uniqueListTests.h

QMAKE_CXXFLAGS += -std=c++11
