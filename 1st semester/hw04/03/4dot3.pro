TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    stackInt.cpp \
    calculator.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    stackInt.h \
    calculator.h

QMAKE_CXXFLAGS += -std=c++11
