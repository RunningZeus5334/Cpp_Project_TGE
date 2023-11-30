#include <QApplication>
#include "Game.h"


Game * game; // need to make this static

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    game = new Game();
    game->show();

    return a.exec();
}
//singleton design pattern for static game
// signal slots     --
// return types
// object composition



