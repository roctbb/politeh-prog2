#include "ball.h"

Ball::Ball()
{
    x = rand()%500;
    y = rand()%500;
    radius = rand()%20;
    vx = rand()%10;
    if (rand()%2==1) reverseX();
    vy = rand()%10;
    if (rand()%2==1) reverseY();
    color.fromRgb(rand()%256, rand()%256, rand()%256);

}

void Ball::draw(QPainter *painter) {
    painter->setBrush(QBrush(color));
    painter->drawEllipse(x-radius, y-radius, 2*radius,2*radius);
}

int Ball::getX() {
    return x;
}
int Ball::getY() {
    return y;
}
int Ball::getRadius() {
    return radius;
}
void Ball::reverseX() {
    vx=-vx;
}
void Ball::reverseY() {
    vy=-vy;
}
void Ball::move() {
    x+=vx;
    y+=vy;
}


