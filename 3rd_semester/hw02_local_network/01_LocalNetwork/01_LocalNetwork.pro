#-------------------------------------------------
#
# Project created by QtCreator 2015-09-17T15:57:34
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

TARGET = 01_LocalNetwork
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    localNetworkModel.cpp \
    computer.cpp \
	network.cpp \
	windowsComputer.cpp \
	linuxComputer.cpp \
	macComputer.cpp

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    localNetworkModel.h \
    computer.h \
    network.h \
	networkTests.h \
	windowsComputer.h \
	linuxComputer.h \
	macComputer.h
