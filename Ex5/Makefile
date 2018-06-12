all: dijkstra


dijkstra: dijkstra.c linkedlist.o lifo.o fifo.o fifoprio.o
	gcc dijkstra.c linkedlist.o lifo.o fifo.o fifoprio.o -o main
	rm *.o

linkedlist.o: ../ADT/linkedlist.c
	gcc ../ADT/linkedlist.c -c

fifo.o: ../ADT/fifo.c
	gcc ../ADT/fifo.c -c

fifoprio.o: ../ADT/fifoprio.c
	gcc ../ADT/fifoprio.c -c

lifo.o: ../ADT/lifo.c
	gcc ../ADT/lifo.c -c

run: dijkstra
	./main

zip:
	zip Makefile.zip *.c *.h Makefile ../ADT/*

val: dijkstra
	valgrind ./dijkstra -v --leak-check=full --track-origins=yes

