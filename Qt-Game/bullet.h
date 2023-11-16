#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>

class Bullet: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Bullet();
public slots:
    void move();
};

#endif // BULLET_H

//soorten bullets maken, gekleurde maybe of meer of minder
//dit mag een base class zijn voor mijn andere bullets.
