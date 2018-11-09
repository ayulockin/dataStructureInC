// array implementation of linked list

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define TRUE 1
#define SIZE 100

// define NODE
struct nodetype{
	int info, next;
};
struct nodetype node[SIZE];

// define FUNCTIONS
int getNode();
void createList();
void freeNode(int);
void display();
void Insert(int, int);
void Delete(int);

int p, avail = 0;

int main(){
	int ch=1, i, n, x;
	
	// linking nodes of available nodes
	printf("\nLinking nodes of available nodes");
	for(i=0;i<SIZE-1;i++){
		node[i].next = i+1;
	}
	node[SIZE-1].next = -1;
	
	printf("\nCreate a List");
	createList();
	
	while(ch!=4){
		printf("\n1 -> Display");
		printf("\n2 -> Insert");
		printf("\n3 -> Delete");
		printf("\n4 -> Quit");
		printf("\nEnter your choice");
		scanf("%d", &ch);
		
		switch(ch){
			case 1:
				display();
				break;
			case 2:
				printf("\nNode insertion: after which node? : ");
				scanf("%d", &n);
				p = n;
				printf("\nInsert the data : ");
				scanf("%d", &x);
				Insert(p, x);
				break;
			case 3:
				printf("\nEnter the node after which the node will be deteted: ");
				scanf("%d", &n);
				p = n;
				Delete(p);
				break;
			case 4:
				break;
			default:
				printf("\nwrong choice!!!\n Try again ^_^");
		}
	}
}

// removes the node from the available list
// returns the pointer of the node 
int getNode(){
	if(avail == -1){
		printf("\nOVERFLOW");
		exit(0);
	}
	p = avail;
	avail = node[avail].next;
	return p;
}

// takes the pointer of the node
// returns that node
void freeNode(int q){
	node[q].next = avail;
	avail = q;
	return;
}

// create list of nodes from the available list
void createList(){
	int x;
	char c;
	p = getNode();
	//printf("\np: %d", p);
	printf("\nEnter an item to be inserted: ");
	scanf("%d", &x);
	node[p].info = x;
	node[p].next = -1;
	while(TRUE){
		printf("\nEnter the choice (y/n): ");
		fflush(stdin);
		c = getchar();
		if(c=='y' || c=='Y'){
			printf("\nEnter an item to be inserted: ");
			scanf("%d", &x);
			//printf("\ninside create list loop, value of p: %d", p);
			Insert(p, x);
			node[p].next = -1;		
		}
		else{
			return;
		}
	}
}

// display the node
void display(){
	p = 0;
	while(node[p].next != -1){
		printf("\n%d\t%d\t%d", p, node[p].info, node[p].next);
		p = node[p].next;
	}
}

// insert a node after the given node
void Insert(int r, int x){
	int q;
	if(r==-1){
		printf("\nVoid Insertion");
		return;
	}
	q = getNode();
	//printf("\nq: %d", q);
	node[q].info = x;
	node[q].next = node[r].next;
	node[r].next = q;
}

// delete a node
void Delete(int r){
	int q;
	if(r==-1 || node[r].next == -1){
		printf("\nVoid Deletion");
		return;
	}
	q = node[r].next;
	//printf("q: %d", q);
	node[r].next = node[q].next;
	freeNode(q);
	return;
}
