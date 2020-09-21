# Strassen's Matrix Multiplication Method


### About Files

`strassen_matmul.c`  
This program calculates the time taken by standard matrix multiplication method and strassen's matrix multiplication method.
  
`matrix_ops.h`  
This file contains the actual implementation of Standard and Strassen's matrix multiplication methods. This file also contains several other methods for working with matrices.

`matrix_ops_efficient.h`  
This file has the a more time efficient implementation of Strassen's method. The function names and arguments are the same as "matrix_ops.h".

### Why is Strassen's Method taking more time?

If you compile and run the test file "strassen_matmul.c", you will see that as we increase matrix size, Strassen's method takes a lot more time as compared to the Standard method of matrix multiplication. You see, the problem is that even though Strassen's method has a better Big-O complexity, function calls, memory allocation, memory access and other factors take up a lot of time in practical application. If you want to see the difference that a few 'calloc' calls can make, compare the execution times of "matrix_ops.h" and "matrix_ops_efficient.h".
