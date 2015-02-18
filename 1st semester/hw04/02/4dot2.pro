TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    stackChar.cpp \
    calculator.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    stackChar.h \
    calculator.h

QMAKE_CXXFLAGS += -std=c++11
