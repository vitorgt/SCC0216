#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

void allocM(int ***m, int l, int c);
void clearM(int **m, int l, int c);
void printM(int **m, int l, int c);
void printMAd(int **m, int l, int c);
void lightedgeM(int **m, int v, char dg);
void removeM(int **m, int vo, int vd);
void freeM(int ***m, int l);

#endif
