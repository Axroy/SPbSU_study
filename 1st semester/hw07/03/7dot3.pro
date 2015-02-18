TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    list.cpp \
    hashTable.cpp \
    line.cpp

QMAKE_CXXFLAGS += -std=c++11

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    list.h \
    hashTable.h \
    line.h

