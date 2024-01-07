#include "rectangle.h"
#include <QGraphicsscene>
#include <QKeyEvent>
#include <bullet.h>
#include <bullet2.h>
#include <bullet3.h>
#include "enemy.h"
#include "static_game.h"
#include "powerup.h"

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
    speed = 10 * Static_game::instance().getGame()->getpower();
    if (event->key()== Qt::Key_Left){
        if(pos().x() > 0)
        setPos(x()-speed,y());
    }
    else if(event->key()== Qt::Key_Right){
        if(pos().x() + 110 < 1000)
        setPos(x()+speed,y());
    }
    else if(event->key()== Qt::Key_Space){
        // create a bullte
        // make different bullets spawn here
        if(Static_game::instance().getGame()->getpower() > 4){
            Bullet3 * kogel = new Bullet3();
            kogel->setPos(x()+45,y()-30);
            scene()->addItem(kogel);
        }
        else if(Static_game::instance().getGame()->getpower() > 2){
            Bullet2 * kogel = new Bullet2();
            kogel->setPos(x()+45,y()-30);
            scene()->addItem(kogel);
        }
        else{
            Bullet * kogel = new Bullet();
            kogel->setPos(x()+45,y()-30);
            scene()->addItem(kogel);
        }
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

void Rectangle::spawn_powerup(){

    //spawn powerup
    Powerup * powerup = new Powerup();
    scene()->addItem(powerup);

}
