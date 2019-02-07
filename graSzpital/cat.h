#ifndef CAT_H
#define CAT_H

#include "animal.h"
#include <QPointF>
#include <QList>
#include <QTimer>

class Cat :public Animal{
    Q_OBJECT
public:
    Cat(QString n = "Garfield", bool f = false, int x=601, int y=185);
    ~Cat();
    void help();
    void setImage(int x, int y);
    void rotateToPoint(QPointF p);
    QList<QPointF> points;
    int point_index;
    QPointF dest;
    QPointF start;
    QTimer *timer;
public slots:
    void move_forward();
};

#endif // CAT_H
