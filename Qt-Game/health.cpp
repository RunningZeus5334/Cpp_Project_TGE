#include "health.h"

#include <QFont>
#include "static_game.h"
#include "game_over.h"

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

        Static_game::instance().getGame()->close();
        // game closes when u lose. TODO:: gameover screen
    }
}

int Health::getHealth()
{
    return health;
}
