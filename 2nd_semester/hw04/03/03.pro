#-------------------------------------------------
#
# Project created by QtCreator 2015-04-10T14:28:40
#
#-------------------------------------------------

QT       += core gui
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 03
TEMPLATE = app


SOURCES += main.cpp\
        uberCalculatorUI.cpp \
    uberCalculator.cpp

HEADERS  += uberCalculatorUI.h \
    uberCalculator.h \
    uberCalculatorTests.h

FORMS    += uberCalculatorUI.ui
