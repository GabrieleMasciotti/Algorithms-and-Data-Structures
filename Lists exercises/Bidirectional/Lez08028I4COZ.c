#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int info;
	struct node* prev;
	struct node* next;}
	lista;

void create_list(lista** head,int dim){
	*head=malloc(sizeof(lista));
	scanf("%d", &((*head)->info));
	(*head)->prev=NULL;
	lista* corr=*head;
	lista* prec=*head;
	for(int i=2; i<=dim; i++){
		corr->next=malloc(sizeof(lista));
		corr=corr->next;
		scanf("%d", &(corr->info));
		corr->prev=prec;
		prec=prec->next;}
	corr->next=NULL;
}

void print_list_inv(lista* head){
	lista* corr=head;
	while(corr->next!=NULL) corr=corr->next;
	while(corr!=NULL){
		printf("%d\n", corr->info);
		corr=corr->prev;}
}

int main(){
	int dim;
	scanf("%d", &dim);
	lista* head=NULL;
	create_list(&head,dim);
	print_list_inv(head);
}
