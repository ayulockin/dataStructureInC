// inorder traversal without recurssion

#include<stdio.h>
#include<stdlib.h>

struct tree{
	struct tree *left;
	char info;
	struct tree *right;
};

struct tree *stack[10];
int top = 0;

struct tree *createList(char data){
	struct tree *curr;
	curr = (struct tree *)malloc(sizeof(struct tree));
	curr->info = data;
	curr->left = NULL;
	curr->right = NULL;
	return curr;
}

void pushleftsubtree(struct tree *node){
	while(node!=NULL){
		top++;
		stack[top] = node;
		node = node->left;
	}
}


void inorder(struct tree *root){
	stack[top] = NULL;
	struct tree *node = root;
	pushleftsubtree(node);
	node = stack[top];
	top--;
	while(top!=0 || node!= NULL){
		printf("%c\t", node->info);
		if(node->right != NULL){
			node = node->right;
			pushleftsubtree(node);
			node = stack[top];
			top--;
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
	
	inorder(root);
	
}

















