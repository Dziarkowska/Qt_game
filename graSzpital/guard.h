#ifndef GUARD_H
#define GUARD_H

#include "person.h"

class Guard :public Person{
private:
    int evilness;
    Person* per;
public:
    Guard(QString n, int p, int m, int s, int w, int e);
    ~Guard();
    void paralyse();
    void fight();
    void help();
    void setImage(int x, int y);
    void show();
    int getEvilness();
    void setEvilness(int newevilness);
};
#endif // GUARD_H
