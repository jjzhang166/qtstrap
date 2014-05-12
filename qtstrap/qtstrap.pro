#-------------------------------------------------
#
# Project created by QtCreator 2014-05-12T01:20:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtstrap
TEMPLATE = app


SOURCES += main.cpp\
        main_window.cpp \
    style_property.cpp \
    styled_button.cpp \
    base/style_components.cpp \
    base/widget_style.cpp \
    test/widget_style_tester.cpp \
    test/styled_button_tester.cpp \
    utility.cpp

HEADERS  += main_window.h \
    style_property.h \
    styled_button.h \
    base/style_components.h \
    base/widget_style.h \
    test/widget_style_tester.h \
    test/styled_button_tester.h \
    utility.h
