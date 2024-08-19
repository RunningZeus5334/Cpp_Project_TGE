#ifndef BULLET_H
#define BULLET_H


#include <QGraphicsItem>
#include "base_object.h"


 class Bullet: public Base_Object
{
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent=nullptr); // <- nullpointer used

public slots:
    void move();
};

#endif // BULLET_H

//soorten bullets maken, gekleurde maybe of meer of minder
//dit mag een base class zijn voor mijn andere bullets.
