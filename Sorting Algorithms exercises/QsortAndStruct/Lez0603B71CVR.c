#include <stdio.h>
#include <stdlib.h>

typedef struct p{
	int x;
	int y;
	}
	point;

int compare(const void* a, const void* b){
	point val1=*(point*)a;
	point val2=*(point*)b;
	if((val1.x)!=(val2.x)) return (val1.x)-(val2.x);
	else return (val2.y)-(val1.y);
}

int main(){
	int dim;
	scanf("%d", &dim);
	point* a=malloc(dim*sizeof(point));
	for(int i=0; i<dim; i++){
		scanf("%d " "%d", &(a[i].x), &(a[i].y));
	}
	qsort(a,dim,sizeof(point),compare);
	for(int j=0; j<dim; j++) printf("%d " "%d\n", a[j].x, a[j].y);
}


