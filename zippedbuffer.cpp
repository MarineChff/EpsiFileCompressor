#include "zippedbuffer.h"
#include "qdatastream.h"

ZippedBuffer::ZippedBuffer()
{
}

void ZippedBuffer::write(QDataStream &stream)
{
   stream << _name << _compressedFile;
}

void ZippedBuffer::read(QDataStream &stream)
{
    stream >> _name >> _compressedFile;
}

