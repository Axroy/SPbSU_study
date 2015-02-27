TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    quickSorter.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    sorter.h \
    quickSorter.h

