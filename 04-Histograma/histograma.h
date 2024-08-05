#ifndef HISTOGRAMA_H
#define HISTOGRAMA_H

#define MAXIMA_LONGITUD 20

typedef struct dataset {
    int frecuenciaPalabras[MAXIMA_LONGITUD + 1];
    int cantidadDeCategorias;
    int longitudPalabra;
    const char *tituloDelGrafico;
    const char *tituloEjeY;
    const char *tituloEjeX;
} Dataset;

void histograma_enum_switch(struct dataset *data);
void histograma_goto(struct dataset *data);
void histograma_rec(struct dataset *data);
void histograma_x(struct dataset *data);

#endif 