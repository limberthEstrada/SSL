#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 100
#define MAX_COLOR_LENGTH 20

// Definición de los colores
const char* obtenerColor(const char* color) {
    if (strcmp(color, "rojo") == 0) return "red";
    if (strcmp(color, "verde") == 0) return "green";
    if (strcmp(color, "azul") == 0) return "blue";
    if (strcmp(color, "amarillo") == 0) return "yellow";
    if (strcmp(color, "negro") == 0) return "black";
    if (strcmp(color, "blanco") == 0) return "white";

    // Soporte para colores RGB
    if (strncmp(color, "rgb", 3) == 0) return color;
    
    return "black"; // Color por defecto
}

// Función para procesar un rectángulo
void procesarRecta(int x, int y, int alto, int ancho, const char* color) {
    printf("<rect x=\"%d\" y=\"%d\" height=\"%d\" width=\"%d\" fill=\"%s\" />\n", 
           x, y, alto, ancho, obtenerColor(color));
}

// Función para procesar un círculo
void procesarCirculo(int cx, int cy, int r, const char* color) {
    printf("<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"%s\" />\n", 
           cx, cy, r, obtenerColor(color));
}

// Función para procesar una elipse
void procesarElipse(int cx, int cy, int rx, int ry, const char* color) {
    printf("<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" fill=\"%s\" />\n", 
           cx, cy, rx, ry, obtenerColor(color));
}

// Función para procesar una línea
void procesarLinea(int x1, int y1, int x2, int y2, int grosor, const char* color) {
    printf("<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"%s\" stroke-width=\"%d\" />\n", 
           x1, y1, x2, y2, obtenerColor(color), grosor);
}

// Función principal para procesar la entrada
void procesarEntrada(const char* comando) {
    char figura;
    int x, y, alto, ancho, radio, radioX, radioY, x1, y1, x2, y2, grosor;
    char color[MAX_COLOR_LENGTH];

    if (sscanf(comando, "r %d %d %d %d %s", &x, &y, &alto, &ancho, color) == 5) {
        procesarRecta(x, y, alto, ancho, color);
    } else if (sscanf(comando, "c %d %d %d %s", &x, &y, &radio, color) == 4) {
        procesarCirculo(x, y, radio, color);
    } else if (sscanf(comando, "e %d %d %d %d %s", &x, &y, &radioX, &radioY, color) == 5) {
        procesarElipse(x, y, radioX, radioY, color);
    } else if (sscanf(comando, "l %d %d %d %d %s %d", &x1, &y1, &x2, &y2, color, &grosor) == 6) {
        procesarLinea(x1, y1, x2, y2, grosor, color);
    } else {
        printf("Comando inválido\n");
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Ingrese un comando:\n");
    while (fgets(input, MAX_INPUT_LENGTH, stdin)) {
        procesarEntrada(input);
    }

    return 0;
}
