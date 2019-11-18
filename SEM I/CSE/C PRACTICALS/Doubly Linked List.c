#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0

// Doubly Linked List Node
typedef struct {
	int data;
	struct node * next;
	struct node * prev;
} node;


node * root= NULL;
node * temp= NULL;

void addNode();
int delNode();
void displayList();


int main(){

	system("clear");
	int val;
	while(true){
		//system("clear");
		printf("\n\n:Options:\n1. Enter a node.\n2. Delete a Value.\n3. Display the list.\n4. Exit\n");
		printf("Enter the choice!:");
		scanf("%d", &val);

		switch(val){
			case 1: addNode(); break;
			case 2: delNode(); break;
			case 3: displayList(); break;
			case 4: return 0;
			default: printf("\nInvalid choice! Try Again!\n");
		}
	}
	return 0;
}


void addNode(){
	int n;
	printf("\nEnter the value to be added:");
	scanf("%d", &n);
	node * newNode= (node *)malloc(sizeof(node));
	newNode->next= NULL;
	newNode->prev= NULL;
	newNode->data= n;
	if(root==NULL){
		root= newNode;
	}else{
		temp= root;
		while(temp->next!=NULL) temp= temp->next;
		temp->next= newNode;
		newNode->prev= temp;
	}
}

int delNode(){
	printf("\nDeleting a value from the list");
	printf("\nEnter the value to be deleted:");
	int val= 0;
	node * node_to_free;
	node * temp2;
	scanf("%d", &val);
	temp= root;

	if(temp->data==val){
		node_to_free= root;
		root= root->next;
		free(node_to_free);
	}else{
		while(temp!=NULL && temp->data!=val){
			temp= temp->next;
		}
		if(temp==NULL){
			printf("\nThe given value was not found in the list!");
			return -1;
		}else{
			if(temp->next==NULL){
				node_to_free=temp;
				temp= temp->prev;
				free(node_to_free);
				temp->next= NULL;
			}else{
				temp= temp->prev;
				node_to_free= temp->next;
				temp2= node_to_free->next;
				temp->next= temp2;
				temp2->prev= temp;
				free(node_to_free);
			}
		}
	}

	printf("\nDeleted the value from list!");
	return val;
}


void displayList(){
	printf("\nDisplaying the list!\n");
	temp= root;
	while(temp!=NULL){
		printf("%d ", temp->data);
		temp= temp->next;
	}
}
