
#include<stdio.h>
#include<stdlib.h>
#define n_activities 6

void swap(int * arr, int i, int j){

	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;

}

// Sorts according to array 1
void joint_sort(int * arr1, int * arr2, int n){

	int temp;
	for(int i=n-1; i>-1; i--){
		for(int j=0; j<i; j++){
			if(arr1[j] > arr1[j+1]){
				swap(arr1, j, j+1);
				swap(arr2, j, j+1);
			}
		}
	}

}

void select_activities(int * start_times, int * finish_times, int n){

	// Sort activities by finish time
	joint_sort(finish_times, start_times, n);

	// First activity is selected
	int i = 0;
	printf("(%d, %d) ", start_times[i], finish_times[i]);

	// Iterate over all other activities
	for(int j=1; j<n; j++){

		// If activity starts after the last activity finished
		if(start_times[j] >= finish_times[i]){
			printf("(%d, %d) ", start_times[j], finish_times[j]);
			i = j;
		}

	}

	printf("\n");
}

int main(){

	int start_times[n_activities]  = {3, 1, 0, 5, 8, 9};
	int finish_times[n_activities] = {5, 2, 8, 8, 9, 12};

	printf("Activity Selection: ");
	select_activities(start_times, finish_times, n_activities);

	return 0;
}

