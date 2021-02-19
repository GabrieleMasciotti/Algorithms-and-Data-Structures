#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compa(const void* a, const void* b){
	char** a1=(char**)a;
	char** b1=(char**)b;
	return (-1)*strcmp(*a1,*b1);
}

int main(){
	int i,dim;
	scanf("%d", &dim);
	char** a=(char**)malloc(dim*sizeof(char*));
	for(i=0; i<dim; i++){
		a[i]=(char*)malloc(101*sizeof(char));
		scanf("%s", a[i]);
		}
	qsort(a,dim,sizeof(char*),compa);
	for(int j=0; j<dim; j++) printf("%s\n", a[j]);
}

