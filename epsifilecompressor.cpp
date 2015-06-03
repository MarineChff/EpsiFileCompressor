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


void EpsiFileCompressor::compress(const QString &folder, const QString &ecfFileName)
{
    QStringList *filePool = new FilePool(folder);
    ZippedBufferPool *zippedBufferPool = new ZippedBufferPool();

    for(QStringList::iterator it = filePool->begin(); it != filePool->end(); it++)
    {
        Zipper *zipper = new Zipper(zippedBufferPool,folder);
        zipper->CompressFile(*it);
    }

    Writer *writer = new Writer(folder, ecfFileName, *zippedBufferPool);
    writer->writeCompressedFile();
}


void EpsiFileCompressor::uncompress(const QString &ecfFileName, const QString &folder )
{
    QFile fileToUncompress(ecfFileName);

    std::cout << ecfFileName.toStdString() << std::endl;
    fileToUncompress.open(QIODevice::ReadOnly);

    QDataStream dataStreamUncompress(&fileToUncompress);

    ZippedBufferPool* zippedBufferPool = new ZippedBufferPool();

    while(dataStreamUncompress.atEnd() == false){
        ZippedBuffer* zippedBuffer = new ZippedBuffer();
        zippedBuffer->read(dataStreamUncompress);

        //std::cout << zippedBuffer->_name.toStdString() << std::endl;

        zippedBufferPool->put(zippedBuffer);
    }

    Writer* writer = new Writer(folder, ecfFileName, *zippedBufferPool);
    writer->writeUnCompressedFiles();

    fileToUncompress.close();
}
