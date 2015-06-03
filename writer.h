#ifndef WRITER_H
#define WRITER_H

#include <QString>
#include "zippedbufferpool.h"

class Writer
{
public:
    Writer(QString directory, QString ecfFileName, ZippedBufferPool pool);
    void writeCompressedFile();
    void writeUnCompressedFiles();

private:
    ZippedBufferPool _poolZippedBuffer;
    QString _parentDirectory;
    QString _rootDirectory;
    QString _rootDirectoryName;
    QString _ecfFileName;
    QString CreateDirectory(QString directoryParent,QString directoryToCreate);
};

#endif // WRITER_H
