#pragma once
//Pido perdon necesito mis comentarios para saber que he hecho si no me pierdo
#pragma once
#include <windows.h>
#include <GL/gl.h>
#include "Pieza.h"

//Nocturno: el alumno que estudia de noche y duerme en clase(voto llamarle ADRIAN)
// es muy resistente porque está acostumbrado al sufrimiento-ataque medio pero aguanta mucho castigo
class Nocturno : public Pieza {
private:
    bool modoNoche;  // si es de noche tiene bonus de ataque

public:
    // mucha vida, velocidad baja, ataque medio
    Nocturno(int fila, int columna)
        : Pieza(fila, columna, true, "Nocturno", 90, 2, 25) {
        modoNoche = false;
    }

    // lo dibujamos como un cuadrado morado oscuro
    void dibujar(float x, float y) override {
        glColor3f(0.3f, 0.0f, 0.5f);  // morado oscuro = nocturnidad
        glBegin(GL_QUADS);
        glVertex2f(x + 5, y + 5);
        glVertex2f(x + 55, y + 5);
        glVertex2f(x + 55, y + 55);
        glVertex2f(x + 5, y + 55);
        glEnd();
    }

    // se mueve hasta 2 casillas en cualquier direccion
    bool puedeMoverseA(int nuevaFila, int nuevaCol) override {
        int difFila = abs(nuevaFila - fila);
        int difCol = abs(nuevaCol - columna);
        return difFila <= 2 && difCol <= 2;
    }

    // activa el modo noche para tener bonus de ataque
    void activarModoNoche() { modoNoche = true; }
    bool getModoNoche() { return modoNoche; }

    std::string getTipo() override { return "Nocturno"; }
};