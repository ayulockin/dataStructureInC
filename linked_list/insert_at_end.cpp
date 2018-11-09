#include<stdio.h>
#include<stdlib.h>

struct link{
	int info;
	struct link *next;
};
struct link *start;

void createList(struct link *);
void display(struct link *);
void insert_at_beginning(struct link *);
void insert_at_end(struct link *);

int main(){
	struct link *node;
	node = (struct link *)malloc(sizeof(struct link));
	if(node == NULL){
		printf("Out of memory\n");
		exit(0);
	}
	createList(node);
	int ch=1;
	while(ch!=4){
		printf("\n1 -> Display\n");
		printf("2 -> Insert At Beginning\n");
		printf("3 -> Insert At End\n");
		printf("4 -> Terminate\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		printf("\n");
		
		switch(ch){
			case 1:
				display(node);
				break;
			case 2:
				insert_at_beginning(node);
				node = start;
				start = NULL;
				break;
			case 3:
				insert_at_end(node);
				break;
			case 4:
				break;
			default:
				printf("wrong choice!!!\n Try again^_^\n");
		}
	}
}

void createList(struct link *node){
	int i=1;
	printf("\nEnter value of %d node: ", i);
	scanf("%d", &node->info);
	node->next = NULL;
	i++;
	
	char ch;
	printf("\nChoose 'n' to quit any other to continue: ");
	fflush(stdin);
	ch = getchar();
	while(ch!='n'){
		node->next = (struct link *)malloc(sizeof(struct link));
		if(node == NULL){
			printf("Out of memory\n");
			exit(0);
		}
		node = node->next;
		printf("\nEnter value of %d node: ", i);
		scanf("%d", &node->info);
		node->next = NULL;
		i++;
		printf("\nChoose 'n' to quit anyother to continue: ");
		fflush(stdin);
		ch = getchar();
	}
}

void display(struct link *node){
	printf("The values of node in the list are as follows: \n");
	while(node != NULL){
		printf("%d\t", node->info);
		node = node->next;
	}
	printf("\n");
}

void insert_at_beginning(struct link *node){
	struct link *curr;
	curr = (struct link *)malloc(sizeof(struct link));
	if(curr==NULL){
		printf("Out of memory\n");
		exit(0);
	}
	curr->next = node;
	printf("\nEnter the value of the node: ");
	scanf("%d", &curr->info);
	start = curr;
}

void insert_at_end(struct link *node){
	struct link *curr;
	while(node->next != NULL){
		node = node->next;
	}
	curr = (struct link *)malloc(sizeof(struct link));
	curr->next = NULL;
	node->next = curr;
	printf("\nEnter the value of to be inserted: ");
	scanf("%d", &curr->info);
}










