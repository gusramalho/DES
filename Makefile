CC=gcc
CFLAGS=-W -Wall
SRC=$(wildcard *.c)
EXEC=des
OBJ=permutations.o des_internals.o main.o

all: des

des: $(OBJ)
	gcc -o des $(OBJ)

permutations.o: src/permutations.c
									$(CC) -o permutations.o -c src/permutations.c $(CFLAGS)

des_internals.o: src/des_internals.c
									$(CC) -o des_internals.o -c src/des_internals.c $(CFLAGS)

main.o: src/main.c src/permutations.h src/des_internals.h
				$(CC) -o $@ -c $< $(CFLAGS)

clean:
			rm -rf *.o
