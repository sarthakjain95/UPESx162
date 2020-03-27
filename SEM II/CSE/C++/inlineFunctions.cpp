
#include<iostream>
#include<ctime>

#define MAX 200'000'000
using namespace std;

void showTimeStamp(time_t start, time_t end){
	cout<<"\nTook "<<(end-start)<<" seconds.\n";
}

int getFactorial(int x){
	int sum= 1; 
	for(int i=1; i<x; i++) sum*=i;
	return sum;
}

inline size_t getBigger(size_t x, size_t y){	
	return (x > y) ? x>>1 : y<<1;
}

size_t _getBigger_(size_t m, size_t n){
	return (m > n) ? m>>1 : n<<1;
}

int main(){

	// How Boaring!
	std::cout<<"\nFactorial of 5: "<<getFactorial(5)<<std::endl;

	// I'm gonna test this;
	// Let's check Time Complexity.
	printf("\nSit back and relax.\n\n");

	time_t start, end;

	cout<<"\nStarting tests on inline function";
	start= time(0);
	for(size_t i=0; i<MAX; i++) getBigger(i, i+1);
	end= time(0);
	cout<<"\nCompleted Tests";
	showTimeStamp(start, end);

	cout<<"\nStarting tests on normal function";
	start= time(0);
	for(size_t i=0; i<MAX; i++) _getBigger_(i, i+1);
	end= time(0);
	cout<<"\nCompleted Tests";
	showTimeStamp(start, end);

	cout<<endl;
	return 0;
}

// Results might vary with system and implementation
// I'd recommend running the program 2-3 times.

// Test Results on my system:
/*

Factorial of 5: 24

Sit back and relax.


Starting tests on inline function
Completed Tests
Took 0 seconds.

Starting tests on normal function
Completed Tests
Took 1 seconds.

*/
