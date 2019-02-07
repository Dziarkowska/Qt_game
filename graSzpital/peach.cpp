#include "peach.h"
#include "patient.h"

extern Patient* patient;

Peach::Peach(QString n){
    name = n;
}

Peach::~Peach(){

}

void Peach::fuel(){
    patient->setPhp(patient->getPhp()+1);
}

void Peach::setImage(int x, int y){
    setPos(x,y);
    setPixmap(QPixmap(":/images/peach.png"));
}
