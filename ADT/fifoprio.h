#ifndef FIFOPRIO_H
#define FIFOPRIO_H

typedef struct _fifotype{
	int v, w;
}fifopriotype;

typedef struct _nodeFIFOP{
	fifopriotype data;
	struct _nodeFIFOP *next;
}nodeFIFOP;

typedef struct _fifoP{
	nodeFIFOP *head;
}fifoP;

fifopriotype createFIFOPnode(int v, int w);
void insertFIFOP(fifopriotype data, fifoP *a);
int removeFIFOPnode(fifopriotype data, fifoP *a);
void updateFIFOPnode(fifopriotype data, fifoP *a);
int mapFIFOP(int v, fifoP a);
fifopriotype removeFIFOP(fifoP *a);
void createFIFOP(fifoP *a);
int isemptyFIFOP(fifoP a);
fifopriotype topFIFOP(fifoP a);
void printFIFOP(fifoP a);

#endif
