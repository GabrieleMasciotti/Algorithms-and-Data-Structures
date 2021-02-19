#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node{
	int info;
	struct node* next;
} lista;

int create(lista** head, int dim){
	int sum=0;
	*head=malloc(sizeof(lista));
	scanf("%d", &((*head)->info));
	sum+=((*head)->info);
	lista* corr=*head;
	for(int i=2; i<=dim; i++){
		corr->next=malloc(sizeof(lista));
		corr=corr->next;
		scanf("%d", &(corr->info));
		sum+=(corr->info);
		}
	corr->next=NULL;
	return sum;
}

void avg_delete(lista** head, int avg){
	lista* prec=NULL;
	lista* corr=*head;
	while(corr!=NULL){
		if(prec==NULL){
			if(corr->info<=avg){
				lista* aux=corr;
				corr=corr->next;
				*head=corr;
				free(aux);
				}
			else{
				prec=corr;
				corr=corr->next;
				}}
		else{
			if(corr->info<=avg){
				lista* aux=corr;
				corr=corr->next;
				prec->next=corr;
				free(aux);}
			else{
				prec=prec->next;
				corr=corr->next;}}
	}
}

void printlist(lista* head){
	if(head==NULL) return;
	printf("%d ", head->info);
	printlist(head->next);
}
	

int main(){
	int dim;
	scanf("%d", &dim);
	lista* head=NULL;
	int sum=create(&head,dim);
	int avg=sum/dim;
	printf("%d\n",avg);
	printlist(head);
	printf("\n");
	avg_delete(&head, avg);
	printlist(head);
	printf("\n");
}
	







	
