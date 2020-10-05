
// Suppose you have a bag and you have a number of objects, each object has
// some weight and profit associated with it, you have to find the max gain 
// from the combination of objects in the bag, maintaining the bag's total
// capacity.

#include<stdio.h>
#include<stdlib.h>
#define total_objects 7
#define bag_capacity 15

typedef struct{
	float profit;
	float weight;
} object;

void swap_floats(float * arr, int i, int j){
	float temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void swap_ints(int * arr, int i, int j){
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void swap_objects(object * arr, int i, int j){
	object temp;
	temp.profit = arr[i].profit; temp.weight = arr[i].weight;
	arr[i].profit = arr[j].profit; arr[i].weight = arr[j].weight;
	arr[j].profit = temp.profit; arr[j].weight = temp.weight;	
}

// Sort by profit (float * pw)
void sort_arrays(float * pw, object * objects, int * n_objects, int n){

	for(int i=n-1; i>-1; i--){
		for(int j=0; j<i; j++){
			if(pw[j] < pw[j+1]){
				swap_floats(pw, j, j+1);
				swap_objects(objects, j, j+1);
				swap_ints(n_objects, j, j+1);
			}
		}
	}

}

void knapsack_fill(object * objects, int * n_objects, int n, int max_capacity){

	float * profit_by_weight = (float*)calloc(n, sizeof(float));
	for(int i=0; i<n; i++)
		profit_by_weight[i] = objects[i].profit / objects[i].weight;
	//
	sort_arrays(profit_by_weight, objects, n_objects, n);

	// Init the bag
	object * bag = (object*)calloc(n, sizeof(object));
	int * n_items = (int*)calloc(n, sizeof(int));
	int size = 0;
	float weight = 0;
	float profit = 0;

	for(int i=0; i<n; i++){

		// If adding the object does not exceed capacity
		// then add it
		if(weight + objects[i].weight <= max_capacity){
			bag[size].weight = objects[i].weight;
			bag[size].profit = objects[i].profit;
			while(weight + objects[i].weight <= max_capacity && n_objects[i]){
				weight += objects[i].weight;
				profit += objects[i].profit;
				n_items[size] += 1;
				n_objects[i]--;
			}
			size++;
		}

	}

	// Display the bag
	printf("Total Weight of bag: %f\n", weight);
	printf("Total profit from bag: %f\n", profit);
	printf("Items: \n");
	for(int i=0; i<size; i++){
		printf("weight:%.1f, profit:%.1f, quantity:%d \n", bag[i].weight, bag[i].profit, n_items[i]);
	}

}

int main(){

	object objects[total_objects];

	int n_objects[total_objects] = {1, 1, 2, 2, 4, 1, 4};
	float weights[total_objects] = {2.0, 3.0, 5.0, 2.0, 3.0, 6.0, 1.0};
	float profits[total_objects] = {4.0, 5.0, 10.0, 30.0, 6.0, 2.0, 1.0};

	// Init weights and profits in the objects array
	for(int i=0; i<total_objects; i++){
		objects[i].weight = weights[i];
		objects[i].profit = profits[i];
	}

	// Maximize profit
	knapsack_fill(objects, n_objects, total_objects, bag_capacity);

	return 0;
}
