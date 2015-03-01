TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    squareArray.cpp \
    consolePrinter.cpp \
    filePrinter.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    squareArray.h \
    printer.h \
    consolePrinter.h \
    filePrinter.h