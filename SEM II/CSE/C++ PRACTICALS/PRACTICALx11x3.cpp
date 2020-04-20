
// EXPERIMENT – 11

// Title: Trees
// Objective: To understand the concepts of Trees Data Structure

// 3. Implement Heap Sort.

#include<iostream>
using namespace std;

#define LEFT(pos)   (pos<<1)+1 
#define RIGHT(pos)  (pos<<1)+2 

void MAX_HEAPIFY(int heap[], int len, int pos){
	
	int l= LEFT(pos);
	int r= RIGHT(pos);
	int temp, largest;

	if( l<len && heap[l]>heap[pos] ) largest= l;
	else largest= pos;
	if( r<len && heap[r]>heap[largest] ) largest= r;

	if(largest!=pos){
		temp= heap[largest];
		heap[largest]= heap[pos];
		heap[pos]= temp;
		MAX_HEAPIFY(heap, len, largest);
	}

}

void HEAP_SORT(int heap[], int len){

	for(int i=len/2-1; i>=0; --i)
		MAX_HEAPIFY(heap, len, i);
	
	int temp;
	for(int i=len-1; i>=0; --i){
		temp= heap[0];
		heap[0]= heap[i];
		heap[i]= temp;
		MAX_HEAPIFY(heap, i, 0);
	}

}

int main(){

	int size{};
	printf("Enter size of Array:");
	cin>>size;

	int arr[size];
	
	printf("Enter %d element(s) for the array:\n", size);
	for(int x=0; x<size; x++) cin>>arr[x];

	printf("\nUnsorted Array is:\n");
	for(int x=0; x<size; x++){
		printf("%d ", arr[x]);
	}

	HEAP_SORT(arr, size);

	printf("\nSorted Arrayt is:\n");
	for(int x=0; x<size; x++){
		printf("%d ", arr[x]);
	}
	cout<<endl;

	return 0;
}

