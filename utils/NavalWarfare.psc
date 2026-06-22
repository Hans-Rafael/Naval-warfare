Algoritmo NavalWarfare
    // --- DECLARACIÓN DE VARIABLES ---
    Definir opcionUsuario, playerShips, aiShips Como Entero
    
    // --- BUCLE PRINCIPAL DEL JUEGO (do-while) ---
    Repetir
        Borrar Pantalla
        // FUNCIÓN DEL MENÚ PRINCIPAL
        Escribir "=============================="
        Escribir "       BATALLA NAVAL          "
        Escribir "=============================="
        Escribir "1. Jugar"
        Escribir "2. Instrucciones"
        Escribir "3. Salir"
        Escribir "Elige una opcion: "
        Leer opcionUsuario
        
        // ESTRUCTURA SWITCH
        Segun opcionUsuario Hacer
            1:
                // ==========================================
                // CASO 1: INICIAR PARTIDA
                // ==========================================
                Borrar Pantalla
                Escribir "Inicializando tableros con '~'..."
                Esperar 1 Segundos
                
                // ETAPA INTEGRANTE 1 (Preparación Jugador)
                Escribir "Menu: Acomoda tus 3 barcos..."
                // (Aquí el usuario colocaría sus barcos en la consola real)
                Esperar 1 Segundos
                
                // Reiniciar contadores de barcos (Regla: MAX_SHIPS = 3)
                playerShips <- 3
                aiShips <- 3
                
                // ETAPA INTEGRANTE 2 (Preparación IA)
                Escribir "La IA esta escondiendo sus 3 barcos al azar..."
                Esperar 1 Segundos
                
                // BUCLE DE COMBATE
                Mientras playerShips > 0 Y aiShips > 0 Hacer
                    Borrar Pantalla
                    
                    // A, B y C) Mostrar Tableros
                    Escribir "--- MAPA ENEMIGO ---"
                    Escribir "[ MATRIZ DE RASTREO ]"
                    Escribir "--- TU FLOTA ---"
                    Escribir "[ MATRIZ DEL JUGADOR ]"
                    
                    // D) Capturar disparo del usuario
                    Escribir "Tu turno. Ingresa coordenadas de disparo:"
                    // Simulación del disparo
                    Esperar 1 Segundos
                    
                    // E) VALIDACIÓN: Si le dimos al último barco, salir del combate
                    Si aiShips = 0 Entonces
                        // En PSeInt no existe el 'break' para el Mientras, 
                        // pero la condición del Si/Sino evita que la IA dispare.
                    Sino
                        // F y G) Turno y disparo automático de la IA
                        Escribir "Es el turno de la computadora..."
                        Esperar 1 Segundos
                        
                        // H) Pausar pantalla
                        Escribir ""
                        Escribir "Presiona ENTER para continuar..."
                        Esperar Tecla
                    FinSi
                FinMientras
                
                // PANTALLA FIN DE JUEGO (DETERMINAR GANADOR)
                Borrar Pantalla
                Si aiShips = 0 Entonces
                    Escribir "¡VICTORIA! Has destruido la flota enemiga. (VERDE)"
                Sino
                    Escribir "GAME OVER. La IA destruyo tus barcos. (ROJO)"
                FinSi
                Escribir "Presiona ENTER para regresar al menu principal..."
                Esperar Tecla
                
            2:
                // ==========================================
                // CASO 2: VER INSTRUCCIONES
                // ==========================================
                Borrar Pantalla
                Escribir "--- INSTRUCCIONES ---"
                Escribir "1. El tablero es de 5x5."
                Escribir "2. Cada jugador tiene 3 barcos (B)."
                Escribir "3. Símbolos: ~ (Agua), X (Impacto), O (Agua/Fallo)."
                Escribir "4. Gana el primero en hundir los 3 barcos del rival."
                Escribir ""
                Escribir "Presiona ENTER para volver al menu..."
                Esperar Tecla
                
            3:
                // ==========================================
                // CASO 3: SALIR DEL JUEGO
                // ==========================================
                Borrar Pantalla
                Escribir "Saliendo de Batalla Naval. ¡Hasta la proxima!"
                
            De Otro Modo:
                // ==========================================
                // CASO POR DEFECTO (ERROR)
                // ==========================================
                Escribir "OPCION INCORRECTA. Por favor, elige 1, 2 o 3. (ROJO)"
                Esperar 2 Segundos
        FinSegun
        
    Hasta Que opcionUsuario = 3
    
FinAlgoritmo