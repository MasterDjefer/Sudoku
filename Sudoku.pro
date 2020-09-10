#-------------------------------------------------
#
# Project created by QtCreator 2017-09-21T08:09:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sudoku
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    map.cpp \
    cell.cpp \
    file.cpp \
    possibility.cpp

HEADERS  += widget.h \
    map.h \
    cell.h \
    file.h \
    possibility.h
