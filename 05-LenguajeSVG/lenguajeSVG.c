#include <stdio.h>
#include <string.h>
// Notas: Será parametrizable solamente el ancho o alto, posiciones, radio, etc.
// [Molde comando figuras SVG]
// Recta: (Figura posX posY alto ancho color) -> r 10 10 10 20 azul
// Circulo: (Figura posX posY radio color) -> c 10 10 20 rojo
// Elipse: (Figura posX posY radioX radioY color) -> e 10 10 20 20 negro
// Linea: (Figura posX1 posY1 posX2 posY2 color grosor) -> l 10 10 20 20 rojo 3



/*int main() {
    int caracter;

    while((caracter = getchar()) != EOF){

    }    
    return 0;
}*/
#define MAX_WORD_LENGTH 20

// Palabras clave
typedef enum {
    RECTA,
    CIRCULO,
    ELIPSE,
    LINEA,
    INVALIDO,
    VALIDO
} Figura;

// Función para convertir la cadena a un valor del enum
Figura obtenerFigura(const char comando) {
    if (comando == 'r') return RECTA;
    if (comando == 'c') return CIRCULO;
    if (comando == 'e') return ELIPSE;
    if (comando == 'l') return LINEA;
    return INVALIDO;
}

const char* obtenerColor(const char* color) {
    if (strcmp(color, "rojo") == 0) return "red";
    if (strcmp(color, "verde") == 0) return "green";
    if (strcmp(color, "azul") == 0) return "blue";
    if (strcmp(color, "amarillo") == 0) return "yellow";
    if (strcmp(color, "negro") == 0) return "black";
    if (strcmp(color, "blanco") == 0) return "white";
    return "black"; // Si no se encuentra el color, se devuelve el por defecto
}

int main() {
    int x, y, alto, ancho, radio, radioX, radioY, x1, x2, y1, y2, grosor;
    char color[MAX_WORD_LENGTH];
    char comando;
    Figura figura = VALIDO;

    printf("Ingrese un comando:\n");
    while(figura != INVALIDO && scanf(" %c", &comando) != EOF){
    //while(scanf("%c %d %d %s", forma, &alto, &ancho, color) == 4) {
        figura = obtenerFigura(comando);
        
        switch(figura) {
            case RECTA:
                printf("Procesando una recta:\n");
                scanf("%d %d %d %d %s", &x, &y, &alto, &ancho, color);

                printf("<rect x=\"%d\" y=\"%d\" height=\"%d\" width=\"%d\" fill=\"%s\" />\n", x, y, alto, ancho, obtenerColor(color));
                printf("\n");
                break;
            case CIRCULO:
                printf("Procesando un circulo:\n");
                scanf("%d %d %d %s", &x, &y, &radio, color);

                printf("<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"%s\" />\n", x, y, radio, obtenerColor(color));
                printf("\n");
                break;
            case ELIPSE:
                printf("Procesando una elipse:\n");
                scanf("%d %d %d %d %s", &x, &y, &radioX, &radioY, color);

                printf("<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" fill=\"%s\" />\n", x, y, radioX, radioY, obtenerColor(color));
                printf("\n");
                break;
            case LINEA:
                printf("Procesando una linea:\n");
                scanf("%d %d %d %d %s %d", &x1, &x2, &y1, &y2, color, grosor);

                printf("<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"%s\" stroke-width=\"%d\" />\n", x1, y1, x2, y2, obtenerColor(color), grosor);
                printf("\n");
                break;
            case INVALIDO:
                printf("Lo que ingreso no es una instruccion valida\n");
                break;
        }
    }   
 
    return 0;
}