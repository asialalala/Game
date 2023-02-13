#include"Enemy.h"
#include<QDebug>
#include<QTimer>
#include<stdlib.h> // random_number
#include<QGraphicsScene>
#include"Constants.h"
#include"Game.h"

extern Game *game; //
Enemy::Enemy(/*QGraphicsItem *parent*/)//: QObject(), QGraphicsPixmapItem(parent)
{
    //ustawienie jakiejs pozycji
    int random_number = rand() % 700;
    setPos(random_number,0);
    // narysowanie wroga
    // setRect(0,0,PLAYER,PLAYER); To gdyby byłQGraphicsRectItem
    setPixmap(QPixmap(":/images/kizo.jpg"));
    //qDebug() << "Stworzono wroga";

    //połączenie ruchu
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(ENEMY_MOVE);


}

void Enemy::move()
{
    setPos(x(),y()+10);

    // gdy znikna ze sceny usun
    if(pos().y() > HEIGHT)
    {
        //odjecie życia
        game->gethealth()->decrease();
        game->getmusic()->pause();
       if(!game->getMusicInfo())
       {
           qDebug() << "przed załączeniem muzyki" << game->getMusicInfo();
           game->getmusicEnemy()->play();
           qDebug() << "ppo załączeniu muzyki" << game->getMusicInfo();
           game->changeMusicInfo();
           qDebug() << "po zmianie informacji" << game->getMusicInfo();
       }
        if(game->gethealth()->getHealth() <= 0)
        {
            game->timerStop();
            game->getsummary()->dashboard(game->getscore()->getScore()); //koniec tworzenia sie Kizo
        }
        scene()->removeItem(this);
        delete this;
        //qDebug() << "Usunieto wroga ze sceny.";
    }
}
