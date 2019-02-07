#include "patient.h"
#include "game.h"
#include "guard.h"
#include "doctor.h"
#include "kitchen.h"
#include "message.h"
#include "dog.h"
#include "greenmessage.h"
#include "wall.h"

#include <QPixmap>
#include <QKeyEvent>
#include <QList>
#include <QPointF>
#include <typeinfo>
#include <QDebug>
#include <QGraphicsLineItem>
#include <QLineF>
#include <QPen>
#include <qmath.h>



extern Game* game;
extern Doctor* doctor;
extern Doctor* bad_doctor;
extern Patient* patient;
extern Guard* guard;
extern Guard* bad_guard;
extern Message* message;

Patient::Patient(QString n, int p, int m, int s, int w) :Person(n,p,m,s,w){

}

Patient::Patient(const Patient &) :Person(){

}

void Patient::operator=(const Patient &){

}

Patient::~Patient(){

}

Patient &Patient::getInstance(){
    static Patient INSTANCE;
    return INSTANCE;
}

void Patient::keyPressEvent(QKeyEvent *event){
if(flag == QString("")){
    game->timer->start(10);

    if(event->key() == Qt::Key_Left){
        if(pos().x() > -20){
            setPos(x()-10, y());
        }
    }
    else if(event->key() == Qt::Key_Right){
        if(pos().x() + 460 < 1290){
            setPos(x()+10, y());
        }
    }
    if(event->key() == Qt::Key_Up){
        if(pos().y() > 10){
            setPos(x(), y() -10);
        }
    }
    else if(event->key() == Qt::Key_Down){
        if(pos().y() +110 < 660){
            setPos(x(), y() +10);
        }
    }
}

positions << QPointF(this->pos().x()+60,this->pos().y()+60);
positions1 << QPointF(this->pos().x(),this->pos().y());
this->myPath();

    if(event->key() == Qt::Key_Escape){
        game->close();
    }

    else if(event->key() == Qt::Key_1){
        if(flag == "guard"){
            if (createRand(2) == 1){
                game->fight(guard);
                game->message->printMessage("guard_fight.txt");
            }
            else{
                game->fight(bad_guard);
                game->message->printMessage("guard_fight.txt");
            }

        }
        else if(flag == "doctor"){
            if (createRand(2) == 1){
                game->fight(doctor);
                game->message->printMessage("doctor_fight.txt");
            }
            else{
                game->fight(bad_doctor);
                game->message->printMessage("doctor_fight.txt");
            }
        }
        else if(flag == "kitchen"){

        }
        else if(flag == "dog"){
            dog->help();
            game->message->printMessage("dog_help.txt");
        }
        else if(flag == "cat"){
            cat->help();
            game->message->printMessage("cat_help.txt");
        }
        else if(flag == "greenmessaage"){

        }
        else if(flag == "wall"){

        }
    setMyFlag("");
    moveBackward();
    }

    else if(event->key() == Qt::Key_2){
        if(flag == "guard"){
            if (createRand(2) == 1){
                bad_guard->paralyse();
                game->message->printMessage("guard_paralyse.txt");
            }
            else{
                guard->help();
                game->message->printMessage("guard_help.txt");
            }
        }
        else if(flag == "doctor"){
            if (createRand(2) == 1){
                doctor->heal();
                game->message->printMessage("doctor_heal.txt");
            }
            else{
                bad_doctor->poison();
                game->message->printMessage("doctor_poison.txt");
            }
        }
        else if(flag == "kitchen"){

        }
        else if(flag == "dog"){

        }
        else if(flag == "cat"){

        }
    setMyFlag("");
    moveBackward();
    }

    else if(event->key() == Qt::Key_3){
        if(flag == "guard"){

        }
        else if(flag == "doctor"){

        }
        else if(flag == "kitchen"){

        }
        else if(flag == "dog"){

        }
        else if(flag == "cat"){

        }
    setMyFlag("");
    moveBackward();
    }
}

void Patient::ifNotInterracting(){
    if(flag != "kitchen"){
        kitchen->cookFood(fruit);
    }
}

QString Patient::getMyFlag(){
    return flag;
}

QPointF Patient::getCollidingPos(){
    return collidingPos;
}

void Patient::ItemDeleted(QString item){
    fruit = item;
}

void Patient::setMyFlag(QString newflag){
    flag = newflag;
}

void Patient::setImage(){
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setPos(290,550);
    setPixmap(QPixmap(":/images/patient2.png"));
}

