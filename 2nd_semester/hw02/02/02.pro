TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    pointerStack.cpp \
    arrayStack.cpp \
    calculator.cpp \
    postfixConverter.cpp

include(deployment.pri)
qtcAddDeployment()

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    stack.h \
    pointerStack.h \
    arrayStack.h \
    calculator.h \
    postfixConverter.h
