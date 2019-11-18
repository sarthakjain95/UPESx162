#include<stdio.h>
#include<stdlib.h>

#define on 1
#define off 0

// Nested Structures
struct switch_{
	int state;
	struct coords{
		int cx;
		int cy;
	} pos;
	int power;
};

// Structure referencing a structure
typedef struct{
	int data;
	struct node * next;
} node;

node * root=NULL;
node * list_status;

int main(int argc, char * argv[]){

	struct switch_ s1;
	s1.state=on;
	s1.power=32;
	s1.pos.cx=4;
	s1.pos.cy=4;
	printf("\n*Switch Data* \nstate=%d \npower=%d \ncoordinate_x=%d \ncoordinate_y=%d \n\n", s1.state, s1.power, s1.pos.cx, s1.pos.cy);

	void add(){
		printf("\nAdding a new value in linked list!\n");
		int n;
		printf("Enter the value of new element:");
		scanf("%d", &n);
		if(root==NULL){
			root= (struct node *)malloc( sizeof(node) );
			root->data= n;
			root->next= NULL;
			list_status= root;
		}else{
			list_status->next= (struct node *)malloc( sizeof(node) );
			list_status= list_status->next;
			list_status->next= NULL;
			list_status->data= n;
		}
	}

	void re_init_last_element(){
		if(root==NULL) return;
		else{
			list_status=root;
			while(list_status->next!=NULL) list_status=list_status->next;
		}
	}

	int remove(int n){
		printf("\nRemoving an element from the list!\n");
		node * temp2= root;
		node * removed_pointer;
		if(root->data==n){
			root=root->next;
			free(temp2);
			return n;
		}else{
			while(temp2->next!=NULL){
				removed_pointer= temp2->next;
				if(removed_pointer->data==n){
					temp2->next = removed_pointer->next;
					free(removed_pointer);
					return n;
				}else{
					temp2= temp2->next;
				}
			}
		}
		printf("\nGiven element not found.\n");
		return -1;
	}

	void display(){
		printf("\nDisplaying the list!\n");
		if(root==NULL) return;
		node * temp2=root;
		while(temp2!=NULL){
			printf("%d\t", temp2->data);
			temp2= temp2->next;
		}
	}

	int ans=0;
	int x=0;
	while(1){
		printf("\nEnter joor choice! \n1. Add an element. \n2. Remove an element \n3. Display list \n4. Exit Program\n\n");
		scanf("%d",&ans);
		switch(ans){
			case 1: add();
				break;
			case 2:	printf("Enter element you want removed:");
				scanf("%d", &x);
				ans= remove(x);
				if(ans!=-1) printf("\nElement was removed.\n");
				re_init_last_element();
				break;
			case 3: display();
				break;
			case 4: return 0;
			default: printf("\nInvalid Input. Retry!\n");
		}
	}

	return 0;
}


