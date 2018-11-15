// bubble sort

#include<stdio.h>

#define SIZE 20

void bubble_sort(int[], int);

int main(){
	int array[SIZE], n;
//	int array[SIZE] = {44,55,33,88,77,22,11,66};
//	int n=8;
	printf("Enter the length of your list\n");
	scanf("%d", &n);
	printf("enter your values\n");
	for(int i=0;i<n;i++){
		scanf("%d", &array[i]);
	}
	bubble_sort(array, n);
	printf("\n\nYour sorted array is: \n");
	for(int i=0;i<n;i++){
		printf("%d\t", array[i]);
	}
}

void bubble_sort(int array[], int n){
	int temp;
	for(int pass=0; pass<n-1;pass++){
		for(int i=0; i<n-pass-1; i++){
			if(array[i]>array[i+1]){
				temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
			}
		}
		printf("\nYour sorted array after pass %d: ", pass);
		for(int i=0;i<n;i++){
			printf("%d\t", array[i]);
		}	
	}
}

