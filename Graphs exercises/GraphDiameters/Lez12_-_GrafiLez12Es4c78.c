#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int num;
	int* edges;
	} grafo;

grafo* create(grafo* g, int dim){
	g=malloc(dim*sizeof(grafo));
	int num;
	for(int i=0; i<dim; i++){
		scanf("%d", &num);
		g[i].num=num;
		g[i].edges=malloc(num*sizeof(int));
		for(int j=0; j<num; j++) scanf("%d", &(g[i].edges[j]));
		}
	return g;
}

typedef struct arrayBFS{
	int* infos;
	int dim;
	int head;
	int tail;
	} arr;

void arr_init(arr* a, int dim){
	a->infos=malloc(dim*sizeof(int));
	a->dim=0;
	a->head=0;
	a->tail=0;
}

void arr_deinit(arr* a){
	free(a->infos);
}

void arr_pushback(arr* a, int el){
	if(a->head==0){
		a->infos[a->head]=el;
		a->tail=a->head;
		a->dim++;}
	else{
		a->infos[a->tail+1]=el;
		a->tail++;
		a->dim++;}
}

int arr_popfront(arr* a){
	int front=a->infos[a->head];
	a->head++;
	a->dim--;
	return front;
}

int arr_empty(arr* a){
	if(a->dim==0) return 1;
	else return 0;
}

int* bfs(grafo* g, int from, int dim){
	int* colors=malloc(dim*sizeof(int));
	int* perc=malloc(dim*sizeof(int));
	for(int i=0; i<dim; i++){
		colors[i]=0;
		perc[i]=-1;
	}
	colors[from]=1;
	perc[from]=0;
	arr a;
	int nodo, dest;
	arr_init(&a,dim);
	arr_pushback(&a,from);
	while(!arr_empty(&a)){
		nodo=arr_popfront(&a);
		for(int j=0; j<g[nodo].num; j++){
			dest=g[nodo].edges[j];
			if(!colors[dest] /*&& perc[dest]<0*/){
				colors[dest]=1;
				perc[dest]=perc[nodo]+1;
				arr_pushback(&a,dest);
			}
		}
	}
	arr_deinit(&a);
	return perc;
}

int max_arr(int* a, int dim){
	int max=-8;
	for(int i=0; i<dim; i++){
		if(a[i]>max) max=a[i];
	}
	return max;
}

int connesso(grafo* g, int dim, int perc[]){
	int ok=1;
	int i=0;
	while(ok && i<dim) {
		if(perc[i]<0) ok=0;
		else i++;}
	return ok;
}

int main(){
	int dim;
	scanf("%d", &dim);
	grafo* g=create(g,dim);
	int maxperc=-12;
	int newperc;
	int* arr_aux;
	for(int i=0; i<dim; i++){
		arr_aux=bfs(g,i,dim);
		newperc=max_arr(arr_aux,dim);
		if(newperc>maxperc) maxperc=newperc;
		}
	if(connesso(g,dim,arr_aux)) printf("%d\n", maxperc);
	else printf("-1\n");
}
