
#include<stdio.h>

// Q. WAP to count number of 1's in the binary equivalant of the number entered by the user.

int main(int argc, char * argv[]){

	int n= 32, counter= 0;
	printf("Enter a Number:");
	scanf("%d", &n);

	while(n!=0){
		if( n & 0x1 == 1 ) counter++;
		n>>= 1;
	}

	printf("\nNumber of binary one(s): %d\n", counter);

	return 0;
}
