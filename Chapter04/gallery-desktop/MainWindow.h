#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H


namespace Ui { class MainWindow; } 
class GalleryWidget;
class PictureWidget;

typedef QMainWindow typedef2;
class MainWindow : public typedef2 {
  Q_OBJECT
  public:
    explicit MainWindow(QWidget * parent = 0);

    ~MainWindow();

  public slots:    void displayGallery();

    void displayPicture(const QModelIndex & index);


  private:
    Ui::MainWindow * ui;

    GalleryWidget * mGalleryWidget;

    PictureWidget * mPictureWidget;

    QStackedWidget * mStackedWidget;

};
#endif
