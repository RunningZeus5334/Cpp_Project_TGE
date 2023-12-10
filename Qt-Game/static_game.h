#ifndef STATIC_GAME_H
#define STATIC_GAME_H

#include <QQmlEngine>
#include "game.h"

class Static_game : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

public:

    static Static_game *create(QQmlEngine *qmlEngine, QJSEngine *jsEngine)
    {
        Static_game *result = nullptr;
        // Create the object using some custom constructor or factory.
        // The QML engine will assume ownership and delete it, eventually.
        return result;
    }

    // members, Q_INVOKABLE functions, et
    // do i want my other classes here??

};

#endif // STATIC_GAME_H
