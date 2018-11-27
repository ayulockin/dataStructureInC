#include<stdio.h>
#include<stdlib.h>

// initialize TREE NODE data type
typedef struct TREE_NODE{
	struct TREE_NODE *left;
	int info;
	struct TREE_NODE *right;
} tree_node;

//void create_tree(tree_node *node){
//	char ch, left, right, op;
//	// root node complete
//	printf("Enter the value of your root node: \n");
//	scanf("%d", &node->info);
//	node->left = NULL;
//	node->right = NULL;
//	// prompt to add subtrees
//	printf("Enter 'n' to terminate, 'y' to continue: \n");
//	fflush(stdin);
//	ch = getchar();
//	while(ch!='n'){
//		tree_node *curr;
//		curr = (tree_node *)malloc(sizeof(tree_node));
//		printf("Enter 'l' for left subtree, 'r' for right subtree: \n");
//		fflush(stdin);
//		op = getchar();
//		if(op == 'l'){
//			node->left = curr;
//			node = curr;
//		}
//		else if(op == 'r'){
//			node->right = curr;
//			node = curr;
//		}
//		printf("Enter the value of your node: \n");
//	 	scanf("%d", &node->info);
//		node->left = NULL;
//		node->right = NULL;
//		printf("Enter 'n' to terminate, 'y' to continue: \n");
//		fflush(stdin);
//		ch = getchar();
//	}
//}

struct TREE_NODE createTree(int data){
	tree_node *node;
	node = (tree_node *)malloc(sizeof(tree_node));
	node->info = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}



void preorder_traversal();

int main(){
	tree_node *root;
	root = createTree(1);
	
}



















