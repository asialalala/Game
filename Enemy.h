#ifndef ENEMY_H
#define ENEMY_H

#include<QObject>
#include <QGraphicsPixmapItem>
#include "FallingThing.h"
#include<QMediaPlayer>

class Enemy: public FallingThing {
    Q_OBJECT
public:
    Enemy(/*QGraphicsItem *parent = 0*/);

public slots:
    void move();

};

#endif // ENEMY_H
