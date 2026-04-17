#pragma once
//Pido perdon necesito mis comentarios para saber que he hecho si no me pierdo
#pragma once
#include <windows.h>
#include <GL/gl.h>
#include "Pieza.h"

//Veterano: lleva mas años en la uni que algunos profes
//esta mas en los clubs por eso repite curso pero conoce el campus mejor que nadie es muy resistente porque ha sobrevivido a todo
class Veterano : public Pieza {
private:
    int aniosEnLaUni;  // cuantos años lleva en la carrera

public:
    // mucha vida porque lleva años aguantando examenes
    // velocidad media, conoce bien el terreno
    Veterano(int fila, int columna)
        : Pieza(fila, columna, true, "Veterano", 85, 3, 22) {
        aniosEnLaUni = 6;  // lleva 6 años, deberia llevar 4
    }

    // lo dibujamos como un cuadrado naranja, como el suspenso que arrastra
    void dibujar(float x, float y) override {
        glColor3f(1.0f, 0.5f, 0.0f);  // naranja = demasiados años aqui
        glBegin(GL_QUADS);
        glVertex2f(x + 5, y + 5);
        glVertex2f(x + 55, y + 5);
        glVertex2f(x + 55, y + 55);
        glVertex2f(x + 5, y + 55);
        glEnd();
    }

    // se mueve hasta 3 casillas, conoce bien el tablero
    bool puedeMoverseA(int nuevaFila, int nuevaCol) override {
        int difFila = abs(nuevaFila - fila);
        int difCol = abs(nuevaCol - columna);
        return difFila <= 3 && difCol <= 3;
    }

    int getAnios() { return aniosEnLaUni; }

    std::string getTipo() override { return "Veterano"; }
};