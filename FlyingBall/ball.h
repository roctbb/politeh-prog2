#ifndef BALL_H
#define BALL_H

#include <QColor>
#include <QPainter>

class Ball
{
private:
    int x,y;
    int vx, vy;
    int radius;
    QColor color;
public:
    Ball();
    int getX();
    int getY();
    int getRadius();
    void reverseX();
    void reverseY();
    void move();
    void draw(QPainter* painter);
};

#endif // BALL_H
