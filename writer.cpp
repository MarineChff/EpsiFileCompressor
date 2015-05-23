#include "writer.h"
#include "zippedbuffer.h"

#include <QString>
#include <QStringList>
#include <QFile>
#include <iostream>
#include <QList>


Writer::Writer(QString directory,ZippedBufferPool pool)
{
    _poolZippedBuffer = pool;
    _rootDirectory = directory;
    QStringList resultat = directory.split("\\");
    for(int i =0;i<resultat.size()-1;i++)
    {
        _parentDirectory+= resultat[i];
    }
    _rootDirectoryName =resultat[resultat.size()-1];
}

void Writer::writeCompressedFile()
{
    QFile file(_parentDirectory + "\\" + _rootDirectoryName + ".ecf");
    QDataStream data(&file);
    std::list<ZippedBuffer> listeZippedBuffer = _poolZippedBuffer._listZippedBuffer;
    for(std::list<ZippedBuffer>::iterator it = listeZippedBuffer.begin(); it != listeZippedBuffer.end(); it++)
    {
        ZippedBuffer zipBuffer = ((ZippedBuffer)*it);
        data << zipBuffer._name;
        data << zipBuffer._compressedFile;
    }
}

void Writer::writeUnCompressedFiles(){

}
