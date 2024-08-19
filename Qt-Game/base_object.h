#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>


class Base_Object: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Base_Object(QObject *parent = nullptr) : QObject(parent) {}
public slots:
   virtual void move() = 0;
};

#endif // BASE_OBJECT_H
