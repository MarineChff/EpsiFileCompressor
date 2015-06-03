#include "writer.h"
#include "zippedbuffer.h"

#include <QString>
#include <QStringList>
#include <QFile>
#include <iostream>
#include <QList>
#include <QDataStream>
#include <direct.h>



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

    std::list<ZippedBuffer*> listeZippedBuffer = _poolZippedBuffer._listZippedBuffer;

    int count = 0;

    for(std::list<ZippedBuffer*>::iterator it = listeZippedBuffer.begin(); it != listeZippedBuffer.end(); it++)
    {
        ZippedBuffer *zippedBuffer = ((ZippedBuffer*) *it);
        zippedBuffer->write(data);

        std::cout << "compress : " << zippedBuffer->_name.toStdString() << std::endl;
        count += 1 ;
    }

    std::cout << "NB fichiers compressés : " << count << std::endl;

    file.close();
}

void Writer::writeUnCompressedFiles()
{
    _ecfFileName.remove(_ecfFileName.size() - 4, _ecfFileName.size());
    QString chemin = _parentDirectory + "\\" + _ecfFileName;



    std::list<ZippedBuffer*> listeZippedBuffer = _poolZippedBuffer._listZippedBuffer;

    int count = 0;

    for(std::list<ZippedBuffer*>::iterator it = listeZippedBuffer.begin(); it != listeZippedBuffer.end(); it++)
    {
        ZippedBuffer *zippedBuffer = ((ZippedBuffer*) *it);
        QString cheminFile = chemin + "\\" + zippedBuffer->_name;
        QFile file(cheminFile);
        file.open(QFile::WriteOnly);

        std::cout << cheminFile.toStdString() << std::endl;

        QDataStream data(&file);

        QByteArray uncompressedArray(qUncompress(zippedBuffer->_compressedFile));
        data.writeRawData(uncompressedArray.constData(), uncompressedArray.size());

        file.close();

        std::cout << "uncompress : " << zippedBuffer->_name.toStdString() << std::endl;
        count += 1 ;

    }

    std::cout << "NB fichiers décompressés : " << count << std::endl;



}
