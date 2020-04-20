
// EXPERIMENT – 11

// Title: Trees
// Objective: To understand the concepts of Trees Data Structure

// 1. Create a binary tree using an array/linked List.

#include<iostream>
using namespace std;

void insert_node(char tree[], char node, int pos){
	if( pos==0 ){
		if( tree[pos] != '\0' ) throw "Tree has a root!";
		else tree[pos]= node;
	}else{
		int parent= pos/2;
		if(tree[parent] == '\0') throw "Parent not found!";
		else if(tree[pos]!='\0') throw "Node Overwrite!";
		else tree[pos]= node;
	}
}

void print_tree(char tree[], int size) { 
	printf("Printing Tree as array:\n");
	int level= 1;
	for(int i{}; i<size;){ 
		int x{};
		for(; i<size && x<level; x++){
			if(tree[i]!='\0') printf("%c ", tree[i]); 
			else printf("- "); 
			i++;
		}
		if(x<level){
			for(;x<level;x++) printf("- ");
		}
		level<<=1;
		cout<<endl;
	} 
	cout<<endl;
} 
  
int main() { 

	int n{};
	printf("Enter number of nodes:");
	cin>>n;

	char tree[n+1];
	for(int i=0; i<n; i++) tree[i]= '\0';

	for(int i{}; i<n; i++){
		char node{};
		int pos{};
		printf("Enter Node and Position:");
		cin>>node;
		cin>>pos;
		try{
			insert_node(tree, node, pos);
		}catch(const char* e){
			printf("Error Occured: %s\n", e);
		}
	}

	print_tree(tree, n);

	return 0; 
} 
