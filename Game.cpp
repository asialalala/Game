#include<Game.h>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <MyPlayer.h>
#include<QTimer>
#include"Constants.h"
#include<QBrush>
#include<QDebug>
#include<QImage>

Game::Game()
{
    // Tworzenie sceny
    scene = new QGraphicsScene;
    // Tworzenie obiektu
    player = new MyPlayer();
    // player->setRect(0,0,PLAYER,PLAYER);  gdyby to był QGraphicsRecItem //okresla pozycje i wielkość obiektu
    //dodawnie obiektów do sceny
    scene->addItem(player);
    // zalaczneie funkcjonowania obeiktu - skupienie sie na tym obiekcie
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();


    // rozpoczecie funkcjonowania wrogów, powstaja co 2000 setnych
    timerE = new QTimer();
    QObject::connect(timerE,SIGNAL(timeout()),player,SLOT(spawn()));
    timerE->start(ENEMIES_CREATING);

    // tworzenie bonusow i umiejscowianie ich na scenie
    timerB = new QTimer();
    QObject::connect(timerB,SIGNAL(timeout()),player,SLOT(spawnBonus()));
    timerB->start(BONUS_CREATING);

    //Stworzenie punktacji
    score = new Score();
    scene->addItem(score);
    scene->setBackgroundBrush(QBrush(QImage(":/images/scena.jpg")));

    //stworzenie życia
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    // załączenie muzyki
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/Ale-Jazz.mp3"));
    music->play();

    // stworzenie podsumowania
    summary = new End();

    // zainicjowanie muzyki wroga
    musicEnemy = new QMediaPlayer();
    musicEnemy->setMedia(QUrl("qrc:/sounds/Disney-Kizo.mp3"));


    MusicInfo = false;

}

Game::~Game()
{
    delete score;
    delete health;
    delete summary;
    delete scene;
    delete player;
    delete music;
    delete musicEnemy;
}

void Game::show()
{
    // dodawnie widocznosci
    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show(); //to pokazuje
    view->setFixedSize(WIDTH,HEIGHT); //ustawia wielkość otweiranego okna
    scene->setSceneRect(0,0,WIDTH,HEIGHT); //zeby scena i widok mialy taka sama wielkosc
    player->setPos(view->width()/2,view->height() - player->boundingRect().height());
}

void Game::timerStop()
{
    timerE->stop();
    timerB->stop();
}

Score *Game::getscore()
{
    return score;
}

End *Game::getsummary()
{
    return summary;
}

Health *Game::gethealth()
{
    return health;
}

MyPlayer *Game::getmyplayer()
{
    return player;
}

QMediaPlayer *Game::getmusic()
{
    return music;
}

QMediaPlayer *Game::getmusicEnemy()
{
    return musicEnemy;
}

bool Game::getMusicInfo()
{
    return MusicInfo;
}

void Game::changeMusicInfo()
{
    if(MusicInfo == false)
        MusicInfo = true;
    else
        MusicInfo = false;
}

