#include<stdio.h>
#include<stdlib.h>

struct tree{
	struct tree *left;
	int info;
	struct tree *right;
};

struct tree* createTree(int data){
	struct tree *node = (struct tree *)malloc(sizeof(struct tree));
	node->info = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void preorder(struct tree *node){
	 if(node == NULL){return;}
	 printf("%d\t", node->info);
	 preorder(node->left);
	 preorder(node->right);
}



int main(){
	struct tree *root = createTree(1);
	root->left = createTree(2);
	root->right = createTree(3);
	root->left->left = createTree(4);
	root->left->right = createTree(5);
	root->left->right->left = createTree(6);
	
	preorder(root);
}

