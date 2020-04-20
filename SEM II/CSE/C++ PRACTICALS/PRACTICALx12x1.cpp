
// EXPERIMENT – 12

// Title: Graphs
// Objective: To understand the concepts of Graph Data Structure

// 1. Accept the vertices and edges for a graph and stores it as an adjacency matrix. Implement
// functions to print indegree, outdegree and to display the adjacency matrix.

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

void print_indegree(int **matrix, int size){
	printf("\nPrinting Indegree of all nodes:\n");
	for(int src{}; src<size; src++){
		int count{};
		for(int dest{}; dest<size; dest++){
			if( matrix[dest][src] ) count++;
		}
		printf("Node %d: Indegree: %d\n", src+1, count);
	}
}

void print_outdegree(int **matrix, int size){
	printf("\nPrinting Outdegree of all nodes:\n");
	for(int dest{}; dest<size; dest++){
		int count{};
		for(int src{}; src<size; src++){
			if( matrix[dest][src] ) count++;
		}
		printf("Node %d: Outdegree: %d\n", dest+1, count);
	}	
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

	print_indegree(adjacency_matrix, matrix_size);
	print_outdegree(adjacency_matrix, matrix_size);

	print_adjacency_matrix(adjacency_matrix, matrix_size);

	return 0;
}
