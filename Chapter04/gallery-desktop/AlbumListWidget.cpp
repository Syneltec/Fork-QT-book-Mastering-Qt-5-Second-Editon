
#include "AlbumListWidget.h"
#include "ui_AlbumListWidget.h"

AlbumListWidget::AlbumListWidget(QWidget * parent)
:
    QWidget(parent),
    ui(new Ui::AlbumListWidget),
    pAlbumModel(nullptr)
{
    ui->setupUi(this);
    connect(ui->createAlbumButton, &QPushButton::clicked, this, &AlbumListWidget::createAlbum);
}

AlbumListWidget::~AlbumListWidget() {
    delete ui;
}

void AlbumListWidget::setModel() {
    pAlbumModel = model;
    ui->albumList->setModel(pAlbumModel);
}

void AlbumListWidget::setSelectionModel() {
    ui->albumList->setSelectionModel(selectionModel);
}

void AlbumListWidget::createAlbum() {
    if(!pAlbumModel) return;

    bool ok;
    QString albumName = QInputDialog::getText(this,
                                              "Create a new Album",
                                              "Choose an name",
                                              QLineEdit::Normal,
                                              "New album",
                                              &ok);

    if (ok && !albumName.isEmpty())
    {
        Album * palbum = new Album(albumName);
        QModelIndex createdIndex = pAlbumModel->addAlbum(palbum);
        ui->albumList->setCurrentIndex(createdIndex);
    }
}

