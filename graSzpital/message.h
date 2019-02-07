#ifndef MESSAGE_H
#define MESSAGE_H

#include <QGraphicsTextItem>
#include "readfile.h"

class Message :public QGraphicsTextItem, public ReadFile{
public:
    Message(QGraphicsItem* parent=0);
    void printMessage(QString newfilename);
};

#endif // MESSAGE_H
