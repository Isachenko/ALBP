TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt

SOURCES += main.cpp \
    icountry.cpp \
    iempire.cpp \
    iicalgorithm.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    icountry.h \
    iempire.h \
    iicalgorithm.h


CONFIG += c++11

