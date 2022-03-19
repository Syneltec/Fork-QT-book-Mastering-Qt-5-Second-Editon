
#include "AlbumDao.h"

 AlbumDao::AlbumDao(QSqlDatabase & pdb) {
}

void AlbumDao::init() const {
    if (!pDB->tables().contains("albums"))
    {
        QSqlQuery query(*pDB);
        query.exec("CREATE TABLE albums (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT)");
        DatabaseManager::debugQuery(query);
    }
}

void AlbumDao::addAlbum(Album & palbum) const {
    QSqlQuery query(*pDB);
    query.prepare("INSERT INTO albums (name) VALUES (:name)");
    query.bindValue(":name", palbum->getName());
    query.exec();
    palbum->setId(query.lastInsertId().toInt());
    DatabaseManager::debugQuery(query);
}

void AlbumDao::updateAlbum(const Album & palbum) const {
    QSqlQuery query(*pDB);
    query.prepare("UPDATE albums SET name = (:name) WHERE id = (:id)");
    query.bindValue(":name", palbum->getName());
    query.bindValue(":id"  , palbum->getId());
    query.exec();
    DatabaseManager::debugQuery(query);
}

void AlbumDao::removeAlbum(int id) const {
    QSqlQuery query(*pDB);
    query.prepare("DELETE FROM albums WHERE id = (:id)");
    query.bindValue(":id", id);
    query.exec();
    DatabaseManager::debugQuery(query);
}

QList<Album*> AlbumDao::getAlbums() const {
    QSqlQuery query("SELECT * FROM albums", *pDB);
    query.exec();
    QList<Album*> * palbums = new QList<Album*>();
    while(query.next())
    {
        Album * palbum = new Album(query.value("name").toString(), query.value("id").toInt());
        palbums->append(palbum);
    }
    return palbums;
}

