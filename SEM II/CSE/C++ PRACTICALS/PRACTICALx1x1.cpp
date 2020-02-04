
// Practical 1
// Title: Classes and Objects
// Objective: To understand the concept of classes and objects, data hiding and encapsulation

// Consider rectangle, square, triangle and circle as 4 given shapes with a
// common area of 314 sq.cm. The length of a rectangle is 2cm and height of
// right-angled triangle is 4cm. Find the shape which has the smallest perimeter
// and largest perimeter.

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

#define PI 3.14159

class Shape{

	float area;
	float rectangle_breadth, rectangle_length;
	float triangle_base, traingle_height;
	float circle_radius;
	float square_side;

	public:

		Shape(float common_area, float rectangle_length, float traingle_height){
			area= common_area;
			this->rectangle_length= rectangle_length;
			this->traingle_height= traingle_height;
		}

		float rectangle_perimeter(){
			rectangle_breadth= area/rectangle_length;
			return 2.0*( rectangle_length + rectangle_breadth );
		}

		float square_perimeter(){
			square_side= sqrt(area);
			return 4*square_side;
		}

		float triangle_perimeter(){
			triangle_base= 2.0*area/traingle_height;
			float hypo= sqrt( traingle_height*traingle_height + pow((triangle_base/2.0),2) );
			return 2.0*hypo + triangle_base;
		}

		float circle_perimeter(){
			circle_radius= area / PI;
			return 2.0 * PI * circle_radius;
		}
};

int main(){

	Shape rstc(314,2,4);

	std::cout<<"Rectangle perimeter: \t"<<rstc.rectangle_perimeter()<<" cm(s).";
	std::cout<<"\nSquare perimeter: \t"<<rstc.square_perimeter()<<" cm(s).";
	std::cout<<"\nTriangle perimeter: \t"<<rstc.triangle_perimeter()<<" cm(s).";
	std::cout<<"\nCircle perimeter: \t"<<rstc.circle_perimeter()<<" cm(s).";

	std::cout<<std::endl;
	return 0;
}
