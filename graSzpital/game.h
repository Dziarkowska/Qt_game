#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include "dispstatistics.h"
#include "position.h"
#include "message.h"
#include "guard.h"
#include "doctor.h"
#include "dog.h"
#include "cat.h"
#include "kitchen.h"
#include "person.h"
#include "patient.h"
#include "dispstatistics.h"
#include "room.h"
#include "animal.h"
#include "greenmessage.h"
#include "wall.h"


class Game :public QGraphicsView{
public:
    QGraphicsScene *scene;
    //Map *map;
    Game(QGraphicsWidget* parent=NULL);
    void start(Guard* g, Doctor *doc, Dog* d, Cat* c, Kitchen* k);
    void fight(Guard* g);
    void fight(Doctor* doc);
    QTimer *timer;
    DispStats* stats;
    Position* cur_pos;
    Message* message;

};
#endif // GAME_H

