#ifndef DOCTOR_H
#define DOCTOR_H

#include "guard.h"
#include "patient.h"

class Doctor : public Guard
{
public:

    Doctor(QString n, int p, int m, int s, int w, int e, Guard* g1);
    void setImage(int x, int y);
    void poison();
    void fight();
    void heal();
private:
    Guard* g;
};

#endif // DOCTOR_H
