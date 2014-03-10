TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    src/Universe.h \
    src/Tile.h \
    src/Task.h \
    src/GameObject.h \
    src/Agent.h \
    src/Engine/Vector2D.h \
    src/Engine/TextureManager.h \
    src/Engine/TextManager.h \
    src/Engine/Sprite.h \
    src/Engine/GameState.h \
    src/Engine/Game.h \
    src/Engine/Drawable.h \
    src/Engine/Camera.h \
    src/Engine/Pathfinding/Pathing.h

SOURCES += \
    src/Universe.cpp \
    src/Tile.cpp \
    src/GameObject.cpp \
    src/Agent.cpp \
    src/Engine/Vector2D.cpp \
    src/Engine/TextureManager.cpp \
    src/Engine/TextManager.cpp \
    src/Engine/Sprite.cpp \
    src/Engine/GameState.cpp \
    src/Engine/Game_onUpdate.cpp \
    src/Engine/Game_onRender.cpp \
    src/Engine/Game_onInit.cpp \
    src/Engine/Game_onEvent.cpp \
    src/Engine/Game_onCleanup.cpp \
    src/Engine/Game_gameTime.cpp \
    src/Engine/Game.cpp \
    src/Engine/Drawable.cpp \
    src/Engine/Camera.cpp \
    src/Engine/Pathfinding/Pathing.cpp

unix|win32: LIBS += -lSDL2
unix|win32: LIBS += -lSDL2_image
unix|win32: LIBS += -lSDL2_ttf
