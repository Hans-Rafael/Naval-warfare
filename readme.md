# Naval Warfare

## Compilar y ejecutar

Desde la terminal en la raíz del proyecto:

```bash
make             # compilar
./naval_warfare  # ejecutar
make clean       # eliminar el ejecutable
```
# ⚓ Batalla Naval C++ - Guía de Estilo y Reglas de Código

Para garantizar que el código de ambos integrantes se integre perfectamente, sea legible y mantenga un estándar profesional, se establecen las siguientes reglas de programación obligatorias para el equipo.

---

## 🔤 1. Nomenclatura (Naming Conventions)

Todo el código (funciones, variables y constantes) debe escribirse estrictamente en **inglés**. Los nombres deben ser lo suficientemente explicativos para entender su propósito sin adivinar.

* **Funciones (`lowerCamelCase` + Verbo):** Comenzarán con la primera letra en minúscula y un verbo en infinitivo que denote acción. Si el nombre tiene más palabras, la primera letra de las palabras siguientes irá en mayúscula.
  * *Correcto:* `initializeGrids()`, `displayBoard()`, `firePlayerShot()`.
  * *Incorrecto:* `inicializar_tableros()`, `MuestraMapa()`, `disparar()`.

* **Variables (`lowerCamelCase`):** Seguirán la misma regla de la primera letra en minúscula y mayúsculas en las palabras siguientes. Deben ser nombres descriptivos.
  * *Correcto:* `playerGrid`, `aiShipsCount`, `targetRow`.
  * *Incorrecto:* `tablero1`, `n`, `f_a`.

* **Constantes (`UPPERCASE` / SNAKE_CASE):** Todas las constantes globales irán completamente en mayúsculas. Si contienen más de una palabra, se separarán obligatoriamente por un guion bajo.
  * *Correcto:* `GRID_SIZE`, `MAX_SHIPS`.

---

## 📝 2. Idioma y Comentarios

* **Código en Inglés:** Palabras clave, variables, funciones y estructuras de control se escriben en inglés.
* **Comentarios en Español:** Para facilitar la explicación de la lógica interna al profesor y la defensa de la nota, todos los comentarios de guía dentro del código se mantendrán en **español**.
* **Textos en Pantalla (UI):** Los mensajes impresos con `cout` dirigidos al usuario final deberán estar completamente en **español**.

---

## 🛠️ 3. Reglas de Programación y Formato

* **Cero Números Mágicos:** Está prohibido usar números sueltos (como `5` o `3`) en los bucles o validaciones del código. Se deben usar las constantes `GRID_SIZE` y `MAX_SHIPS` declaradas en el archivo de cabecera.
* **Estilo de Llaves (K&R):** Las llaves de apertura `{` se colocan en la misma línea de la función, bucle o condicional. La llave de cierre `}` va sola en una línea inferior.
  ```cpp
  if (row >= 0 && row < GRID_SIZE) {
      // Código indentado aquí
  }
  ```
* **Indentación (Sangrado):** Ambos programadores deben configurar su editor de texto con un sangrado uniforme de **4 espacios** para que el archivo no se desordene al fusionarlo. El proyecto incluye un archivo `.editorconfig` en la raíz que aplica esta configuración automáticamente:
  * **VS Code:** instalar la extensión `EditorConfig for VS Code` (`Ctrl+Shift+X` → buscar `EditorConfig for VS Code`).
  * **CLion:** soporte nativo, no requiere nada extra.
  * **Vim/Neovim:** instalar el plugin `editorconfig-vim`.

  Una vez instalada la extensión, al guardar el archivo (`Ctrl+S`) las reglas se aplican automáticamente. Podés verificarlo mirando la barra inferior de VS Code, debe mostrar `Spaces: 4`.
* **Modularidad Obligatoria:** Ninguna función lógica debe escribirse directamente dentro del archivo de cabecera `funciones.h`. Este archivo solo sirve para declarar prototipos. Toda la "cocina" y el desarrollo del código va en `funciones.cpp`.

---

## 📱 4. Multiplataforma (Windows / Linux)

Para asegurar que la pantalla se limpie correctamente tanto en las computadoras del equipo (Linux) como en la del profesor (Windows), es obligatorio usar el bloque de preprocesamiento condicional en cada limpieza de terminal:

```cpp
#ifdef _WIN32
    system("cls");   // Limpieza nativa de Windows
#else
    system("clear"); // Limpieza nativa de Linux / Mac
#endif
```
## 🕹️ 5. Reglas del Juego y Lógica de Funcionamiento

