# Trabajo Práctico: Máquinas de Estado — Histograma de longitud de palabras

## Información del Trabajo
- **Número de equipo:** 4

## Autores de la Resolución
## 👥 Integrantes del Grupo
- **limberthEstrada** (176.499-8) Estrada, Limberth Daniel
- **matibapti** (156.359-2) Baptista, Matias
- **UsuarioGitHub** (Legajo) Carreras, Gabriel Martin
- **UsuarioGitHub** (Legajo) Gerez, Florencia Ayelen
- **UsuarioGitHub** (Legajo) Herbas Montero, Axel Junior
- nmmeli (203.826-2) Martino, Nehuen Oscar
- **UsuarioGitHub** (Legajo) Miranda, Maria Belen
- **UsuarioGitHub** (208.125-8) Ramirez Alarcon, Nataly Nicole
- IvanSamokec (167.434-1) Samokec, Ivan

## Transcripción del Enunciado
1. **Enunciado**
   - Imprimir un histograma de las longitudes de las palabras de en la entrada estándar.

## 📊 Hipótesis de Trabajo

Luego de leer el enunciado se llegó a la siguiente hipótesis:

1. Este trabajo práctico nos desafía a pensar más allá del código. Al implementar un histograma de longitud de palabras usando una máquina de estado, pero con diferentes técnicas de programación, aprendemos a ver el problema desde una perspectiva más amplia. El objetivo es entender la máquina de estado como concepto, sin importar cómo la escribamos en código. Nos enfocamos en cómo funciona la máquina de estado en sí, no en los detalles de cada implementación.


## Tareas
### Árboles de expresión:
   
a. Dibujar el árbol de expresión para la inicialización de los contadores: nl = nw = nc = 0.
![Árbol](https://imgur.com/whfidDY.png)

b. Dibujar el árbol de expresión para la expresión de control del segundo if: c == ' ' || c == '\n' || c == '\t'.
![Árbol](https://imgur.com/YIYg7Oz.png)

---

### Máquina de estado:

La máquina de estados del histograma se define formalmente como: M = (Q, Σ, T, q0, A)

Elementos de la n-upla:
- **Conjunto de estados (Q):**
  - { OUT, IN }
- **Alfabeto (Σ):**
  - Σ = { CB, CNB }, en donde **CB** = {' ', '\t', '\n'} y **CNB** = ASCII - CB
- **Estado inicial (q0):**
  - OUT
- **Conjunto de acciones (A):**
  - ε
  - longitud++
  - ++palabras[longitud] 
  - longitud=0
- **Función de transición T:**
  - T: QxΣ -> QxA es la función de transiciones y la tabla de transiciones (TT) es la siguiente
    | TT   | CB                             | CNB                  |
    |-----|---------------------------------|--------------------|
    | OUT | {OUT, ε}                       | {IN, longitud++}   |
    | IN  | {OUT, (++palabras[longitud], longitud=0)} | {IN, longitud++}   |

---

### Implementaciones de máquinas de estado:

- **Implementación #1**: Una variable para el estado actual.
  - Ventajas de la versión de [KR1988]:
    - El uso de if-else puede ser más eficiente en términos de ejecución en comparación con switch en algunos compiladores y arquitecturas.
    - Tiene menos código, más directo y fácil de entender para tareas simples.

  - Desventajas de la versión de [KR1988]:
    - El uso de constantes definidas (#define) puede ser menos legible y más propenso a errores en comparación con enum.
    - Añadir nuevos estados o múltiples sentencias 'if' puede hacer que el código sea menos legible al manejar varios estados y transiciones.

  - Ventajas de esta implementación:
    - Uso de enum y switch mejora la legibilidad y organización del código, haciendo que la lógica de las transiciones entre estados sea más explícita y clara.
    - Facilita la adición y manejo de nuevos estados, ya que **enum** permite agrupar estados de manera coherente.

  - Desventajas de esta implementación:
    - Puede ser ligeramente más lento debido al uso de la sobrecarga de switch en lugar de if-else.
    - Aunque es más escalable y fácil de mantener, esta implementación inicial puede ser más compleja y tomar más tiempo en desarrollarse y entenderse en comparación con la versión original más simple de [KR1988].

- **Implementación #2**: Sentencias goto.
  - ¿Tiene alguna aplicación go to hoy en día? ¿Algún lenguaje moderno lo utiliza?
    - La mayoría de los lenguajes de programación modernos, como Java, Python y C#, desaconsejan o directamente prohíben el uso de goto. Sin embargo, lenguajes como C y C++, que están más cerca del hardware, aún permiten su uso
    > Fuente: The C++ Programming Language (Stroustrup) y The C Programming Language (Kernighan & Ritchie)

- **Implementación #3**: Funciones Recursivas
  - ¿Es necesario que las funciones accedan a a contadores? Si es así, ¿cómo hacerlo?
    - Sí, es necesario que las funciones recursivas accedan y modifiquen contadores para poder realizar su tarea de conteo correctamente. Hay dos formas principales de lograr esto:
      1) Usando variables globales: Se pueden declarar los contadores como variables globales (externas) que sean accesibles y modificables por las funciones recursivas. Las variables globales se definen fuera de cualquier función y están disponibles para muchas funciones.
      2) Pasando los contadores como parámetros por referencia: Otra opción es pasar los contadores a las funciones recursivas como parámetros, pero de una manera que permita a la función modificar el valor original. En C, esto se puede lograr pasando un puntero al contador. De esta forma, la función recibe la dirección de memoria del contador y puede modificar su valor directamente.

- **Implementación #X**:
  - En esta implementación, los estados y transiciones se definen en una tabla. La tabla define para cada estado y entrada cuál es el siguiente estado y la acción a tomar. Los estados se representan mediante una enumeración (enum). Esto permite que los estados sean identificadores simbólicos en lugar de simples enteros, lo que mejora la legibilidad del código. Las transiciones se representan mediante una tabla de transiciones, que es una matriz bidimensional. Las filas de la matriz corresponden a los estados actuales y las columnas corresponden a los símbolos de entrada. Cada celda de la matriz contiene el estado siguiente y la acción correspondiente para una combinación de estado actual y símbolo de entrada.

---

### Benchmark:

# Benchmark de Implementaciones

| Implementación | archivo_kb.txt (ms) | archivo_mb.txt (ms) | archivo_gb.txt |
|----------------|----------------------|---------------------|----------------|
| enum-switch    | 416.89               | 4605.69             | Demasiado tiempo y consume mucha memoria |
| goto           | 55.85                | 4408.15             | Demasiado tiempo y consume mucha memoria |
| rec            | 44.88                | 3695.85             | Demasiado tiempo y consume mucha memoria |
| tabla          | 39.89                | 3802.46             | Demasiado tiempo y consume mucha memoria |
