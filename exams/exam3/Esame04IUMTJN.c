#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pos(char* nome, int dim){
	int cont=0;
	int i=0;
	while(nome[i]!='\0'){
		cont=cont+nome[i];
		i++;}
	return cont%(2*dim);
}

typedef struct node{
	char* nome;
	char* numero;
	struct node* next;
} list;

void insert(list **T , char *val){
	list *new = malloc(sizeof(list));
	new->numero = malloc(21 * sizeof(char));
	scanf("%s",new->numero);
	new->nome = malloc(101 * sizeof(char));
	strcpy(new->nome , val);
	list *corr = *T;
	list *prec = NULL;

	if(*T == NULL){
		new->next = *T;	    // prende NULL
		*T = new; }
	else{ 
		while(corr != NULL && strcmp(new->nome , corr->nome) > 0){
			prec = corr;
			corr = corr->next;
			}
		if(corr == *T){
			new->next = *T;	        // prende *T (la testa della lista)
			*T = new;
			}
		else{
			new->next = corr;
			prec->next = new;
			}
			
	}
}

int main(){
	int dim;
	scanf("%d", &dim);
	list** rubrica=malloc((2*dim)*sizeof(list*));
	int p;
	char* n;
	for(int i=0; i<dim; i++){
		n=malloc(101*sizeof(char));
		scanf("%s", n);
		p=pos(n,dim);
		insert(&rubrica[p],n);
		free(n);}	
	int k;
	scanf("%d", &k);
	list* aux=rubrica[k];
	while(aux!=NULL){
		printf("%s %s\n", aux->nome, aux->numero);
		aux=aux->next;}
}
