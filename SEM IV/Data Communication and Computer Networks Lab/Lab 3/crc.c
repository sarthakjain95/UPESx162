
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define CHR2BIN(chr) ((chr=='1') ? 1 : 0)
#define BIN2CHR(bin) ((bin==1) ? '1' : '0')

int main(){

	const char* message = "10011101";
	const char* polynomial = "1001";
	char* temp = (char*)malloc(sizeof(char) * strlen(polynomial));
	char* redundant_bits = (char*)malloc(sizeof(char) * (strlen(polynomial) - 1));

	const size_t message_length = strlen(message);
	const size_t polynomial_length = strlen(polynomial);

	size_t i=0, j=0, k=0;

	while(i < (message_length+polynomial_length-1) ){
		// Fill up temp as much as possible
		while( (j < polynomial_length) && (i < message_length+polynomial_length-1) ){
			for(k=0; k<polynomial_length-1; k++) temp[k] = temp[k+1]; // shift
			// Append new bit to temp
			if(i >= message_length) temp[polynomial_length-1] = '0';
			else temp[polynomial_length-1] = message[i];
			j++; i++;
		}
		// If temp is full
		if(j == polynomial_length){
			// XOR temp with polynomial
			for(k=0; k<polynomial_length; k++){
				temp[k] = BIN2CHR( CHR2BIN(temp[k]) ^ CHR2BIN(polynomial[k]) );
			}
			// change j to the number of new bits that can be added
			for(j=0; j<polynomial_length; j++)
				if(temp[j] == '1') break;
			j = polynomial_length - j;
		}
	}

	printf("Message to send: %s\n", message);
	printf("Polynomial: %s\n", polynomial);
	printf("Reminder: %s\n", temp);
	// Print the final message
	printf("Encoded Message is: %s%s\n", message, temp+1 );

	free(redundant_bits);
	free(temp);
	return 0;
}
