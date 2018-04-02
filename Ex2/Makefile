all: a


a: a.c linkedlist.o fifo.o lifo.o
	gcc a.c linkedlist.o fifo.o lifo.o -o a -g
	rm *.o

linkedlist.o: linkedlist.c
	gcc linkedlist.c -c

fifo.o: fifo.c
	gcc fifo.c -c

lifo.o: lifo.c
	gcc lifo.c -c

run: a
	./a

zip:
	zip mak.zip *.c *.h

val: a
	valgrind ./a --leak-check=full --track-origins=yes

