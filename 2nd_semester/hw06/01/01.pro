#-------------------------------------------------
#
# Project created by QtCreator 2015-05-04T12:02:38
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = 01
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    parseTree.cpp \
    counter.cpp

HEADERS += \
    parseTree.h \
    counter.h

QMAKE_CXXFLAGS += -std=c++11
