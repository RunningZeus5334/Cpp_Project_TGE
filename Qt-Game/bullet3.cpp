#include "bullet3.h"
#include <QTimer>
#include <QGraphicsScene>
#include <qlist.h>
#include "enemy.h"
#include "powerup.h"
#include "static_game.h"
//#include "score.h"
// Uncheck Qdebug if u want to see that bullets get deleted
//#include <Qdebug>

Bullet3::Bullet3(QGraphicsItem *parent)
{
    // set image for bullet
    setPixmap(QPixmap(":/Textures/among.png"));
    if (scene() != nullptr) {  // Ensure the scene is not null
        scene()->addItem(this);
    }
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}



void Bullet3::move()
{
    setPos(x() + 45, y() - 30);
    //when collision with enemy
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n ; i++ )
    {
        if(typeid(*(colliding_items[i]))==typeid(Enemy))
        {
            Static_game::instance().getGame()->score->inscrease();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete colliding_items[i];
            this->deleteLater();

            return;
        }

        if(typeid(*(colliding_items[i]))==typeid(Powerup))
        {
            Static_game::instance().getGame()->increase_power(); // <- makes game crash for some reason

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            this->deleteLater();
            return;
        }

    }
    //Bullet goes up
    setPos(x(),y()-10);
    if(pos().y() < 0)
    {

        scene()->removeItem(this);
        this->deleteLater();

        // Uncheck Qdebug if u want to see that bullets get deleted
        //qDebug("Deleted Bullet");
    }
}

