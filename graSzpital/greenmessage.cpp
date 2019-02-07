#include "greenmessage.h"

GreenMessage::GreenMessage(QString n){
    name = n;
}

void GreenMessage::setImage(int x, int y){
    setPos(x,y);
    setPixmap(QPixmap(":/images/greenmessage.png"));
}
