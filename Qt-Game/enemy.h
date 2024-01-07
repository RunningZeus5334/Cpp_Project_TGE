#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=nullptr);  // <- nullpointer used
public slots:
    void move();
};

#endif // ENEMY_H
