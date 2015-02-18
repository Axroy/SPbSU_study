TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    8.2.cpp

QMAKE_CXXFLAGS += -std=c++11

include(deployment.pri)
qtcAddDeployment()

