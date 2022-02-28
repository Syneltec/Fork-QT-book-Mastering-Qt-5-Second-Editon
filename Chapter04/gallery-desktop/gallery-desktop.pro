#-------------------------------------------------
#
# Project created by QtCreator 2016-04-16T15:09:10
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = gallery-desktop
TEMPLATE = app
CONFIG  += c++11
DEFINES -= GALLERYCORE_LIBRARY

OBJECTS_DIR=../gallery/desktop #Intermediate object files directory
MOC_DIR    =../gallery/desktop #Intermediate moc files directory
RCC_DIR    =../gallery/desktop #Intermediate moc files directory
UI_DIR     =../gallery/desktop #Intermediate moc files directory
DESTDIR    =../gallery

SOURCES += main.cpp\
    MainWindow.cpp \
    AlbumListWidget.cpp \
    AlbumWidget.cpp \
    PictureDelegate.cpp \
    PictureWidget.cpp \
    GalleryWidget.cpp \
    ThumbnailProxyModel.cpp

HEADERS  += \
    MainWindow.h \
    AlbumListWidget.h \
    AlbumWidget.h \
    PictureDelegate.h \
    PictureWidget.h \
    GalleryWidget.h \
    ThumbnailProxyModel.h

FORMS += \
    MainWindow.ui \
    AlbumListWidget.ui \
    AlbumWidget.ui \
    PictureWidget.ui \
    GalleryWidget.ui

LIBS += -L../gallery
LIBS += -L../gallery-core/
LIBS += -L../../../gallery-core/build/gallery
LIBS += -lgallery-core

INCLUDEPATH += ../gallery-core
DEPENDPATH  += ../gallery-core

RESOURCES += \
    res/resource.qrc
