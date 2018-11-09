// Warshall's algorithm
// This algorithm finds out the path matirx P of a directed graph G
// Finds P more efficiently than adjacency matrix approach

#include<stdio.h>
#include<stdlib.h>

#define SIZE 20
int adj[SIZE][SIZE];
int path[SIZE][SIZE];

void warshall(int);

int main(){
	int numv;
	
	printf("Enter the number of vertices: ");
	scanf("%d", &numv);
	// Enter the values of the adjacency matrix
	printf("\nEnter the values of adjacency matrix: \n");
	for(int i=0;i<numv;i++){
		for(int j=0;j<numv;j++){
			scanf("%d", &adj[i][j]);
		}
	}
	// display adjacency matrix
	printf("\nYour adjacency matrix is: \n");
	for(int i=0;i<numv;i++){
		for(int j=0;j<numv;j++){
			printf("%d\t", adj[i][j]);
		}
		printf("\n");
	}
	// apply warshall algorithm
	warshall(numv);
	
	// display the path matrix
	printf("\nYour path matrix is: \n");
	for(int i=0;i<numv;i++){
		for(int j=0;j<numv;j++){
			printf("%d\t", path[i][j]);
		}
		printf("\n");
	}
}

void warshall(int numv){
	// initialize P ie, P0
	for(int i=0; i<numv; i++){
		for(int j=0; j<numv; j++){
			if(adj[i][j] == 0){
				path[i][j] = 0;
			}
			else{
				path[i][j] = 1;
			}
		}
	}
	
	// main algo
	for(int k=0; k<numv; k++){
		for(int i=0; i<numv; i++){
			for(int j=0; j<numv; j++){
				path[i][j] = path[i][j] || (path[i][k] && path[k][j]);
			}
		}
	}
}



