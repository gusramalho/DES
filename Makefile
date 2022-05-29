CC=gcc
CFLAGS=-W -Wall
SRC=$(wildcard *.c)
EXEC=des
OBJ=permutations.o des_internals.o des.o main.o 

TESTS_OBJ=permutations.o des_internals.o des.o des_internals_tests.o

all: des

des: $(OBJ)
	gcc -o des $(OBJ)

tests: $(TESTS_OBJ)
	gcc -o des_tests $(TESTS_OBJ)

permutations.o: src/permutations.c
									$(CC) -o permutations.o -c src/permutations.c $(CFLAGS)

des_internals.o: src/des_internals.c
									$(CC) -o des_internals.o -c src/des_internals.c $(CFLAGS)
									
des.o: src/des.c
				$(CC) -o des.o -c src/des.c $(CFLAGS)

main.o: src/main.c src/permutations.h src/des_internals.h
				$(CC) -o $@ -c $< $(CFLAGS)

des_internals_tests.o: tests/des_internals_tests.c src/permutations.h src/des_internals.h
				$(CC) -o $@ -c $< $(CFLAGS)

clean:
			rm -rf *.o
