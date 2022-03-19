#ifndef _PICTUREDELEGATE_H
#define _PICTUREDELEGATE_H


typedef QStyledItemDelegate typedef3;
class PictureDelegate : public typedef3 {
  Q_OBJECT
  public:
    PictureDelegate(QObject * parent = 0);

    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const override;

    QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const override;

};
#endif
