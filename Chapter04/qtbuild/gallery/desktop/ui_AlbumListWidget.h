/********************************************************************************
** Form generated from reading UI file 'AlbumListWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALBUMLISTWIDGET_H
#define UI_ALBUMLISTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlbumListWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *createAlbumButton;
    QListView *albumList;

    void setupUi(QWidget *AlbumListWidget)
    {
        if (AlbumListWidget->objectName().isEmpty())
            AlbumListWidget->setObjectName(QString::fromUtf8("AlbumListWidget"));
        AlbumListWidget->resize(209, 294);
        verticalLayout_2 = new QVBoxLayout(AlbumListWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame = new QFrame(AlbumListWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 40));
        frame->setMaximumSize(QSize(16777215, 40));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        createAlbumButton = new QPushButton(frame);
        createAlbumButton->setObjectName(QString::fromUtf8("createAlbumButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/album-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        createAlbumButton->setIcon(icon);

        horizontalLayout_2->addWidget(createAlbumButton);


        verticalLayout_2->addWidget(frame);

        albumList = new QListView(AlbumListWidget);
        albumList->setObjectName(QString::fromUtf8("albumList"));

        verticalLayout_2->addWidget(albumList);


        retranslateUi(AlbumListWidget);

        QMetaObject::connectSlotsByName(AlbumListWidget);
    } // setupUi

    void retranslateUi(QWidget *AlbumListWidget)
    {
        AlbumListWidget->setWindowTitle(QCoreApplication::translate("AlbumListWidget", "Form", nullptr));
        createAlbumButton->setText(QCoreApplication::translate("AlbumListWidget", " Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AlbumListWidget: public Ui_AlbumListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALBUMLISTWIDGET_H
