#ifndef KITCHEN_H
#define KITCHEN_H
#include "room.h"
#include "food.h"

class Kitchen :public Room{
public:
    Kitchen(int x, int y, int width, int height, double opacity, QString newname);
    ~Kitchen();
    void accept();
    void cookFood(QString kind);
    Food* pin;
    Food* picz;
    Food* grapes;
};


#endif // KITCHEN_H
