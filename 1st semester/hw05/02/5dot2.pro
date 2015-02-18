TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    5.2.cpp

include(deployment.pri)
qtcAddDeployment()