Para que el juego funcione correctamente, ambos programadores debemos basar nuestras funciones en las siguientes reglas matemáticas y mecánicas de juego:

### 🗺️ El Sistema de Coordenadas
* El tablero es una matriz bidimensional de **5x5 casillas**.
* Las posiciones se manejan estrictamente con números enteros del **0 al 4** tanto para Filas como para Columnas (Indexación basada en cero).
* El punto superior izquierdo del mapa es la coordenada `(0,0)` y el punto inferior derecho es la coordenada `(4,4)`.

### 📦 Significado de los Símbolos en las Matrices
Para que las funciones de visualización (Front) y las funciones de disparo (Back) se entiendan, usaremos siempre los mismos caracteres `char`:
* `~` (Virgulilla) ➡️ **Agua inexplorada:** Casilla donde no hay nada o donde aún no se ha disparado (color azul).
* `B` (Letra B) ➡️ **Barco a flote:** Representa un barco propio que sigue activo (Color Verde).
* `X` (Letra X) ➡️ **Tocado / Impacto:** Casilla donde un disparo acertó con éxito en un barco (Color Rojo).
* `O` (Letra O) ➡️ **Agua / Fallo:** Casilla donde un disparo cayó al mar y no había ningún barco (Color Amarillo).

---

## 🔄 6. Flujo de las Fases del Juego

### 🧑‍💻 Fase 1: Inicialización y Despliegue (Responsabilidad del Integrante 1)
1. Al presionar "Iniciar Partida", todas las casillas de las 3 matrices (`playerGrid`, `aiGrid`, `trackingGrid`) deben llenarse con el carácter `~`.
2. El jugador humano debe ingresar manualmente las coordenadas de sus **3 barcos**. Cada barco ocupa exactamente **1 casilla**.
3. **Validación obligatoria:** El programa no debe permitir que el jugador ingrese coordenadas fuera del rango (0 a 4) ni colocar un barco en una casilla que ya esté ocupada por otro barco (`B`). El mapa se debe refrescar con cada barco colocado con éxito.
4. Al mismo tiempo, la computadora llamará a su función automática para esconder sus 3 barcos de forma aleatoria en `aiGrid` sin que el usuario los vea.

### 🎯 Fase 2: El Bucle de Combate (Responsabilidad del Integrante 2)
El juego entra en un ciclo alternado de turnos que no se detiene hasta que los barcos de algún bando lleguen a 0:

1. **Turno del Jugador:**
   * Se borra la pantalla y se muestran dos mapas: `trackingGrid` (tus disparos al enemigo) y `playerGrid` (tus propios barcos y los daños que has recibido).
   * El jugador "carga su jugada" ingresando la fila y columna a la que desea atacar.
   * **Validación:** Se debe comprobar que el tiro esté en el rango de 0 a 4 y que el jugador no haya disparado previamente en esa misma casilla (es decir, la casilla en `trackingGrid` debe ser obligatoriamente `~`).
   * **Procesamiento:** Si en esa coordenada de `aiGrid` había una `B`, se cambia a `X` en ambos tableros y se le resta 1 a la vida de la IA (`aiShips`). Si había agua `~`, se marca con una `O` en `trackingGrid`.

2. **Turno de la IA:**
   * Si tras el disparo del jugador la IA se quedó con 0 barcos, el bucle se rompe de inmediato (**Victoria**).
   * Si la IA sigue viva, genera una coordenada de ataque completamente aleatoria con `rand()`.
   * **Validación:** La IA debe verificar que no haya disparado antes en esa posición de tu tablero (la casilla en `playerGrid` no puede ser ni `X` ni `O`). Si se repite, debe generar otra coordenada hasta encontrar una válida.
   * **Procesamiento:** Si la IA acierta en tu barco (`B`), tu mapa cambia a `X` y pierdes 1 vida (`playerShips`). Si falla, se marca una `O` en tu agua.

### 🏆 Fase 3: Fin de la Partida
Al salir del bucle de combate, el programa debe limpiar la pantalla una última vez y evaluar las vidas:
* Si `aiShips == 0` ➡️ Imprime en verde: **"¡FELICIDADES! ¡HAS GANADO LA BATALLA NAVAL!"**.
* Si `playerShips == 0` ➡️ Imprime en rojo: **"GAME OVER. La IA ha hundido tu flota."**.
* Se hace una pausa y, al presionar ENTER, el juego debe redirigir a los usuarios de vuelta al Menú Principal de forma limpia.
