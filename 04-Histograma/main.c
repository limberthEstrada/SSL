#include <stdio.h>
#include <string.h>
#include "histograma.h"
#include "graficador.h"

int main(int argc, char *argv[]) {
    Dataset data;
    
    //Seria la categoria a la cual el usuario quiere visualizar, se supone que tiene que ser menor o igual a
    //MAXIMA_LONGITUD
    data.cantidadDeCategorias = 10;

    if (argc != 3) {
        printf("==============================================================\n");
        printf("Ingrese en consola la implementacion y orientacion deseada.\n");
        printf("==============================================================\n");
        printf("Implementaciones disponibles: enum-switch, goto, rec, tabla\n");
        printf("Orientaciones disponibles: horizontal, vertical\n");
        printf("==============================================================\n");
        printf("\n");
        printf("Recorda que la longitud maxima de palabra (categoria) es: %d\n", data.cantidadDeCategorias);
        
        return 1;
    }

    //Descomentar cuando quieres realizar el benchmark
    /*if (argc != 2) {
        printf("No se pasó los argumentos necesarios");
        return 1;
    }*/

    if (strcmp(argv[1], "enum-switch") == 0) {
        histograma_enum_switch(&data);
    } else if (strcmp(argv[1], "goto") == 0) {
        histograma_goto(&data);
    } else if (strcmp(argv[1], "rec") == 0) {
        histograma_rec(&data);
    } else if (strcmp(argv[1], "tabla") == 0) {
        histograma_x(&data);
    } else {
        printf("Implementacion no valida: %s\n", argv[1]);
        return 1;
    }

    if (strcmp(argv[2], "horizontal") == 0) {
        data.tituloDelGrafico = "Histograma - Horizontal";
        graficar_histograma_horizontal_svg(&data);
    } else if (strcmp(argv[2], "vertical") == 0) {
        data.tituloDelGrafico = "Histograma - Vertical";
        graficar_histograma_vertical_svg(&data);
    } else {
        printf("Orientacion no valida: %s\n", argv[2]);
        return 1;
    }

    return 0;
}