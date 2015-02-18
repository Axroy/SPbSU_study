TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    directory.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    directory.h

QMAKE_CXXFLAGS += -std=c++11
