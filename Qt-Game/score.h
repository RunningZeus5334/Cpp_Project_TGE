#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>


class Score: public QGraphicsTextItem
{
public:
    Score();  // <- default constructer
    void inscrease();
    int getScore();
private:
    int score;
};

#endif // SCORE_H
