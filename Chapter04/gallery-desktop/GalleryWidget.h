#ifndef _GALLERYWIDGET_H
#define _GALLERYWIDGET_H


#include "AlbumListWidget.h"

class ThumbnailProxyModel;
namespace Ui { class GalleryWidget; } 

class GalleryWidget : public typedef1 {
  Q_OBJECT
  public:
    explicit GalleryWidget(QWidget * parent = 0);

    ~GalleryWidget();

    void setAlbumModel(AlbumModel * albumModel);

    void setAlbumSelectionModel(QItemSelectionModel * albumSelectionModel);

    void setPictureModel(ThumbnailProxyModel * pictureModel);

    void setPictureSelectionModel(QItemSelectionModel * pictureSelectionModel);

  signals:    void pictureActivated(const QModelIndex & _t1);


  private:
    Ui::GalleryWidget * ui;

};
#endif
