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
