#include <stdio.h>
#include <stdlib.h>

char* mystrcpy(char* dest, char* src){
	int i=0;
	while(src[i]){
		dest[i]=src[i];
		i++;
		}
	dest[i]='\0';
	return dest;
}

int main(){
	char* src=malloc(1001*sizeof(char));
	char* dest=malloc(1001*sizeof(char));
	scanf("%s", src);
	printf("%s\n", mystrcpy(dest, src));
}
