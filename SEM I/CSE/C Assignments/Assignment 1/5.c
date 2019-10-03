
#include<stdio.h>

// Q. Explain  break, continue, goto with the help of example.

int main(int argc, char * argv[]){

	int n= 32;
	printf("\nEnter a Number:");
	scanf("%d",&n);

	printf("Break Example (breaks at n-1)");
	for(int i=0;i<n+32;i++)
		if(i==n) break;
		else printf("\n%d",i);

	printf("\nContinue Example\n");
	for(int i=0;i<n+32;i++)
		if(i%2==0) continue;
		else printf("%d\t",i);
	
	printf("\nGoto Example\n");
	int i=0;
	start:while(1){
		i++;
		for(printf("Starting for loop!\n"); i<8 ;i++)
			if(i%2!=0)
				goto start;
		break;
	}

	return 0;
}
