#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXIMA_LONGITUD 20

int main(){
	int caracter, estado, longitud, ultimo, maximo;
	int i, j;
	int palabras[MAXIMA_LONGITUD + 1];
	
	longitud = 0;
	estado = OUT;
	
	for (i = 0; i <= MAXIMA_LONGITUD; i++)
		palabras[i] = 0;
		
	while((caracter = getchar()) != EOF){
		if (caracter != '\n' && caracter != '\t' && caracter != ' '){
			if (longitud < MAXIMA_LONGITUD)
                ++longitud;
			
            estado = IN;
		}
		else{
			if (estado == IN){
				++palabras[longitud];
				longitud = 0;
			}
			estado = OUT;
		}
	}

	if (estado == IN)
		++palabras[longitud];
	
	maximo = palabras[1];

	for(i = 1; i <= MAXIMA_LONGITUD; i++){
		if (palabras[i] > maximo)
			maximo = palabras[i];
	}
	
	for (i = maximo; i > 0; i--){
		for(j = 1; j <= MAXIMA_LONGITUD; j++){
			if(palabras[j] >= i)
				printf("*\t");
            else
                printf("\t");
		}
		printf("\n");
	}
	
	for(i = 1; i <= MAXIMA_LONGITUD; i++)
		printf("%d\t", i);

    return 0;
}