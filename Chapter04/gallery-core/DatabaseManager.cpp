
#include "DatabaseManager.h"

DatabaseManager DatabaseManager::instance()
{
    static DatabaseManager singleton;
    return singleton;
}

 DatabaseManager::~DatabaseManager() {
    pDataBase->close();
}

void DatabaseManager::debugQuery(const QSqlQuery & query)
{
    if (query.lastError().type() == QSqlError::ErrorType::NoError)
    {
        qDebug() << "Query OK:"  << query.lastQuery();
    }
    else
    {
       qWarning() << "Query KO:"   << query.lastError().text();
       qWarning() << "Query text:" << query.lastQuery();
    }
}

 DatabaseManager::DatabaseManager(const QString & path) :
    pDataBase (new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"))),
    albumDao  (pDataBase),
    pictureDao(pDataBase)
 {
    pDataBase->setDatabaseName(path);

    bool openStatus = pDataBase->open();
    qDebug() << "Database connection: " << (openStatus ? "OK" : "Error");

    albumDao  .init();
    pictureDao.init();
}

DatabaseManager DatabaseManager::operator =(const DatabaseManager & rhs) {
}

