#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *next;
};
typedef struct node *stack;

int isEmpty(stack);
stack push(stack);
stack pop(stack);
void display(stack);

int main(){
	stack top = NULL;

	int ch = 1;
		
	while(ch!=4){
		printf("\n 1->push");
		printf("\n 2->pop");
		printf("\n 3->display");
		printf("\n 4->quit");
		
		printf("\nEnter your choice: \n");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				top = push(top);
				break;
				
			case 2:
				top = pop(top);			
				break;
				
			case 3:
				display(top);
				break;
				
			case 4:
				break;
			default:
				printf("wrong choice!!! try again ^_^");
		}	
	}
}

int isEmpty(stack top){
	if(top==NULL){return 1;}
	else{return 0;}
}

stack push(stack top){
	stack temp;
	temp = (stack)malloc(sizeof(struct node));
	printf("Enter the value to be pushed\n");
	int x;
	scanf("%d", &x);
	temp->info = x;
	temp->next = top;
	top = temp;
	return (top);
}

stack pop(stack top){
	stack curr;
	int val;
	curr = top;
	val = curr->info;
	printf("The value poped is: %d\n", val);
	top = top->next;
	free(curr);
	return(top);
}

void display(stack top){
	stack ptr;
	ptr = top;
	while(ptr!=NULL){
		printf("%d\t", ptr->info);
		ptr = ptr->next;
	}
	printf("\n");
}









