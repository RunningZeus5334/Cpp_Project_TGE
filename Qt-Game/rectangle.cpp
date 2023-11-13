#include "rectangle.h"
#include <QGraphicsscene>
#include <QKeyEvent>
#include <bullet.h>

void Rectangle::keyPressEvent(QKeyEvent *event)
{
    if (event->key()== Qt::Key_Left){
        setPos(x()-10,y());
    }
    else if(event->key()== Qt::Key_Right){
        setPos(x()+10,y());
    }
    else if(event->key()== Qt::Key_Up){
        setPos(x(),y()-10);
    }
    else if(event->key()== Qt::Key_Down){
        setPos(x(),y()+10);
    }
    else if(event->key()== Qt::Key_Space){
        // create a bullter
        Bullet * kogel = new Bullet();
        kogel->setPos(x(),y());
        scene()->addItem(kogel);
    }
}
