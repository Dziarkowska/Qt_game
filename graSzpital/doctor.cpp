#include "doctor.h"
#include <QPixmap>

extern Patient* patient;

Doctor::Doctor(QString n, int p, int m, int s, int w, int e, Guard *g1) :Guard(n,p,m,s,w,e){
    g=g1;
}

void Doctor::setImage(int x, int y){
    setPos(x,y);
    setPixmap(QPixmap(":/images/doctor.png"));
}

void Doctor::poison(){
    if(this->getEvilness() > 0){
        patient->setPhp(patient->getPhp()-1);
        patient->setStrength(patient->getStrength()-1);
    }
}

void Doctor::fight(){
    g->fight();
    if(this->getEvilness() > 0){
        patient->setStrength(patient->getStrength()+1);
    }
    else{
        patient->setStrength(patient->getStrength()-1);
    }
}

void Doctor::heal(){
    patient->setPhp(patient->getPhp()+1);
    patient->setStrength(patient->getStrength()+1);
}
