#include "game.h"
#include <QBrush>
#include <QImage>
#include "food.h"
#include "pineapple.h"
#include "grapes.h"
#include "peach.h"

extern Patient *patient;
extern Guard* guard;
extern Doctor* doctor;
extern Doctor* bad_doctor;
extern Guard* bad_guard;

Game::Game(QGraphicsWidget *parent){

   //Room* kitchen = new Kitchen(291,35,213,263,0,"kitchen");
   //kitchen->accept(patient);


   Animal* dog = Animal::getAnimal("dog");
   dog->setImage(800,150);
   Animal* cat = Animal::getAnimal("cat");
   cat->setImage(601,185);
   Food* pineapple = Food::getFood("pineapple");
   pineapple->setImage(290,30);
   Food* peach = Food::getFood("peach");
   peach->setImage(350,70);
   Food* grapes = Food::getFood("grapes");
   grapes->setImage(450,50);

   Kitchen* kitchen;
   kitchen = new Kitchen(291,35,213,263,0,"kitchen");
   Wall *wall1,*wall2,*wall3,*wall4,*wall5,*wall6;
   wall1 = new Wall(281,35,36,250,0,"wall1");
   wall2 = new Wall(499,35,8,257,0,"wall2");
   wall3 = new Wall(702,39,8,257,0,"wall3");
   wall4 = new Wall(279,420,10,240,0,"wall4");
   wall5 = new Wall(429,420,6,244,0,"wall5");
   wall6 = new Wall(711,420,10,244,0,"wall6");

   GreenMessage* gm;
   gm = new GreenMessage("greenmessage");
   gm->setImage(50,580);

   patient = &patient->getInstance();
   patient->setImage();
   patient->setFood(pineapple,peach,grapes,kitchen,cat,dog);
   guard = new Guard("Rio",10,10,10,10,0);
   guard->setImage(100,400);
   bad_guard = new Guard("Helsinki",10,10,10,0,10);
   bad_guard->setImage(500,500);
   doctor = new Doctor("Dexter",10,10,10,10,0,guard);
   doctor->setImage(50,50);
   bad_doctor = new Doctor("DredDoctor",10,10,10,10,10,bad_guard);
   bad_doctor->setImage(800,600);

   stats = new DispStats();
   cur_pos = new Position();

   message = new Message();

   //scene

   setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   setFixedSize(1335,690);

   scene = new QGraphicsScene();
   scene->setSceneRect(0,0,1335,690);
   setScene(scene);
   setBackgroundBrush(QBrush(QImage(":/images/szpital.png")));

   //stats background

   QGraphicsRectItem* statsback;
   statsback = new QGraphicsRectItem();
   QBrush brush;
   brush.setStyle(Qt::SolidPattern);
   brush.setColor(Qt::gray);
   statsback->setRect(1080,10,170,140);
   statsback->setBrush(brush);
   statsback->setOpacity(0.3);

   //pos background

   QGraphicsRectItem* posback;
   posback = new QGraphicsRectItem();
   QBrush brush1;
   brush1.setStyle(Qt::SolidPattern);
   brush1.setColor(Qt::red);
   posback->setRect(1080,155,170,70);
   posback->setBrush(brush1);
   posback->setOpacity(0.2);

   //timer

   timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),patient,SLOT(move()));
   timer->start(10);

   //items

   scene->addItem(patient);
   scene->addItem(guard);
   scene->addItem(doctor);
   scene->addItem(bad_doctor);
   scene->addItem(bad_guard);
   scene->addItem(stats);
   scene->addItem(cur_pos);
   scene->addItem(message);
   scene->addItem(kitchen);   
   scene->addItem(statsback);
   scene->addItem(posback);
   scene->addItem(dog);
   scene->addItem(cat);
   scene->addItem(pineapple);
   scene->addItem(grapes);
   scene->addItem(peach);
   scene->addItem(gm);
   scene->addItem(wall1);
   scene->addItem(wall2);
   scene->addItem(wall3);
   scene->addItem(wall4);
   scene->addItem(wall5);
   scene->addItem(wall6);


}

void Game::start(Guard *g, Doctor *doc, Dog *d, Cat *c, Kitchen *k){

}

void Game::fight(Guard *g){
    g->fight();
    patient->fight();
}

void Game::fight(Doctor *doc){
    doc->fight();
    patient->fight();
}

