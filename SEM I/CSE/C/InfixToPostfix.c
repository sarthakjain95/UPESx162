#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char item){
	if(top >= SIZE){
		printf("Stack Overflow.\n");
	}
	else{
		top = top + 1;
		stack[top] = item;
	}
}

char pop(){
	char item;
	if(top < 0){
		printf("Stack Underflow.\n");
	}	
	else{
		item = stack[top];
		top = top -1;
		return item;
	}
}

int is_operator(char symbol){
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

int precedence(char symbol)
{
	if(symbol == '^')/* exponent operator, highest precedence*/
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          /* lowest precedence */
	{
		return(1);
	}
	else
	{
		return(0);
	}
}


void InfixtoPostfix(char infix[], char postfix[]){
	int i, j;
	char item;
	char x;
	
	push('(');
	strcat(infix, ")");
	
	i = 0;
	j = 0;
	item = infix[i];
	
	while(item != '\0'){
		if(item == '('){
			push(item);
		}
		else if(isdigit(item) || isalpha(item)){
			postfix[j] = item;
			j++;
		}
		else if(is_operator(item) == 1){
			x = pop();
			while(is_operator(x) == 1 && precedence(x) >= precedence(item))
			{
				postfix[j] = x;
				j++;
				x = pop();
			}
			
			push(x);
			push(item);
		}
		
		else if(item == ')'){
			x = pop();
			while(x != '('){
				postfix[j] = x;
				j++;
				x = pop();
			}
		}
		else{
			printf("Invalid Expression.\n");
		}
		
		i++;
		item = infix[i];
	}
		
	if(top > 0){
		printf("\nInvalid Expression.\n");
	}
	
	postfix[j] = '\0';
}

int main(){
	char infix[SIZE], postfix[SIZE];
	printf("Enter infix expression: ");
	scanf("%s", infix);
	
	InfixtoPostfix(infix, postfix);
	printf("Postfix Expression: %s", postfix);
	return 0;
}
