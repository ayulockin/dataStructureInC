#include<stdio.h>

#define MAX 100
int stack[MAX];
int top = -1;

int isEmpty();
int isFull();
void push(int);
int pop();
void display();

int main(){
	int x;
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
				printf("Enter the value to be pushed\n");
				scanf("%d", &x);
				push(x);
				break;
				
			case 2:
				x = pop();
				printf("The poped value is: %d\n", x);			
				break;
				
			case 3:
				display();
				break;
				
			case 4:
				break;
			default:
				printf("wrong choice!!! try again ^_^");
		}	
	}
}

int isEmpty(){
	if(top==-1){return 1;}
	else{return 0;}
}

int isFull(){
	if(top==MAX-1){return 1;}
	else{return 0;}
}

void push(int x){
	if(isFull()){
		printf("Full\n");
		return;
	}
	top++;
	stack[top] = x;
}

int pop(){
	if(isEmpty()){
		printf("Empty\n");
		return 0;
	}
	int temp = stack[top];
	top--;
	return temp;
}

void display(){
	if(isEmpty()){
		printf("Empty\n");
		return;
	}
	for(int k=top; k>=0; k--){
		printf("%d\t", stack[k]);
	}
	printf("\n");
}

















