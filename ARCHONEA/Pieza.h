#pragma once
//Pido perdon necesito mis comentarios para saber que he hecho si no me pierdo y no me encuentro
#pragma once
#include <string>

// Clase base para todas las piezas del juego (alumnos y profesores)- clase abstract-no se puede crear una Pieza directamente
// sino que cada tipo de pieza (Delegado, Catedratico, etc.) hereda de esta
class Pieza {
protected:
    // Posición en el tablero (fila y columna del 0 al 8)
    int fila;
    int columna;

    // Estadísticas de combate de la pieza
    int vida;       // vida actual
    int vidaMax;    // vida máxima (para saber cuánto se puede curar)
    int velocidad;  // qué tan rápido se mueve en la arena de combate
    int ataque;     // cuánto daño hace con cada golpe

    // true = bando EE309 (alumnos), false = bando Automática (profesores)
    bool esBandoLuz;

    std::string nombre; // nombre de la pieza, por ejemplo "Delegado" o "Catedrático"

public:
    // Constructor: inicializa todos los atributos de la pieza
    Pieza(int fila, int columna, bool esBandoLuz, std::string nombre,
        int vida, int velocidad, int ataque);

    // Destructor virtual, necesario porque usamos herencia
    virtual ~Pieza() {}

    // Métodos virtuales puros: cada tipo de pieza DEBE implementarlos
    // de forma distinta según sus características

    // Dibuja la pieza en la pantalla en la posición (x,y) en píxeles
    virtual void dibujar(float x, float y) = 0;

    // Comprueba si la pieza puede moverse a una casilla concreta
    // depende del tipo de pieza (tierra, vuelo, teletransporte)
    virtual bool puedeMoverseA(int nuevaFila, int nuevaCol) = 0;

    // Devuelve el tipo de pieza como texto, por ejemplo "Delegado"
    virtual std::string getTipo() = 0;

    // Getters: para acceder a los atributos desde fuera de la clase
    int getFila() { return fila; }
    int getColumna() { return columna; }
    int getVida() { return vida; }
    bool getBando() { return esBandoLuz; }
    std::string getNombre() { return nombre; }

    // Devuelve true si la pieza sigue viva (vida > 0)
    bool estaViva() { return vida > 0; }

    // Setters: para modificar atributos
    void setPos(int f, int c) { fila = f; columna = c; }

    // Resta daño a la vida, sin bajar de 0
    void recibirDanio(int danio) {
        vida -= danio;
        if (vida < 0) vida = 0;
    }
};