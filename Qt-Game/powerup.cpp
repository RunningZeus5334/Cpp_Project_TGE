#include "powerup.h"
#include <QTimer>
#include <stdlib.h>
#include <QGraphicsScene>
#include <QList>
//#include "static_game.h"

Powerup::Powerup(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

    setPos(rand()%700,0);

    setPixmap(QPixmap(":/Textures/Star.png"));

    QTimer * timer3 = new QTimer(); //to do: put as member and delete in destructor
    connect(timer3,SIGNAL(timeout()),this,SLOT(move()));

    timer3->start(50);

}


void Powerup::move()
{
    // star wil go down
    setPos(x(),y()+5);
    if(pos().y()> 580)
    {
        scene()->removeItem(this);
        this->deleteLater();

    }
}
