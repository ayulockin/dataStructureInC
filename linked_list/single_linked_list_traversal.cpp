#include<stdio.h>
#include<stdlib.h>

#define SIZE 100;
struct link{
	int info;
	struct link *next;
};

void createList(struct link *);
void display(struct link *);

int main(){
	struct link *node;
	node = (struct link *)malloc(sizeof(struct link)); //It's a pointer 
	
	if(node== NULL){
		printf("\nOut of memory");
		exit(0);
	}
	
	createList(node);
	display(node);
}

void createList(struct link *node){
	char ch;
	int i=1;
	printf("\nEnter the valur for the %d node: ",i);
	scanf("%d", &node->info); //Entering the first value to the node pointed by node ptr
	node->next = NULL; //Setting the next part of the node to NULL
	i++;
	printf("\nPress 'n'to quit any other key to continue: ");
	fflush(stdin);
	ch = getchar();
	while(ch !='n'){
		node->next = (struct link *)malloc(sizeof(struct link)); // allocating a new pointer to the 'next' part of current node
		if(node->next == NULL){
			printf("\nOut of memory");
			exit(0);
		}
		
		node = node->next; //updating node
		printf("\nEnter the value for the %d node: ",i);
		scanf("%d", &node->info);
		node->next = NULL;
		i++;
		printf("\nPress 'n'to quit any other key to continue: ");
		fflush(stdin);
		ch = getchar();
	}
}

void display(struct link *node){
	printf("\n\nValues of nodes in the list are as follows: ");
	while(node!= NULL){
		printf("%d\t", node->info);
		node = node->next;
	}
}






