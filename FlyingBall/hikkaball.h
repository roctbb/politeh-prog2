#ifndef HIKKABALL_H
#define HIKKABALL_H

#include "ball.h"

class HikkaBall : public Ball
{
public:
    HikkaBall();
    void up();
    void left();
    void down();
    void right();
    void draw(QPainter * painter);

};

#endif // HIKKABALL_H
