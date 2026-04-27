#pragma once
#include <windows.h>
#include <GL/gl.h>
#include "Pieza.h"

// OscarC: profe del departamento de Automatica
// es rapido y agil pero no aguanta mucho castigo
// el tipico profe que va a mil pero si le das bien lo tumbas
class OscarC : public Pieza {
private:
    int velocidadExtra;  // bonus de velocidad porque siempre va corriendo

public:
    // poca vida pero muy rapido, ataque basico
    OscarC(int fila, int columna)
        : Pieza(fila, columna, false, "OscarC", 55, 5, 18) {
        velocidadExtra = 2;  // se mueve mas rapido que los demas profes
    }

    // lo dibujamos como un cuadrado naranja oscuro
    void dibujar(float x, float y)  {
        glColor3f(0.8f, 0.3f, 0.0f);  // naranja oscuro = profe rapido
        glBegin(GL_QUADS);
        glVertex2f(x + 5, y + 5);
        glVertex2f(x + 55, y + 5);
        glVertex2f(x + 55, y + 55);
        glVertex2f(x + 5, y + 55);
        glEnd();
    }

    // se mueve hasta 4 casillas en cualquier direccion, es el mas rapido
    bool puedeMoverseA(int nuevaFila, int nuevaCol) {
        int difFila = abs(nuevaFila - fila);
        int difCol = abs(nuevaCol - columna);
        return difFila <= 4 && difCol <= 4;
    }

    int getVelocidadExtra() { return velocidadExtra; }

    std::string getTipo() { return "OscarC"; }
};