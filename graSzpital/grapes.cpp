#include "grapes.h"
#include "patient.h"

extern Patient* patient;

Grapes::Grapes(QString n){
    name = n;
}

Grapes::~Grapes(){

}

void Grapes::fuel(){
    patient->setPhp(patient->getPhp()+1);
}

void Grapes::setImage(int x, int y){
    setPos(x,y);
    setPixmap(QPixmap(":/images/grapes.png"));
}
