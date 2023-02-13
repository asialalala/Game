#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include<QObject>
class Bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT // makro jest po to, zeby qt wiiedzial ze to jest obiekt, trzeba bylo to dodac bo dziedziczy z QObject
public:
    Bullet(QGraphicsItem *parent=0);
public slots:
    void move();
};

#endif // BULLET_H

// dla norrmalnych obiektów można zrobić QGraphicsItem, anie QGraphicsPixmapItem
