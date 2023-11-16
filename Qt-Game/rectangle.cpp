#include "rectangle.h"
#include <QGraphicsscene>
#include <QKeyEvent>
#include <bullet.h>
#include "enemy.h"
void Rectangle::keyPressEvent(QKeyEvent *event)
{
    if (event->key()== Qt::Key_Left){
        if(pos().x() > 0)
        setPos(x()-10,y());
    }
    else if(event->key()== Qt::Key_Right){
        if(pos().x() + 110 < 800)
        setPos(x()+10,y());
    }
    else if(event->key()== Qt::Key_Space){
        // create a bullter
        Bullet * kogel = new Bullet();
        kogel->setPos(x(),y());
        scene()->addItem(kogel);
    }
}

void Rectangle::spawn()
{
    //enemy creation
    Enemy * enemy1 = new Enemy();
    scene()->addItem(enemy1);
}
