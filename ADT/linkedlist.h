#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct _node{
	int v, w;
	struct _node *link;
}node;

typedef struct _adj{
	int q, *aj;
}adj;

void allocL(node **l, int v);
void clearL(node *l, int v);
void createN(node *l, int p, int v, int w);
void printL(node *l, int v);
void printLAd(node *l, int p);
adj  LAd(node *l, int p);
void lightedgeL(node *l, int v, char dg);
void removeL(node *l, int vo, int vd);
int weight(node *l, int vo, int vd);
void freeL(node *l, int v);

#endif
