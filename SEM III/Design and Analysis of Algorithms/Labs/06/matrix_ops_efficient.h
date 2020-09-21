/*
##################################################################
	:NOTE:
	Functions are defined strictly for 'int' type NxN dimensional 
	matrices.

	:FORMULAS:
	P1= A * ( F – H )
	P2= H * ( A + B )
	P3= E * ( C + D )
	P4= D
	P5= ( A + D ) * ( E + H )
	P6= ( B – D ) * ( G + H)
	P7= ( A – C ) * ( E + F)
	C1 = P4 + P5 + P6 – P2
	C2 = P1 + P2
	C3 = P3 + P4
	C4 = P1 – P3 + P5 – P7
##################################################################*/

#include<stdlib.h>
#define invalid_size_error 0x1
typedef int** matrix; // Defining int** as matrix

matrix matrix_gen(int xs, int ys){

	matrix x = (matrix)malloc(ys*sizeof(int*));
	for(int i=0; i<ys; i++) x[i]= (int*)malloc(xs*sizeof(int));
	//
	return x;
}

void display_matrix(matrix x, int size){

	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			printf("%6d ", x[i][j]);
		}
		printf("\n");
	}

}

void raise_exception(int error_code){

	switch(error_code){
		case 0x1: printf("Error(%x): Invalid size encountered!\n", error_code); break;
		default: printf("Error(%x): Unknown\n", error_code);
	}
	// Terminates the program
	exit(-1);
}

matrix matrix_multiplication2D(matrix a, matrix b, int size){
	
	matrix res= matrix_gen(size, size);
	//
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			res[i][j]= 0;
			for(int k=0; k<size; k++){
				res[i][j]+= a[i][k]*b[k][j];
			}
		}
	}

	return res;
}

int matrix_equality_check(matrix a, matrix b, int size){

	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(a[i][j]!=b[i][j]) return 0;
		}
	}

	return 1;
}

// from,to inteface
void matrix_copy(
	matrix x, 
	matrix y, 
	int xy, 
	int xx, 
	int yy, 
	int yx, 
	int size){

	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			y[i+yy][j+yx]= x[i+xy][j+xx]; 
		}
	}

}

void matrix_subtraction2D(
	matrix x, 
	matrix y, 
	matrix result, 
	int xys,
	int xxs,
	int yys,
	int yxs,
	int ry,
	int rx,
	int size){

	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			result[i+ry][j+rx]= x[i+xys][j+xxs] - y[i+yys][j+yxs];
		}
	}

}

void matrix_addition2D(
	matrix x, 
	matrix y, 
	matrix result, 
	int xys,
	int xxs,
	int yys,
	int yxs,
	int ry,
	int rx,
	int size){

	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			result[i+ry][j+rx]= x[i+xys][j+xxs] + y[i+yys][j+yxs];
		}
	}

}

