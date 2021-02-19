#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int info;
	struct node* left;
	struct node* right;}
	nodo;

/*void create_abr(nodo** tree, int dim){       //FUNZIONE CREATE UNICA SENZA INSERZIONE SEPARATA
	int n=dim;
	int el;
	scanf("%d", &el);
	nodo* new=malloc(sizeof(nodo));
	new->info=el;
	new->left=NULL;
	new->right=NULL;
	n--;
	*tree=new;
	nodo* corr;
	while(n>0){
		corr=*tree;
		scanf("%d", &el);
		while(corr->left!=NULL && corr->right!=NULL){
			if(el<corr->info) corr=corr->left;
			else corr=corr->right;}
		if(el<corr->info && corr->left==NULL){
			corr->left=malloc(sizeof(nodo));
			corr=corr->left;
			corr->info=el;
			corr->left=NULL;
			corr->right=NULL;
			n--;}
		else{
			corr->right=malloc(sizeof(nodo));
			corr=corr->right;
			corr->info=el;
			corr->left=NULL;
			corr->right=NULL;
			n--;}
		}
}*/

nodo* inserisciRic(nodo *t, int key) {
	if (t == NULL) {    
		nodo* new = (nodo *) malloc(sizeof(nodo));
		new->info=key;
		new->left=NULL;
		new->right=NULL;
		return new;}
	if(t->info < key) t->right=inserisciRic(t->right, key);
	else t->left=inserisciRic(t->left, key);
	return t;
} 

void insert(nodo** tree, int el){
	if(*tree==NULL){
		nodo* new=malloc(sizeof(nodo));
		new->info=el;
		new->left=NULL;
		new->right=NULL;
		*tree=new;}
	else{
		if(el<(*tree)->info) insert(&((*tree)->left), el);
		else insert(&((*tree)->right), el);}
}

void create_abrr(nodo** tree, int dim){
	int el;                             //FUNZIONE CREATE CHE UTILIZZA INSERZIONE SEPARATA
	for(int i=0; i<dim; i++){
		scanf("%d", &el);
		//*tree=inserisciRic(*tree, el);
		insert(tree,el);
		}
}

void print_abr(nodo* tree){
	if(tree==NULL) return;
	printf("%d ", tree->info);
	print_abr(tree->left);
	print_abr(tree->right);
}

int search_abr(nodo* tree, int el){
	if(tree==NULL) return -1;
	if(tree->info==el) return 0;
	int trovato=-1;
	if(el<tree->info) trovato=search_abr(tree->left, el);
	else trovato=search_abr(tree->right, el);
	if(trovato==-1) return -1;
	else return trovato+1;
}

int main(){
	int dim;
	scanf("%d", &dim);
	nodo* tree=NULL;
	create_abrr(&tree, dim);
	int ok=1;
	int i;
	int ris;
	while(ok){
		scanf("%d", &i);
		if(i<0) ok=0;
		else{
			ris=search_abr(tree, i);
			if(ris==-1) {
				printf("NO\n");}
			else{
				printf("%d\n", ris);
				}
		}
	}
	/*print_abr(tree);
	printf("\n");*/
}
