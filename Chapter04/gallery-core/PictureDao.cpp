
#include "PictureDao.h"

 PictureDao::PictureDao(QSqlDatabase & pdb) {
}

void PictureDao::init() const {
    if (!pDB->tables().contains("pictures"))
    {
        QSqlQuery query(*pDB);
        query.exec(QString("CREATE TABLE pictures")
        + " (id INTEGER PRIMARY KEY AUTOINCREMENT, "
        + "album_id INTEGER, "
        + "url TEXT)");
        DatabaseManager::debugQuery(query);
    }
}

void PictureDao::addPictureInAlbum(int albumId, Picture & ppict) const {
    QSqlQuery query(*pDB);
    query.prepare(QString("INSERT INTO pictures")
        + " (album_id, url)"
        + " VALUES ("
        + ":album_id, "
        + ":url"
        + ")");
    query.bindValue(":album_id", albumId);
    query.bindValue(":url", ppict->getFileUrl());
    query.exec();
    DatabaseManager::debugQuery(query);
    ppict->setId(query.lastInsertId().toInt());
    ppict->setAlbumId(albumId);
}

void PictureDao::removePicture(int id) const {
    QSqlQuery query(*pDB);
    query.prepare("DELETE FROM pictures WHERE id = (:id)");
    query.bindValue(":id", id);
    query.exec();
    DatabaseManager::debugQuery(query);
}

void PictureDao::removePicturesForAlbum(int albumId) const {
    QSqlQuery query(*pDB);
    query.prepare("DELETE FROM pictures WHERE album_id = (:album_id)");
    query.bindValue(":album_id", albumId);
    query.exec();
    DatabaseManager::debugQuery(query);
}

QList<Picture*> PictureDao::getPicturesForAlbum(int albumId) const {
    QSqlQuery query(*pDB);
    query.prepare("SELECT * FROM pictures WHERE album_id = (:album_id)");
    query.bindValue(":album_id", albumId);
    query.exec();
    DatabaseManager::debugQuery(query);

    QList<Picture*> * ppicts = new QList<Picture*>();
    while(query.next())
    {
        Picture *ppict = new Picture();
        ppict->setId(query.value("id").toInt());
        ppict->setAlbumId(query.value("album_id").toInt());
        ppict->setFileUrl(query.value("url").toString());
        ppicts->append(ppict);
    }
    return ppicts;
}

