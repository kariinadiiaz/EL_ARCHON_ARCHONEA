#pragma once
#include <windows.h>
#include <GL/gl.h>
#include "Pieza.h"

// Platero: el jefe del departamento de Automatica
// es el lider del bando de los profes, puede lanzar conjuros
// muy poderoso, suspende con una sola mirada
class Platero : public Pieza {
private:
    int conjuros;  // conjuros disponibles, uno por cada asignatura que imparte

public:
    // mucha vida y ataque alto, es el jefe por algo
    Platero(int fila, int columna)
        : Pieza(fila, columna, false, "Platero", 100, 3, 25) {
        conjuros = 7;
    }

    // lo dibujamos como un cuadrado rojo oscuro, color del bando profes
    void dibujar(float x, float y) {
        glColor3f(0.7f, 0.0f, 0.0f);  // rojo oscuro = autoridad maxima
        glBegin(GL_QUADS);
        glVertex2f(x + 5, y + 5);
        glVertex2f(x + 55, y + 5);
        glVertex2f(x + 55, y + 55);
        glVertex2f(x + 5, y + 55);
        glEnd();
    }

    // se mueve una casilla en cualquier direccion como el Delegado
    bool puedeMoverseA(int nuevaFila, int nuevaCol) {
        int difFila = abs(nuevaFila - fila);
        int difCol = abs(nuevaCol - columna);
        return difFila <= 1 && difCol <= 1;
    }

    // lanza un conjuro , por ejemplo suspender a alguien
    bool lanzarConjuro() {
        if (conjuros > 0) {
            conjuros--;
            return true;
        }
        return false;
    }

    int getConjuros() { return conjuros; }

    std::string getTipo() { return "Platero"; }
};