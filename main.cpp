#include "mainwindow.h"
#include <QApplication>

#include "epsifilecompressor.h"

int main(int argc, char *argv[])
{
    EpsiFileCompressor *epsiFileCompressor = new EpsiFileCompressor();
    epsiFileCompressor->compress("C:\\Users\\benjamin\\Documents\\Cours I4\\Multithreading C++\\Parser3","COMPRESS");

    epsiFileCompressor->uncompress("C:\\Users\\benjamin\\Documents\\Cours I4\\Multithreading C++\\COMPRESS.ecf","C:\\Users\\benjamin\\Documents\\Cours I4\\Multithreading C++\\projet");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
