#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmpfunc(const void *a, const void *b){
	int val1, val2, mod1, mod2;
	val1=*((int*)a);
	val2=*((int*)b);
	mod1=abs(val1%2);
	mod2=abs(val2%2);
	if(mod1!=mod2) return mod1-mod2;
	else if(mod1==0) return val1-val2;
	else return val2-val1;
}

int main(){
	int dim;
	scanf("%d", &dim);
	int *a=malloc(dim*sizeof(int));
	for(int i=0; i<dim; i++) scanf("%d", &a[i]);
	qsort(a,dim,sizeof(int),cmpfunc);
	for(int j=0; j<dim; j++) printf("%d\n", a[j]);
}

