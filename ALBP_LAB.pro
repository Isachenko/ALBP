TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt

SOURCES += main.cpp \
    icountry.cpp \
    iempire.cpp \
    iicalgorithm.cpp \
    albpcountry.cpp \
    albpempire.cpp \
    albpicalgorithm.cpp \
    albptask.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    icountry.h \
    iempire.h \
    iicalgorithm.h \
    albpcountry.h \
    albpempire.h \
    albpicalgorithm.h \
    albptask.h


CONFIG += c++11

