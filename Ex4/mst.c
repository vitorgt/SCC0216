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

void mst(node *l, int v){
	int i = 0;
	int *c = NULL;//"color" array: #0 not yet visited #1 visited #2 ajdacents visited
	int *p = NULL;//parents array
	int *d = NULL;//distance from origin
	c = (int *)malloc(sizeof(int)*v);
	p = (int *)malloc(sizeof(int)*v);
	d = (int *)malloc(sizeof(int)*v);
	for(i = 0; i < v; i++){
		c[i] = 0; p[i] = -1; d[i] = inf;
	}

	//c[vo]++;//root node painted gray
	//d[vo] = 0;//its distance from root is 0
}

int main(){

	int v = 0, e = 0;

	node *l = NULL;//l := graph
	scanf("%d %d\n", &v, &e);//reads number of vertex and edges
	allocL(&l, v);//allocates and clears a linked list

	readGraph(l, e);//read graph input

	mst(l, v);

	fifoP prio;
	createFIFOP(&prio);
	insertFIFOP(createFIFOPnode(3,4,9), &prio);
	insertFIFOP(createFIFOPnode(0,4,6), &prio);
	insertFIFOP(createFIFOPnode(1,2,2), &prio);
	insertFIFOP(createFIFOPnode(0,2,4), &prio);
	insertFIFOP(createFIFOPnode(2,3,8), &prio);
	insertFIFOP(createFIFOPnode(0,1,4), &prio);
	insertFIFOP(createFIFOPnode(0,3,6), &prio);
	printFIFOP(prio);

	freeL(l, v);//free linked list

	return 0;
}
