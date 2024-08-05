#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXIMA_LONGITUD 20

int main(){
	int caracter, estado, longitud, ultimo;
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
	
	for(i = 1; i <= MAXIMA_LONGITUD; i++){ 
		printf("\n%d\t", i);
		for(j = 0; j < palabras[i]; j++)
			printf("*"); 

        if (palabras[i] == 0)
            printf(" ");   
	}

    return 0;
}