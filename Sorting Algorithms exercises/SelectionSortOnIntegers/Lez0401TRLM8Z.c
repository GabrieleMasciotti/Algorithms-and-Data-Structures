#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int a[], int dim){
	int min;
	int temp;
	for(int j=0; j<dim-1; j++){
		min=j;
		for(int i=j+1; i<dim; i++){
			if(a[i]<a[min]) min=i;}
		temp=a[min];
		a[min]=a[j];
		a[j]=temp;
		}
}

int main(){
	int dim;
	scanf("%d", &dim);
	int* a=malloc(dim*sizeof(int));
	for(int i=0; i<dim; i++) scanf("%d", &a[i]);
	SelectionSort(a,dim);
	for(int h=0; h<dim; h++) printf("%d\n", a[h]);
}

