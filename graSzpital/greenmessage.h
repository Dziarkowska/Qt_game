#ifndef GREENMESSAGE_H
#define GREENMESSAGE_H

#include <QObject>
#include <QGraphicsPixmapItem>

class GreenMessage :public QObject, public QGraphicsPixmapItem{
public:
    QString name;
    GreenMessage(QString n="");
    void setImage(int x, int y);
};

#endif // GREENMESSAGE_H
