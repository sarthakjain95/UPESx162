
#include<stdio.h>

// Q. WAP to reverse the digits of the number using do-while loop.

int main(int argc, char * argv[]){
	
	unsigned int n= 0, reversed= 0;
	printf("\nEnter a Number:");
	scanf("%d", &n);

	int temp=n, power=1;
	while(temp!=0){
		power*=10;
		temp/=10;
	}
	
	do{
		temp= n%10;
		power/= 10;
		reversed+= temp*power;
		n/= 10;
	}while(n!=0);

	n= reversed;
	printf("Reversed Number is:%d\n",n);

	return 0;
}
