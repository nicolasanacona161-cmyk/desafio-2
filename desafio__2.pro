QT -= gui

TEMPLATE = lib
DEFINES += DESAFIO__2_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    desafio__2.cpp \
    equipo.cpp \
    jugador.cpp

HEADERS += \
    desafio__2_global.h \
    desafio__2.h \
    equipo.h \
    jugador.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
