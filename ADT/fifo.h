#ifndef FIFO_H
#define FIFO_H

typedef int fifotype;

typedef struct _node{
	fifotype data;
	struct _node *next;
}node;

typedef struct _fifo{
	node *head, *tail;
}fifo;

void insertFIFO(fifotype data, fifo a);
fifotype removeFIFO(fifo a);
void createFIFO(fifo a);
int isemptyFIFO(fifo a);
fifotype topFIFO(fifo a);
void printFIFO(fifo a);

#endif
