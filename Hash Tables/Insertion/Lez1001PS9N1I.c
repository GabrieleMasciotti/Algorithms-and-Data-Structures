#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int info;
	struct node* next;}
	tab;

int len(tab* lista){
	if(lista==NULL) return 0;
	return 1+len(lista->next);
}

int posizione(int el, int a, int b, int dim){
	return ((a*el+b)%999149)%(2*dim);
}

void add(tab** lista, int el){
	tab* new=malloc(sizeof(tab));
	new->info=el;
	new->next=*lista;
	*lista=new;
}

int main(){
	int dim;
	scanf("%d", &dim);
	int a,b;
	scanf("%d", &a);
	scanf("%d", &b);
	tab** hash=malloc(2*dim*(sizeof(tab*)));
	int conf=0;
	int max=0;
	int pos;
	int el;
	for(int i=0; i<dim; i++){
		scanf("%d", &el);
		pos=posizione(el,a,b,dim);
		if(hash[pos]!=NULL) conf++;
		add(&hash[pos],el);
		}
	int u;
	for(int j=0; j<2*dim; j++){
		u=len(hash[j]);
		if(u>max) max=u;
	}
	printf("%d\n", max);
	printf("%d\n", conf);
}