void apply_strassen(
	matrix x, 
	matrix y, 
	matrix result, 
	int xx,
	int xy,
	int yx,
	int yy, 
	int rx, 
	int ry,
	int size){

	// Sanity check
	if( size&(size-1) != 0 ) raise_exception(invalid_size_error);

	if( size == 2 ){

		int p1, p2, p3, p4, p5, p6, p7;
		//
		p1=  x[xy+0][xx+0] * (y[yy+0][yx+1] - y[yy+1][yx+1]);
		p2=  y[yy+1][yx+1] * (x[xy+0][xx+0] + x[xy+0][xx+1]);
		p3=  y[yy+0][yx+0] * (x[xy+1][xx+0] + x[xy+1][xx+1]);
		p4=  x[xy+1][xx+1] * (y[yy+1][yx+0] - y[yy+0][yx+0]);
		p5= (x[xy+0][xx+0] + x[xy+1][xx+1]) * (y[yy+0][yx+0]+y[yy+1][yx+1]);
		p6= (x[xy+0][xx+1] - x[xy+1][xx+1]) * (y[yy+1][yx+0]+y[yy+1][yx+1]);
		p7= (x[xy+0][xx+0] - x[xy+1][xx+0]) * (y[yy+0][yx+0]+y[yy+0][yx+1]);

		result[ry][rx]= p4 + p5 + p6 - p2;
		result[ry][rx+1]= p1 + p2;
		result[ry+1][rx]= p3 + p4;
		result[ry+1][rx+1]= p1 - p3 + p5 - p7;

	} else {

		int hs= size/2; // half size

		matrix temp = matrix_gen(hs, hs);
		matrix temp2= matrix_gen(hs, hs);
		matrix temp3= matrix_gen(hs, hs);

		// First Quadrant
		// C1 = D*(G-E) + (A+D)*(E+H) + (B-D)*(G+H) - (A+B) * H
		matrix_subtraction2D(y, y, temp, hs+yy,0+yx, 0+yy,0+yx, 0,0, hs);
		apply_strassen(x, temp, temp2, hs+xy,hs+xx, 0,0, 0,0, hs);
		matrix_copy(temp2, result, 0,0, 0+ry,0+rx, hs);
		matrix_addition2D(x, x, temp, 0+xy,0+xx, hs+xy,hs+xx, 0,0, hs);
		matrix_addition2D(y, y, temp2, 0+yy,0+yx, hs+yy,hs+yx, 0,0, hs);
		apply_strassen(temp, temp2, temp3, 0,0, 0,0, 0,0, hs);
		matrix_addition2D(result, temp3, result, 0+ry,0+rx, 0,0, 0+ry,0+rx, hs);
		matrix_subtraction2D(x, x, temp, 0+xy,hs+xx, hs+xy,hs+xx, 0,0, hs);
		matrix_addition2D(y, y, temp2, hs+yy,0+yx, hs+yy,hs+yx, 0,0, hs);
		apply_strassen(temp, temp2, temp3, 0,0, 0,0, 0,0, hs);
		matrix_addition2D(result, temp3, result, 0+ry,0+rx, 0,0, 0+ry,0+rx, hs);
		matrix_addition2D(x, x, temp, 0+xy,0+xx, 0+xy,hs+xx, 0,0, hs);
		apply_strassen(temp, y, temp2, 0,0, hs+yy,hs+yx, 0,0, hs);
		matrix_subtraction2D(result, temp2, result, 0+ry,0+rx, 0,0, 0+ry,0+rx, hs);

		// Second Quadrant
		// C2 = A * (F-H) + (A+B)*H
		matrix_subtraction2D(y, y, temp, 0+yy,hs+yx, hs+yy,hs+yx, 0,0, hs);
		apply_strassen(x, temp, temp2, 0+xy,0+xx, 0,0, 0,0, hs);
		matrix_copy(temp2, result, 0,0, 0+ry,hs+rx, hs);
		matrix_addition2D(x, x, temp, 0+xy,0+xx, 0+xy,hs+xx, 0,0, hs);
		apply_strassen(temp, y, temp2, 0,0, hs+yy,hs+yx, 0,0, hs);
		matrix_addition2D(result, temp2, result, 0+ry,hs+rx, 0,0, 0+ry,hs+rx, hs);

		// Third Quadrant
		// C3 = (C + D)*E + D*(G-E)
		matrix_addition2D(x, x, temp, hs+xy,0+xx, hs+xy,hs+xx, 0,0, hs);
		apply_strassen(temp, y, temp2, 0,0, 0+yy,0+yx, 0,0, hs);
		matrix_copy(temp2, result, 0,0, hs+ry,0+rx, hs);
		matrix_subtraction2D(y, y, temp, hs+yy,0+yx, 0+yy,0+yx, 0,0, hs);
		apply_strassen(x, temp, temp2, hs+xy,hs+xx, 0,0, 0,0, hs);
		matrix_addition2D(result, temp2, result, hs+ry,0+rx, 0,0, hs+ry,0+rx, hs);

		// Fourth Quadrant
		// C4 = A * (F-H) - (C+D)*E + (A+D)*(E+H) - (A-C)*(E+F)
		matrix_subtraction2D(y, y, temp, 0+yy,hs+yx, hs+yy,hs+yx, 0,0, hs);
		apply_strassen(x, temp, temp2, 0+xy,0+xx, 0,0, 0,0, hs);
		matrix_copy(temp2, result, 0,0, hs+ry,hs+rx, hs);
		matrix_addition2D(x, x, temp, hs+xy,0+xx, hs+xy,hs+xx, 0,0, hs);
		apply_strassen(temp, y, temp2, 0,0, 0+yy,0+yx, 0,0, hs);
		matrix_subtraction2D(result, temp2, result, hs+ry,hs+rx, 0,0, hs+ry,hs+rx, hs);
		matrix_addition2D(x, x, temp, 0+xy,0+xx, hs+xy,hs+xx, 0,0, hs);
		matrix_addition2D(y, y, temp2, 0+yy,0+yx, hs+yy,hs+yx, 0,0, hs);
		apply_strassen(temp, temp2, temp3, 0,0, 0,0, 0,0, hs);
		matrix_addition2D(result, temp3, result, hs+ry,hs+rx, 0,0, hs+ry,hs+rx, hs);
		matrix_subtraction2D(x, x, temp, 0+xy,0+xx, hs+xy,0+xx, 0,0, hs);
		matrix_addition2D(y, y, temp2, 0+yy,0+yx, 0+yy,hs+yx, 0,0, hs);
		apply_strassen(temp, temp2, temp3, 0,0, 0,0, 0,0, hs);
		matrix_subtraction2D(result, temp3, result, hs+ry,hs+rx, 0,0, hs+ry,hs+rx, hs);		
	
	}

}

matrix strassen_matrix_multiplication2D(matrix x, matrix y, int size){

	matrix result= matrix_gen(size, size);
	apply_strassen(x, y, result, 0,0, 0,0, 0,0, size);
	//
	return result;
}
