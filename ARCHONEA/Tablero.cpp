//Pido perdon necesito mis comentarios para saber que he hecho si no me pierdo y no me encuentro
#include "Tablero.h"

/*Constructor: cuando creamos el tablero, todas las casillas empiezan vacías
nullptr significa que no hay ninguna pieza en esa casilla*/ 
Tablero::Tablero() {
    for (int i = 0; i < 9; i++)        // recorremos las 9 filas
        for (int j = 0; j < 9; j++)    // recorremos las 9 columnas
            casillas[i][j] = nullptr;   // casilla vacía
}

// Destructor: cuando el juego termina, liberamos la memoria de todas las piezas
Tablero::~Tablero() {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (casillas[i][j] != nullptr)    // si hay una pieza en esta casilla
                delete casillas[i][j];       // la eliminamos de memoria
}

// Coloca una pieza en una casilla concreta del tablero. También le decimos a la pieza en qué posición está
void Tablero::colocarPieza(Pieza* p, int fila, int col) {
    casillas[fila][col] = p;
    p->setPos(fila, col);  // actualizamos la posición de la pieza
}

// Devuelve la pieza que hay en una casilla (o nullptr si está vacía)
Pieza* Tablero::getPieza(int fila, int col) {
    return casillas[fila][col];
}

// Elimina una pieza del tablero y libera su memoria
void Tablero::eliminarPieza(int fila, int col) {
    if (casillas[fila][col] != nullptr) {
        delete casillas[fila][col];
        casillas[fila][col] = nullptr;  // dejamos la casilla vacía
    }
}

/*Comprueba si una casilla es un punto de poder
Los 5 puntos de poder son: centro, y centro de cada borde*/
bool Tablero::esPuntoPoder(int fila, int col) {
    for (int i = 0; i < 5; i++)
        if (puntosPoder[i][0] == fila && puntosPoder[i][1] == col)
            return true;
    return false;
}

// Comprueba si una casilla está libre (sin piezas)
bool Tablero::esCasillaLibre(int fila, int col) {
    return casillas[fila][col] == nullptr;
}

// MUEVE UNA PIEZA DE UNA CASILLA A OTRA
// Primero cogemos la pieza, luego vaciamos la casilla origen y finalmente la colocamos en el destino
void Tablero::moverPieza(int filaOrigen, int colOrigen, int filaDestino, int colDestino) {
    Pieza* p = casillas[filaOrigen][colOrigen];
    if (p != nullptr) {
        casillas[filaOrigen][colOrigen] = nullptr;   // vaciamos el origen
        casillas[filaDestino][colDestino] = p;        // colocamos en destino
        p->setPos(filaDestino, colDestino);           // actualizamos posición
    }
}