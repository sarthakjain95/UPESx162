
#include<stdio.h>

// Q. WAP to Function main() gets two numbers from the user and calls two functions defined as follows:
// a.	The function “void swap1(int *, int*)” swaps the two numbers using bitwise operator and displays them.
// b.	The function “int swap2(int, int)” swaps two numbers using arithmetic binary operator plus (+) and minus (-).

void swap1(int *a, int *b){

	*a= *a ^ *b;
	*b= *a ^ *b;
	*a= *a ^ *b;
	
	printf("\nNumbers after swap(in swap1): p=%d q=%d", *a, *b);
}

int swap2(int m, int n){

	m= m+n;
	n= m-n;
	m= m-n;

	printf("\nNumbers after swap(in swap2): p=%d q=%d", m, n);
	return 0;
}

int main(int argc, char * argv[]){
	
	int p=0, q=0;
	printf("Enter two numbers to be swapped: ");
	scanf("%d%d",&p ,&q);
	printf("\nNumbers before swap: p=%d q=%d", p, q);

	printf("\n\nSwapping Numbers using bitwise operators");
	swap1(&p, &q);
	printf("\nNumbers after swap(in main): p=%d q=%d", p, q);

	printf("\n\nSwapping Numbers using arithmetic operators");
	swap2(p, q);
	printf("\nNumbers after swap(in main): p=%d q=%d\n", p, q);

	return 0;
}
