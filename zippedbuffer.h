#ifndef ZIPPEDBUFFER_H
#define ZIPPEDBUFFER_H

#include <QString>
#include <QByteArray>
#include <QDataStream>

class ZippedBuffer
{
public:
    ZippedBuffer();
    void write(QDataStream &stream);
    void read(QDataStream &stream);

    QString _name;
    QByteArray _compressedFile;

};

#endif // ZIPPEDBUFFER_H
