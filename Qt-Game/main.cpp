#include <QApplication>
#include <QGraphicsScene>
#include <rectangle.h>
#include <QGraphicsView>
#include <QTimer>
#include <iostream>



// Discclaimer the current code is from a tutorial.
int main(int argc, char *argv[])
{
    std::cout << "Hello" << std::endl;
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to put into the scene
    Rectangle * Player1 = new Rectangle();
    Player1->setRect(0,0,100,100);

    // add the item to the scene
    scene->addItem(Player1);

    //make item focusable
    Player1->setFlag(QGraphicsItem::ItemIsFocusable);
    Player1->setFocus();


    // add a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(800,600);
    view->setSceneRect(0,0,800,600);

    Player1->setPos(view->width()/2 - (Player1->rect().width()/2),view->height()-Player1->rect().height()-5);

    //Enemy spawn
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),Player1,SLOT(spawn()));

    timer->start(2000);

    return a.exec();
}
