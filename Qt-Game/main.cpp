#include <QApplication>
#include "static_game.h"


 // need to make this static

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    Static_game::instance().getGame()->show();


    return a.exec();
}
//singleton design pattern for static game
// signal slots     --
// return types
// object composition



