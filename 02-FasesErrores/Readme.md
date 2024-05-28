## 🛠 Funciones de mi compilador para limitar el inicio y fin de las fases de traducción:

### [Preprocesamiento]
- **-E:** Ejecuta solo la fase de preprocesamiento y muestra el resultado en la salida estándar.

### [Compilación]
- **-S:** Ejecuta el preprocesamiento y la compilación, generando el código ensamblador.

### [Ensamblado]
- **-c:** Ejecuta el preprocesamiento, compilación y el ensamblado, generando el código objeto.

Referencia: https://gcc.gnu.org/onlinedocs/gcc/Overall-Options.html

## Paso 1 - [Preprocesador]

### a) 
Puedo ver a simple vista que a la función `main` contiene errores, por ejemplo, le falta cerrar una llave y tiene una función no definida.

### b) 
De acuerdo al contenido de `hello2.i`, se puede concluir que el breve código que estaba inicialmente se expandió, mejor dicho se expandieron las directivas `include` y otras directivas del preprocesador. Se puede observar el contenido que corresponde al archivo `stdio.h` y otros archivos de encabezado que son incluidos indirectamente por ese archivo.
Utilicé el siguiente comando: `gcc -E hello2.c -o hello2.i`

### c)  
Esta variante es muy similar al hello2.c, solo que esta vez tiene una definición a la función `printf` y no hace inclusión del archivo de cabecera `stdio.h`.

### d)
Para empezar la primera línea se trata de una declaración de una función y también de una función que devuelve un entero y toma al menos un parámetro. Sobre el primer parámetro se trata de un puntero a un caracter constante llamado 's'. El `restrict` es una palabra clave que le indica al compilador que el puntero 's' es el único puntero que se utilizará para acceder al objeto al que apunta. El '...' indica que la función puede tener un número indeterminado de argumentos después del primer argumento, que se utilizan para proporcionar los valores a imprimir según el formato especificado en el primer argumento.

Referencias:
- El lenguaje de programación de Kernighan & Ritchie, Capitulo 7: Entrada y Salida (Sección 7.2 - Salida con formato - printf), Capitulo 5: Apuntadores y arreglos (Sección 5.5 - Apuntadores a caracteres, y funciones), 
- N1570 - ISO/IEC 9899:201x - C11 (Sección 6.7.3.1  Formal deﬁnition of restrict)

### e)
`hello3.i` es el resultado de la primera fase de la compilación, conocida como la fase de preprocesamiento. El preprocesador realiza las siguientes tareas:
- Elimina los comentarios del código fuente.
- Incluye los archivos de encabezado utilizando las directivas `#include`.
- Expande las macros definidas por el usuario o por el preprocesador.
- Realiza sustitución de texto condicional basado en directivas como `#if`, `#ifdef`, `#ifndef`, `#else`, `#endif`. 
Además, analizando archivo `hello3.i` se puede concluir que el preprocesador generó marcadores de línea, dichos marcadores representan: el nombre del archivo fuente, el nombre de archivo de encabezado predefinido y la línea de comando utilizada para invocar al preprocesador. El archivo `hello3.i` se usa como entrada para la siguiente fase de compilación, es decir la compilación en sí.
Utilicé este comando: `gcc -E hello3.c -o hello3.i` 

## Paso 2 - [Compilación]

### a)
Al compilar el resultado y no ensamblar se generó un error en la función `main`, dicho error se trata de que no existe una declaración para la función invocada `prontf`, en el mensaje de error se menciona que pudo ser un error de tipeo y que la función sea `printf` y no `prontf`. Y debido a este error no se pudo generar el archivo ensamblador.
Utilicé este comando: `gcc -S hello3.c -o hello3.s`

### b)
Ya fueron corregidos los errores y se pudo generar el archivo `hello4.s`. Y en su contenido se puede observar una representación intermedia entre el código fuente en C y el código maquina, propiamente en código ensamblador. Y que al ensamblarlo se podrá generar un archivo ejecutable.
Utilicé este comando: `gcc -S hello4.c -o hello4.s`

