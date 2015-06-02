#ifndef ZIPPER_H
#define ZIPPER_H

#include "zippedbuffer.h"
#include "zippedbufferpool.h"
#include <QString>

class Zipper
{
public:
    Zipper(ZippedBufferPool* ZBP);
    void CompressFile(QString file);

    ZippedBufferPool* _ZBP;
};

#endif // ZIPPER_H
