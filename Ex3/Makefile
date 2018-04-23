all: main


main: main.c linkedlist.o lifo.o fifo.o
	gcc main.c linkedlist.o lifo.o fifo.o -o main -g
	rm *.o

linkedlist.o: ../ADT/linkedlist.c
	gcc ../ADT/linkedlist.c -c

fifo.o: ../ADT/fifo.c
	gcc ../ADT/fifo.c -c

lifo.o: ../ADT/lifo.c
	gcc ../ADT/lifo.c -c

run: main
	./main

zip:
	zip Makefile.zip *.c *.h Makefile

val: main
	valgrind ./main -v --leak-check=full --track-origins=yes

