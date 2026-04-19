#include "Equipo.h"

Equipo::Equipo()
    : nombre(nullptr), ranking(999), plantilla(nullptr), cantJugadores(0), capacidadPlantilla(0), stats() {}

Equipo::Equipo(const Equipo& otro) : nombre(nullptr), ranking(999), plantilla(nullptr), cantJugadores(0), capacidadPlantilla(0), stats() {
    copiarDesde(otro);
}

Equipo& Equipo::operator=(const Equipo& otro) {
    if (this != &otro) {
        liberarPlantilla();
        liberarNombre();
        copiarDesde(otro);
    }
    return *this;
}

Equipo::~Equipo() {
    liberarPlantilla();
    liberarNombre();
}

void Equipo::liberarNombre() {
    if (nombre != nullptr) {
        delete[] nombre;
        nombre = nullptr;
    }
}

void Equipo::liberarPlantilla() {
    if (plantilla != nullptr) {
        for (int i = 0; i < cantJugadores; ++i) {
            delete plantilla[i];
        }
        delete[] plantilla;
        plantilla = nullptr;
    }
    cantJugadores = 0;
    capacidadPlantilla = 0;
}

void Equipo::copiarDesde(const Equipo& otro) {
    ranking = otro.ranking;
    stats = otro.stats;

    if (otro.nombre != nullptr) {
        int tam = 0;
        while (otro.nombre[tam] != '\0') {
            ++tam;
        }
        nombre = new char[tam + 1];
        for (int i = 0; i < tam; ++i) {
            nombre[i] = otro.nombre[i];
        }
        nombre[tam] = '\0';
    } else {
        nombre = new char[1];
        nombre[0] = '\0';
    }

    capacidadPlantilla = otro.capacidadPlantilla;
    cantJugadores = otro.cantJugadores;
    if (capacidadPlantilla > 0) {
        plantilla = new Jugador*[capacidadPlantilla];
        for (int i = 0; i < cantJugadores; ++i) {
            plantilla[i] = new Jugador(*(otro.plantilla[i]));
        }
        for (int i = cantJugadores; i < capacidadPlantilla; ++i) {
            plantilla[i] = nullptr;
        }
    }
}

void Equipo::redimensionarPlantilla(int nuevaCapacidad) {
    if (nuevaCapacidad <= capacidadPlantilla) {
        return;
    }

    Jugador** nueva = new Jugador*[nuevaCapacidad];
    for (int i = 0; i < cantJugadores; ++i) {
        nueva[i] = plantilla[i];
    }
    for (int i = cantJugadores; i < nuevaCapacidad; ++i) {
        nueva[i] = nullptr;
    }

    delete[] plantilla;
    plantilla = nueva;
    capacidadPlantilla = nuevaCapacidad;
}

void Equipo::configurar(const std::string& nombreEquipo, int rankingEquipo, int cantidadJugadores) {
    configurar(nombreEquipo.c_str(), rankingEquipo, cantidadJugadores);
}

void Equipo::configurar(const char* nombreEquipo, int rankingEquipo, int cantidadJugadores) {
    liberarPlantilla();
    liberarNombre();

    int tam = 0;
    while (nombreEquipo[tam] != '\0') {
        ++tam;
    }
    nombre = new char[tam + 1];
    for (int i = 0; i < tam; ++i) {
        nombre[i] = nombreEquipo[i];
    }
    nombre[tam] = '\0';
    ranking = rankingEquipo;

    redimensionarPlantilla(cantidadJugadores);
    for (int i = 0; i < cantidadJugadores; ++i) {
        agregarJugador("nombre" + std::to_string(i + 1), i + 1);
    }
}

void Equipo::agregarJugador(const std::string& nombreJugador, int dorsal) {
    if (cantJugadores == capacidadPlantilla) {
        int nuevaCap = (capacidadPlantilla == 0) ? 4 : (capacidadPlantilla * 2);
        redimensionarPlantilla(nuevaCap);
    }

    plantilla[cantJugadores] = new Jugador();
    plantilla[cantJugadores]->configurar(nombreJugador.c_str(), dorsal);
    ++cantJugadores;
}

void Equipo::registrarResultado(int golesFavor, int golesContra) { stats.actualizarDatos(golesFavor, golesContra); }

void Equipo::resetDatosGrupo() { stats.resetGrupo(); }

const char* Equipo::getNombre() const { return (nombre != nullptr) ? nombre : ""; }

int Equipo::getRanking() const { return ranking; }

int Equipo::getPuntosGrupo() const { return stats.getPuntosGrupo(); }

int Equipo::getDiferenciaGoles() const { return stats.getDiferenciaGoles(); }

int Equipo::getGolesFavor() const { return stats.getGolesFavor(); }

int Equipo::getCantJugadores() const { return cantJugadores; }

Jugador* Equipo::getJugador(int idx) const {
    if (idx < 0 || idx >= cantJugadores) {
        return nullptr;
    }
    return plantilla[idx];
}

bool Equipo::operator>(const Equipo& otro) {
    if (getPuntosGrupo() != otro.getPuntosGrupo()) {
        return getPuntosGrupo() > otro.getPuntosGrupo();
    }
    if (getDiferenciaGoles() != otro.getDiferenciaGoles()) {
        return getDiferenciaGoles() > otro.getDiferenciaGoles();
    }
    if (getGolesFavor() != otro.getGolesFavor()) {
        return getGolesFavor() > otro.getGolesFavor();
    }
    return ranking < otro.ranking;
}

std::ostream& operator<<(std::ostream& os, const Equipo& e) {
    os << e.getNombre() << " (ranking FIFA: " << e.ranking << ")";
    return os;
}
