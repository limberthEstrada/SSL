#ifndef GRAFICADOR_H
#define GRAFICADOR_H

void graficar_histograma_horizontal(int *palabras);
void graficar_histograma_vertical(int *palabras);
void graficar_histograma_vertical_svg(struct dataset *data);
void graficar_histograma_horizontal_svg(struct dataset *data);
#endif 