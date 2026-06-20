#include <iostream>
#include "functions.h" //../include/functions.h no fue necesario asi

using namespace std;

// --- DEFINICIÓN DE VARIABLES GLOBALES ---
// Aquí deben definir e inicializar (darles un valor inicial) las variables del header:
// Las 3 matrices (playerGrid, aiGrid, trackingGrid)
// Los 2 contadores de barcos (playerShips = 3, aiShips = 3)

// --- FUNCIÓN DEL MENÚ PRINCIPAL ---
// ¿Qué debe hacer?: Imprimir el diseño del menú en pantalla (1. Jugar, 2. Instrucciones, 3. Salir).
void showMainMenu()

{
    // Usar std::cout para dibujar el menú textualmente con colores ANSI
}

int main()
{
    //*********Prueba de modularidad */
    cout << "hello world" << endl;
    funcionDePruebas();
    return 0;
    // *****Fin de prueba  de moddularidad */

    // LÍNEA OBLIGATORIA: Inicializar la semilla para que rand() sea verdaderamente aleatorio
    srand(time(0));

    int option; // Variable para capturar la opción del usuario

    do
    {
// -------------------------------------------------------------------------
// 💡 TRUCO PROFESIONAL PARA LIMPIAR PANTALLA EN WINDOWS Y LINUX/MAC 💡
// Coloquen este bloque exactamente donde necesiten borrar la pantalla.
// El compilador detectará el sistema operativo y usará el comando correcto.
// -------------------------------------------------------------------------
#ifdef _WIN32
        system("cls"); // Si se ejecuta en Windows, usa CLS
#else
        system("clear"); // Si se ejecuta en Linux o Mac, usa CLEAR
#endif
        // -------------------------------------------------------------------------

        // 1. Mostrar el menú principal llamando a la función de arriba

        // 2. Leer la opción del usuario con std::cin

        // 3. Estructurar el control de opciones usando un switch(option)
        switch (option)
        {

        // =================================================================
        // CASO 1: INICIAR PARTIDA
        // =================================================================
        case 1:
            // --- ETAPA DEL INTEGRANTE 1 (PREPARACIÓN) ---
            // Llamar a la función para limpiar/inicializar los tableros con '~'

            // Llamar a la función que pide al usuario acomodar sus barcos

            // Reiniciar los contadores de barcos a 3 por si juegan una segunda partida

            // --- ETAPA DEL INTEGRANTE 2 (PREPARACIÓN IA) ---
            // Llamar a la función que esconde los 3 barcos de la IA al azar

            // --- ETAPA DEL INTEGRANTE 2 (BUCLE DE COMBATE) ---
            // Crear un ciclo 'while' que se repita MIENTRAS playerShips > 0 Y aiShips > 0
            while (true)
            { // Reemplazar 'true' por la condición real de vida de los barcos

                // A) Limpiar pantalla aquí usando el truco de #ifdef _WIN32 (cls / clear)

                // B) Llamar a displayGrid para mostrar el mapa de disparos (enemigo)

                // C) Llamar a displayGrid para mostrar el estado de tu propia flota (tus barcos)

                // D) Llamar a la función para cargar la jugada / disparo del jugador

                // E) VALIDACIÓN: Si aiShips llega a 0, usar 'break' para salir del bucle de inmediato

                // F) Imprimir un texto que avise que es el turno de la computadora

                // G) Llamar a la función para el disparo automático de la IA

                // H) Pausar la pantalla para que el usuario lea lo que hizo la IA usando:
                // std::cout << "\nPresiona ENTER para continuar...";
                // std::cin.ignore(); std::cin.get();
            }

            // --- PANTALLA DE FIN DE JUEGO (DETERMINAR GANADOR) ---
            // A) Limpiar pantalla aquí con el truco (cls / clear)

            // B) Evaluar con un 'if': Si aiShips == 0, imprimir cartel de victoria en VERDE.
            //    Si no, imprimir cartel de GAME OVER en ROJO.

            // C) Hacer una pausa final con std::cin.get() antes de regresar al menú principal

            break;

        // =================================================================
        // CASO 2: VER INSTRUCCIONES
        // =================================================================
        case 2:
            // A) Limpiar pantalla aquí con el truco (cls / clear)

            // B) Imprimir con std::cout las reglas del juego y el significado de los símbolos (~, B, X, O)

            // C) Hacer una pausa con std::cin.get() para que el usuario pueda leer antes de volver

            break;

        // =================================================================
        // CASO 3: SALIR DEL JUEGO
        // =================================================================
        case 3:
            // Imprimir un mensaje de despedida en la consola
            break;

        // =================================================================
        // CASO POR DEFECTO (OPCIÓN INCORRECTA)
        // =================================================================
        default:
            // Imprimir mensaje de error en ROJO y hacer una pausa rápida
            break;
        }

    } while (option != 3); // El programa se repite hasta que el usuario elija la opción 3 (Salir)

    return 0;
}
