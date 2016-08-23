#-------------------------------------------------
#
# Project created by QtCreator 2016-06-22T20:35:17
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Trader
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    util.cpp \
    merchantsdialog.cpp \
    db.cpp

HEADERS  += mainwindow.h \
    util.h \
    merchantsdialog.h \
    db.h

FORMS    += mainwindow.ui \
    merchantsdialog.ui

PLUGINS += qsqlite

INCLUDEPATH += .

CONFIG+= static
