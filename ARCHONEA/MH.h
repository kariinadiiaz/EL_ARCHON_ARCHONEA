#pragma once
#include <windows.h>
#include <GL/gl.h>
#include "Pieza.h"

// MH: el profe mas duro del departamento de Automatica
// es lento para que entiendas bien pero le vas a ver mas de un año entonces tiene mucha vida, casi imposible de eliminar
// si te toca en el examen... suerte
class MH : public Pieza {
private:
    int nivelDificultad;  // lo dificil que es su asignatura, del 1 al 10

public:
    // muchisima vida, velocidad minima pero ataque brutal
    MH(int fila, int columna)
        : Pieza(fila, columna, false, "MH", 150, 1, 40) {
        nivelDificultad = 10;  // maximo nivel de dificultad, como sus examenes
    }

    // color gris oscuro de tension , como el ambiente de sus examenes
    void dibujar(float x, float y) override {
        glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(x + 5, y + 5);
        glVertex2f(x + 55, y + 5);
        glVertex2f(x + 55, y + 55);
        glVertex2f(x + 5, y + 55);
        glEnd();
    }

    // se mueve solo una casilla, es muy lento pero nadie lo para
    bool puedeMoverseA(int nuevaFila, int nuevaCol) override {
        int difFila = abs(nuevaFila - fila);
        int difCol = abs(nuevaCol - columna);
        return difFila <= 1 && difCol <= 1;
    }

    int getNivelDificultad() { return nivelDificultad; }

    std::string getTipo() override { return "MH"; }
};