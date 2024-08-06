#include <stdio.h>
#include "histograma.h"
#include "graficador.h"

void print_array2(int frecuenciaPalabras[]){
    for (int i = 0; i <= MAXIMA_LONGITUD; i++) {
        printf("%d,", frecuenciaPalabras[i]);
    }
    printf("\n");
}

enum Modo {
    HORIZONTAL,
    VERTICAL
};

void dibujarHistogramaHorizontalVacio(struct dataset *data){
	printf(
	"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
	"<svg width=\"100%\" height=\"100%\" xmlns=\"http://www.w3.org/2000/svg\">\n"
	"<style>\n"
		".bar { stroke: #333; stroke-width: 1; }\n"
		".axis { stroke: #333; stroke-width: 1; }\n"
		".label { font-family: Arial, sans-serif; font-size: 12px; }\n"
		".title { font-family: Arial, sans-serif; font-size: 16px; font-weight: bold; }\n"
	"</style>\n"

	"<text x=\"425\" y=\"30\" text-anchor=\"middle\" class=\"title\">%s</text>\n"

	"<text x=\"25\" y=\"150\" text-anchor=\"middle\" transform=\"rotate(-90 25,150)\" class=\"label\">%s</text>\n"
	"<text x=\"45\" y=\"250\" text-anchor=\"end\" class=\"label\">0</text>\n"
	"<line x1=\"50\" y1=\"250\" x2=\"800\" y2=\"250\" class=\"axis\" />\n"

	"<text x=\"425\" y=\"290\" text-anchor=\"middle\" class=\"label\">%s</text>\n"
	"<line x1=\"50\" y1=\"50\" x2=\"50\" y2=\"250\" class=\"axis\" />\n"
	"</svg>\n", data->tituloDelGrafico, data->tituloEjeX, data->tituloEjeY);
}

void dibujarEncabezadoHistograma(){
		printf(
		"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
		"<svg width=\"100%\" height=\"100%\" xmlns=\"http://www.w3.org/2000/svg\">\n"
		"<style>\n"
			".bar { stroke: #333; stroke-width: 1; }\n"
			".axis { stroke: #333; stroke-width: 1; }\n"
			".label { font-family: Arial, sans-serif; font-size: 12px; }\n"
			".title { font-family: Arial, sans-serif; font-size: 16px; font-weight: bold; }\n"
		"</style>\n");
}

void dubujarCierreHistograma(){
	printf("</svg>\n");
}

void dibujarEjeYConEtiquetasHorizontal(int cantidadDeCategorias, double extremoInferiorEjeY, struct dataset *data){
	double coordenadaYTitulo = 0;
	double coordenadaYEtiquetasDeFrecuencia = 56.25;

	for(int i=cantidadDeCategorias; i>0; i--){
		printf("<text x=\"45\" y=\"%.2f\" text-anchor=\"end\" dy=\"0.35em\" class=\"label\">%d</text>\n", coordenadaYEtiquetasDeFrecuencia, i);
		coordenadaYEtiquetasDeFrecuencia+=18.75;
	}

	printf("<line x1=\"50\" y1=\"50\" x2=\"50\" y2=\"%.2f\" class=\"axis\"/>\n", extremoInferiorEjeY);
	
	coordenadaYTitulo = ((extremoInferiorEjeY - 50)/2) + 50;

	if(cantidadDeCategorias < 9){
		printf("<text x=\"25\" y=\"50\" text-anchor=\"middle\" transform=\"rotate(-90 25,50)\" class=\"label\">%s</text>\n", data->tituloEjeY);
	} else {
		printf("<text x=\"25\" y=\"%.3f\" text-anchor=\"middle\" transform=\"rotate(-90 25,%.3f)\" class=\"label\">%s</text>\n", coordenadaYTitulo, coordenadaYTitulo, data->tituloEjeY);
	}
}

