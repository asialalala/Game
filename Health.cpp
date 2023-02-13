#include"Health.h"
#include"QFont"

Health::Health(QGraphicsTextItem *parent): QGraphicsTextItem(parent)
{
    //inicjalizacja 0 życia
    health = 15;
    //narysowanie tekstu
    setPlainText(QString("Życie: ") + QString::number(health)); // health = 15
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));
}

void Health::decrease()
{
    --health;
    setPlainText(QString("Życie: ") + QString::number(health)); // health = 0
}

int Health::getHealth()
{
    return health;
}

