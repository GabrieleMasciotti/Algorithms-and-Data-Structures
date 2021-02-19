#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int num;
	int* edges;
	} grafo;

grafo* create(grafo* graph, int dim){
	int num;
	graph=malloc(dim*sizeof(grafo));
	for(int i=0; i<dim; i++){
		scanf("%d", &num);
		graph[i].num=num;
		graph[i].edges=malloc(num*sizeof(int));
		for(int j=0; j<num; j++){
			scanf("%d", &(graph[i].edges[j]));}
		}
	return graph;
}

void dfs_rec(grafo* graph, int src_qualunque, int* colors){
	int nodo;
	for(int i=0; i<graph[src_qualunque].num; i++){
		nodo=graph[src_qualunque].edges[i];
		if(!colors[nodo]) {colors[nodo]=1;
		dfs_rec(graph,nodo,colors);}
		}
}

int main(){
	int dim;
	scanf("%d", &dim);
	int* colors=malloc(dim*sizeof(int));
	for(int i=0; i<dim; i++) colors[i]=0;
	grafo* g=create(g,dim);
	dfs_rec(g,0,colors);
	int ok=1;
	int j=0;
	while(ok && j<dim){
		if(colors[j]==0) ok=0;
		else j++;}
	printf("%d\n", ok);
}
