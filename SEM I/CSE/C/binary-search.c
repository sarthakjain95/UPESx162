#include <stdio.h>
int BinarySearch(int A[], int n, int x){
	
	int num_steps = 0;	
	int mid = 0;
	int low = 0;
	int high = n - 1;
	
	while(low <= high){
		mid = low + (high - low)/2;
		num_steps += 1;
		if(x == A[mid]) return mid;
		else if(x < A[mid]) high = mid - 1;
		else low = mid + 1;	
	}
	
	printf("No. of steps taken: %d", num_steps);
	return -1;
	
}

int main(){
	int C[5] = {1, 2, 5, 6, 7};
	int x = 7;
	
	int index = BinarySearch(C, sizeof(C), x);
	if(index != 1) printf("%d is at index %d.", x, index);
	else printf("%d is not found.", x);
	
}
