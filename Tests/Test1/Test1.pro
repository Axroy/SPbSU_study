#-------------------------------------------------
#
# Project created by QtCreator 2015-04-03T09:39:20
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

TARGET = Test1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

HEADERS += \
    priorityQueue.h \
    priorityQueueTests.h

QMAKE_CXXFLAGS += -std=c++11
