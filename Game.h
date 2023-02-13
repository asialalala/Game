#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include"MyPlayer.h"
#include"Score.h"
#include"Health.h"
#include<QWidget>
#include"End.h"
#include<QMediaPlayer>
class Game{
public:
    Game();
    ~Game();
    void show();
    void timerStop();
    Score *getscore();
    End *getsummary();
    Health *gethealth();
    MyPlayer *getmyplayer();
    QMediaPlayer *getmusic();
    QMediaPlayer *getmusicEnemy();
    bool  getMusicInfo();
    void changeMusicInfo();
private:
     QGraphicsScene *scene;
     MyPlayer *player;
     QTimer * timerE;
     QTimer * timerB;
     Score *score;
     Health *health;
     End *summary;
     QMediaPlayer *music;   
     QMediaPlayer *musicEnemy;
     bool MusicInfo; //false = Sanah, true = Kizo

};

#endif // GAME_H
