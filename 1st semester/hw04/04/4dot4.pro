TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    calculator.cpp \
    stackChar.cpp \
    stackInt.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    calculator.h \
    stackChar.h \
    stackInt.h

QMAKE_CXXFLAGS += -std=c++11
