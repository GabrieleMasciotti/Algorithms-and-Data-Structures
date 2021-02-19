#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s{
	char* str;
	int len;}
	string;


int compstr(const void* a, const void* b){
	string s1=*(string*)a;
	string s2=*(string*)b;
	if(s1.len!=s2.len) return s1.len-s2.len;
	else return strcmp(s1.str,s2.str);
}

int main(){
	int dim;
	scanf("%d", &dim);
	string* a=malloc(dim*sizeof(string));
	for(int i=0; i<dim; i++) {
		a[i].str=malloc(101*sizeof(char));
		scanf("%s", a[i].str);
		a[i].len=strlen(a[i].str);}
	qsort(a,dim,sizeof(string),compstr);
	for(int j=0; j<dim; j++) printf("%s\n", a[j].str);
}

