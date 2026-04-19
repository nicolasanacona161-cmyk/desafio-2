#include "Jugador.h"

Jugador::Jugador() : nombre(nullptr), dorsal(0), statsPartida() { copiarNombre(""); }

Jugador::Jugador(const Jugador& otro) : nombre(nullptr), dorsal(otro.dorsal), statsPartida(otro.statsPartida) {
    copiarNombre(otro.nombre != nullptr ? otro.nombre : "");
}

Jugador& Jugador::operator=(const Jugador& otro) {
    if (this != &otro) {
        liberarNombre();
        copiarNombre(otro.nombre != nullptr ? otro.nombre : "");
        dorsal = otro.dorsal;
        statsPartida = otro.statsPartida;
    }
    return *this;
}

Jugador::~Jugador() { liberarNombre(); }

void Jugador::liberarNombre() {
    if (nombre != nullptr) {
        delete[] nombre;
        nombre = nullptr;
    }
}

void Jugador::copiarNombre(const char* origen) {
    int tam = 0;
    while (origen[tam] != '\0') {
        ++tam;
    }

    nombre = new char[tam + 1];
    for (int i = 0; i < tam; ++i) {
        nombre[i] = origen[i];
    }
    nombre[tam] = '\0';
}

void Jugador::configurar(const char* nombreJugador, int dorsalJugador) {
    liberarNombre();
    copiarNombre(nombreJugador != nullptr ? nombreJugador : "");
    dorsal = dorsalJugador;
}

const char* Jugador::getNombre() const { return (nombre != nullptr) ? nombre : ""; }

int Jugador::getDorsal() const { return dorsal; }

EstadisticaPartido& Jugador::getStatsPartida() { return statsPartida; }
