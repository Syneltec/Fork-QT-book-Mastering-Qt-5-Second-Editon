/********************************************************************************
** Form generated from reading UI file 'PictureWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICTUREWIDGET_H
#define UI_PICTUREWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PictureWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *backButton;
    QLabel *nameLabel;
    QPushButton *previousButton;
    QPushButton *nextButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *deleteButton;
    QLabel *pictureLabel;

    void setupUi(QWidget *PictureWidget)
    {
        if (PictureWidget->objectName().isEmpty())
            PictureWidget->setObjectName(QString::fromUtf8("PictureWidget"));
        PictureWidget->resize(450, 165);
        verticalLayout_2 = new QVBoxLayout(PictureWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame = new QFrame(PictureWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 40));
        frame->setMaximumSize(QSize(16777215, 40));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 4, -1, 4);
        backButton = new QPushButton(frame);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setMaximumSize(QSize(130, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/back-to-gallery.png"), QSize(), QIcon::Normal, QIcon::Off);
        backButton->setIcon(icon);

        horizontalLayout_2->addWidget(backButton);

        nameLabel = new QLabel(frame);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        nameLabel->setFont(font);
        nameLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(nameLabel);

        previousButton = new QPushButton(frame);
        previousButton->setObjectName(QString::fromUtf8("previousButton"));
        previousButton->setMaximumSize(QSize(50, 16777215));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/photo-previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        previousButton->setIcon(icon1);

        horizontalLayout_2->addWidget(previousButton);

        nextButton = new QPushButton(frame);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setMaximumSize(QSize(50, 16777215));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/photo-next.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextButton->setIcon(icon2);

        horizontalLayout_2->addWidget(nextButton);

        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        deleteButton = new QPushButton(frame);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setMaximumSize(QSize(130, 16777215));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/photo-delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon3);

        horizontalLayout_2->addWidget(deleteButton);


        verticalLayout_2->addWidget(frame);

        pictureLabel = new QLabel(PictureWidget);
        pictureLabel->setObjectName(QString::fromUtf8("pictureLabel"));
        pictureLabel->setScaledContents(false);
        pictureLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(pictureLabel);


        retranslateUi(PictureWidget);

        QMetaObject::connectSlotsByName(PictureWidget);
    } // setupUi

    void retranslateUi(QWidget *PictureWidget)
    {
        PictureWidget->setWindowTitle(QCoreApplication::translate("PictureWidget", "Form", nullptr));
        backButton->setText(QCoreApplication::translate("PictureWidget", " Back", nullptr));
        nameLabel->setText(QCoreApplication::translate("PictureWidget", "lorem ipsum.jpg", nullptr));
        previousButton->setText(QString());
        nextButton->setText(QString());
        deleteButton->setText(QCoreApplication::translate("PictureWidget", " Delete", nullptr));
        pictureLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PictureWidget: public Ui_PictureWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICTUREWIDGET_H
