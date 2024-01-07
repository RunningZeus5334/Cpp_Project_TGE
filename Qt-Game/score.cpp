#include "score.h"
#include <QFont>

Score::Score() : QGraphicsTextItem()
{
    score = 0;

    setPlainText("Score: " + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::inscrease()
{
    score++;
    setPlainText("Score: " + QString::number(score));
}

int Score::getScore()
{
    return score;
}
