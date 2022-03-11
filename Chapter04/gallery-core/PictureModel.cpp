#include "PictureModel.h"

#include "Album.h"
#include "DatabaseManager.h"
#include "AlbumModel.h"

using namespace std;

PictureModel::PictureModel(const AlbumModel& albumModel, QObject* parent) :
    QAbstractListModel(parent),
    pDB(&DatabaseManager::instance()),
    pPictures(new QList<Picture*>()),
    mAlbumId(-1),
    mPictsCount(0)
{
    connect(&albumModel, &AlbumModel::rowsRemoved, this, &PictureModel::deletePicturesForAlbum);
}

bool PictureModel::canFetchMore(const QModelIndex &parent) const
{
    if (parent.isValid()) return false;

    return (mPictsCount < pPictures->size());
}

void PictureModel::fetchMore(const QModelIndex &parent)
{
    if (parent.isValid()) return;

    int remainder = pPictures->size() - mPictsCount;
    int itemsToFetch = qMin(100, remainder);

    if (itemsToFetch <= 0)  return;

    beginInsertRows(QModelIndex(), mPictsCount, mPictsCount + itemsToFetch - 1);

    mPictsCount += itemsToFetch;

    endInsertRows();

    emit numberPopulated(itemsToFetch);
}

QModelIndex PictureModel::addPicture(Picture * ppict)
{
    int rows = rowCount();
    beginInsertRows(QModelIndex(), rows, rows);
    pDB->pictureDao.addPictureInAlbum(mAlbumId, ppict);
    pPictures->append(ppict);
    endInsertRows();
    return index(rows, 0);
}

int PictureModel::rowCount(const QModelIndex& /*parent*/) const
{
    return pPictures->size();
}

QVariant PictureModel::data(const QModelIndex& index, int role) const
{
    if (!isIndexValid(index)) return QVariant();

    Picture * ppict = pPictures->at(index.row());
    switch (role)
    {
        case Qt::DisplayRole:
            return ppict->getFileUrl().fileName();
            break;

        case Roles::UrlRole:
            return ppict->getFileUrl();
            break;

        case Roles::FilePathRole:
            return ppict->getFileUrl().toLocalFile();
            break;


        default:
            return QVariant();
    }
}

bool PictureModel::removeRows(int row, int count, const QModelIndex& parent)
{
    if (row < 0 || row >= rowCount() || count < 0 || (row + count) > rowCount()) return false;

    beginRemoveRows(parent, row, row + count - 1);
    int countLeft = count;
    while(countLeft--)
    {
        Picture * ppict = pPictures->at(row + countLeft);
        pDB->pictureDao.removePicture(ppict->getId());
        delete ppict;
    }
    pPictures->erase(pPictures->begin() + row, pPictures->begin() + row + count);
    endRemoveRows();


    return true;
}

QHash<int, QByteArray> PictureModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::DisplayRole] = "name";
    roles[Roles::FilePathRole] = "filepath";
    roles[Roles::UrlRole] = "url";
    return roles;
}

void PictureModel::setAlbumId(int albumId)
{
    beginResetModel();
    mAlbumId = albumId;
    loadPictures(mAlbumId);
    endResetModel();
}

void PictureModel::clearAlbum()
{
    setAlbumId(-1);
}

void PictureModel::deletePicturesForAlbum()
{
    pDB->pictureDao.removePicturesForAlbum(mAlbumId);
    clearAlbum();
}

void PictureModel::loadPictures(int albumId)
{
    if (albumId <= 0) pPictures = new QList<Picture*>();
    else              pPictures = pDB->pictureDao.getPicturesForAlbum(albumId);
}

bool PictureModel::isIndexValid(const QModelIndex& index) const
{
    if (index.row() < 0 || index.row() >= rowCount() || !index.isValid()) return false;
    else                                                                  return true;
}
