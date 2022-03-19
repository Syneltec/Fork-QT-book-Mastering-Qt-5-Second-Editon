#ifndef _ALBUMWIDGET_H
#define _ALBUMWIDGET_H


#include "AlbumListWidget.h"

class ThumbnailProxyModel;
namespace Ui { class AlbumWidget; } 

class AlbumWidget : public typedef1 {
  Q_OBJECT
  public:
    explicit AlbumWidget(QWidget * parent = 0);

    ~AlbumWidget();

    void setAlbumModel(AlbumModel * albumModel);

    void setAlbumSelectionModel(QItemSelectionModel * albumSelectionModel);

    void setPictureModel(ThumbnailProxyModel * pictureModel);

    void setPictureSelectionModel(QItemSelectionModel * selectionModel);

  signals:    void pictureActivated(const QModelIndex & _t1);

  private slots:
  private:
    void deleteAlbum();

    void editAlbum();

    void addPictures();

    void clearUi();

    void loadAlbum(const QModelIndex & albumIndex);

    Ui::AlbumWidget * ui;

    AlbumModel * mAlbumModel;

    QItemSelectionModel * mAlbumSelectionModel;

    ThumbnailProxyModel * mPictureModel;

    QItemSelectionModel * mPictureSelectionModel;

};
#endif
