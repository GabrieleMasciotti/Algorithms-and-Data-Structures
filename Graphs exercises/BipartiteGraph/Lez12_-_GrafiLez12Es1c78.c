#include <stdio.h>
#include <stdlib.h>

typedef struct edge{
	int num_edges;
	int* edges;}
	graph;

graph* create_graph(graph* grafo, int dim){
	grafo=malloc(dim*sizeof(graph));
	int el,num;
	for(int i=0; i<dim; i++){
		scanf("%d", &num);
		grafo[i].num_edges=num;
		grafo[i].edges=malloc(num*sizeof(int));
		for(int j=0; j<num; j++) scanf("%d", &(grafo[i].edges[j]));
		}
	return grafo;
}

void rec_dfs_2colors(graph* grafo, int sor, int colors[], int colore){
	int nodo;
	for(int i=0; i<grafo[sor].num_edges; i++){
		nodo=grafo[sor].edges[i];
		if(colors[nodo]==0){ colors[nodo]=-colore;
		rec_dfs_2colors(grafo,nodo,colors,-colore);}
}}

int bipartito(graph* grafo, int sor, int dim, int colors[]){
	int edge;
	colors[sor]=1;
	rec_dfs_2colors(grafo,sor,colors,1);
	for(int i=0; i<dim; i++){
		for(int j=0; j<grafo[i].num_edges; j++){
			if(colors[i]==colors[grafo[i].edges[j]]) return 0;}
		}
	return 1;
}

int main(){
	int dim;
	scanf("%d", &dim);
	graph* grafo=create_graph(grafo,dim);
	int* colors=malloc(dim*sizeof(int));
	for(int i=0; i<dim; i++) colors[i]=0;
	printf("%d\n", bipartito(grafo,0,dim,colors));
}

