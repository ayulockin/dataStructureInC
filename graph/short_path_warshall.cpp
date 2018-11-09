// Warshall's algorithm to find the shortest path matrix

#include<stdio.h>
#include<stdlib.h>

#define SIZE 20
int adj[SIZE][SIZE];
int Wt[SIZE][SIZE];

void shortPath();
void display(char);

int numv;
int ifn = 999; //infinity 
int main(){
	
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
	display('a');

	// apply warshall algorithm
	shortPath();
}

void shortPath(){
	printf("Adjacency matrix after replacing zeros by infinity: \n");
	for(int i=0;i<numv;i++){
		for(int j=0;j<numv;j++){
			if(adj[i][j] == 0){
				Wt[i][j] = ifn;
			}
			else{
				Wt[i][j] = adj[i][j];
			}
		}
	}
	
	display('p');
	
	for(int k=0; k<numv; k++){
		for(int i=0; i<numv; i++){
			for(int j=0; j<numv; j++){
				if(Wt[i][j] <= Wt[i][k]+Wt[k][j]){
					Wt[i][j] = Wt[i][j];
				}
				else{
					Wt[i][j] = Wt[i][k] + Wt[k][j];
				}
			}
		}
		printf("\nStep: %d", k);
		printf("\n");
		display('p');
	}
}


void display(char matrix_type){
	if(matrix_type == 'a'){
		for(int i=0;i<numv;i++){
			for(int j=0;j<numv;j++){
				printf("%d\t", adj[i][j]);
			}
			printf("\n");
		}	
	}
	else if(matrix_type = 'p'){
		for(int i=0;i<numv;i++){
			for(int j=0;j<numv;j++){
				printf("%d\t", Wt[i][j]);
			}
			printf("\n");
		}
	}
}
