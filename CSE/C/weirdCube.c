// UPESx162
// CSE / C Basics
// weirdCube
// Recommended execution on https://repl.it/languages/c

#include<stdio.h>
#include<stdlib.h>

// Tested on GCC
// Debian GNU/Linux 9 (stretch) 64-bit 

#define DEFAULT_SIZE 4

void printRow(int n){
	for(int x=0;x<(n*2-1);x++) printf("%d ",n);
}

int main(int argc, char * argv[]){

	system("clear");

	int cube_size = DEFAULT_SIZE;
	
	printf("Enter Cube Size:");
	scanf("%d",&cube_size);
	printf("\n\n");

	if(cube_size<0 || cube_size>9) return 1;

	// // Make Cube

	// Double Loop Variant
	// // Upper Portion
	// for(int i=cube_size; i>0 ;i--){
	// 	for(int y=cube_size; y>i; y--) printf("%d ",y);
	// 	printRow(i);
	// 	for(int y=i+1; y<=cube_size;y++) printf("%d ",y);
	// 	printf("\n");
	// }
	// // Lower Portion
	// for(int i=2; i<=cube_size; i++){
	// 	for(int y=cube_size; y>i; y--) printf("%d ",y);
	// 	printRow(i);
	// 	for(int y=i+1; y<=cube_size;y++) printf("%d ",y);
	// 	printf("\n");
	// }

	// Single Loop Variant	
	int temp;
	for(int i=cube_size; i>=(-1*cube_size); i--){
		if(i==0 || i==1) continue;
		temp=i;
		if(temp<0) temp*=-1;
		for(int y=cube_size; y>temp; y--) printf("%d ",y);
		printRow(temp);
		for(int y=temp+1; y<=cube_size;y++) printf("%d ",y);
		printf("\n");
	}

	printf("\n\n\n");
	system("read -p \'Press Enter to continue...\' var");

	return 0;
}

// https://github.com/sarthakjain95
// Sarthak Jain