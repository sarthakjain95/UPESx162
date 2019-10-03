
#include<stdio.h>

// Q. WAP to check if a given character is a vowel or consonant using Switch-Case statement.

int main(int argc, char * argv[]){

	unsigned char ch='a';
	printf("\nEnter a character:\n");
	scanf("%c",&ch);

	switch(ch){
		case 'a':printf("It is a vowel\n"); break;
		case 'e':printf("It is a vowel\n"); break;
		case 'i':printf("It is a vowel\n"); break;
		case 'o':printf("It is a vowel\n"); break;
		case 'u':printf("It is a vowel\n"); break;
		default: printf("It is a consonant\n");
	}

	return 0;
}
