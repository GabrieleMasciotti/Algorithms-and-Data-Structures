#include <stdio.h>
#include <stdlib.h>

void unione(int a[], int dima, int b[], int dimb, int nw[]){
	int j=0;
	int z=0;
	int i=0;
	while(i<dima && j<dimb){
			if(a[i]<b[j]) {nw[z]=a[i]; i++; z++;}
			else {nw[z]=b[j]; j++; z++;}
	}
	if(j<dimb) {for(int w=j; w<dimb; w++) {nw[z]=b[w]; z++;} }
	if(i<dima) {for(int t=i; t<dima; t++) {nw[z]=a[t]; z++;} }
}
	

int main(){
	int dima;
	scanf("%d", &dima);
	int* a=(int*)malloc(dima*sizeof(int));
	for(int i=0; i<dima; i++) scanf("%d", &a[i]);
	
	int dimb;
	scanf("%d", &dimb);
	int* b=(int*)malloc(dimb*sizeof(int));
	for(int j=0; j<dimb; j++) scanf("%d", &b[j]);

	int dimn=dima+dimb;
	int* nw=(int*)malloc(dimn*sizeof(int));
	//for(int w=0; w<dimn; w++) nw[w]=0;
	unione(a,dima,b,dimb,nw);
	for(int z=0; z<dimn; z++) printf("%d\n", nw[z]);
}

