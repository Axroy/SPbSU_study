QT       += core
QT       -= gui
QT       += testlib

TARGET = 01
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    list.cpp \
    singleLinkedList.cpp \
    doubleLinkedList.cpp

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    list.h \
    singleLinkedList.h \
    doubleLinkedList.h \
    singleLinkedListTests.h \
    doubleLinkedListTests.h
