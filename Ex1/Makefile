all: main


main: main.c linkedlist.o adjacencymatrix.o
	gcc main.c linkedlist.o adjacencymatrix.o -o main
	rm *.o

linkedlist.o: linkedlist.c
	gcc linkedlist.c -c

adjacencymatrix.o: adjacencymatrix.c
	gcc adjacencymatrix.c -c

run:
	./main

