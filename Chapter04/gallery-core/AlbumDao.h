#ifndef _ALBUMDAO_H
#define _ALBUMDAO_H


class AlbumDao {
  public:
     AlbumDao(QSqlDatabase & pdb);

    void init() const;

    void addAlbum(Album & palbum) const;

    void updateAlbum(const Album & palbum) const;

    void removeAlbum(int id) const;

    QList<Album*> getAlbums() const;


  private:
    QSqlDatabase pDB;

};
#endif
