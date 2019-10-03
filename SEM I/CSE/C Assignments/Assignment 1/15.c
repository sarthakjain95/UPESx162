
#include<stdio.h>
#include<stdlib.h>

// Q. WAP to convert uppercase string to lowercase using for loop.

int main(int argc, char * argv[]){

	size_t size= 128;
	char * str;
	str= (char *)malloc( sizeof(char) * size );
	printf("Enter the string: ");
	getline(&str, &size, stdin);

	int i= 0; 
	while(str[i]!='\0'){
		if(str[i]>='A' && str[i]<='Z')
			str[i]+= 32;
		i++;
	}

	printf("\nFinal String:\n%s\n", str);

	return 0;
}
