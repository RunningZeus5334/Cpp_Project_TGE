#include "rectangle.h"
#include <QGraphicsscene>
#include <QKeyEvent>
#include <bullet.h>
#include "enemy.h"
#include "static_game.h"

Rectangle::Rectangle(QGraphicsItem * parent) : QGraphicsPixmapItem(parent)
{
    pew = new QMediaPlayer();
    pewspeaker = new QAudioOutput();
    pew->setAudioOutput(pewspeaker);
    pew->setSource(QUrl("qrc:/Sounds/Pew Sound Effect.mp3"));

    setPixmap(QPixmap(":/Textures/Spaceship.png"));

}
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
        kogel->setPos(x()+45,y()-30);
        scene()->addItem(kogel);

        // play pew
        pew->play();
    }
    else if(event->key()== Qt::Key_Escape){
        Static_game::instance().getGame()->Dead->End_game();
    }
}

void Rectangle::spawn()
{
    //enemy creation
    Enemy * enemy1 = new Enemy();
    scene()->addItem(enemy1);
}

