#include<stdio.h>
#include<stdlib.h>
#include"../ADT/linkedlist.h"
#include"../ADT/fifo.h"
#include"../ADT/lifo.h"
#include"../ADT/fifoprio.h"

#define inf 0x7fffffff

void readGraph(node *l, int e){
	int vo = 0, vd = 0, w = 0;
	while(e--){
		scanf("%d %d %d", &vo, &vd, &w);
		createN(l, vo, vd, w);
	}
}

void dijkstra(node *l, int v, int vo, int vd){//vo := origin vertex; vd := target vertex
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

	c[vo]++;//root node painted gray
	d[vo] = 0;//its distance from root is 0
	p[vo] = vo;
	updateFIFOPnode(createFIFOPnode(vo, d[vo]), &prio);
	while(!isemptyFIFOP(prio)){
		fifopriotype u = removeFIFOP(&prio);
		c[u.v]++;
		if(u.v != vd){
			adj adja = LAd(l, u.v);//find its ajdacents
			for(i = 0; i < adja.q; i++){
				if(c[adja.aj[i]] == 0){
					int Weight = weight(l, u.v, adja.aj[i]) + d[u.v];
					if(d[adja.aj[i]] > Weight){
						d[adja.aj[i]] = Weight;
						p[adja.aj[i]] = u.v;
						updateFIFOPnode(createFIFOPnode(adja.aj[i], Weight), &prio);
					}
				}
			}
		}
		else while(!isemptyFIFOP(prio)) removeFIFOP(&prio);
	}
	if(p[vd] != -1){
		lifo path;
		createLIFO(&path);
		int veri = vd;
		while(veri != vo){
			insertLIFO(veri, &path);//enqueue
			veri = p[veri];
			if(veri == -1)
				break;
		}
		if(veri != -1){
			insertLIFO(veri, &path);//enqueue
			while(path.head){
				printf("%d ", removeLIFO(&path));//enqueue
			}
		}
	}
	printf("\n");
}

int main(){

	int v = 0, e = 0;
	int vo = 0, vd = 0;

	node *l = NULL;//l := graph
	scanf("%d %d\n", &v, &e);//reads number of vertex and edges
	allocL(&l, v);//allocates and clears a linked list

	readGraph(l, e);//read graph input

	while(scanf("%d %d", &vo, &vd) == 2)
		dijkstra(l, v, vo, vd);

	freeL(l, v);//free linked list

	return 0;
}
