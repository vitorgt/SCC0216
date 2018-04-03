#include<stdio.h>
#include<stdlib.h>
#include"../ADT/linkedlist.h"
#include"../ADT/lifo.h"

void readGraph(node *l, int e){
	int vo = 0, vd = 0;
	while(e--){
		scanf("%d %d\n", &vo, &vd);//reads origin and destiny vertex and egde's weight
		createN(l, vo, vd, 1);//assigns value to linked list
	}
}

void dfs(node *l, lifo *stack, int v, int vo, int vd){
	int i = 0, success = 0, ed = 0, ok = 0;

	lifo path;
	createLIFO(&path);

	int *c;//"color" array: #0 not yet visited #1 visited #2 ajdacents visited
	int *p;//parents array
	int time = 0, *d, *f;//timestamps
	c = (int *)malloc(sizeof(int)*v);
	p = (int *)malloc(sizeof(int)*v);
	d = (int *)malloc(sizeof(int)*v);
	f = (int *)malloc(sizeof(int)*v);
	for(i = 0; i < v; i++){
		c[i] = 0; p[i] = -1; d[i] = -1; f[i] = -1;//clears
	}

	c[vo]++;//root node painted gray
	d[vo] = time++;
	insertLIFO(vo, stack);//enqueue
	while(stack->head){//while queue isnt empty
		insertLIFO(stack->head->data, &path);//enqueue
		if(stack->head->data != vd){//if visiting node isnt the one we're looking for
			int u = stack->head->data;
			removeLIFO(stack);
			adj adja = LAd(l, u);//find its ajdacents
			ed = 0;
			ok = 0;
			for(i = adja.q-1; i >= 0; i--){//do it for its adjacents
				if(c[adja.aj[i]] == 0){//if this adjacent hasnt been visited
					c[adja.aj[i]]++;//visit
					d[adja.aj[i]] = time++;
					if(p[adja.aj[i]] == -1){//if his parent isnt yet set
						p[adja.aj[i]] = u;//set his parent
					}
					insertLIFO(adja.aj[i], stack);//enqueue
				}
				else{
					ed++;
					if(adja.aj[i] == vd){
						ok = 1;
					}
				}
			}
			if(adja.q == ed && !ok){
				removeLIFO(&path);
			}
			free(adja.aj);
			c[u]++;//visited all its adjacents, paint it black
			f[u] = time++;
		}
		else{//if we find the node we're looking for
			success = 1;
			while(stack->head)
				removeLIFO(stack);
		}
	}

	if(success){
		lifo path2;
		createLIFO(&path2);
		while(path.head){
			insertLIFO(removeLIFO(&path), &path2);//enqueue
		}
		while(path2.head){
			printf("%d ", removeLIFO(&path2));//enqueue
		}
	}
	printf("\n");

	free(c);
	free(p);
	free(d);
}

int main(){

	int v = 0, e = 0;
	int op1 = 0, op2 = 0;

	node *l = NULL;
	scanf("%d %d\n", &v, &e);//reads number of vertex and edges
	allocL(&l, v);//allocates and clears a linked list

	readGraph(l, e);//read graph input

	lifo stack;
	createLIFO(&stack);

	while(scanf("%d %d\n", &op1, &op2) == 2){
		//printf("dfs(%d, %d)\n", op1, op2);
		dfs(l, &stack, v, op1, op2);
	}

	freeL(l, v);//free linked list

	return 0;
}
