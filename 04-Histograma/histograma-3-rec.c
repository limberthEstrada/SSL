#include <stdio.h>
#include "histograma.h"

void fuera_palabra(struct dataset *data);
void dentro_palabra(struct dataset *data);

void fuera_palabra(struct dataset *data) {
    int caracter;

    if ((caracter = getchar()) == EOF)
        return;
    if (caracter != ' ' && caracter != '\n' && caracter != '\t') {
        ++(data->longitudPalabra);
        dentro_palabra(data);
    } else {
        fuera_palabra(data);
    }
}

void dentro_palabra(struct dataset *data) {
    int caracter;
    
    if ((caracter = getchar()) == EOF) {
        if (data->longitudPalabra <= data->cantidadDeCategorias)
            ++data->frecuenciaPalabras[data->longitudPalabra];
        return;
    }
    if (caracter == ' ' || caracter == '\n' || caracter == '\t') {
        if (data->longitudPalabra <= data->cantidadDeCategorias)
            ++data->frecuenciaPalabras[data->longitudPalabra];
        data->longitudPalabra = 0;
        fuera_palabra(data);
    } else {
        ++(data->longitudPalabra);
        dentro_palabra(data);
    }
}

void histograma_rec(struct dataset *data) {
    int i;
    data->longitudPalabra = 0;

    for (i = 0; i <= MAXIMA_LONGITUD; i++)
        data->frecuenciaPalabras[i] = 0;

    fuera_palabra(data);
}