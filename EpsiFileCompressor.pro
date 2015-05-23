#-------------------------------------------------
#
# Project created by QtCreator 2015-05-23T07:59:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EpsiFileCompressor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    epsifilecompressor.cpp \
    filepool.cpp \
    writer.cpp \
    zippedbuffer.cpp \
    zippedbufferpool.cpp \
    zipper.cpp

HEADERS  += mainwindow.h \
    epsifilecompressor.h \
    filepool.h \
    writer.h \
    zippedbuffer.h \
    zippedbufferpool.h \
    zipper.h

FORMS    += mainwindow.ui
