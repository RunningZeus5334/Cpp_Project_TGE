#include <QApplication>
#include <QGraphicsScene>
#include <rectangle.h>
#include <QGraphicsView>
#include <iostream>



// Discclaimer the current code is from a tutorial.
int main(int argc, char *argv[])
{
    std::cout << "Hello" << std::endl;
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to put into the scene
    Rectangle * rect = new Rectangle();
    rect->setRect(0,0,100,100);

    // add the item to the scene
    scene->addItem(rect);

    //make item focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();


    // add a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    return a.exec();
}
