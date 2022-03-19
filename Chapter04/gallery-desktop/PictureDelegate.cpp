
#include "PictureDelegate.h"

PictureDelegate::PictureDelegate(QObject * parent) :
    QStyledItemDelegate(parent)
{
}

void PictureDelegate::paint() const {
    painter->save();

    QPixmap pixmap = index.model()->data(index, Qt::DecorationRole).value<QPixmap>();
    painter->drawPixmap(option.rect.x(), option.rect.y(), pixmap);

    QRect bannerRect = QRect(option.rect.x(), option.rect.y(), pixmap.width(), BANNER_HEIGHT);
    QColor bannerColor = QColor(BANNER_COLOR);
    bannerColor.setAlpha(BANNER_ALPHA);
    painter->fillRect(bannerRect, bannerColor);

    QString filename = index.model()->data(index, Qt::DisplayRole).toString();
    painter->setPen(BANNER_TEXT_COLOR);
    painter->drawText(bannerRect, Qt::AlignCenter, filename);

    if (option.state.testFlag(QStyle::State_Selected)) {
        QColor selectedColor = option.palette.highlight().color();
        selectedColor.setAlpha(HIGHLIGHT_ALPHA);
        painter->fillRect(option.rect, selectedColor);
    }

    painter->restore();
}

QSize PictureDelegate::sizeHint() const {
    const QPixmap& pixmap = index.model()->data(index, Qt::DecorationRole).value<QPixmap>();
    return pixmap.size();
}

