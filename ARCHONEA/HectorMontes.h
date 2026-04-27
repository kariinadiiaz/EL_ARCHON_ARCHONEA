#pragma once
#include <windows.h>
#include <GL/gl.h>
#include "Pieza.h"

// HectorM: el profe investigador del departamento
// ataca a distancia lanzando papers cientificos
// si te da uno de sus papers te quedas K.O. de aburrimiento
class HectorM : public Pieza {
private:
    int papersLanzados;  // cuantos papers ha lanzado ya

public:
    // buen ataque a distancia pero vida media
    HectorM(int fila, int columna)
        : Pieza(fila, columna, false, "HectorMontes", 65, 3, 35) {
        papersLanzados = 0;
    }

    // lo dibujamos como un cuadrado azul oscuro
    void dibujar(float x, float y) {
        glColor3f(0.0f, 0.0f, 0.6f);  // azul oscuro = investigador serio
        glBegin(GL_QUADS);
        glVertex2f(x + 5, y + 5);
        glVertex2f(x + 55, y + 5);
        glVertex2f(x + 55, y + 55);
        glVertex2f(x + 5, y + 55);
        glEnd();
    }

    // se mueve en linea recta como un arquero, lanza papers a distancia
    bool puedeMoverseA(int nuevaFila, int nuevaCol) {
        int difFila = abs(nuevaFila - fila);
        int difCol = abs(nuevaCol - columna);
        return (difFila == 0 || difCol == 0) && (difFila + difCol) <= 4;
    }

    void lanzarPaper() { papersLanzados++; }
    int getPapersLanzados() { return papersLanzados; }

    std::string getTipo() { return "HectorMontes"; }
};