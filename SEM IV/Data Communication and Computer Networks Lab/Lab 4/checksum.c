
// NOTE:
// This implementation is specifically for 4 bit check sums. 
// I know that the standard is 16 bits, but this is just a (badly designed) demo.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CHECKSUM_SIZE 4
typedef unsigned char byte;

byte get_checksum(const byte* message, const size_t size){

	byte checksum = 0;
	for(size_t i=0; i<size; i++){
		checksum += message[i];
		while(checksum > 0b1111){
			checksum = (checksum & 0b00001111) + (checksum >> 4);
		}
	}

	checksum = ~checksum;
	checksum = (checksum & 0b00001111);

	return checksum;
}

void print_message(const byte* message, const size_t size){
	
	for(size_t i=0; i<size; i++){
		for(size_t j=0; j<8; j++){
			if((message[i]>>(7-j))&0x1) printf("1");
			else printf("0");
		}
		printf(" ");
	}
	
	printf("\n");
}

int main(){

	const char* raw_message = "01010101011111101010100111011101";
	// Check validity of n
	if(strlen(raw_message)%CHECKSUM_SIZE != 0) return -1;

	const size_t n_quads = strlen(raw_message) / CHECKSUM_SIZE;
	const size_t n_bytes = n_quads / 2;

	byte* message = (byte*)malloc(sizeof(byte) * n_bytes);

	// Convert byte string to bits
	for(size_t i=0; i<n_bytes; i++){
		for(size_t j=0; j<8; j++){
			message[i] += (raw_message[i*8 + j] == '1') ? 1 << (7-j) : 0;
		}
	}
	//
	printf("Input Message: ");
	print_message(message, n_bytes);
	
	byte checksum = get_checksum(message, n_bytes);

	byte* message_with_checksum = (byte*)malloc(n_bytes + 1);
	for(size_t i=0; i<n_bytes; i++)
		message_with_checksum[i] = message[i];

	message_with_checksum[n_bytes] = checksum;
	printf("Final Message: ");
	print_message(message_with_checksum, n_bytes+1);
	printf("Message Checksum: %u\n", checksum);

	free(message);
	free(message_with_checksum);
	return 0;
}
