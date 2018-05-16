#include<stdio.h>
#include<stdlib.h>
#include"fifoprio.h"

fifopriotype createFIFOPnode(int v, int w){
	fifopriotype a;
	a.v = v;
	a.w = w;
	return a;
}

void insertFIFOP(fifopriotype data, fifoP *a){
	nodeFIFOP *new = (nodeFIFOP *)malloc(sizeof(nodeFIFOP));
	nodeFIFOP *aux = a->head;
	new->data = data;
	new->next = NULL;
	if(!(a->head))
		a->head = new;
	else if(a->head->data.w > new->data.w){
		new->next = aux;
		a->head = new;
	}
	else{
		while(aux->next){
			if(aux->next->data.w < new->data.w)
				aux = aux->next;
			else if(aux->next->data.w == new->data.w){
				if(aux->next->data.v < new->data.v)
					aux = aux->next;
				else break;
			}
			else break;
		}
		nodeFIFOP *temp = aux->next;
		aux->next = new;
		new->next = temp;
	}
}

void updateFIFOPnode(fifopriotype data, fifoP *a){
	printFIFOP(*a);
	int ok = 0;
	if(a && a->head)
		if(a->head->data.v == data.v){
			nodeFIFOP *temp = a->head;
			a->head = a->head->next;
			free(temp);
			insertFIFOP(data, a);
		}
		else{
			nodeFIFOP *aux = a->head;
			while(aux){
				if(aux->next->data.v == data.v){
					ok = 1;
					nodeFIFOP *temp = aux->next;
					aux->next = aux->next->next;
					free(temp);
					break;
				}
				else
					aux = aux->next;
			}
			if(ok) insertFIFOP(data, a);
		}
	printFIFOP(*a);
}

int mapFIFOP(int v, fifoP a){
	if(a.head){
		nodeFIFOP *aux = a.head;
		while(aux)
			if(aux->data.v == v)
				return aux->data.w;
			else
				aux = aux->next;
		return -1;
	}
	return -1;
}

fifopriotype removeFIFOP(fifoP *a){
	if(!(a->head))
		printf("Nothing to remove\n");
	nodeFIFOP *temp = a->head;
	fifopriotype resu = a->head->data;
	a->head = a->head->next;
	free(temp);
	return resu;
}

void createFIFOP(fifoP *a){
	a->head = NULL;
}

int isemptyFIFOP(fifoP a){
	if(!(a.head)) return 1;
	return 0;
}

fifopriotype topFIFOP(fifoP a){
	fifopriotype *nul = NULL;
	if(!(a.head)){
		printf("Nothing\n");
		return *nul;
	}
	return a.head->data;
}

void printFIFOP(fifoP a){
	nodeFIFOP *aux = a.head;
	while(aux){
		printf("%d %d\n", aux->data.v, aux->data.w);
		aux = aux->next;
	}
	printf("\n");
}

