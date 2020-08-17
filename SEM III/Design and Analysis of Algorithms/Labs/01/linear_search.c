
#include<stdio.h>
//
#define length 10

int main(){

	// Check length before changing the array
	int arr[length]= {3, 21, 2, 5, 6, 78, 67, 8, 89, 12};
	int element= 67;

	// Linear search
	for(int i=0; i<length; i++){
		if(arr[i]==element){
			printf("Element found at %d index\n", i);
			break;
		}
	}

	return 0;
}
