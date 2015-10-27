#ifndef BALL_H
#define BALL_H

#include <QColor>
#include <QPainter>
const int screenX = 1000, screenY = 1000;

class Ball
{
    protected:
		int x,y;
		int vx, vy;
		int radius;
        QColor color, trans;
	public:
		Ball();
		int getX();
		int getY();
		int getRadius();
		QColor getColor();
		void reverseX();
		void reverseY();
		void move();
		void draw(QPainter* painter);
};

#endif // BALL_H
