#-------------------------------------------------
#
# Project created by QtCreator 2015-05-17T18:53:40
#
#-------------------------------------------------

QT       += core gui
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 03
TEMPLATE = app


SOURCES += main.cpp\
        ticTacToeUI.cpp \
    ticTacToe.cpp

HEADERS  += ticTacToeUI.h \
    ticTacToe.h \
    ticTacToeTests.h

FORMS    += ticTacToeUI.ui
