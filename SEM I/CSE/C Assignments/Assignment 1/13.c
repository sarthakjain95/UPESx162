
#include<stdio.h>

// Q. WAP to generate the first ‘n’ terms of a Fibonacci sequence.

int main(int argc, char * argv[]){
	
	unsigned int n= 0, prev=0, cur=1, i=2, temp=0;
	printf("Enter number for Fibonacci Series:");
	scanf("%d",&n);

	printf("%d\n%d\n",prev,cur);
	while(i<n){
		temp= cur;
		cur= prev+cur;
		prev= temp;
		printf("%d\n",cur);
		i++;
	}

	return 0;
}
