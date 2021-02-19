#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int num;
	int* edges;}
	grafo;

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

typedef struct nod{
	int info;
	struct nod* next;}
	lista;

void deinit(lista** head){
	free(*head);
}

void push_back(lista** head, int el){
	if(*head==NULL){
		*head=malloc(sizeof(lista));
		(*head)->info=el;
		(*head)->next=NULL;
		}
	else{
		lista* corr=*head;
		while(corr->next!=NULL) corr=corr->next;
		lista* new=malloc(sizeof(lista));
		new->info=el;
		new->next=NULL;
		corr->next=new;
		}
}

void init(lista** head, int el){
	*head=malloc(sizeof(lista));
	(*head)->info=el;
	(*head)->next=NULL;
}

int pop_front(lista** head){
	int testa=(*head)->info;
	lista* aux=*head;
	*head=(*head)->next;
	free(aux);
	return testa;
}

int empty(lista* head){
	if(head==NULL) return 1;
	else return 0;
}

void printlist(lista* head){
	if(head==NULL) return;
	printf("%d ", head->info);
	printlist(head->next);
}

int bfs(grafo* g, int dim, int start, int end){
	if(start==end) return 0;
	int* colors=malloc(dim*sizeof(int));

	int* dist=malloc(dim*sizeof(int));
	for(int i=0; i<dim; i++){
		colors[i]=0;
		dist[i]=-1;
		}

	colors[start]=1;
	dist[start]=0;
	int sor, nodo;
	int cont=0;
	lista* head=NULL;
	init(&head,start);
	while(!empty(head)){
		sor=pop_front(&head);
		for(int j=0; j<g[sor].num; j++){
			nodo=g[sor].edges[j];
			if(!colors[nodo]){
				colors[nodo]=1;
				dist[nodo]=dist[sor]+1;
				push_back(&head,nodo);
			}
		}
	}
	deinit(&head);
	return dist[end];
}

int main(){
	int dim;
	scanf("%d", &dim);
	grafo* g=create(g,dim);
	int m;
	scanf("%d", &m);
	int start,end;
	while(m){
		scanf("%d %d", &start, &end);
		printf("%d\n", bfs(g,dim,start,end));
		m--;}
}

