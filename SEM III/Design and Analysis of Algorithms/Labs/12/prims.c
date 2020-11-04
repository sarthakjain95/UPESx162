
// v2.0

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

// Specific for test case
#define n_edges 9

typedef struct {
	int v1; int v2;
	int weight;
} edge;

void display_edges(edge* edges, int size){
	for(int i=0; i<size; i++){
		printf("%d<->%d : %d\n", edges[i].v1, edges[i].v2, edges[i].weight);
	}
}

void swap_edges(edge* edges, int i, int j){
	edge temp;
	// i to temp
	temp.v1 = edges[i].v1; 
	temp.v2 = edges[i].v2; 
	temp.weight = edges[i].weight;
	// j to i
	edges[i].v1 = edges[j].v1; 
	edges[i].v2 = edges[j].v2; 
	edges[i].weight = edges[j].weight;
	// temp = j
	edges[j].v1 = temp.v1; 
	edges[j].v2 = temp.v2; 
	edges[j].weight = temp.weight;
}

void sort_edges(edge* edges, int size){
	// bubble sort
	for(int i=size-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(edges[j].weight > edges[j+1].weight){
				swap_edges(edges, j, j+1);
			}
		}
	}
}

bool node_present_in_mst(edge* edges, int size, int n){
	for(int i=0; i<size; i++){
		if(edges[i].v1 == n || edges[i].v2 == n) return true;
	}
	return false;
}

int make_min_spanning_tree_prims(edge* edges, edge* mst, int size){

	// Sort edges with weight
	sort_edges(edges, size); 

	mst[0].v1 = edges[0].v1;
	mst[0].v2 = edges[0].v2;
	mst[0].weight = edges[0].weight;

	int* all_nodes = (int*)calloc(size*2, sizeof(int));
	int all_nodes_length = 0;
	bool is_present = false;
	for(int i=0; i<size; i++){
		// v1 check
		is_present = false;
		for(int j=0; j<all_nodes_length; j++){
			if(all_nodes[j] == edges[i].v1){
				is_present = true;
				break;
			}
		}
		if(!is_present){
			all_nodes[all_nodes_length] = edges[i].v1;
			all_nodes_length++;
		}
		// v2 check
		is_present = false;
		for(int j=0; j<all_nodes_length; j++){
			if(all_nodes[j] == edges[i].v2){
				is_present = true;
				break;
			}
		}
		if(!is_present){
			all_nodes[all_nodes_length] = edges[i].v2;
			all_nodes_length++;
		}
	}

	int* ignored_edges = (int*)calloc(size, sizeof(int)); 
	ignored_edges[0] = 0;
	int ignored_edges_length = 1;

	// // logs
	// for(int i=0; i<all_nodes_length; i++){
	// 	printf("%d ", all_nodes[i]);
	// }
	// printf("\n");

	bool all_nodes_connected = false;
	int mst_length = 1;

	// while all nodes are not connected in min_spanning_tree
	while(!all_nodes_connected){ 

		// Select the min_weight_edge that is connected to the mst
		int min_weights_edge_index = -1;
		int other_node;
		for(int i=0; i<mst_length; i++){ //
			for(int j=0; j<size; j++){ // iterate over edges

				// bypass the edges already added
				is_present = false;
				for(int k=0; k<ignored_edges_length; k++){
					if(j == ignored_edges[k]){
						is_present = true;
						break;
					}
				}
				if(is_present) continue;

				// v1
				if(edges[j].v1 == mst[i].v1 || edges[j].v2 == mst[i].v1){ // consider the edge
					other_node = edges[j].v1;
					if(edges[j].v1 == mst[i].v1) other_node = edges[j].v2;
					// Check if other_node is already present in the mst
					if(!node_present_in_mst(mst, mst_length, other_node)){
						if(min_weights_edge_index == -1 || edges[min_weights_edge_index].weight > edges[j].weight){
							min_weights_edge_index = j;
						}
					}
				} 
				// v2
				if(edges[j].v1 == mst[i].v2 || edges[j].v2 == mst[i].v2){ // consider the edge
					other_node = edges[j].v1;
					if(edges[j].v1 == mst[i].v2) other_node = edges[j].v2;
					// Check if other_node is already present in the mst
					if(!node_present_in_mst(mst, mst_length, other_node)){
						if(min_weights_edge_index == -1 || edges[min_weights_edge_index].weight > edges[j].weight){
							min_weights_edge_index = j;
						}
					}
				} 
				//
				
			}
		}

		// error case
		if(min_weights_edge_index == -1){
			printf("Min weight not found!\n");
			exit(0);
		}
		// printf("Min weight edge is %d %d -> %d\n",min_weights_edge_index, edges[min_weights_edge_index].v1, edges[min_weights_edge_index].v2);

		// Add min node to the mst
		mst[mst_length].v1 = edges[min_weights_edge_index].v1;
		mst[mst_length].v2 = edges[min_weights_edge_index].v2;
		mst[mst_length].weight = edges[min_weights_edge_index].weight;
		mst_length++;

		ignored_edges[ignored_edges_length] = min_weights_edge_index;
		ignored_edges_length++;

		// logs
		// printf("Added %d  to %d {%d}\n", mst[mst_length-1].v1, mst[mst_length-1].v2, mst[mst_length-1].weight);

		for(int i=0; i<all_nodes_length; i++){
			all_nodes_connected = false;
			for(int j=0; j<mst_length; j++){
				if(mst[j].v1 == all_nodes[i] || mst[j].v2 == all_nodes[i]){
					all_nodes_connected = true;
					break;
				}
			}
			if(all_nodes_connected == false) break;
		}

	}

	return mst_length;
}

int main(){

	edge* edges = (edge*)calloc(n_edges, sizeof(edge));

	edges[0].v1 = 0; edges[0].v2 = 1; edges[0].weight = 28;
	edges[1].v1 = 0; edges[1].v2 = 5; edges[1].weight = 10;
	edges[2].v1 = 5; edges[2].v2 = 4; edges[2].weight = 25;
	edges[3].v1 = 6; edges[3].v2 = 1; edges[3].weight = 14;
	edges[4].v1 = 6; edges[4].v2 = 4; edges[4].weight = 24;
	edges[5].v1 = 1; edges[5].v2 = 2; edges[5].weight = 16;
	edges[6].v1 = 3; edges[6].v2 = 4; edges[6].weight = 22;
	edges[7].v1 = 3; edges[7].v2 = 6; edges[7].weight = 18;
	edges[8].v1 = 3; edges[8].v2 = 2; edges[8].weight = 12;

	// Display edges
	printf("GRAPH:\n");
	display_edges(edges, n_edges);

	// // Make min spanning tree with prim's algorithm
	edge* min_spanning_tree_edges = (edge*)calloc(n_edges, sizeof(edge));
	int min_spanning_tree_size = make_min_spanning_tree_prims(edges, min_spanning_tree_edges, n_edges);
	printf("\nMST:\n");
	display_edges(min_spanning_tree_edges, min_spanning_tree_size);

	return 0;
}
