#ifndef BULLET2_H
#define BULLET2_H
#include "bullet.h"

class Bullet2: public Bullet{


public:
    Bullet2(QGraphicsItem * parent=nullptr); // <- nullpointer used
public slots:
    void move();
};

#endif // BULLET2_H
