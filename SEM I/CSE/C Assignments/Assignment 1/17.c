
#include<stdio.h>
#include<stdlib.h>

// Q. WAP to enter the string entered by the user and extract only the integer part from the string.

int main(int argc, char * argv[]){

	char * str;
	size_t size= 128;
	str= (char *)malloc( sizeof(char)*size );
	
	printf("Enter the string:");
	getline(&str, &size, stdin);

	printf("\nPrinting Numbers:\n");
	int i=0;
	char prev_print;
	while(str[i]!='\0'){
		if(str[i]<='9' && str[i]>='0') printf("%c",str[i]);
		else if(str[i-1]<='9' && str[i-1]>='0') printf(" ");
		i++;
	}
	
	printf("\n");
	return 0;
}
