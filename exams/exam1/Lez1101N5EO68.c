#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char* name;
	struct node* next;}
	lista;

lista* add_patient(lista* head, char* namepat){
	if(head==NULL){
		head=malloc(sizeof(lista));
		(head)->name=malloc(strlen(namepat)*sizeof(char));
		(head)->name=namepat;
		(head)->next=NULL;
		}
	else{
		lista* corr=head;
		while(corr->next!=NULL) {corr=corr->next;}
		lista* new=malloc(sizeof(lista));
		new->name=malloc(strlen(namepat)*sizeof(char));
		new->name=namepat;
		new->next=NULL;
		corr->next=new;}
	return head;
}

void delpat(lista** head){
	if(*head!=NULL){
	lista* aux=*head;
	*head=(*head)->next;
	free(aux);
}}

char** list_to_array(lista** head, int len){
	char** a=malloc(len*sizeof(char*));
	lista* corr=*head;
	for(int i=0; i<len; i++){
		a[i]=malloc(strlen(corr->name)*sizeof(char));
		a[i]=corr->name;
		corr=corr->next;}
	return a;
}

int compare(const void* a, const void* b){
	char** a1=(char**)a;
	char** b1=(char**)b;
	return strcmp(*a1,*b1);
}

int main(){
	lista* head=NULL;
	int e;
	int len=0;
	scanf("%d", &e);
	while(e!=0){
		if(e==1){
			char* namepat=malloc(101*sizeof(char));
			scanf("%s", namepat);
			head=add_patient(head,namepat);
			len++;
			scanf("%d", &e);
			}
		else{ if(e==2) {delpat(&head); len--;
				scanf("%d", &e);}
			}
	}
	char** arr=list_to_array(&head,len);
	qsort(arr,len,sizeof(char*),compare);
	for(int i=0; i<len; i++) printf("%s\n", arr[i]);
	printf("$\n");
}

