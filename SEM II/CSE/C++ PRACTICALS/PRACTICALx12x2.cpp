
// EXPERIMENT – 12

// Title: Graphs
// Objective: To understand the concepts of Graph Data Structure

// 2. Accept the vertices and edges for a graph and stores it as an adjacency list. Implement functions
// to print outdegree of any vertex i.

#include<iostream>
using namespace std;

void print_adjacency_matrix(int **matrix, int matrix_size){
	printf("\nAdjacency Matrix:\n  ");
	for(int i{}; i<matrix_size; i++) printf("%d ", i+1);
	cout<<endl;
	for(int y{}; y<matrix_size; y++){
		printf("%d ", y+1);
		for(int x{}; x<matrix_size; x++){
			printf("%d ", matrix[y][x]);
		}
		cout<<endl;
	}
	cout<<endl;
}

void add_connection(int **matrix, int size, int source, int destination){
	matrix[source-1][destination-1]= 1;
}

void print_outdegree(int **matrix, int size, int src){
	int count{};
	for(int dest{}; dest<size; dest++){
		if( matrix[src-1][dest] ) 
			count++;
	}
	printf("\nOutdegree for Node-%d is %d\n", src, count);
}

int main(){

	// Getting Vertices
	int matrix_size{};
	printf("Enter number of nodes:");
	cin>>matrix_size;

	int **adjacency_matrix= new int*[matrix_size];
	for(int y{}; y<matrix_size; y++){
		adjacency_matrix[y]= new int[matrix_size];
		for(int x{}; x<matrix_size; x++){
			adjacency_matrix[y][x]= 0;
		}
	} 

	int connections{};
	printf("Enter number of connections:");
	cin>>connections;

	// Getting Edges for the graph
	int source{}, destination;
	for(int i{}; i<connections; i++){
		printf("Enter source and destination:");
		cin>>source;
		cin>>destination;
		add_connection(adjacency_matrix, matrix_size, source, destination);
	}

	print_adjacency_matrix(adjacency_matrix, matrix_size);

	int src{};
	printf("Enter node to get Outdegree:");
	cin>>src;

	print_outdegree(adjacency_matrix, matrix_size, src);

	return 0;
}