void dibujarEjeXConEtiquetasHorizontal(int frecuenciaPalabrasMaxima, double extremoInferiorEjeY, struct dataset *data){
	int extremoDerechoEjeX = 0;
	int coordenadaXEtiquetasBarra = 50;
	int coordenadaXTitulo = 0;

	coordenadaXTitulo = ((20 * frecuenciaPalabrasMaxima) / 2) + 50;

	if(frecuenciaPalabrasMaxima < 6){
		printf("<text x=\"50\" y=\"%.2f\" class=\"label\">%s</text>\n", extremoInferiorEjeY+40, data->tituloEjeX);
		printf("<text x=\"50\" y=\"30\" class=\"title\">%s</text>\n", data->tituloDelGrafico);
	} else {
		printf("<text x=\"%d\" y=\"%.2f\" text-anchor=\"middle\" class=\"label\">%s</text>\n", coordenadaXTitulo, extremoInferiorEjeY+40, data->tituloEjeX);
		printf("<text x=\"%d\" y=\"30\" text-anchor=\"middle\" class=\"title\">%s</text>\n", coordenadaXTitulo, data->tituloDelGrafico);
	}
	

	extremoDerechoEjeX = (20 * frecuenciaPalabrasMaxima) + 50;
	printf("<line x1=\"50\" y1=\"%.2f\" x2=\"%d\" y2=\"%.2f\" class=\"axis\"/>\n", extremoInferiorEjeY, extremoDerechoEjeX, extremoInferiorEjeY);

	for(int i=0; i<=frecuenciaPalabrasMaxima; i++){
		printf("<text x=\"%d\" y=\"%.2f\" text-anchor=\"middle\" class=\"label\">%d</text>\n", coordenadaXEtiquetasBarra, extremoInferiorEjeY+20, i);
		coordenadaXEtiquetasBarra += 20;
	}
}

void dibujarBarrasHistogramaHorizontal(int cantidadDeCategorias, int *frecuenciaPalabras){
	int anchoBarra = 0;
	double coordenadaYBarra = 50;

	for(int i=cantidadDeCategorias; i>0; i--){
		anchoBarra = frecuenciaPalabras[i] * 20;
		//printf("TEST CONTADOR: %d\n", i);
		printf("<rect x=\"50\" y=\"%.2f\" width=\"%d\" height=\"12.5\" rx=\"5\" class=\"bar\" fill=\"#FBBC05\" />\n", coordenadaYBarra, anchoBarra);
		coordenadaYBarra+=18.75;
	}
}

void graficar_histograma_horizontal_svg(struct dataset *data){
	int i, frecuenciaPalabrasMaxima = 0;
	double extremoInferiorEjeY = data->cantidadDeCategorias * 18.75 + 50;
	
	data->tituloEjeY = "Longitud de palabras (categoria)";
	data->tituloEjeX = "Frecuencia de palabras";
	
	frecuenciaPalabrasMaxima = data->frecuenciaPalabras[1];
	for(i = 1; i <= MAXIMA_LONGITUD; i++){
		if (data->frecuenciaPalabras[i] > frecuenciaPalabrasMaxima)
			frecuenciaPalabrasMaxima = data->frecuenciaPalabras[i];
	}

	if(frecuenciaPalabrasMaxima == 0){
		dibujarHistogramaHorizontalVacio(data);
	}
	else{
		dibujarEncabezadoHistograma();
		dibujarEjeYConEtiquetasHorizontal(data->cantidadDeCategorias, extremoInferiorEjeY, data);
		dibujarEjeXConEtiquetasHorizontal(frecuenciaPalabrasMaxima, extremoInferiorEjeY, data);
		//dibujarBarrasHistogramaHorizontal(frecuenciaPalabrasMaxima, data->frecuenciaPalabras);
		dibujarBarrasHistogramaHorizontal(data->cantidadDeCategorias, data->frecuenciaPalabras);
		dubujarCierreHistograma();
	}

}

void graficar_histograma_horizontal(int *frecuenciaPalabras){
    int i, j = 0;
    for(i = 1; i <= MAXIMA_LONGITUD; i++){ 
            printf("\n%d\t", i);
            for(j = 0; j < frecuenciaPalabras[i]; j++)
                printf("*"); 

            if (frecuenciaPalabras[i] == 0)
                printf(" ");   
    }
}

