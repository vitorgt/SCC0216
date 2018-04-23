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

void dfs(node *l, int ing, int *c, int *p, int *d, int *f, int *time, lifo *path){
	if(c[ing] == 0){
		int i = 0;
		c[ing]++;
		d[ing] = (*time)++;
		adj adja = LAd(l, ing);//find its ajdacents
		for(i = 0; i < adja.q; i++){//do it for its adjacents
			if(c[adja.aj[i]] == 0){//if this adjacent hasnt been visited
				p[adja.aj[i]] = ing;
				dfs(l, adja.aj[i], c, p, d, f, time, path);
			}
		}
		c[ing]++;
		f[ing] = (*time)++;
		insertLIFO(ing, path);
		free(adja.aj);
	}
}

void dfsI(node *l, int v){
	int i = 0;

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

	lifo path;
	createLIFO(&path);

	for(i = 0; i < v; i++) dfs(l, i, c, p, d, f, &time, &path);

	while(path.head) printf("%d ", removeLIFO(&path));//enqueue
	printf("\n");

	free(c);
	free(p);
	free(d);
	free(f);
}

int main(){

	int v = 0, e = 0;

	node *l = NULL, *t = NULL;//l := graph; //t := trasposed graph
	scanf("%d %d\n", &v, &e);//reads number of vertex and edges
	allocL(&l, v);//allocates and clears a linked list
	allocL(&t, v);

	readGraph(l, e);//read graph input

	dfsI(l, v);

	freeL(l, v);//free linked list

	return 0;
}
