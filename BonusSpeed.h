#ifndef BONUSSPEED_H
#define BONUSSPEED_H
#include"FallingThing.h"

class BonusSpeed: public FallingThing {
    Q_OBJECT
public:
    void changeSpeed();
    BonusSpeed();
    bool inside();
private:
    int times;
public slots:
    void move();
};
#endif //BONUSSPEED_H

