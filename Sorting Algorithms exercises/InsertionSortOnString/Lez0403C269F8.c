#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InsertionStringSort(char* a[], int dim){
	char* key;
	int i;
	for(int j=1; j<dim; j++){
		key=a[j];
		i=j-1;
		while((i>=0) && (strcmp(a[i], key)>0)){
			a[i+1]=a[i];
			i=i-1;
		}
	a[i+1]=key;
	}
}

int main(){
	int dim;
	scanf("%d", &dim);
	char** a=(char**)malloc(dim*sizeof(char*));
	for(int i=0; i<dim; i++){
		a[i]=(char*)malloc(101*sizeof(char));
		scanf("%s", a[i]);
		}
	InsertionStringSort(a,dim);
	for(int j=0; j<dim; j++) printf("%s\n", a[j]);
}
