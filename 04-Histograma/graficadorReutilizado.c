#include <stdio.h>
#include "histograma.h"
#include "graficador.h"

enum Modo {
    HORIZONTAL,
    VERTICAL
};

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

void dibujarHistogramaVacio(enum Modo modo, struct dataset *data){
    if (modo == HORIZONTAL) {
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
    } else if (modo == VERTICAL) {
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
}

void dibujarEjeXConEtiquetas(enum Modo modo, int frecuenciaPalabrasMaxima, double extremoInferiorEjeY, int cantidadDeCategorias, int coordenadaYEtiquetasDeFrecuencia, struct dataset *data)
{
    if (modo == HORIZONTAL) {
        int extremoDerechoEjeX = 0;
        int coordenadaXEtiquetasBarra = 50;
        int coordenadaXTitulo = 0;

        coordenadaXTitulo = ((20 * frecuenciaPalabrasMaxima) / 2) + 50;
        printf("<text x=\"%d\" y=\"%.2f\" text-anchor=\"middle\" class=\"label\">%s</text>\n", coordenadaXTitulo, extremoInferiorEjeY+40, data->tituloEjeX);
        printf("<text x=\"%d\" y=\"30\" text-anchor=\"middle\" class=\"title\">%s</text>\n", coordenadaXTitulo, data->tituloDelGrafico);

        extremoDerechoEjeX = (20 * frecuenciaPalabrasMaxima) + 50;
        printf("<line x1=\"50\" y1=\"%.2f\" x2=\"%d\" y2=\"%.2f\" class=\"axis\"/>\n", extremoInferiorEjeY, extremoDerechoEjeX, extremoInferiorEjeY);

        for(int i=0; i<=frecuenciaPalabrasMaxima; i++){
            printf("<text x=\"%d\" y=\"%.2f\" text-anchor=\"middle\" class=\"label\">%d</text>\n", coordenadaXEtiquetasBarra, extremoInferiorEjeY+20, i);
            coordenadaXEtiquetasBarra += 20;
        }
    } else if (modo == VERTICAL) {
        int extremoDerechoEjeX = 0;
        int coordenadaXEtiquetasBarra = 100;
        int coordenadaXTitulo = 0;

        coordenadaXTitulo = ((25*cantidadDeCategorias + 50*cantidadDeCategorias) / 2) + 50;
        printf("<text x=\"%d\" y=\"%d\" text-anchor=\"middle\" class=\"label\">%s</text>\n", coordenadaXTitulo, coordenadaYEtiquetasDeFrecuencia+40, data->tituloEjeX);
        printf("<text x=\"%d\" y=\"30\" text-anchor=\"middle\" class=\"title\">%s</text>\n", coordenadaXTitulo, data->tituloDelGrafico);

        extremoDerechoEjeX = (25*cantidadDeCategorias + 50*cantidadDeCategorias) + 50;
        printf("<line x1=\"50\" y1=\"%d\" x2=\"%d\" y2=\"%d\" class=\"axis\"/>\n", coordenadaYEtiquetasDeFrecuencia, extremoDerechoEjeX, coordenadaYEtiquetasDeFrecuencia);

        for(int i=1; i<=cantidadDeCategorias; i++){
            printf("<text x=\"%d\" y=\"%d\" text-anchor=\"middle\" class=\"label\">%d</text>\n", coordenadaXEtiquetasBarra, coordenadaYEtiquetasDeFrecuencia+20, i);
            coordenadaXEtiquetasBarra += 75;
        }
    }
}

void dibujarEjeYConEtiquetas(enum Modo modo, int cantidadDeCategorias, double extremoInferiorEjeY, int frecuenciaPalabrasMaxima, int *coordenadaYEtiquetasDeFrecuencia, struct dataset *data){
    if (modo == HORIZONTAL) {
        double coordenadaYTitulo = 0;
        double coordenadaYEtiquetasDeFrecuencia = 56.25;

        for(int i=cantidadDeCategorias; i>0; i--){
            printf("<text x=\"45\" y=\"%.2f\" text-anchor=\"end\" dy=\"0.35em\" class=\"label\">%d</text>\n", coordenadaYEtiquetasDeFrecuencia, i);
            coordenadaYEtiquetasDeFrecuencia+=18.75;
        }

        printf("<line x1=\"50\" y1=\"50\" x2=\"50\" y2=\"%.2f\" class=\"axis\"/>\n", extremoInferiorEjeY);
        
        coordenadaYTitulo = ((extremoInferiorEjeY - 50)/2) + 50;
        printf("<text x=\"25\" y=\"%.3f\" text-anchor=\"middle\" transform=\"rotate(-90 25,%.3f)\" class=\"label\">%s</text>\n", coordenadaYTitulo, coordenadaYTitulo, data->tituloEjeY);
    } else if (modo == VERTICAL) {
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
        printf("<text x=\"25\" y=\"%d\" text-anchor=\"middle\" transform=\"rotate(-90 25,%d)\" class=\"label\">%s</text>\n", coordenadaYTitulo, coordenadaYTitulo, data->tituloEjeY);
    }
}

void dibujarBarrasHistograma(enum Modo modo, int cantidadDeCategorias, int *frecuenciaPalabras, int coordenadaYEtiquetasDeFrecuencia){
    if (modo == HORIZONTAL) {
        int anchoBarra = 0;
        double coordenadaYBarra = 50;

        for(int i=cantidadDeCategorias; i>0; i--){
            anchoBarra = frecuenciaPalabras[i] * 20;
            //printf("TEST CONTADOR: %d\n", i);
            printf("<rect x=\"50\" y=\"%.2f\" width=\"%d\" height=\"12.5\" rx=\"5\" class=\"bar\" fill=\"#FBBC05\" />\n", coordenadaYBarra, anchoBarra);
            coordenadaYBarra+=18.75;
        }
    } else if (modo == VERTICAL) {
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
}

void graficarHistogramaSVG(enum Modo modo, struct dataset *data){
    int i, frecuenciaPalabrasMaxima = 0;
    double extremoInferiorEjeY = data->cantidadDeCategorias * 18.75 + 50;
    int i, frecuenciaPalabrasMaxima = 0;
    int coordenadaYEtiquetasDeFrecuencia = 50;

    frecuenciaPalabrasMaxima = data->frecuenciaPalabras[1];
    
    for(i = 1; i <= MAXIMA_LONGITUD; i++){
        if (data->frecuenciaPalabras[i] > frecuenciaPalabrasMaxima)
            frecuenciaPalabrasMaxima = data->frecuenciaPalabras[i];
    }

    if (modo == HORIZONTAL) {
        data->tituloEjeY = "Longitud de palabras (categoria)";
        data->tituloEjeX = "Frecuencia de palabras";
        
        if(frecuenciaPalabrasMaxima == 0){
            dibujarHistogramaVacio(HORIZONTAL, data);
        }
        else{
            dibujarEncabezadoHistograma();
            dibujarEjeYConEtiquetas(HORIZONTAL, data->cantidadDeCategorias, extremoInferiorEjeY, frecuenciaPalabrasMaxima, &coordenadaYEtiquetasDeFrecuencia, data);
            dibujarEjeXConEtiquetas(HORIZONTAL, frecuenciaPalabrasMaxima, extremoInferiorEjeY, data->cantidadDeCategorias, coordenadaYEtiquetasDeFrecuencia, data);
            dibujarBarrasHistograma(HORIZONTAL, data->cantidadDeCategorias, data->frecuenciaPalabras, coordenadaYEtiquetasDeFrecuencia);
            dubujarCierreHistograma();
        }
    } else if (modo == VERTICAL) {
        data->tituloEjeX = "Longitud de palabras (categoria)";
        data->tituloEjeY = "Frecuencia de palabras";

        if(frecuenciaPalabrasMaxima == 0){
            dibujarHistogramaVacio(VERTICAL, data);
        }
        else{
            dibujarEncabezadoHistograma();
            dibujarEjeYConEtiquetas(VERTICAL, data->cantidadDeCategorias, extremoInferiorEjeY, frecuenciaPalabrasMaxima, &coordenadaYEtiquetasDeFrecuencia, data);
            dibujarEjeXConEtiquetas(VERTICAL, frecuenciaPalabrasMaxima, extremoInferiorEjeY, data->cantidadDeCategorias, coordenadaYEtiquetasDeFrecuencia, data);
            dibujarBarrasHistograma(VERTICAL, data->cantidadDeCategorias, data->frecuenciaPalabras, coordenadaYEtiquetasDeFrecuencia);
            dubujarCierreHistograma();
        } 
    }
}