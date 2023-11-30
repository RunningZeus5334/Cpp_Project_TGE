#include "health.h"

#include <QFont>
#include "game.h"
extern Game * game;
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
    if(health <= 0)
    {
        game->close();
        // game closes when u lose. TODO:: gameover screen
    }
}

int Health::getHealth()
{
    return health;
}
