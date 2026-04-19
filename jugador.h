#ifndef JUGADOR_H
#define JUGADOR_H


class Jugador {
private:
    char* nombre;
    int dorsal;


    void liberarNombre();
    void copiarNombre(const char* origen);

public:
    Jugador();
    Jugador(const Jugador& otro);
    Jugador& operator=(const Jugador& otro);
    ~Jugador();

    void configurar(const char* nombreJugador, int dorsalJugador);
    const char* getNombre() const;
    int getDorsal() const;

};

#endif // JUGADOR_H
