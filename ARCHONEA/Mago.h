#pragma once
//Pido perdon necesito mis comentarios para saber que he hecho si no me pierdo
#pragma once
#include <windows.h>
#include <GL/gl.h>
#include "Pieza.h"

// Mago: nadie sabe como, ni el mismo pero siempre aprueba raspado como un don 
// tiene habilidades impredecibles, a veces falla y a veces arrasa-es el personaje mas misterioso del bando EE309
class Mago : public Pieza {
private:
    int suerte;  // factor de suerte, cambia aleatoriamente

public:
    // estadisticas medias en todo, nunca se sabe lo que va a hacer
    Mago(int fila, int columna)
        : Pieza(fila, columna, true, "Mago", 75, 3, 25) {
        suerte = rand() % 10;  // suerte aleatoria entre 0 y 9
    }

    // lo dibujamos como un cuadrado amarillo, como el aprobado raspado
    void dibujar(float x, float y) override {
        glColor3f(1.0f, 0.85f, 0.0f);  // amarillo = aprobado por los pelos
        glBegin(GL_QUADS);
        glVertex2f(x + 5, y + 5);
        glVertex2f(x + 55, y + 5);
        glVertex2f(x + 55, y + 55);
        glVertex2f(x + 5, y + 55);
        glEnd();
    }

    // se puede mover a cualquier casilla del tablero, nadie sabe como
    // es como teletransporte, aparece donde menos te esperas
    bool puedeMoverseA(int nuevaFila, int nuevaCol) override {
        return true;  // puede ir a cualquier sitio, es un mago
    }

    // regenera su suerte aleatoriamente cada turno
    void regenerarSuerte() { suerte = rand() % 10; }
    int getSuerte() { return suerte; }

    std::string getTipo() override { return "Mago"; }
};