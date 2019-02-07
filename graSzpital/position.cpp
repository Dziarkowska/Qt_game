#include "position.h"
#include "patient.h"
#include <QFont>

extern Patient* patient;

Position::Position(QGraphicsItem *parent) :QGraphicsTextItem(parent){
    setPlainText(QString("current position: ") +QString("\n      ") + QString::number(posX) + QString(":")
                 + QString::number(posY));
    setDefaultTextColor(Qt::darkRed);
    setFont(QFont("times",16));
    setPos(1085,160);
}

void Position::updatePos()
{
    posX = patient->pos().x() + 60;
    posY = patient->pos().y() + 60;
    setPlainText(QString("current position: ") +QString("\n      ") + QString::number(posX) + QString(":")
                 + QString::number(posY));
}
