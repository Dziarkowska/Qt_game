#include "wall.h"

Wall::Wall(int x, int y, int width, int height, double opacity, QString newname){
    setRect(x,y,width,height);
    setOpacity(opacity);
    name = newname;
}

QString Wall::getName(){
    return name;
}

void Wall::setName(QString newName){
    name = newName;
}
