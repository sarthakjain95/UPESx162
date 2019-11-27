#include <stdio.h>
#include <stdlib.h>



int main(){
	int i, j, row, col, **a, **b, **c; //a, b, c are the matrices
	printf("Enter number of rows of the matrix: ");
	scanf("%d", &row);
	printf("Enter number of columns of the matrix: ");
	scanf("%d", &col);
	
	
	a = (int**)calloc(sizeof(int), col);
	b = (int**)calloc(sizeof(int), col);
	c = (int**)calloc(sizeof(int), col);
	
	for(i = 0; i<row; i++){
		a[i] = (int*)calloc(col, sizeof(int));
	}
	
	for(i = 0; i<row; i++){
		b[i] = (int*)calloc(col, sizeof(int));
	}
	
	for(i = 0; i<row; i++){
		c[i] = (int*)calloc(col, sizeof(int));
	}
	
	printf("Enter elements of first matrix: \n");
	for(i = 0; i < row; i++){
		for(j=0; j< col; j++){
			printf("Enter element: ");
			scanf("%d", &a[i][j]);
		}
	}
	
	printf("Enter elements of second matrix: \n");
	for(i = 0; i < row; i++){
		for(j=0; j< col; j++){
			printf("Enter element: ");
			scanf("%d", &b[i][j]);
		}
	}
	
	printf("A x B is: \n");
	for(i = 0; i < row; i++){
		for(j=0; j< col; j++){
			c[i][j] = a[i][j] * b[i][j];
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
}
