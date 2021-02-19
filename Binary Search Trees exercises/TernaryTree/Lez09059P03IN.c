#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int info;
	struct node* left;
	struct node* middle;
	struct node* right;}
	tree;

tree* insert_middle(tree* abrt, int el){
	if(abrt==NULL) {
		abrt=malloc(sizeof(tree));
		abrt->info=el;
		abrt->left=NULL;
		abrt->middle=NULL;
		abrt->right=NULL;
		return abrt;}
	if(el%abrt->info==0) abrt->middle=insert_middle(abrt->middle,el); //attenzione a chi deve essere divisibile per cosa...
	else {
		if(abrt->info>el) abrt->left=insert_middle(abrt->left,el);
		else abrt->right=insert_middle(abrt->right,el);}
	return abrt;
}

tree* create(tree* abrt, int dim){
	int el;
	for(int i=0; i<dim; i++){
		scanf("%d", &el);
		abrt=insert_middle(abrt,el);}
	return abrt;
}

int count_tree_sons(tree* abrt){
	if(abrt==NULL) return 0;
	if(abrt->left!=NULL && abrt->middle!=NULL && abrt->right!=NULL) 
		return 1+count_tree_sons(abrt->left)+count_tree_sons(abrt->middle)+count_tree_sons(abrt->right);
	return count_tree_sons(abrt->left)+count_tree_sons(abrt->middle)+count_tree_sons(abrt->right);}

int main(){
	int dim;
	scanf("%d", &dim);
	tree* abrt=NULL;
	abrt=create(abrt,dim);
	printf("%d\n", count_tree_sons(abrt));
}
