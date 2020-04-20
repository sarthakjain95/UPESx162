
// EXPERIMENT – 12

// Title: Graphs
// Objective: To understand the concepts of Graph Data Structure

// 3. Accept the graph as an adjacency matrix and checks if the graph is undirected. The matrix for
// undirected graph is symmetric

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

bool is_undirected_graph(int **matrix, int size){
	for(int y{}; y<size; y++){
		for(int x{}; x<size; x++){
			if( matrix[y][x] != matrix[x][y] ) 
				return false;
		}
	}
	return true;
}

int main(){

	// Getting Vertices
	int matrix_size{};
	printf("Enter number of nodes:");
	cin>>matrix_size;

	// Getting Adjacency Matrix
	printf("Enter %d values for Adjacency Matrix:\n", matrix_size*matrix_size);
	int **adjacency_matrix= new int*[matrix_size];
	for(int y{}; y<matrix_size; y++){
		printf("Enter %d values for row %d: ", matrix_size, y+1);
		adjacency_matrix[y]= new int[matrix_size];
		for(int x{}; x<matrix_size; x++){
			cin>>adjacency_matrix[y][x];
		}
	} 

	print_adjacency_matrix(adjacency_matrix, matrix_size);

	bool is_undirected= is_undirected_graph(adjacency_matrix, matrix_size);
	if(is_undirected) printf("Given Graph is a Undirected Graph");
	else printf("Given Graph is not Undirected Graph");
	cout<<endl;

	return 0;
}
