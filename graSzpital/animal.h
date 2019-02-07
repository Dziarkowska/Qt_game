#ifndef ANIMAL_H
#define ANIMAL_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>

class Animal :public QObject, public QGraphicsPixmapItem{
public:
    Animal();
    ~Animal();
    virtual void help()=0;
    virtual void setImage(int x, int y)=0;
    bool friendly;
    QString species;
    QString name;
    static Animal* getAnimal(QString species);

};


#endif // ANIMAL_H
