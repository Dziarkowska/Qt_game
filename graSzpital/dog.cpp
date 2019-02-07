#include "dog.h"
#include "patient.h"

extern Patient* patient;

Dog::Dog(QString n, bool f){
    name = n;
    friendly = f;

}

Dog::~Dog(){

}

void Dog::help(){
    patient->setMhp(patient->getMhp()+1);
}

void Dog::setImage(int x, int y){
    setPos(x,y);
    setPixmap(QPixmap(":/images/pudel.png"));
}
