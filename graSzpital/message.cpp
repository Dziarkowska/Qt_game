#include "message.h"
#include  <QFont>

Message::Message(QGraphicsItem *parent) :QGraphicsTextItem(parent){
    setPlainText(message("wstep.txt"));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",12));
    setPos(1000,200);
}

void Message::printMessage(QString newfilename){
    setPos(1000,300);
    setPlainText(message(newfilename));

}
