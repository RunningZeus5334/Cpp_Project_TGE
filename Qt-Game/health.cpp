#include "health.h"

#include <QFont>

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    health = 5;

    setPlainText("Health: " + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
    setPos(x(),y()+20);
}

void Health::decrease()
{
    health--;
    setPlainText("Health: " + QString::number(health));
}

int Health::getHealth()
{
    return health;
}
