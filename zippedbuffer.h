#ifndef ZIPPEDBUFFER_H
#define ZIPPEDBUFFER_H

#include "qdatastream.h"

class ZippedBuffer
{
public:
    void write(QDataStream &stream);
    void read(QDataStream &stream);
    ZippedBuffer();

    QString _name;
    QByteArray _compressedFile;
};

#endif // ZIPPEDBUFFER_H