### c)
Es un lenguaje de programación de bajo nivel que se utiliza para programar microprocesadores. Es una representación simbolica del código de máquina, lo que significa que es la forma más legible para un programador de entender las instrucciones especificas de cada arquitectura de procesador. Fue usado principalmente en los inicios del desarrollo de software, cuando aún no se contaba con potentes lenguajes de alto nivel y los recursos eran limitados. Actualmente se utiliza con frecuencia en ambientes académicos y de investigación, especialmente cuando se requiere la manipulación directa de hardware, alto rendimiento, o un uso de recursos controlado y reducido. También es utilizado en el desarrollo de controladores de dispositivo (en inglés, device drivers) y en el desarrollo de sistemas operativos, debido a la necesidad del acceso directo a las instrucciones de la máquina.

El objetivo del código es imprimir en la salida estándar la cadena "La respuesta es 42" utilizando la función `printf`. El valor 42 se asigna a una variable "i" y luego se formatea junto con la cadena "La respuesta es %d \n"

Referencia: https://es.wikipedia.org/wiki/Lenguaje_ensamblador

### d)
Quedó ensamblado, pero no es posible abrir el archivo objeto para analizarlo porque en su contenido hay texto binario.
Utilicé este comando: `gcc -c hello4.s -o hello4.o`

## Paso 3 - [Vinculación]

### a) 
Utilicé este comando: `gcc -o hello4.exe hello4.o`

### b)
Corregido, el error radicaba en que, al ejecutar hello4.exe, no se le había pasado la variable 'i' como argumento en la función `printf`, lo que resultaba en la ausencia de la impresión del valor de 'i'. Dado que este comportamiento estaba indefinido, se devolvía un valor indeterminado.
Utilicé este comando: `gcc -o hello5.exe hello5.c`

### c)
Al corregir los errores, se obtiene la respuesta esperada

## Paso 4 - [Corrección de bug]

### a)
Volví a hacer todo en hello6.c y funciona con normalidad.

## Paso 5 - [Remoción de prototipo]

### a)
Listo, ahora hello7.c no se tiene una declaración para `printf`.

### b)  

- i) 
Arroja warning: implicit declaration of function 'printf'; incompatible implicit declaration of built-in function 'printf'. Significa que el programa se compilará y ejecutará correctamente, pero el compilador está advirtiendo sobre un posible problema.

- ii) 
Es una declaración que especifica el nombre de la función, los tipos de los parámetros y el tipo de retorno. Se puede generar un prototipo incluyendo el header file o escribiendo el prototipo manualmente. Permite al compilador verificar que las llamadas a la función sean correctas.

Referencia: El lenguaje de programación de Kernighan & Ritchie, Capitulo 1 (Sección 1.7 Funciones)

- iii) 
La declaración implícita de una función es la característica del lenguaje C que ocurre cuando se llama a una función sin haberla declarado previamente. Es cuando se usa una función sin proveer previamente su prototipo. En este caso, el compilador asume un prototipo basado en la llamada a la función. Puede llevar a problemas si la suposición era incorrecta.

Referencia: https://www.ibm.com/docs/es/i/7.5?topic=definitions-function-declarations

- iv) 
La especificación C indica que se debe proveer una declaración o una definición de una función antes de usarla. De no hacerlo, el comportamiento será indefinido. Muchos compiladores permiten el uso de funciones sin una declaración previa.

Referencia: N1570 - ISO/IEC 9899:201x - C11 (Sección 6.5.2.2 Function calls, P6)

- v) 
Las primeras implementaciones de C permitían llamadas a funciones sin prototipo, generando un prototipo implícito; actualmente para mantener compatibilidad con versiones anteriores se emite una advertencia para alertar a un programador de un posible error.

Referencia: ISO/IEC 9899:1989 (Sección 3.3.2.2)

- vi) 
Se trata de una función que está integrada directamente en el compilador. El compilador conoce su prototipo sin necesidad de incluir un encabezado. Para este caso `printf` no es una función de este tipo, sino es una función de biblioteca.

Referencia: https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html

