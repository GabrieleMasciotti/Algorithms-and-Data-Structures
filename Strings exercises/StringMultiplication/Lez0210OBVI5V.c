#include <stdio.h>
#include <stdlib.h>

int len(char* str){
	int i=0;
	int len=0;
	while(str[i]){
		len++;
		i++;
	}
	return len;
}

char* product(char* str, int k){
	int l=len(str);
	char* pr=malloc(k*(l*sizeof(char)));
	int j=0;
	while(k>0){
		int i=0;
		while(str[i]){
			pr[j]=str[i];
			i++;
			j++;
			}
		k--;
	}
	pr[j]='\0';
	return pr;
}

int main(){
	char* string=malloc(1001*sizeof(char));
	scanf("%s", string);
	int k;
	scanf("%d", &k);
	printf("%s\n", product(string, k));
}
