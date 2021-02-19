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

tree* create(tree* abr, int dim){
	int el;
	for(int i=0; i<dim; i++){
		scanf("%d", &el);
		abr=insert(abr,el);}
	return abr;
}

void print_simm_ord(tree* abr){
	if(abr==NULL) return;
	print_simm_ord(abr->left);
	printf("%d\n", abr->info);
	print_simm_ord(abr->right);
}

int main(){
	int dim;
	scanf("%d", &dim);
	tree* abr=NULL;
	abr=create(abr,dim);
	print_simm_ord(abr);
}
