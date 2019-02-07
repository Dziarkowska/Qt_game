#include "room.h"

Room::Room(int x, int y, int width, int height, double opacity, QString newname){
    setRect(x,y,width,height);
    setOpacity(opacity);
    name = newname;
}

Room::~Room(){

}

QString Room::getName(){
    return name;
}

void Room::setName(QString newName){
    name = newName;
}


