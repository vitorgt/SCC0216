#include<stdio.h>
#include<stdlib.h>
#include"../ADT/linkedlist.h"
#include"../ADT/lifo.h"

/*

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
	int *p;//parents array
	int *d;//distance from origin
	c = (int *)malloc(sizeof(int)*v);
	p = (int *)malloc(sizeof(int)*v);
	d = (int *)malloc(sizeof(int)*v);
	for(i = 0; i < v; i++){
		c[i] = 0; p[i] = -1; d[i] = -1;//clears
	}

	c[vo]++;//root node painted gray
	d[vo] = 0;//its distance from root is 0
	insertFIFO(vo, queue);//enqueue
	while(queue->head){//while queue isnt empty
		if(queue->head->data != vd){//if visiting node isnt the one we're looking for
			nodeFIFO *u = queue->head;//create a pointer
			adj adja = LAd(l, u->data);//find its ajdacents
			for(i = 0; i < adja.q; i++){//do it for its adjacents
				if(c[adja.aj[i]] == 0){//if this adjacent hasnt been visited
					c[adja.aj[i]]++;//visit
					d[adja.aj[i]] = d[u->data] + 1;//calculate its distance from root (his parent's distance + 1)
					if(p[adja.aj[i]] == -1){//if his parent isnt yet set
						p[adja.aj[i]] = u->data;//set his parent
					}
					insertFIFO(adja.aj[i], queue);//enqueue
				}
			}
			free(adja.aj);
			c[u->data]++;//visited all its adjacents, paint it black
			removeFIFO(queue);//dequeue
		}
		else{//if we find the node we're looking for
			success = 1;
			while(queue->head)
				removeFIFO(queue);//empty queue
		}
	}

	if(success){
		int veri = vd, size = d[veri] + 1, *sol;//size of the solution array is the distance from the node to root set on the 'd' array
		sol = (int *)calloc(size, sizeof(int));//solution array
		sol[d[veri]] = vd;//set last value of the solution array as the desired destination vertex
		veri = p[veri];//aux receives its parent
		for(i = size-2; i > 0 && veri != vo && veri != -1; i--){//while aux isnt the origin vertex nor empty parent (-1)
			sol[i] = veri;//store solution
			veri = p[veri];//aux receives its parent
		}
		if(vo != vd)//if the origin vertex isnt the destination vertex
			sol[0] = veri;//aux should now be orign vertex and must be on solution arrya
		for(i = 0; i < size; i++){
			printf("%d ", sol[i]);//print solution
		}
		free(sol);
	}
	printf("\n");

	free(c);
	free(p);
	free(d);
}

*/

int main(){

/*

	int v = 0, e = 0;
	int op1 = 0, op2 = 0;
	int i = 0;

	node *l = NULL;
	scanf("%d %d\n", &v, &e);//reads number of vertex and edges
	allocL(&l, v);//allocates and clears a linked list

	readGraph(l, e);//read graph input

	fifo queue;
	createFIFO(&queue);

	while(scanf("%d %d\n", &op1, &op2) == 2){
		bfs(l, &queue, v, op1, op2);
	}

	freeL(l, v);//free linked list

*/

	return 0;
}
