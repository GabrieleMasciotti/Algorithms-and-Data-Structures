#include <stdio.h>
#include <stdlib.h>

char* mystrcat(char*s1, char*s2){
	int i=0;
	while(s1[i]) i++;
	int j=0;
	while(s2[j]){
		s1[i]=s2[j];
		i++;
		j++;
		}
	s1[i]='\0';
	return s1;
}

int main(){
	char* s1=malloc(1001*sizeof(char));
	char* s2=malloc(1001*sizeof(char));
	scanf("%s", s1);
	scanf("%s", s2);
	printf("%s\n", mystrcat(s1,s2));
}