void graficar_histograma_vertical(int *frecuenciaPalabras){
    int i, j, maximo = 0;

    maximo = frecuenciaPalabras[1];

	for(i = 1; i <= MAXIMA_LONGITUD; i++){
		if (frecuenciaPalabras[i] > maximo)
			maximo = frecuenciaPalabras[i];
	}
	
	for (i = maximo; i > 0; i--){
		for(j = 1; j <= MAXIMA_LONGITUD; j++){
			if(frecuenciaPalabras[j] >= i)
				printf("*\t");
            else
                printf("\t");
		}
		printf("\n");
	}
	
	for(i = 1; i <= MAXIMA_LONGITUD; i++)
		printf("%d\t", i);
}

//Gráfico SVG -----------------------------------------------------------------------------------------
void dibujarHistogramaVerticalVacio(struct dataset *data){
	printf(
	"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
	"<svg width=\"100%\" height=\"100%\" xmlns=\"http://www.w3.org/2000/svg\">\n"
	"<style>\n"
		".bar { stroke: #333; stroke-width: 1; }\n"
		".axis { stroke: #333; stroke-width: 1; }\n"
		".label { font-family: Arial, sans-serif; font-size: 12px; }\n"
		".title { font-family: Arial, sans-serif; font-size: 16px; font-weight: bold; }\n"
	"</style>\n"

	"<text x=\"425\" y=\"30\" text-anchor=\"middle\" class=\"title\">%s</text>\n"

	"<text x=\"25\" y=\"150\" text-anchor=\"middle\" transform=\"rotate(-90 25,150)\" class=\"label\">%s</text>\n"
	"<text x=\"45\" y=\"250\" text-anchor=\"end\" class=\"label\">0</text>\n"
	"<line x1=\"50\" y1=\"250\" x2=\"800\" y2=\"250\" class=\"axis\" />\n"

	"<text x=\"425\" y=\"290\" text-anchor=\"middle\" class=\"label\">%s</text>\n"
	"<line x1=\"50\" y1=\"50\" x2=\"50\" y2=\"250\" class=\"axis\" />\n"
	"</svg>\n", data->tituloDelGrafico, data->tituloEjeY, data->tituloEjeX);
}

void dibujarEjeYConEtiquetasVertical(int frecuenciaPalabrasMaxima, int *coordenadaYEtiquetasDeFrecuencia, struct dataset *data){
	int coordenadaYTitulo = 0;
	
	for(int i=frecuenciaPalabrasMaxima; i>=0; i--){
		if(i!=0){
			printf("<text x=\"45\" y=\"%d\" text-anchor=\"end\" class=\"label\">%d</text>", (*coordenadaYEtiquetasDeFrecuencia), i);
			(*coordenadaYEtiquetasDeFrecuencia)+=20;
		}	
		else {
			printf("<text x=\"45\" y=\"%d\" text-anchor=\"end\" class=\"label\">%d</text>", (*coordenadaYEtiquetasDeFrecuencia), i);
		}
	}

	printf("<line x1=\"50\" y1=\"50\" x2=\"50\" y2=\"%d\" class=\"axis\"/>\n", (*coordenadaYEtiquetasDeFrecuencia));
	

	coordenadaYTitulo = (((*coordenadaYEtiquetasDeFrecuencia) - 50)/2) + 50;
	
	//Para que no desborde
	if(frecuenciaPalabrasMaxima < 6) {
		printf("<text x=\"25\" y=\"50\" text-anchor=\"end\" transform=\"rotate(-90 25,50)\" class=\"label\">%s</text>\n", data->tituloEjeY);	
	} else {
		printf("<text x=\"25\" y=\"%d\" text-anchor=\"middle\" transform=\"rotate(-90 25,%d)\" class=\"label\">%s</text>\n", coordenadaYTitulo, coordenadaYTitulo, data->tituloEjeY);
	}
}

