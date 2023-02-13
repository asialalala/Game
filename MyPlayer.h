#ifndef MYPLAYER_H
#define MYPLAYER_H
#include <QGraphicsPixmapItem>
#include<QObject>
#include<QMediaPlayer>
class MyPlayer: public QObject, public QGraphicsPixmapItem{
        Q_OBJECT
public:
    void keyPressEvent(QKeyEvent * event);
    MyPlayer(QGraphicsItem *parent=0);
    void changeSpeed(int times);
    int *getPlayerMove();
    bool getInfoBonus();
    void changeInfoBonus();
public slots:
    void spawn();
    void spawnBonus();
    void setNormalSpeed();
private:
    QMediaPlayer *bulletsound;
    int PlayerMove;
    bool InfoBonus;
    int ConstantSpeed;
};

#endif // MYPLAYER_H

