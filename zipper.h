#ifndef ZIPPER_H
#define ZIPPER_H

#include "zippedbuffer.h"
#include <QString>

class Zipper
{
public:
    Zipper();
    ZippedBuffer GetZippedBuffer(QString fileName);
};

#endif // ZIPPER_H
