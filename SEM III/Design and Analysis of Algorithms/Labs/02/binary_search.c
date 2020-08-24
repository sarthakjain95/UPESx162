
#include<stdio.h>
#include<stdlib.h>

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

	int len= 0;
	printf("Enter length of array: ");
	scanf("%d", &len);
	//
	int * arr= malloc(sizeof(int)*len);
	printf("\nEnter %d elements for Array\n", len);
	for(int i=0; i<len; i++){
		scanf("%d", &arr[i]);
	}
	bubble_sort(arr, len);
	//
	printf("Sorted array is ");
	for(int i=0; i<len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	//
	int element_to_find= 0;
	printf("Enter element to find: ");
	scanf("%d", &element_to_find);
	printf("\nElement to find: %d\n", element_to_find);
	//
	int res= binary_search(arr, 0, len, element_to_find);
	//	
	if(res==-1) printf("Element not found!\n");
	else printf("Element found at index %d\n", res);

	return 0;
}


