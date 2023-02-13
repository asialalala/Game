#include"Score.h"
#include<QString>
#include<QFont>
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //inicjalizacja 0 punktow
    score = 0;
    //narysowanie tekstu
    setPlainText(QString("Punkty: ") + QString::number(score)); // Score = 0
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));
}

void Score::increase()
{
    ++score;
    setPlainText(QString("Punkty: ") + QString::number(score)); // Score ++

}

int Score::getScore()
{
    return score;
}


