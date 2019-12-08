#include <stdio.h>
void bubble_sort(int arr[], int n);
int main(){
	int array[10], n, i;
	
	printf("Enter number of elements: ");
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		printf("Enter integer %d: ", i);
		scanf("%d", &array[i]);
	}
	
	bubble_sort(array, n);
	
	printf("Sorted list is :");
	for(i = 0; i < n; i++){
		printf("%d, ", array[i]);
	}

	return 0;
}

void bubble_sort(int arr[], int n){
	int i, j, temp;
	for(i = 0; i < n; i++){
		for(j = 0; j < n - i -1; j++){
			if(arr[i] > arr[i+1]){
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
}
