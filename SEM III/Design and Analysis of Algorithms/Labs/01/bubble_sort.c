
#include<stdio.h>
#define arr_length 10

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

void display_array(int arr[], int length){

	for(int i=0; i<length; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

}

int main(){

	int arr[10]= {120, 1, 23, 4, 78, 23, 89, 122, 90, 2};
	//
	printf("Unsorted Array is:\t");
	display_array(arr, arr_length);
	bubble_sort(arr, arr_length);
	printf("Sorted Array is:\t");
	display_array(arr, arr_length);

	return 0;
}
