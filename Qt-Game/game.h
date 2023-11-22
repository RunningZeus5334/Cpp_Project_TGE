#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "rectangle.h"
#include "score.h"
#include "health.h"
#include "Enemy.h"
#include <QAudioOutput>
#include <QMediaPlayer>

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Rectangle * Player1;
    Score * score;
    Health * health;
    QMediaPlayer * music;
    QAudioOutput * Speakers;

};

#endif // GAME_H
