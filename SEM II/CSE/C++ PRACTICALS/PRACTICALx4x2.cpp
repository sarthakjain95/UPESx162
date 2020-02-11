
// Practical 4x2
// Title: Friends to a Class and Inheritance
// Objective: To understand the concepts of friend function, friend class and Inheritance

// Read molecular values for Oxygen, Hydrogen and Sulphur in three different classes named
// Oxygen, Hydrogen and Sulphur. These classes have a common non-member friend function
// which is used to find out the chemical compounds (Sulphuric acid, Sulphurous acid,
// Thiosulphuric acid) that can be formed based on the given input molecular values.

#include<iostream>
#include<cstdio>
using namespace std;

class Oxygen;
class Hydrogen;
class Sulphur;

class Oxygen{

	int n;

	public:
		Oxygen(int n){
			this->n= n;
		}

		friend bool getChemicalCompound(Oxygen &, Hydrogen &, Sulphur &);
};

class Hydrogen{

        int n;

        public:
                Hydrogen(int n){
                        this->n= n;
                }

		friend bool getChemicalCompound(Oxygen &, Hydrogen &, Sulphur &);
};

class Sulphur{

        int n;

        public:
                Sulphur(int n){
                        this->n= n;
                }


		friend bool getChemicalCompound(Oxygen &, Hydrogen &, Sulphur &);
};

bool getChemicalCompound(Oxygen &o, Hydrogen &h, Sulphur &s){

	printf("Given Compound:\nH:%d\nS:%d\nO:%d\n\n", h.n, s.n, o.n);

	if(h.n==2 && s.n==1 && o.n==4){
		cout<<"Sulphuric Acid"<<endl;
		return true;
	}else if(h.n==2 && s.n==1 && o.n==3){
		cout<<"Sulphurous Acid"<<endl;
		return true;
	}else if(h.n==2 && s.n==3 && o.n==3){
		cout<<"Thiosulphurous Acid"<<endl;
		return true;
	}else{
		cout<<"Given Compound was not found."<<endl;
		return false;
	}

}

int main(){

	Oxygen o(4);
	Hydrogen h(2);
	Sulphur s(1);

	getChemicalCompound(o, h, s);

	// (more) Tests

        Oxygen a(3);
        Hydrogen b(2);
        Sulphur c(1);

        getChemicalCompound(a, b, c);

        Oxygen l(4);
        Hydrogen m(2);
        Sulphur n(2);

        getChemicalCompound(l, m, n);

        Oxygen x(3);
        Hydrogen y(2);
        Sulphur z(3);

        getChemicalCompound(x, y, z);

	return 0;
}
