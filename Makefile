CC = gcc
CFLAGS = -Wall -Iinclude

SRC = src/main.c src/integracion.c src/densidades.c
OBJ = $(SRC:.c=.o)

all: main

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ) -lm

clean:
	rm -f src/*.o main