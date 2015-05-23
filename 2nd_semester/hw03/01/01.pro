QT       += core
QT       -= gui
QT       += testlib

TARGET = 01
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    quickSorter.cpp \
    heapSorter.cpp \
    insertionSorter.cpp \
    bubbleSorter.cpp

HEADERS += \
    sorter.h \
    quickSorter.h \
    heapSorter.h \
    insertionSorter.h \
    bubbleSorter.h \
    sortersTests.h

