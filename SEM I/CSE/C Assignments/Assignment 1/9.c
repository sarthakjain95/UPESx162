
#include<stdio.h>

// Q. WAP to check whether a given character is an alphabet, digit or special character.

int main(int argc, char * argv[]){

	unsigned char ch='e';
	printf("\nEnter the character to check:");
	scanf("%c",&ch);

	if(ch>='0' && ch<='9')
		printf("\nCharacter is a digit.\n");
	else if( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') )
		printf("\nCharacter is a alphabet.\n");
	else
		printf("\nSpeacial Character.\n");

	return 0;
}
