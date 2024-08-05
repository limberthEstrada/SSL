#include <stdio.h>
#include <assert.h>
#include "histograma.h"

void copiar_array(int frecuenciaPalabras[], int resultados[]) {
    for (int i = 0; i <= MAXIMA_LONGITUD; i++) {
        resultados[i] = frecuenciaPalabras[i];
    }
}

void reiniciar_array(int palabras[]) {
    for (int i = 0; i <= MAXIMA_LONGITUD; i++) {
        palabras[i] = 0;
    }
}

void print_array(int palabras[]){
    for (int i = 0; i <= MAXIMA_LONGITUD; i++) {
        printf("%d,", palabras[i]);
    }
    printf("\n");
}

int comparar_resultados(int resultados[][MAXIMA_LONGITUD + 1], int cantidadFilas, int cantidadColumnas) {
    for (int i = 0; i < cantidadFilas; i++) {
        for (int j = 0; j < cantidadColumnas; j++) {
            if (resultados[i][j] != resultados[0][j]) {
                return 0;  // Retorna 0 (falso) si alguna fila es diferente
            }
        }
    }
    return 1;  // Retorna 1 (verdadero) si todas las filas son iguales
}

void ejecutar_implementacion(void (*implementacion)(struct dataset *), int numImplementacion, int resultados[][MAXIMA_LONGITUD + 1], struct dataset *data) {
    rewind(stdin);  // Vuelve al inicio del archivo de entrada, esto lo pusé porque la primera implementación si lee de stdin, pero al leerlo todo no es posible volver al inicio para las siguientes implementaciones.
    implementacion(data);
    copiar_array(data->frecuenciaPalabras, resultados[numImplementacion-1]);
    reiniciar_array(data->frecuenciaPalabras);
}

int main() {
    Dataset data;
    data.cantidadDeCategorias = 10;
    //Son 4 por cada implementación, da la posibilidad de escalarlo en caso
    //de existir nuevas implementaciones
    int resultados[4][MAXIMA_LONGITUD + 1];

    /*histograma_enum_switch();
    copiar_array(palabras, resultados[0]);
    reiniciar_array(palabras);
    //print_array(resultados[0]);

    histograma_goto();
    copiar_array(palabras, resultados[1]);
    reiniciar_array(palabras);
    //print_array(resultados[1]);

    histograma_rec();
    copiar_array(palabras, resultados[2]);
    reiniciar_array(palabras);
    //print_array(resultados[2]);

    histograma_x();
    copiar_array(palabras, resultados[3]);
    reiniciar_array(palabras);
    //print_array(resultados[3]);*/

    ejecutar_implementacion(histograma_enum_switch, 1, resultados, &data);
    ejecutar_implementacion(histograma_goto, 2, resultados, &data);
    ejecutar_implementacion(histograma_rec, 3, resultados, &data);
    ejecutar_implementacion(histograma_x, 4, resultados, &data);

    assert(comparar_resultados(resultados, 4, MAXIMA_LONGITUD+1));
    printf("Este test paso las pruebas sin errores!\n");

    return 0;
}