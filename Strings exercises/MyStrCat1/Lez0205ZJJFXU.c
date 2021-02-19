#include <stdio.h>
#include <stdlib.h>

char *mystrcat1(char* s1, char* s2){
	char *string=malloc(2002*sizeof(char));
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
	char *s1=malloc(1001*sizeof(char));
	char *s2=malloc(1001*sizeof(char));
	scanf("%s", s1);
	scanf("%s", s2);
	printf("%s\n", mystrcat1(s1,s2));}

