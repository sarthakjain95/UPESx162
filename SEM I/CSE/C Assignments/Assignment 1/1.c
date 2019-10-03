
#include<stdio.h>

// Q. Write an algorithm of to find the factorial of a number. And draw the flowchart for the same.

unsigned long factorial(unsigned int num){

	unsigned long sum= 1;
	for(int i=1;i<=num;i++) sum*= i;

	return sum;
}

int main(int argc, char * argv[]){

	unsigned int n= 3;
	printf("Enter a Number:");
	scanf("%d",&n);

	unsigned long result= factorial(n);
	printf("Factorial for %d is %lu\n",n, result); 

	return 0;
}
