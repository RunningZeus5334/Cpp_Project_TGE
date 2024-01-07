#include "health.h"

#include <QFont>
#include "static_game.h"


Health::Health() : QGraphicsTextItem()
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
    Static_game::instance().getGame()->decrease_power();
    if(health <= 0)
    {

        Static_game::instance().getGame()->Dead->End_game();
    }
}

int Health::getHealth()
{
    return health;
}
