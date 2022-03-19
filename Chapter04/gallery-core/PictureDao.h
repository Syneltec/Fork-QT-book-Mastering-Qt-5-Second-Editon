#ifndef _PICTUREDAO_H
#define _PICTUREDAO_H


class PictureDao {
  public:
     PictureDao(QSqlDatabase & pdb);

    void init() const;

    void addPictureInAlbum(int albumId, Picture & ppict) const;

    void removePicture(int id) const;

    void removePicturesForAlbum(int albumId) const;

    QList<Picture*> getPicturesForAlbum(int albumId) const;


  private:
    QSqlDatabase pDB;

};
#endif
