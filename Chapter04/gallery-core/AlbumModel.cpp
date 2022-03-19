#include "AlbumModel.h"

using namespace std;

AlbumModel::AlbumModel(QObject* parent) : QAbstractListModel(parent),
                                          pDB(&DatabaseManager::instance()),
                                          pAlbums(pDB->albumDao.getAlbums())
{
}

QModelIndex AlbumModel::addAlbum(Album * palbum)
{
    int rowIndex = rowCount();
    beginInsertRows(QModelIndex(), rowIndex, rowIndex);
    pDB->albumDao.addAlbum(palbum);
    pAlbums->append(palbum);
    endInsertRows();
    return index(rowIndex, 0);
}

int AlbumModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return pAlbums->size();
}

QVariant AlbumModel::data(const QModelIndex& index, int role) const
{
    QVariant retVal = QVariant();

    if (!isIndexValid(index)) return retVal;

    const Album * palbum = pAlbums->at(index.row());
    switch (role)
    {
        case Roles::IdRole:     retVal = palbum->getId()  ;  break;
        case Roles::NameRole:   retVal = palbum->getName();  break;
        case Qt::DisplayRole:   retVal = palbum->getName();  break;
    }
    return retVal;
}

bool AlbumModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (!isIndexValid(index) || role != Roles::NameRole) return false;

    Album * palbum = pAlbums->at(index.row());
    palbum->setName(value.toString());
    pDB->albumDao.updateAlbum(palbum);
    emit dataChanged(index, index);
    return true;
}

bool AlbumModel::removeRows(int row, int count, const QModelIndex& parent)
{
    if (row < 0 || row >= rowCount() || count < 0 || (row + count) > rowCount()) return false;

    beginRemoveRows(parent, row, row + count - 1);
    int countLeft = count;
    while (countLeft--)
    {
        Album * palbum = pAlbums->at(row + countLeft);
        pDB->albumDao.removeAlbum(palbum->getId());
        delete palbum;
    }
    pAlbums->erase(pAlbums->begin() + row, pAlbums->begin() + row + count);
    endRemoveRows();
    return true;
}

QHash<int, QByteArray> AlbumModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Roles::IdRole] = "id";
    roles[Roles::NameRole] = "name";
    return roles;
}

bool AlbumModel::isIndexValid(const QModelIndex& index) const
{
    return index.isValid() && index.row() < rowCount();
}

