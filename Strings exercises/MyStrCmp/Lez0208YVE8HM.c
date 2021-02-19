#include <stdio.h>
#include <stdlib.h>

int mystrcmp(char*s1, char*s2){
	int i=0;
	while(s1[i] && s2[i] && s1[i]==s2[i]) i++;
	if(s1[i]=='\0' && s2[i]=='\0') printf("0\n");
	else{
		if(s1[i]=='\0' && s2[i]!='\0') printf("-1\n");
		else{
			if(s1[i]!='\0' && s2[i]=='\0') printf("+1\n");
			else{
				if(s1[i]>s2[i]) printf("+1\n");
				else{
				printf("-1\n");}
}}}}

int main(){
	char* s1=malloc(1001*sizeof(char));
	char* s2=malloc(1001*sizeof(char));
	scanf("%s", s1);
	scanf("%s", s2);
	mystrcmp(s1,s2);
}
