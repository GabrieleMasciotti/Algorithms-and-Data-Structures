#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int a[], int dim){
	int key;
	int i;
	for(int j=1; j<dim; j++){
		key=a[j];
		i=j-1;
		while(i>=0 && a[i]>key){
			a[i+1]=a[i];
			i=i-1;
		}
	a[i+1]=key;
	}
}

int main(){
	int dim;
	scanf("%d", &dim);
	int* a=malloc(dim*sizeof(int));
	for(int i=0; i<dim; i++) scanf("%d", &a[i]);
	InsertionSort(a,dim);
	for(int h=0; h<dim; h++) printf("%d\n", a[h]);
}


