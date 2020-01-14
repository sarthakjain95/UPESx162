
// UPESx162 - Github
// classes.cpp

#include<iostream>
#include<cstdio>

using namespace std;

class typical_example_class{

	// Private by Default
	int a;
	char c;

public:

	typical_example_class(){
		cout<<"Constructor is running!"<<endl;
	}

	int get_a(){
		cout<<c;
		return a;
	}

	void set_a(int x){
		a= x;
		c= x;
	}

	~typical_example_class(){
		cout<<"Deconstructor is running!"<<endl;
	}
};

int main(){


	{ // In scope
		typical_example_class cls;
		cls.set_a(33);
		// cout<<cls.a; // Won't work, 'a' is private.
		cout<<"|a is "<<cls.get_a()<<endl;
	} // Out of scope

	// delete cls;

	return 0;
}

// sarthakjain95
