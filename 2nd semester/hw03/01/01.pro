TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    quickSorter.cpp \
    heapSorter.cpp \
    insertionSorter.cpp \
    bubbleSorter.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    sorter.h \
    quickSorter.h \
    heapSorter.h \
    insertionSorter.h \
    bubbleSorter.h

