#ifndef PICTUREMODEL_H
#define PICTUREMODEL_H

#include <QList>
#include <QAbstractListModel>

#include "gallery-core_global.h"
#include "Picture.h"

class Album;
class DatabaseManager;
class AlbumModel;

class GALLERYCORESHARED_EXPORT PictureModel : public QAbstractListModel
{
    Q_OBJECT

public:

    enum Roles 
    {
        UrlRole = Qt::UserRole + 1,
        FilePathRole
    };
    PictureModel(const AlbumModel& albumModel, QObject* parent = 0);

    QModelIndex addPicture(Picture  * ppict);
    void        setAlbumId(int albumId);
    void        clearAlbum();

    QHash<int, QByteArray> roleNames ()  const override;
    bool                   removeRows(int row, int count, const QModelIndex &parent)   override;
    int                    rowCount  (const QModelIndex &parent = QModelIndex()) const override;
    QVariant               data      (const QModelIndex &index, int role)        const override;

protected:
    bool canFetchMore(const QModelIndex &parent) const override;
    void fetchMore   (const QModelIndex &parent)       override;

signals:
    void numberPopulated(int number);
public slots:
    void deletePicturesForAlbum();

private:
    void loadPictures(int albumId);
    bool isIndexValid(const QModelIndex& index) const;

private:
    DatabaseManager * pDB;
    QList<Picture*> * pPictures;
    int               mAlbumId;
    int               mPictsCount;
};

#endif // PICTUREMODEL_H
