// create a double linked list
// traverse the linked list formed

#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
	struct NODE *prev;
	int info;
	struct NODE *next;
} dlink;


void createdlink(dlink *);
void displaydlink(dlink *);

int main(){
	dlink *node;
	node = (dlink *)malloc(sizeof(dlink));
	if(node==NULL){
		printf("Out of memory\n");
		exit(0);
	}
	createdlink(node);
	displaydlink(node);
}


void createdlink(dlink *node){
	dlink *curr;
	int i = 1;
	char ch;
	printf("enter the value of %d node: ", i);
	scanf("%d", &node->info);
	node->prev = NULL;
	node->next = NULL;
	i++;
	printf("Enter 'n' to exit anything to continue\n");
	fflush(stdin);
	ch = getchar();
	
	while(ch!='n'){
		curr = (dlink *)malloc(sizeof(dlink));
		if(curr==NULL){
			printf("out of memory\n");
			exit(0);
		}
		node->next = curr;
		curr->prev = node;
		node = curr;
		printf("\nenter the value of %d node: ", i);
		scanf("%d", &node->info);
		node->next = NULL;
		printf("\nEnter 'n' to exit anything to continue\n");
		fflush(stdin);
		ch = getchar();
		i++;	
	}
}

void displaydlink(dlink *node){
	dlink *ptr;
	printf("values in forward direction\n");
	while(node!=NULL){
		ptr = node;
		printf("%d\t", node->info);
		node = node->next;
	}
	printf("\nvalues in backward direction\n");
	node = ptr;
	while(node!=NULL){
		printf("%d\t", node->info);
		node = node->prev;
	}
}





