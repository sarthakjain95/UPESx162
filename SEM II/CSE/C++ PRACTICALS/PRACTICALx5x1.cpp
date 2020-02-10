
// Practical 5
// Title: Redefinition and Overloading
// Objective: To understand the concepts of Redefinition and Overloading

// Base class ‘Temperature’ obtains temperature value in Celsius (c) through its parameterized
// constructor with default arguments and convert it into Fahrenheit value (f) and prints it using
// the function calculate(). Class ‘Temp’ inherits class ‘Temperature’ to obtain the temperature
// value in Fahrenheit and converts it into Kelvin value (k) and prints it using the redefined
// function calculate().

#include<iostream>

class Temperature{

	float temp_c;

	public:
		float temp_f;

		void calculate(){
			temp_f= (9.0/5.0)*(temp_c) + 32;
			std::cout<<"\nTemperature in Fahrenheit is: "<<temp_f<<" F";
		}

		Temperature(float t= 25){
			temp_c= t;
			calculate();
		}
};

class Temp : public Temperature{

	public:
		float temp_k;

		void calculate(){
			temp_k= (temp_f-32)/1.8 + 273.15;
			std::cout<<"\nTemperature in Kelvin is: "<<temp_k<<" k";
		}

		Temp(float kelvin= 273.15){
			calculate();
		}
};

int main(){

	Temp now;
	return 0;
}
