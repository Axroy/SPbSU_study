TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    7.1.cpp

include(deployment.pri)
qtcAddDeployment()

