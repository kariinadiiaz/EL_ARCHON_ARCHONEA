// ARCHONEA.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#define USE_ETSIDI
#include "ETSIDI.h"
#include "GL/glut.h"

using namespace ETSIDI;

const int TAM_CASILLA = 60;
const int FILAS = 9;
const int COLS = 9;
const int MARGEN = 50;

void dibujarTablero() {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Alternar colores blanco y negro
            if ((i + j) % 2 == 0)
                glColor3f(1.0f, 1.0f, 1.0f); // blanco
            else
                glColor3f(0.0f, 0.0f, 0.0f); // negro

            float x = MARGEN + j * TAM_CASILLA;
            float y = MARGEN + i * TAM_CASILLA;

            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x + TAM_CASILLA, y);
            glVertex2f(x + TAM_CASILLA, y + TAM_CASILLA);
            glVertex2f(x, y + TAM_CASILLA);
            glEnd();
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    dibujarTablero();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, h, 0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(650, 650);
    glutCreateWindow("ARCHONEA");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}