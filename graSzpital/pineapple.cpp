#include "pineapple.h"
#include "patient.h"

extern Patient* patient;

Pineapple::Pineapple(QString n){
    name = n;
}

Pineapple::~Pineapple(){

}

void Pineapple::fuel(){
    patient->setPhp(patient->getPhp()+2);
}

void Pineapple::setImage(int x, int y){
    setPos(x,y);
    setPixmap(QPixmap(":/images/ananas.png"));
}
