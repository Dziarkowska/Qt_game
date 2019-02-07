#ifndef ROOM_H
#define ROOM_H

#include <QGraphicsRectItem>
#include <QString>


class Room :public QGraphicsRectItem{
public:
    Room(int x, int y, int width, int height, double opacity, QString newname);
    ~Room();
    QString name;
    QString getName();
    void setName(QString newName);
    virtual void accept()=0;
};
#endif // ROOM_H
