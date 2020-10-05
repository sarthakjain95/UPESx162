
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

void interval_partitioning(int * start_times, int * finish_times, int n){

	// Sort by starting time
	joint_sort(start_times, finish_times, n);

	int n_classrooms = 1;
	int * classrooms = (int*)calloc(n, sizeof(int));
	
	// Add first class
	classrooms[0] = finish_times[0];
	printf("\n(classroom: %d, starttime:%d)\n", 0, start_times[0]);

	for(int j = 1; j<n ; j++){
		// Check if this class can be scheduled after any other class
		int is_compatible = 0;
		for(int i=0; i<n_classrooms; i++){
			if(classrooms[i] <= start_times[j]){
				printf("(classroom: %d, starttime:%d)\n", i, start_times[j]);
				classrooms[i] = finish_times[j];
				is_compatible = 1;
				break;
			}
		}
		// If this class cannot be scheduled after any other class then
		// allot a new classroom
		if(!is_compatible){
			finish_times[n_classrooms] = finish_times[j];
			printf("(classroom: %d, starttime:%d)\n", n_classrooms, start_times[j]);
			n_classrooms++;
		}
	}

	printf("\nTotal number of classrooms required: %d\n", n_classrooms);

}

int main(){

	int start_times[n_activities]  = {2, 1, 0, 5, 8, 9};
	int finish_times[n_activities] = {8, 2, 8, 8, 9, 12};

	printf("Interval Partitioning: ");
	interval_partitioning(start_times, finish_times, n_activities);

	return 0;
}

