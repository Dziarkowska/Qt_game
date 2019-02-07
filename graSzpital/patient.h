#ifndef PATIENT_H
#define PATIENT_H

#include "person.h"
#include <QPointF>
#include <QList>
#include <QLineF>
#include <stdlib.h>
#include "pineapple.h"
#include "grapes.h"
#include "peach.h"
#include "kitchen.h"
#include "cat.h"

class Patient :public Person{
    Q_OBJECT
private:
    int counter=0;
    QString flag="";


    Person *per;
    Patient(QString n="", int p=10, int m=10, int s=10, int w=10);
    Patient(Patient const&);
    void operator=(Patient const&);

public:
    int counter1=0;
    ~Patient();
    QString fruit="";
    Food* pin;
    Food* picz;
    Food* grapes;
    Kitchen* kitchen;
    Animal* cat;
    Animal* dog;
    QPointF collidingPos;
    QLineF line;
    QList<QPointF> positions;
    QList<QPointF> positions1;

    QString getMyFlag();
    QPointF getCollidingPos();
    static Patient& getInstance();

    void keyPressEvent(QKeyEvent *event);

    void setMyFlag(QString newflag);
    void setImage();
    void setFruit(QString newfruit);
    void setFood(Food *newpin, Food *newpicz, Food *newgrapes, Kitchen *kitch, Animal *kiti, Animal *dogi);
    void setCollidingPos(int x, int y);
    void setPine(Food* newpin);
    void setPicz(Food* newpicz);
    void setGrape(Food* newgrape);
    void moveBackward();

    void ifNotInterracting();
    int createRand(int limit);
    void fight();
    void ItemDeleted(QString item);
    void fuel(Pineapple* p);
    void fuel(Peach *p);
    void fuel(Grapes* gr);
    void escape();
    void heal();
    void myPath();
public slots:
    void move();
};
#endif // PATIENT_H
