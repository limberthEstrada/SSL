Para desarrollar y utilizar la biblioteca studio hicé lo siguiente:
1) Primero, generé un archivo llamado studio.h que contenga la declaración de las funciones que exportará la biblioteca
2) Luego generé el archivo de implementación "studio.c"
3) Hice la compilación del archivo studio.c con el siguiente comando: gcc -c studio.c
4) Para crear la biblioteca estatica studio.lib, utilicé el siguiente comando: ar rcs studio.lib studio.o
5) Generé el archivo hello.c que utiliza la función prontf de la biblioteca studio
6) Para obtener el ejecutable utilicé el siguiente comando: gcc -o hello.exe hello.c studio.lib

