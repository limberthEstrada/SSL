#include <stdio.h>
#include "histograma.h"

#define NUM_ESTADOS 2
#define NUM_ENTRADAS 4

typedef enum { IN, OUT } State;
typedef enum { ESPACIO, NUEVA_LINEA, TABULADOR, OTRO } Entrada;

typedef struct {
    State siguiente_estado;
    void (*accion)(struct dataset *);
} Transicion;

void accion_fuera(struct dataset *data);
void accion_dentro(struct dataset *data);

Transicion tabla_transiciones[NUM_ESTADOS][NUM_ENTRADAS] = {
    [OUT][ESPACIO]     = {OUT, accion_fuera},
    [OUT][NUEVA_LINEA] = {OUT, accion_fuera},
    [OUT][TABULADOR]   = {OUT, accion_fuera},
    [OUT][OTRO]        = {IN, accion_dentro},
    [IN][ESPACIO]      = {OUT, accion_fuera},
    [IN][NUEVA_LINEA]  = {OUT, accion_fuera},
    [IN][TABULADOR]    = {OUT, accion_fuera},
    [IN][OTRO]         = {IN, accion_dentro}
};

Entrada obtener_entrada(int c) {
    if (c == ' ') return ESPACIO;
    if (c == '\n') return NUEVA_LINEA;
    if (c == '\t') return TABULADOR;
    return OTRO;
}

void accion_fuera(struct dataset *data) {
    if (data->longitudPalabra > 0 && data->longitudPalabra <= data->cantidadDeCategorias) {
        ++data->frecuenciaPalabras[data->longitudPalabra];
    }
    data->longitudPalabra = 0;
}

void accion_dentro(struct dataset *data) {
    ++(data->longitudPalabra);
}

void histograma_x(struct dataset *data) {
    int caracter, i;
    State estado = OUT;
    data->longitudPalabra = 0;

    for (i = 0; i <= MAXIMA_LONGITUD; i++)
        data->frecuenciaPalabras[i] = 0;

    while ((caracter = getchar()) != EOF) {
        Entrada entrada = obtener_entrada(caracter);
        
        Transicion t = tabla_transiciones[estado][entrada];
        t.accion(data);
        estado = t.siguiente_estado;
    }

    if (estado == IN && data->longitudPalabra <= data->cantidadDeCategorias) {
        ++data->frecuenciaPalabras[data->longitudPalabra];
    }
}
