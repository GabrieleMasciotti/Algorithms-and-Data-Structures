#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int info;
	struct node* next;}
	lista;

lista* create_list(lista* head, int dim){
	head=malloc(sizeof(lista));
	scanf("%d", &(head->info));
	lista* corr=head;
	for(int i=2; i<=dim; i++){
		corr->next=malloc(sizeof(lista));
		corr=corr->next;
		scanf("%d", &(corr->info));
		}
	corr->next=NULL;
	return head;
}

int MTF(lista** head, int el){
	if((*head)->info==el) return 0;
	int trovato=0;
	lista* prec=*head;
	lista* corr=(*head)->next;
	int i=1;
	while(corr!=NULL && !trovato){
		if(corr->info==el) trovato=1;
		else{
			i++;
			prec=prec->next;
			corr=corr->next;}
	}
	if(trovato==0) return -1;
	int aux=corr->info;
	prec->next=corr->next;
	free(corr);
	lista* new=malloc(sizeof(lista));
	new->info=aux;
	new->next=*head;
	*head=new;
	return i;
}

int main(){
	int dim;
	scanf("%d", &dim);
	lista* head=create_list(head, dim);
	int ok=1;
	int el;
	while(ok){
		scanf("%d", &el);
		int i=MTF(&head,el);
		if(i==-1) {ok=0; printf("%d\n", i);}
		else{
			printf("%d\n", i);}
	}
}






