
// Practical 2
// Title: Dynamic Memory Allocation
// Objective: To understand the concept of Dynamic Memory Allocation

// Design a class with a recursive member function with prototype “int fact(int &no)” to find the
// factorial of a number (n) obtained using a parameterized constructor. The class also has a
// destructor. Illustrate dynamic initialization of the variable ‘int result’ with a suitable function
// call to fact() from main().

#include<iostream>
#include<cstdio>
#include<cstdlib>

class factorial{

	public:
		int fact(int &n){
			int m= n-1;
			if(n>1) return n*fact(m);
			else return 1;
		}

};

int main(){

	factorial fn;
	int x= 6;
	std::cout<<"Factorial of 6 is "<<fn.fact(x)<<std::endl;

	return 0;
}
