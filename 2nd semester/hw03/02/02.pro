TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    squareArray.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    squareArray.h

