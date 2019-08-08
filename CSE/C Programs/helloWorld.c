
// UPESx162
// CSE / C Basics
// helloWorld
// Recommended execution on https://repl.it/languages/c

#include<stdio.h>

#define SayHi printf("\nHello random person!"); 

int main(void) {
	
	printf("Hello World!!\n");  // Hello World!!

	// Well, only printing Hello World would be quite boaring.	
	// Let's step it up a notch.
	// Here are some other C console print examples;
	// SayHi;

	float foo = 324.4234343;
	char ch= 'X';
	int ti = 469;

	printf("\n%0.4f",foo+0.32432);	// 324.7478
	printf("\n%.f",foo);	// 324
	// printf('%c-kid, Uno ,Greenday','X');
	printf("%d",30>20);	//1 [ 30>20 returns true( which in decimal is 1 ) ] 
	
	int watdis = printf("\nabc, \n%c-kid and \n%fth digit kills this.",ch,foo);
	printf("\n\nprintf returns the length of the string you print. It is %d in previous case.",watdis);


	printf("Enter Y to continue with program and print all character with ASCII codes from 0-256.");
	ch=getchar();
	
	if(ch=='Y'){
		printf("You said %ces\n",ch);		
		for(int i=0;i<256;i++) printf("\'%c\' \t",i);
	}

	return 0;
}

// https://github.com/sarthakjain95
// Sarthak Jain