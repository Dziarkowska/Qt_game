#ifndef FOOD_H
#define FOOD_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>


class Food :public QObject, public QGraphicsPixmapItem{
public:

    QString name;
    Food();
    ~Food();
    static Food* getFood(QString name);
    virtual void fuel()=0;
    virtual void setImage(int x, int y)=0;

};

#endif // FOOD_H
