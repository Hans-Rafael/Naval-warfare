#ifndef LOGICA_JUEGO_H
#define LOGICA_JUEGO_H

// --------------------------------------
// Configuración del juego
// --------------------------------------

// Tamaño del tablero 5x5
const int TAMA_TABLERO = 5;

// Cantidad de barcos por jugador
const int CANTIDAD_BARCOS = 3;

// Tamaño de cada barco
const int TAMA_BARCO = 2;

// --------------------------------------
// Funciones de lógica del juego
// --------------------------------------


// Recibe los tres tableros del juego.
// TAMA_TABLERO indica que cada tablero es de 5x5.
// Inicializa los tres tableros con agua (~)
void inicializarTableros(
    char tableroJugador[][TAMA_TABLERO],
    char tableroComputadora[][TAMA_TABLERO],
    char tableroDisparos[][TAMA_TABLERO]
);

#endif // LOGICA_JUEGO_H