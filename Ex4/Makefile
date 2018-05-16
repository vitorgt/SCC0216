all: mst


mst: mst.c linkedlist.o lifo.o fifo.o fifoprio.o
	gcc mst.c linkedlist.o lifo.o fifo.o fifoprio.o -o main -g
	rm *.o

linkedlist.o: ../ADT/linkedlist.c
	gcc ../ADT/linkedlist.c -c

fifo.o: ../ADT/fifo.c
	gcc ../ADT/fifo.c -c

fifoprio.o: ../ADT/fifoprio.c
	gcc ../ADT/fifoprio.c -c

lifo.o: ../ADT/lifo.c
	gcc ../ADT/lifo.c -c

run: mst
	./mst

zip:
	zip Makefile.zip *.c *.h Makefile

val: mst
	valgrind ./mst -v --leak-check=full --track-origins=yes

