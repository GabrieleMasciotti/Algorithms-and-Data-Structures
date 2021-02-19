#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int info;
	struct node* next;}
	lista;

void create(lista** head, int dim){
	*head=malloc(sizeof(lista));
	int el;
	scanf("%d", &el);
	(*head)->info=el;
	lista* corr=*head;
	for(int i=2; i<=dim; i++){
		corr->next=malloc(sizeof(lista));
		corr=corr->next;
		scanf("%d", &(corr->info));
		}
	corr->next=NULL;
}

int sum(lista* head){
	if(head==NULL) return 0;
	return (head->info)+sum(head->next);
}

void sum_print(lista** head){
	lista* corr=*head;
	while(corr!=NULL){
		corr->info=sum(corr->next);
		corr=corr->next;}
}

void print_list(lista* head){
	if(head==NULL) return;
	printf("%d ", head->info);
	print_list(head->next);
}

int main(){
	int dim;
	scanf("%d", &dim);
	lista* head=NULL;
	create(&head, dim);
	print_list(head);
	printf("\n");
	sum_print(&head);
	print_list(head);
	printf("\n");
}
