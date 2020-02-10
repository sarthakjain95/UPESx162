
// Practical 5
// Title: Redefinition and Overloading
// Objective: To understand the concepts of Redefinition and Overloading

// Add two matrices by overloading binary operator +

#include<iostream>
using namespace std;

class Matrix{

	public:

		int values[3][3];

		Matrix(){ // 3 for 3x3

		}

		void print(){
			cout<<endl;
			for(int i=0; i<3; i++){
				for(int j=0; j<3; j++){
					cout<<values[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<endl;
		}

		Matrix operator +(Matrix b){
			Matrix c;
			for(int y=0; y<3; y++)
				for(int x=0; x<3; x++)
					c.values[y][x]= values[y][x] + b.values[y][x];
			return c;
		}
};

int main(){

	Matrix A,B;

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			A.values[i][j]= i+j;
			B.values[i][j]= i+j;
		}
	}

	A.print();
	B.print();

	Matrix C = A + B;

	C.print();

	return 0;
}
