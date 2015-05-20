#-------------------------------------------------
#
# Project created by QtCreator 2015-05-19T19:57:13
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

TARGET = 01
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    bag.cpp

HEADERS += \
    bag.h \
    bagTests.h

QMAKE_CXXFLAGS += -std=c++11
