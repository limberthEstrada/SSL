#include <stdio.h>
#include "histograma.h"

void histograma_goto(struct dataset *data) {
    int caracter, i;
    data->longitudPalabra = 0;

    for (i = 0; i <= MAXIMA_LONGITUD; i++)
        data->frecuenciaPalabras[i] = 0;

OutState:
    if ((caracter = getchar()) == EOF) 
        goto ProcessLastWord;

    if (caracter == ' ' || caracter == '\n' || caracter == '\t')
        goto OutState;

    ++data->longitudPalabra;
    goto InState;

InState:
    if ((caracter = getchar()) == EOF)
        goto ProcessLastWord;

    if (caracter == ' ' || caracter == '\n' || caracter == '\t') {
        if (data->longitudPalabra <= data->cantidadDeCategorias) {
            ++data->frecuenciaPalabras[data->longitudPalabra]; 
        }
        data->longitudPalabra = 0;
        goto OutState;
    }

    if (data->longitudPalabra < MAXIMA_LONGITUD)
        ++data->longitudPalabra;
    
    goto InState;

ProcessLastWord:
    if (data->longitudPalabra <= data->cantidadDeCategorias) {
        if (data->longitudPalabra > 0) {
            ++data->frecuenciaPalabras[data->longitudPalabra];
        }
    }
}