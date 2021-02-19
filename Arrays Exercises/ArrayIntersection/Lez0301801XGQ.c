#include <stdio.h>
#include <stdlib.h>

int member(int a[], int n, int k){
	int i=0;
	int trovato=0;
	while(i<n && trovato==0){
		if(a[i]==k) trovato=1;
		else i++;
	}
	return trovato;
}

int share(int a[], int n, int b[], int m){
	int i=0;
	int conto=0;
	while(i<n){
		if(member(b,m,a[i])) conto++;
		i++;
		}
	return conto;
}

int main(){
	int n;
	scanf("%d", &n);
	int* a=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++) {scanf("%d", &a[i]);}
	
	int m;
	scanf("%d", &m);
	int* b=(int*)malloc(m*sizeof(int));
	for(int j=0;j<m;j++) {scanf("%d", &b[j]);}
	printf("%d\n", share(a,n,b,m));
}

