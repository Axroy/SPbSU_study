TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    squareArray.cpp \
    consolePrinter.cpp \
    filePrinter.cpp \
    printer.cpp

HEADERS += \
    squareArray.h \
    printer.h \
    consolePrinter.h \
    filePrinter.h \
    filePrinterTests.h

QT += testlib
QT += core
