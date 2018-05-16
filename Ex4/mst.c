#include<stdio.h>
#include<stdlib.h>
#include"../ADT/linkedlist.h"
#include"../ADT/fifo.h"
#include"../ADT/lifo.h"
#include"../ADT/fifoprio.h"

#define inf 2147483646

void readGraph(node *l, int e){
	int vo = 0, vd = 0, w = 0;
	while(e--){
		scanf("%d %d %d", &vo, &vd, &w);
		createN(l, vo, vd, w);
	}
}

void mst(node *l, int v, int vo){//vo := origin vertex
	fifoP prio;
	createFIFOP(&prio);
	int i = 0;
	int *c = NULL;//"color" array: #0 not yet visited #1 visited #2 ajdacents visited
	int *p = NULL;//parents array
	int *d = NULL;//distance from origin
	c = (int *)malloc(sizeof(int)*v);
	p = (int *)malloc(sizeof(int)*v);
	d = (int *)malloc(sizeof(int)*v);
	for(i = 0; i < v; i++){
		c[i] = 0; p[i] = -1; d[i] = inf;
		insertFIFOP(createFIFOPnode(i, d[i]), &prio);
	}

	printFIFOP(prio);

	c[vo]++;//root node painted gray
	d[vo] = 0;//its distance from root is 0
	updateFIFOPnode(createFIFOPnode(vo, d[vo]), &prio);

	printFIFOP(prio);
}

int main(){

	int v = 0, e = 0;

	node *l = NULL;//l := graph
	scanf("%d %d\n", &v, &e);//reads number of vertex and edges
	allocL(&l, v);//allocates and clears a linked list

	readGraph(l, e);//read graph input

	mst(l, v, 0);

	freeL(l, v);//free linked list

	return 0;
}
