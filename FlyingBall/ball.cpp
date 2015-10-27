#include "ball.h"
#include <QDebug>

Ball::Ball()
{
	x = rand()%screenX;
	y = rand()%screenY;
	radius = rand()%30;
	vx = rand()%5;
	if (rand()%2==1) reverseX();
	vy = rand()%5;
	if (rand()%2==1) reverseY();
    color = color.fromRgb(rand()%256, rand()%256, rand()%256);
    trans = trans.fromRgb(0, 0, 0, 0);

}

void Ball::draw(QPainter *painter) {
	qDebug() << color.name();
	painter->setBrush(QBrush(color));
    painter->setPen(trans);
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
	if (x >= screenX || x <= 0)
	{
        reverseX();
	}
	if (y >= screenY || y <= 0)
	{
        reverseY();
    }
	x+=vx;
	y+=vy;
}
