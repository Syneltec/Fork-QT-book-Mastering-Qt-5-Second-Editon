#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <memory>

#include <QString>

#include "AlbumDao.h"
#include "PictureDao.h"

class QSqlQuery;
class QSqlDatabase;

const QString DATABASE_FILENAME = "/home/charly/Documents/DataBase-LinuxIcons/MySQLiteDB.db";

class DatabaseManager
{
public:
    static DatabaseManager& instance();
    ~DatabaseManager();

    static void debugQuery(const QSqlQuery& query);


protected:
    DatabaseManager           (const QString& path = DATABASE_FILENAME);
    DatabaseManager& operator=(const DatabaseManager& rhs);

private:
    QSqlDatabase * pDataBase;

public:
    const AlbumDao   albumDao;
    const PictureDao pictureDao;
};

#endif // DATABASEMANAGER_H
