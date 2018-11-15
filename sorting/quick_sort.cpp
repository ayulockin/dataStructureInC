#include<stdio.h>

void quick_sort(int [], int, int);
int partition(int [], int, int);

int main(){
	int array[20] = {44,55,55,33,99,88,77,22,22,11,110,66};
	int n = 12;
	
	quick_sort(array, 0, n-1);
	
	printf("Your sorted array is: \n");
	for(int i=0;i<n;i++){
		printf("%d\t", array[i]);
	}
}

void quick_sort(int array[], int l, int h){
	if(l<h){
		int q = partition(array, l, h);
		quick_sort(array, l, q);
		quick_sort(array, q+1, h);	
	}
}

int partition(int array[], int l, int h){
	int pivot = array[l];
	int i=l-1, j=h+1;
	
	while(1){
		do{
			i++;
		}while(array[i]<pivot);
		do{
			j--;
		}while(array[j]>pivot);
		if(i<j){
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		else{
			return(j);
		}
	}
}





