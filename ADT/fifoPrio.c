#include<stdio.h>
#include<stdlib.h>
#include"fifoPrio.h"

fifopriotype createFIFOPnode(int vo, int vd, int w){
	fifopriotype a;
	a.vo = vo;
	a.vd = vd;
	a.w = w;
	return a;
}

void insertFIFOP(fifopriotype data, fifoP *a){
	nodeFIFOP *new = (nodeFIFOP *)malloc(sizeof(nodeFIFOP));
	nodeFIFOP *aux = a->head;
	new->data = data;
	new->next = NULL;
	if(!(a->head)){
		a->head = new;
	}
	else if(aux->data.w > new->data.w){
		new->next = aux;
		aux = new;
	}
	else{
		while(aux->next){
			if(aux->next->data.w < new->data.w)
				aux = aux->next;
			else if(aux->next->data.w = new->data.w){
				if(aux->next->data.vo < new->data.vo)
					aux = aux->next;
				else if(aux->next->data.vo = new->data.vo){
					if(aux->next->data.vd < new->data.vd)
						aux = aux->next;
					else break;
				}
				else break;
			}
			else break;
		}
		new->next = aux->next;
		aux->next = new;
	}
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
	if(!(a.head)){
		printf("Nothing\n");
		return (fifopriotype)0;
	}
	return a.head->data;
}

void printFIFOP(fifoP a){
	nodeFIFOP *aux = a.head;
	while(aux){
		printf("%d %d %d", aux->data.vo, aux->data.vd, aux->data.w);
		aux = aux->next;
	}
	printf("\n");
}

