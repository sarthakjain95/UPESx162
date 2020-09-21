
// ######################################################################
// :ABOUT:
// This program tests the file 'matrix_ops.h' (and 'matrix_ops_efficient.h') 
// for bugs and other experimental operations.
// ######################################################################

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// #include"matrix_ops.h"
#include"matrix_ops_efficient.h"

// Constrains: NxN
void matrix_random_fill(matrix x, int size, int range){

	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			x[i][j]= rand()%range;
		}
	}
}


int main(){

	srand(42);

	int matrix_size;
	int n_range;

	if(true){

		// checking if passing 'ABA' in strassens matmul produces the 
		// correct result.
		matrix_size= 8;
		n_range= 255;
		//
		matrix a= matrix_gen(matrix_size, matrix_size);
		matrix b= matrix_gen(matrix_size, matrix_size);
		matrix_random_fill(a, matrix_size, n_range);
		matrix_random_fill(b, matrix_size, n_range);

		matrix standard_res= matrix_multiplication2D(a, b, matrix_size);
		matrix strassens_res= strassen_matrix_multiplication2D(a, b, matrix_size);

		if( matrix_equality_check(standard_res, strassens_res, matrix_size) ){
			printf("[+] 'ABA' test passed!\n");
		} else {
			display_matrix(a, matrix_size);
			display_matrix(b, matrix_size);
			printf("[-] 'ABA' test failed!\n");
			display_matrix(standard_res, matrix_size);
			printf("\n");
			display_matrix(strassens_res, matrix_size);
		}


	}




}
