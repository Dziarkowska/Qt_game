#include "dispstatistics.h"
#include "patient.h"
#include "game.h"
#include "QFont"
#include <QBrush>
#include <QGraphicsRectItem>

extern Patient* patient;
extern Game* game;

DispStats::DispStats(QGraphicsItem *parent) :QGraphicsTextItem(parent){


    setPlainText(QString("name: ") + QString(names) + QString("\nphp: ") + QString::number(phps)
                 + QString("\nmhp: ") + QString::number(mhps)
                 + QString("\nwisdom: ") + QString::number(wisdoms)
                 + QString("\nstrength: ") + QString::number(strengths));


    setDefaultTextColor(Qt::black);
    setFont(QFont("times",16));
    setPos(1100,10);
}

void DispStats::updateStats(){
    names = patient->getName();
    mhps = patient->getMhp();
    phps = patient->getPhp();
    wisdoms = patient->getWisdom();
    strengths = patient->getStrength();
    setPlainText(QString("name: ") + QString(names) + QString("\nphp: ") + QString::number(phps)
                 + QString("\nmhp: ") + QString::number(mhps)
                 + QString("\nwisdom: ") + QString::number(wisdoms)
                 + QString("\nstrength: ") + QString::number(strengths));
}
