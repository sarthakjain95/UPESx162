
// UPESx162
// CSE / C Basics
// notSoBasic.c
// Recommended execution on https://repl.it/languages/c

#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>
#include<string.h>

#define pi 3.1415

#define TRUE 1
#define FALSE 0

/* 48 = 0011 0000 */
#ifdef __linux__
	char * os="linux";
#else
	char * os="(notLinux)";
#endif

void _startup_(void) __attribute__((constructor));
void _cleanup_(void) __attribute__((destructor)); 

void _startup_(void){}

typedef struct something{
	char * data;
	struct something * otherthing;
} onething;

int main(int argc, char * argv[]) {
	printf("\nRunning as %s On %s\n\n", getenv("USER"), os );
	// getenv("PWD")
	// CONVERT THESE TO CONDITION AND CHECKING..
	int fn(void), *ptr, (*fp)(int), arr[10][20], num;
	/* commonly used types include */
	uint32_t u32 = 32; /* exactly 32-bits wide */
	uint8_t u8 = 255; /* exactly 8-bits wide */
	int64_t i64 = -65; /* exactly 64 bit in two's complement representation */	
	int d = 42; /* decimal constant (base10) */
	int o = 052; /* octal constant (base8) */
	int x = 0xaf; /* variables are initialized to the same value: */
	int X = 0XAf; /* (letters 'a' through 'f' (case insensitive) represent 10 through 15) */

	// LONG_MIN long int -2147483647 / -(2^31 - 1)
	// LONG_MAX long int +2147483647 / 2^31 - 1
	// ULONG_MAX unsigned long int 4294967295 / 2^Version ≥ C99

	// LLONG_MAX long long int +9223372036854775807 / 263 - 1
	// ULLONG_MAX unsigned long long int 18446744073709551615 / 264 - 132 - 1

	/* wide character string literal, of type wchar_t[] */
	wchar_t* s2 = L"abc";
	// Version ≥ C11
	/* UTF-8 string literal, of type char[] */
	// char* s3 = u8"abc";
	/* 16-bit wide string literal, of type char16_t[] */
	// char16_t* s4 = u"abc";
	/* 32-bit wide string literal, of type char32_t[] */
	// char32_t* s5 = U"abc";

	// BitWise BIT
	// ^ bitwise exclusive OR (XOR)
	// ~ bitwise not (one's complement)
	
	unsigned int a = 29;/* 29 = 0001 1101 */
	unsigned int b = 48;/* 48 = 0011 0000 */
	int c = 0;
	c = a & b; /* 32 = 0001 0000 */
	printf("%d & %d = %d\n", a, b, c );
	c = a | b; /* 61 = 0011 1101 */
	printf("%d | %d = %d\n", a, b, c );
	c = a ^ b; /* 45 = 0010 1101 */
	printf("%d ^ %d = %d\n", a, b, c );
	c = ~a; /* -30 = 1110 0010 */
	printf("~%d = %d\n", a, c );
	c = a << 2; /* 116 = 0111 0100 */
	printf("%d << 2 = %d\n", a, c );
	c = a >> 2; /* 7 = 0000 0111 */
	printf("%d >> 2 = %d\n", a, c );

	// if( argc>1 )
		// for(int i=1;i<argc;i++)
			// printf("%s\n",argv[i]);

	printf("\nBTW. Address of a is %x\n\n",&a);
	
	return 0;
}

// https://github.com/sarthakjain95
// Sarthak Jain