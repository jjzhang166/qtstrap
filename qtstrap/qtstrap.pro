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
    widget_style.cpp \
    style_property.cpp \
    styled_button.cpp \
    test/styled_button_test.cpp

HEADERS  += main_window.h \
    widget_style.h \
    style_property.h \
    styled_button.h \
    test/styled_button_test.h
