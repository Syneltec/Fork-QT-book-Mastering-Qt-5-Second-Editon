
#include "GalleryWidget.h"
#include "ThumbnailProxyModel.h"
#include "ui_GalleryWidget.h"

GalleryWidget::GalleryWidget(QWidget * parent) :
    QWidget(parent),
    ui(new Ui::GalleryWidget)
{
    ui->setupUi(this);
    ui->albumListWidget->setMaximumWidth(250);
    connect(ui->albumWidget, &AlbumWidget::pictureActivated, this, &GalleryWidget::pictureActivated);
}

GalleryWidget::~GalleryWidget() {
    delete ui;
}

void GalleryWidget::setAlbumModel() {
    ui->albumListWidget->setModel(albumModel);
    ui->albumWidget->setAlbumModel(albumModel);
}

void GalleryWidget::setAlbumSelectionModel() {
    ui->albumListWidget->setSelectionModel(albumSelectionModel);
    ui->albumWidget->setAlbumSelectionModel(albumSelectionModel);
}

void GalleryWidget::setPictureModel() {
    ui->albumWidget->setPictureModel(pictureModel);
}

void GalleryWidget::setPictureSelectionModel() {
    ui->albumWidget->setPictureSelectionModel(pictureSelectionModel);
}

// SIGNAL 0

void GalleryWidget::pictureActivated(const QModelIndex & _t1) {
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

