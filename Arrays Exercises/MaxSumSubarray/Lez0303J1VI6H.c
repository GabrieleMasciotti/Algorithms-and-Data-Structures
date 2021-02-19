#include <stdio.h>
#include <stdlib.h>

int sub_a_max_sum(int a[], int dim){
	int max=0;
	int somma=0;
	for(int i=0; i<dim; i++){
		if(somma>0) somma+=a[i];
		else somma=a[i];
		if(somma>max) max=somma;
	}
	return max;
}

int main(){
	int dim;
	scanf("%d", &dim);
	int* a=malloc(dim*sizeof(int));
	for(int i=0; i<dim; i++) scanf("%d", &a[i]);
	printf("%d\n", sub_a_max_sum(a,dim));
}

