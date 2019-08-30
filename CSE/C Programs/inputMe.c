
// UPESx162
// CSE / C Basics
// inputMe
// Recommended execution on https://repl.it/languages/c

#include<stdio.h>
#include<stdlib.h>

// #define true 1
// #define false 0

#define SIZE 56

typedef enum { false, true } bool;
//                  0      1

int main(int argc, char * argv[]){
	char name[SIZE];
	// fgets reads upto one less than the SIZE argument
	printf("Input your name:");
	char * n = fgets(name, SIZE, stdin); // returns the location of name.
	printf("\nName:%s\n%u=%u\n", name, n, &name);
	printf("%f\n", (double)4/5);
	char state[SIZE];
	printf("Enter your state:(everything upto a is stored):");
	// scanf("%[^\n]s", &state); // inputs until \n. REGEX?
	int s = scanf("%[^a]s", &state); // stores everything upto 'a' in the string.	
	printf("State:%s , %d\n",state,s);

	char c[1000];
	FILE *fp;
	fp=fopen("tmp/txt.txt","r");
	if(fp==NULL) printf("Didn't work\n");
    	while (fgets(c,1000, fp)!=NULL) printf("%s",c);
	fclose(fp);
	printf("\n");
	
	return 0;
}

// https://github.com/sarthakjain95
// Sarthak Jain
