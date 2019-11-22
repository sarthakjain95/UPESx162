
#! /usr/bin/env python3

import numpy as np 

a= np.array([234,23,42,34,23,5,2354,23,4324])
print(a)

b= np.array([(234,234,23,423,4,32,4,234),(23,423,65,865,8,65,765,765) ])
print(b)

c= np.array([(214234234),(),(234234),(),(),(234324)])
print(c)

matrix= [ [1,2,3], [4,5,6], [7,8,9] ]
matrix= np.array(matrix)
print( "\n\n", matrix )

# Properties of the num py object.

# Gives out the dimension of the array
print( "\nDimension of the array:", matrix.ndim )
# Gives out the number of rows and the columns of the matrix/array
print( "Shape of the array:", matrix.shape )
# Gives out the total number of elements in the array
print( "Size of array:", matrix.size )


matrix= [[1,2,3],[4,5,6]]
matrix= np.array(matrix)
print( "\n\n",matrix )
# Re-shape function
print("Re shapin'\n")
print( matrix.reshape( 3,2 ) )
print( matrix.reshape(1,6) )
print( matrix.reshape(6,1) )

# Min/Max Functions
print( "Maximum value in the array", matrix.max() )
print( "Minimum value in the array", matrix.min() )

# Sum Function
print( "Sum of all the values", matrix.sum() )
# Sum function for the sum of values in a column
# axis=0 #Columns
# axis=1 #Rows
print( "Sum of values on each row\t", matrix.sum(axis=0) )
print( "Sum of values on each column\t", matrix.sum(axis=1) )


a= np.array( ([1,2] , [3,6]) )
b= np.array( ([1,2] , [7,5]) )

# Operators on matrices
print( a+b )
print( a-b )
print( a*b )
print( a/b )

# Vertical Stacking
print( np.vstack( (a,b) ) )
print( np.vstack( (b,a) ) )

# Horizontal Stacking
print( np.hstack( (a,b) ) )
print( np.hstack( (b,a) ) )

# Convert to 1D array
print( np.ravel( matrix ) )


# Numy arange function
# numpy.arange(start, stop, step, dtype)
# interval includes start and not the stop value
# start: number/optional/start of interval/defaults to zero
# stop:  number//end of interval/
# step:  number/optional/cannot be zero/
# dtype: type of an output array

import matplotlib.pyplot as plt

x= np.arange(0, np.pi, 0.1)
y= np.sin(x)
plt.plot( x,y )
plt.show()

y= np.cos(x)
plt.plot(x,y)
plt.show()

y= np.tan(x)
plt.plot(x,y)
plt.show()
