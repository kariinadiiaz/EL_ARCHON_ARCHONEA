#pragma once
#pragma once
#include "Pieza.h"

class Tablero {
private:
    Pieza* casillas[9][9];  // nullptr = casilla vacía
    int puntosPoder[5][2] = {
        {4, 4},  // centro
        {0, 4},  // borde superior
        {8, 4},  // borde inferior
        {4, 0},  // borde izquierdo
        {4, 8}   // borde derecho
    };

public:
    Tablero();
    ~Tablero();

    void colocarPieza(Pieza* p, int fila, int col);
    Pieza* getPieza(int fila, int col);
    void eliminarPieza(int fila, int col);
    bool esPuntoPoder(int fila, int col);
    bool esCasillaLibre(int fila, int col);
    void moverPieza(int filaOrigen, int colOrigen, int filaDestino, int colDestino);
};