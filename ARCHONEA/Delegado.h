#pragma once
//Pido perdon necesito mis comentarios para saber que he hecho si no me pierdo y no me encuentro
#include <windows.h>
#include <GL/gl.h>
#include "Pieza.h"
// Delegado: es el lider de los alumnos del EE309
// puede lanzar conjuros y es bastante resistente aguanta charlas de los profes y de los alumnos 
class Delegado : public Pieza {
private:
    int conjuros;  // conjuros que le quedan, empieza con 7

public:
    // le ponemos vida 100, velocidad 3 y ataque 20
    Delegado(int fila, int columna)
        : Pieza(fila, columna, true, "Delegado", 100, 3, 20) {
        conjuros = 7;
    }

    // de momento lo dibujamos como un cuadrado azul
    // luego pondremos sprites de verdad
    void dibujar(float x, float y) override {
        glColor3f(0.0f, 0.4f, 1.0f);
        glBegin(GL_QUADS);
        glVertex2f(x + 5, y + 5);
        glVertex2f(x + 55, y + 5);
        glVertex2f(x + 55, y + 55);
        glVertex2f(x + 5, y + 55);
        glEnd();
    }

    // se mueve una casilla en cualquier direccion como el rey del ajedrez
    bool puedeMoverseA(int nuevaFila, int nuevaCol) override {
        int difFila = abs(nuevaFila - fila);
        int difCol = abs(nuevaCol - columna);
        return difFila <= 1 && difCol <= 1;
    }

    // lanza un conjuro si le quedan
    bool lanzarConjuro() {
        if (conjuros > 0) {
            conjuros--;
            return true;
        }
        return false;
    }

    std::string getTipo() override { return "Delegado"; }
};
