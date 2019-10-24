# Entry point for user
HEADERS += \
    game.h \
    game_view.h \
    player.h \
    player_shape.h \
    game_resources.h

SOURCES += main.cpp \
    game.cpp \
    game_view.cpp \
    player.cpp \
    player_shape.cpp \
    game_resources.cpp

CONFIG += c++17
QMAKE_CXXFLAGS += -std=c++17
CONFIG += resources_big

# High warning levels
# SFML goes bad with -Weffc++
QMAKE_CXXFLAGS += -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic

# A warning is an error
QMAKE_CXXFLAGS += -Werror

# Debug and release settings
CONFIG += debug_and_release
CONFIG(release, debug|release) {
  DEFINES += NDEBUG
}

# Qt5
QT += core gui

# SFML, default compiling
# GNU/Linux
unix:!macx {
  LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
}

win32{
  INCLUDEPATH += C:/Qt/sfml/include
  LIBS += -LC:/Qt/sfml/lib
  LIBS += -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
  LIBS += -lopenal32              #Dependency
  LIBS += -lfreetype              #Dependency
  LIBS += -lopengl32              #Dependency
  LIBS += -lgdi32                 #Dependency
  LIBS += -lwinmm                 #Dependency
}

RESOURCES += \
    game_resources.qrc