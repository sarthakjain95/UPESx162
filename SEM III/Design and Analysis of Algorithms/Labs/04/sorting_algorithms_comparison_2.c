
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
	ALGORITHMS COMPARED:
	- Bubble Sort
	- Selection Sort
	- Merge Sort 
	- Quick Sort
*/

#define max_tests 32

// Test results array
int idx= 0;
double bs_rec[max_tests];
double ss_rec[max_tests];
double ms_rec[max_tests];
double qs_rec[max_tests];

int * generate_random_array(int size){
	//
	return malloc( sizeof(int) * size );
}

void bubble_sort(int * arr, int size){

	int temp;
	//
	for(int i=size; i>0; i--){
		for(int j=0; j<i; j++){
			if(arr[j] > arr[j+1]){
				temp= arr[j];
				arr[j]= arr[j+1];
				arr[j+1]= temp;
			}
		}
	}

}

void selection_sort(int * arr, int size){

	int temp;
	//
	for(int i=0; i<size; i++){
		int lowest_element_index= i;
		for(int j=i; j<size; j++){
			if( arr[j] < arr[lowest_element_index] ){
				lowest_element_index= j;
			}		
		}
		//
		temp= arr[lowest_element_index];
		arr[lowest_element_index]= arr[i];
		arr[i]= temp;
	}

}

void merge(int * arr, int start, int mid, int end){

		int l_size= mid-start+1;
		int r_size= end-mid;
		int * l_arr= malloc( sizeof(int) * l_size );
		int * r_arr= malloc( sizeof(int) * r_size );
		//
		for(int i=0; i<l_size; i++) l_arr[i]= arr[start+i];
		for(int i=0; i<r_size; i++) r_arr[i]= arr[mid+i+1];
		//
		int i, j, k;
		i= 0;
		j= 0;
		k= start;
		//
		while(i<l_size && j<r_size){
			//
			if(l_arr[i]<r_arr[j]){
				arr[k]= l_arr[i];
				i++;
			}else{
				arr[k]= r_arr[j];
				j++;
			}
			//
			k++;
		}
		//
		while(i<l_size){
			arr[k]= l_arr[i];
			i++;
			k++;
		}
		//
		while(j<r_size){
			arr[k]= r_arr[j];
			j++;
			k++;
		}
		
}

void merge_sort(int * arr, int start, int end){

	if(start<end){
		int mid= start + (end-start)/2;
		//
		// Sort sub arrays
		merge_sort(arr, start, mid);
		merge_sort(arr, mid+1, end);
		//
		// Combine/Merge the two sorted sub arrays
		merge(arr, start, mid, end);
	}

}

int partition(int * arr, int start, int end){

	int pivot= arr[end];
	int i= start - 1;
	int temp;

	for(int j=start; j<end; j++){
		if(arr[j] < pivot){
			i++;
			temp= arr[j];
			arr[j]= arr[i];
			arr[i]= temp;
		}
	}

	temp= arr[i+1];
	arr[i+1]= arr[end];
	arr[end]= temp;

	return i+1;
}

void quick_sort(int * arr, int start, int end){

	if(start < end){
		int pivot= partition(arr, start, end);
		quick_sort(arr, start, pivot-1);
		quick_sort(arr, pivot+1, end);
	}

}

int sorting_tests(int size){

	int * bst1= generate_random_array(size);
	int * sst1= generate_random_array(size);
	int * mst1= generate_random_array(size);
	int * qst1= generate_random_array(size);
	//
	int n=0;
	for(int i=0; i<size; i++){
		n= rand() % size;
		bst1[i]= n;
		sst1[i]= n;
		mst1[i]= n;
		qst1[i]= n;
	}
	
	clock_t start, end;
	double time_taken= 0;
	//
	printf("Tests for %d elements\n", size);
	
	// Bubble Sort Test
	start= clock();
	bubble_sort(bst1, size);	
	end= clock();
	time_taken= ( (end-start) * 10e3 ) / CLOCKS_PER_SEC;
	printf("Bubble sort took %lf micro sec\n", time_taken);
	// Save sorting time in global array
	bs_rec[idx]= time_taken; // saving results
	
	// Selection Sort Test
	start= clock();
	selection_sort(sst1, size);	
	end= clock();
	time_taken= ( (end-start) * 10e3 ) / CLOCKS_PER_SEC;
	printf("Selection sort took %lf micro sec\n", time_taken);
	ss_rec[idx]= time_taken;
	
	// Merge Sort Test
	start= clock();
	merge_sort(mst1, 0, size);	
	end= clock();
	time_taken= ( (end-start) * 10e3 ) / CLOCKS_PER_SEC;
	printf("Merge sort took %lf micro sec\n", time_taken);
	ms_rec[idx]= time_taken;
	
	// Quick Sort Test
	start= clock();
	quick_sort(qst1, 0, size-1);	
	end= clock();
	time_taken= ( (end-start) * 10e3 ) / CLOCKS_PER_SEC;
	printf("Quick sort took %lf micro sec\n", time_taken);
	qs_rec[idx]= time_taken;

	//
	idx++; // incrementing results array index
	printf("\n");
}

int main(){

	// constant seed
	srand(42);
	//
	sorting_tests(10000);
	sorting_tests(20000);
	sorting_tests(30000);
	sorting_tests(40000);
	sorting_tests(50000);
	sorting_tests(60000);
	sorting_tests(70000);
	sorting_tests(80000);
	sorting_tests(90000);
	sorting_tests(200000);

	// Uncomment for getting plot arrays
	//
	// printf("Bubble sort: [");
	// for(int i=0; i<idx; i++) printf("%.2lf, ", bs_rec[i]);
	// printf("]\n");
	
	// printf("Selection sort: [");
	// for(int i=0; i<idx; i++) printf("%.2lf, ", ss_rec[i]);
	// printf("]\n");
	
	// printf("Merge sort: [");
	// for(int i=0; i<idx; i++) printf("%.2lf, ", ms_rec[i]);
	// printf("]\n");
	
	// printf("Quick sort: [");
	// for(int i=0; i<idx; i++) printf("%.2lf, ", qs_rec[i]);
	// printf("]\n");

	return 0;
}
