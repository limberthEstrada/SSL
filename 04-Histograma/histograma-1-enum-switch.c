#include <stdio.h>
#include "histograma.h"

typedef enum { IN, OUT } State;

void histograma_enum_switch(struct dataset *data) {
    int caracter, i;
    State estado = OUT;

    data->longitudPalabra = 0;

    for (i = 0; i <= MAXIMA_LONGITUD; i++)
        data->frecuenciaPalabras[i] = 0;

    while ((caracter = getchar()) != EOF) {
        switch (estado) {
            case IN:
                switch (caracter) {
                    case ' ':
                    case '\n':
                    case '\t':
                        estado = OUT;

                        switch (data->longitudPalabra <= data->cantidadDeCategorias) {
                            case 1:
                                ++data->frecuenciaPalabras[data->longitudPalabra];
                            break;
                        }
                        data->longitudPalabra = 0;
                    break;
                    default:
                        ++data->longitudPalabra;
                    break;
                }
            break;

            case OUT:
                switch (caracter) {
                    case ' ':
                    case '\n':
                    case '\t':
                    break;
                    
                    default:
                        estado = IN;
                        ++data->longitudPalabra;
                    break;
                }
            break;
        }
    }

    switch (estado) {
        case IN:
            switch (data->longitudPalabra <= data->cantidadDeCategorias) {
                case 1:
                    ++data->frecuenciaPalabras[data->longitudPalabra];
                break;
            }
        break;

        case OUT:
        break;
    }
}