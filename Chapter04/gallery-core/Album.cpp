#include "Album.h"

Album::Album(const QString& name, int id) : mId(id), mName(name)
{
}

int Album::getId() const
{
    return mId;
}

void Album::setId(int id)
{
    mId = id;
}

QString Album::getName() const
{
    return mName;
}

void Album::setName(const QString& name)
{
    mName = name;
}
