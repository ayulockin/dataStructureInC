// circular doubly linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
	struct NODE *prev;
	int info;	
	struct NODE *next;
} dlink;

dlink *start;

void createList(dlink *);
void displayList(dlink *);

int main(){
	dlink *node;
	node = (dlink *)malloc(sizeof(dlink));
	start = node;
	createList(node);
	displayList(node);
}

void createList(dlink *node){
	dlink *curr;
	start = node;
	int i=1; char ch;
	printf("Enter the value of %d node: \n", i);
	scanf("%d", &node->info);
	node->next = start;
	node->prev = start;
	printf("Enter 'n' to quit | 'y' to continue: \n");
	fflush(stdin);
	ch = getchar();
	i++;
	while(ch!='n'){
		curr = (dlink *)malloc(sizeof(dlink));
		printf("Enter the value of %d node: \n", i);
		scanf("%d", &curr->info);
		curr->next = start;
		curr->prev = node;
		node->next = curr;
		node = curr;
		start->prev = curr;
		printf("Enter 'n' to quit | 'y' to continue: \n");
		fflush(stdin);
		ch = getchar();
		i++;
	}
}


void displayList(dlink *node){
	dlink *temp;
	temp = node;
	
	do{
		printf("%d\t", node->info);
		node = node->next;
	}while(node!=temp);
	printf("\n");
	node = node->prev;
	temp = node;
	do{
		printf("%d\t", node->info);
		node = node->prev;
	}while(node!=temp);
}











