#ifndef EQUIPO_H
#define EQUIPO_H

#include <iostream>
#include <string>
#include "Jugador.h"
#include "EstadisticaHistorica.h"

class Equipo {
private:
    char* nombre;
    int ranking;
    Jugador** plantilla;
    int cantJugadores;
    int capacidadPlantilla;
    EstadisticaHistorica stats;

    void liberarNombre();
    void liberarPlantilla();
    void copiarDesde(const Equipo& otro);
    void redimensionarPlantilla(int nuevaCapacidad);

public:
    Equipo();
    Equipo(const Equipo& otro);
    Equipo& operator=(const Equipo& otro);
    ~Equipo();

    void configurar(const std::string& nombreEquipo, int rankingEquipo, int cantidadJugadores = 26);
    void configurar(const char* nombreEquipo, int rankingEquipo, int cantidadJugadores = 26);
    void agregarJugador(const std::string& nombreJugador, int dorsal);
    void registrarResultado(int golesFavor, int golesContra);
    void resetDatosGrupo();

    const char* getNombre() const;
    int getRanking() const;
    int getPuntosGrupo() const;
    int getDiferenciaGoles() const;
    int getGolesFavor() const;
    int getCantJugadores() const;
    Jugador* getJugador(int idx) const;

    bool operator>(const Equipo& otro);
    friend std::ostream& operator<<(std::ostream& os, const Equipo& e);
};

#endif // EQUIPO_H
