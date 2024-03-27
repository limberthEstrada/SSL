/* hello.c
 * Resolución de trabajo  
 * Limberth Estrada
 * 20240327  
 */

#include <stdio.h>
void filecopy(FILE *ifp, FILE *ofp)
{
    int c;

    while((c = getc(ifp)) != EOF)
    {
        putc(c, ofp);
    }
}

int main(void){
    FILE *fp;
    fp = fopen("output.txt", "w");

    if(fp == NULL){
        printf("No se puede abrir");
        return 1;
    }
    
    freopen("output.txt", "w", stdout);
    
    printf("Hello, World!\n");

    fclose(fp);

    return 0;
}