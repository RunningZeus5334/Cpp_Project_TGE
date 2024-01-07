#ifndef POWERUP_H
#define POWERUP_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Powerup : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Powerup(QGraphicsItem *parent = nullptr); // <- nullpointer used

public slots:
    void move();

};

#endif // POWERUP_H
