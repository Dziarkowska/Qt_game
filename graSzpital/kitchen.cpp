#include "kitchen.h"
#include <QDebug>
#include "patient.h"
#include "game.h"

extern Patient* patient;
extern Game* game;

Kitchen::Kitchen(int x, int y, int width, int height, double opacity, QString newname) :Room(x,y,width,height,opacity,newname){

}

Kitchen::~Kitchen(){

}

void Kitchen::accept(){

}

void Kitchen::cookFood(QString kind){
    if(patient->fruit != ""){
        if(kind == "pineapple"){
            Food* pineapple = Food::getFood(kind);
            pineapple->setImage(290,30);
            patient->setPine(pineapple);
            game->scene->addItem(pineapple);
        }
        if(kind == "peach"){
            Food* peach = Food::getFood(kind);
            peach->setImage(350,70);
            patient->setPicz(peach);
            game->scene->addItem(peach);
        }
        if(kind == "grapes"){
            Food* grapes = Food::getFood(kind);
            grapes->setImage(450,50);
            patient->setGrape(grapes);
            game->scene->addItem(grapes);
        }
    }
    patient->setFruit("");
}


