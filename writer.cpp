#include "writer.h"
#include "zippedbuffer.h"

#include <QString>
#include <QStringList>
#include <QFile>
#include <iostream>
#include <QList>


Writer::Writer(QString directory, QString ecfFileName, ZippedBufferPool pool)
{
    _poolZippedBuffer = pool;
    QStringList resultat = directory.split("\\");
    for(int i =0;i<resultat.size()-1;i++)
    {
        _parentDirectory += resultat[i] + "\\";
    }
    _ecfFileName = ecfFileName;
}

void Writer::writeCompressedFile()
{
    QString chemin = _parentDirectory + "\\" + _ecfFileName + ".ecf";
    QFile file(chemin);
    file.open(QIODevice::Append);

    std::cout << chemin.toStdString() << std::endl;
    QDataStream data(&file);

    std::cout << "first" << data.status() << std::endl;

    std::list<ZippedBuffer*> listeZippedBuffer = _poolZippedBuffer._listZippedBuffer;
    for(std::list<ZippedBuffer*>::iterator it = listeZippedBuffer.begin(); it != listeZippedBuffer.end(); it++)
    {
        ZippedBuffer *zippedBuffer = ((ZippedBuffer*) *it);
        zippedBuffer->write(data);
    }

    file.close();
}

void Writer::writeUnCompressedFiles(){

}
