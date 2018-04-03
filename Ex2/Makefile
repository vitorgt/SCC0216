all: bfs dfs


bfs: bfs.c linkedlist.o fifo.o
	gcc bfs.c linkedlist.o fifo.o -o bfs
	rm *.o

dfs: dfs.c linkedlist.o lifo.o
	gcc dfs.c linkedlist.o lifo.o -o dfs
	rm *.o

linkedlist.o: ../ADT/linkedlist.c
	gcc ../ADT/linkedlist.c -c

fifo.o: ../ADT/fifo.c
	gcc ../ADT/fifo.c -c

lifo.o: ../ADT/lifo.c
	gcc ../ADT/lifo.c -c

runb: bfs
	./bfs

runb: dfs
	./dfs

zip:
	zip Makefile.zip *.c *.h Makefile

valb: bfs
	valgrind ./bfs --leak-check=full --track-origins=yes

vald: dfs
	valgrind ./dfs --leak-check=full --track-origins=yes

