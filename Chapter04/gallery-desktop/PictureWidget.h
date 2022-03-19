#ifndef _PICTUREWIDGET_H
#define _PICTUREWIDGET_H


#include "AlbumListWidget.h"

class ThumbnailProxyModel;
namespace Ui { class PictureWidget; } 

class PictureWidget : public typedef1 {
  Q_OBJECT
  public:
    explicit PictureWidget(QWidget * parent = 0);

    ~PictureWidget();

    void setModel(ThumbnailProxyModel * model);

    void setSelectionModel(QItemSelectionModel * selectionModel);

  signals:    void backToGallery();


  protected:
    void resizeEvent(QResizeEvent * event) override;

  private slots:
  private:
    void deletePicture();

    void loadPicture(const QItemSelection & selected);

    void updatePicturePixmap();

    Ui::PictureWidget * ui;

    ThumbnailProxyModel * mModel;

    QItemSelectionModel * mSelectionModel;

    QPixmap mPixmap;

};
#endif
