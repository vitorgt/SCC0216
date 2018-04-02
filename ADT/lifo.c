#include<stdio.h>
#include<stdlib.h>
#include"lifo.h"

void insertLIFO(lifotype data, lifo *a){
	nodeLIFO *new = (nodeLIFO *)malloc(sizeof(nodeLIFO));
	new->data = data;
	new->next = a->head;
	if(!(a->head)){
		a->head = new;
		a->tail = new;
	}
	else{
		a->head = new;
	}
}

lifotype removeLIFO(lifo *a){
	if(!(a->head))
		printf("Nothing to remove\n");
	nodeLIFO *temp = a->head;
	lifotype resu = a->head->data;
	a->head = a->head->next;
	free(temp);
	return resu;
}

void createLIFO(lifo *a){
	a->head = NULL;
	a->tail = NULL;
}

int isemptyLIFO(lifo a){
	if(!(a.head)) return 1;
	return 0;
}

lifotype topLIFO(lifo a){
	if(!(a.head)){
		printf("Nothing\n");
		return;
	}
	return a.head->data;
}

void printLIFO(lifo a){
	//works onle if lifotype is int
	nodeLIFO *aux = a.head;
	while(aux){
		printf("%d ", aux->data);
		aux = aux->next;
	}
	printf("\n");
}

