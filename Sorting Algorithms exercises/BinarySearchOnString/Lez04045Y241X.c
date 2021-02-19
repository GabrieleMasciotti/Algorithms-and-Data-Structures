#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int StringBinarySearch(char* a[], int sx, int dx, char* str){
	if(sx>dx) return -1;
		int cx=(sx+dx)/2;
		if(strcmp(a[cx],str)==0) return cx;
		if(strcmp(a[cx], str)<0) return StringBinarySearch(a,cx+1,dx,str);
		else return StringBinarySearch(a,sx,cx-1,str);
	/*else{if(sx==dx){
		if(strcmp(a[sx],str)==0) return sx;
		else return -1;}}*/
}

int main(){
	int dim;
	scanf("%d", &dim);
	char** a=(char**)malloc(dim*sizeof(char*));

	for(int i=0; i<dim; i++){
		a[i]=(char*)malloc(101*sizeof(char));

		scanf("%s", a[i]);
		}
	int continua;
	char stringa[101];
	scanf("%d", &continua);
	while(continua){
		scanf("%s", stringa);
		printf("%d\n", StringBinarySearch(a,0,(dim-1),stringa));
		scanf("%d", &continua);}
}


