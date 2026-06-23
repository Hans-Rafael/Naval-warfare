#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <cstdlib> // para numeros aleatorios con rand() y srand()
#include <ctime>   // para manipular los tiempos ej. time() o srand(time(0))
#include <string>  // para gestionar string

// En Windows se necesita <windows.h> para habilitar los colores ANSI en la consola
#ifdef _WIN32
#include <windows.h>
#endif

//---------------
void funcionDePruebas();
//---------------
// --- COLORES ANSI ---
// Uso: cout << VERDE << "texto" << RESET;  <- siempre terminar con RESET para no "manchar" la consola
// Ejemplo: cout << RED << "X" << RESET << " impacto!";
// IMPORTANTE: enableAnsiColors() en main.cpp ya los activa en Windows, no hay que hacer nada más
#define RESET "\033[0m"   // Vuelve al color por defecto
#define BLUE "\033[34m"   // Agua inexplorada (~)
#define GREEN "\033[32m"  // Barco a flote (B)
#define RED "\033[31m"    // Impacto (X)
#define YELLOW "\033[33m" // Fallo / agua disparada (O)
#define CYAN "\033[36m"   // Uso general / títulos

// --- CONSTANTES GLOBALES ---
// aquí las constantes del tamaño del mapa (5) y barcos máximos (3) usando 'const int'
const int TAM_MAPA = 5; // o GRID_SIZE
const int MAX_BARCOS = 3;

// --- MATRICES GLOBALES COMPARTIDAS ---
//'extern char' le dice al compilador 'Esta variable existe, pero está definida en otro lugar'
extern char matrizJugador[TAM_MAPA][TAM_MAPA];
extern char matrizIa[TAM_MAPA][TAM_MAPA];
extern char matrizSeguimiento[TAM_MAPA][TAM_MAPA];

// --- VARIABLES GLOBALES DE CONTROL ---
//'extern int' para declarar los contadores de barcos (playerShips, aiShips)
extern int barcosJugador;
extern int barcosIa;

// =================================================================
// 🧑‍💻 INTEGRANTE 1: FASE DE PREPARACIÓN (Declaraciones)
// =================================================================

// PROTOTIPO 1: Nombre de la función para inicializar los tableros vacíos.
void inicializarTableros();
// PROTOTIPO 2: Nombre de la función para el menú donde el jugador pone sus barcos.
void colocarBarcosJugador();

// =================================================================
// 🎯 INTEGRANTE 2: FASE DE COMBATE (Declaraciones)
// =================================================================

// PROTOTIPO 3: Nombre de la función reutilizable para dibujar un tablero en pantalla.
void dibujarTablero(char matriz[TAM_MAPA][TAM_MAPA], bool ocultarBarcos);

// PROTOTIPO 4: Nombre de la función para esconder los barcos de la IA.
void ColocarBarcoIa(char matriz[TAM_MAPA][TAM_MAPA]);
// PROTOTIPO 5: Nombre de la función para capturar el disparo del usuario.
void disparoJugador(char matriz[TAM_MAPA][TAM_MAPA]);
// PROTOTIPO 6: Nombre de la función para el disparo automático de la IA.
void disparoIa(char matriz[TAM_MAPA][TAM_MAPA]);

#endif
