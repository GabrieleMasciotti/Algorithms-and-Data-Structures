#include <stdio.h>
#include <stdlib.h>

int* findval(int a[], int len, int val){
	int i;
	int* ris=NULL;
	for(i=0; i<len; i++){
		if(a[i]==val) ris=&a[i];
	}
	return ris;}

int main(){
	int *a=malloc(10*sizeof(int));
	int i=0;
	while(i<10){
		scanf("%d", &a[i]);
		i++;}
	int val;
	scanf("%d", &val);
	int *ris=findval(a,10,val);
	if(ris!=NULL) printf("trovato\n");
	else printf("non trovato\n");}

