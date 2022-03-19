
#include "ThumbnailProxyModel.h"

ThumbnailProxyModel::ThumbnailProxyModel(QObject * parent) :
    QIdentityProxyModel(parent),
    mThumbnails()
{
}

QVariant ThumbnailProxyModel::data() const {
    if (role != Qt::DecorationRole) {
        return QIdentityProxyModel::data(index, role);
    }

    QString filepath = sourceModel()->data(index, PictureModel::Roles::FilePathRole).toString();
    return *mThumbnails[filepath];
}

void ThumbnailProxyModel::setSourceModel() {

class xxx : public ThumbnailProxyModel
{
private:
    ThumbnailProxyModel * ptpm;
public:
    xxx(ThumbnailProxyModel *p)
    {
        ptpm = p;
    }
    void reset()
    {
        ptpm->reloadThumbnails();
    }
};
    QIdentityProxyModel::setSourceModel(sourceModel);
    if (!sourceModel) return;



    connect(sourceModel, &QAbstractItemModel::modelReset, this, &ThumbnailProxyModel::reloadThumbnails);

    connect(sourceModel, &QAbstractItemModel::rowsInserted,
    [this] (const QModelIndex& /*parent*/, int first, int last)
    {
        generateThumbnails(index(first, 0), last - first + 1);
    });
}

PictureModel ThumbnailProxyModel::pictureModel() const {
    return static_cast<PictureModel*>(sourceModel());
}

void ThumbnailProxyModel::reloadThumbnails() {
    qDeleteAll(mThumbnails);
    mThumbnails.clear();
    generateThumbnails(index(0, 0), rowCount());
}

void ThumbnailProxyModel::generateThumbnails() {
    if (!startIndex.isValid()) {
        return;
    }

    const QAbstractItemModel* model = startIndex.model();
    int lastIndex = startIndex.row() + count;
    for(int row = startIndex.row(); row < lastIndex; row++) {
        QString filepath = model->data(model->index(row, 0), PictureModel::Roles::FilePathRole).toString();
        QPixmap pixmap(filepath);
        auto thumbnail = new QPixmap(pixmap
                                     .scaled(THUMBNAIL_SIZE, THUMBNAIL_SIZE,
                                             Qt::KeepAspectRatio,
                                             Qt::SmoothTransformation));
        mThumbnails.insert(filepath, thumbnail);
    }
}

