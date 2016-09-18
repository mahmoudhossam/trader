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
    db.cpp \
    merchantslist.cpp \
    merchantdetaildialog.cpp \
    addtradedialog.cpp

HEADERS  += mainwindow.h \
    util.h \
    merchantsdialog.h \
    db.h \
    merchantslist.h \
    merchantdetaildialog.h \
    addtradedialog.h

FORMS    += mainwindow.ui \
    merchantsdialog.ui \
    merchantslist.ui \
    merchantdetaildialog.ui \
    addtradedialog.ui

PLUGINS += qsqlite

INCLUDEPATH += .

CONFIG+= static