- vii) 
GCC se comporta de esta manera para cumplir con la especificación del lenguaje C y al mismo tiempo proporcionar una advertencia al programador. También se emiten warnings para alentar al programador a mejorar el código. No va directamente contra la especificación. El código de `hello7.c` funciona porque GCC permite llamadas a `printf` sin prototipo como una extensión, generando/asumiendo un prototipo implícito. La razón por la que GCC permite llamadas a funciones sin declaración previa es para mantener compatibilidad con código antiguo de C. La especificación de C dice que llamar a una función sin declaración previa resulta en un comportamiento indefinido. "Indefinido" significa que la especificación no define qué debe pasar en este caso: podría funcionar, podría fallar, podría hacer cualquier cosa. GCC no viola la especificación, sino que provee una extensión documentada.

## Paso 6 - Compilación separada: Contratos y Módulos

### a)
Listo, ya generados.

### b)
Utilicé el comando: `gcc -c studio1.c hello8.c`
Utilicé el comando: `gcc studio1.o hello8.o -o programa`

Referencia: https://gcc.gnu.org/onlinedocs/gcc/Overall-Options.html#Overall-Options

### c)
Ya sea eliminando o agregando argumentos, se produciría errores de compilación. Esto se debe a qué no hay un contrato establecido entre las unidades de traducción `hello8.c` y `stdio1.c` sobre la interfaz de la función `prontf`. El compilador de C asumirá que `prontf` toma cualquier número de argumentos de cualquier tipo (porque no tiene información sobre su interfaz real) y permitirá que el código compile, y eso producirá un error porque la definición real de `prontf` no coincide con la asumida. Ya sea que agreguemos o eliminemos, siempre fallará en el paso de enlace porque la llamada no coincide con la definición.

### d) iv) 
- Verificación de tipos en tiempo de compilación: Se puede verificar que los tipos de los argumentos pasados a 'prontf' coincidan con los tipos declarados en su prototipo. Esto ayuda a detectar errores en tiempo de compilación.
- Documentación de interfaz: Facilita la comprensión y el uso correcto de la función por parte de los clientes, al tener acceso a la declaración de la función y los tipos de datos esperados.
- Facilita el mantenimiento: Al tener un contrato separado, es decir, tener la interfaz por un lado y la implementación por otro lado, se logra una separación clara, esto puede permitir al proveedor modificar la implementación de `prontf` sin afectar a los clientes, siempre y cuando se mantenga el contrato.
- Reutilización y modularidad: Al tenerlo separa    do en un archivo encabezado, puede ser incluido y utilizado en multiples archivos fuente.
- Prevención de declaraciones implícitas: Para evitar comportamientos inesperados.
- Ocultamiento de información: Al tenerlo todo en un archivo encabezado, el cliente solo necesita saber cómo llamar a las funciones, no como funcionan internamente.

Referencia: Mencionado en clase

## Crédito extra:

Las bibliotecas son un conjunto de funciones y rutinas que pueden ser utilizadas por programas de software para realizar tareas especificas.

Son distribuibles junto con el software que las utiliza. Pueden ser distribuidas como archivos compilados (binarios) o como archivos fuente que deben ser compilados antes de su uso. Permiten compartir código entre diferentes programas y entre diferentes desarrolladores.

En general son portables, especialmente si están escritas en un lenguaje de programación de alto nivel y no dependen de características especificas de una plataforma o SO. Pero si dependen de eso, puede limitar su portabilidad.

Sus ventajas son:
- Reutilización de código: se pueden utilizar las funciones que están en las bibliotecas, lo que ahorra tiempo y esfuerzo.
- Modularidad: Al dividir el código en bibliotecas, se facilita la organización y mantenimiento del código.
- Abstracción: Las bibliotecas proporcionan una capa de abstracción lo que facilita el uso para los programadores, ya que se oculta la complejidad interna de las funciones.

Sus desventajas son:
- Dependencia: Los programas que utilizan a esas bibliotecas están vinculadas a las mismas, por ende cualquier cambio en las bibliotecas puede afectar a multiples programas.
- Tamaño del archivo ejecutable: Si se utilizan muchas bibliotecas, el tamaño del archivo ejecutable puede aumentar.
- Posibles problemas de compatibilidad: Las bibliotecas pueden tener diferentes versiones entre si, lo que puede causar problemas de compatibilidad en programas que las utilizan.

Referencia: https://es.wikipedia.org/wiki/Biblioteca_(informática)

