TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    listsComparator.cpp \
    linkedList.cpp \
    sortedSet.cpp

include(deployment.pri)
qtcAddDeployment()

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    listsComparator.h \
    linkedList.h \
    sortedSet.h
