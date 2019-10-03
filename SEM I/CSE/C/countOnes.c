

#include<stdio.h>
#include<stdlib.h>


int main(int argc, char * argv[]){

	int n=0;
	printf("Enter a Number to count zeroes:");
	scanf("%d",&n);

	int counter=0;

	for(int i=0, j=1; i<(sizeof(int)*8) ; i++, j<<=1) 
		counter+= ((n&j)==j);
	
	printf("\nNumber of Ones : %d\n", counter);

	return 0;
}

