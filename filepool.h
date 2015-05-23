#ifndef FILEPOOL_H
#define FILEPOOL_H

#include <QString>
#include <iostream>
#include <QList>

class FilePool
{
public:
    FilePool();
    std::list<QString> GetListeFichiers(QString directory);

private:
    void GetFiles(QString directory);
    std::list<QString> _listeFichiers;
};

#endif // FILEPOOL_H
