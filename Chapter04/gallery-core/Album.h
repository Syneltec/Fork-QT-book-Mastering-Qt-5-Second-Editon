#ifndef ALBUM_H
#define ALBUM_H

#include <QString>

#include "gallery-core_global.h"

class GALLERYCORESHARED_EXPORT Album
{
public:
    explicit Album(const QString& name = "", int id = -1);

    int     getId  () const;
    void    setId  (int id);
    QString getName() const;
    void    setName(const QString& name);

private:
    int     mId;
    QString mName;
};

#endif // ALBUM_H
