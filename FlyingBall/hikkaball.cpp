#include "hikkaball.h"

HikkaBall::HikkaBall()
{
}

void HikkaBall::up() {
    y = y - 10;
}
void HikkaBall::down() {
    y = y + 10;
}
void HikkaBall::left() {
    x = x - 10;
}
void HikkaBall::right() {
    x = x + 10;
}
void HikkaBall::draw(QPainter* painter) {
    painter->setPen(trans);
    painter->setBrush(QBrush(Qt::green));
    painter->drawRect(x-radius, y-radius, 2*radius,2*radius);
    painter->setBrush(QBrush(color));

	painter->drawEllipse(x-radius, y-radius, 2*radius,2*radius);

}
