// non recursive approach to preorder tree transversal

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct tree{
	struct tree *left;
	char info;
	struct tree *right;
};

struct tree *stack[SIZE];
int top = 0;

struct tree *createList(char data){
	struct tree *curr;
	curr = (struct tree *)malloc(sizeof(struct tree));
	curr->info = data;
	curr->left = NULL;
	curr->right = NULL;
	return curr;
}


void preorder(struct tree *root){
	stack[0] = NULL;
	top++;	
	struct tree *node;
	node = root;
	while(top!=0){
		printf("%c\t", node->info);
		if(node->right!=NULL){
			top++;
			stack[top] = node->right;
		}
		if(node->left != NULL){
			node = node->left;
		}
		else{
			node = stack[top];
			top--;
		}
		
	}
	
}

int main(){
	struct tree *root;
	root = createList('A');
	root->left = createList('B');
	root->right = createList('C');
	root->left->left = createList('D');
	root->left->left->right = createList('G');
	root->right->left = createList('E');
	root->right->right = createList('F');
	
	/*
				A
			B			C
		D			E		F	
			G
		
	*/
	
	preorder(root);
	
}



