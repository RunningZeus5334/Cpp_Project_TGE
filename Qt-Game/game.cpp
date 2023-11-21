#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>


Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // create the player
    Player1 = new Rectangle();
    Player1->setRect(0,0,100,100); // change the rect from 0x0 (default) to 100x100 pixels
    Player1->setPos(400,500); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    Player1->setFlag(QGraphicsItem::ItemIsFocusable);
    Player1->setFocus();
    // add the player to the scene
    scene->addItem(Player1);


    //create score
    score = new Score();
    scene->addItem(score);
    health = new Health();
    scene->addItem(health);


    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),Player1,SLOT(spawn()));
    timer->start(2000);

    // play music
    music = new QMediaPlayer();
    Speakers = new QAudioOutput();
    music->setAudioOutput(Speakers);

    //link to music https://www.youtube.com/watch?v=k872Q87ktb0
    //had to do some diggen cuz api changed for mediaplayer and needed other functions to call it.
    music->setSource(QUrl("qrc:Sounds/Action 8-bit Chiptune Background Music for Games Tunnels.mp3"));
    Speakers->setVolume(50);
    music->play();
    music->loops();

    show();
}
