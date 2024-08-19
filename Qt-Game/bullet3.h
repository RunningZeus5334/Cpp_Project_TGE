#ifndef BULLET3_H
#define BULLET3_H
#include "base_object.h"
#include "bullet.h"

class Bullet3: Base_Object
{
    Q_OBJECT
public:
    Bullet3(QGraphicsItem * parent=nullptr);
public slots:
    void move();
};

#endif // BULLET3_H
