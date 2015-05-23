#include "epsifilecompressor.h"
#include "filepool.h"
#include "zippedbufferpool.h"
#include "writer.h"
#include "zipper.h"


EpsiFileCompressor::EpsiFileCompressor()
{

}
void EpsiFileCompressor::uncompress(const QString &ecfFileName, const QString &folder )
{

}
void EpsiFileCompressor::compress(const QString &folder, const QString &ecfFileName)
{
    FilePool *filePoolManager = new FilePool();
    ZippedBufferPool *zippedBufferPool = new ZippedBufferPool();
    std::list<QString> listeFiles = filePoolManager->GetListeFichiers(folder);
    for(std::list<QString>::iterator it = listeFiles.begin(); it != listeFiles.end(); it++)
    {
        Zipper *zipper = new Zipper();
        zippedBufferPool->put(zipper->GetZippedBuffer(*it));
    }
    Writer *writer = new Writer(folder,*zippedBufferPool);
    writer->writeCompressedFile();
}
