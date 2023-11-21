#include "enemy.h"
#include <QTimer>
#include <stdlib.h>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
//Uncheck Qdebug to see that enemys get deleted
//#include <QDebug>
extern Game * game;

Enemy::Enemy()
{
    //set random pos for enemy on X axis
    setPos(rand()%700,0);

    setRect(0,0,100,100);

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
   // enemy wil go down
    setPos(x(),y()+5);
    if(pos().y()- rect().height()> 580)
    {
        scene()->removeItem(this);
        delete this;
        game->health->decrease();
        //Uncheck Qdebug to see that enemys get deleted
        //qDebug("Deleted enemy");

    }
}
