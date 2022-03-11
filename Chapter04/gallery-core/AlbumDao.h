#ifndef ALBUMDAO_H
#define ALBUMDAO_H

#include <QList>

class QSqlDatabase;
class Album;

class AlbumDao
{
public:
    AlbumDao (QSqlDatabase * pdb);

    void           init       ()                     const;
    void           addAlbum   (      Album * palbum) const;
    void           updateAlbum(const Album * palbum) const;
    void           removeAlbum(int id)               const;
    QList<Album*> *getAlbums  ()                     const;

private:
    QSqlDatabase *pDB;
};

#endif // ALBUMDAO_H
