#include "enemy.h"
#include <QTimer>
#include <stdlib.h>
#include <QGraphicsScene>
#include <QList>
#include "static_game.h"
//Uncheck Qdebug to see that enemys get deleted
//#include <QDebug>


Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //set random pos for enemy on X axis
    setPos(rand()%700,0);

    setPixmap(QPixmap(":/Textures/Invader.png"));

    QTimer * timer = new QTimer(); //to do: put as member and delete in destructor
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
   // enemy wil go down
    setPos(x(),y()+5);
    if(pos().y()> 580)
    {
        scene()->removeItem(this);
        this->deleteLater();
        Static_game::instance().getGame()->health->decrease();
        //Uncheck Qdebug to see that enemys get deleted
        //qDebug("Deleted enemy");

    }
}

