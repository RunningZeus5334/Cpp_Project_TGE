#ifndef BULLET2_H
#define BULLET2_H
#include "bullet.h"
#include "base_object.h"

class Bullet2: Base_Object{

    Q_OBJECT
public:
    Bullet2(QGraphicsItem * parent=nullptr); // <- nullpointer used
public slots:
    void move();
};

#endif // BULLET2_H
