// ARCHONEA.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#define USE_ETSIDI
#include "ETSIDI.h"
#include <GL/glut.h>

using namespace ETSIDI;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Texto de prueba
    setFont("arial.ttf", 24);
    setTextColor(1, 1, 1);
    printxy("ARCHONEA - Bienvenido!", 300, 300);

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("ARCHONEA");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}