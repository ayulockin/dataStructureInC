// merge sort

#include<stdio.h>

#define SIZE 20

void merge(int [], int, int, int);
void merge_sort(int [], int, int);

int main(){
	int array[SIZE] = {44,55,33,99,88,77,22,11,110,66};
	int n=10;
	
	printf("! --------- Leaving main loop ----------!\n");
	merge_sort(array, 0, n-1);
	printf("\n\nYour sorted array is: \n");
	for(int i=0;i<n;i++){
		printf("%d\t", array[i]);
	}
}

void merge_sort(int array[], int l, int r){
	int q;
	if(l<r){
		q = (l+r)/2; // mid point which acts as r for first haf and p for 2nd half
		merge_sort(array, l, q); // for first half, here r is updated
		
		printf("left subarray | first merge sort done\n");
		for(int i=l;i<=q;i++){
			printf("%d\t", array[i]);
		}
		printf("\n");
	
		merge_sort(array, q+1, r); // for 2nd half, here p is updated
		printf("right subarray | second merge sort done\n");
		for(int i=l;i<=q;i++){
			printf("%d\t", array[i]);
		}
		printf("\n");
	
		merge(array, l, q, r);
		printf("**************************************************************************\n\n");
	}
}

void merge(int array[], int l, int q, int r){
	printf("merging........................................\n");
	int l1 = l;
	int r1 = q+1;
	int i = l;
	int subarray[SIZE/2];
	while((l1<=q) && (r1<=r)){
		printf("inside first while \n");
		if(array[l1]<array[r1]){
			subarray[i] = array[l1];
			l1++;
			i++;
		}
		
		else{
			subarray[i] = array[r1];
			r1++;
			i++;
		}
		
		printf("l1: %d | i: %d", l1, i);
		printf("\n");
	}
	
	while(l1<=q){
		printf("inside 2nd while\n");
		subarray[i] = array[l1];
		l1++;
		i++;
		printf("l1: %d | i: %d", l1, i);
		printf("\n");
	}
	
	while(r1<=r){
		printf("inside 3rd while\n");
		subarray[i] = array[r1];
		r1++;
		i++;
		printf("r1: %d | i: %d", r1, i);
		printf("\n");
	}
	
	printf("going for loop\n");
	for(i=l;i<=r;i++){
		array[i] = subarray[i];
	}
	
	
}
