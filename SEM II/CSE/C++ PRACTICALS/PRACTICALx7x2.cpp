
// Practical – 7

// Title: Generic Programming
// Objective: To understand the concepts of Generic Functions and Generic Classes

// 2. Write a generic class to implement the operations of a stack data structure using arrays. This
// generic class must support integer and float types.

#include<iostream>
using namespace std;

template <class num>
class Stack{
	
	num * arr;
	int len, top;

	public:
		Stack(int len){
			this->len= len;
			arr= new num[len];
		}

		void push(num x){
			if( top>=len ){ 
				cout<<"Overflow! "<<"Could not add "<<x<<endl;
			}else{
				arr[top]= x;
				top++;
				cout<<"Added "<<x<<endl;				
			}

		}

		void pop(){
			if( top<=0 ) cout<<"Underflow!"<<endl;
			else{
				cout<<"Removed "<<arr[top-1]<<endl;
				top--;
			}
		}

		void peep(){
			if( top>0 ){
				cout<<":Top: "<<arr[top-1]<<endl;				
			}
		}

		void print(){
			cout<<":Printing: ";
			for(int i=0; i<top; i++) cout<<arr[i]<<" ";
			cout<<endl;
		}


};

int main(){

	// Stack<int> s1(3);
	
	// s1.push(5);
	// s1.push(22);
	
	// s1.print();
	// s1.peep();
	
	// s1.pop();
	// s1.pop();
	// s1.pop();
	
	// s1.push(2234);
	// s1.push(223);
	// s1.push(567);
	// s1.push(2345);

	// s1.peep();
	// s1.print();

	Stack<char> s1(5);
	
	s1.push('e');
	s1.push('t');
	
	s1.print();
	s1.peep();
	
	s1.pop();
	s1.pop();
	s1.pop();
	
	s1.push('o');
	s1.push('y');
	s1.push('p');
	s1.push('q');

	s1.peep();
	s1.print();
	
	return 0;

}

