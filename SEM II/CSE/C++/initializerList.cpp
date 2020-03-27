
#include<iostream>
using namespace std;

class pleaseBeAnAlternateUniverse{

	const float PI_inThisPossiblyAlternateUniverse;

	public:
		// Basically, initializerLists are usually used to declare values for
		// the constant variables in a class
		pleaseBeAnAlternateUniverse(float new_pi):PI_inThisPossiblyAlternateUniverse(new_pi){
			printf("\nWelcome to this Alternate Universe!");
		}

		void whatispi(){
			printf("\nPI is %.2f in this Universe.", PI_inThisPossiblyAlternateUniverse);
		}
};

int main(){

	pleaseBeAnAlternateUniverse _x_(69.69);
	_x_.whatispi();

	cout<<endl;
	return 0;
}
