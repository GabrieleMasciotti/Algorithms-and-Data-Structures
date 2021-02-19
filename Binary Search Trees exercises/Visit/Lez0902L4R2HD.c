#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int info;
	struct node* left;
	struct node* right;}
	tree;

tree* insert(tree* abr, int el){
	if(abr==NULL){
		abr=malloc(sizeof(tree));
		abr->info=el;
		abr->left=NULL;
		abr->right=NULL;
		return abr;}
	if(abr->info>el) abr->left=insert(abr->left,el);
	else abr->right=insert(abr->right,el);
	return abr;
}

tree* create_abr(tree* abr, int dim){
	int el;
	for(int i=0; i<dim; i++){
		scanf("%d", &el);
		abr=insert(abr,el);}
	return abr;
}

int height(tree* abr){
	if(abr==NULL) return 0;
	int hl=height(abr->left);
	int hr=height(abr->right);
	if(hl>hr) return hl+1;
	else return hr+1;
}

int main(){
	int dim;
	scanf("%d", &dim);
	tree* abr=NULL;
	abr=create_abr(abr,dim);
	printf("%d\n", height(abr));
}
