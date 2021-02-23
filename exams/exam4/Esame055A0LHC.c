#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct el{
	char* nome;
	int credito;
	int diffi;}
	esame;

int super_comp(const void* a, const void* b){
	esame es1=*(esame*)a;
	esame es2=*(esame*)b;
	if(es2.credito==es1.credito){
		if(es2.diffi==es1.diffi) return strcmp(es1.nome,es2.nome);
		else return es1.diffi-es2.diffi;}
	else return es2.credito-es1.credito;
}

int comp_aux(const void* a, const void* b){
	char** s1=(char**)a;
	char** s2=(char**)b;
	return strcmp(*s1,*s2);
}

int main(){
	int k;
	scanf("%d", &k);
	int n;
	scanf("%d", &n);
	esame* esami=malloc(n*sizeof(esame));
	for(int i=0; i<n; i++){
		esami[i].nome=malloc(101*sizeof(char));
		scanf("%s", esami[i].nome);
		scanf("%d", &(esami[i].credito));
		scanf("%d", &(esami[i].diffi));
		}
	qsort(esami,n,sizeof(esame),super_comp);
	int ok=0;
	int cont=0;
	int j=0;
	int z=0;
	char** a=malloc(n*sizeof(char*));
	while(!ok && j<n){
		if(cont+esami[j].credito==k){
			a[z]=malloc(101*sizeof(char));
			strcpy(a[z],esami[j].nome);
			ok=1;}
		else {
				if(cont+esami[j].credito>k){
					j++;}
				else{
					cont+=esami[j].credito;
					a[z]=malloc(101*sizeof(char));
					strcpy(a[z],esami[j].nome);
					z++;
					j++;}
			}
	}
	qsort(a,z+1,sizeof(char*),comp_aux);
	for(int h=0; h<=z; h++) printf("%s\n", a[h]);
}
