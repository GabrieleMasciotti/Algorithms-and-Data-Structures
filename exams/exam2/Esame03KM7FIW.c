#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int info;
	struct node* left;
	struct node* right;}
	tree;

tree* insert(tree* abr, int el){
	if(abr==NULL){
		tree* new=malloc(sizeof(tree));
		new->info=el;
		new->left=NULL;
		new->right=NULL;
		return new;}
	if(abr->info<el) abr->right=insert(abr->right,el);
	else abr->left=insert(abr->left,el);
	return abr;
}

void create(tree** abr, int dim){
	int el;
	for(int i=0; i<dim; i++){
		scanf("%d", &el);
		*abr=insert(*abr,el);}
}

int left_visit(tree* abr){
	if(abr==NULL) return -1;
	return 1+left_visit(abr->left);
}

int right_visit(tree* abr){
	if(abr==NULL) return -1;
	return 1+right_visit(abr->right);
}

int* func_ris(tree* abr){
	if(abr!=NULL){
	func_ris(abr->left);
	if(left_visit(abr)>right_visit(abr))
		printf("%d\n", abr->info);
	func_ris(abr->right);}
}

int main(){
	int dim;
	scanf("%d", &dim);
	tree* abr=NULL;
	create(&abr,dim);
	func_ris(abr);
}

