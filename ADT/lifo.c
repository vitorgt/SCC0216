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
	if(!(a) || !(a->head)){
		printf("Nothing to remove\n");
		return (lifotype)0;
	}
	else{
		nodeLIFO *temp = a->head;
		lifotype resu = a->head->data;
		a->head = a->head->next;
		free(temp);
		return resu;
	}
}

void createLIFO(lifo *a){
	a->head = NULL;
	a->tail = NULL;
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

