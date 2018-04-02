all: main


main: main.c linkedlist.o adjacencymatrix.o
	gcc main.c linkedlist.o adjacencymatrix.o -o main
	rm *.o

linkedlist.o: ../ADT/linkedlist.c
	gcc ../ADT/linkedlist.c -c

adjacencymatrix.o: ../ADT/adjacencymatrix.c
	gcc ../ADT/adjacencymatrix.c -c

run:
	./main

