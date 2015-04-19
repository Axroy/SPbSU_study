#-------------------------------------------------
#
# Project created by QtCreator 2015-04-15T20:43:58
#
#-------------------------------------------------

QT       += core
QT       -= gui

TARGET = 01
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    hashTable.cpp \
    list.cpp \
    hashFunctions.cpp

HEADERS += \
    hashTable.h \
    list.h \
    hashFunctions.h

QMAKE_CXXFLAGS += -std=c++11
