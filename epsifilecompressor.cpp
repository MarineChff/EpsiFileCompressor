#include "epsifilecompressor.h"
#include "filepool.h"
#include "zippedbufferpool.h"
#include "writer.h"
#include "zipper.h"

#include <QStringList>
#include <QFile>

EpsiFileCompressor::EpsiFileCompressor()
{

}
void EpsiFileCompressor::uncompress(const QString &ecfFileName, const QString &folder )
{
    QFile fileToUncompress(ecfFileName);
    fileToUncompress.open(QIODevice::Append);

    QDataStream dataStreamUncompress(&fileToUncompress);

    ZippedBufferPool* zippedBufferPool = new ZippedBufferPool();

    while(dataStreamUncompress.atEnd() == false){
        ZippedBuffer* zippedBuffer = new ZippedBuffer();
        zippedBuffer->read(dataStreamUncompress);

        zippedBufferPool->put(zippedBuffer);
    }

    std::list<ZippedBuffer*> listeZippedBuffer = zippedBufferPool->_listZippedBuffer;
    int count = 0;
    for(std::list<ZippedBuffer*>::iterator it = listeZippedBuffer.begin(); it != listeZippedBuffer.end(); it++)
    {
        count += 1;
    }

    std::cout << count << std::endl;

}

void EpsiFileCompressor::compress(const QString &folder, const QString &ecfFileName)
{
    QStringList *filePool = new FilePool(folder);
    ZippedBufferPool *zippedBufferPool = new ZippedBufferPool();

    for(QStringList::iterator it = filePool->begin(); it != filePool->end(); it++)
    {
        Zipper *zipper = new Zipper(zippedBufferPool);
        zipper->CompressFile(*it);
    }

    Writer *writer = new Writer(folder, ecfFileName, *zippedBufferPool);
    writer->writeCompressedFile();
}
