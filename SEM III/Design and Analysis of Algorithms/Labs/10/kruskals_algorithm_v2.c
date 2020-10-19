
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

bool is_path_node_to_node(edge* mst, int* path, int mst_size, int path_length, int destination_node){

	if(destination_node == -1) destination_node = path[0];
	int prev_node = path[path_length-2];

	int this_node = path[path_length-1];
	int other_node = -1;

	for(int i=0; i<mst_size; i++){
		// Process further if this edge includes last path node
		if(mst[i].v1 == this_node) other_node = mst[i].v2;
		else if(mst[i].v2 == this_node) other_node = mst[i].v1;
		else continue;
		// 
		if(other_node == prev_node) continue; // Don't make a U-turn
		if(other_node == destination_node) return true; // Reached destination;
		// Check if new node exceed the size limit for path
		if( path_length+1 >= mst_size+1 ) return false; // we are (probably) in a loop; 
		else{ // Add this node to path
			path[path_length] = other_node;
			path_length++;
			if(is_path_node_to_node(mst, path, mst_size, path_length, destination_node)){
				return true;
			} 
				// return true;
			else path_length--; // Removed the new path node
		}
	}

	return false;
}

bool contains_loop(edge* mst, int size){

	int* path = (int*)calloc(size+1, sizeof(int));
	
	for(int i=0; i<size; i++){
		path[0] = mst[i].v1;
		path[1] = mst[i].v2;
		if(is_path_node_to_node(mst, path, size, 2, -1)) 
			return true;
	}

	return false;
}

void push_back(edge* edges, int start, int end){
	edge temp;
	temp.v1 = edges[start].v1; 
	temp.v2 = edges[start].v2; 
	temp.weight = edges[start].weight;

	for(int i=start; i<end; i++) 
		swap_edges(edges, i, i+1);
	
	edges[end-1].v1 = temp.v1;
	edges[end-1].v2 = temp.v2;
	edges[end-1].weight = temp.weight;
}

int make_min_spanning_tree(edge* edges, edge* mst, int size){

	// Sort edges with weight
	sort_edges(edges, size); 

	// Stores a list of all vertices/nodes
	int* all_nodes = (int*)calloc(size*2, sizeof(int));
	int  all_nodes_length = 0;
	for(int i=0; i<size; i++){
		// v1 check
		bool is_present = false;
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

	bool all_nodes_connected = false;
	int mst_length = 0;
	int edges_queue_start = 0; // Treat list of edges as a queue

	// while all nodes are not connected in min_spanning_tree
	while(!all_nodes_connected){ 

		// Add the lowest weight available to min_spanning_tree
		mst[mst_length].v1 = edges[edges_queue_start].v1;
		mst[mst_length].v2 = edges[edges_queue_start].v2;
		mst[mst_length].weight = edges[edges_queue_start].weight;
		mst_length++;

		// 
		// printf("MST WEIGHTs: ");
		// for(int i=0; i<mst_length; i++){
		// 	printf("%d ", mst[i].weight);
		// }
		// printf("\n");

		// Check if new edges forms a loop
		if(contains_loop(mst, mst_length)){
			mst_length--; // Remove new element from mst
			push_back(edges, edges_queue_start, size); // Push selected edge to the back
		}else{ // New edges does not corrupt mst
			edges_queue_start++; // Remove the first element of edges
		}

		{ // Check if all nodes of graph are connected in MST
			all_nodes_connected = true;
			int dest_node;
			int* path = (int*)calloc(mst_length+1, sizeof(int));
			for(int i=0; i<all_nodes_length; i++){ 
				dest_node = all_nodes[i];
				for(int j=0; j<mst_length; j++){
					if(mst[j].v1 == dest_node || mst[j].v2 == dest_node) continue;
					else{
						// Check path v1, v2 ....
						path[0] = mst[j].v1;
						path[1] = mst[j].v2;
						if(!is_path_node_to_node(mst, path, mst_length, 2, dest_node)){
							all_nodes_connected = false;
						}
						// Check path v2, v1, ....
						if(!all_nodes_connected){
							path[0] = mst[j].v2;
							path[1] = mst[j].v1;
							if(!is_path_node_to_node(mst, path, mst_length, 2, dest_node)){
								all_nodes_connected = false;
								break;
							}else{
								all_nodes_connected = true;
							}
						}
					}
				}
				// 
				if(!all_nodes_connected) break;
			}
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

	// // Make min spanning tree
	edge* min_spanning_tree_edges = (edge*)calloc(n_edges, sizeof(edge));
	int min_spanning_tree_size = make_min_spanning_tree(edges, min_spanning_tree_edges, n_edges);
	printf("\nMST:\n");
	display_edges(min_spanning_tree_edges, min_spanning_tree_size);

	return 0;
}
