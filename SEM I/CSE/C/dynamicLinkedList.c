
// UPESx162
// CSE / C Basics
// dynamicLinkedList
// Recommended execution on https://repl.it/languages/c

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define true 1
#define false 0

struct node{
	int value;
	struct node * next;
};

int main(int argc, char * argv[]){
	
	system("clear");
	
	struct node * root;
	root= (struct node *)malloc( sizeof(struct node) );
	root->value= 32;
	root->next= NULL;
	
	struct node * ptr= root;
	struct node * temp;
	int n=1;
	
	while(n){
		// Allocated memory equal to struct node and returns pointer. 		
		temp= (struct node *)malloc( sizeof(struct node) ); 
		
		temp->next=NULL;
		temp->value=0;
		ptr->next = temp;
		
		printf("\nLocation of new node: %p\nEnter Value for current node:", temp);
		scanf("%d", &(temp->value) );
		
		printf("Do you want to add more elements? (y/n):");
		while((getchar())!='\n'); // Clearing Buffer
		scanf("%c",&n);
		
		ptr=temp;
		if(n!='y') break;
	}
	
	printf("\nPRINTING LINKED LIST\n");
	
	temp=root->next;
	while(temp != NULL){
		printf("%d ", temp->value );
		temp=temp->next;
	}
	printf("\n");

	return 0;
}

// https://github.com/sarthakjain95
// Sarthak Jain