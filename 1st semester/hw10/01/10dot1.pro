TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    10.1v3.cpp
HEADERS += line.h
SOURCES +=

QMAKE_CXXFLAGS += -std=c++11

include(deployment.pri)
qtcAddDeployment()

