
#include<stdio.h>

// Q. WAP to input and print 1D array using pointer.

int main(int argc, char * argv[]){

	size_t size= 4;
	long arr[size];
	printf("Input %d element(s) in the array:\n", size);

	for(int i=0;i<size;i++)
		scanf("%lu", (arr+i) );

	printf("\nPrinting Array:\n");
	for(int i=0;i<size;i++)
		printf("%lu ", *(arr+i));

	printf("\n");
	return 0;
}
