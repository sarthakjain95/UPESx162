
/*
VERSION: 1.0

:NOTE:
(Even though it works,) This version is probably less efficient, buggy and harder to 
understand than v2.0, because I made some bad design decisions. 
>>> Try to avoid this and skip to v2.0

*Oh and by the way, Even though I'm using adjacency matrices, when I declare a path
at i,j (adjacency_matrix[i][j] = x), I mean i,j and j,i (adjacency_matrix[i][j] = x and
adjacency_matrix[j][i] = x)
*/ 

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int** matrix;
typedef int*  array;

#define n_nodes 7


matrix make_matrix(int size){
	matrix _matrix = (matrix)calloc(size, sizeof(int*));
	for(int i=0; i<size; i++)
		_matrix[i] = (array)calloc(size, sizeof(int));
	return _matrix;
}

void display_matrix(matrix m, int size){

	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(m[i][j] == 0) printf("__ ");
			else printf("%02d ", m[i][j]);
		}
		printf("\n");
	}
}

bool path_from_node_to_node(matrix m, array path, int size, int path_size, int destination_node){

	// printf("Path from node to node call\n");
	int last_node = path[path_size-1];
	int prev_path_node = path[path_size-2];
	if(destination_node == -1) destination_node = path[0];
	// printf("%d %d %d\n", prev_path_node, last_node, destination_node);
	for(int i=0; i<size; i++){
		if( i == prev_path_node ) continue;
		// printf("%d\n", i);
		if(m[i][last_node]!=0 || m[last_node][i]!=0){
			// There is a path between i and j	
			if(i == destination_node) return true;
			else{
				// add this new node to path
				if(path_size+1 > size) return true; // we are in another internal loop
				path[path_size] = i;
				path_size++;
				if(path_from_node_to_node(m, path, size, path_size, destination_node)) return true;
				else{
					path_size--;
					path[path_size] = 0;
				}
			}
		}
	}

	return false;
}

bool check_for_loops(matrix m, int size){

	// i is the starting node
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(m[i][j] != 0){
				array visited_nodes = (array)calloc(size+1, sizeof(int));
				visited_nodes[0] = i;
				visited_nodes[1] = j;
				// Check if you can get to first node with this path
				if(path_from_node_to_node(m, visited_nodes, size, 2, -1)) return true;
			}
		}
	}

	// no loops present
	return false;
}

void kruskals_min_spanning_tree(matrix adjacency_matrix, matrix spanning_tree, int size){

	bool all_nodes_connected = false;

	// copy adjacency_matrix
	matrix adjacency_matrix_copy = make_matrix(size);
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			adjacency_matrix_copy[i][j] = adjacency_matrix[i][j];
		}
	}

	unsigned int min_y = -1;
	unsigned int min_x = -1;
	unsigned int min_val = -1; // -1 on unsigned int, so the result will be the max
	// value int can hold
	
	while(!all_nodes_connected){

		// Select new minimun value
		min_val = -1;

		// find minimum weight
		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++){
				if(adjacency_matrix[i][j]!=0 && adjacency_matrix[i][j]!=-1){
					if(adjacency_matrix[i][j] < min_val){
						min_val = adjacency_matrix[i][j];
						min_y = i;
						min_x = j;
					}
				}
			}
		}

		// If all nodes are rejected, copy the rejected elements
		// to the original adjacency matrix
		if(min_val == -1){

			for(int i=0; i<size; i++){
				for(int j=0; j<size; j++){
					if(adjacency_matrix_copy[i][j] == 0) continue;
					if(spanning_tree[i][j] != 0) continue;
					// Rejected element
					adjacency_matrix[i][j] = adjacency_matrix_copy[i][j];
				}
			}

			// display_matrix(spanning_tree, size);

			// break;
			continue;
		}

		// debug logs
		// Print the weights as you select them
		// printf("%d\n", min_val);
		// display_matrix(spanning_tree, size);

		spanning_tree[min_y][min_x] = min_val;

		// Check if adding that weight will form a loop
		if(check_for_loops(spanning_tree, size)){
			// if path forms a loop, the reject path
			// printf("Loop Exists!\n");
			spanning_tree[min_y][min_x] = 0;
		
		}else{ // Else update the number of nodes connected

			printf("EDGE SELECTED:%d\n", min_val);

			// Check if you can go from any node to any other node
			all_nodes_connected = true;
			for(int i=0; i<size; i++){ // from 
				for(int j=0; j<size; j++){ // to
					if(i==j) continue;
					if(spanning_tree[i][j] != 0 || spanning_tree[j][i] != 0 ) continue;
					// For every path that start with 'from' node check path to 'to'
					array path = (array)calloc(size+1, sizeof(int));
					path[0] = i;
					bool path_exists = false;
					for(int k=0; k<size; k++){
						if(spanning_tree[i][k] == 0 && spanning_tree[k][i] == 0) continue;
						path[1] = k;
						if(path_from_node_to_node(spanning_tree, path, size, 2, j)){
							path_exists = true;
							break;
						}
					}
					if(path_exists == false){
						all_nodes_connected = false;
						// printf("Failed for %d %d\n", i, j);
						// printf("Every node is not connected!\n");
						break;
					} 
				}
				if(all_nodes_connected == false) break;
			}

		}

		// Remove selected node.
		adjacency_matrix[min_y][min_x] = -1;
	}

}

int main(){

	matrix adjacency_matrix = make_matrix(n_nodes);

	// Adding nodes and connections
	adjacency_matrix[0][1] = 28;
	adjacency_matrix[0][5] = 10;
	adjacency_matrix[5][4] = 25;
	adjacency_matrix[6][1] = 14;
	adjacency_matrix[6][4] = 24;
	adjacency_matrix[1][2] = 16;
	adjacency_matrix[3][4] = 22;
	adjacency_matrix[3][6] = 18;
	adjacency_matrix[3][2] = 12;

	// Display adjacency matrix
	display_matrix(adjacency_matrix, n_nodes);
	printf("\n");

	// Make min spanning tree
	matrix min_spanning_tree = make_matrix(n_nodes);
	kruskals_min_spanning_tree(adjacency_matrix, min_spanning_tree, n_nodes);
	printf("\n");
	display_matrix(min_spanning_tree, n_nodes);

	printf("\ndone.\n");

	return 0;
}
