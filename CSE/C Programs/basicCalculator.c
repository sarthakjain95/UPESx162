
// UPESx162
// CSE / C Basics
// basicCalculator
// Recommended execution on https://repl.it/languages/c

#include <stdio.h>

double divideThese( double a, double b ){ return a/b; }
double getProduct( double fn, double sn ){ return fn*sn; }
double addThese( double a, double b ){ return a+b; }
double subtractThese( double a, double b ){ return a-b; }

int main(){

	double fnum, secnum, temp;
	char ch='+';
	int flag=1;

	while(1){
		flag=1;
		printf("\nEnter the two numbers: ");
		scanf("%lf %lf", &fnum, &secnum);  

		getchar();
		printf("\nEnter Operation on these Numbers:");
		ch = getchar();

		switch(ch){
			case '+':temp = addThese(fnum,secnum); break;
			case '-':temp = subtractThese(fnum,secnum); break;
			case '*':temp = getProduct(fnum,secnum); break;
			case '/':temp = divideThese(fnum,secnum); break;
			default: temp=0; printf("\nInvalid Operation. Try Again."); flag=0;
		}
		
		flag && printf("\n%lf %c %lf = %lf", fnum, ch, secnum, temp);

		getchar();
		printf("\n\nDo you want to use again? (Y/n):");
		ch = getchar();
		if(ch!='Y'){ break; }
	}

	return 0;
} 

// https://github.com/sarthakjain95
// Sarthak Jain