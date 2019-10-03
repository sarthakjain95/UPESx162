
// https://stackoverflow.com/questions/2575048/arrow-operator-usage-in-c

#include<stdio.h>
#include<stdlib.h>

struct node{
	int n;
	char c;
	long n_2;
	// double d2;
};


int main(int argc, char * argv[]){

	unsigned long other_n; // Pointers actually have unsigned long data type.

	struct node point;
	struct node * ptr;
	int * ptr_2;

	// printf("pointer=%d\nstructure=%d\nint pointer size = %d\n", sizeof(ptr), sizeof(point), sizeof(ptr_2) );
	printf("Enter a number, a character and another number:");
	scanf( "%d %c %lu", &point.n, &point.c, &point.n_2 );

	printf("Entered values:");

	printf( "\nn=%d c=%c n_2=%lu\n", point.n, point.c, point.n_2);

	// using pointer

	ptr = &point;

	printf("p.n= %d\np.c= %p\n", ptr->n, &ptr->n);

	// foo->bar is equivalent to (*foo).bar, i.e. it gets the member called bar from 
	// the struct that foo points to.

	struct foo{
		int x;     // 5
		float y;
	};

	struct foo var;
	struct foo* pvar;
	// (struct foo *) is not really required since malloc returns void * that will be
	// type casted to any other data type
	// pvar = (struct foo *)malloc(sizeof(struct foo));
	pvar= malloc(sizeof(struct foo));

	var.x = 5;   // var.x is 5
	(&var)->y = 14.3;  // Equivalent to (*(&var)).y or var.y	
	pvar->y = 22.4;
	(*pvar).x = 6;   // (*pvar).x is 5
	printf("var.x=%d, var.y=%f, pvar=%p, pvar->y=%f\n", var.x, var.y, pvar, pvar->y);

	typedef struct node_2{
		unsigned long sapid;
		char name[32];
	} node_2;

	node_2 students[48];
	while((getchar())!='\n');

	printf("\nEnter Student's SAP ID (9 characters):");
	scanf("%lu",&students[1].sapid);
	printf("Enter Student's name (max. 32 characters):");
	while(getchar()!='\n');
	fgets( students[1].name , 32, stdin);
	printf("Student Name:%sStudent SAPID:%lu\n\n", students[1].name, students[1].sapid);

	return 0;
}