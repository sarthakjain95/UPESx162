
#include<stdio.h>

// Q. Explain bitwise AND, OR, LEFT SHIFT and RIGHT SHIFT operators with example

int main(int argc, char * argv[]){

	int n=34;
	// AND
	printf("\nUsing AND operation on 34 and 3: %d", n&3);

	// OR
	printf("\nUsing OR operation on 34 and 3: %d", n|3);

	// LEFT
	printf("\nUsing LEFT SHIFT operation on 32 and 3: %d", 32<<3);

	// RIGHT SHIFT
	printf("\nUsing RIGHT SHIFT operation on 32 and 3: %d\n", 32>>3);

	return 0;
}
