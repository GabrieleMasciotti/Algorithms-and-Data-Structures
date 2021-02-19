#include <stdio.h>
#include <stdlib.h>

int bin_search(int a[], int sx, int dx, int k){
	if(sx>dx) return 0;
		int cx=(sx+dx)/2;
		if(a[cx]==k) return 1;
		if(k<a[cx]) bin_search(a, sx, cx-1, k);
		else bin_search(a, cx+1, dx, k);
		
}

int main(){
	int dim1;
	scanf("%d", &dim1);
	int* A=malloc(dim1*sizeof(int));
	for(int i=0; i<dim1; i++) scanf("%d", &A[i]);
	
	int dim2;
	scanf("%d", &dim2);
	int* B=malloc(dim2*sizeof(int));
	for(int j=0; j<dim2; j++) scanf("%d", &B[j]);
	
	int ris=0;
	for(int in=0; in<dim1; in++){
		ris=ris+bin_search(B, 0, dim2-1, A[in]);}
	printf("%d\n", ris);
}
