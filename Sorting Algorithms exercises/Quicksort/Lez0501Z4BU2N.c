#include <stdio.h>
#include <stdlib.h>

int partiziona(int a[], int sx, int dx){
	int pivot=a[dx];
	int i=sx-1;
	for(int j=sx; j<dx; j++){
		if(a[j]<=pivot){
		i++;
		int temp=a[j];
		a[j]=a[i];
		a[i]=temp;}}
	int temp1=a[dx];
	a[dx]=a[i+1];
	a[i+1]=temp1;
	return i+1;
}

void QuickSort(int a[], int sx, int dx){
	if(sx<dx){
		int q=partiziona(a,0,dx);
		QuickSort(a,sx,q-1);
		QuickSort(a,q+1,dx);}
}

int main(){
	int dim;
	scanf("%d", &dim);
	int* a=malloc(dim*sizeof(int));
	for(int i=0; i<dim; i++) scanf("%d", &a[i]);
	QuickSort(a,0,dim-1);
	for(int j=0; j<dim; j++) printf("%d ", a[j]);
}

