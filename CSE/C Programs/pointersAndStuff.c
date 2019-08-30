
// UPESx162
// CSE / C Basics
// pointersAndStuff
// Recommended execution on https://repl.it/languages/c

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define true 1
#define false 0

int myFunction(int x, int y){ return x * 2 + y; }

int main(int argc, char * argv[]){

	int (*fn)(int, int) = &myFunction; // Pointer to a functions
	int a=32,x=42,y=123;

	int * b = &a;  // Stores the location for 'a'
	int ** c = &b; // Store the location for the location of b.
	printf("a=%d\nLocation of a=%u\n\nValue at b=%u\nLocation of b=%u\n\nValue at c=%u\nPointer from c=%d\n",a,&a,b,&b,c,**c);
	
	printf("(*fn)(%i, %i) = %i\n", x, y, (*fn)(x, y)); /* Outputs "fn(42, 123) = 207". */
	printf("fn(%i, %i) = %i\n", x, y, fn(x, y)); /* Another form: you don't need to dereference explicitly */	

	int n=12;
	int * v = &n;
	*v += 27;
	printf("*v=%d,n=%d\n",*v,n);
	//dereferences p only once, whereas the following does so twice.
	*v = *v + 27;
	printf("*v=%d,n=%d\n",*v,n);

	   char *str;

	/* Initial memory allocation */
	str = (char *) malloc(15); // allocates requested amount of memory and returns a pointer to it.
	strcpy(str, "BlackHill");
	printf("String = %s,  Address = %u\n", str, str);
	/* Reallocating memory */
	str = (char *) realloc(str, 25); // attempts to resize the memory location previously allocated.
	strcat(str, "&SilentMountain");  // concats strings
	printf("String = %s,  Address = %u\n", str, str);
	free(str);

	// printf("Input the size of memory required:");
	// int mem=0;
	if(true){
		char *buffer;
		if ( ( buffer=malloc(39614081271975168) ) != NULL ){  
			// Bound to fail because of unrealistic requirements.
			free(buffer);
		}
		else{	// malloc returned null
			/* report allocation failure */
			printf("Memory Allocation Failed.\n");
		}
	}

	size_t k=0; // size_t is an unsigned integer type of at least 16 bit
	int arr[] = {1, 2, 3, 4, 5};
	//           0  1  2  3  4
	int *p = &arr[2]; // holds address of 3
	int *q = &arr[3]; // holds address of 4 
	unsigned int diff = q - p;
	printf("q - p = %ti\n", diff); /* Outputs "1". */
	printf("*(p + (q - p)) = %d\n", *(p + diff)); /* Outputs "4". */
   
	double* A = malloc(n*sizeof *A);
	if (A==NULL) {
		perror("allocation problems");
		exit(EXIT_FAILURE);
	}
	// Here the pointer A is evaluated and if it is a null pointer, an error is detected and the program exits.

	// char *foo = "hello";
	// foo[0] = 'y'; /* Undefined behavior - BAD! */

	char *foo_p = "hello";
	foo_p = "World!"; /* OK - we're just changing what foo points to */
	char foo[] = "hello";
	foo[0] = 'y'; /* OK! */

	char modifiable_string[] = "hello world";
	// This is equivalent to the following:
	// char modifiable_string[] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '\0'};

	// array of character pointers 
	char * string_array[] = {
		"foo",
		"bar",
		"baz"
	};

	printf("%s\n",string_array[2]);

	return 0;
}

// https://github.com/sarthakjain95
// Sarthak Jain
