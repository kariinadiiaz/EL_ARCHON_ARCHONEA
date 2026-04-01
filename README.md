# EL ARCHON ARCHONEA 🎮
### Trabajo de Informática Industrial - Curso 2025/2026
### EE309 - Departamento de Automática, UPM

---

## 🎯 Descripción del juego

Variación del juego clásico ARCHON (1983) con temática universitaria.
Enfrentamiento entre los alumnos de la clase EE309 contra los profesores 
del Departamento de Automática de la UPM.

El juego combina estrategia por turnos en un tablero 9x9 con combates 
en tiempo real cuando dos piezas se encuentran en la misma casilla.

---

## ⚔️ Bandos

### 🟡 Bando EE309 - ALUMNOS (Luz)

| Pieza | Rol | Características |
|-------|-----|----------------|
| Delegado | Líder | Lanza conjuros. Lento pero poderoso |
| Empollón | Atacante a distancia | Lanza libros/apuntes. Débil físicamente |
| Deportista | Atacante rápido | Muy veloz pero poca vida. Cuerpo a cuerpo |
| Nocturno | Tanque | Estudia de noche. Resistente. Ataque medio |
| Copión | Especial | Habilidad única: copia el ataque del rival |

### 🔴 Bando AUTOMÁTICA - PROFESORES (Oscuridad)

| Pieza | Rol | Características |
|-------|-----|----------------|
| Platero | Líder | Lanza conjuros. Equivalente al Delegado |
| MH | Tanque | Muy lento pero resistentísimo. El más duro |
| Oscar C | Atacante rápido | Veloz y débil. Ataque básico |
| Hector M | Atacante a distancia | Lanza papers científicos |
| Imanol | Expulsor | El que te echa del aula. Muy rápido y molesto |

---

## 🏆 Condiciones de victoria

- Controlar los 5 puntos de poder del tablero
- Eliminar todas las piezas del rival
- Dejar al rival con solo una pieza encarcelada

---

## 🛠️ Tecnologías utilizadas

- C++ con Visual Studio 2026
- Librería ETSIDI (UPM)
- OpenGL / freeglut

---


## 📅 Estado del desarrollo

- [x] Proyecto creado en Visual Studio
- [x] Librería ETSIDI configurada
- [x] Tablero 9x9 dibujado en pantalla
- [x] Clases base Pieza y Tablero creadas
- [ ] Piezas de cada bando implementadas
- [ ] Movimiento en el tablero
- [ ] Arena de combate
- [ ] Conjuros del líder
