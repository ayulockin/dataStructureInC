#include<stdio.h>

void merge_sort(int [], int, int);
void merge(int [], int, int, int);

int main(){
	int a[20] = {44,55,33,99,88,77,22,11,110,66};
	int n = 10;
	
	merge_sort(a, 0, n-1);
	
	for(int i=0; i<n; i++){
		printf("%d\t", a[i]);
	}
}

void merge_sort(int a[], int l, int r){
	int q;
	if(l<r){
		q = (l+r)/2;
		merge_sort(a, l, q);
		merge_sort(a, q+1, r);
		merge(a, l, q, r);
	}
}

void merge(int a[], int l, int q, int r){
	int b[20];
	int l1 = l;
	int r1 = q+1;
	int i = l;
	
	while((l1<=q) && (r1<=r)){
		if(a[l1]<a[r1]){
			b[i] = a[l1];
			l1++;
			i++;
		}
		else{
			b[i] = a[r1];
			r1++;
			i++;
		}
	}
	
	while(l1<=q){
		b[i] = a[l1];
		l1++;
		i++;
	}
	
	while(r1<=r){
		b[i] = a[r1];
		r1++;
		i++;
	}
	
	for(i=l; i<=r; i++){
		a[i] = b[i];
	}
}




