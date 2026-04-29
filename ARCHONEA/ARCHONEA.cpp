#define USE_ETSIDI
#include "ETSIDI.h"
#include "GL/glut.h"

using namespace ETSIDI;

const int TAM_CASILLA = 60;
const int FILAS = 9;
const int COLS = 9;
const int MARGEN = 50;

int tiempoOscilacion = 0;
bool faseClaraOscura = true;

bool casillaOscila[9][9] = {
    {0,0,0,1,1,1,0,0,0},
    {0,0,1,0,1,0,1,0,0},
    {0,1,0,0,1,0,0,1,0},
    {1,0,0,0,1,0,0,0,1},
    {0,1,1,1,1,1,1,1,0},
    {1,0,0,0,1,0,0,0,1},
    {0,1,0,0,1,0,0,1,0},
    {0,0,1,0,1,0,1,0,0},
    {0,0,0,1,1,1,0,0,0}
};

bool esPuntoPoder(int fila, int col) {
    if (fila == 4 && col == 4) return true;
    if (fila == 0 && col == 4) return true;
    if (fila == 8 && col == 4) return true;
    if (fila == 4 && col == 0) return true;
    if (fila == 4 && col == 8) return true;
    return false;
}

void dibujarCruz(float x, float y) {
    glColor3f(1.0f, 0.8f, 0.0f);
    float cx = x + TAM_CASILLA / 2;
    float cy = y + TAM_CASILLA / 2;
    float tam = 15.0f;

    glBegin(GL_QUADS);
    glVertex2f(cx - tam, cy - 4);
    glVertex2f(cx + tam, cy - 4);
    glVertex2f(cx + tam, cy + 4);
    glVertex2f(cx - tam, cy + 4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(cx - 4, cy - tam);
    glVertex2f(cx + 4, cy - tam);
    glVertex2f(cx + 4, cy + tam);
    glVertex2f(cx - 4, cy + tam);
    glEnd();
}

void dibujarTablero() {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            float x = MARGEN + j * TAM_CASILLA;
            float y = MARGEN + i * TAM_CASILLA;

            bool esCasillaClara = (i + j) % 2 == 0;

            if (casillaOscila[i][j]) {
                if (faseClaraOscura) {
                    if (esCasillaClara)
                        glColor3f(0.5f, 0.5f, 1.0f);
                    else
                        glColor3f(0.3f, 0.3f, 0.8f);
                }
                else {
                    if (esCasillaClara)
                        glColor3f(0.2f, 0.2f, 0.7f);
                    else
                        glColor3f(0.1f, 0.1f, 0.5f);
                }
            }
            else {
                if (esCasillaClara)
                    glColor3f(1.0f, 1.0f, 1.0f);
                else
                    glColor3f(0.0f, 0.0f, 0.0f);
            }

            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x + TAM_CASILLA, y);
            glVertex2f(x + TAM_CASILLA, y + TAM_CASILLA);
            glVertex2f(x, y + TAM_CASILLA);
            glEnd();

            if (esPuntoPoder(i, j))
                dibujarCruz(x, y);
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

void timer(int value) {
    tiempoOscilacion++;
    if (tiempoOscilacion >= 50) {
        tiempoOscilacion = 0;
        faseClaraOscura = !faseClaraOscura;
    }
    glutPostRedisplay();
    glutTimerFunc(100, timer, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(650, 650);
    glutCreateWindow("ARCHONEA - EE309 vs Automatica");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(100, timer, 0);
    glutMainLoop();
    return 0;
}