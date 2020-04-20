
// EXPERIMENT – 11

// Title: Trees
// Objective: To understand the concepts of Trees Data Structure

// 2. Construct a Binary Tree and perform Inorder, Preorder and Postorder Traversal.

#include<iostream>
using namespace std;

#define LEFT_CHILD(pos)  pos*2 + 0
#define RIGHT_CHILD(pos) pos*2 + 1

void insert_node(char tree[], char node, int pos){
	if( pos==0 ){
		throw "Cannot add node at 0. Tree starts from 1!";
	}else if( pos==1 ){
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
	printf("\nPrinting Tree with levels:\n");
	int level= 1;
	for(int i{}; i<size;){ 
		int x{};
		for(; i<size && x<level; x++){
			if(tree[i+1]!='\0') printf("%c ", tree[i+1]); 
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
	// printf("Printing Tree as array:\n");
	// for(int i=0; i<size; i++){
	// 	printf("%d:%c ", i, tree[i]);
	// }
	// cout<<endl;
} 

void inorder_traversal(char tree[], int size, int index){
	if(index>0 && tree[index]!='\0' && index<size){
		inorder_traversal(tree, size, LEFT_CHILD(index));
		printf("%c ", tree[index]);
		inorder_traversal(tree, size, RIGHT_CHILD(index));
	}
}

void preorder_traversal(char tree[], int size, int index){
	if(index>0 && tree[index]!='\0' && index<size){
		printf("%c ", tree[index]);
		preorder_traversal(tree, size, LEFT_CHILD(index));
		preorder_traversal(tree, size, RIGHT_CHILD(index));
	}
}

void postorder_traversal(char tree[], int size, int index){
	if(index>0 && tree[index]!='\0' && index<size){
		postorder_traversal(tree, size, LEFT_CHILD(index));
		postorder_traversal(tree, size, RIGHT_CHILD(index));
		printf("%c ", tree[index]);
	}
}
  
int main() { 

	int n{};
	printf("Enter number of nodes:");
	cin>>n;

	char tree[n];
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
	n++;

	print_tree(tree, n);

	printf("\nInorder Treaversal:\n");
	inorder_traversal(tree, n, 1);

	printf("\nPreorder Treaversal:\n");
	preorder_traversal(tree, n, 1);

	printf("\nPostorder Treaversal:\n");
	postorder_traversal(tree, n, 1);

	cout<<endl;
	return 0; 
} 

