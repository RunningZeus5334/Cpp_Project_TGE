#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <qlist.h>
#include "enemy.h"
#include "game.h"
//#include "score.h"
// Uncheck Qdebug if u want to see that bullets get deleted
//#include <Qdebug>
extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // set image for bullet
    setPixmap(QPixmap(":/Textures/Bullet.png"));

   QTimer * timer = new QTimer();
   connect(timer,SIGNAL(timeout()),this,SLOT(move()));

   timer->start(50);
}

void Bullet::move()
{
   //when collision with enemy
   QList<QGraphicsItem *> colliding_items = collidingItems();
   for(int i = 0, n = colliding_items.size(); i < n ; i++ )
   {
       if(typeid(*(colliding_items[i]))==typeid(Enemy))
       {
           game->score->inscrease();
           scene()->removeItem(colliding_items[i]);
           scene()->removeItem(this);

           delete colliding_items[i];
           delete this;  //fix with delete later

           return;
       }

   }
    //Bullet goes up
    setPos(x(),y()-10);
   if(pos().y() < 0)
    {
       scene()->removeItem(this);
       delete this;

       // Uncheck Qdebug if u want to see that bullets get deleted
       //qDebug("Deleted Bullet");
    }
}

