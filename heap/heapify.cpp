// heap is an array of elements which can be seen as complete binary tree
// The value of internal node is greater than or equal to its children
// The tree is completely filled in all levels maybe except lowest level
// attributes: length of array, 
//             heapsize ie, no of elements in the heap within array

// root of tree is array[0], contains the largest element in heap
// (1) heapify 

#include<stdio.h>

void heapify(int [], int, int);
void buildheap(int [], int);
void heap_sort(int [], int);

// helper functions
int parent(int);
int leftChild(int);
int rightChild(int);

int main(){
	int data[10] = {9,6,8,7,21,14,15,19,13,12};
	printf("data: 9,6,8,7,21,14,15,19,13,12\n");
	int n = 10;
	
	heap_sort(data, n);
	
	for(int i=0; i<n; i++){
		printf("%d\t", data[i]);
	}
}

int parent(int i){return(i/2);}
int leftChild(int i){return(2*i+1);}
int rightChild(int i){return(2*i+2);}

void heapify(int array[], int i, int n){
	int largest = i;
	int l = leftChild(i);
	int r = rightChild(i);
	
	if(l<=n-1 && array[l]>array[largest]){
		largest = l;
	}
	if(r<=n-1 && array[r]>array[largest]){
		largest = r;
	}
	if(largest!=i){
		int temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;
		heapify(array, largest, n);
	}
}


void buildheap(int array[], int n){
	for(int i=n/2-1; i>=0; i--){
		heapify(array, i, n);
	}	
}

void heap_sort(int array[], int n){
	buildheap(array, n);
	int start = 0;
	while(n!=start){
		int temp = array[start];
		array[start] = array[n-1];
		array[n-1] = temp;
		heapify(array, 0, n-1);
		n--;		
	}
}




