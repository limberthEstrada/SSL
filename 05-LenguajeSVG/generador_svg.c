#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 100
#define MAX_COLOR_LENGTH 20

// Enumeración para representar las figura
typedef enum {
    RECTA,
    CIRCULO,
    ELIPSE,
    LINEA,
    INVALIDO,
    VALIDO
} Figura;

typedef struct {
    int x, y, alto, ancho, radio, radioX, radioY, x1, y1, x2, y2, grosor;
    char color[MAX_COLOR_LENGTH];
} AtributosFigura;

Figura obtenerFigura(const char comando) {
    if (comando == 'r') return RECTA;
    if (comando == 'c') return CIRCULO;
    if (comando == 'e') return ELIPSE;
    if (comando == 'l') return LINEA;
    return INVALIDO;
}

// Definición de los colores
const char* obtenerColor(const char* color) {
    if (strcmp(color, "rojo") == 0) return "red";
    if (strcmp(color, "verde") == 0) return "green";
    if (strcmp(color, "azul") == 0) return "blue";
    if (strcmp(color, "amarillo") == 0) return "yellow";
    if (strcmp(color, "negro") == 0) return "black";
    if (strcmp(color, "blanco") == 0) return "white";
    
    return "black"; // Color por defecto
}

// Verifica si toda la entrada ha sido procesada correctamente sin caracteres adicionales
int esEntradaCompleta(const char* comando, int caracteresLeidos) {
    return comando[caracteresLeidos] == '\0';  // Devuelve 1 si es verdadero, 0 si es falso
}

// Función principal para procesar la entrada
void procesarEntrada(const char* comando) {
    char encabezadoComando;
    AtributosFigura atributo;
    int caracteresLeidos;

    sscanf(comando, "%c", &encabezadoComando); // sscanf es una función que lee y analiza datos desde una cadena que ya esta en memoria, y los valores extraidos los almacena en variables que se pasan como argumento. Y retorna el número de variables a las que se le asignaron valores
    
    switch(obtenerFigura(encabezadoComando)){
        case RECTA:
            if (sscanf(comando, "%*c %d %d %d %d %s %n", &atributo.x, &atributo.y, &atributo.alto, &atributo.ancho, atributo.color, &caracteresLeidos) == 5 && esEntradaCompleta(comando, caracteresLeidos)){
                printf("<rect x=\"%d\" y=\"%d\" height=\"%d\" width=\"%d\" fill=\"%s\" />\n", atributo.x, atributo.y, atributo.alto, atributo.ancho, obtenerColor(atributo.color));
            }
            else{
                printf("Los atributos ingresados no son validos\n");
            }
        break;

        case CIRCULO:
            if (sscanf(comando, "%*c %d %d %d %s %n", &atributo.x, &atributo.y, &atributo.radio, atributo.color, &caracteresLeidos) == 4 && esEntradaCompleta(comando, caracteresLeidos)){
                printf("<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"%s\" />\n", atributo.x, atributo.y, atributo.radio, obtenerColor(atributo.color));            
            }
            else{
                printf("Los atributos ingresados no son validos\n");
            }
        break;

        case ELIPSE:
            if (sscanf(comando, "%*c %d %d %d %d %s %n", &atributo.x, &atributo.y, &atributo.radioX, &atributo.radioY, atributo.color, &caracteresLeidos) == 5 && esEntradaCompleta(comando, caracteresLeidos)){
                printf("<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" fill=\"%s\" />\n", atributo.x, atributo.y, atributo.radioX, atributo.radioY, obtenerColor(atributo.color));
            }
            else{
                printf("Los atributos ingresados no son validos\n");
            }
        break;

        case LINEA:
            if (sscanf(comando, "%*c %d %d %d %d %s %d %n", &atributo.x1, &atributo.y1, &atributo.x2, &atributo.y2, atributo.color, &atributo.grosor, &caracteresLeidos) == 6 && esEntradaCompleta(comando, caracteresLeidos)){
                printf("<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"%s\" stroke-width=\"%d\" />\n", atributo.x1, atributo.y1, atributo.x2, atributo.y2, obtenerColor(atributo.color), atributo.grosor);
            }
            else{
                printf("Los atributos ingresados no son validos\n");
            }
        break;

        case INVALIDO:
            printf("Lo que ingreso no es una figura valida\n");
        break;
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Ingrese un comando:\n");
    while (fgets(input, MAX_INPUT_LENGTH, stdin)) { // 'fgets' es una función para leer una línea de texto desde el flujo de entrada y almacenarla en un array de char, termina cuando encuentra salto de linea o EOF
        procesarEntrada(input);
    }

    return 0;
}