//No se como voy a pasar (*coordenadaYEtiquetasDeFrecuencia), quizas global :v
void dibujarEjeXConEtiquetasVertical(int cantidadDeCategorias, int coordenadaYEtiquetasDeFrecuencia, struct dataset *data){
	int extremoDerechoEjeX = 0;
	int coordenadaXEtiquetasBarra = 100;
	int coordenadaXTitulo = 0;

	coordenadaXTitulo = ((25*cantidadDeCategorias + 50*cantidadDeCategorias) / 2) + 50;
	
	if(cantidadDeCategorias < 2){
		printf("<text x=\"50\" y=\"%d\" class=\"label\">%s</text>\n", coordenadaYEtiquetasDeFrecuencia+40, data->tituloEjeX);
		printf("<text x=\"50\" y=\"30\" class=\"title\">%s</text>\n", data->tituloDelGrafico);
	} else {
		printf("<text x=\"%d\" y=\"%d\" text-anchor=\"middle\" class=\"label\">%s</text>\n", coordenadaXTitulo, coordenadaYEtiquetasDeFrecuencia+40, data->tituloEjeX);
		printf("<text x=\"%d\" y=\"30\" text-anchor=\"middle\" class=\"title\">%s</text>\n", coordenadaXTitulo, data->tituloDelGrafico);
	}

	extremoDerechoEjeX = (25*cantidadDeCategorias + 50*cantidadDeCategorias) + 50;
	printf("<line x1=\"50\" y1=\"%d\" x2=\"%d\" y2=\"%d\" class=\"axis\"/>\n", coordenadaYEtiquetasDeFrecuencia, extremoDerechoEjeX, coordenadaYEtiquetasDeFrecuencia);

	for(int i=1; i<=cantidadDeCategorias; i++){
		printf("<text x=\"%d\" y=\"%d\" text-anchor=\"middle\" class=\"label\">%d</text>\n", coordenadaXEtiquetasBarra, coordenadaYEtiquetasDeFrecuencia+20, i);
		coordenadaXEtiquetasBarra += 75;
	}
}

void dibujarBarrasHistogramaVertical(int cantidadDeCategorias, int coordenadaYEtiquetasDeFrecuencia, int *frecuenciaPalabras){
  int ejeXBarra = 75;
  int alturaBarra = 0;
  int coordenadaYBarra = 0;

  for(int i=1; i <= cantidadDeCategorias; i++){
	coordenadaYBarra = coordenadaYEtiquetasDeFrecuencia - (20 * frecuenciaPalabras[i]);
	alturaBarra = 20 * frecuenciaPalabras[i];
	printf("<rect x=\"%d\" y=\"%d\" width=\"50\" height=\"%d\" rx=\"5\" class=\"bar\" fill=\"#FBBC05\"/>\n", ejeXBarra, coordenadaYBarra, alturaBarra);
	ejeXBarra += 75;
  }
}

void graficar_histograma_vertical_svg(struct dataset *data){
	int i, frecuenciaPalabrasMaxima = 0;
	int coordenadaYEtiquetasDeFrecuencia = 50;
    
	data->tituloEjeX = "Longitud de palabras (categoria)";
	data->tituloEjeY = "Frecuencia de palabras";
	frecuenciaPalabrasMaxima = data->frecuenciaPalabras[1];

	for(i = 1; i <= MAXIMA_LONGITUD; i++){
		if (data->frecuenciaPalabras[i] > frecuenciaPalabrasMaxima)
			frecuenciaPalabrasMaxima = data->frecuenciaPalabras[i];
	}

	if(frecuenciaPalabrasMaxima == 0){
		dibujarHistogramaVerticalVacio(data);
	}
	else{
		dibujarEncabezadoHistograma();
		dibujarEjeYConEtiquetasVertical(frecuenciaPalabrasMaxima, &coordenadaYEtiquetasDeFrecuencia, data);
		dibujarEjeXConEtiquetasVertical(data->cantidadDeCategorias, coordenadaYEtiquetasDeFrecuencia, data);
		dibujarBarrasHistogramaVertical(data->cantidadDeCategorias, coordenadaYEtiquetasDeFrecuencia, data->frecuenciaPalabras);
		dubujarCierreHistograma();
	}

}
