#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int info;
	struct lista* next;}
	lista;

void print_inv(lista* head){
	if(head==NULL) return;
	print_inv(head->next);
	printf("%d\n", head->info);
}

/*void create_list_rifer(lista** head, int dim){
	*head=malloc(sizeof(lista));
	scanf("%d", &((*head)->info));       //IMPORTANTI LE PARENTESI INTORNO A (*HEAD)
	lista* corr=*head;
	for(int i=2; i<=dim; i++){
		corr->next=malloc(sizeof(lista));
		corr=corr->next;
		scanf("%d", &(corr->info));
		}
	corr->next=NULL;
	}*/

lista* create_list_valore(lista* head, int dim){
	head=malloc(sizeof(lista));
	scanf("%d", &(head->info));
	lista* corr=head;
	for(int i=2; i<=dim; i++){
		corr->next=malloc(sizeof(lista));
		corr=corr->next;
		scanf("%d", &(corr->info));}
	corr->next=NULL;
	return head;
}

int main(){
	int dim;
	scanf("%d", &dim);
	
	//lista* head=NULL;
	
	/*int el;
	scanf("%d", &el);
	head=malloc(sizeof(lista));
	head->info=el;
	lista* corr=head;
	for(int i=2; i<=dim; i++){
		corr->next=malloc(sizeof(lista));
		corr=corr->next;
		scanf("%d", &(corr->info));}
	corr->next=NULL;*/
	

	//create_list_rifer(&head,dim);

	lista* head=create_list_valore(head,dim);
	print_inv(head);
	










}
