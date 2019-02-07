#ifndef WALL_H
#define WALL_H

#include "room.h"

class Wall :public QGraphicsRectItem{
public:
    Wall(int x, int y, int width, int height, double opacity, QString newname);
    QString name;
    QString getName();
    void setName(QString newName);

};

#endif // WALL_H
