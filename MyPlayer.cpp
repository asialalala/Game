#include "MyPlayer.h"
#include"Bullet.h"
#include<QKeyEvent>
#include<QDebug>
#include<QGraphicsScene>
#include<Enemy.h>
#include"Constants.h"
#include"BonusSpeed.h"
#include<QTimer>

void MyPlayer::keyPressEvent(QKeyEvent *event)
{
if(event->key() == Qt::Key_Left)
{
    if(pos().x() > 0)
        setPos(x()-PlayerMove,y());
}

else if(event->key() == Qt::Key_Right)
{
    if(pos().x() + PLAYER < WIDTH)
        setPos(x()+PlayerMove,y());
}
else if (event->key() == Qt::Key_Space)
    {
    //tworzenie pocisku
    Bullet *bullet = new Bullet();
    bullet->setPos(x(),y());
  //  qDebug() << "Pocisk stworzony.";
    scene()->addItem(bullet);

    //zalaczenie dzwieku
    if(bulletsound->state() == QMediaPlayer::PlayingState)
    {
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState)
    {
        bulletsound->play();
    }

}
}

MyPlayer::MyPlayer(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    // stworzenie dzwieku
     bulletsound = new QMediaPlayer();
     bulletsound->setMedia(QUrl("grc:/sounds/Disney-Kizo.mp3"));
     // narysowanie gracza
     setPixmap(QPixmap(":/images/sanah.jpg"));
     // ustawienie szybkosci
     PlayerMove = ConstantSpeed = PLAYER_MOVE;
     InfoBonus = false;
}

void MyPlayer::changeSpeed(int times)
{
    PlayerMove = times*PlayerMove;
    QTimer::singleShot(6000, this, &MyPlayer::setNormalSpeed); //zwiększa prędkość na 6000 milisekund
    changeInfoBonus();
    // może dorobisz tu kiedyś wyświetlacz czasu

}

void MyPlayer::setNormalSpeed()
{
    PlayerMove = ConstantSpeed;
    changeInfoBonus();
}


void MyPlayer::spawn()
{
 // tworzenie wroga
   // qDebug() << "wywolanie tworzenia wroga";
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

void MyPlayer::spawnBonus()
{
   // qDebug() << "wywolanie tworzenia bonusu";
    // tworzenie wroga
       BonusSpeed * bonus = new BonusSpeed();
       scene()->addItem(bonus);
}

int *MyPlayer::getPlayerMove()
{
    return &PlayerMove;
}

bool MyPlayer::getInfoBonus()
{
    return InfoBonus;
}

void MyPlayer::changeInfoBonus()
{
    if(InfoBonus == false)
        InfoBonus = true;
    else
        InfoBonus = false;
}
