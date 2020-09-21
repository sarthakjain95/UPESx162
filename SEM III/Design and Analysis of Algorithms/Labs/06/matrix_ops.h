
// ##################################################################
// :NOTE:
// Functions are defined strictly for 'int' type NxN dimensional 
// matrices.
// ##################################################################

#include<stdlib.h>
typedef int** matrix; // defining int** as matrix

void display_matrix(matrix x, int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			printf("%4d ", x[i][j]);
		}
		printf("\n");
	}
}

matrix matrix_gen(int xs, int ys){
	matrix x = (matrix)malloc(ys*sizeof(int*));
	for(int i=0; i<ys; i++) x[i]= (int*)malloc(xs*sizeof(int));
	//
	return x;
}

matrix matrix_subtraction2D(matrix x, matrix y, int size){

	matrix result= matrix_gen(size, size);

	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			result[i][j]= x[i][j] - y[i][j];
		}
	}

	return result;
}

matrix matrix_addition2D(matrix x, matrix y, int size){

	matrix result= matrix_gen(size, size);

	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			result[i][j]= x[i][j] + y[i][j];
		}
	}

	return result;
}

matrix matrix_multiplication2D(matrix a, matrix b, int size){
	
	matrix res= matrix_gen(size, size);

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

matrix* split_matrix(matrix x, int size){

	matrix* return_matrix_arr= (matrix*)malloc(4*sizeof(matrix*));
	//
	int half_size= size/2;
	//
	return_matrix_arr[0]= matrix_gen(half_size, half_size);
	return_matrix_arr[1]= matrix_gen(half_size, half_size);
	return_matrix_arr[2]= matrix_gen(half_size, half_size);
	return_matrix_arr[3]= matrix_gen(half_size, half_size);

	// Top Left Matrix
	for(int i=0; i<half_size; i++){
		for(int j=0; j<half_size; j++){
			return_matrix_arr[0][i][j]= x[i][j];
		}
	}

	// Top Right Matrix
	for(int i=0; i<half_size; i++){
		for(int j=half_size; j<size; j++){
			return_matrix_arr[1][i][j-half_size]= x[i][j];
		}
	}

	// Bottom Left Matrix
	for(int i=half_size; i<size; i++){
		for(int j=0; j<half_size; j++){
			return_matrix_arr[2][i-half_size][j]= x[i][j];
		}
	}

	// Bottom Right Matrix
	for(int i=half_size; i<size; i++){
		for(int j=half_size; j<size; j++){
			return_matrix_arr[3][i-half_size][j-half_size]= x[i][j];
		}
	}

	return return_matrix_arr;
}

matrix strassen_matrix_multiplication2D(matrix x, matrix y, int size){

	matrix result= matrix_gen(size, size);

	if(size == 1){
			
			result[0][0]= x[0][0] * y[0][0];

	} else {
		
		int half_size= size/2;

		// Splitting 'x'
		matrix* res1= split_matrix(x, size);
		matrix a= res1[0];
		matrix b= res1[1];
		matrix c= res1[2];
		matrix d= res1[3];
	
		// Splitting 'y'
		matrix* res2= split_matrix(y, size);
		matrix e= res2[0];
		matrix f= res2[1];
		matrix g= res2[2];
		matrix h= res2[3];	

		matrix f_minus_h= matrix_subtraction2D(f, h, half_size);
		matrix a_plus_b= matrix_addition2D(a, b, half_size);
		matrix c_plus_d= matrix_addition2D(c, d, half_size);
		matrix g_minus_e= matrix_subtraction2D(g, e, half_size);
		matrix a_plus_d= matrix_addition2D(a, d, half_size);
		matrix e_plus_h= matrix_addition2D(e, h, half_size);
		matrix b_minus_d= matrix_subtraction2D(b, d, half_size);
		matrix g_plus_h= matrix_addition2D(g, h, half_size);
		matrix a_minus_c= matrix_subtraction2D(a, c, half_size);
		matrix e_plus_f= matrix_addition2D(e, f, half_size);
		//
		matrix p1= strassen_matrix_multiplication2D(
					a, 
					f_minus_h,
					half_size
		);
		matrix p2= strassen_matrix_multiplication2D(
					a_plus_b, 
					h,
					half_size
		);
		matrix p3= strassen_matrix_multiplication2D(
					c_plus_d, 
					e,
					half_size
		);
		matrix p4= strassen_matrix_multiplication2D(
					d, 
					g_minus_e,
					half_size
		);
		matrix p5= strassen_matrix_multiplication2D(
					a_plus_d, 
					e_plus_h,
					half_size
		);
		matrix p6= strassen_matrix_multiplication2D(
					b_minus_d, 
					g_plus_h,
					half_size
		);
		matrix p7= strassen_matrix_multiplication2D(
					a_minus_c, 
					e_plus_f,
					half_size
		);

		// Constructing quadrants of Final Matrix
		//
		matrix temp; // Holds matrix address to avoid memory leak
		//
		// c11= p5+p4-p2+p6;
		matrix c11= matrix_addition2D(p5, p4, half_size);
		temp= c11; c11= matrix_addition2D(c11, p6, half_size); free(temp);
		temp= c11; c11= matrix_subtraction2D(c11, p2, half_size); free(temp);
		//
		// c12= p1+p2;
		matrix c12= matrix_addition2D(p1, p2, half_size);
		//
		// c12= p3+p4;
		matrix c21= matrix_addition2D(p3, p4, half_size);
		//
		// c22= p1+p5-p3-p7;
		matrix c22= matrix_addition2D(p1, p5, half_size);
		temp= c22; c22= matrix_subtraction2D(c22, p3, half_size); free(temp);
		temp= c22; c22= matrix_subtraction2D(c22, p7, half_size); free(temp);

		// Freeing Memory
		free(p1); free(p2); free(p3); free(p4);
		free(p5); free(p6); free(p7);
		//
		free(f_minus_h); free(a_plus_b); free(c_plus_d); free(g_minus_e);
		free(a_plus_d); free(e_plus_h); free(b_minus_d);
		free(g_plus_h); free(a_minus_c); free(e_plus_f);
		
		// Combining quadrants of Final Matrix
		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++){
				if(i<half_size){
					if(j<half_size){
						result[i][j]= c11[i][j];
					} else {
						result[i][j]= c12[i][j-half_size];
					}
				} else {
					if(j<half_size){
						result[i][j]= c21[i-half_size][j];
					} else {
						result[i][j]= c22[i-half_size][j-half_size];
					}
				}
			}
		}
		
	}

	return result;
}

