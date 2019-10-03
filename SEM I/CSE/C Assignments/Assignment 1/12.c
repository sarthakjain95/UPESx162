
#include<stdio.h>

// Q. WAP to generate all the Armstrong numbers between 1 and n, where n is a value supplied by the user?

int isArmstrong(int num){

	int temp=0, sum=0, n=num;
	
	while(num!=0){
		temp= num%10;
		sum += temp*temp*temp;
		num/=10;
	}
	
	if(sum==n) return 1;
	else return 0;
}

int main(int argc, char * argv[]){
	
	unsigned n= 0;
	printf("Enter the number for Armstrong Number: ");
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
		if(isArmstrong(i))
			printf("%d\n",i);

	return 0;
}
