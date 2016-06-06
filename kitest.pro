#-------------------------------------------------
#
# Project created by QtCreator 2016-06-06T01:51:18
#
#-------------------------------------------------

QT       -= core gui

TARGET = kitest
TEMPLATE = lib

DEFINES += KITEST_LIBRARY

SOURCES += kitest.cpp

HEADERS += kitest.h\
        kitest_global.h \
    ../xchat-plugin.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
