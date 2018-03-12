#include<stdio.h>
#include<stdlib.h>
#include"adjacencymatrix.h"
#include"linkedlist.h"

void ReadInput(char dg, char ml, int v, int e, int **m){
	if(ml == 'M'){//if adjacency matrix

		if(dg == 'G'){//undirected graph
			int v1 = 0, v2 = 0, w = 0;//reads two vertex and edge's weight
			while(e--){
				scanf("%d %d %d ", &v1, &v2, &w);
				m[v1][v2] = w;
				m[v2][v1] = w;
			}
		}
		else{//directed graph
			int vo = 0, vd = 0, w = 0;//reads orign and destiny vertex and egde's weight
			while(e--){
				scanf("%d %d %d ", &vo, &vd, &w);
				m[vo][vd] = w;
			}
		}
	}
	else{//if linked list
		if(dg == 'G'){//undirected graph
		}
		else{//directed graph
		}
	}
}

int main(){
	char dg = 0, ml = 0;//d or g	//m or l
	int v = 0, e = 0;//vertex and edges
	int **m = NULL;
	scanf("%c %c %d %d ", &dg, &ml, &v, &e);

	if(((dg != 'D') && (dg != 'G')) || ((ml != 'M') && (ml != 'L'))){
		printf("Matrix type not recognized\n");
		return 1;
	}

	if(ml == 'M')
		allocM(&m, v, v);//allocates and clears a matrix
	ReadInput(dg, ml, v, e, m);
	printM(m, v, v);
	if(ml == 'M')
		freeM(&m, v);


	return 0;
}
