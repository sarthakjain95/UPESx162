
#include<stdio.h>
#include<stdlib.h>

int main(){

	int c=0;
	// Loop won't end until you press Ctrl+c
	// also treats and prints the 'new line' character
	while( (c=getchar()) != EOF ) printf("%c",c);

	return 0;
}
