//220m
#include<stdio.h>
#include<stdlib.h>
#include"adjacencymatrix.h"
#include"linkedlist.h"

void ReadInput(char dg, char ml, int v, int e, int **m, int **mt, node *l, node *lt){
	if(ml == 'M'){//if adjacency matrix

		if(dg == 'G'){//undirected graph
			int v1 = 0, v2 = 0, w = 0;//reads two vertex and edge's weight
			while(e--){
				scanf("%d %d %d ", &v1, &v2, &w);
				m[v1][v2] = w;//assigns value to matrix
				m[v2][v1] = w;
			}
		}
		else{//directed graph
			int vo = 0, vd = 0, w = 0;//reads origin and destiny vertex and egde's weight
			while(e--){
				scanf("%d %d %d ", &vo, &vd, &w);
				m[vo][vd] = w;//assingns value to matrix
				mt[vd][vo] = w;//assigns value to transposed matrix
			}
		}
	}
	else{//if linked list
		if(dg == 'G'){//undirected graph
			int v1 = 0, v2 = 0, w = 0;//reads two vertex and edge's weight
			while(e--){
				scanf("%d %d %d ", &v1, &v2, &w);
				createN(l, v1, v2, w);
				createN(l, v2, v1, w);
			}
		}
		else{//directed graph
			int vo = 0, vd = 0, w = 0;//reads origin and destiny vertex and egde's weight
			while(e--){
				scanf("%d %d %d ", &vo, &vd, &w);
				createN(l, vo, vd, w);//assigns value to linked list
				createN(lt, vd, vo, w);//assigns value to transposed linked list
			}
		}
	}
}

int main(){
	char dg = 0;//d or g
	char ml = 0;//m or l
	char op1 = 0, op2 = 0;
	int v = 0, e = 0;//vertex and edges
	int **m = NULL, **mt = NULL;//matrix and transposed matrix
	node *l = NULL, *lt = NULL;//linked list and transposed linked list
	scanf("%c %c %d %d ", &dg, &ml, &v, &e);//scans D G M L #vertex #edges

	if(((dg != 'D') && (dg != 'G')) || ((ml != 'M') && (ml != 'L'))){//if not G or D or M or L
		printf("Matrix type not recognized\n");
		return 1;
	}

	if(ml == 'M'){
		allocM(&m, v, v);//allocates and clears a matrix
		if(dg == 'D')
			allocM(&mt, v, v);//allocates and clears a transposed matrix
	}
	if(ml == 'L'){
		allocL(&l, v);//allocates and clears a linked list
		if(dg == 'D')
			allocL(&lt, v);//allocates and clears a transposed linked list
	}

	ReadInput(dg, ml, v, e, m, mt, l, lt);//parse input

	while(scanf("%c%c", &op1, &op2) == 2){

		if((op1 == 'I') && (op2 == 'G')){
			scanf(" ");
			if(ml == 'M') printM(m, v, v);//prints matrix or linked list
			else printL(l, v);
		}
		else if((op1 == 'V') && (op2 == 'A')){
			int va = 0;
			scanf("%d\n", &va);
			if(ml == 'M') printMAd(m, va, v);//prints transposed
			else printLAd(l, va);
		}
		else if((op1 == 'A') && (op2 == 'A')){
			ReadInput(dg, ml, v, 1, m, mt, l, lt);//reads one edge to insert
		}
		else if((op1 == 'R') && (op2 == 'A')){
			int v1 = 0, v2 = 0;
			scanf("%d %d ", &v1, &v2);
			if(dg == 'G'){
				if(ml == 'M'){
					removeM(m, v1, v2);//removes from matrix
					removeM(m, v2, v1);
				}
				else{
					removeL(l, v1, v2);//removes from linked list
					removeL(l, v2, v1);
				}
			}
			else{
				if(ml == 'M'){
					removeM(m, v1, v2);//removes from matrix and its transposed
					removeM(mt, v2, v1);
				}
				else{
					removeL(l, v1, v2);//removes from ll and its transposed
					removeL(lt, v2, v1);
				}
			}
		}
		else if((op1 == 'I') && (op2 == 'T')){
			scanf(" ");
			if(dg == 'G'){}//if not digraph, do nothing
			else{//if digraph prints transposed
				if(ml == 'M') printM(mt, v, v);
				else printL(lt, v);
			}
		}
		else if((op1 == 'M') && (op2 == 'P')){
			scanf(" ");
			if(ml == 'M') lightedgeM(m, v, dg);//searches for the lightest edge
			else lightedgeL(l, v, dg);
		}
		else{
			printf("Operation requested not recognized\n");
			return 1;
		}
	}

	if(ml == 'M'){//free matrix
		freeM(&m, v);
		if(dg == 'D')
			freeM(&mt, v);
	}
	if(ml == 'L'){//free ll
		freeL(l, v);
		if(dg == 'D')
			freeL(lt, v);
	}

	return 0;
}
