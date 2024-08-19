QT       += core gui
QT       += multimedia
QT       += qml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    base_object.cpp \
    bullet.cpp \
    bullet2.cpp \
    bullet3.cpp \
    enemy.cpp \
    game.cpp \
    game_over.cpp \
    health.cpp \
    main.cpp \
    powerup.cpp \
    rectangle.cpp \
    score.cpp \
    static_game.cpp

HEADERS += \
    base_object.h \
    bullet.h \
    bullet2.h \
    bullet3.h \
    enemy.h \
    game.h \
    game_over.h \
    health.h \
    powerup.h \
    rectangle.h \
    score.h \
    static_game.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
