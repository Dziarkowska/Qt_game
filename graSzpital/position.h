#ifndef POSITION_H
#define POSITION_H

#include <QGraphicsTextItem>
#include <QPointF>

class Position :public QGraphicsTextItem{
public:
    Position(QGraphicsItem* parent=0);
    int posX;
    int posY;
    void updatePos();
};

#endif // POSITION_H
