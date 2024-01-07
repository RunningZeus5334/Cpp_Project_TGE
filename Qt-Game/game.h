#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "rectangle.h"
#include "score.h"
#include "health.h"
#include "game_over.h"
#include <QAudioOutput>
#include <QMediaPlayer>

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=nullptr);  // <- nullpointer used

    QGraphicsScene * scene;
    Rectangle * Player1;
    Score * score;
    Health * health;
    QMediaPlayer * music;
    QAudioOutput * Speakers;
    Game_over * Dead;

    ~Game(){
        delete scene;
        delete Player1;
        delete score;
        delete health;
        delete music;
        delete Speakers;
        delete Dead;
        std::cout << "HALLLOO";
    }
};

#endif // GAME_H
