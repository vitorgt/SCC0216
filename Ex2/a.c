#include<stdio.h>
#include<stdlib.h>
#include"../ADT/linkedlist.h"
#include"../ADT/fifo.h"
#include"../ADT/lifo.h"

void readGraph(node *l, int e){
	int vo = 0, vd = 0;
	while(e--){
		scanf("%d %d\n", &vo, &vd);//reads origin and destiny vertex and egde's weight
		createN(l, vo, vd, 1);//assigns value to linked list
	}
}

void bfs(node *l, fifo *queue, int v, int vo, int vd){
	int i = 0, success = 0;

	int *c;//"color" array: #0 not yet visited #1 visited #2 ajdacents visited
	int *p;
	int *d;
	c = (int *)malloc(sizeof(int)*v);
	p = (int *)malloc(sizeof(int)*v);
	d = (int *)malloc(sizeof(int)*v);
	for(i = 0; i < v; i++){
		c[i] = 0; p[i] = -1; d[i] = -1;
	}

	c[vo]++;
	d[vo] = 0;
	insertFIFO(vo, queue);
	printFIFO(*queue);
	while(queue->head){
		if(queue->head->data != vd){
			nodeFIFO *u = queue->head;
			adj adja = LAd(l, u->data);
			printf("%d adjacentes a %d: ", adja.q, u->data);
			for(i = 0; i < adja.q; i++){
				printf("%d ", adja.aj[i]);
			}
			printf("\n");
			for(i = 0; i < adja.q; i++){
				if(c[adja.aj[i]] == 0){
					c[adja.aj[i]]++;
					d[adja.aj[i]] = d[u->data] + 1;
					if(p[adja.aj[i]] == -1){
						p[adja.aj[i]] = u->data;
					}
					insertFIFO(adja.aj[i], queue);
					printFIFO(*queue);
				}
			}
			c[u->data]++;
			removeFIFO(queue);
			printFIFO(*queue);
		}
		else{
			printf("ACHOU\n");
			success = 1;
			while(queue->head)
				removeFIFO(queue);
		}
	}
	for(i = 0; i < v; i++){
		printf("c[%d]==%2d ", i, c[i]);
	}
	printf("\n");
	for(i = 0; i < v; i++){
		printf("p[%d]==%2d ", i, p[i]);
	}
	printf("\n");
	for(i = 0; i < v; i++){
		printf("d[%d]==%2d ", i, d[i]);
	}
	printf("\n");

	free(c);
	free(p);
	free(d);
}

int main(){
	int v = 0, e = 0;
	int op1 = 0, op2 = 0;
	int i = 0;

	node *l = NULL;
	scanf("%d %d\n", &v, &e);
	allocL(&l, v);//allocates and clears a linked list

	readGraph(l, e);
	printL(l, v);

	fifo queue;
	createFIFO(&queue);

	while(scanf("%d %d\n", &op1, &op2) == 2){
		printf("bfs(o%d, d%d)\n", op1, op2);
		bfs(l, &queue, v, op1, op2);
	}

	freeL(l, v);//free linked list

	return 0;
}
