QT       += core
QT       -= gui
QT       += testlib

TARGET = 02
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    pointerStack.cpp \
    arrayStack.cpp \
    calculator.cpp \
    postfixConverter.cpp

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    stack.h \
    pointerStack.h \
    arrayStack.h \
    calculator.h \
    postfixConverter.h \
    calculatorTests.h
