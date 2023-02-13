QT       += core gui \
        multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BonusSpeed.cpp \
    Bullet.cpp \
    End.cpp \
    Enemy.cpp \
    FallingThing.cpp \
    Game.cpp \
    Health.cpp \
    MyPlayer.cpp \
    Score.cpp \
    main.cpp

HEADERS += \
    BonusSpeed.h \
    Bullet.h \
    Constants.h \
    End.h \
    Enemy.h \
    FallingThing.h \
    Game.h \
    Health.h \
    MyPlayer.h \
    Score.h

FORMS += \
    End.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rsc.qrc
