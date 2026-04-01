#pragma once
#pragma once
#include <string>

class Pieza {
protected:
    int fila;
    int columna;
    int vida;
    int vidaMax;
    int velocidad;
    int ataque;
    bool esBandoLuz;
    std::string nombre;

public:
    Pieza(int fila, int columna, bool esBandoLuz, std::string nombre,
        int vida, int velocidad, int ataque);

    virtual ~Pieza() {}

    // Métodos virtuales que cada pieza implementará a su manera
    virtual void dibujar(float x, float y) = 0;
    virtual bool puedeMoverseA(int nuevaFila, int nuevaCol) = 0;
    virtual std::string getTipo() = 0;

    // Getters
    int getFila() { return fila; }
    int getColumna() { return columna; }
    int getVida() { return vida; }
    bool getBando() { return esBandoLuz; }
    std::string getNombre() { return nombre; }
    bool estaViva() { return vida > 0; }

    // Setters
    void setPos(int f, int c) { fila = f; columna = c; }
    void recibirDanio(int danio) { vida -= danio; if (vida < 0) vida = 0; }
};