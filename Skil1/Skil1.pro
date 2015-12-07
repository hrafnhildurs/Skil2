QT += core
QT -= gui
QT += sql

TARGET = Skil1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    person.cpp \
    interface.cpp \
    manager.cpp \
    computer.cpp \
    database.cpp \
    relations.cpp

HEADERS += \
    person.h \
    interface.h \
    manager.h \
    computer.h \
    database.h \
    relations.h

