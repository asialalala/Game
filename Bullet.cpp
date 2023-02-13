#include"Bullet.h"
#include"Game.h"
#include <QTimer>
#include<QGraphicsScene>
#include<QDebug>
#include<QList>
#include<Enemy.h>
#include"Constants.h"

extern Game *game; //
Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // narysowanie pocisku
   /// setRect(0,0,BULLET_W,BULLET_H); to gdyby był QGraphicsRecItem
   setPixmap(QPixmap(":/images/nuta.jpg"));
    this->update(x(),y(),5,5);

    // polaczenie
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(BULLET_MOVE);
}

void Bullet::move()
{
    // sprawdzneie zderzenia z wrogiem
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0, n = colliding_items.size(); i < n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            //zmiana muzyki
            if(game->getMusicInfo() == true)
            {
                game->getmusicEnemy()->pause();
                game->getmusic()->play();
                game->changeMusicInfo();
            }
            //zwieszenie punktacji
            game->getscore()->increase();
            // usuniecie pocisku i wroga
            scene()->removeItem(colliding_items[i]);
          //  qDebug() << "Usunieto wroga.";
            scene()->removeItem(this);
           // qDebug() << "Usunieto pocisk.";
            delete colliding_items[i];
            delete this;
            return; // zeby dwa razy nie czyscic pamieci
        }
    }
    // poruszenie pocisku do gory
    setPos(x(),y()-BULLET_W);
    if(pos().y() + boundingRect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
       // qDebug() << "Usunieto przycisk.";
    }
}

