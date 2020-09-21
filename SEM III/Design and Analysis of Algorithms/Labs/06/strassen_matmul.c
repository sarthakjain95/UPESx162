
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// #include"matrix_ops.h"
#include"matrix_ops_efficient.h"

// Testing constrains
#define matrix_size 4     // Size of Matrix NxN where 'N' is a power of 2
#define num_range 3141569    // Defines the range of numbers in matrix

// matrix defined as 'int**' in matrix_ops.h

// Constrains : Defined only for NxN matrix
void fill_matrix(int** x, int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			x[i][j]= rand()%num_range;
		}
	}
}

int main(){

	// Constant seed
	srand(42);

	// Constructing Matrices
	matrix a= matrix_gen(matrix_size, matrix_size);
	matrix b= matrix_gen(matrix_size, matrix_size);

	// Filling with random numbers
	fill_matrix(a, matrix_size);
	fill_matrix(b, matrix_size);
	//
	// printf("Matrix A:\n");
	// display_matrix(a, matrix_size);
	// printf("Matrix B:\n");
	// display_matrix(b, matrix_size);

	clock_t start_time, end_time;
	double time_taken;

	// Strassen Matrix Multiplication
	start_time= clock();
	matrix c= strassen_matrix_multiplication2D(a, b, matrix_size);
	end_time= clock();
	time_taken= (((double)(end_time-start_time))*10e6)/CLOCKS_PER_SEC;
	printf("Strassen's Method took %lf micro seconds.\n", time_taken);

	// Standard Matrix Multiplication
	start_time= clock();
	matrix d= matrix_multiplication2D(a, b, matrix_size);
	end_time= clock();
	time_taken= (((double)(end_time-start_time))*10e6)/CLOCKS_PER_SEC;
	printf("Standard  Method  took %lf micro seconds.\n", time_taken);

	// // Displaying Results
	// printf("Matrix C (Strassen Matrix Multiplication Result):\n");
	// display_matrix(c, matrix_size);
	// // 
	// printf("Matrix D (Standard Matrix Multiplication Result):\n");
	// display_matrix(d, matrix_size);

	// Tests to see if Both Results are Equal
	int are_equal= matrix_equality_check(c, d, matrix_size);
	if( are_equal == 1 ) printf("Both matrices are equal!\n");
	else printf("Both matrices are NOT equal!\n");

	return 0;
}

