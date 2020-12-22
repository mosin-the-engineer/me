#-------------------------------------------------
#
# Project created by QtCreator 2020-12-18T18:09:22
#
#-------------------------------------------------

QT       -= gui

TARGET = me
TEMPLATE = lib

DEFINES += ME_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        src/me.cpp \
    src/idelessdebugger.cpp

HEADERS += \
        src/me.h \
        src/me_global.h \
    src/idelessdebugger.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

#TODO: добавить этап копирования в папку libs
#для файлов .lib и заголовочников!!
#не с релизом же связывать остальные проекты

#куда
#CONFIG(release, debug|release): DESTDIR = $$PWD/../../bin/release
#CONFIG(debug, debug|release): DESTDIR = $$PWD/../../bin/debug
#copy_to_build.path = $$DESTDIR
#откуда
#copy_to_build.files = $$PWD/copy_to_build_dir/*
#добавить параметр в команду
#http://blog.harrix.org/article/6339
#В пункте Make arguments пишем install.
#INSTALLS += \
#    copy_to_build
