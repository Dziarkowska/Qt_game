#ifndef DISPSTATISTICS_H
#define DISPSTATISTICS_H

#include <QGraphicsTextItem>
#include <QGraphicsRectItem>

class DispStats :public QGraphicsTextItem{
public:
    DispStats(QGraphicsItem* parent=0);
    QString names;
    int phps; //physicalhealthpoints
    int mhps; //mentalhealthpoints
    int strengths;
    int wisdoms;
    void updateStats();
};

#endif // DISPSTATISTICS_H
