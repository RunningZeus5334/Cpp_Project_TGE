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
    // speed changer for enemys
    int spawn_speed = 50;
    if( Static_game::instance().getGame()->score->getScore() >= 40){
        spawn_speed = 10;
    }
    else if( Static_game::instance().getGame()->score->getScore() >= 20){
        spawn_speed = 30;
    }
    else if( Static_game::instance().getGame()->score->getScore() >= 10){
        spawn_speed = 40;
    }

    //set random pos for enemy on X axis
    setPos(rand()%900,0);

    setPixmap(QPixmap(":/Textures/Invader.png"));

    QTimer * timer = new QTimer(); //to do: put as member and delete in destructor
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(spawn_speed);
}

void Enemy::move()
{
   // enemy wil go down
    setPos(x(),y()+5);
    if(pos().y()> 850)
    {
        scene()->removeItem(this);
        this->deleteLater();
        Static_game::instance().getGame()->health->decrease();
        //Uncheck Qdebug to see that enemys get deleted
        //qDebug("Deleted enemy");

    }
}

