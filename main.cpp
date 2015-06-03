#include "mainwindow.h"
#include <QApplication>

#include "epsifilecompressor.h"

int main(int argc, char *argv[])
{
    EpsiFileCompressor *epsiFileCompressor = new EpsiFileCompressor();
    epsiFileCompressor->compress("C:\\Users\\Marine\\Documents\\C++\\TESTCompress","COMPRESS");

    epsiFileCompressor->uncompress("C:\\Users\\Marine\\Documents\\C++\\COMPRESS.ecf","C:\\Users\\Marine\\Documents\\C++\\COMPRESS");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
