#include <stdio.h>
#include <stdlib.h>

int anagramma(unsigned char *s1, unsigned char *s2){
	int a1[256]; for(int x=0;x<256;x++) a1[x]=0;
	int a2[256]; for(int b=0;b<256;b++) a2[b]=0;
	int i=0;
	int j=0;
	while(s1[i]) {a1[s1[i]]+=1; i+=1;}
	while(s2[j]) {a2[s2[j]]+=1; j+=1;}
	int z=0;
	int ok=1;
	while(ok && z<256) {
		if(a1[z]!=a2[z]) ok=0;
		else z+=1;}
	return ok;
}

int main(){
	unsigned char *s1=malloc(1000*sizeof(char));
	scanf("%s",s1);
	unsigned char *s2=malloc(1000*sizeof(char));
	scanf("%s",s2);
	printf("%d\n", anagramma(s1,s2));
}
