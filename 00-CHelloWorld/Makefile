SOURCE = hello.c
BIN = hello.exe
OBJ = hello.o
CC = gcc
CFLAGS = -std=c18

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN)

run: $(BIN)
	./$(BIN)

$(OBJ): $(SOURCE)
	$(CC) $(CFLAGS) -c $(SOURCE) -o $(OBJ)