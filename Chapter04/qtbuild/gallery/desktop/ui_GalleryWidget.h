/********************************************************************************
** Form generated from reading UI file 'GalleryWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GALLERYWIDGET_H
#define UI_GALLERYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>
#include "AlbumListWidget.h"
#include "AlbumWidget.h"

QT_BEGIN_NAMESPACE

class Ui_GalleryWidget
{
public:
    QHBoxLayout *horizontalLayout;
    AlbumListWidget *albumListWidget;
    AlbumWidget *albumWidget;

    void setupUi(QWidget *GalleryWidget)
    {
        if (GalleryWidget->objectName().isEmpty())
            GalleryWidget->setObjectName(QString::fromUtf8("GalleryWidget"));
        GalleryWidget->resize(1057, 676);
        horizontalLayout = new QHBoxLayout(GalleryWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        albumListWidget = new AlbumListWidget(GalleryWidget);
        albumListWidget->setObjectName(QString::fromUtf8("albumListWidget"));

        horizontalLayout->addWidget(albumListWidget);

        albumWidget = new AlbumWidget(GalleryWidget);
        albumWidget->setObjectName(QString::fromUtf8("albumWidget"));

        horizontalLayout->addWidget(albumWidget);


        retranslateUi(GalleryWidget);

        QMetaObject::connectSlotsByName(GalleryWidget);
    } // setupUi

    void retranslateUi(QWidget *GalleryWidget)
    {
        GalleryWidget->setWindowTitle(QCoreApplication::translate("GalleryWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GalleryWidget: public Ui_GalleryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GALLERYWIDGET_H
