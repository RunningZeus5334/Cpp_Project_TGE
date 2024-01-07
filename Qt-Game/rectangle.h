#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QAudioOutput>

class Rectangle: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Rectangle(QGraphicsItem * parent=nullptr);  // <- nullpointer used
    void keyPressEvent(QKeyEvent *event);
public slots:
    void spawn();
private:
    QMediaPlayer * pew;
    QAudioOutput * pewspeaker;
};

#endif // RECTANGLE_H

