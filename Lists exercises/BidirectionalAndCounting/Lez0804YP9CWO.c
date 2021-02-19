#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int info;
	int freq;
	struct node* prev;
	struct node* next;}
	lista;

void create_list(lista** head, int dim){
	*head=malloc(sizeof(lista));
	scanf("%d", &((*head)->info));
	(*head)->prev=NULL;
	lista* corr=*head;
	lista* prec=*head;
	for(int i=2; i<=dim;i++){
		corr->next=malloc(sizeof(lista));
		corr=corr->next;
		scanf("%d", &(corr->info));
		corr->prev=prec;
		prec=prec->next;
		corr->freq=0;}
	corr->next=NULL;
}

int func(lista* head, int el){
	int trovato=0;
	int pos=0;
	lista* corr=head;
	while(!trovato && corr!=NULL){
		if(corr->info==el) {trovato=1; (corr->freq)++;}
		else{
			corr=corr->next;
			pos++;}
	}
	if(trovato==0) return -1;
	if(corr->prev==NULL || corr->freq<=corr->prev->freq) return pos;
	while(corr->prev!=NULL && corr->freq>corr->prev->freq){
		int infotemp=corr->info;
		int freqtemp=corr->freq;
		corr->info=corr->prev->info;
		corr->freq=corr->prev->freq;
		corr->prev->info=infotemp;
		corr->prev->freq=freqtemp;
		corr=corr->prev;}
	return pos;
}

int main(){
	lista* head=NULL;
	int dim;
	scanf("%d", &dim);
	create_list(&head, dim);
	int ok=1;
	int i;
	while(ok){
		scanf("%d", &i);
		int util=func(head,i);
		if(util==-1) {ok=0; printf("%d\n", util);}
		else{
			printf("%d\n", util);}
		}
}
