
// Practical – 9

// Title: Exception Handling
// Objective: To understand the concepts of Exception Handling.

// 3. Illustrate Stack unwinding while working with Exception Handling.

#include<iostream>
using namespace std;

void f3(){
	cout<<"   f3 Function Starts!\n";

	cout<<"   Exception generated in f3()!\n";
	throw "Exception occured in f3()!\n";

	cout<<"   f3 Function Ends!\n";
}

void f2(){
	cout<<"  f2 Function Starts!\n";

	f3();

	cout<<"  f2 Function Ends!\n";
}

void f1(){
	cout<<" f1 Function Starts!\n";

	try{
		f2();
	}catch(...){
		cout<<" Exception Caught in f1()\n";
	}

	cout<<" f1 Function Ends!\n";
}

int main(){
	cout<<"Starting Main Function!\n";

	f1();

	cout<<endl;
	try{
		f3();
	}catch(...){
		cout<<"Caught Exception in Main Function!\n";
	}

	cout<<"Main Function Ends\n";
}
