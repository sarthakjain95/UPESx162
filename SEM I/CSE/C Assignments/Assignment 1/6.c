
#include<stdio.h>

// Q. WAP to obtain value of two numbers in variables. Swap the values of variables, 
//    with a third variable and later without using third variable.

int main(int argc, char * argv[]){
	
	int n= 32, m= 64;
	printf("\nEnter two numbers:");
	scanf("%d%d",&n,&m);

	printf("\nNumbers before swapping n=%d and m=%d",n,m);
	printf("\n\nSwapping Numbers using a third variable");
	int temp= m;
	m= n;
	n= temp;
	printf("\nNumbers after swapping n=%d and m=%d",n,m);
	
	printf("\n\nSwapping Numbers without using a third variable");
	m= m+n;
	n= m-n;
	m= m-n;
	printf("\nNumbers after swapping n=%d and m=%d\n",n,m);

	return 0;
}
