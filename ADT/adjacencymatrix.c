//220m
#include<stdio.h>
#include<stdlib.h>
#include"adjacencymatrix.h"

void allocM(int ***m, int l, int c){//allocates and clears matrix
	int i = 0;
	*m = (int **)malloc(sizeof(int *) * l);
	for(; i < l; i++)
		*(*m + i) = (int *)malloc(sizeof(int) * c);
	clearM(*m, l, c);
}

void clearM(int **m, int l, int c){//clears, setting -1
	int i = 0, j = 0;
	for(; i < l; i++)
		for(j = 0; j < c; j++)
			m[i][j] = -1;
}

void printM(int **m, int l, int c){//prints matrix
	int i = 0, j = 0;
	for(; i < l; i++){
		for(j = 0; j < c; j++)
			if(m[i][j] > -1)//if theres a value set
				printf("%d ", m[i][j]);//prints value
			else//else print dot
				printf(". ");
		printf("\n");
	}
}

void printMAd(int **m, int l, int c){//prints only one line of the adjacency matrix
	int i = 0;
	for(; i < c; i++)
		if(m[l][i] > -1)
			printf("%d ", i);
	printf("\n");
}

void lightedgeM(int **m, int v, char dg){//looks for the lightest edge
	int i = 0, j = 0, vo = 0, vd = 0, w = 99999999;
	for(; i < v; i++){
		for(j = 0; j < v; j++){
			if((m[i][j] > -1) && (m[i][j] < w)){//if finds a lighter edge, set
				w = m[i][j];
				vo = i;
				vd = j;
			}
		}
	}
	if(dg == 'G'){
		if(vo > vd)//print sorted
			printf("%d %d\n", vd, vo);
		else
			printf("%d %d\n", vo, vd);
	}
	else
		printf("%d %d\n", vo, vd);
}

void removeM(int **m, int vo, int vd){
	m[vo][vd] = -1;
}

void freeM(int ***m, int l){//deallocates matrix
	int i = 0;
	for(; i < l; i++)
		free(*(*m + i));
	free(*m);
}
