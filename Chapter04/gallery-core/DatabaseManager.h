#ifndef _DATABASEMANAGER_H
#define _DATABASEMANAGER_H


#include "AlbumDao.h"
#include "PictureDao.h"

class DatabaseManager {
  public:
    static DatabaseManager instance();

     ~DatabaseManager();

    static void debugQuery(const QSqlQuery & query);


  protected:
     DatabaseManager(const QString & path = DATABASE_FILENAME);

    DatabaseManager operator =(const DatabaseManager & rhs);


  private:
    QSqlDatabase pDataBase;


  public:
    const AlbumDao albumDao;

    const PictureDao pictureDao;

};
#endif
