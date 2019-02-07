#ifndef PINEAPPLE_H
#define PINEAPPLE_H

#include "food.h"

class Pineapple :public Food{
public:

    Pineapple(QString n="pineapple");
    ~Pineapple();
    void fuel();
    void setImage(int x, int y);
};

#endif // PINEAPPLE_H
