all: a


a: a.c linkedlist.o fifo.o lifo.o
	gcc a.c linkedlist.o fifo.o lifo.o -o a -g
	rm *.o

linkedlist.o: ../ADT/linkedlist.c
	gcc ../ADT/linkedlist.c -c

fifo.o: ../ADT/fifo.c
	gcc ../ADT/fifo.c -c

lifo.o: ../ADT/lifo.c
	gcc ../ADT/lifo.c -c

run: a
	./a

zip:
	zip mak.zip *.c *.h

val: a
	valgrind ./a --leak-check=full --track-origins=yes

