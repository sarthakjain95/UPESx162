#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0

#define space ' '

int main(int argc, char * argv[]){


	// Find out largest and smallest number in an array
	size_t size=8;
	int arr[size];
	printf("Enter %ld elements for the array\n",size);
	for(int i=0;i<size;i++)
		scanf("%d", (arr+i) );

	int biggest=0,smallest=0;
	for(int i=0;i<size;i++)
		if(arr[i]>arr[biggest]) biggest=i;
		else if(arr[i]<arr[smallest]) smallest=i;

	printf("\nPrinting array:\n");
	for(int i=0;i<size;i++) printf("%d ", arr[i]);

	printf("\n\nThe biggest and the largest numbers are at indexes %d and %d respectively.\n",biggest,smallest);


	// Find out wheather the entered string is palindrome or not
	char * input;
	size_t input_size= 128;
	input= (char *)malloc( sizeof(char)*input_size );
	while((getchar())!='\n');
	printf("\nEnter the string to check for palindrome: ");
	getline(&input, &input_size, stdin);

	size_t input_length= 0;
	while(input[input_length]!='\0') input_length++;
	input_length-=1;

	int isPalindrome= true;
	for(int i=0,j=input_length-1; i<input_length/2 ; i++,j--){
		printf("\n%c and %c", input[i], input[j]);
		if(input[i]!=input[j]){
			isPalindrome= false;
			break;
		}
	}

	if(isPalindrome) printf("\nThe entered string is a palindrome!\n");
	else printf("\nThe entered string is not a palindrome\n");


	// Find the number of words in a string
	//while((getchar())!='\n');
	printf("\nEnter the string to check for words: ");
	size_t word_counter= 0;
	getline(&input, &input_size, stdin);

	input_length=0;
	while(input[input_length]!='\0') input_length++;
	input_length--;

	for(int i=0;i<input_length;i++)
		if(input[i]==space && input[i-1]!=space)
			word_counter++;

	printf("\nThe number of words found in the given string : %ld\n", word_counter+1);
	//printf("size of size_t : %ld", sizeof(size_t));

	printf("\n");
	return 0;
}
