#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int info;
	struct node* left;
	struct node* right;
}	tree;

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

int conf_abr(tree* abr1, tree* abr2, int k){
	while(abr1!=NULL && abr2!=NULL){
		if(abr1->info==k && abr2->info==k) return 1;
		if(abr1->info!=abr2->info) return 0;
		if(abr1->info>k) abr1=abr1->left;
		else abr1=abr1->right;
		if(abr2->info>k) abr2=abr2->left;
		else abr2=abr2->right;
	}
	if(abr1==NULL || abr2==NULL) return 0;
}

int main (){
	int dim,k;
	scanf("%d %d", &dim, &k);
	tree* abr1=NULL;
	abr1=create(abr1,dim);
	tree* abr2=NULL;
	abr2=create(abr2,dim);
	printf("%d\n", conf_abr(abr1,abr2,k));
}
