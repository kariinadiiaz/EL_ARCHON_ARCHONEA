#pragma once
//Pido perdon necesito mis comentarios para saber que he hecho si no me pierdo
#pragma once
#include <windows.h>
#include <GL/gl.h>
#include "Pieza.h"

// Todo10: el alumno que saca 10 facil del EE309(Voto llamrlo DAVID)
// ataca a distancia lanzando apuntes y libros , es débil físicamente pero muy preciso desde lejos
class Todo10 : public Pieza {
private:
    int alcance;  // hasta cuántas casillas puede atacar a distancia

public:
    // poca vida pero buen ataque a distancia
    Todo10(int fila, int columna)
        : Pieza(fila, columna, true, "Todo10", 60, 4, 30) {
        alcance = 3;  // puede atacar hasta 3 casillas de distancia
    }

    // lo dibujamos de momento como un cuadrado verde claro
    void dibujar(float x, float y) override {
        glColor3f(0.0f, 0.8f, 0.2f);  // verde = alumno aplicado
        glBegin(GL_QUADS);
        glVertex2f(x + 5, y + 5);
        glVertex2f(x + 55, y + 5);
        glVertex2f(x + 55, y + 55);
        glVertex2f(x + 5, y + 55);
        glEnd();
    }

    // se mueve hasta 3 casillas en línea recta (no diagonal)
    bool puedeMoverseA(int nuevaFila, int nuevaCol) override {
        int difFila = abs(nuevaFila - fila);
        int difCol = abs(nuevaCol - columna);
        // solo horizontal o vertical, máximo 3 casillas
        return (difFila == 0 || difCol == 0) && (difFila + difCol) <= 3;
    }

    int getAlcance() { return alcance; }

    std::string getTipo() override { return "Todo10"; }
};