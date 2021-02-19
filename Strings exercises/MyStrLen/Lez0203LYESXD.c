#include <stdio.h>
#include <stdlib.h>

int mystrlen(char* s){
	int i=0;
	int c=0;
	while(s[i]!='\0'){
		c=c+1;
		i=i+1;}
	return c;}

int main(){
	char* s=malloc(1000*sizeof(char));
	scanf("%s", s);
	int ris=mystrlen(s);
	printf("%d\n", ris);}

