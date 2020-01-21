
#include<iostream>
#include<cstdio>

using namespace std;

class CircularQueue{

	int front, rear, len;
	int * base;

	public:
		CircularQueue(int x){
			len= x;
			base= (int *)malloc(sizeof(int)*len);
			front= -1;
			rear= -1;
		}

		~CircularQueue(){
			free(base);
		}

		void print(){
			if(front==-1) return;
			else{
				cout<<endl;
				int x= front;
				for(; x!=rear; x=(x+1)%len){
					printf(" %d", base[x]);
				}
				cout<<" "<<base[x];
			}
		}

		void enqueue(int n){

			if(rear==-1){
				front= 0;
				rear= 0;
				base[rear]= n;
			}else if( (rear+1)%len != front ){
				rear= (rear+1)%len;
				base[rear]= n;
			}else{
				printf("\nOverflow!");
			}

		}

		int dequeue(){

			int ret_val= 0;

			if(front==-1){
				printf("\nUnderflow!");
			}else if(front==rear){
				ret_val= base[front];
				front= -1;
				rear= -1;
			}else{
				ret_val= base[front];
				front= (front+1)%len;
			}

			return ret_val;
		}

};

int main(){

	int len= 0;
	cout<<"Enter size of Queue:";
	cin>>len;

	CircularQueue queue(len);

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

			case '2':cout<<endl<<queue.dequeue();
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
