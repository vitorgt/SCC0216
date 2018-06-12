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
	else if((a->head->data.w == new->data.w) && (a->head->data.v >= new->data.v)){
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
		new->next = aux->next;
		aux->next = new;
	}
}

int removeFIFOPnode(fifopriotype data, fifoP *a){
	if(a && a->head)
		if(a->head->data.v == data.v){
			nodeFIFOP *temp = a->head;
			a->head = a->head->next;
			free(temp);
			return 1;
		}
		else{
			nodeFIFOP *aux = a->head;
			while(aux->next){
				if(aux->next->data.v == data.v){
					nodeFIFOP *temp = aux->next;
					aux->next = temp->next;
					free(temp);
					return 1;
				}
				else
					aux = aux->next;
			}
		}
	return 0;
}

void updateFIFOPnode(fifopriotype data, fifoP *a){
	if(removeFIFOPnode(data, a)) insertFIFOP(data, a);
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
		printf("%3d %d\n", aux->data.v, aux->data.w);
		aux = aux->next;
	}
	printf("\n");
}

