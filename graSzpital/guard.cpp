#include "guard.h"
#include "patient.h"
#include <QPixmap>

extern Patient* patient;

Guard::Guard(QString n, int p, int m, int s, int w, int e) :Person(n,p,m,s,w){
    evilness = e;
}

Guard::~Guard(){

}

void Guard::paralyse(){
    if(this->getEvilness() > 0){
        patient->setPhp(patient->getPhp()-2);
    }
}

void Guard::fight(){
    if(this->getEvilness() > 0){
        patient->setPhp(patient->getPhp()-1);
        patient->setMhp(patient->getMhp()-1);
    }
    else{
        patient->setMhp(patient->getMhp()+1);
    }
}

void Guard::help(){
    patient->setWisdom(patient->getWisdom()+1);
}

void Guard::setImage(int x, int y){
    setPos(x,y);
    setPixmap(QPixmap(":/images/guard.png"));
}

void Guard::show(){

}

int Guard::getEvilness(){
    return evilness;
}

void Guard::setEvilness(int newevilness){
    evilness=newevilness;
}
