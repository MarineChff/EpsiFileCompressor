#include "filepool.h"

#include <QDirIterator>
#include <QDebug>

FilePool::FilePool()
{
}

void FilePool::GetFiles(QString directory)
{
    QDirIterator it(directory, QDirIterator::Subdirectories);
    while (it.hasNext())
    {
        _listeFichiers.insert(_listeFichiers.begin(),it.filePath());
        qDebug() << it.next();
    }
}

std::list<QString> FilePool::GetListeFichiers(QString directory)
{
    GetFiles(directory);
    return _listeFichiers;
}

