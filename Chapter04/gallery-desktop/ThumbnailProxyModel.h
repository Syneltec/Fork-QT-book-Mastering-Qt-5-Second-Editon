#ifndef _THUMBNAILPROXYMODEL_H
#define _THUMBNAILPROXYMODEL_H


typedef QIdentityProxyModel typedef4;
class ThumbnailProxyModel : public typedef4 {
  Q_OBJECT
  public:
    ThumbnailProxyModel(QObject * parent = 0);

    QVariant data(const QModelIndex & index, int role) const override;

    void setSourceModel(QAbstractItemModel * sourceModel) override;

    PictureModel * pictureModel() const;


  private:
    void reloadThumbnails();

    void generateThumbnails(const QModelIndex & startIndex, int count);

    QHash<QString, QPixmap*> mThumbnails;

};
#endif
