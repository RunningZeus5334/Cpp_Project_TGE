#ifndef BULLET3_H
#define BULLET3_H
#include "bullet.h"

class Bullet3: public Bullet
{
public:
    Bullet3(QGraphicsItem * parent=nullptr);
public slots:
    void move();
};

#endif // BULLET3_H
