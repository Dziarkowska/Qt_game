#ifndef GRAPES_H
#define GRAPES_H

#include "food.h"

class Grapes :public Food{
public:
    Grapes(QString n="peach");
    ~Grapes();
    void fuel();
    void setImage(int x, int y);
};

#endif // GRAPES_H
