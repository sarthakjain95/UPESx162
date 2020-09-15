
#include<stdio.h>
#include<stdlib.h>

#define matrix_size 2
#define num_range 10

void matmul(int** x, int** y, int**z, int size){

	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			for(int k=0; k<size; k++){
				z[i][j]+= x[i][k] * y[k][j];
			}
		}
	}

}

void strassen_matmul(int** x, int** y, int** z, int size){

	int a= x[0][0];
	int b= x[0][1];
	int c= x[1][0];
	int d= x[1][1];
	int e= y[0][0];
	int f= y[0][1];
	int g= y[1][0];
	int h= y[1][1];

	int p1= a*(f-h);
	int p2= (a+b)*h;
	int p3= (c+d)*e;
	int p4= d*(g-e);
	int p5= (a+d)*(e+h); 
	int p6= (b-d)*(g-h);
	int p7= (a-c)*(e+f);

	z[0][0]= p5 + p4 - p2 + p6;
	z[0][1]= p1 + p2;
	z[1][0]= p3 + p4;
	z[1][1]= p1 + p5 - p3 - p7;

}

void fill_matrix(int** a, int size){

	for(int y=0; y<size; y++){
		for(int x=0; x<size; x++){
			a[y][x]= rand()%num_range;
		}
	}

}

void display_matrix(int** a, int size){

	for(int y=0; y<size; y++){
		for(int x=0; x<size; x++){
			printf("%d ", a[y][x]);
		}
		printf("\n");
	}

}

int main(){

	srand(42);

	// Constructing Matrices
	int** a= (int**)calloc(matrix_size, sizeof(int**));
	int** b= (int**)calloc(matrix_size, sizeof(int**));
	int** c= (int**)calloc(matrix_size, sizeof(int**));
	//
	for(int i=0; i<matrix_size; i++) a[i]= (int*)calloc(matrix_size, sizeof(int*));
	for(int i=0; i<matrix_size; i++) b[i]= (int*)calloc(matrix_size, sizeof(int*));
	for(int i=0; i<matrix_size; i++) c[i]= (int*)calloc(matrix_size, sizeof(int*));

	// Filling with random numbers
	fill_matrix(a, matrix_size);
	fill_matrix(b, matrix_size);
	//
	printf("Matrix A:\n");
	display_matrix(a, matrix_size);
	printf("Matrix B:\n");
	display_matrix(b, matrix_size);

	// Matrix Multiplication
	strassen_matmul(a, b, c, matrix_size);
	// matmul(a, b, c, matrix_size);
	//
	printf("Matrix C (Result Matrix):\n");
	display_matrix(c, matrix_size);

}

