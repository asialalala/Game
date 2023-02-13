#include"BonusSpeed.h"
#include"Constants.h"
#include"Game.h"
#include <QDebug>
#include<QTimer>
#include<stdlib.h>
#include<QGraphicsScene>

extern Game *game;
void BonusSpeed::changeSpeed()
{
    game->getmyplayer()->changeSpeed(times);
}

BonusSpeed::BonusSpeed()
{
    //ustawienie jakiejs pozycji
    int random_number = (rand()*180) % 700; // do położenia x wyświetlania się bonusu
    setPos(random_number,0);

    //narysowanie bonusu
    setPixmap(QPixmap(":/images/kwiatki.jpg"));
    //qDebug() << "Stworzono bonus";

    //połączenie ruchu
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(BONUS_MOVE);

    // o ile zwiekszyc szybkosc
    times = 2;
}

bool BonusSpeed::inside()
{
    int check = 0;
    if((pos().x() + PLAYER >= game->getmyplayer()->pos().x()) && (pos().x() + PLAYER <= game->getmyplayer()->pos().x() + PLAYER)
            || (pos().x() <= game->getmyplayer()->pos().x()) + PLAYER && (pos().x() >= game->getmyplayer()->pos().x()))
        check++;
    if(pos().y() > HEIGHT - PLAYER)
        check++;
    return check == 2? true : false;
}

void BonusSpeed::move()
{

    setPos(x(),y()+10); // porusza sie co 10

    if(inside() && !game->getmyplayer()->getInfoBonus())
    {
        //qDebug() << "wewnatrz";
        game->getmyplayer()->changeSpeed(3); //zwiększneie prędkości o trzy
    }

    // gdy znikna ze sceny usun
    if(pos().y() > HEIGHT)
    {
        scene()->removeItem(this);
        delete this;

        /////////////////// to trzeba zmienic ////////////////
        if(game->getmyplayer()->getInfoBonus() == true)
            game->getmyplayer()->changeInfoBonus();
        //qDebug() << "Usunieto bonus ze sceny.";
    }



}
