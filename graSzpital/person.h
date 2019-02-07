#ifndef PERSON_H
#define PERSON_H
#include <QString>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Person :public QObject, public QGraphicsPixmapItem{
public:
    QString name;
    int php; //physicalhealthpoints
    int mhp; //mentalhealthpoints
    int strength;
    int wisdom;

    Person(QString n, int p, int m, int s, int w);
    Person();
    ~Person();
    QString getName();
    void setName(QString newName);
    int getPhp();
    void setPhp(int newphp);
    int getMhp();
    void setMhp(int newmhp );
    int getStrength();
    void setStrength(int newstrength);
    int getWisdom();
    void setWisdom(int newwisdom );
    void show();
    virtual void fight()=0;

};

#endif // PERSON_H
