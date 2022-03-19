/********************************************************************************
** Form generated from reading UI file 'AlbumWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALBUMWIDGET_H
#define UI_ALBUMWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlbumWidget
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *albumInfoFrame;
    QHBoxLayout *horizontalLayout;
    QLabel *albumName;
    QPushButton *addPicturesButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QListView *thumbnailListView;

    void setupUi(QWidget *AlbumWidget)
    {
        if (AlbumWidget->objectName().isEmpty())
            AlbumWidget->setObjectName(QString::fromUtf8("AlbumWidget"));
        AlbumWidget->resize(673, 269);
        verticalLayout = new QVBoxLayout(AlbumWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        albumInfoFrame = new QFrame(AlbumWidget);
        albumInfoFrame->setObjectName(QString::fromUtf8("albumInfoFrame"));
        albumInfoFrame->setMinimumSize(QSize(0, 40));
        albumInfoFrame->setMaximumSize(QSize(16777215, 40));
        albumInfoFrame->setFrameShape(QFrame::StyledPanel);
        albumInfoFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(albumInfoFrame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 4, -1, 4);
        albumName = new QLabel(albumInfoFrame);
        albumName->setObjectName(QString::fromUtf8("albumName"));
        albumName->setMinimumSize(QSize(0, 0));
        albumName->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        albumName->setFont(font);
        albumName->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(albumName);

        addPicturesButton = new QPushButton(albumInfoFrame);
        addPicturesButton->setObjectName(QString::fromUtf8("addPicturesButton"));
        addPicturesButton->setMaximumSize(QSize(130, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/photo-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addPicturesButton->setIcon(icon);

        horizontalLayout->addWidget(addPicturesButton);

        editButton = new QPushButton(albumInfoFrame);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        editButton->setMaximumSize(QSize(130, 16777215));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/album-edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        editButton->setIcon(icon1);

        horizontalLayout->addWidget(editButton);

        deleteButton = new QPushButton(albumInfoFrame);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setMaximumSize(QSize(130, 16777215));
        deleteButton->setLayoutDirection(Qt::LeftToRight);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/album-delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon2);

        horizontalLayout->addWidget(deleteButton);


        verticalLayout->addWidget(albumInfoFrame);

        thumbnailListView = new QListView(AlbumWidget);
        thumbnailListView->setObjectName(QString::fromUtf8("thumbnailListView"));

        verticalLayout->addWidget(thumbnailListView);


        retranslateUi(AlbumWidget);

        QMetaObject::connectSlotsByName(AlbumWidget);
    } // setupUi

    void retranslateUi(QWidget *AlbumWidget)
    {
        AlbumWidget->setWindowTitle(QCoreApplication::translate("AlbumWidget", "Form", nullptr));
        albumName->setText(QCoreApplication::translate("AlbumWidget", "Lorem ipsum", nullptr));
        addPicturesButton->setText(QCoreApplication::translate("AlbumWidget", " Add pictures", nullptr));
        editButton->setText(QCoreApplication::translate("AlbumWidget", " Edit", nullptr));
        deleteButton->setText(QCoreApplication::translate("AlbumWidget", " Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AlbumWidget: public Ui_AlbumWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALBUMWIDGET_H
