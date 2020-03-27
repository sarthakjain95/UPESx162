#include <iostream>
using namespace std;

template<typename T>
class Number {
	private:
		T num;
	public:
		void setNum(T n);
		T plus1() const;
};

template<typename T>
void Number<T>::setNum(T n) {
	num = n;
}

template<typename T>
T Number<T>::plus1() const {
	return num + 1;
}

template<typename X>
X add(X a, X b){
	X c= a+b;
	return c;
}

template<typename X, typename Y>
X add_different(X a, Y b){
	X c;
	c= a+b;
	return c;
}

int main() {

	Number<int> anInt;
	anInt.setNum(1);
	cout<<"integer + 1 is "<<anInt.plus1()<<"\n";
	
	Number<double> aDouble;
	aDouble.setNum(3.1415);
	cout<<"double + 1 is "<< aDouble.plus1()<<"\n"; // Prints 4.14159
	
	string a= "foo";
	string b= "bar";
	cout<<"Add function with strings: "<<add(a,b)<<endl;
	cout<<"Add function with floats but int specified: "<<add<int>(16.32,16.67)<<endl;

	// Line below give out error!
	// cout<<add(324,34.64)<<endl;
	cout<<"Add function with deduction problem but int specified: "<<add<int>(24,45.35)<<endl;

	cout<<"Add function with different argument types: "<<add_different<int, float>(90,6.35)<<endl;
	return 0;
}