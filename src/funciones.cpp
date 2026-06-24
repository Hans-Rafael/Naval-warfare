#include <iostream>
#include "funciones.h"

using namespace std;
// la funcion de prueba
void funcionDePruebas()
{
    cout << "Hola soy la FUNCION de prueba\n";
}
// =================================================================
// 🧑‍💻 INTEGRANTE 1: FASE DE PREPARACIÓN (Lógica interna)
// =================================================================

// FUNCIÓN 1: inicializarTableros (initializeGrids)
// Desarrolla el doble bucle 'for' para llenar las 3 matrices con '~'.
void inicializarTableros(
    char tableroJugador[][TAMA_TABLERO],
    char tableroComputadora[][TAMA_TABLERO],
    char tableroDisparos[][TAMA_TABLERO]
)
{
    // Recorre todas las
    for (int i =0; i < TAMA_TABLERO; i++)
    {
        for (int j = 0; j < TAMA_TABLERO; j++)
        {
        // Inicializa cada celda de los tableros con agua (~)
            tableroJugador[i][j] = '~';
            tableroComputadora[i][j] = '~';
            tableroDisparos[i][j] = '~';
        }
    }
}


// FUNCIÓN 2: menuColocacionJugador (menuPlacePlayerShips)
// Desarrolla el bucle que pide filas y columnas al usuario, limpia pantalla con
// 'system("clear")', muestra el mapa para previsualizar y guarda los barcos ('B').



// =================================================================
// 🎯 INTEGRANTE 2: FASE DE COMBATE (Lógica interna)
// =================================================================

// FUNCIÓN 3: mostrarTablero (displayGrid)
// Desarrolla la impresión del marco de coordenadas (0-4) y el doble ciclo 'for'
// que evalúa cada casilla para pintarla con su color ANSI en Linux.


// FUNCIÓN 4: colocarBarcosIA (placeAiShips)
// Desarrolla la lógica para que la máquina use 'rand() % 5' y coloque sus 3 barcos
// de forma oculta y sin encimarlos.


// FUNCIÓN 5: realizarDisparoJugador (firePlayerShot)
// Desarrolla la captura del ataque del usuario, valida que no repita casilla y
// resta vidas si le da a un barco ('B') de la IA cambiando el mapa a 'X' u 'O'.


// FUNCIÓN 6: realizarDisparoIA (fireAiShot)
// Desarrolla el disparo automático de la máquina con 'rand() % 5', asegurando
// que no ataque donde ya disparó y restándote vidas si te impacta.
