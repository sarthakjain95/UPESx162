
// Practical 3
// Title: Dynamic Memory Allocation
// Objective: To understand the concept of Dynamic Memory Allocation

// Implement the operations of a dynamically allocated Stack data structure using a self-referential
// structure and single Linked List.

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

class Node{

	public:
		int data;
		Node * prev;

};

class Stack{

	Node * top;

	public:
		
		Stack(){
			this->top=NULL;
		}

		void push(int val){

			Node * new_ptr= (Node *)malloc(sizeof(Node));
			new_ptr->data= val;
			new_ptr->prev= NULL;
			if(top!=NULL) new_ptr->prev= this->top;
			this->top= new_ptr;
		}

		int pop(){

			int ret_val= 0;

			if(top==NULL){
				printf("\nUnderflow!");
			}else{
				Node * temp;
				temp= this->top;
				this->top= (this->top)->prev;
				ret_val= temp->data;
				free(temp);
			}

			return ret_val;
		}

		int peek(){

			if(top==NULL){
				printf("\nNo element in the stack!");
				return 0;
			}else{
				return top->data;
			}
		}

		void print(){

			if(this->top==NULL){
                                printf("\nNo element in the stack!\n");
                                return;
			}

			Node * temp= this->top;
			printf("\n%d", temp->data);
			while(temp->prev!=NULL){
				temp= temp->prev;
				printf("\n%d", temp->data);
			}

			cout<<endl;
		}

		~Stack(){}
};


int main(){

	Stack s1;

	char ans= '1';
	int val;

	while(1){

		printf("\nChoose one of the following options:\n");
		printf("1.Enter a node\n2.Delete a node\n3.Print Stack\n4.Peek top value\n5.Exit\n");
		printf("Enter Value:");
		cin>>ans;

		switch(ans){

			case '1': printf("\nEnter a value:");
				  cin>>val;
				  s1.push(val);
				  break;
			
			case '2': printf("\nDeleted value is %d", s1.pop());
				  break;
			
			case '3': s1.print();
				  break;
			
			case '4': printf("\nTop value is %d\n", s1.peek());
				  break;
			
			case '5': return 0; 
			
			default:  printf("\n%c is invalid input\n", ans);
		
		}

	}

	return 0;
}
