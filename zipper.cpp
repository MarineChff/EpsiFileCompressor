#include "zipper.h"
#include "zippedbuffer.h"
#include "zippedbufferpool.h"
#include "filepool.h"

#include <QDataStream>
#include <QFile>

using namespace std;

Zipper::Zipper()
{
}

void Zipper::CompressFile(QString filePath)
{
    QFile file(filePath);
    file.open(QIODevice::ReadOnly);
    QByteArray ba = file.readAll();
    file.close();

    QStringList resultat = filePath.split("\\");
    QString fileName = "";
    fileName = resultat[resultat.size()-1];

    ZippedBuffer* zipBuffer = new ZippedBuffer();
    zipBuffer->_name = fileName;
    zipBuffer->_compressedFile = ba;

    _ZBP.put(zipBuffer);


}
