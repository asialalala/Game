#ifndef FALLINGTHING_H
#define FALLINGTHING_H

#include<QObject>
#include <QGraphicsPixmapItem>

class FallingThing: public QObject, public QGraphicsPixmapItem {
public:
    FallingThing (QGraphicsItem *parent = 0);
public slots:
    virtual void move() = 0;

};

#endif // FALLINGTHING_H
