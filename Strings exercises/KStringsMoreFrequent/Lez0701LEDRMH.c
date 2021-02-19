#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct c{
	char* str;
	int freq;}
	stri;

int member(stri a[], int dim, char* k){
	int trovato=0;
	int i=0;
	while(!trovato && i<dim){
		if(strcmp(a[i].str,k)==0) trovato=1;
		else i++;
	}
	if(trovato==0) return -1;	
	else return i;
}

int member1(char* a[], int dim, char* k){
	int trovato=0;
	int i=0;
	while(!trovato && i<dim){
		if(strcmp(a[i],k)==0) trovato=1;
		else i++;
	}
	if(trovato==0) return -1;	
	else return i;
}

int comp1(const void* a, const void* b){
	stri s1=*(stri*)a;
	stri s2=*(stri*)b;
	return s2.freq-s1.freq;
}

int comp(const void* a, const void* b){
	char **s1=(char**)a;
	char **s2=(char**)b;
	return strcmp(*s1,*s2);
}

int main(){
	int dim;
	scanf("%d", &dim);
	int k;
	scanf("%d",&k);
	stri* a=malloc(dim*sizeof(stri));
	for(int i=0; i<dim; i++) {
		a[i].str=malloc(101*sizeof(char));
		scanf("%s", a[i].str);
		qsort(a,i,sizeof(stri),comp1);
		int m=member(a,i,a[i].str);
		if(m!=-1) a[i].freq=a[m].freq+1; else a[i].freq=1;
	}
	qsort(a,dim,sizeof(stri),comp1);

//for(int e=0; e<dim; e++) {printf("%s, ""%d\n", a[e].str, a[e].freq);}

	char** b=malloc(k*sizeof(char*));
	int f=0;
	int z=0;
	while(z<k){
		if(f<dim){
			if(member1(b,z,a[f].str)==-1) {b[z]=malloc(101*sizeof(char)); b[z]=a[f].str; f++; z++;}
			else f++;}
	}
	qsort(b,k,sizeof(char*),comp);
	for(int y=0; y<k; y++) printf("%s\n", b[y]);
}

		



