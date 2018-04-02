all: a


a: a.c linkedlist.o fifo.o lifo.o
	gcc a.c linkedlist.o fifo.o lifo.o -o a
	rm *.o

linkedlist.o: linkedlist.c
	gcc linkedlist.c -c

fifo.o: fifo.c
	gcc fifo.c -c

lifo.o: lifo.c
	gcc lifo.c -c

run:
	./a

