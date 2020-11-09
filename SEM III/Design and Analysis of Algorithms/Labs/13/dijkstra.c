
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MATRIX_SIZE 6 // Specific for test case
typedef uint** matrix;

uint* dijkstra_min_path(matrix distances, uint size, uint start_idx){

	uint* visited_nodes = (uint*)calloc(size, sizeof(uint));
	for(int i=0; i<size; i++) visited_nodes[i] = false;
	visited_nodes[start_idx] = true;

	uint* node_to_node_distances = (uint*)calloc(size, sizeof(uint));
	// Set all distances to infinity
	for(int i=0; i<size; i++) node_to_node_distances[i] = -1;
	// Set the initially connected nodes
	node_to_node_distances[start_idx] = 0;
	// Set directly connected nodes
	for(int i=0; i<size; i++){
		if(distances[start_idx][i] != -1){
			node_to_node_distances[i] = distances[start_idx][i];
		}
	}

	bool all_nodes_visited = false;

	while(!all_nodes_visited){

		// Select the node that is not on path and has min distance 
		uint min_distance_idx = -1;
		for(int i=0; i<size; i++){
			if(!visited_nodes[i]){
				if(min_distance_idx == -1 || node_to_node_distances[i] < node_to_node_distances[min_distance_idx]){
					min_distance_idx = i;
				}
			}
		}

		// Error scenario
		if(min_distance_idx == -1){
			printf("Min dist idx is -1!!\n");
			exit(-1);
		}

		// Add that node to path
		visited_nodes[min_distance_idx] = true;

		// Add updates the distances to all other nodes
		for(int i=0; i<size; i++){
			if(i != min_distance_idx && distances[min_distance_idx][i] != -1){
				if((node_to_node_distances[min_distance_idx] + distances[min_distance_idx][i]) < node_to_node_distances[i]){
					node_to_node_distances[i] = distances[min_distance_idx][i] + node_to_node_distances[min_distance_idx];
				}
			}
		}

		// logs
		// printf("Min distance idx: %u\n", min_distance_idx);

		// Check if all nodes are visited
		all_nodes_visited = true;
		uint visited_nodes_count = 0;
		for(int i=0; i<size; i++){
			if(visited_nodes[i] == false){
				visited_nodes_count++;
			}
		}

		if(visited_nodes_count > 1){
			all_nodes_visited = false;
		}

	}

	return node_to_node_distances;
}

int main(){

	// Init matrix
	matrix distances = (matrix)calloc(MATRIX_SIZE, sizeof(uint*));
	for(int i=0; i<MATRIX_SIZE; i++) distances[i] = (uint*)calloc(MATRIX_SIZE, sizeof(uint));
	for(int i=0; i<MATRIX_SIZE; i++){
		for(int j=0; j<MATRIX_SIZE; j++){
			distances[i][j] = -1; // infinity
		}
		distances[i][i] = 0;
	}

	// Adding edges
	distances[0][1] = 2;
	distances[0][2] = 4;
	distances[1][2] = 1;
	distances[1][3] = 7;
	distances[2][4] = 3;
	distances[4][3] = 2;
	distances[3][5] = 1;
	distances[4][5] = 5;

	// 0 to 5
	uint start_idx = 0;
	uint end_idx = 5;
	// Get min distances from start_idx to all other nodes
	uint* min_distances = dijkstra_min_path(distances, MATRIX_SIZE, start_idx);
	printf("Shortest path from %u to %u is %u unit length.\n", start_idx, end_idx, min_distances[end_idx]);

	// logs
	for(int i=0; i<MATRIX_SIZE; i++){
		printf("%u ", min_distances[i]);
	}
	printf("\n");
	
	return 0;
}
