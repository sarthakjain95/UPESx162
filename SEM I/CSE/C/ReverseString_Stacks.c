// Reverse a string using stacks

#include <stdio.h>
#include <string.h>

char stack[50];
int top = -1;

void push(char c){
	top = top + 1;
	stack[top] = c;
}

void pop(){
	char c;
	c = stack[top];
	top = top - 1;
	printf("%c" ,c);
}

int main(){
	char str[50];
	int i, len;
	
	printf("Enter string: ");
	scanf("%s", str);
	
	len = strlen(str);
	
	for(i = 0; i < len; i++){
		push(str[i]);
	}
	
	printf("Reversed string is: ");
	for(i = 0; i < len; i++){
		pop();
	}
	
	return 0;
}	
