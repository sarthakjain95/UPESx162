
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//
#define n_test_cases 4

void bubble_sort(int arr[], int length){

	int temp;
	//
	for(int i=length-1; i>0; i--){
		for(int j=0; j<i; j++){
			if( arr[j]>arr[j+1] ){
				temp= arr[j];
				arr[j]= arr[j+1];
				arr[j+1]= temp;
			}
		}
	}

}

int linear_search(int arr[], int length, int elem){

	for(int i=0; i<length; i++){
		if(arr[i]==elem) 
			return i;
	}
	//
	return -1;

}

int binary_search(int arr[], int start, int end, int elem){

	if(end>=start){
		int mid= (end-start)/2 + start;
		if( arr[mid] == elem ) return mid;
		if( arr[mid] < elem ) return binary_search(arr, mid+1, end, elem);
		else return binary_search(arr, start, mid-1, elem);
	}

	return -1;
}

int main(){

	// Iterate over all test cases
	clock_t start, end;
	double time_taken;
	int res;
	//
	for(int i=0; i<n_test_cases; i++){

		int len= 0;
		printf("\nEnter length of array: ");
		scanf("%d", &len);
		//
		int * arr= (int*)malloc(sizeof(int)*len);
		printf("\nEnter %d elements for Array\n", len);
		for(int i=0; i<len; i++){
			scanf("%d", &arr[i]);
		}
		bubble_sort(arr, len);
		//
		int element_to_find= 0;
		printf("Enter element to find: ");
		scanf("%d", &element_to_find);
		printf("\nElement to find: %d\n", element_to_find);
		
		// Linear Search
		start= clock();
		res= linear_search(arr, len, element_to_find);
		end= clock();
		//	
		if(res==-1) printf("Element not found!\n");
		else printf("Element found at index %d\n", res);
		//
		time_taken= (((double)(end-start))*10e9)/CLOCKS_PER_SEC;
		printf("Total time taken by Linear Search: %6.3f\n", time_taken);
		
		// Binary Search
		start= clock();
		res= binary_search(arr, 0, len, element_to_find);
		end= clock();
		//	
		if(res==-1) printf("Element not found!\n");
		else printf("Element found at index %d\n", res);
		//
		time_taken= (((double)(end-start))*10e9)/CLOCKS_PER_SEC;
		printf("Total time taken by Binary Search: %6.3f\n", time_taken);
	}

	return 0;
}


