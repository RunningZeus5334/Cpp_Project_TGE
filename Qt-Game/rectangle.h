#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QGraphicsRectItem>

class Rectangle: public QGraphicsRectItem
{
public:
    void keyPressEvent(QKeyEvent *event);
};

#endif // RECTANGLE_H
