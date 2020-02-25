
// Practical 6
// Title: Virtual Functions and Abstract Classes
// Objective: To understand the concepts of Virtual Functions and Abstract Classes

// 1. Base class ‘Temperature’ obtains temperature value in Kelvin (k) through its parameterized
// constructor, convert it into Celsius value (c) and prints it using the virtual function calculate().
// Class ‘Temp’ inherits class ‘Temperature’ to obtain the temperature value in Celsius (c),
// converts it into Fahrenheit value (f) and prints it using the overridden function calculate().

#include<iostream>
using namespace std;

class Temperature{

	public:

		float tempC, tempK;

		Temperature(float tempK){
			this->tempK= tempK;
			tempC= tempK + 273.15;
		}

		virtual void calculate(){
			// tempC= tempK + 273.15;
			cout<<"Temperature in Celcius is "<<tempC<<"°C"<<endl;
		}

};

class Temp : public Temperature{

	float tempF;

	public:

		void calculate(){
			tempF= (tempC * 1.8) + 32;
			cout<<"Temperature in Fahrenheit is "<<tempF<<"°F"<<endl;
		}

		Temp(float tk) : Temperature(tk) {}

};


int main(){

	Temperature *d= new Temp(25);
	d->calculate();

	return 0;
}
