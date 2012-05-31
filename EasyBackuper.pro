#-------------------------------------------------
#
# Project created by QtCreator 2012-05-28T14:30:00
#
#-------------------------------------------------

QT       += core gui

TARGET = EasyBackuper
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    profilewidget.cpp \
    ebprofile.cpp \
    ebdialogprofile.cpp \
    ebdialogsettings.cpp

HEADERS  += mainwindow.h \
    profilewidget.h \
    ebprofile.h \
    ebdialogprofile.h \
    ebdialogsettings.h

FORMS    += mainwindow.ui \
    profilewidget.ui \
    ebdialogprofile.ui \
    ebdialogsettings.ui

RESOURCES += \
    Icons.qrc
