
// Practical 1
// Title: Classes and Objects
// Objective: To understand the concept of classes and objects, data hiding and encapsulation

// Convert Decimal number into a Binary Number using 1D array.

#include<iostream>
#include<cstdio>
#include<cstdlib>


int main(){

	int n;
	printf("\nEnter Number:");
	std::cin>>n;

	int size= sizeof(int)*8;
	bool bin[ size ];

	for(int x=0; x<size; x++) bin[x]= false;

	int pos=0;
	while(n!=0){
		if( n&0x1 ) bin[pos]= true;
		else bin[pos]= false;
		n>>=1;
		pos++;
	}
	pos--;

	printf("\nBinary Equivalent:");
	while(pos>=0){
		if(bin[pos]) printf("1");
		else printf("0");
		pos--;
	}

	printf("\n");
	return 0;
}
