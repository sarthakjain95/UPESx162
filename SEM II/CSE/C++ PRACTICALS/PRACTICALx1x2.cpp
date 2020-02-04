
// Practical 1
// Title: Classes and Objects
// Objective: To understand the concept of classes and objects, data hiding and encapsulation

// Use for loop to print the truth table for the expression XY+Z.

#include<iostream>
#include<cstdio>
#include<cstdlib>


int main(){

	printf("\n| X | Y | Z | X*Y | X*Y+Z |\n");
	printf("---------------------------\n");
	for(int x=0; x<=1; x++)
		for(int y=0; y<=1; y++)
			for(int z=0; z<=1; z++)
				printf("| %d | %d | %d |  %d  |   %d   |\n", x, y, z, x*y, (x*y+z)%2);

	printf("\n");
	return 0;
}
