#ifndef LIFO_H
#define LIFO_H

typedef int lifotype;

typedef struct _nodeLIFO{
	lifotype data;
	struct _nodeLIFO *next;
}nodeLIFO;

typedef struct _lifo{
	nodeLIFO *head, *tail;
}lifo;

void insertLIFO(lifotype data, lifo a);
lifotype removeLIFO(lifo a);
void createLIFO(lifo a);
int isemptyLIFO(lifo a);
lifotype topLIFO(lifo a);
void printLIFO(lifo a);

#endif
