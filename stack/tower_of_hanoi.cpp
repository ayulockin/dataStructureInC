// tower of hanoi

#include<stdio.h>

void Move(int, int, int, int);

int main(){
	int n;
	printf("Enter the number of disks: \n");
	scanf("%d", &n);
	
	Move(n,1,3,2);
}

void Move(int n, int start, int stop, int temp){
	if(n>0){
		Move(n-1, start, temp, stop);
		printf("Move disk %d from %d to %d\n", n, start, stop);
		Move(n-1, temp, stop, start);
	}
}


