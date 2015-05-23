
QT       += core
QT       -= gui
QT       += testlib

TARGET = 03
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    listsComparator.cpp \
    linkedList.cpp \
    sortedSet.cpp

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    listsComparator.h \
    linkedList.h \
    sortedSet.h \
    sortedSetTests.h
