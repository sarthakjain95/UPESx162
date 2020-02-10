
// Practical 5
// Title: Redefinition and Overloading
// Objective: To understand the concepts of Redefinition and Overloading

// Define a class with following member functions
// a. constructor to obtain side1, side2.
// b. void choice() to have menu driven control to find and print the area of square, rectangle, or triangle
// c. int calculate(int) to compute the Area of Square
// d. int calculate(int, int) to compute the Area of Rectangle
// e. float calculate(int, int) to compute the Area of Triangle

#include<iostream>
using namespace std;

class Shape{

	float side1, side2;

	public:
		Shape(float a, float b){
			side1= a;
			side2= b;
		}

		int calculate_square(int side){ // Square
			return side*side;
		}

		int calculate_rectangle(int height, int width){ // Rectangle
			return height*width;
		}

		float calculate_triangle(int base, int height){ // Triangle
			return 0.5*base*height;
		}

		void choice(){
			char ans= '0';
			bool res= true;
			while(res){
				printf("\nChoose one of the following options:");
				printf("\n1. Get Square Area\n2. Get Rectangle Area\n3. Get Triangle Area");
				printf("\n4. Quit");
				printf("\nEnter: ");
				cin>>ans;
				switch(ans){
					case '1': cout<<"\nArea of Square is:"<<calculate_square(side1);
						  break;
					case '2': cout<<"\nArea of Rectangle is:"<<calculate_rectangle(side1, side2);
						  break;
					case '3': cout<<"\nArea of Triangle is:"<<calculate_triangle(side1, side2);
						  break;
					case '4': res= false; 
						  break;
					default:  cout<<"\nInvalid Response.";
				}
			}
		}
};

int main(){

	Shape foobar(32, 42);
	foobar.choice();
	return 0;
}
