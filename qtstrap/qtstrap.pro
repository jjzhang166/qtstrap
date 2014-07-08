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
    styled_button.cpp \
    base/style_components.cpp \
    base/widget_style.cpp \
    test/widget_style_tester.cpp \
    test/styled_button_tester.cpp \
    base/styled_widget.cpp \
    utility/double_map.cpp

HEADERS  += main_window.h \
    styled_button.h \
    base/style_components.h \
    base/widget_style.h \
    test/widget_style_tester.h \
    test/styled_button_tester.h \
    base/property_types.h \
    base/properties.h \
    base/styled_widget.h \
    utility/utility.h \
    base/styled_color.h \
    utility/double_map.h \
    base/property_pseudo_states.h
