#ifndef PICTUREDAO_H
#define PICTUREDAO_H

#include <QList>

class QSqlDatabase;
class Picture;

class PictureDao
{
public:
    explicit PictureDao(QSqlDatabase * pdb);

    void              init()                                                  const;
    void              addPictureInAlbum       (int albumId, Picture *picture) const;
    void              removePicture           (int id)                        const;
    void              removePicturesForAlbum  (int albumId)                   const;
    QList<Picture*> * getPicturesForAlbum     (int albumId)                   const;

private:
    QSqlDatabase * pDB;
};

#endif // PICTUREDAO_H
