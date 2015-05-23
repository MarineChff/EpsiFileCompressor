#include "mainwindow.h"
#include <QApplication>

#include "epsifilecompressor.h"

int main(int argc, char *argv[])
{
    EpsiFileCompressor *epsiFileCompressor = new EpsiFileCompressor();
    epsiFileCompressor->compress("C:\\Users\\Marine\\Documents\\C++","TESTCompress.txt");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
