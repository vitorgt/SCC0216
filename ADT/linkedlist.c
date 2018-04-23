//220m
#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

void allocL(node **l, int v){//allocates an array of struct nodes
	*l = (node *)malloc(sizeof(node)*v);
	clearL(*l, v);//clears them
}

void clearL(node *l, int v){//clears linked list setting -1
	int i = 0;
	for(; i < v; i++){
		l[i].v = -1;
		l[i].w = -1;
		l[i].link = NULL;
	}
}

void createN(node *l, int p, int v, int w){
	int repeated = 0;
	node *new = NULL, *aux = &(l[p]);
	while(aux){//runs the linked list looking for repetitions
		if(aux->v == v){
			aux->w = w;
			repeated = 1;
			break;
		}
		aux = aux->link;
	}
	if(!repeated){
		new = (node *)malloc(sizeof(node));//malloc a new node
		new->v = v;//assigns values
		new->w = w;
		new->link = NULL;
		aux = l[p].link;
		if(!aux){//if theres no destiny on the first node, creates the first link to the first cell
			l[p].link = new;
		}
		else if(aux->v >= new->v){//if the first node is bigger puts the new node before it
			new->link = aux;
			l[p].link = new;
		}
		else{//looks for the place to put the new cell, sorting
			while((aux->link) && (aux->link->v < v)){//runs the linked list
				aux = aux->link;//run
			}
			new->link = aux->link;
			aux->link = new;
		}
	}
}

void printL(node *l, int v){
	int i = 0;
	node *aux = NULL;
	for(; i < v; i++){
		printf("%d. ", i);//prints the origin vertx
		aux = l[i].link;
		while(aux){
			printf("%d(%d) ", aux->v, aux->w);//prints its destinies
			aux = aux->link;//run
		}
		printf("\n");
	}
}

void printLAd(node *l, int p){//prints adjacents to a node
	node *aux = l[p].link;
	while(aux){
		printf("%d ", aux->v);
		aux = aux->link;
	}
	printf("\n");
}

adj LAd(node *l, int p){//returns adjacents to a node
	node *aux = l[p].link;
	adj resu;
	int *to = NULL, i = 0;
	resu.q = 0;
	while(aux){
		to = (int *)realloc(to, sizeof(int)*(++(resu.q)));
		to[resu.q - 1] = aux->v;
		aux = aux->link;
	}
	resu.aj = (int *)malloc(sizeof(int)*resu.q);
	for(; i < resu.q; i++){
		resu.aj[i] = to[i];
	}
	free(to);
	return resu;
}

void lightedgeL(node *l, int v, char dg){//looks for the lightest edge
	int i = 0, vo = 0, vd = 0, w = 99999999;
	node *aux = NULL;
	for(; i < v; i++){
		aux = l[i].link;
		while(aux){
			if(aux->w < w){//if finds a lighter edge, set
				w = aux->w;
				vo = i;
				vd = aux->v;
			}
			aux = aux->link;//run
		}
	}
	if(dg == 'G'){
		if(vo > vd)//prints sorted
			printf("%d %d\n", vd, vo);
		else
			printf("%d %d\n", vo, vd);
	}
	else
		printf("%d %d\n", vo, vd);
}

void removeL(node *l, int vo, int vd){//remove node
	node *aux = &(l[vo]), *del = NULL;
	while(aux->link){//while theres a next node
		if(aux->link->v == vd){//if the next node is the one its looking for
			del = aux->link;
			aux->link = aux->link->link;
			break;
		}
		aux = aux->link;
	}
	if(del)
		free(del);
}

void freeL(node *l, int v){
	int i = 0;
	node *aux1 = NULL, *aux2 = NULL;
	for(; i < v; i++){
		aux1 = l[i].link;
		while(aux1){
			aux2 = aux1->link;
			free(aux1);
			aux1 = aux2;
		}
	}
	free(l);
}
