#ifndef STATIC_GAME_H
#define STATIC_GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Game.h"
//#include "rectangle.h"
//#include "score.h"
//#include "health.h"
//#include "Enemy.h"
#include <QAudioOutput>
#include <QMediaPlayer>

class Static_game
{
private:
    Static_game() {game = new Game();}
    Static_game(const Static_game&) {}
    Static_game&  operator = (const Static_game&) {

        return *this;
    }
    Game * game;

    // In C++11, copy constructor and assignment operator could be deleted (= delete)

public:
    static Static_game & instance() {
        static Static_game *_instance = new Static_game();

        return *_instance;
    }

    Game *getGame() const;
};

#endif // STATIC_GAME_H
