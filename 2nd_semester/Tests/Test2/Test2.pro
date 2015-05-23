#-------------------------------------------------
#
# Project created by QtCreator 2015-05-22T13:54:43
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

TARGET = Test2
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    iterator.cpp \
    binaryTree.cpp

HEADERS += \
    iterator.h \
    binaryTree.h \
    iteratorTests.h

QMAKE_CXXFLAGS += -std=c++11
