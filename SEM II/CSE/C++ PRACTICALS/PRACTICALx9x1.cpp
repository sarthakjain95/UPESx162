
// Practical – 9

// Title: Exception Handling
// Objective: To understand the concepts of Exception Handling.

// 1. Write an interactive program to compute different roots of a Quadratic Equation. While
// computing square root of a number the input value must be tested for validity. If it is negative,
// the user defined function my_sqrt() should be invoked by set_terminate() to handle the
// exception promptly.

#include<iostream>
#include<cmath>
using namespace std;

void my_sqrt(){

	printf("Exception Occured!\n");
	printf("Cannot caculate square root for negative value!\n");
	exit(1);

}

double get_sqrt(float x){
	if(x<0) throw "Cannot Compute Square root of Negative Number!\n";
	else return sqrt(x);
}

int main(){

	set_terminate(my_sqrt);

	float a{}, b{}, c{};
	float discriminant{}, realPart{}, d{};
	float x1{}, x2{};

	printf("For Equation of type ax(^2) + bx + c = 0\n");

	printf("Enter a:");
	cin>>a;

	printf("Enter b:");
	cin>>b;

	printf("Enter c:");
	cin>>c;

	discriminant= b*b - 4*a*c;
	d= get_sqrt(discriminant);

	x1= (-b + d) / (2*a);
	x2= (-b - d) / (2*a);
	printf("Roots are real and different.\n");
	printf("x1= %.2f\n", x1);
	printf("x1= %.2f\n", x2);
	
	return 0;
}