#include <QApplication>
#include "static_game.h"




int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    Static_game::instance().getGame()->show();


    return a.exec();
}

