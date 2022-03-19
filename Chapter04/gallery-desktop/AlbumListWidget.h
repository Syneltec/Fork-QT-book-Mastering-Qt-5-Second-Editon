#ifndef _ALBUMLISTWIDGET_H
#define _ALBUMLISTWIDGET_H


namespace Ui { class AlbumListWidget; } 

typedef QWidget typedef1;
class AlbumListWidget : public typedef1 {
  Q_OBJECT
  public:
    explicit AlbumListWidget(QWidget * parent = 0);

    ~AlbumListWidget();

    void setModel(AlbumModel * model);

    void setSelectionModel(QItemSelectionModel * selectionModel);

  private slots:
  private:
    void createAlbum();

    Ui::AlbumListWidget * ui;

    AlbumModel * pAlbumModel;

};
#endif