void Patient::setFruit(QString newfruit){
    fruit = newfruit;
}

void Patient::setFood(Food* newpin, Food* newpicz, Food* newgrapes, Kitchen* kitch, Animal *kiti, Animal *dogi){
    pin = newpin;
    picz = newpicz;
    grapes = newgrapes;
    kitchen = kitch;
    cat = kiti;
    dog = dogi;
}

void Patient::setCollidingPos(int x, int y){
    collidingPos.setX(x);
    collidingPos.setY(y);
}

void Patient::setPicz(Food *newpicz){
    picz=newpicz;
}

void Patient::setGrape(Food *newgrape){
    grapes=newgrape;
}

void Patient::setPine(Food *newpin){
    pin = newpin;
}

void Patient::moveBackward(){
    int n = positions1.size()-2;
    setPos(positions1[n].x(),positions1[n].y());
}

int Patient::createRand(int limit){
    int random_numb = rand() % limit;
    return random_numb;
}

void Patient::fight(){
    if(createRand(2) == 1)
        setPhp(getPhp()+1);
    else
        setPhp(getPhp()-1);
}

void Patient::fuel(Pineapple *p){
    p->fuel();
}

void Patient::fuel(Peach *p){
    p->fuel();
}

void Patient::fuel(Grapes *gr){
    gr->fuel();
}

void Patient::escape(){
    setPos(50,50);
}

void Patient::heal(){

}

void Patient::myPath(){
    for(size_t i = 1, n = positions.size(); i < n ; i++){
        line = QLineF(positions[i-1],positions[i]);
        QGraphicsLineItem * lineItem = new QGraphicsLineItem(line);
        QPen pen;
        pen.setWidth(1);
        pen.setColor(Qt::lightGray);
        pen.setStyle(Qt::DotLine);
        lineItem->setPen(pen);
        //game->scene->addItem(lineItem);
    }

}

void Patient::move(){

    game->stats->updateStats();
    game->cur_pos->updatePos();
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0, n = colliding_items.size(); i < n; i++){

        collidingPos = pos();

        if(typeid(*(colliding_items[i])) == typeid(Guard)){

            game->message->printMessage("guard.txt");
            setMyFlag(QString("guard"));
        }
        else if(typeid(*(colliding_items[i])) == typeid(Doctor)){
            game->message->printMessage("doctor.txt");
            setMyFlag(QString("doctor"));
        }
        else if(typeid(*(colliding_items[i])) == typeid(Kitchen)){
            if(this->mhp > 7){
                setMyFlag(QString("kitchen"));
                //game->message->printMessage("food.txt");
                game->message->printMessage("kitchen.txt");
            }
        }
        else if(typeid(*(colliding_items[i])) == typeid(Dog)){
            setMyFlag("dog");
            game->message->printMessage("dog.txt");
        }
        else if(typeid(*(colliding_items[i])) == typeid(Cat)){
            setMyFlag("cat");
            game->message->printMessage("cat.txt");
        }
        else if(typeid(*(colliding_items[i])) == typeid(Pineapple)){
            pin->fuel();
            game->scene->removeItem(colliding_items[i]);
            delete colliding_items[i];
            ItemDeleted(QString("pineapple"));
            counter1++;
        }
        else if(typeid(*(colliding_items[i])) == typeid(Peach)){
            picz->fuel();
            game->scene->removeItem(colliding_items[i]);
            delete colliding_items[i];
            ItemDeleted(QString("peach"));
            counter1++;
        }
        else if(typeid(*(colliding_items[i])) == typeid(Grapes)){
            grapes->fuel();
            game->scene->removeItem(colliding_items[i]);
            delete colliding_items[i];
            ItemDeleted(QString("grapes"));
            counter1++;

        }
        else if(typeid(*(colliding_items[i])) == typeid(GreenMessage)){
            if(fruit == ""){
                setMyFlag("greenmessage");
                game->message->printMessage(("greenmessage.txt"));
            }
            else if(counter1 != 0){
                ifNotInterracting();
                game->scene->removeItem(colliding_items[i]);
                delete colliding_items[i];
            }
        }
        else if(typeid(*(colliding_items[i])) == typeid(Wall)){
            setMyFlag("wall");
        }

    //QLineF ln(pos(),colliding_items[i]->pos());
    //setRotation(-1*ln.angle());
    game->timer->stop();
    }


}

