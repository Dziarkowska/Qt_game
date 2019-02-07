#ifndef PEACH_H
#define PEACH_H

#include "food.h"

class Peach :public Food{
public:
    Peach(QString n="peach");
    ~Peach();
    void fuel();
    void setImage(int x, int y);
};

#endif // PEACH_H
