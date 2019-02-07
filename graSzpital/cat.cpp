#include "cat.h"
#include "patient.h"
#include "game.h"
#include <QTimer>
#include <qmath.h>

extern Patient* patient;
extern Game* game;

Cat::Cat(QString n, bool f, int x, int y){
    name = n;
    friendly = f;

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));
    timer->start(150);
}

Cat::~Cat(){

}

void Cat::help(){
    patient->setMhp(patient->getMhp()-2);
}

void Cat::setImage(int x, int y){
    setPos(x+80,y);
    setPixmap(QPixmap(":/images/cat.png"));
    points << QPointF(x-80,y) << QPointF(x+80,y);
    point_index=0;
    dest = points[0];
    rotateToPoint(dest);

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));
    timer->start(150);

}

void Cat::rotateToPoint(QPointF p){
        QLineF ln(pos(),p);
        //setRotation(-1*ln.angle());
}

void Cat::move_forward(){
    if(pos() != QPointF(521,185)){
       setPos(x()-1,y());
    }
    else{
       while( pos()!= QPointF(641,185)){
            setPos(x()+1,y());
        }
    }
}
