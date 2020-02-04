
// Practical 2
// Title: Dynamic Memory Allocation
// Objective: To understand the concept of Dynamic Memory Allocation

// Implement the operations of a Queue Data Structure using 1D array and constructor
// initialization list.

#include<iostream>
#include<cstdio>

using namespace std;

class Queue{

	int front, rear, len;
	int * base;

	public:
		Queue(int x){
			len= x;
			base= (int *)malloc(sizeof(int)*len);
			front= -1;
			rear= -1;
		}

		~Queue(){ free(base); }

		void print(){

			if(front==-1) return;
			else{
				cout<<endl;
				int x= front;
				for(; x!=rear; x++){
					printf(" %d", base[x]);
				}
				cout<<" "<<base[x]<<endl;
			}
		}

		void enqueue(int n){

			if(rear==-1){
				front= 0;
				rear= 0;
				base[front]= n;
			}else if( (rear+1)<len ){
				rear= rear+1;
				base[rear]= n;
			}else{
				printf("\nOVERFLOW!\n");
			}

		}

		int dequeue(){

			int ret_val= 0;

			if(front==-1){
				printf("\nUNDERFLOW!\n");
			}else if(front==rear){
				ret_val= base[front];
				front= -1;
				rear= -1;
			}else{
				ret_val= base[front];
				front++;
			}

			return ret_val;
		}

};

int main(){

	int len= 0;
	cout<<"Enter size of Queue:";
	cin>>len;

	Queue queue(len);

	char ans= '0';
	int val;

	while(1){

		cout<<"\n1.Enter new value\n2.Delete a value\n3.Print\n4.Exit";
		cout<<"\nEnter Choice:";
		cin>>ans;

		switch(ans){

			case '1':cout<<"\nEnter Value:";
				 cin>>val;
				 queue.enqueue(val);
				 break;

			case '2':cout<<endl<<queue.dequeue()<<" deleted."<<endl;
				 break;
			
			case '3':queue.print();
				 break;
			
			case '4':exit(0); 
			         break;

			default: printf("Invalid!");

		}
	}

	return 0;
}