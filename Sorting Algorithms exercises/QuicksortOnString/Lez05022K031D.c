#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int partiziona(char* a[], int sx, int dx){
	char* pivot=a[dx];
	int i=sx-1;
	for(int j=sx; j<dx; j++){
		if(strcmp(a[j],pivot)<=0){      /*a[j]<=pivot*/
		i++;
		char* temp=a[j];
		a[j]=a[i];
		a[i]=temp;}}
	char* temp1=a[dx];
	a[dx]=a[i+1];
	a[i+1]=temp1;
	return i+1;
}

void QuickSort(char* a[], int sx, int dx){
	if(sx<dx){
		int q=partiziona(a,0,dx);
		QuickSort(a,sx,q-1);
		QuickSort(a,q+1,dx);}
}

int main(){
	int dim;
	scanf("%d", &dim);
	char** a=malloc(dim*sizeof(char*));
	for(int i=0; i<dim; i++){
		a[i]=malloc(101*sizeof(char));
		scanf("%s", a[i]);}
	QuickSort(a,0,dim-1);
	for(int j=0; j<dim; j++) printf("%s\n", a[j]);
}
