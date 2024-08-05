CC = gcc
CFLAGS = -Wall -Wextra -std=c99

main: main.o graficador.o histograma-1-enum-switch.o histograma-2-goto.o histograma-3-rec.o histograma-x.o
	$(CC) $(CFLAGS) main.o graficador.o histograma-1-enum-switch.o histograma-2-goto.o histograma-3-rec.o histograma-x.o -o main

main.o: main.c graficador.h histograma.h
	$(CC) $(CFLAGS) -c main.c -o main.o

graficador.o: graficador.c graficador.h histograma.h
	$(CC) $(CFLAGS) -c graficador.c -o graficador.o

histograma-1-enum-switch.o: histograma-1-enum-switch.c histograma.h
	$(CC) $(CFLAGS) -c histograma-1-enum-switch.c -o histograma-1-enum-switch.o

histograma-2-goto.o: histograma-2-goto.c histograma.h
	$(CC) $(CFLAGS) -c histograma-2-goto.c -o histograma-2-goto.o

histograma-3-rec.o: histograma-3-rec.c histograma.h
	$(CC) $(CFLAGS) -c histograma-3-rec.c -o histograma-3-rec.o

histograma-x.o: histograma-x.c histograma.h
	$(CC) $(CFLAGS) -c histograma-x.c -o histograma-x.o

clean:
	rm -f main main.o graficador.o histograma-1-enum-switch.o histograma-2-goto.o histograma-3-rec.o histograma-x.o
