TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += 9.3.cpp

QMAKE_CXXFLAGS += -std=c++11

include(deployment.pri)
qtcAddDeployment()

