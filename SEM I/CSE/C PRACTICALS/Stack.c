#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0

typedef struct{
	int data;
	struct node * next;
} node;

node * root;
node * temp;

int rem_(){
	// Pops off a node from stack
	printf("\nRemoving an element from the stack.");

	node * temp2= root;
	int removedData=0;
	while(temp2->next!=temp) temp2= temp2->next;

	removedData= temp->data;
	free(temp);
	temp= temp2;
	temp->next= NULL;

	printf("\nRemoved element is %d\n", removedData);

	return  0;
}

void add_(){
	// Adds a new node to stack
	printf("\nAdding a new node\n");

	node * newNode= malloc(sizeof(node));

	while(getchar()!='\n');

	printf("Enter the value for new node:");
	scanf("%d", &(newNode->data) );
	newNode->next= NULL;

	temp->next= newNode;
	temp= newNode;

	printf("\n");
}

void dis_(){
	// Displays the whole stack
	printf("\nDisplaying the stack\n");

	node * temp2= root;

	while(temp2!=NULL){
		printf("%d  ", temp2->data);
		temp2= temp2->next;
	}

	printf("\n");
}

int main(int argc, char * argv[]){

	system("clear");
	root= malloc(sizeof(node));
	root->data= 0;
	temp= root;

	printf("Root is set to %d\n\n", root->data);
	printf("Use the given options to control the stack:\n\n");

	int rep=0;
	while(true){
		printf("\n1: Add a Node");
		printf("\n2: Remove an element from node");
		printf("\n3: Display the stack");
		printf("\n4: Exit the program\n");
		printf("\nENTER: ");
		scanf("%d",&rep);
		switch(rep){
			case 1: add_(); break;
			case 2:	rem_(); break;
			case 3:	dis_(); break;
			case 4: return 0;
			dafault: printf("Invalid choice!\n");
		}
	}

	return 0;
}
