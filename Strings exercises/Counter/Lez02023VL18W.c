#include <stdio.h>
#include <stdlib.h>

void reset(int a[], int dim){
	for(int i=0;i<dim;i++){
		a[i]=0;}
}

void add(int a[], int dim, int val){
	if(val>=0 && val<dim) a[val]+=1;
}

int main(){
	int* a= (int*) malloc(10*sizeof(int));
	reset(a,10);
	int n;
	scanf("%d",&n);
	while(n!=-1){
		add(a,10,n);
		scanf("%d",&n);
		}
	for(int j=0;j<10;j++) printf("%d\n",a[j]);
}
