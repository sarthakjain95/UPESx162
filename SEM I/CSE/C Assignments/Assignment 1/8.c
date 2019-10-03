
#include<stdio.h>

// Q. WAP to check whether a given year is leap year or not.

int main(int argc, char * argv[]){
	
	int year=2000;
	printf("\nEnter the year:");
	scanf("%d",&year);

	int is= 0;
	if(year%400 == 0) is=1;
	else if(year%100 == 0) is=0;
	else if(year%4 == 0) is=1;
	else is=0;

	if(is) printf("\nIt is a Leap Year\n"); 
	else printf("\nIt is not a Leap Year.\n");
	
	return 0;
}
