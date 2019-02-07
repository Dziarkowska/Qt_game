#ifndef DOG_H
#define DOG_H

#include "animal.h"

class Dog :public Animal{
public:
    Dog(QString n = "Reksio",bool f = true);
    ~Dog();
    void help();
    void setImage(int x, int y);
};
#endif // DOG_H
