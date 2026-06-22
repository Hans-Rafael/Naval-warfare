#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <cstdlib> // para numeros aleatorios con rand() y srand()
#include <ctime>  // para manipular los tiempos ej. time() o srand(time(0))
#include <string> // para gestionar string

//---------------
void funcionDePruebas();
//---------------
// --- COLORES ANSI PARA LA TERMINAL DE LINUX ---
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

// --- CONSTANTES GLOBALES ---
// Pongan aquí las constantes del tamaño del mapa (5) y barcos máximos (3) usando 'const int'
const int MAX_SIZE = 5; //o GRID_SIZE
const int MAX_SHIPS = 3;

// --- MATRICES GLOBALES COMPARTIDAS ---
//'extern char' le dice al compilador 'Esta variable existe, pero está definida en otro lugar'
extern char playerGrid[MAX_SIZE][MAX_SIZE];
extern char aiGrid[MAX_SIZE][MAX_SIZE];
extern char trackingGrid[MAX_SIZE][MAX_SIZE];

// --- VARIABLES GLOBALES DE CONTROL ---
//'extern int' para declarar los contadores de barcos (playerShips, aiShips)
extern int playerShips;
extern int aiShips;

// =================================================================
// 🧑‍💻 INTEGRANTE 1: FASE DE PREPARACIÓN (Declaraciones)
// =================================================================

// PROTOTIPO 1: Nombre de la función para inicializar los tableros vacíos.
//void initGrids();
// PROTOTIPO 2: Nombre de la función para el menú donde el jugador pone sus barcos.
//void placePlayerShips();

// =================================================================
// 🎯 INTEGRANTE 2: FASE DE COMBATE (Declaraciones)
// =================================================================

// PROTOTIPO 3: Nombre de la función reutilizable para dibujar un tablero en pantalla.
void drawGrid(char grid[MAX_SIZE][MAX_SIZE], bool hideShips);

// PROTOTIPO 4: Nombre de la función para esconder los barcos de la IA.
void placeAiShips(char grid[MAX_SIZE][MAX_SIZE]);
// PROTOTIPO 5: Nombre de la función para capturar el disparo del usuario.
void playerShot(char grid[MAX_SIZE][MAX_SIZE]);
// PROTOTIPO 6: Nombre de la función para el disparo automático de la IA.
void aiShot(char grid[MAX_SIZE][MAX_SIZE]);

#endif

