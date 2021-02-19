#include <stdio.h>
#include <stdlib.h>

char *mystrcat1(char* s1, char* s2, int dim){
	char *string=malloc(dim+1*sizeof(char));
	int i=0;
	while(s1[i]){
		string[i]=s1[i];
		i++;}
	int j=0;
	while(s2[j]){
		string[i]=s2[j];
		j++;
		i++;}
	return string;}

int main(){
	int dim1;
	scanf("%d",&dim1);
	char *s1=malloc(dim1+1*sizeof(char));
	scanf("%s", s1);
	int dim2;
	scanf("%d",&dim2);
	char *s2=malloc(dim2+1*sizeof(char));
	scanf("%s", s2);
	printf("%s\n", mystrcat1(s1,s2,dim1+dim2));}

