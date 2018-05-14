#ifndef FIFOPRIO_H
#define FIFOPRIO_H

typedef struct _node{
	int vo, vd, w;
}fifopriotype;

typedef struct _nodeFIFOP{
	fifopriotype data;
	struct _nodeFIFOP *next;
}nodeFIFOP;

typedef struct _fifoP{
	nodeFIFOP *head;
}fifoP;

fifopriotype createFIFOPnode(int vo, int vd, int w);
void insertFIFOP(fifopriotype data, fifoP *a);
fifopriotype removeFIFOP(fifoP *a);
void createFIFOP(fifoP *a);
int isemptyFIFOP(fifoP a);
fifopriotype topFIFOP(fifoP a);
void printFIFOP(fifoP a);

#endif
